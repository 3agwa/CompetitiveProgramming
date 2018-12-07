// reference https://github.com/rezwan4029/SPOJ-solutions/blob/master/1716.%20Can%20you%20answer%20these%20queries%20III%20%5BGSS3%5D.cpp

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

const int MX = 50001;

int prefix[4 * MX], suffix[4 * MX], best[4 * MX], sum[4 * MX], arr[MX];

void build(int node, int st, int en)
{
	if (st > en)
		return;

	if (st == en)
	{
		prefix[node] = suffix[node] = best[node] = sum[node] = arr[st];
		return;
	}

	int mid = (st + en) / 2;

	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);

	prefix[node] = max(prefix[2 * node], sum[2 * node] + prefix[2 * node + 1]);
	suffix[node] = max(suffix[2 * node + 1],
			sum[2 * node + 1] + suffix[2 * node]);
	best[node] = max(suffix[2 * node] + prefix[2 * node + 1],
			max(best[2 * node], best[2 * node + 1]));
	sum[node] = sum[2 * node] + sum[2 * node + 1];
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		prefix[node] = suffix[node] = best[node] = sum[node] = val;
		return;
	}

	int mid = (st + en) / 2;

	update(2 * node, st, mid, shemal, yemeen, val);
	update(2 * node + 1, mid + 1, en, shemal, yemeen, val);

	prefix[node] = max(prefix[2 * node], sum[2 * node] + prefix[2 * node + 1]);
	suffix[node] = max(suffix[2 * node + 1],
			sum[2 * node + 1] + suffix[2 * node]);
	best[node] = max(suffix[2 * node] + prefix[2 * node + 1],
			max(best[2 * node], best[2 * node + 1]));
	sum[node] = sum[2 * node] + sum[2 * node + 1];
}

vi vec;

void solve(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		vec.push_back(node);
		return;
	}

	int mid = (st + en) / 2;

	solve(2 * node, st, mid, shemal, yemeen);
	solve(2 * node + 1, mid + 1, en, shemal, yemeen);
}

int query(int node, int st, int en, int shemal, int yemeen)
{
	vec.clear();

	solve(node, st, en, shemal, yemeen);

	int res = -2e9;
	int temp = -2e9;

	for (auto i : vec)
	{
		res = max(res, best[i]);
		res = max(res, temp + prefix[i]);
		temp = max(temp + sum[i], suffix[i]);
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(i, 0, n)
		cin >> arr[i];

	build(1, 0, n - 1);

	int q;
	cin >> q;

	while (q--)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if (!op)
			update(1, 0, n-1, l-1, l-1, r);
		else
			cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
	}

	return 0;
}
