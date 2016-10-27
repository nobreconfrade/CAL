#include "rsa/keys.hpp"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	PublicKey pubKey;
	PrivateKey priKey;

	LoadKeysFromFile(pubKey, priKey);

	cout << "Public  Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	cout << "Eu sou o trabalho de RSA e eu vou cifrar coisas! :D" << endl;

	return 0;
}
