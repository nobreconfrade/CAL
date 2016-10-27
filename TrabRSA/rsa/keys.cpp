#include "keys.hpp"

#include <string>
#include <fstream>

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

void LoadKeysFromFile(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	{
		ifstream pubKeyFile;

		pubKeyFile.open("key.pub");
		string n, e;
		pubKeyFile >> n >> e;
		pubKeyFile.close();

		out_pubKey.n = n;
		out_pubKey.e = e;
	}
	{
		ifstream priKeyFile;

		priKeyFile.open("key.pri");
		string n, d;
		priKeyFile >> n >> d;
		priKeyFile.close();

		out_priKey.n = n;
		out_priKey.d = d;
	}
}
