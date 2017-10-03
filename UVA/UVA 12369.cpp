/*
 *  for the given input, we'll pick a card, multiply it by its probability and move to the next state
 *  we try to matck Joker1 to a suit, we'll do the same with Joker2
 *  we'll have to minimize over the Joker cards to optain our solution
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

int tc, id;

bool visited[15][15][15][15][5][5];
double memo[15][15][15][15][5][5];
double C, D, H, S;

double solve(int c, int d, int h, int s, int j1, int j2)
{
	if (c < 0 || d < 0 || h < 0 || s < 0) return 0.;

	double ret = 0.;

	double cc = 13 - c + (j1 == 1) + (j2 == 1);
	double cd = 13 - d + (j1 == 2) + (j2 == 2);
	double ch = 13 - h + (j1 == 3) + (j2 == 3);
	double cs = 13 - s + (j1 == 4) + (j2 == 4);

	if (cc >= C && cd >= D && ch >= H && cs >= S) return 0.;
	if (!(c + d + h + s + (!j1) + (!j2))) return 1e9;

	if (visited[c][d][h][s][j1][j2]) return memo[c][d][h][s][j1][j2];
	visited[c][d][h][s][j1][j2] = true;


	double rem = c + d + h + s + (!j1) + (!j2);
	ret += (c / rem) * (1. + solve(c-1, d, h, s, j1, j2));
	ret += (d / rem) * (1. + solve(c, d-1, h, s, j1, j2));
	ret += (h / rem) * (1. + solve(c, d, h-1, s, j1, j2));
	ret += (s / rem) * (1. + solve(c, d, h, s-1, j1, j2));

	if (!j1)
	{
		double mn = 1e9;
		rep(i, 1, 5)
		{
			mn = min(mn, (1. / rem) * (1. + solve(c, d, h, s, i, j2)));
		}
		ret += mn;
	}

	if (!j2)
	{
		double mn = 1e9;
		rep(i, 1, 5)
		{
			mn = min(mn, (1. / rem) * (1. + solve(c, d, h, s, j1, i)));
		}
		ret += mn;
	}

	return memo[c][d][h][s][j1][j2] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x = 1;
	cin >> tc;
	while(tc--)
	{
		reset(visited, false);
		cin >> C >> D >> H >> S;

		cout << "Case " << x++ << ": " << 	fixed << setprecision(3);
		if (C+D+H+S > 54) cout << -1. << endl;
		else
		{
			double ret = solve(13, 13, 13, 13, 0, 0);

			if (ret > 54) cout << -1. << endl;
			else cout << ret << endl;
		}
	}
	return 0;
}
