bitset<10000010> bs;
vi primes;
int dp[10100];
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
			primes.push_back((int) i);

		}
}
