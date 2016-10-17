#include "hash_map.hpp"

/*----------------------------------------------------------------------------*/
// Hash Functions

uint32_t SimpleHash(std::string text)
{
	uint64_t hash = 0;
	for (char c : text)
	{
		hash = hash * 33 + (uint64_t) c;
	}
	return hash;
}

// http://research.cs.vt.edu/AVresearch/hashing/strings.php
uint64_t FoldHash(std::string text)
{
	uint32_t length = text.length() / 4;
	uint64_t hash = 0;
	for (size_t c = 0; c < length; c++) {
		uint64_t mul = 1;
		hash += (text[c] + text[c+1] + text[c+2] + text[c+3]) * mul;
		mul *= 256;
	}

	uint64_t mul = 1;
	for (char c : text) {
		hash += (uint64_t) c * mul;
		mul *= 256;
	}

	return hash;
}

/*----------------------------------------------------------------------------*/
// HashMap

HashMapTree::HashMapTree(unsigned int numElements) {
	this->data.resize(numElements, Tree());
}

HashMapTree::~HashMapTree() {
}

uint32_t HashMapTree::GetIndexFromHash(const char *key) {
	// uint64_t hash = SimpleHash(std::string(key));
	uint64_t hash = FoldHash(std::string(key));
	return hash % data.size();
}

int HashMapTree::GetValue(const char* key) {
	uint32_t index = GetIndexFromHash(key);
	return data[index][key];
}

void HashMapTree::SetValue(const char* key, const int& value) {
	uint32_t index = GetIndexFromHash(key);
	data[index][key] = value;
}

unsigned HashMapTree::GetNumCollisions() {
	unsigned numCollisions = 0;
	for(auto t : data) {
		numCollisions += t.size() - 1;
	}
	return numCollisions;
}

/*----------------------------------------------------------------------------*/
