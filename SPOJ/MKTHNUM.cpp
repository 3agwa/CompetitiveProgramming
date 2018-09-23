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
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 100000 + 5;

struct node
{
	int l, r, cnt;

	node()
	{
		l = r = 0;
		cnt = 0;
	}
} tree[20*N]; // each persistent version holds a range inside this tree, maximum nodes created is NlogN

int arr[N], sz, root[N]; // N persistent versions
vi vec;

void update(int &curr, int prev, int st, int en, int idx)
{
	curr = ++sz;					// gives id to the current node
	tree[curr] = tree[prev];		// new node has the same values as the old node
	if (st == en)
	{
		tree[curr].cnt++;
		return;
	}

	int mid = (st + en) / 2;

	if (idx <= mid)					// move towards the target
		update(tree[curr].l, tree[prev].l, st, mid, idx);
	else
		update(tree[curr].r, tree[curr].r, mid + 1, en, idx);

	tree[curr].cnt = tree[tree[curr].l].cnt + tree[tree[curr].r].cnt;
}

int query(int curr, int prev, int st, int en, int idx)
{
	if (st == en)
		return st;
	int cnt = tree[tree[curr].l].cnt - tree[tree[prev].l].cnt;
	int mid = (st + en) / 2;
	if (idx <= cnt)
		return query(tree[curr].l, tree[prev].l, st, mid, idx);
	return query(tree[curr].r, tree[prev].r, mid + 1, en, idx - cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	erep(i, 1, n)
		cin >> arr[i], vec.push_back(arr[i]);
	sort(all(vec));
	erep(i, 1, n)
		arr[i] = lower_bound(all(vec), arr[i]) - vec.begin() + 1;

	int s = sz(vec);
	update(root[1], 0, 1, s, arr[1]);
	erep(i, 2, n)
		update(root[i], root[i - 1], 1, s, arr[i]);

	while (q--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		int ret = query(root[r], root[l - 1], 1, s, x);
		cout << vec[ret - 1] << endl;
	}

	return 0;
}
