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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

string x;
int n, memo[(1<<20) + 1][2];

int solve(int mask, bool turn)
{
    if (__builtin_popcount(mask) == 1 && (mask & (1<<(n-1))))
    {
        return !turn;
    }
    if (memo[mask][turn] != -1) return memo[mask][turn];
    int ret = 0;
    rep(i, 0, n-1)
    {
        if (mask & (1<<i))
        {
            if (i+1 == n-1)
            {
                int _mask = mask;
                _mask &= ~(1<<i);
                _mask |= (1<<(i+1));
                ret = max(ret, solve(_mask, !turn));
            }
            if (i+1 < n-1 && !(mask & (1<<(i+1))))
            {
                int _mask = mask;
                _mask &= ~(1<<i);
                _mask |= (1<<(i+1));
                ret = max(ret, solve(_mask, !turn));
            }
            if (i+3 == n-1)
            {
                int _mask = mask;
                _mask &= ~(1<<i);
                _mask |= (1<<(i+3));
                ret = max(ret, solve(_mask, !turn));
            }
            if (i+3 < n && !(mask & (1<<(i+3))) && (mask & (1<<(i+1))) && (mask & (1<<(i+2))))
            {
                int _mask = mask;
                _mask &= ~(1<<i);
                _mask |= (1<<(i+3));
                ret = max(ret, solve(_mask, !turn));
            }
        }
    }
    return memo[mask][turn] = ret;
}

class EllysCheckers
{
public:
    string getWinner(string board)
    {
        reset(memo, -1);
        x = board, n = sz(board);

        int mask = 0;
        rep(i, 0, sz(x)) if (x[i] == 'o') mask |= (1<<i);
        int ret = solve(mask, 1);

        if (!ret) return "NO";
        return "YES";
    }
};
