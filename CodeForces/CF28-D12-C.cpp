/*
	for each room, we'll try to place in it people from 0 -> remaining people
	multiply the solution by rem people C picked people 
	divide the probability by M as they are equiprobable
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

ll ncr[51][51];

double memo[51][51][51];
vd vec;
double n, m;

void pre()
{
	rep(i, 0, 51)
	{
		erep(j, 0, i)
		{
			if (i == j || !j) ncr[i][j] = 1;
			else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
		}
	}
}

double solve(int idx, int rem, int mx)
{
	if (idx == m)
	{
		return !rem ? mx : 0;
	}
	if (memo[idx][rem][mx] == memo[idx][rem][mx]) return memo[idx][rem][mx];
	double ret = 0;
	double p = 1.;

	erep(i, 0, rem)
	{
		int queue = (i + vec[idx] - 1) / vec[idx];
		ret += solve(idx+1, rem - i, max(mx, queue)) * p * ncr[rem][i];
		p /= m;
	}
	return memo[idx][rem][mx] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vec = vd(m);
    rep(i, 0, m) cin >> vec[i];
    pre();
    reset(memo, -1);
    cout << fixed << setprecision(9) << solve(0, n, 0) << endl;
    return 0;
}


