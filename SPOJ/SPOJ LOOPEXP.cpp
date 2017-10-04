/*
 *  solution is the sum of geometric series till N, could be noticed by brute forcing the solution
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vd vec(100001);
	vec[1] = 1.;

	rep(i, 2, 100001)
		vec[i] = vec[i-1] + (1. / i);

	int n, tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		cout << fixed << setprecision(6) << vec[n] << endl;		
	}

	return 0;
}
