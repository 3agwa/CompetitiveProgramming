/*
 *  we'll simulate the process, incrementing the denominator whenever we find 2 pairs to swap
 *  if the deno is not 0, we can divide out solution by it
 *  memoize in a vector to avoid overlapping
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

map<vi, double> mp;

double solve(vi vec)
{
	if (mp.find(vec) != mp.end()) return mp[vec];

	double ret = 0., deno = 0.;

	rep(i, 0, sz(vec))
	{
		rep(j, i+1, sz(vec))
		{
			if (vec[i] > vec[j])
			{
				swap(vec[i], vec[j]);
				ret += (1. + solve(vec));
				deno++;
				swap(vec[i], vec[j]);
			}
		}
	}

	if (deno) ret /= deno;

	return mp[vec] = ret;
}

class RandomSort
{
public:
	double getExpected(vector<int> permutation)
	{
		mp.clear();
		return solve(permutation);
	}
};
