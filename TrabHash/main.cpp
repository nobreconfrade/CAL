#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm> // std::find
#include <string.h>  // strcmp

#include "hash_map.hpp"

using namespace std;

void PrintHashes(string text);

typedef pair<const char*, int> ListPair;
struct NameValuePair {
	const char* name;
	int value;
	NameValuePair(const char* argName, int argValue) {
		name = argName;
		value = argValue;
	}

	inline bool operator==(const char* rhs){
		return strcmp(name, rhs) == 0;
	}

};

int main(int argc, char const *argv[]) {
	const char * name = "Winnie";

	list<NameValuePair> nameList;
	map<const char*, int> nameTree;
	HashMapTree nameHashMap(10);

	nameList.push_back(NameValuePair(name, 20));
	nameTree[name] = 20;
	nameHashMap.SetValue(name, 20);

	auto it = find(nameList.begin(), nameList.end(), name);
	cout << it->value <<  endl;
	cout << nameTree[name] << endl;
	cout << nameHashMap.GetValue(name) << endl;

	return 0;
}

void PrintHashes(string text) {
	cout << text << endl;
	cout << SimpleHash(string(text)) << endl;
	cout << FoldHash(string(text)) << endl;
}
