/*
 *  first off, we'll have to compress the input to fit a 1e5 range
 *  that being done, we could use a segment tree to maintain the maximum LIS so far and the number of intervals with max LIS so far
 *  when merging 2 nodes, we need to check their LIS count in order to see whether we add them or not
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

const int mx = 1e5 + 5;

int n, mod = 1e9 + 7;
int arr[mx];

struct seg_tree
{
	int mx, nmx, smx, nsmx;

	seg_tree()
	{
		mx = nmx = smx = nsmx = 0;
	}
};

seg_tree tree[4*mx];

void add(int &a, int b)
{
	a += b;
	if (a >= mod) a-=mod;
}

seg_tree merge(const seg_tree &a, const seg_tree &b)
{
	seg_tree ret;

	ret.mx = max(a.mx, b.mx);

	if (a.mx == ret.mx)
	{
		add(ret.nmx, a.nmx);
		add(ret.nsmx, a.nsmx);
	}
	else if (a.mx == ret.mx-1)
	{
		add(ret.nsmx, a.nmx);
	}

	if (b.mx == ret.mx)
	{
		add(ret.nmx, b.nmx);
		add(ret.nsmx, b.nsmx);
	}
	else if (b.mx == ret.mx-1)
	{
		add(ret.nsmx, b.nmx);
	}

	return ret;
}

void update(int node, int st, int en, int shemal, int yemeen, seg_tree &val)
{
	if (st > en || st > yemeen || en < shemal) return;

	if (shemal <= st && en <= yemeen)
	{
		tree[node] = merge(tree[node], val);
		return;
	}

	int mid = (st+en)/2;

	update(2*node, st, mid, shemal, yemeen, val);
	update(2*node + 1, mid + 1, en, shemal, yemeen, val);

	tree[node] = merge(tree[2*node], tree[2*node + 1]);
}

seg_tree query(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal) return seg_tree();

	if (shemal <= st && en <= yemeen) return tree[node];

	int mid = (st+en)/2;

	return merge(query(2*node, st, mid, shemal, yemeen), query(2*node + 1, mid + 1, en, shemal, yemeen));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n;

		reset(tree, 0);
		vi temp(n);
		rep(i, 0, n) cin >> arr[i], temp[i] = arr[i];

		sort(all(temp));
		mapii mp;
		int t = 1;
		rep(i, 0, n) if (!mp[temp[i]]) mp[temp[i]] = t++;

		seg_tree init = seg_tree();
		init.nmx = 1;
		update(1, 0, t, 0, 0, init);

		rep(i, 0, n)
		{
			int idx = mp[arr[i]];

			seg_tree ret = query(1, 0, t, 0, idx-1);

			ret.mx++;

			update(1, 0, t, idx, idx, ret);
		}
		cout << tree[1].nsmx << endl;
	}

	return 0;
}
