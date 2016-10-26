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

bool MillerRabin(BigInt n) {
	return false;
}

BigInt GeneratePrime() {
	BigInt prime = 7;

	return prime;
}

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	BigInt p = GeneratePrime();
	BigInt q = GeneratePrime();
	BigInt n = p * q;
}
