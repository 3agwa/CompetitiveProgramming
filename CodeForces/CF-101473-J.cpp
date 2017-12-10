/*
 *  we want the maximum minimum roads possible, this indicates that we should get the maximum spanning tree of the graph
 *  that being done, we should build a sparse table for ancestors and the min-cost for each ancestor
 *  let x = LCA(u, v), now our solution would be min( query(u, x), query(v, x) )
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

set< pair<ll, pii> > st;
vvii node;
vvii tree;
int n, m, q;
vb visited;

const int lg = 21;
int cost[100001][21];
int lca[100001][21];
int depth[100001];

void explore(int v)
{
	for(auto i : node[v])
		if (!visited[i.first])
			st.insert({i.second, {i.first, v}});
}

void dfs(int v, int p)
{
	lca[v][0] = p;
	depth[v] = depth[p] + 1;

	for(auto i : tree[v])
		if(i.first != p)
			cost[i.first][0] = i.second, dfs(i.first, v);
}


void build_sparse()
{
	rep(i, 1, lg)
		erep(j, 1, n)
			lca[j][i] = lca[lca[j][i-1]][i-1];

	rep(i, 1, lg)
		erep(j, 1, n)
			cost[j][i] = min(cost[j][i-1], cost[lca[j][i-1]][i-1]);
}

/*0 0 0
50 40 0
20 20 20
40 0 0 */

int LCA(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v];

	rep(i, 0, lg)
		if (diff & (1<<i))
			u = lca[u][i];

	if (u != v)
	{
		for(int i = lg-1; i>=0; i--)
		{
			if (lca[u][i] != lca[v][i])
			{
				u = lca[u][i];
				v = lca[v][i];
			}
		}
		u = lca[u][0];
	}

	return u;
}

int query(int u, int v)
{
	if(depth[u] > depth[v])
		swap(v, u);

	int ret = INT_MAX;

	int level = depth[v] - depth[u];

	for(int i = 0; i < lg; i++)
		if(level & (1 << i))
			ret = min(ret, cost[v][i]), v = lca[v][i];

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;

	node = vvii(n + 1);
	visited = vb(n + 1);
	tree = vvii(n + 1);

	while(m--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		node[u].push_back({v, -c});
		node[v].push_back({u, -c});
	}

	visited[1] = true;
	explore(1);

	while(!st.empty())
	{
		auto i = st.begin();
		st.erase(st.begin());

		ll cost = i->first, idx = i->second.first;

		if (!visited[idx])
		{
			int u = i->second.first, v = i->second.second;
			tree[u].push_back({v, -cost});
			tree[v].push_back({u, -cost});
			visited[idx] = true;
			explore(idx);
		}
	}

	dfs(1, 1);

	build_sparse();

	/*erep(i, 1, n)
	{
		erep(j, 0, log2(n))
				cerr << cost[i][j] << " ";
		cerr << endl;
	}*/

	while(q--)
	{
		int u, v;
		cin >> u >> v;

		int common = LCA(u, v);

		cout << min(query(u, common), query(v, common)) << endl;
	}

	return 0;
}
