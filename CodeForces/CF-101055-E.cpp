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

int k, val, n;//, memo[]
int modulo = 1000000007;

int memo[(1<<13)+1][201];

int solve(int mask, int idx)
{
    if (idx == n)
    {
        int hoba = min(n, k);
        if (mask == (1<<hoba)-1) return 1;
        return 0;
    }
    if (memo[mask][idx] != -1) return memo[mask][idx];

    ll ret = 0;
    int st = max(0, idx-k), en = min(n-1, idx+k), bit = (en-st+1);
    rep(i, 0, bit)
    {
        if (mask & (1<<i)) continue;

        int _mask = mask;
        _mask |= (1<<i);


        if (idx - k >= 0 )
        {
            if (_mask & (1<<(bit-1)))
            {
                _mask -= (1<<(bit-1));
            }
            else continue;
        }

        if (idx + k + 1< n) _mask *= 2;

        ret += solve(_mask, idx+1);

        if (ret > modulo) ret %= modulo;
    }

    return memo[mask][idx] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;

    erep(i, 1, 200)
    {
        reset(memo, -1);
        n = i;
        cout << solve(0, 0) << endl;
    }
    return 0;
}
