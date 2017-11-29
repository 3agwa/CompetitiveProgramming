/*
 *  since we can't generate all 2^n possibilities, we could generate 2^(n/2) for the 2 halves of the array
 *  after sorting the 2 generated outputs, iterate over the first half and binary search for the best answer on the second half
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
#define mp(x, y, z) {{x, y}, z}

int n, m, arr[35], id;
vvi vec(2);

void solve(int idx, int lim, ll sum)
{
	if (idx == lim)
	{
		vec[id].push_back(sum);
		return;
	}
	solve(idx + 1, lim, (sum + arr[idx])%m);
	solve(idx + 1, lim, sum);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, 0, n) cin >> arr[i];

	solve(0, n/2, 0);
	id++;
	solve(n/2, n, 0);

	sort(all(vec[0]));
	sort(all(vec[1]));
	int mx = 0;
	rep(i, 0, sz(vec[0]))
	{
		int x = vec[0][i];
		int t = upper_bound(all(vec[1]), m - 1 - x) - vec[1].begin();
		t--;
		if (t >= 0)
			mx = max(mx, ((x%m)+(vec[1][t]%m))%m);
	}
	cout << mx << endl;
	return 0;
}
