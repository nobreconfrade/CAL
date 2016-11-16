#include "rsa/keys.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

BigInt FindD(BigInt n, BigInt e) {
	BigInt i = (sqrt(n));
	if (i % 2 == 0) {
		i -= 1;
	}

	BigInt p;
	for (; i > 0; i -= 2) {
		if (n % i == 0) {
			p = i;
			break;
		}
	}

	BigInt q = n / p;
	BigInt phi = (p - 1) * (q - 1);

	// cout << "p: " << p.get_str() << '\n';
	// cout << "q: " << q.get_str() << '\n';
	// cout << "phi: " << phi.get_str() << '\n';

	BigInt negOne = -1;
	BigInt d;

	mpz_powm(d.get_mpz_t(),
			 e.get_mpz_t(),
			 negOne.get_mpz_t(),
			 phi.get_mpz_t());

	return d;
}

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

	PublicKey pubKey;
	if (LoadPublicKeyFromFile(pubKey) == false)
		return 0;

	// BigInt d = FindD(203, 5);
	BigInt d = FindD(pubKey.n, pubKey.e);
	cout << "Found d: " << d.get_str() << '\n';

	PrivateKey priKey = PrivateKey(pubKey.n, d);

	string cyphertext;
	if (LoadCyphertextFromFile(cyphertext) == false)
		return 0;

	cout << "Decrypting..." << endl << endl;
	string text = DecryptCyphertext(priKey, cyphertext);

	cout << "-----------text-----------" << endl
		 << text						 << endl
		 << "--------------------------" << endl << endl;

	return 0;
}
