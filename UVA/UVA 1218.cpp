/*
 *  for this problem we have 3 states
 *  1- parent is a server
 *  2- parent is a client but connected to a server
 *  3- parent is a client and not connected to a server
 *  the solution would be to consider the 3 states and apply the correct transitions
 *  state 1 will transition to 3
 *  state 2 will transition to 1
 *  state 3 will transition to either 2 or 3
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
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 1e4 + 5;
vi node[N];
int n;
int memo[N][3], visited[N][3], id;

int dfs(int v, int p, int state)
{
	if (visited[v][state] == id)
		return memo[v][state];
	visited[v][state] = id;

	int &ret = memo[v][state];
	ret = N;

	if (state == 0)
	{
		int curr = 0;
		for (auto i : node[v])
		{
			if (i == p)
				continue;
			curr += dfs(i, v, 2);
		}
		ret = 1 + curr;
	}
	else if (state == 1)
	{
		int curr = 0;
		for (auto i : node[v])
		{
			if (i == p)
				continue;
			curr += dfs(i, v, 0);
		}
		ret = curr;
	}
	else
	{
		int s1 = 0, s2 = 0;
		for (auto i : node[v])
		{
			if (i == p)
				continue;
			s1 += dfs(i, v, 2);
			s2 += dfs(i, v, 1);
		}
		ret = min(1 + s1, s2);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n)
	{
		id++;
		rep(i, 0, N)
			node[i].clear();
		rep(i, 0, n - 1)
		{
			int u, v;
			cin >> u >> v;
			node[u].push_back(v);
			node[v].push_back(u);
		}

		cout << dfs(1, 0, 0) << endl;
		cin >> n;
		if (n == -1)
			break;
	}

	return 0;
}
