/*
 *  To simplify the problem, it's asking at what is the first position such that each index from [1, n] satisfies (sum >= X[i])
 *
 *  Let's imagine we have 1 point and Q queries, we could use binary search to solve such problem
 *  In our problem, we have N points and we're asked to do the same
 *
 *  We need a data structure that allows us to query different positions at a specific moment of time
 *  this could be done using persistent segment tree maintaining different versions after each update query
 *
 *  Now for each index, we binary search on its answer and access the values using the persistent segment tree
 *  In the Tree struct, the variable "val" allows us to perform range sum update and range sum query as if we're applying lazy propagation
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

const int N = 3e5 + 5;
ll need[N];
vi pos[N];
struct tree
{
	long long val;
	tree *left, *right;

	tree(long long _val = 0, tree* _left = NULL, tree* _right = NULL)
	{
		val = _val;
		left = _left;
		right = _right;
	}

	void build_tree(int L, int R)
	{
		if (L == R)
			return;

		int mid = (L + R) / 2;
		left = new tree;
		left->build_tree(L, mid);
		right = new tree;
		right->build_tree(mid + 1, R);
	}

	tree* update(int L, int R, int qL, int qR, long long v)
	{
		if (L > qR || R < qL)
			return this;

		if (qL <= L && R <= qR)
		{
			tree* new_node = new tree(val, left, right);
			new_node->val += v;
			return new_node;
		}

		tree* new_node = new tree(val);
		int mid = (L + R) / 2;
		new_node->left = left->update(L, mid, qL, qR, v);
		new_node->right = right->update(mid + 1, R, qL, qR, v);

		return new_node;
	}

	long long query(int L, int R, int x)
	{
		if (L == R)
			return val;

		int mid = (L + R) / 2;
		if (x <= mid)
		{
			return val + left->query(L, mid, x);
		}
		else
		{
			return val + right->query(mid + 1, R, x);
		}
	}
} *roots[N];

int n, m;

int main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin >> n >> m;
	roots[0] = new tree();
	roots[0]->build_tree(1, m);

	erep(i, 1, m)
	{
		int x;
		cin >> x;
		pos[x].push_back(i);
	}

	erep(i, 1, n)
		cin >> need[i];

	int q;
	cin >> q;
	erep(i, 1, q)
	{
		int l, r;
		ll v;
		cin >> l >> r >> v;
		if (l > r)
		{
			roots[i] = roots[i-1]->update(1, m, l, m, v);
			roots[i] = roots[i]->update(1, m, 1, r, v);
		}
		else
		{
			roots[i] = roots[i-1]->update(1, m, l, r, v);
		}
	}

	erep(i, 1, n)
	{
		int st = 1, en = q, mid, ret = -1;

		while(st <= en)
		{
			mid = (st+en)/2;
			ll sum = 0;
			for(auto x : pos[i])
			{
				sum += roots[mid]->query(1, m, x);
				if (sum >= need[i])
					break;
			}
			if (sum >= need[i])
				en = mid - 1, ret = mid;
			else
				st = mid + 1;
		}

		if (ret == -1)
			cout << "NIE\n";
		else
			cout << ret << endl;
	}
	return 0;
}
