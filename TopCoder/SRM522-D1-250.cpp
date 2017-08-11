/*
    remove all duplicates from the string, if there's a substring of size > 1 containing the same element, compress it
    we'll represent the elements with a mask, we'll turn on the bits according to the player's turn and run the dp
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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

string x;
int n, memo[(1<<14) + 1][2];

int solve(int mask, bool turn)
{
    if (__builtin_popcount(mask) == sz(x)-1)
    {
        rep(i, 0, sz(x))
        {
            if (!(mask & (1<<i)))
            {
                if (x[i] == 'A') return 1;
                return 0;
            }
        }
    }
    if (memo[mask][turn] != -1) return memo[mask][turn];

    int ret = 0;
    rep(i, 0, n)
    {
        if (!(mask & (1<<i)))
        {
            int _mask = mask;
            if (turn)
            {
                if (x[i] == 'B')
                {
                    _mask |= (1<<i);
                    ret = max(ret, solve(_mask, !turn));
                }
            }
            else
            {
                if (x[i] == 'A')
                {
                    _mask |= (1<<i);
                    ret = max(ret, solve(_mask, !turn));
                }
            }
        }
    }
    return memo[mask][turn] = ret;
}

class RowAndCoins
{
public:
    string getWinner(string cells)
    {
        reset(memo, -1);
        x.clear();
        cells.push_back('*');
        rep(i, 0, sz(cells)-1)
        {
            if (cells[i] == cells[i+1]) continue;
            x.push_back(cells[i]);
        }
        n = sz(x);
        int cnt = 0;
        rep(i, 0, sz(x)) cnt += (x[i] == 'A');
        int ret = solve(0, 1);
        if (ret) return "Alice";
        return "Bob";
    }
};
