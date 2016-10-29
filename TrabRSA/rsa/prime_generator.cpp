#include "prime_generator.hpp"

static gmp_randclass gmpRandom(gmp_randinit_mt);

void SetSeed(BigInt seed) {
	gmpRandom.seed(seed);
}

bool IsWitness(BigInt n, BigInt witness, BigInt exponent, BigInt remainder) {
	// Equivalent to: witness = pow(witness, remainder) % n
	mpz_powm(witness.get_mpz_t(),
			 witness.get_mpz_t(),
			 remainder.get_mpz_t(),
			 n.get_mpz_t());

	if (witness == 1 or witness == n - 1)
		return false;

	// The variable 'two' is created because of the way 'mpz_powm()' handles
	// arguments.
	BigInt two = 2;
	for (BigInt i = 0; i < exponent; ++i) {
		mpz_powm(witness.get_mpz_t(),
				 witness.get_mpz_t(),
				 two.get_mpz_t(),
				 n.get_mpz_t());
	}

	if (witness == n - 1)
		return false;

	return true;
}

bool MillerRabin(BigInt n) {
	if (n < 2)
		return false;
	else if (n == 2 || n == 3)
		return true;

	BigInt remainder = n - 1;
	BigInt exponent  = 0;

	while (remainder % 2 == 0){
		remainder /= 2;
		exponent  += 1;
	}

	for (BigInt i = 0; i < 100/*sqrt(n)*/; i++) {
		BigInt candidate = gmpRandom.get_z_range(n - 2) + 2;

		if (IsWitness(n, candidate, exponent, remainder)) {
			return false;
		}
	}

	return true;
}

BigInt GenerateProbableBigPrime(unsigned int numBits) {
	unsigned int numTries = 100000;

	while(numTries-- > 0) {
		BigInt candidate = gmpRandom.get_z_bits(numBits);

		if (MillerRabin(candidate))
			return candidate;
	}
	return 0;
}

// O retorno não necessariamente precisa ser Bigint pois o retorno é um número
//pequeno
BigInt GenerateOddCoprime(BigInt n) {
	BigInt coprime;
	BigInt i = 65003;

	while(i++) {
		if (gcd(i, n) == 1)
		{
			coprime = i;
			break;
		}
	}

	return coprime;
}
