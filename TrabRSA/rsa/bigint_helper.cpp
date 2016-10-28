#include "bigint_helper.hpp"
#include <iostream>
using namespace std;
BigInt EncodeTextAsBigInt(std::string text) {
	// cout << "|encoding text|: " << text << endl;
	BigInt block = 0;
	for(unsigned char c : text) {
		block = block << 8;
		block = block | (BigInt)c;
		// cout << block.get_str() << endl;
	}
	// cout << endl;
	// cout << block.get_str() << endl;
	// cout << "|finished text|" << endl;
	return block;
}

std::string EncodeBigIntAsText(BigInt number) {
	// cout << "|encoding bigint|: " << endl;
	// cout << "   number: " << number << endl;
	std::string text = "";
	while (number != 0) {
		BigInt maskedBig = BigInt(number & 0xFF);
		int masked = maskedBig.get_ui();
		unsigned char c = (unsigned char)masked;
		// cout << "maskedBig: " << maskedBig << endl;
		// cout << "   masked: " << masked << endl;
		// cout << "        c: " << c << endl;
		// cout << "     cint: " << (int)c << endl;
		text.insert(0, 1, c);
		number = number >> 8;
		// cout << text << endl;
	}
	// cout << "|finished bigint|" << endl;
	return text;
}
