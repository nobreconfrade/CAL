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

bool LoadKeysFromFile(PublicKey &out_pubKey, PrivateKey &out_priKey) {
	{
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

		out_pubKey.n = n;
		out_pubKey.e = e;
	}
	{
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

		out_priKey.n = n;
		out_priKey.d = d;
	}

	return true;
}
