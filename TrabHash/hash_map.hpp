#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <string>
#include <vector>
#include <map>
#include <stdint.h>

uint32_t SimpleHash(std::string text);
uint64_t FoldHash(std::string text);

// Linear Search
class HashMapLinear {
private:
	std::vector<int> data;
	std::vector<bool> isOccupied;

	uint32_t GetIndexFromHash(const char* key);
public:
	HashMapLinear (unsigned int numElements);
	virtual ~HashMapLinear ();

	void SetValue(const char* key, const int& value);
	int GetValue(const char* key);
};

// Binary Tree Search
class HashMapTree {
private:
	std::vector<int> data;
	std::vector<bool> isOccupied;

	uint32_t GetIndexFromHash(const char* key);
public:
	HashMapTree (unsigned int numElements);
	virtual ~HashMapTree ();

	void SetValue(const char* key, const int& value);
	int GetValue(const char* key);
};
#endif
