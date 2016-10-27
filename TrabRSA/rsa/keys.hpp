#ifndef KEYS_HPP
#define KEYS_HPP

// GMP Documentation
// https://gmplib.org/manual/
#include <gmpxx.h>

typedef mpz_class BigInt;

#include <string>

// Private Key: (d, n)
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

#endif // KEYS_HPP