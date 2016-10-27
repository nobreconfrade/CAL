#include "rsa/keys.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoadCyphertextFromFile(string &cyphertext) {
	ifstream file;

	file.open("cyphertext.txt");
	if (file.is_open() == false)
	{
		cout << "*ERROR*: file 'cyphertext.txt' not found" << endl;
		return false;
	}

	file >> cyphertext;

	return true;
}

int main(int argc, char const *argv[]) {
	cout << "Eu sou o trabalho de RSA e eu vou decifrar coisas! :D" << endl;

	PublicKey pubKey;
	PrivateKey priKey;

	if (LoadKeysFromFile(pubKey, priKey) == false)
		return 0;

	cout << "Public  Key: " << pubKey.ToString() << endl;
	cout << "Private Key: " << priKey.ToString() << endl;

	string cyphertext;

	if (LoadCyphertextFromFile(cyphertext) == false)
		return 0;

	cout << "Secret decrypted message: " << cyphertext << endl;


	return 0;
}
