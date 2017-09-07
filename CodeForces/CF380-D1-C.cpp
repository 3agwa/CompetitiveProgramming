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

const int MAX = 4000004;
int sum[MAX], open[MAX], close[MAX];
string x;

void build(int node, int st, int en)
{
	if (st > en) return;

	if (st == en)
	{
		x[st] == '(' ? open[node]++ : close[node]++;
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	int mn = min(open[2*node], close[2*node + 1]);

	sum[node] = sum[2*node] + sum[2*node + 1] + mn + mn;
	open[node] = open[2*node] + open[2*node + 1] - mn;
	close[node] = close[2*node] + close[2*node + 1] - mn;
}

pair<int, pii> query(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal) return {0, {0, 0}};

	if (shemal <= st && en <= yemeen) return {sum[node], {open[node], close[node]}};

	int mid = (st+en)/2;

	pair<int, pii> a = query(2*node, st, mid, shemal, yemeen);
	pair<int, pii> b = query(2*node + 1, mid + 1, en, shemal, yemeen);
	int mn = min(a.second.first, b.second.second);
	return {a.first + b.first + mn + mn, {a.second.first + b.second.first - mn, a.second.second + b.second.second - mn}};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x;
	int q, n = sz(x);
	cin >> q;
	build(1, 0, n-1);
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		pair<int, pii> hoba = query(1, 0, n-1, a, b);
		cout << hoba.first << endl;
	}
	return 0;
}
