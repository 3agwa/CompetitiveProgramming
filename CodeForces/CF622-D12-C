/*
 *  use a merge sort segment tree to keep track of the sorted ranges
 *  sort the ranges by value then index
 *  for each query, we want to find the upper bound of {x, n}, index should be n in order to get the next value > x
 *  in case we added an index smaller than n, we might get a pair of {x, y | y < n} - we don't want that -
 *  we lower bound on {x, -1} as we'll decrement the index by 1 (insured that the value is not x)
 *  if we found a valid answer, we return it or return -1 otherwise 
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

const int mx = 2e5 + 10;

int n, m, arr[mx];
vector< pii > tree[4*mx];

void build(int node, int st, int en)
{
	if (st > en)
		return;

	if (st == en)
	{
		tree[node].push_back({arr[st], st + 1});
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	merge(all(tree[2*node]), all(tree[2*node + 1]), back_inserter(tree[node]));
}

int query(int node, int st, int en, int shemal, int yemeen, int val)
{
	if (st > en || st > yemeen || en < shemal)
		return -1;

	if (shemal <= st && en <= yemeen)
	{
		int t = upper_bound(all(tree[node]), pii(val, n)) - tree[node].begin();

		if (t != sz(tree[node]))
			return tree[node][t].second;

		t = lower_bound(all(tree[node]), pii(val, -1)) - tree[node].begin();
		t--;

		if (t >= 0)
			return tree[node][t].second;
		return -1;
	}

	int mid = (st+en)/2;

	return max(query(2*node, st, mid, shemal, yemeen, val), query(2*node + 1, mid + 1, en, shemal, yemeen, val));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, 0, n) cin >> arr[i];

	build(1, 0, n-1);

	while(m--)
	{
		int l, r, x;
		cin >> l >> r >> x;

		l--, r--;

		int ret = query(1, 0, n-1, l, r, x);
		cout << ret << endl;
	}
	return 0;
}
