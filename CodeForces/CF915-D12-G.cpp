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

//int curr, n;
//
//int get(int idx, int gcd = 0)
//{
//	if (idx == n)
//		return gcd != 1;
//	int ret = 0;
//
//	erep(i, 1, curr)
//	{
//		ret += get(idx + 1, __gcd(gcd, i));
//	}
//
//	return ret;
//}

const int N = 2e6 + 5, mod = 1e9 + 7;
bitset<N> prime;
vi divs[N];
int mobius[N];
int pw[N];

void getMobius()
{
	reset(mobius, -1);
	mobius[1] = 1;

	for (int i = 2; i < N; i++)
	{
		divs[i].push_back(i);
		if (!prime[i])
		{
			mobius[i] = 1;
			for (int j = i + i; j < N; j += i)
				prime[j] = true, mobius[j] =
						j % (i * 1ll * i) == 0 ? 0 : -mobius[j], divs[j].push_back(
						i);
		}
		else
		{
			if (!mobius[i])
				continue;
			for (int j = i + i; j < N; j += i)
				divs[j].push_back(i);
		}
	}
}

int fast_pow(int b, int p)
{
	if (!p)
		return 1;

	int ret = fast_pow(b, p / 2);

	ret = (ret * 1ll * ret) % mod;
	if (p & 1)
		ret = (ret * 1ll * b) % mod;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	erep(i, 1, k)
		pw[i] = fast_pow(i, n);

	ll res = 0, sum = 0;
	getMobius();

//	rep(i, 1, 20)
//		cout << mobius[i] << " ";
//	cout << endl;

	erep(i, 2, k)
	{
		for (int j : divs[i])
		{
			sum -= (mobius[j] * pw[(i - 1) / j]);
			if (sum >= mod)
				sum -= mod;
			if (sum < 0)
				sum += mod;
			sum += (mobius[j] * pw[i / j]);
			if (sum >= mod)
				sum -= mod;
		}
		ll curr = pw[i] - sum;
		curr %= mod;
		if (curr < 0)
			curr += mod;
		res = (res + (curr ^ i)) % mod;
	}
	cout << res << endl;
	return 0;
}
