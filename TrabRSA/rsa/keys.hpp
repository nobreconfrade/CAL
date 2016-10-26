#ifndef KEYS_HPP
#define KEYS_HPP

#include "InfInt.h"

#include <string>

// Private Key: (d, n)
struct PrivateKey {
	InfInt d;
	InfInt n;

	PrivateKey(InfInt argD, InfInt argN) {
		d = argD;
		n = argN;
	}

	std::string ToString() {
		return "(" + d.toString() + ", " + n.toString() + ")";
	}
};

// Public Key: (n, e)
struct PublicKey {
	InfInt n;
	InfInt e;

	PublicKey(InfInt argN, InfInt argE) {
		n = argN;
		e = argE;
	}

	std::string ToString() {
		return "(" + n.toString() + ", " + e.toString() + ")";
	}
};

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey);

#endif // KEYS_HPP
