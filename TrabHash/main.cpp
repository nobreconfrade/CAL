#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm> // std::find
#include <string.h>  // strcmp

#include "hash_map.hpp"

using namespace std;

void PrintHashes(string text);

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

	// Linear List Search
	list<NameValuePair> nameList;
	nameList.push_back(NameValuePair(name, 20));
	auto it = find(nameList.begin(), nameList.end(), name);
	cout << it->value <<  endl;

	// Binary Tree Search
	map<const char*, int> nameTree;
	nameTree[name] = 20;
	cout << nameTree[name] << endl;

	// Hash with binary tree search for collision
	HashMapTree nameHashMap(10);
	nameHashMap.SetValue(name, 20);
	cout << nameHashMap.GetValue(name) << endl;

	return 0;
}

void PrintHashes(string text) {
	cout << text << endl;
	cout << SimpleHash(string(text)) << endl;
	cout << FoldHash(string(text)) << endl;
}
