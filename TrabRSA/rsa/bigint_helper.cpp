#include "bigint_helper.hpp"

BigInt EncodeTextAsBigInt(std::string text) {
	BigInt block = 0;
	for(char c : text) {
		block = block << 8;
		block = block | (BigInt)c;
	}
	return block;
}
