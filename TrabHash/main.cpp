#include <iostream>
#include <string>

#include "hash_map.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	const char * name = "Winnie";

	cout << name << endl;
	cout << SimpleHash(string(name)) << endl;
	cout << FoldHash(string(name)) << endl;

	HashMapTree hashMap(10);

	hashMap.SetValue(name, 20);
	cout << hashMap.GetValue(name) << endl;

	return 0;
}
