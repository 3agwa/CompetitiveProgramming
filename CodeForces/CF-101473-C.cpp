/*
 *  since the number of nodes/edges is not large, we could tear down the tree and re-build it with each query
 *  before re-building the tree, we should update the info regarding the 2 nodes, their parents and their children
 *  answering each query could be done with a recursive naiive approach
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

// el int aslan 7aram [[fakss]]

unsigned short n, m, q, mn, u, v, a, b;
char c;
vector< unsigned short > age;
vector< vector< unsigned short > >  tree, itree;
bool visited[501];

void getparent(unsigned short src, unsigned short v)
{
	if (src != v)
		mn = min(mn, age[v]);
	visited[v] = true;
	for(auto i : itree[v])
		if(!visited[i])
			getparent(src, i);
}

void fakss()
{
	rep(i, 0, n)
	{
		while(!tree[i].empty())
			tree[i].pop_back();
		while(!itree[i].empty())
			itree[i].pop_back();
	}
}

vector< pair<unsigned short, unsigned short> > edge;

void build(unsigned short u, unsigned short v)
{
	rep(i, 0, sz(edge))
	{
		int a = edge[i].first, b = edge[i].second;

		if (a == u)
			a = v;
		else if (a == v)
			a = u;

		if (b == u)
			b = v;
		else if (b == v)
			b = u;

		edge[i].first = a, edge[i].second = b;
	}

	rep(i, 0, sz(edge))
	{
		tree[edge[i].first].push_back(edge[i].second);
		itree[edge[i].second].push_back(edge[i].first);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	age = vector<unsigned short>(n);

	tree = vector< vector< unsigned short > >(n);
	itree = vector< vector< unsigned short > > (n);
	rep(i, 0, n) cin >> age[i];

	while(m--)
	{
		cin >> u >> v;
		u--, v--;
		edge.push_back({u, v});
		tree[u].push_back(v);
		itree[v].push_back(u);
	}

	while(q--)
	{
		cin >> c;
		if (c == 'T')
		{
			cin >> a >> b;
			a--, b--;

			fakss();
			build(a, b);
		}
		else
		{
			cin >> a;
			a--;
			mn = USHRT_MAX;
			reset(visited, false);
			getparent(a, a);
			if (mn == USHRT_MAX)
				cout << "*\n";
			else
				cout << mn << endl;
		}
	}
	return 0;
}
