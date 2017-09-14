/*
    get the accumulative sum based on the lastest update, then update the tree
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


const int MAX_VAL = 100005;

int arr[MAX_VAL], tree[MAX_VAL];

void update(int idx, int val)
{
	while(idx < MAX_VAL)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx)
{
	ll ret = 0;

	while(idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(i, 0, n)
	{
		int l, r;
		cin >> l >> r;

		int hela = query(l), hoba = query(r);

		cout << hela + hoba - arr[l] - arr[r] << endl;

		arr[l] = hela, arr[r] = hoba;

		update(l+1, 1);
		update(r, -1);

	}

	return 0;
}
