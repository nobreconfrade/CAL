#include "rsa.hpp"

struct EuclidTriple {
	BigInt d, x, y;

	EuclidTriple(BigInt argD, BigInt argX, BigInt argY) {
		d = argD;
		x = argX;
		y = argY;
	}
};

EuclidTriple ExtendedEuclid(BigInt a, BigInt b) {
	if (b == 0)
		return EuclidTriple(a, 1, 0);

	EuclidTriple e = ExtendedEuclid(b, a % b);
	return EuclidTriple(e.d, e.y, e.x - a / b * e.y);
}

// TODO: Implement
bool IsWitness(BigInt n, BigInt witness, BigInt exponent, BigInt remainder) {
	// Equivalent to: witness = pow(witness, remainder) % n
	mpz_powm(witness.get_mpz_t(),
			 witness.get_mpz_t(),
			 remainder.get_mpz_t(),
			 n.get_mpz_t());

	if (witness == 1 or witness == n - 1)
		return false;

	BigInt two = 2;
	for (BigInt i = 0; i < exponent; ++i)
		mpz_powm(witness.get_mpz_t(),
				 witness.get_mpz_t(),
				 two.get_mpz_t(),
				 n.get_mpz_t());

	if (witness == n - 1)
		return false;

	return true;
}

// TODO: Implement
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

	gmp_randclass gmpRandom(gmp_randinit_mt);

	for (BigInt i = 2; i < sqrt(n); i++) {
		BigInt candidate = gmpRandom.get_z_range(n - 2) + 2;

		if (IsWitness(n, candidate, exponent, remainder)) {
			return false;
		}
	}

	return true;
}

BigInt GenerateProbableBigPrime(int numBits) {
	return 0;
}

// TODO: implement
BigInt GenerateBigPrime() {
	BigInt prime = 7;

	return prime;
}

// O retorno não necessariamente precisa ser Bigint pois o retorno é um número
//pequeno
// TODO: Implement
BigInt GenerateOddCoprime(BigInt n) {
	BigInt coprime;
	BigInt i = 2;

	while(i++) {
		if (gcd(i, n) == 1) {
			coprime = i;
			break;
		}
	}

	return coprime;
}

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	BigInt p = GenerateBigPrime();
	BigInt q = GenerateBigPrime();
	BigInt n = p * q;
	// An e = Odd Coprime of (p-1) * (q-1)
	BigInt e = GenerateOddCoprime((p - 1) * (q - 1));
	// Modular inverse or multiplicative inverse
	BigInt d = -1;
	// BigInt d = ModularInverse(e);

	out_pubKey = PublicKey(n, e);
	out_priKey = PrivateKey(n, d);
}
