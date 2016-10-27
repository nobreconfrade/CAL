#include "rsa/keys.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SaveCyphertextToFile(string cyphertext) {
	ofstream file;
	file.open("cyphertext.txt");

	file << cyphertext;
}

int main(int argc, char const *argv[]) {
	cout << "Eu sou o trabalho de RSA e eu vou cifrar coisas! :D" << endl;

	PublicKey pubKey;
	PrivateKey priKey;

	if (LoadKeysFromFile(pubKey, priKey) == false)
		return 0;

	cout << "Public  Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	SaveCyphertextToFile("Oi:DDDDDDDDDDDDDD");

	return 0;
}
