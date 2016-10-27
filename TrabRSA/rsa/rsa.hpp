#ifndef RSA_HPP
#define RSA_HPP

#include "keys.hpp"

void SetSeed(int seed);
void GenerateKeys(PublicKey &out_pubKey, PrivateKey &out_priKey);

#endif // RSA_HPP
