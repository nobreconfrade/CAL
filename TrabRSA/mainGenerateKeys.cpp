#include <iostream>
#include <ctime>	// std::time
#include <string>   // std::stoi
#include "rsa/rsa.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[]) {

	SetSeed(std::time(nullptr));

	if (argc < 2) {
		cout << "**Missing argument**" << endl;
		cout << "Proper usage: ./generate_keys.out [numPrimeBits]" << endl
			 << "     Example: ./generate_keys.out 512" << endl;

		return -1;
	}

	cout << "Eu sou o trabalho de RSA e eu estou finalmente gerando chaves! :D" << endl;

	unsigned numPrimeBits = std::stoi(argv[1]);
	PublicKey pubKey;
	PrivateKey priKey;
	GenerateKeys(numPrimeBits, pubKey, priKey);

	SaveKeysToFile(pubKey, priKey);

	cout << "Public  Key: " << pubKey.ToString() << endl
		 << "Private Key: " << priKey.ToString() << endl;

	return 0;
}
