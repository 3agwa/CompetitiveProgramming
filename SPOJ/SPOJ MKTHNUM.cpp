/*
    we'll keep a merge sort segment tree carrying the indices of the array (after sorting it)
    when getting a query, we'll traverse the tree to the left/right child
    according to which child contains the target index
    the returned index is the index of our solution in the main array
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

const int MAX = 100001;

vii arr;
vector<int> tree[4*MAX];

void build(int node, int st, int en)
{
	if (st > en) return;

	if (st == en)
	{
		tree[node].push_back(arr[st].second);
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	merge(all(tree[2*node]), all(tree[2*node + 1]), back_inserter(tree[node]));
}

int query(int node, int st, int en, int shemal, int yemeen, int idx)
{
	if (st == en) return tree[node][0];

	int mid = (st+en)/2;

	auto it = upper_bound(all(tree[2*node]), yemeen);
	int total = it - lower_bound(all(tree[2*node]), shemal);

	if (total >= idx) return query(2*node, st, mid, shemal, yemeen, idx);
	return query(2*node + 1, mid + 1, en, shemal, yemeen, idx - total);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	arr = vii(n);
	vi yay;
	rep(i, 0, n)
	{
		cin >> arr[i].first, arr[i].second = i;
		yay.push_back(arr[i].first);
	}
	sort(all(arr));
	build(1, 0, n-1);

	while(q--)
	{
		int l, r, idx;
		cin >> l >> r >> idx;
		l--, r--;

		cout << yay[query(1, 0, n-1, l, r, idx)] << endl;
	}

	return 0;
}
