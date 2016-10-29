#include "rsa/keys.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool LoadCyphertextFromFile(string &cyphertext) {
	std::ifstream file;

	file.open("cyphertext.txt");
	if (file.is_open() == false)
	{
		cout << "*ERROR*: file 'cyphertext.txt' not found" << endl;
		return false;
	}

	// Reads the whole textfile into a buffer and copy it's string, so we recei-
	//ve every character into the string, even '\0', '\n' and whitespaces, this
	//is important if we want to recover the encoded cyphertext properly.
	std::stringstream buffer;
	buffer << file.rdbuf();
	cyphertext = buffer.str();

	return true;
}

BigInt DecryptEncodedCypher(PrivateKey key, BigInt encodedCypher) {
	BigInt encodedText;
	// M = C^e mod n
	// Equivalent to: text = pow(cypher, d) % n
	mpz_powm_sec(encodedText.get_mpz_t(),
				 encodedCypher.get_mpz_t(),
				 key.d.get_mpz_t(),
				 key.n.get_mpz_t());

	// cout << "C: " << encodedCypher << endl;
	// cout << "M: " << encodedText << endl;

	return encodedText;
}

string DecryptCyphertext(PrivateKey key, string cyphertext) {
	BigInt encodedCypher = EncodeTextAsBigInt(cyphertext);

	BigInt encodedText = DecryptEncodedCypher(key, encodedCypher);

	string text = EncodeBigIntAsText(encodedText);
	return text;
}

int main(int argc, char const *argv[]) {
	// cout << "Eu sou o trabalho de RSA e eu estou quase decifrando coisas! :D" << endl;

	PrivateKey priKey;
	if (LoadPrivateKeyFromFile(priKey) == false)
		return 0;

	string cyphertext;
	if (LoadCyphertextFromFile(cyphertext) == false)
		return 0;

	cout << "--------cyphertext--------" << endl
		 << cyphertext					 << endl
		 << "--------------------------" << endl << endl;

	cout << "Decrypting..." << endl << endl;
	string text = DecryptCyphertext(priKey, cyphertext);

	cout << "-----------text-----------" << endl
		 << text						 << endl
		 << "--------------------------" << endl << endl;

	return 0;
}
