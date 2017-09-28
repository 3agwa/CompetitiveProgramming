/*
 * basic fast power problem
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int mod;

ll fast_pow(int b, int p)
{
	if (!p) return 1LL;

	ll temp = fast_pow(b, p/2) % mod;
	temp = (temp * temp)%mod;

	if (p&1) temp = (temp * b)%mod;

	return temp;
}

class PseudoPrimeTest
{
public:
	int firstFail(int q)
	{
		mod = q;

		erep(i, 2, mod - 1)
		{
			if (fast_pow(i, mod-1) != 1)
				return i;
		}
		return q;
	}
};
