#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(int i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int n;

struct node
{
	node*l, *r;
	int mx;
	node()
	{
		l = r = NULL;
		mx = 0;
	}
};

void update(node* root, ll st, ll en, ll idx, int val)
{
	if (st == en)
	{
		root->mx = max(root->mx, val);
		return;
	}

	ll mid = (st + en) / 2;
	if (idx <= mid)
	{
		if (root->l == NULL)
			root->l = new node();
		update(root->l, st, mid, idx, val);
		root->mx = max(root->mx, root->l->mx);
	}

	if (mid + 1 <= idx)
	{
		if (root->r == NULL)
			root->r = new node();
		update(root->r, mid + 1, en, idx, val);
		root->mx = max(root->mx, root->r->mx);
	}
}

int query(node* curr, ll st, ll en, ll shemal, ll yemeen)
{
	if (st > en || st > yemeen || en < shemal || !curr)
		return 0;

	if (shemal <= st && en <= yemeen)
		return curr->mx;

	ll mid = (st + en) / 2;

	return max(query(curr->l, st, mid, shemal, yemeen),
			query(curr->r, mid + 1, en, shemal, yemeen));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	node* root = new node();
	cin >> n;
	vector<pair<ll, int>> vec(n);
	rep(i, 0, n)
		cin >> vec[i].first >> vec[i].second;
	sort(all(vec));
	rep(i, 0, n)
		vec[i].first += 1e9;

	for (int i = n - 1; i >= 0; i--)
	{
		ll idx = vec[i].first + vec[i].second;
		int mx = query(root, 0, 2e9, idx, 2e9);
		ll pos = vec[i].first - vec[i].second;
		update(root, 0, 2e9, pos, 1 + mx);
	}

	cout << root->mx << endl;

	return 0;
}
