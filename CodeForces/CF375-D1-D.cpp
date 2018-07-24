#include <bits/stdc++.h>
#include <unordered_map>

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

const int N = 1e5 + 5;
int f[N], ff[N], in[N], out[N], ans[N], col[N], arr[N], id, sq, n, q, idxxx;
vvi node;

void dfs(int v, int p)
{
	in[v] = ++id;
	arr[id] = col[v];
	for (auto i : node[v])
		if (i != p)
			dfs(i, v);

	out[v] = id;
}

bool cmp(pair<int, pii> a, pair<int, pii> b)
{
	if (a.first / sq != b.first / sq)
		return a.first / sq < b.first / sq;
	return a.second.first < b.second.first;
}

void add(int &x)
{
	++f[x];
	++ff[f[x]];
}

void remove(int &x)
{
	--ff[f[x]];
	--f[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	rep(i, 0, n)
		cin >> col[i];
	node = vvi(n + 1);
	sq = sqrt(n);
	vector<pair<int, pii>> queries(q);

	rep(i, 0, n-1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(0, -1);

	vi vec;
	rep(i, 0, q)
	{
		int u, x;
		cin >> u >> x;
		u--;
		vec.push_back(x);
		int a = in[u], b = out[u];
		queries[i] = mp(a, b, i);
	}

	sort(all(queries), cmp);

	int moL = 0, moR = -1;
	rep(i, 0, q)
	{
		int l = queries[i].first, r = queries[i].second.first, idx =
				queries[i].second.second;
		while (moR < r)
			add(arr[++moR]);
		while (moL > l)
			add(arr[--moL]);
		while (moR > r)
			remove(arr[moR--]);
		while (moL < l)
			remove(arr[moL++]);
		ans[idx] = ff[vec[idx]];
	}
	rep(i, 0, q)
		cout << ans[i] << endl;

	return 0;
}
