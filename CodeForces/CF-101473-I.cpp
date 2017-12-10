/*
 *  we could cover ahead T1 or T2 units, after that we need to start from the next available hole
 *  that said, we should use upper bound on our current value to skip to the next hole
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

int n, c, t1, t2;

vi arr;

int memo[1001];

int solve(int idx)
{
	if (idx == n)
		return 0;

	if (memo[idx] != -1)
		return memo[idx];
	int a = t1 + solve(upper_bound(all(arr), arr[idx] + t1) - arr.begin());
	int b = t2 + solve(upper_bound(all(arr), arr[idx] + t2) - arr.begin());

	return memo[idx] = min(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	reset(memo, -1);
	cin >> n >> c >> t1 >> t2;
	arr.resize(n);
	rep(i, 0, n)
		cin >> arr[i];
	arr.push_back(INT_MAX);

	cout << solve(0) << endl;

	return 0;
}
