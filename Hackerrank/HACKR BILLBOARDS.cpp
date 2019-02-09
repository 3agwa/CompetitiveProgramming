/*
 *  it's noticeable that it could be solved using dp in O(N*K) but this will lead to TLE
 *  let's try to simulate the same process of consecutive ranges but using a segment tree
 *  we'll iterate from N-1 --> 0, for each index we will consider cutting at that position
 *  then, the best result for this cut is the max value in [i + 1, i + k + 1]
 *  if we don't cut in the current position, then its value is added to the range [i + 1, i + k]
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

const int N = 1e6 + 100;
int n, k;
ll memo[N], lazy[4 * N], tree[4 * N], arr[N];

void propagate(int node, int st, int en)
{
	if (!lazy[node])
		return;

	tree[node] += lazy[node];
	if (st != en)
		lazy[2 * node] += lazy[node], lazy[2 * node + 1] += lazy[node];

	lazy[node] = 0;
}

void update(int node, int st, int en, int shemal, int yemeen, ll val)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		lazy[node] += val;
		propagate(node, st, en);
		return;
	}

	int mid = (st + en) / 2;
	update(2 * node, st, mid, shemal, yemeen, val);
	update(2 * node + 1, mid + 1, en, shemal, yemeen, val);

	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int st, int en, int shemal, int yemeen)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return 0;

	if (shemal <= st && en <= yemeen)
		return tree[node];

	int mid = (st + en) / 2;
	ll a = query(2 * node, st, mid, shemal, yemeen);
	ll b = query(2 * node + 1, mid + 1, en, shemal, yemeen);

	return max(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	rep(i, 0, n)
		cin >> arr[i];

	ll mx = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int st = min(n, i + 1), en = min(n, i + k + 1), en2 = min(n, i + k);
		ll curr = query(1, 0, n, st, en);
		update(1, 0, n, i, i, curr);
		update(1, 0, n, st, en2, arr[i]);
	}

	rep(i, 0, n)
		mx = max(mx, query(1, 0, n, i, i));

	cout << mx << endl;

	return 0;
}
