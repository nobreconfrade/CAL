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

string EncryptText(string text) {
	string cyphertext;
	return cyphertext;
}

int main(int argc, char const *argv[]) {
	cout << "Eu sou o trabalho de RSA e eu vou cifrar coisas! :D" << endl;

	PublicKey pubKey;
	if (LoadPublicKeyFromFile(pubKey) == false)
		return 0;

	cout << "Public Key: " << pubKey.ToString() << endl;

	string plaintext;
	cout << "Write a super secret message to encrypt: ";
	cin >> plaintext;

	string cyphertext = EncryptText(plaintext);
	SaveCyphertextToFile(cyphertext);

	return 0;
}
