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
#define mod(n, m) (1ll*n >= mod ? (1ll*n - mod) : (1ll*n < 0 ? (1ll*n + mod)%mod : n))
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

struct node
{
	node *lc, *rc;
	int lazyl, lazyr;
	int bound;

	node()
	{
		lc = rc = 0;
		bound = 0;
		lazyl = lazyr = 0;
	}
};

void propagate(node *curr, int st, int en, int &lazy)
{
	if (!lazy)
		return;

	curr->bound = max(curr->bound, lazy);
	curr->lazyl = max(curr->lazyl, lazy);
	curr->lazyr = max(curr->lazyr, lazy);

	lazy = 0;
}

void update(node* curr, int st, int en, int shemal, int yemeen, int val)
{
	if (shemal <= st && en <= yemeen)
	{
		curr->bound = max(curr->bound, val);
		curr->lazyl = max(curr->lazyl, val);
		curr->lazyr = max(curr->lazyr, val);
		return;
	}

	int mid = (st + en) / 2;

	if (shemal <= mid)
	{
		if (!curr->lc)
			curr->lc = new node();
		propagate(curr->lc, st, mid, curr->lazyl);
		update(curr->lc, st, mid, shemal, yemeen, val);
	}

	if (mid + 1 <= yemeen)
	{
		if (!curr->rc)
			curr->rc = new node();
		propagate(curr->rc, mid + 1, en, curr->lazyr);
		update(curr->rc, mid + 1, en, shemal, yemeen, val);
	}

	if (curr->lc)
	{
		propagate(curr->lc, st, mid, curr->lazyl);
		curr->bound = max(curr->bound, curr->lc->bound);
	}

	if (curr->rc)
	{
		propagate(curr->rc, mid + 1, en, curr->lazyr);
		curr->bound = max(curr->bound, curr->rc->bound);
	}
}

int query(node *curr, int st, int en, int shemal, int yemeen)
{
	if (shemal <= st && en <= yemeen)
		return curr->bound;

	int mid = (st + en) / 2;

	int ret = 0;
	if (shemal <= mid)
	{
		if (!curr->lc)
			curr->lc = new node();
		propagate(curr->lc, st, mid, curr->lazyl);
		ret = max(ret, query(curr->lc, st, mid, shemal, yemeen));
	}

	if (mid + 1 <= yemeen)
	{
		if (!curr->rc)
			curr->rc = new node();
		propagate(curr->rc, mid + 1, en, curr->lazyr);
		ret = max(ret, query(curr->rc, mid + 1, en, shemal, yemeen));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	node *up = new node();
	node *left = new node();

	int n, q;
	cin >> n >> q;
	while(q--)
	{
		int x, y;
		char c;
		cin >> x >> y >> c;

		if (c == 'U')
		{
			int foo2 = query(up, 1, n, x, x);
			cout << y - foo2 << endl;
			update(up, 1, n, x, x, y);
			update(left, 1, n, foo2, y, x);
		}
		else
		{
			int shemal = query(left, 1, n, y, y);

			cout << x - shemal << endl;
			update(left, 1, n, y, y, x);
			update(up, 1, n, shemal, x, y);
		}
	}

	return 0;
}
