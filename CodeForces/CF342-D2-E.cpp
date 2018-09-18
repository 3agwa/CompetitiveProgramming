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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

const int MAXN = 1e5 + 5;
int root = -1, n, q;
int sp[MAXN][20];
int depth[MAXN], par[MAXN];
ll ans[MAXN];
vvi node;

struct CentroidDecomposition
{
	int sz[MAXN];
	bool done[MAXN];
	vector<pair<int, int> > saved[MAXN];
	vector<int> ctree[MAXN];
	vector<int> g[MAXN];
	// init: done(0), get graph in constructor
	CentroidDecomposition()
	{

	}

	int updateSZ(int u, int par)
	{
		sz[u] = 1;
		for (int i = 0; i < g[u].size(); i++)
			if (!done[g[u][i]] && g[u][i] != par)
				sz[u] += updateSZ(g[u][i], u);
		return sz[u];
	}
	int getCentroid(int u, int par, int n)
	{
		int hvyChild = -1;
		for (int i = 0; i < g[u].size(); i++)
			if (!done[g[u][i]] && g[u][i] != par
					&& (hvyChild == -1 || sz[g[u][i]] > sz[hvyChild]))
				hvyChild = g[u][i];
		if (sz[hvyChild] <= n / 2)
			return u;
		return getCentroid(hvyChild, u, n);
	}
	void save(int u, int par, int cen, int x)
	{
		saved[cen].push_back(make_pair(u, x));
		for (int i = 0; i < g[u].size(); i++)
			if (!done[g[u][i]] && g[u][i] != par)
				save(g[u][i], u, cen, x + 1);
	}
	void decompose(int u, int par = -1)
	{
		int cen = getCentroid(u, par, updateSZ(u, par));
		if (root == -1)
			root = cen;
		done[cen] = 1;
		save(cen, -1, cen, 0);
		if (par != -1)
			ctree[par].push_back(cen);
		for (int i = 0; i < g[cen].size(); i++)
			if (!done[g[cen][i]])
				decompose(g[cen][i], cen);
	}
} cent;

void buildSparse()
{
	erep(j, 1, 19)
		erep(i, 1, n)
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v];

	for (int i = 19; i >= 0; i--)
		if (diff & (1 << i))
			u = sp[u][i];

	if (u == v)
		return u;

	for (int i = 19; i >= 0; i--)
		if (sp[u][i] != sp[v][i])
			u = sp[u][i], v = sp[v][i];

	return sp[u][0];
}

int dist(int u, int v)
{
	int lca = LCA(u, v);
	return depth[u] + depth[v] - 2 * depth[lca];
}

void dfs(int v, int p)
{
	depth[v] = 1 + depth[p];
	sp[v][0] = p;
	for(auto i : node[v])
		if (i != p)
			dfs(i, v);
}

void centDFS(int v, int p)
{
	par[v] = p;
	for(auto i : cent.ctree[v])
		if (i != p)
			centDFS(i, v);
}

void update(int v)
{
	int x = v;
	while(v)
	{
//		cout << v << " " << x << " " << dist(v, x) << endl;
		ans[v] = min(ans[v], 1ll*dist(v, x));
		v = par[v];
	}
}

int query(int v)
{
	int x = v;
	ll ret = INF;
	while(v)
	{
		ret = min(ret, ans[v] + dist(v, x));
		v = par[v];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	erep(i, 0, n) ans[i] = 1e18;

	node = vvi(n + 1);
	rep(i, 0, n-1)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
		cent.g[u].push_back(v);
		cent.g[v].push_back(u);
	}

	dfs(1, 0);
	buildSparse();

	cent.decompose(1);

	centDFS(root, 0);
	update(1);
	while(q--)
	{
		int t, u;
		cin >> t >> u;

		if (t == 1)
			update(u);
		else
			cout << query(u) << endl;
	}

	return 0;
}
