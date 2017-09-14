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

const int MX = 200005;

struct hoba
{
	int cnt[10][10];
	int left;
	int right;
}tree[4*MX];

int lazy[4*MX];
char x[MX];

hoba merge(hoba a, hoba b)
{
	hoba ret;
	rep(i, 0, 10)
	{
		rep(j, 0, 10)
		{
			ret.cnt[i][j] = a.cnt[i][j] + b.cnt[i][j];
		}
	}

	ret.cnt[a.right][b.left]++; //a5er shemali, awel yemeeni
	ret.left = a.left;
	ret.right = b.right;

	return ret;
}

void build(int node, int st, int en)
{
	if (st > en) return;

	if (st == en)
	{
		tree[node].left = tree[node].right = x[st]-'a';
		reset(tree[node].cnt, 0);
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	tree[node] = merge(tree[2*node], tree[2*node + 1]);
}

void propagate(int node, int st, int en)
{
	if (lazy[node] != -1)
	{
		int lololey = lazy[node];

		reset(tree[node].cnt, 0);
		tree[node].cnt[lololey][lololey] = en-st;

		tree[node].left = tree[node].right = lazy[node];

		if (st != en)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal) return;

	if (shemal <= st && en <= yemeen)
	{
		lazy[node] = val;
		propagate(node, st, en);
		return;
	}

	int mid = (st+en) / 2;

	update(2*node, st, mid, shemal, yemeen, val);
	update(2*node + 1, mid + 1, en, shemal, yemeen, val);

	tree[node] = merge(tree[2*node], tree[2*node + 1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	erep(i, 1, n) cin >> x[i];
	build(1, 1, n);
	reset(lazy, -1);
	while(m--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int l, r;
			char c;
			cin >> l >> r >> c;

			update(1, 1, n, l, r, c - 'a');
		}
		else
		{
			string yay;
			cin >> yay;

			int ret = 0;
			rep(i, 0, k)
			{
				erep(j, 0, i)
				{
					ret += tree[1].cnt[yay[i]-'a'][yay[j]-'a'];
				}
			}

			cout << ret + 1 << endl;
		}
	}

	return 0;
}
