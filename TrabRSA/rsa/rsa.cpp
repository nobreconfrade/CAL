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

void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	BigInt p = GenerateProbableBigPrime(48);
	BigInt q = GenerateProbableBigPrime(48);

	// cout << "p: " << p.get_str() << endl;
	// cout << "q: " << q.get_str() << endl;

	BigInt n = p * q;
	// ϕ(n) = Euler's totient = (p - 1) * (q - 1)
	BigInt totient = (p - 1) * (q - 1);

	BigInt e = GenerateOddCoprime(totient);
	BigInt d = ModularInverseSolver(e, totient);

	out_pubKey = PublicKey(n, e);
	out_priKey = PrivateKey(n, d);
}
