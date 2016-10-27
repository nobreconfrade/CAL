#include <iostream>
#include <ctime>	// std::time

#include "rsa/rsa.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[]) {
	cout << "Eu sou o trabalho de RSA e eu estou finalmente gerando chaves! :D" << endl;

	SetSeed(std::time(nullptr));

	PublicKey pubKey;
	PrivateKey priKey;

	GenerateKeys(pubKey, priKey);
	SaveKeysToFile(pubKey, priKey);

	cout << "Public  Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	return 0;
}
