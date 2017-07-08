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

int n, m, k;
map< pii, int > mp;
vi vec;

ll memo[(1<<18)+1][20];

ll solve(int mask, int rem, int prev)
{
    if (!rem) return 0;
    if (memo[mask][prev] != -1) return memo[mask][prev];

    ll ret = 0;
    rep(i, 0, n)
    {
        if (!(mask & (1<<i)))
        {
            ret = max(ret, vec[i] + mp[{i, prev}] + solve(mask | (1<<i), rem-1, i));
        }
    }
    return memo[mask][prev] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(memo, -1);
    cin >> n >> m >> k;
    vec = vi(n);
    rep(i, 0, n) cin >> vec[i];
    while(k--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        mp[{u, v}] = c;
    }
    cout << solve(0, m, n);
    return 0;
}
