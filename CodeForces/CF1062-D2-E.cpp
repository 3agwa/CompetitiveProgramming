/*
 *  since we could remove 1 node from the range, it's easy to see that it's optimal to choose one 
 *  either on the very left or the very right of the range when it's represented as a tree
 *  this is mainly because these 2 nodes are the ones that might give a better lca after removing them
 *  hence, we want to know the min/max inTime for each node in the range, this could be done using sparse table or segment tree
 *  now we know the possible indices from which we want to get the result of lca( lca(l, idx - 1), lca(idx + 1, r) )
 *  this could also be done using sparse table or segment tree carrying the lca of the nodes in the given range
 *  refer to the code below to check how to handle lca query on ranges carefully
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

const int N = 1e5 + 5;
int n, q;
int in[N], out[N], id;
int lcaTree[4 * N];
pii mnTree[4 * N], mxTree[4 * N];
int depth[N], sp[N][18];
vvi node;

void dfs(int v, int p)
{
	depth[v] = 1 + depth[p];
	sp[v][0] = p;
	in[v] = ++id;
	for (auto i : node[v])
		if (i != p)
			dfs(i, v);
	out[v] = id;
}

void buildSp()
{
	erep(j, 1, 17)
		erep(i, 1, n)
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
}

int lca(int u, int v)
{
	if (depth[v] > depth[u])
		swap(u, v);

	int diff = depth[u] - depth[v];
	for (int i = 17; i >= 0; i--)
		if (diff & (1 << i))
			u = sp[u][i];

	if (u == v)
		return u;

	for (int i = 17; i >= 0; i--)
		if (sp[u][i] != sp[v][i])
			u = sp[u][i], v = sp[v][i];

	return sp[u][0];
}

void buildMMTree(int node, int st, int en)
{
	if (st > en)
		return;
	if (st == en)
	{
		mnTree[node] = mxTree[node] =
		{	in[st], st};
		return;
	}
	int mid = (st + en) / 2;
	buildMMTree(2 * node, st, mid);
	buildMMTree(2 * node + 1, mid + 1, en);
	mnTree[node] = min(mnTree[2 * node], mnTree[2 * node + 1]);
	mxTree[node] = max(mxTree[2 * node], mxTree[2 * node + 1]);
}

void buildLcaTree(int node, int st, int en)
{
	if (st > en)
		return;
	if (st == en)
	{
		lcaTree[node] = st;
		return;
	}
	int mid = (st + en) / 2;
	buildLcaTree(2 * node, st, mid);
	buildLcaTree(2 * node + 1, mid + 1, en);
	lcaTree[node] = lca(lcaTree[2 * node], lcaTree[2 * node + 1]);
}

// flag = 1 = max
pii queryMM(int node, int st, int en, int shemal, int yemeen, bool flag)
{
	if (st > en || st > yemeen || en < shemal || shemal > yemeen)
	{
		if (flag)
			return
			{	0, 0};
		return
		{	1e9, 1e9};
	}

	if (shemal <= st && en <= yemeen)
	{
		if (flag)
			return mxTree[node];
		return mnTree[node];
	}

	int mid = (st + en) / 2;

	pii a = queryMM(2 * node, st, mid, shemal, yemeen, flag);
	pii b = queryMM(2 * node + 1, mid + 1, en, shemal, yemeen, flag);

	if (flag)
		return max(a, b);
	return min(a, b);
}

int queryLca(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal || shemal > yemeen)
		return -1;

	if (shemal <= st && en <= yemeen)
		return lcaTree[node];

	int mid = (st + en) / 2;

	int a = queryLca(2 * node, st, mid, shemal, yemeen);
	int b = queryLca(2 * node + 1, mid + 1, en, shemal, yemeen);
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	return lca(a, b);
}

int getResult(int idx, int l, int r)
{
	if (idx == l)
		return queryLca(1, 0, id, l + 1, r);
	if (idx == r)
		return queryLca(1, 0, id, l, r - 1);
	return lca(queryLca(1, 0, id, l, idx - 1), queryLca(1, 0, id, idx + 1, r));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	rep(i, 0, 4*N)
		mnTree[i] =
		{	1e9, 1e9};

	cin >> n >> q;
	node = vvi(n + 1);
	erep(i, 2, n)
	{
		int v;
		cin >> v;
		node[i].push_back(v);
		node[v].push_back(i);
	}
	dfs(1, 0);
	buildSp();
	buildMMTree(1, 0, id);
	buildLcaTree(1, 0, id);

	while (q--)
	{
		int l, r;
		cin >> l >> r;

		pii i1 = queryMM(1, 0, id, l, r, 0);
		pii i2 = queryMM(1, 0, id, l, r, 1);

		int r1 = getResult(i1.second, l, r);
		int r2 = getResult(i2.second, l, r);

		if (depth[r1] > depth[r2])
			cout << i1.second << " " << depth[r1] - 1 << endl;
		else
			cout << i2.second << " " << depth[r2] - 1 << endl;
	}

	return 0;
}
