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

int m;
vi vec;

ll memo[(1<<18)+1][101];

ll solve(int mask, int rem)
{
    if (__builtin_popcount(mask) == sz(vec)) return !rem;
    if (memo[mask][rem] != -1) return memo[mask][rem];
    ll ret = 0;
    int prev = -1;
    rep(i, 0, sz(vec))
    {
        if (mask & (1<<i)) continue;
        if (__builtin_popcount(mask) == 0 && !vec[i]) continue;
        if (vec[i] == prev) continue;
        ret += solve(mask | (1<<i), (rem*10 + vec[i])%m);
        prev = vec[i];
    }
    return memo[mask][rem] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin >> n >> m;
    rep(i, 0, sz(n)) vec.push_back(n[i] - '0');
    sort(all(vec));
    reset(memo, -1);
    cout << solve(0, 0);
    return 0;
}
