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

string DecryptCyphertext(PrivateKey key, string cyphertext) {
	string text;
	/* Decryption happens here! */
	return text;
}

int main(int argc, char const *argv[]) {
	cout << "Eu sou o trabalho de RSA e eu vou decifrar coisas! :D" << endl;

	PrivateKey priKey;
	if (LoadPrivateKeyFromFile(priKey) == false)
		return 0;

	cout << "Private Key: " << priKey.ToString() << endl;

	string cyphertext;
	if (LoadCyphertextFromFile(cyphertext) == false)
		return 0;

	string text = DecryptCyphertext(priKey, cyphertext);

	cout << "Secret decrypted message: " << text << endl;

	return 0;
}
