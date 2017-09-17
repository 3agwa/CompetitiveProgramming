/*
    we want to find the best sum in a given range, we'll use a segment tree to find the required values.
    
    we'll have to keep track, for each node:
    the number on its left, the number on its right, the best prefix sum, the best suffix sum, and the current best sum
    
    when merging 2 nodes, the new node's left value is the left node's left value
    the new node's right value is the right node's right value
    this is intuitive as we're merging 2 blocks 
    if we're merging 2 nodes carrying the same number, then we should maximize the current best max with their summation
    
    our prefix sum is either the left node's prefix sum, or that sum + right node's prefix sum (in case they have the same number)
    same goes for suffix sum with right children
    
    this way we can maintain the best possible sum in a given range
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

int arr[100001];

struct seg_tree
{
	int prefix, suffix, mx, left, right;

	seg_tree()
	{
		prefix = suffix = mx = left = right = 0;
	}

	seg_tree(int p, int s, int m, int l, int r)
	{
		prefix = p, suffix = s;
		mx = m;
		left = l, right = r;
	}
};

seg_tree tree[400004];

void build(int node, int st, int en)
{
	if (st > en) return;

	if (st == en)
	{
		tree[node] = seg_tree(1, 1, 1, arr[st], arr[st]);
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid +1 , en);

	tree[node].mx = max(tree[2*node].mx, tree[2*node + 1].mx);
	tree[node].left = tree[2*node].left;
	tree[node].right = tree[2*node + 1].right;

	if (tree[2*node].right == tree[2*node + 1].left)
		tree[node].mx = max(tree[node].mx, tree[2*node].suffix + tree[2*node + 1].prefix);

	if (tree[2*node].left == tree[2*node + 1].left)
		tree[node].prefix = tree[2*node].prefix + tree[2*node + 1].prefix;
	else tree[node].prefix = tree[2*node].prefix;

	if (tree[2*node].right == tree[2*node + 1].right)
		tree[node].suffix = tree[2*node].suffix + tree[2*node + 1].suffix;
	else tree[node].suffix = tree[2*node + 1].suffix;
}

seg_tree query(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal) return seg_tree(0, 0, 0, 0, 0);

	if (shemal <= st && en <= yemeen) return tree[node];

	int mid = (st+en)/2;

	seg_tree a = query(2*node, st, mid, shemal, yemeen);
	seg_tree b = query(2*node + 1, mid + 1, en, shemal, yemeen);

	seg_tree ret;

	ret.mx = max(a.mx, b.mx);
	ret.left = a.left;
	ret.right = b.right;

	if (a.right == b.left)
		ret.mx = max(ret.mx, a.suffix + b.prefix);

	if (a.left == b.left)
		ret.prefix = a.prefix+ b.prefix;
	else ret.prefix= a.prefix;

	if (a.right == b.right)
		ret.suffix = a.suffix + b.suffix;
	else ret.suffix = b.suffix;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	while(cin >> n && n)
	{
		rep(i, 0, 400004) tree[i] = seg_tree(0, 0, 0, 0, 0);
		cin >> q;

		rep(i, 0, n) cin >> arr[i];

		build(1, 0, n-1);

		while(q--)
		{
			int l, r;
			cin >> l >> r;
			l--, r--;

			cout << query(1, 0, n-1, l, r).mx << endl;
		}
	}
	return 0;
}

