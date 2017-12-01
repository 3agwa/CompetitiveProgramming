/*
 *  we should pre-process the maximum sum in the interval of [i, n-1]
 *  if the amount of money in the deposit exceeds D we return -1
 *  on each day where Ai = 0 and current deposite is < 0
 *  we should deposit the maximum amount of money we could such that it doesn't let the maximum in range [i, n-1] exceed D
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

ll arr[100001], sum[100001], mx[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	rep(i, 0, n)
	{
		cin >> arr[i];
		sum[i] = arr[i];
		if (i)
			sum[i] += sum[i-1];
	}

	mx[n-1] = sum[n-1];

	for(int i = n-2; i>=0; i--)
		mx[i] = max(mx[i+1], sum[i]);

	ll curr = 0, ret = 0;

	rep(i, 0, n)
	{
		if (sum[i] + curr > d)
			return cout << -1, 0;

		if (!arr[i] && sum[i] + curr < 0)
		{
			ll extra = d - (mx[i] + curr);

			if (sum[i] + curr + extra < 0)
				return cout << -1, 0;

			ret++;
			curr += extra;
		}
	}

	cout << ret << endl;

	return 0;
}
