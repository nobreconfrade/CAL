#ifndef BIGINT_HELPER_HPP
#define BIGINT_HELPER_HPP

#include <string>

// GMP Documentation
// https://gmplib.org/manual/
#include <gmpxx.h>
typedef mpz_class BigInt;

BigInt EncodeTextAsBigInt(std::string text);

#endif // BIGINT_HELPER_HPP
