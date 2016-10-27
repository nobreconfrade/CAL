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
bool IsWitness(BigInt n) {
	return false;
}

// TODO: Implement
bool MillerRabin(BigInt n) {
	if (n < 2)
		return false;
	else if (n == 2 || n == 3)
		return true;

	gmp_randclass gmpRandom(gmp_randinit_mt);

	for (BigInt i = 2; i < sqrt(n); i++) {
		n = gmpRandom.get_z_range(n - 2) + 2;
		if (IsWitness(n)) {

		}
	}

	return false;
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
