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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int m, d, memo[2002][2002][2][2], mod = 1000000007;
string x, y;
string ans;

int solve(int idx, int rem, bool a, bool b)
{
    if (idx >= sz(x)) return !rem;

    if (memo[idx][rem][a][b] != -1) return memo[idx][rem][a][b];

    ll ret = 0;
    erep(i, 0, 9)
    {
        if (i < x[idx] - '0' && !a) continue;
        if (i > y[idx] - '0' && !b) continue;
        if (idx&1 && i != d) continue;
        if (idx%2 == 0 && i == d) continue;

        bool t1 = (i > x[idx] - '0'), t2 = (i < y[idx] - '0');

        //char c = ans[idx];
        //ans[idx] = i + '0';
        ret += solve(idx+1, (rem * 10 + i)%m, t1 || a , t2 || b);

        //ans[idx] = c;
        if (ret >= mod) ret %= mod;

    }

    return memo[idx][rem][a][b] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    reset(memo, -1);
    cin >> m >> d >> x >> y;
    //ans.resize(sz(x));
    //fill(all(ans), '0');

    cout << solve(0, 0, 0, 0);

    return 0;
}
