// Resources:
// http://doctrina.org/How-RSA-Works-With-Examples.html

#include "rsa.hpp"
#include <iostream>

using namespace std;

struct EuclidTriple {
	BigInt d, x, y;

	EuclidTriple(BigInt argD, BigInt argX, BigInt argY) {
		d = argD;
		x = argX;
		y = argY;
	}
};

static gmp_randclass gmpRandom(gmp_randinit_mt);

void SetSeed(int seed) {
	gmpRandom.seed(seed);
}

// Solves e*d mod n =
EuclidTriple ExtendedEuclid(BigInt a, BigInt b) {
	if (b == 0)
		return EuclidTriple(a, 1, 0);

	EuclidTriple e = ExtendedEuclid(b, a % b);
	//	   EuclidTriple(d, x, y)
	return EuclidTriple(e.d, e.y, e.x - e.y * (a/b) );
}

// Modular multiplicative inverse
BigInt ModularInverseSolver(BigInt a, BigInt n) {
	EuclidTriple euclid = ExtendedEuclid(a, n);

	if (euclid.d % 1 == 0) {
		BigInt x0 = euclid.x * (1 / euclid.d) % n;
		// cout << "D: " << euclid.d << endl;
		for (BigInt i = 0; i <= euclid.d; i++) {
			BigInt x = (x0 + i * (n / euclid.d) ) % n;

			if (x > 0)
				return x;

		}
	}

	return 0;
}

bool IsWitness(BigInt n, BigInt witness, BigInt exponent, BigInt remainder) {
	// Equivalent to: witness = pow(witness, remainder) % n
	mpz_powm(witness.get_mpz_t(),
			 witness.get_mpz_t(),
			 remainder.get_mpz_t(),
			 n.get_mpz_t());

	if (witness == 1 or witness == n - 1)
		return false;

	BigInt two = 2;
	for (BigInt i = 0; i < exponent; ++i) {
		mpz_powm(witness.get_mpz_t(),
				 witness.get_mpz_t(),
				 two.get_mpz_t(),
				 n.get_mpz_t());
	}

	if (witness == n - 1)
		return false;

	return true;
}

bool MillerRabin(BigInt n) {
	if (n < 2)
		return false;
	else if (n == 2 || n == 3)
		return true;

	BigInt remainder = n-1;
	BigInt exponent  = 0;
	while (remainder % 2 == 0){
		remainder /= 2;
		exponent  += 1;
	}

	for (BigInt i = 2; i < sqrt(n); i++) {
		BigInt candidate = gmpRandom.get_z_range(n - 2) + 2;

		if (IsWitness(n, candidate, exponent, remainder)) {
			return false;
		}
	}

	return true;
}

BigInt GenerateProbableBigPrime(int numBits) {
	int numTries = 100000;

	while(numTries-- > 0) {
		BigInt candidate = gmpRandom.get_z_bits(numBits);

		if (MillerRabin(candidate))
			return candidate;
	}
	return 0;
}

BigInt GenerateBigPrime() {
	return GenerateProbableBigPrime(8);
}

// O retorno não necessariamente precisa ser Bigint pois o retorno é um número
//pequeno
BigInt GenerateOddCoprime(BigInt n) {
	BigInt coprime;
	BigInt i = 3;

	while(i++) {
		if (gcd(i, n) == 1)
		{
			coprime = i;
			break;
		}
	}

	return coprime;
}

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	BigInt p = GenerateBigPrime();
	BigInt q = GenerateBigPrime();

	// cout << "p: " << p.get_str() << endl;
	// cout << "q: " << q.get_str() << endl;

	BigInt n = p * q;
	//
	BigInt nPhi = (p - 1) * (q - 1);

	BigInt e = GenerateOddCoprime(nPhi);
	BigInt d = ModularInverseSolver(e, nPhi);

	out_pubKey = PublicKey(n, e);
	out_priKey = PrivateKey(n, d);
}
