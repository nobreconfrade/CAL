#ifndef KEYS_HPP
#define KEYS_HPP

#include <string>
#include "bigint_helper.hpp"

// Private Key: (n, d)
struct PrivateKey {
	BigInt n = 0;
	BigInt d = 0;

	PrivateKey(){};
	PrivateKey(BigInt argN, BigInt argD) {
		n = argN;
		d = argD;
	}

	std::string ToString() {
		return "(" + n.get_str() + ", " + d.get_str() + ")";
	}
};

// Public Key: (n, e)
struct PublicKey {
	BigInt n = 0;
	BigInt e = 0;

	PublicKey(){};
	PublicKey(BigInt argN, BigInt argE) {
		n = argN;
		e = argE;
	}

	std::string ToString() {
		return "(" + n.get_str() + ", " + e.get_str() + ")";
	}
};

void SaveKeysToFile(PublicKey pubKey, PrivateKey priKey);
bool LoadPublicKeyFromFile(PublicKey &out_pubKey);
bool LoadPrivateKeyFromFile(PrivateKey &out_priKey);
bool LoadKeysFromFile(PublicKey &out_pubKey, PrivateKey &out_priKey);

#endif // KEYS_HPP
