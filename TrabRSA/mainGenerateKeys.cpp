#include <iostream>

#include "rsa/rsa.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	PublicKey pubKey;
	PrivateKey priKey;

	GenerateKeys(pubKey, priKey);

	cout << "Public Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	cout << "Eu sou o trabalho de RSA e eu vou gerar chaves! :D" << endl;
	return 0;
}
