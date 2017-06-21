/*
    dp counting problem
    either paste the copied data 
    or copy then paste them
    minimize over all solutions
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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class EmoticonsDiv2
{
public:
    int smilez;
    ll memo[1005][1005];

    ll solve(int n, int co)
    {
        if (n == smilez) return 0;
        if (n + co > smilez) return INT_MAX;
        if (co > smilez) return INT_MAX;
        if (memo[n][co] != -1) return memo[n][co];

        ll ret = 1 + solve(n+co, co); // paste
        if (2*n <= smilez) ret = min(ret, 2 + solve(2*n, n)); // paste - copy
        return memo[n][co] = ret;
    }

    int printSmiles(int smiles)
    {
        smilez = smiles;
        reset(memo, -1);
        return 1 + solve(1, 1);
    }
};
