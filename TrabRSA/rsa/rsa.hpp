#ifndef RSA_HPP
#define RSA_HPP

#include "keys.hpp"
#include "prime_generator.hpp"

void GenerateKeys(unsigned numBits, PublicKey &out_pub, PrivateKey &out_pri);

#endif // RSA_HPP
