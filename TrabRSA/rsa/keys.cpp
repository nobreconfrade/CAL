#include "keys.hpp"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

void SaveKeysToFile(PublicKey pubKey, PrivateKey priKey) {
	{
		ofstream pubKeyFile;
		pubKeyFile.open("key.pub");
		pubKeyFile << pubKey.n.get_str() << '\n'
				   << pubKey.e.get_str();
		pubKeyFile.close();
	}
	{
		ofstream priKeyFile;
		priKeyFile.open("key.pri");
		priKeyFile << priKey.n.get_str() << '\n'
				   << priKey.d.get_str();
		priKeyFile.close();
	}
}

bool LoadPublicKeyFromFile(PublicKey &out_pubKey) {
	ifstream pubKeyFile;

	pubKeyFile.open("key.pub");
	if (pubKeyFile.is_open() == false)
	{
		cout << "*ERROR*: file 'key.pub' not found" << endl;
		return false;
	}

	string n, e;
	pubKeyFile >> n >> e;
	pubKeyFile.close();

	out_pubKey = PublicKey(BigInt(n), BigInt(e));
	return true;
}

bool LoadPrivateKeyFromFile(PrivateKey &out_priKey) {
	ifstream priKeyFile;

	priKeyFile.open("key.pri");
	if (priKeyFile.is_open() == false)
	{
		cout << "*ERROR*: file 'key.pri' not found" << endl;
		return false;
	}

	string n, d;
	priKeyFile >> n >> d;
	priKeyFile.close();

	out_priKey = PrivateKey(BigInt(n), BigInt(d));
	return true;
}

bool LoadKeysFromFile(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	if (LoadPublicKeyFromFile(out_pubKey) == false)
		return false;

	if (LoadPrivateKeyFromFile(out_priKey) == false)
		return false;

	return true;
}
