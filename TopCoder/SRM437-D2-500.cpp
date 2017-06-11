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
#define mp(x, y, z) {x, {y, z}}

class TheSwap
{
public:
    int temp_k, rett;
    map< pair< string, int >, bool > mp;
    void solve(string x, int rem)
    {
        if (mp[{x, rem}]) return;
        else mp[{x, rem}] = true;
        if (rem == temp_k)
        {
            int hoba = 0;
            rep(i, 0, sz(x)) hoba = hoba*10 + x[i]-48;
            if (hoba > rett) rett = hoba;
            return;
        }
        rep(i, 0, sz(x))
        {
            rep(j, i+1, sz(x))
            {
                if (!i && x[j] == '0') continue;
                swap(x[i], x[j]);
                solve(x, rem+1);
                swap(x[i], x[j]);
            }
        }

    }

    int findMax(int n, int k)
    {
        rett = -1, temp_k = k;
        string x = "";
        while(n)
        {
            int rem = n%10;
            n/=10;
            x += rem + 48;
        }
        reverse(all(x));
        solve(x, 0);
        return rett;
    }
};
