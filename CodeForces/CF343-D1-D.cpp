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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) { x, {y, z} }

const int N = 500000 + 5;
int lazy[4 * N], tree[4 * N], par[N], id, in[N], out[N], sz[N], nxt[N];
vvi node;

void dfs(int v, int p)
{
	par[v] = p;
	sz[v] = 1;
	int idx = -1, mx = -1;
	rep(i, 0, sz(node[v]))
	{
		int u = node[v][i];
		if (u == p)
			continue;
		dfs(u, v);
		sz[v] += sz[u];
		if (sz[u] > mx) // get heaviest child
			mx = sz[u], idx = i;
	}
	if (idx != -1)
		swap(node[v][0], node[v][idx]); // move heaviest child to the begining of the vector
}

void hld(int v, int p = 0)
{
	in[v] = ++id;
	for (auto u : node[v])
	{
		if (u == p)
			continue;
		nxt[u] = (u == node[v][0] ? nxt[v] : u); // first element in the current chain
		hld(u, v);
	}
	out[v] = id;
}

void propagate(int node, int st, int en)
{
	if (lazy[node] == 2)
		return;
	tree[node] = lazy[node];

	if (st != en)
		lazy[2 * node] = lazy[2 * node + 1] = lazy[node];

	lazy[node] = 2;
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		lazy[node] = val;
		propagate(node, st, en);
		return;
	}

	int mid = (st + en) / 2;

	update(2 * node, st, mid, shemal, yemeen, val);
	update(2 * node + 1, mid + 1, en, shemal, yemeen, val);
}

int query(int node, int st, int en, int shemal, int yemeen)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return 0;

	if (shemal <= st && en <= yemeen)
		return tree[node];

	int mid = (st + en) / 2;

	return query(2 * node, st, mid, shemal, yemeen)
			+ query(2 * node + 1, mid + 1, en, shemal, yemeen);
}

void etsha2lebFelHLD(int v)
{
	int u = 1;
	while (nxt[v] != nxt[u])
	{
		int l = in[nxt[v]], r = in[v]; // [head, myself]
		update(1, 0, id, l, r, 0);
		v = par[nxt[v]]; // move to the previous chain
	}
	update(1, 0, id, in[1], in[v], 0); // update the last chain
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	node = vvi(n + 1);
	rep(i, 0, n-1)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	nxt[1] = 1;
	dfs(1, 0);
	hld(1);

	int q;
	cin >> q;
	while (q--)
	{
		int t, a;
		cin >> t >> a;

		if (t == 1)
			update(1, 0, id, in[a], out[a], 1);
		else if (t == 2)
			etsha2lebFelHLD(a);
		else
			cout << query(1, 0, id, in[a], in[a]) << endl;
	}

	return 0;
}
