/*
 *  we need the k-th element in a specific path
 *  this is equivalent to getting the kth element from u, v, lca(u, v)
 *  however, overlapping could occur, so we should subtract the elements from
 *  u->lca(u, v) and from parent(lca(u, v))->v
 *  now, to compute the kth element in a path, we could use segment tree for this purpose
 *  but since we can't build n^2 size segment tree for all paths, we'll use persistent segment tree
 *  this allows us to have an overall of NlogN memory, where maximum logN new nodes are created per update
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

struct Node
{
	int cnt, left, right;
};

int n, m, mx = 1, cnt;
const int lg = 19, last = 123455;
mapii mp, rev;
vi vec;
vvi node;

Node tree[123456 * lg];
int parent[123456][lg], depth[123456], root[123456];

int insert(int prev, int st, int en, int idx)
{
	int curr = ++cnt; // number of node
	tree[curr] = tree[prev];

	tree[curr].cnt++;

	int mid = (st+en)/2;

	if (st < en)
	{
		if (idx <= mid)
			tree[curr].left = insert(tree[prev].left, st, mid, idx);
		else
			tree[curr].right = insert(tree[prev].right, mid + 1, en, idx);
	}

	return curr;
}

int query(int u, int v, int lca, int plca, int st, int en, int k)
{
	if (st == en)
		return st;

	int cnt = tree[ tree[u].left ].cnt;
	cnt += tree[ tree[v].left ].cnt;
	cnt -= tree[ tree[lca].left ].cnt;
	cnt -= tree[ tree[plca].left ].cnt;

	int mid = (st+en)/2;

	if (k <= cnt)
		return query(tree[u].left, tree[v].left, tree[lca].left, tree[plca].left, st, mid, k);
	else
		return query(tree[u].right, tree[v].right, tree[lca].right, tree[plca].right, mid + 1, en, k - cnt);
}

void dfs(int v, int p)
{
	parent[v][0] = p;
	depth[v] = depth[p] + 1;

	int idx = mp[vec[v]];

	root[v] = insert(root[p], 1, n, idx);

	for(auto i : node[v])
		if (i != p)
			dfs(i, v);
}

int LCA(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v];

	rep(i, 0, lg)
		if (diff & (1<<i))
			u = parent[u][i];

	if (u != v)
	{
		for(int i = lg-1; i>=0; i--)
		{
			if (parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}

	return u;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vec = vi(n + 1), node = vvi(n + 1);

	multiset<int> ms;
	erep(i, 1, n) cin >> vec[i], ms.insert(vec[i]);

	for(auto i : ms) mp[i] = mx, rev[mx] = i, mx++;

	rep(i, 0, n-1)
	{
		int u, v;

		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	dfs(1, 0);

	rep(i, 1, lg)
	{
		erep(j, 1, n)
		{
			parent[j][i] = parent[parent[j][i-1]][i - 1];
		}
	}

	while(m--)
	{
		int u, v, k;
		cin >> u >> v >> k;

		int lca = LCA(u, v);

		int ret = query(root[u], root[v], root[lca], root[ parent[lca][0] ], 1, n, k);

		cout << rev[ret] << endl;
	}
	return 0;
}
