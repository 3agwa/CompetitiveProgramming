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

ll memo[(1<<20)+1][22];
bool arr[21][21];
int n;

ll solve(int mask, int i)
{
    if (__builtin_popcount(mask) == n) return 1;
    if (memo[mask][i] != -1) return memo[mask][i];
    ll ret = 0;
    rep(a, 0, n)
    {
        if (arr[i][a] && !(mask & (1<<a))) ret += solve(mask | (1<<a), i+1);
    }
    return memo[mask][i] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        reset(memo, -1);
        cin >> n;
        rep(i, 0, n)
        {
            rep(j, 0, n) cin >> arr[i][j];
        }
        cout << solve(0, 0) << endl;
    }
    return 0;
}
