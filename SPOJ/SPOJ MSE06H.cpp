/*
    it's easy to see that if the point are sorted on their x, y axes
    then the solution in the ith turn would be the number of Ys greater than the current Y
    
    we'll use BIT to update and answer the queries in logN time
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

vll tree;

const int MAX_VAL = 1005;

void update(int idx, int val)
{
	while(idx < MAX_VAL)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

ll query(int idx)
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

	int tc;
	cin >> tc;

	erep(t, 1, tc)
	{
		int n, m, k;

		cin >> n >> m >> k;
		tree = vll(MAX_VAL + 1);
		vii vec;

		while(k--)
		{
			int a, b;
			cin >> a >> b;
			vec.push_back({a, b});
		}

		sort(all(vec));

		ll cnt = 0;

		rep(i, 0, sz(vec))
		{
			cnt += (query(m) - query(vec[i].second));
			update(vec[i].second, 1);
		}

		cout << "Test case " << t << ": " << cnt << endl;
	}

	return 0;
}
