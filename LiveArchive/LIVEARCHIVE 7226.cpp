/*
 *  Let's consider moving only black coins to black vertices, we can construct a network with that constraint
 *  Next thing is to run min cost bipartite matching to get the best result possible
 *  Min cost bipartite matching could work by modifying MCMF 
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvii;
typedef long double ld;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)

vvi node;
vb visited;
int n, m;
vi ver, coin;
int dist[501][501];

//Minimum Cost Max Flow SPFA implementation
const int mxN = 110;
const int inf = 1000000010;
struct Edge
{
	int to, cost, cap, flow, backEdge;
};
struct MCMF
{
	int s, t, n;
	vector<Edge> g[mxN];
	MCMF(int _s, int _t, int _n)
	{
		s = _s, t = _t, n = _n;
	}
	void addEdge(int u, int v, int cost, int cap)
	{
		Edge e1 =
		{ v, cost, cap, 0, g[v].size() };
		Edge e2 =
		{ u, -cost, 0, 0, g[u].size() };
		g[u].push_back(e1);
		g[v].push_back(e2);
	}
	pair<int, int> minCostMaxFlow()
	{
		int flow = 0, cost = 0;
		vector<int> state(n), from(n), from_edge(n), d(n);
		deque<int> q;
		while (true)
		{
			for (int i = 0; i < n; i++)
				state[i] = 2, d[i] = inf, from[i] = -1;
			state[s] = 1;
			q.clear();
			q.push_back(s);
			d[s] = 0;
			while (!q.empty())
			{
				int v = q.front();
				q.pop_front();
				state[v] = 0;
				for (int i = 0; i < (int) g[v].size(); i++)
				{
					Edge e = g[v][i];
					if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
						continue;
					int to = e.to;
					d[to] = d[v] + e.cost;
					from[to] = v;
					from_edge[to] = i;
					if (state[to] == 1)
						continue;
					if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
						q.push_front(to);
					else
						q.push_back(to);
					state[to] = 1;
				}
			}
			if (d[t] == inf)
				break;
			int it = t, addflow = inf;
			while (it != s)
			{
				addflow = min(addflow,
						g[from[it]][from_edge[it]].cap
								- g[from[it]][from_edge[it]].flow);
				it = from[it];
			}
			it = t;
			while (it != s)
			{
				g[from[it]][from_edge[it]].flow += addflow;
				g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
				cost += g[from[it]][from_edge[it]].cost * addflow;
				it = from[it];
			}
			flow += addflow;
		}
		return
		{	cost,flow};
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		node = vvi(n + 1);
		ver = coin = vi(n + 1);
		visited = vb(n + 1);
		rep(i, 0, n)
			rep(j, 0, n)
				dist[i][j] = 1e5, dist[i][i] = 0;

		while (m--)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			dist[u][v] = dist[v][u] = 1;
		}

		rep(i, 0, n)
			cin >> ver[i];
		rep(i, 0, n)
			cin >> coin[i];

		rep(k, 0, n)
			rep(i, 0, n)
				rep(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		/*rep(i, 0, n)
		{
			rep(j, 0, n)
				cout << dist[i][j] << " ";
			cout << endl;
		}
		cout << endl;*/

		vi black, white;
		rep(i, 0, n)
		{
			if (!coin[i])
				black.push_back(i);
			if (!ver[i])
				white.push_back(i);
		}
		int src = sz(black) + sz(white), sink = src + 1;
		MCMF flow(src, sink, sink + 1);
		rep(i, 0, sz(black))
		{
			rep(j, 0, sz(white))
			{
				flow.addEdge(black[i], white[j], dist[black[i]][white[j]], 1);
			}
		}

		rep(i, 0, sz(black))
			flow.addEdge(src, black[i], 0, 1);
		rep(i, 0, sz(white))
			flow.addEdge(white[i], sink, 0, 1);

		pii hoba = flow.minCostMaxFlow();

		cout << hoba.first << endl;
	}

	return 0;
}
