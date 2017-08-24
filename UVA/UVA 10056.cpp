/*
    the player might win in his first game
    or in his second game after N loses 
    of in his third game after 2N loses and so on..
    keep adding turns till the abs difference is extremely small and doesn't affect the answer 
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, t;
        double p;
        cin >> n >> p >> t;
        double nott = 1, st = p;
        // series p*(1-p)^(k-1) + p*(1-p)^(n+k-1) + ...
        erep(i, 1, n)
        {
            if (i < t) st *= (1. - p);
            nott *= (1. - p);
        }

        double ans = 0;
        while(st > 1e-8) ans += st, st*=nott;
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}
