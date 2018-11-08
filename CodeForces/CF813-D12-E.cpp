/*
 *  it's easy to notice that the problem could be solved using merge sort segment tree
 *  the only problem is that we need to find different values < k
 *  we could iterate over all values and query the same thing for the range but this operation takes too much time
 *  we can replace each pos in our array with -1 if freq[x] < k or replace it with pos[x][sz(x) - k] if freq[x] >= k
 *  this allows us to query on all values less than L and it will return a correct answer
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

const int N = 100000 + 5;
int n, k;
int x, arr[N];
vi tree[4 * N];
vi pos[N];

void build(int node, int st, int en)
{
	if (st > en)
		return;

	if (st == en)
	{
		tree[node].push_back(arr[st]);
		return;
	}

	int mid = (st + en) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);

	merge(all(tree[2 * node]), all(tree[2 * node + 1]),
			back_inserter(tree[node]));
}

int query(int node, int st, int en, int shemal, int yemeen, int k)
{
	if (st > en || st > yemeen || en < shemal)
		return 0;

	if (shemal <= st && en <= yemeen)
		return lower_bound(all(tree[node]), k) - tree[node].begin();

	int mid = (st + en) / 2;

	int a = query(2 * node, st, mid, shemal, yemeen, k);
	int b = query(2 * node + 1, mid + 1, en, shemal, yemeen, k);

	return a + b;
}

int main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin >> n >> k;
	rep(i, 0, n)
	{
		cin >> x;
		if (sz(pos[x]) < k)
			arr[i] = -1;
		else
			arr[i] = pos[x][sz(pos[x]) - k];
		pos[x].push_back(i);
	}

	build(1, 0, n - 1);

	int l = 0, r = 0, last = 0;

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		l = ((x + last) % n) + 1;
		r = ((y + last) % n) + 1;
		if (l > r)
			swap(l, r);
		l--, r--;
		last = query(1, 0, n - 1, l, r, l);
		cout << last << endl;
	}

	return 0;
}
