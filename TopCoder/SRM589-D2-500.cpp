/*
    if 2 consecutive gears are the same, we have to change one of them
    else we move to the next gear
    
    now we need to minimize between different cuts
    
    if the first and last gear are not the same, we can let them be
    
    otherwise we should try and separate the cycle by either cutting the first or last gear
    
    logically, this should work regardless of where we cut, as we'll consider
    the ith gear as our start of the string and ith-1 gear as our end
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

int solve(string x)
{
	int n = sz(x);

	if (n <= 1) return 0;

	if (x[0] == x[1]) return 1 + solve(x.substr(2));

	return solve(x.substr(1));
}

class GearsDiv2
{
public:
	int getmin(string Directions)
	{
		int n = sz(Directions);
		int ret = n-1;

		if (Directions.front() != Directions.back()) ret = solve(Directions);

		ret = min(ret, 1 + solve(Directions.substr(1)));
		Directions.pop_back();
		ret = min(ret, 1 + solve(Directions));


		return ret;
	}
};

