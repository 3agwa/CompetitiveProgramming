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

const int MAX = 100002;

vi arr;
pii tree[4*MAX][2];

void build(int node, int st, int en, int id)
{
	if (st > en) return;

	if (st == en)
	{
		tree[node][id] = {arr[st], st};
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid, id);
	build(2*node + 1, mid + 1, en, id);

	tree[node][id] = min(tree[2*node][id], tree[2*node + 1][id]);
}

pii query(int node, int st, int en, int shemal, int yemeen, int id)
{
	if (st > en || st > yemeen || en < shemal) return {1e9, -1};

	if (shemal <= st && en <= yemeen) return tree[node][id];

	int mid = (st+en)/2;

	pii a = query(2*node, st, mid, shemal, yemeen, id);
	pii b = query(2*node + 1, mid + 1, en, shemal, yemeen, id);
	return min(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n && n)
	{
		arr = vi(n);
		rep(i, 0, n) cin >> arr[i];
		//arr[n] = -1;
		build(1, 0, n-1, 0);

		ll area = 0;
		vll yay(n);
		rep(i, 0, n)
		{
			int st = i, en = n-1, mid, ret = -1;

			while(st <= en)
			{
				mid = (st+en)/2;
				pii hoba = query(1, 0, n-1, i, mid, 0);
				if (hoba.first < arr[i]) en = mid - 1;
				else st = mid + 1, ret = mid;
			}
			yay[i] = 1LL*arr[i]*(ret - i + 1);
		}

		//rep(i, 0, sz(yay)) cerr << yay[i] << " ";
		//cerr << endl;
		reverse(all(arr));
		reverse(all(yay));
		
		build(1, 0, n-1, 1);
		ll sol = 0;
		rep(i, 0, n)
		{
			int st = i, en = n-1, mid, ret = -1;

			while(st <= en)
			{
				mid = (st+en)/2;
				pii hoba = query(1, 0, n-1, i, mid, 1);
				if (hoba.first < arr[i]) en = mid - 1;
				else st = mid + 1, ret = mid;
			}
			area = (1LL*arr[i]*(ret - i + 1)) - arr[i];
			yay[i] += area;
			sol = max(sol, yay[i]);
		}
		cout << sol << endl;
	}

	return 0;
}

