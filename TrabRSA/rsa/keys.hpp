#ifndef KEYS_HPP
#define KEYS_HPP

#include <gmpxx.h>

typedef mpz_class BigInt;

#include <string>

// Private Key: (d, n)
struct PrivateKey {
	BigInt d;
	BigInt n;

	PrivateKey(BigInt argD, BigInt argN) {
		d = argD;
		n = argN;
	}

	std::string ToString() {
		return "(" + d.get_str() + ", " + n.get_str() + ")";
	}
};

// Public Key: (n, e)
struct PublicKey {
	BigInt n;
	BigInt e;

	PublicKey(BigInt argN, BigInt argE) {
		n = argN;
		e = argE;
	}

	std::string ToString() {
		return "(" + n.get_str() + ", " + e.get_str() + ")";
	}
};

#endif // KEYS_HPP
