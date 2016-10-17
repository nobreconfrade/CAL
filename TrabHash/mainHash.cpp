#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <list>
#include <algorithm> // std::find
#include <string.h>  // strcmp

#include "timer.hpp"
#include "hash_map.hpp"

using namespace std;

struct NameValuePair {
	char name[40];
	int value;

	NameValuePair(const char* argName, const int argValue) {
		strcpy(name, argName);
		value = argValue;
	}

	inline bool operator==(const char* rhs){
		return strcmp(name, rhs) == 0;
	}
};

void PrintHashes(string text);

void ListMain();
void TreeMain();
void HashMain();

int main(int argc, char const *argv[]) {
	//ListMain();
	//TreeMain();
	HashMain();

	return 0;
}

void ListMain() {
	list<NameValuePair> nameList;

	int numNames;
	cin >> numNames;

	while (numNames-- > 0) {
		int id;
		cin >> id;
		scanf(" "); // "removes" the next whitespace from cin

		char name[40];
		cin.getline(name, sizeof(name));
		// cout << id << ' ' << name << endl;
		nameList.push_back(NameValuePair(name, id));

	}

	int numQueries;
	cin >> numQueries;
	// cout << "NumQueries: " << numQueries << endl;

	char clearLine[30];
	cin.getline(clearLine, sizeof(clearLine));

	Timer timer = Timer("Busca sequencial");

	while (numQueries > 0) {
		numQueries -= 1;
		char name[40];
		cin.getline(name, sizeof(name));
		// cout << numQueries << ": "<< name << endl;

		auto it = find(nameList.begin(), nameList.end(), name);
		if (it != nameList.end()) {
			cout << it->value << endl;
		}
	}
}

void TreeMain() {
	map<string, int> nameTree;

	int numNames;
	cin >> numNames;

	while (numNames-- > 0) {
		int id;
		cin >> id;
		scanf(" "); // "removes" the next whitespace from cin

		char name[40];
		cin.getline(name, sizeof(name));
		// cout << id << ' ' << name << endl;
		nameTree[name] = id;

	}

	int numQueries;
	cin >> numQueries;
	// cout << "NumQueries: " << numQueries << endl;

	char clearLine[30];
	cin.getline(clearLine, sizeof(clearLine));

	Timer timer = Timer("Busca binaria");

	while (numQueries > 0) {
		numQueries -= 1;
		char name[40];
		cin.getline(name, sizeof(name));
		// cout << numQueries << ": "<< name << endl;

		cout << nameTree[name] << endl;
	}
}

void HashMain() {
		HashMapTree nameHashMap(10);

		int numNames;
		cin >> numNames;

		while (numNames-- > 0) {
			int id;
			cin >> id;
			scanf(" "); // "removes" the next whitespace from cin

			char name[40];
			cin.getline(name, sizeof(name));
			// cout << id << ' ' << name << endl;
			nameHashMap.SetValue(name, id);

		}

		int numQueries;
		cin >> numQueries;
		// cout << "NumQueries: " << numQueries << endl;

		char clearLine[30];
		cin.getline(clearLine, sizeof(clearLine));

		Timer timer = Timer("Hash");

		while (numQueries > 0) {
			numQueries -= 1;
			char name[40];
			cin.getline(name, sizeof(name));
			// cout << numQueries << ": "<< name << endl;

			cout << nameHashMap.GetValue(name) << endl;
		}
}


void PrintHashes(string text) {
	cout << text << endl;
	cout << SimpleHash(string(text)) << endl;
	cout << FoldHash(string(text)) << endl;
}
