/*
    the idea is to count the difference between winScore and loseScore in each round
    from this we can run an N^2 solution, if andrew won matches I and J, then Jerry 
    can win the rest of the games, we'll also keep track how many times I and J were included in a triplet
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

ll accum[5005];
int cnt[5005];

ll sum(int l, int r)
{
	if (l > r) return 0;
	if (!l) return accum[r];
	return accum[r] - accum[l-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));
    double deno = 0;
    rep(i, 0, n)
    {
    	rep(j, i+1, n)
		{
    		cnt[arr[j]-arr[i]]++;

    		deno++;
		}
    }

    erep(i, 1, 5000) accum[i] = accum[i-1] + cnt[i];
    double ret = 0.;
    erep(i, 1, 5000)
    {
    	erep(j, 1, 5000)
		{
    		if (i+j+1 > 5000 || !cnt[i] || !cnt[j]) continue;
    		double temp = cnt[i] / deno;
    		temp *= (cnt[j] / deno);
    		temp *= (sum(i+j+1, 5000) / deno);
    		ret += temp;
		}
    }
    cout << fixed << setprecision(9) << ret << endl;

    return 0;
}


