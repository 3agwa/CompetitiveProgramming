/*
 *  we'll simulate the process using dp to avoid overlapping
 *  if we skip the current witch, we get to live till curr_days + remaining hp 
 *  if we chose to fight, we have 2 options, lose and die on the current day
 *  or win (with the given probability) and move on to the next day with the newely gained hp (must not exceed M)
 *  all what's left is to handle the number of days between fighting the ith and i+1th witch
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

vector< pair<int, pii> > vec;
int n;
double MM;
bool visited[50][100001];
double memo[50][100001];

double solve(int idx, int m)
{
	if (idx == n)
		return vec[idx-1].first + m;

	if (!idx) m -= vec[idx].first;
	else m = m - (vec[idx].first - vec[idx-1].first);

	if (m <= 0) return vec[idx].first + m;

	if (visited[idx][m]) return memo[idx][m];
	visited[idx][m] = true;

	double ret = 0., p = (1. * vec[idx].second.first) / 100., gain = vec[idx].second.second;

	ret = solve(idx+1, m);

	ret = max(ret, solve(idx+1, min(MM, m + gain))*p + (vec[idx].first)*(1. - p));

	return memo[idx][m] = ret;
}

class MagicalGirl
{
public:
	double maxExpectation(int M, vector<int> day, vector<int> win,
			vector<int> gain)
	{
		n = sz(day), MM = M;
		rep(i, 0, n) vec.push_back(mp(day[i], win[i], gain[i]));
		sort(all(vec));

		return solve(0, M);
	}
};
