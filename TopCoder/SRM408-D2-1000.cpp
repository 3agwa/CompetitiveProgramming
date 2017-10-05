/*
 *  in one turn, we'll either move to (b-2, r) or to (b-1, r-1), putting into consideration player 2's turn
 *  the issue remains with the memory, putting memory as a vector is not enough
 *  the numbers decrease quickly, since epsilon is 1e-9, it made sense that the solution would be 0 after some numbers
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

vector< vector <double> > memo;
bool visited[4001][4001];

double solve(int blue, int red)
{
	if (!red)
		return blue&1;

	if (!blue)
		return !red;
	if (blue < 0) return 0;

	if (visited[blue][red])
		return memo[blue][red];

	visited[blue][red] = true;

	double ret = 0., p = blue+red;

	ret = solve(blue-2, red)*( (blue*1.) / p) + solve(blue-1, red-1)*( (red*1.) / p);

	return memo[blue][red] = ret;
}

class MarblesInABag
{
public:
	double getProbability(int redCount, int blueCount)
	{
		if (redCount + blueCount > 4500) 
			return 0.;
		memo = vector< vector <double>>(blueCount + 1);
		rep(i, 0, blueCount + 1)
			rep(j, 0, redCount + 1)
				memo[i].push_back(0);
		return solve(blueCount, redCount);
	}
};
