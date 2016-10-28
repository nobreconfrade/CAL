#ifndef PRIME_GENERATOR_HPP
#define PRIME_GENERATOR_HPP

#include <gmpxx.h>
typedef mpz_class BigInt;

void SetSeed(BigInt seed);

BigInt GenerateProbableBigPrime(unsigned int numBits);
BigInt GenerateOddCoprime(BigInt n);

#endif // PRIME_GENERATOR_HPP
