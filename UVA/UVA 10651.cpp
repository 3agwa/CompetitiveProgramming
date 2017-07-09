/*

    for each unvisited bit, check the following and previous 2 cells
    if both are on, turn them off, turn on the current bit and recurse
    minimize over the bitcount of all calls
    
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

int memo[(1<<12)+1][13];

int solve(int mask, int i)
{
    if (memo[mask][i] != -1) return memo[mask][i];
    int ret = __builtin_popcount(mask);
    rep(j, 0, 12)
    {
        if (!(mask & (1<<j)) && j+2 < 12)
        {
            if ((mask & (1<<(j+1))) && (mask & (1<<(j+2))))
            {
                int temp = mask;
                temp |= (1<<j);
                temp &= ~(1<<(j+1));
                temp &= ~(1<<(j+2));
                ret = min(ret, solve(temp, j+1));
            }
        }

        if (!(mask & (1<<j)) && j-2 >= 0)
        {
            if ((mask & (1<<(j-1))) && (mask & (1<<(j-2))))
            {
                int temp = mask;
                temp |= (1<<j);
                temp &= ~(1<<(j-1));
                temp &= ~(1<<(j-2));
                ret = min(ret, solve(temp, j+1));
            }
        }
    }
    ret = max(ret, 1);
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
        string x;
        cin >> x;
        int mask = 0;
        rep(i, 0, sz(x)) if (x[i] != '-') mask |= (1<<i);
        cout << solve(mask, 0) << endl;
    }

    return 0;
}
