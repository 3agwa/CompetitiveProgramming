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

class StringWeightDiv2
{
public:
    ll memo[27][1001];

    ll modulo = 1000000009;

    ll solve(int let, int i)
    {
        ll &ret = memo[let][i];
        if (ret == -1)
        {
            if (!i) ret = (!let);
            else if (let == 1) ret = 1;
            else
            {
                ret = 0;
                erep(j, 1, i)
                {
                    ret += (let*solve(let-1, i-j))%modulo;
                }
                ret %= modulo;
            }
        }
        return ret;
    }

    int countMinimums(int L)
    {
        ll res = 1;
        if (L <= 26)
        {
            rep(i, 0, L)
            {
                res *= (26-i);
                res %= modulo;
            }
        }
        else
        {
            reset(memo, -1);
            res = solve(26, L);
        }
        return res;
    }
};
