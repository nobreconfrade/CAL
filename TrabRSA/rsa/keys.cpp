#include "keys.hpp"

struct EuclidTriple {
	InfInt d, x, y;

	EuclidTriple(InfInt argD, InfInt argX, InfInt argY) {
		d = argD;
		x = argX;
		y = argY;
	}
};

EuclidTriple ExtendedEuclid(InfInt a, InfInt b) {
	if (b == 0)
		return EuclidTriple(a, 1, 0);

	EuclidTriple e = ExtendedEuclid(b, a % b);
	return EuclidTriple(e.d, e.y, e.x - a / b * e.y);
}


InfInt GeneratePrime() {
	InfInt prime;

	return prime;
}

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	InfInt p = GeneratePrime();
	InfInt q = GeneratePrime();
	InfInt n = p * q;
}
