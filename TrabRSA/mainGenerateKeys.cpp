#include <iostream>

#include "rsa/rsa.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	PublicKey pubKey = PublicKey(10, 20);
	cout << pubKey.ToString() << endl;
	
	cout << "Eu sou o trabalho de RSA e eu vou gerar chaves! :D" << endl;
	return 0;
}
