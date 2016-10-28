#include "bigint_helper.hpp"

BigInt EncodeTextAsBigInt(std::string text) {
	BigInt block = 0;
	for(char c : text) {
		block = block << 8;
		block = block | (BigInt)c;
	}
	return block;
}

std::string EncodeBigIntAsText(BigInt number) {
	std::string text = "";
	while (number != 0) {
		char c = (char)(number.get_ui() & 0xFFFF);
		text.insert(0, 1, c);
		number = number >> 8;
	}
	return text;
}
