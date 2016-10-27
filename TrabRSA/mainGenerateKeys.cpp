#include <iostream>

#include "rsa/rsa.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	PublicKey pubKey;
	PrivateKey priKey;

	SetSeed(15);
	GenerateKeys(pubKey, priKey);

	cout << "Public  Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	cout << "Eu sou o trabalho de RSA e eu estou finalmente gerando chaves! :D" << endl;
	return 0;
}
