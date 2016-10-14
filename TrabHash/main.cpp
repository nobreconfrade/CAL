#include <iostream>
#include <string>

#include "hash_map.hpp"

using namespace std;

void PrintHashes(string text);

int main(int argc, char const *argv[]) {
	const char * name = "Winnie";

	HashMapTree hashMap(10);

	hashMap.SetValue(name, 20);
	cout << hashMap.GetValue(name) << endl;

	return 0;
}

void PrintHashes(string text) {
	cout << text << endl;
	cout << SimpleHash(string(text)) << endl;
	cout << FoldHash(string(text)) << endl;
}
