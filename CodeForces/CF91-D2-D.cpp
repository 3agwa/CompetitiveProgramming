/*
 *  We'd like to know the furthest element smaller than a[i]
 *  We could do this by maintaining a min segment tree over the ranges
 *  To answer for a specific a[i] we'll binary search for the furtherst L in an interval [L, R]
 *  such that the minimum in this range is < a[i]
 */
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
#define mp(x, y, z) { x, {y, z } }

const int N = 1e5 + 5;

int arr[N], tree[4*N];

void build(int node, int st, int en)
{
	if (st > en)
		return;

	if (st == en)
	{
		tree[node] = arr[st];
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	tree[node] = min(tree[2*node], tree[2*node + 1]);
}

int query(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal)
		return 2e9;

	if (shemal <= st && en <= yemeen)
		return tree[node];

	int mid = (st+en)/2;

	return min(query(2*node, st, mid, shemal, yemeen), query(2*node + 1, mid + 1, en, shemal, yemeen));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	rep(i, 0, 4*N) tree[i] = 2e9;

	rep(i, 0, n)
		cin >> arr[i];
	build(1, 0, n-1);
	rep(i, 0, n)
	{
		int st = i + 1, en = n - 1, mid, ret = -1;

		while(st <= en)
		{
			mid = (st+en)/2;

			if (query(1, 0, n-1, mid, n - 1) < arr[i])
				st = mid + 1, ret = mid;
			else
				en = mid - 1;
		}

		if (ret == -1)
			cout << ret << " ";
		else
			cout << ret - 1 - i << " ";
	}

	return 0;
}

