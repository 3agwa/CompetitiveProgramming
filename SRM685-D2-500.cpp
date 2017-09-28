/*
 *  since N is small, we could try all different ways to reach 1 from 0
 *  if the current l*r is >= mn, then we don't need to continue and just return as the value won't decrease
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

vector< vector< pair<int, pii> > > node;

bool visited[21];
int mn;

void dfs(int v, int l, int r)
{
	if (l*r >= mn) return;
	
	if (v == 1)
	{
		mn = min(mn, l*r);
		return;
	}

	visited[v] = true;

	for(auto i : node[v])
		if (!visited[i.first])
			dfs(i.first, l + i.second.first, r + i.second.second);

	visited[v] = false;
}

class DoubleWeights
{
public:
	int minimalCost(vector<string> weight1, vector<string> weight2)
	{
		int n = sz(weight1);
		mn = 1e9;
		reset(visited, 0);
		node = vector< vector< pair<int, pii> > >(n);

		rep(i, 0, sz(weight1))
		{
			rep(j, 0, sz(weight1[i]))
			{
				if (weight1[i][j] != '.')
				{
					node[i].push_back({j, {weight1[i][j] - '0', weight2[i][j] - '0'}});
					node[j].push_back({i, {weight1[i][j] - '0', weight2[i][j] - '0'}});
				}
			}
		}

		dfs(0, 0, 0);

		return (mn == 1e9 ? -1 : mn);
	}
};
