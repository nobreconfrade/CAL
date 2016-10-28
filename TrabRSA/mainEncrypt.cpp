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

BigInt EncryptEncodedText(PublicKey key, BigInt encodedText) {
	BigInt encodedCypher;
	// C = M^e mod n
	// Equivalent to: cypher = pow(text, e) % n
	mpz_powm_sec(encodedCypher.get_mpz_t(),
				 encodedText.get_mpz_t(),
				 key.e.get_mpz_t(),
				 key.n.get_mpz_t());

	// cout << "M: " << encodedText << endl;
	// cout << "C: " << encodedCypher << endl;

	return encodedCypher;
}

string EncryptText(PublicKey key, string text) {
	BigInt encodedText = EncodeTextAsBigInt(text);

	BigInt encodedCypher = EncryptEncodedText(key, encodedText);

	string cyphertext = EncodeBigIntAsText(encodedCypher);
	return cyphertext;
}

int main(int argc, char const *argv[]) {
	// cout << "Eu sou o trabalho de RSA e eu estou quase cifrando coisas! :D" << endl;

	PublicKey pubKey;
	if (LoadPublicKeyFromFile(pubKey) == false)
		return 0;

	// cout << "Public Key: " << pubKey.ToString() << endl;

	string plaintext;
	cout << "Write a super secret message to encrypt: ";
	cin >> plaintext;

	cout << "-----------text-----------" << endl
		 << plaintext					 << endl
		 << "--------------------------" << endl << endl;

	cout << "Encrypting..." << endl << endl;
	string cyphertext = EncryptText(pubKey, plaintext);
	
	 cout << "--------cyphertext--------" << endl
		 << cyphertext					 << endl
		 << "--------------------------" << endl << endl;
	SaveCyphertextToFile(cyphertext);

	return 0;
}
