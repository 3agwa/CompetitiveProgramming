/*
    we'll binary search on the min c(a) value
    our check fucntion will be a dp function
    dp will return the maximum number of elements we don't have to change
    so if (ret + k >= n) we can minimize over this value
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

int arr[100001], n, k, mid;
int memo[2001][2001];

int solve(int last, int curr)
{
	if (curr == n) return 0;

	if (memo[last + 1][curr] != -1) return memo[last + 1][curr];
	//cerr << last << " " << curr << endl;
	int ret = 0;

	ret = max(ret, solve(last, curr + 1));

	if (last == -1 || abs(arr[last] - arr[curr]) <= (curr - last) * mid)
		ret = max(ret, 1 + solve(curr, curr + 1));


	return memo[last + 1][curr] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	rep(i, 0, n) cin >> arr[i];
	//reset(memo, -1);
	// solve(-1, 0);
	ll st = 0, en = INT_MAX, ret = -1;

	while(st <= en)
	{
		mid = (st+en)/2;
		reset(memo, -1);
		int hoba = solve(-1, 0);
		//cerr << mid << " " << hoba << endl;
		if (hoba >= n-k) en = mid - 1, ret = mid;
		else st = mid + 1;
	}

	cout << ret << endl;

	return 0;
}
