/*
    we'll try removing 1 object or splitting the sequence into 2 ways
    when splitting, get the maximum between the 2 splits and minimize over the main solution
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int memo[101][101];

int solve(int n, int k)
{
	if (!n) return  0;
	if (memo[n][k] != -1) return memo[n][k];

	int ret = 1 + solve(n-1, k);
	if (k)
	{
		rep(i, 1, n)
		{
			rep(j, 0, k) ret = min(ret, 1 + max(solve(i, j), solve(n-i, k-1-j)));
		}
	}
	return memo[n][k] = ret;
}

class CartInSupermarketEasy
{
public:
	int calc(int N, int K)
	{
		reset(memo, -1);
		return solve(N, K);
	}
};
