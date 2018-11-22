/*
 *	we need to find the answer for a specific X given an interval [L, R] this often refers to line sweep
 *	consider we have a valid windown for the current position, we need to find how many shops can deliver to my place
 *	since the shops have different positions with different qualities, it's a good idea to generalize this form
 *	we'll do that by stating for each shop, the quality it would have at X = 0
 *	now for any given query, we could get the customer's quality at X = 0 and our answer would be
 *	the sum of shops that have quality >= the customer's quality
 *	since the values are too large, i use implicit segment tree to solve this problem
 *	one more thing that will arise, the quality values could get -ve coordinates, it produces a bug in segment tree
 *	a solution to this is to SHIFT the coordinates so that they're always non-negative
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

struct node
{
	node *l, *r;
	int sum;

	node()
	{
		l = r = 0;
		sum = 0;
	}
};

const int shift = 1e9;

void del(node *curr)
{
	if (curr->l)
		del(curr->l);
	if (curr->r)
		del(curr->r);
	delete (curr);
}

void update(node* curr, ll st, ll en, int shemal, int yemeen, int val)
{
	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		curr->sum += val;
		return;
	}

	ll mid = (st + en) / 2;

	if (shemal <= mid)
	{
		if (!curr->l)
			curr->l = new node();
		update(curr->l, st, mid, shemal, yemeen, val);
	}

	if (mid + 1 <= yemeen)
	{
		if (!curr->r)
			curr->r = new node();
		update(curr->r, mid + 1, en, shemal, yemeen, val);
	}

	curr->sum = 0;
	if (curr->l)
		curr->sum += curr->l->sum;
	if (curr->r)
		curr->sum += curr->r->sum;
}

int query(node* curr, ll st, ll en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal || !curr)
		return 0;

	if (shemal <= st && en <= yemeen)
		return curr->sum;

	ll mid = (st + en) / 2;

	int a = query(curr->l, st, mid, shemal, yemeen);
	int b = query(curr->r, mid + 1, en, shemal, yemeen);

	return a + b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		node *root = new node();
		int n, m;
		cin >> n >> m;
		vector<pair<int, pii>> vec;
		rep(i, 0, n)
		{
			ll x, q, r;
			cin >> x >> q >> r;
			vec.push_back(
			{ x,
			{ 1, q - x + shift } });
			vec.push_back(
			{ x + r + 1,
			{ 0, q - x + shift } });
		}
		sort(all(vec));

//		for (auto i : vec)
//			cout << i.first << " " << i.second.first << " " << i.second.second
//					<< endl;
//		cout << endl;

		int idx = 0;
		rep(i, 0, m)
		{
			ll y, d;
			cin >> y >> d;

			d -= y;
			d += shift;
//			cout << "----> " << d << endl;
			while (idx < sz(vec) && vec[idx].first <= y)
			{
				if (!vec[idx].second.first)
					update(root, 0, 2e9, vec[idx].second.second,
							vec[idx].second.second, -1);
				else
					update(root, 0, 2e9, vec[idx].second.second,
							vec[idx].second.second, 1);
				idx++;
			}

			if (i)
				cout << " ";
			cout << query(root, 0, 2e9, d, 2e9);
		}
		cout << endl;
		del(root);
	}

	return 0;
}
