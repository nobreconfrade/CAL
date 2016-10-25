#ifndef KEYS_HPP
#define KEYS_HPP

#include "../bigint/bigint.h"

#include <string>

using Dodecahedron::Bigint;

// Private Key: (d, n)
struct PrivateKey {
	Bigint d;
	Bigint n;

	PrivateKey(Bigint argD, Bigint argN) {
		d = argD;
		n = argN;
	}

	std::string ToString() {
		return "(" + to_string(d) + ", " + to_string(n) + ")";
	}
};

// Public Key: (n, e)
struct PublicKey {
	Bigint n;
	Bigint e;

	PublicKey(Bigint argN, Bigint argE) {
		n = argN;
		e = argE;
	}

	std::string ToString() {
		return "(" + to_string(n) + ", " + to_string(e) + ")";
	}
};

#endif // KEYS_HPP
