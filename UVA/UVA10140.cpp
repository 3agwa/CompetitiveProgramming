/*
 *  R - L + 1 is 1e6, we can iterate on range, L <= R <= 2^31
 *  if we can't generate the primes in a big range [L, R] but we can iterate over the range (constraint)
 *  we can generate all primes till sqrt of max and maintain a bitset indicating whether or not this index is a prime
 *  check on primes if N <= BOUND then return bs[N], else iterate over the generated primes
 *  if N > pr*pr this means that there is no prime divisor in our set, then this number is a prime
 *  if N % pr == 0, then this number is not a prime
 *  if we finish looping without returning anything, return true, this is a prime number with a big value
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 1e6 + 5;

bitset<N> bs;
vector<ll> primes;

bool check(ll num)
{
	if (num <= N - 5)
		return bs[num];
	else
	{
		for (auto i : primes)
		{
			if (i * i > num)
				return true;
			if (num % i == 0)
				return false;
		}
	}
	return true;
}

void gen()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= N - 5ll; i++)
	{
		if (bs[i])
		{
			for (ll j = i * i; j <= N - 5ll; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	gen();
	ll l, r;
	while (cin >> l >> r)
	{
		ll prev = -1, mn = 1e9, mx = 0;
		pair<ll, ll> minn =
		{ 1e18, 1e18 }, maxx =
		{ 0, 0 };

		erep(i, l, r)
		{
			if (check(i))
			{
				if (prev == -1)
					prev = i;
				else
				{
					if (i - prev < mn)
					{
						mn = i - prev;
						minn =
						{	prev, i};
					}

					if (i-prev > mx)
					{
						mx = i-prev;
						maxx =
						{	prev, i};
					}
				}
				prev = i;
			}
		}

		if (!mx)
			cout << "There are no adjacent primes.\n";
		else
			cout << minn.first << "," << minn.second << " are closest, "
					<< maxx.first << "," << maxx.second
					<< " are most distant.\n";
	}

	return 0;
}
