// the main idea: if the maximum suffix sum to this node is >= 0 then it's black
// query of type 1, update the position of node V
// query of type 2, update the subtree by -1, also if the answer to query #3 on the same node is >= 0
// then you should update the position of node V by - ans - 1 (to cancel the maximum suffix sum)
// if the answer to query # 3 is >= 0 then this node is colored in black, otherwise it's white 
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
#define rep(i, x, n) for(int i = x; i<(ll)(n); i++)
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

const int N = 100000 + 5;
int lazy[4 * N], par[N], id, in[N], out[N], sz[N], nxt[N];
int n, q;
vvi node;

struct Node
{
	int sum, mx;
} tree[4 * N];

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

Node merge(Node l, Node r)
{
	Node ret;
	ret.sum = l.sum + r.sum;
	// ya ema ha5od el suffix beta3 el left + kol el right
	// aw ha5od el suffix beta3 el right
	ret.mx = max(l.mx + r.sum, r.mx);
	return ret;
}

void build(int node, int st, int en)
{
	if (st > en)
		return;
	if (st == en)
	{
		tree[node].mx = tree[node].sum = -1;
		return;
	}

	int mid = (st + en) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);

	tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void propagate(int node, int st, int en)
{
	if (lazy[node])
	{
		tree[node] =
		{	-(en - st + 1), -1};

		if (st != en)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node + 1] = lazy[node];
		}
	}
	lazy[node] = 0;
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

	tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void updatePos(int node, int st, int en, int shemal, int yemeen, int val)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		tree[node].mx += val;
		tree[node].sum += val;
		return;
	}

	int mid = (st + en) / 2;

	updatePos(2 * node, st, mid, shemal, yemeen, val);
	updatePos(2 * node + 1, mid + 1, en, shemal, yemeen, val);

	tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node get(int node, int st, int en, int shemal, int yemeen)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
	{
		Node ret;
		ret.mx = -1e9;
		ret.sum = 0;
		return ret;
	}

	if (shemal <= st && en <= yemeen)
		return tree[node];

	int mid = (st + en) / 2;

	return merge(get(2 * node, st, mid, shemal, yemeen),
			get(2 * node + 1, mid + 1, en, shemal, yemeen));
}

int query(int v, int curr)
{
	if (nxt[v] == nxt[1])
		return curr + get(1, 1, id, 1, in[v]).mx;
	auto temp = get(1, 1, id, in[nxt[v]], in[v]);
	return max(curr + temp.mx, query(par[nxt[v]], curr + temp.sum));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	node = vvi(n + 1);
	erep(i, 2, n)
	{
		int p;
		cin >> p;
		node[p].push_back(i);
		node[i].push_back(p);
	}

	nxt[1] = 1;
	dfs(1, 0);
	hld(1);

	build(1, 1, id);

	while (q--)
	{
		int t, v;
		cin >> t >> v;

		if (t == 1)
			updatePos(1, 1, id, in[v], in[v], 1);
		else if (t == 2)
		{
			update(1, 1, id, in[v], out[v], 1);
			int ret = query(v, 0);
			if (ret >= 0)
				updatePos(1, 1, id, in[v], in[v], -ret - 1);
		}
		else
		{
			if (query(v, 0) >= 0)
				cout << "black\n";
			else
				cout << "white\n";
		}
	}

	return 0;
}
