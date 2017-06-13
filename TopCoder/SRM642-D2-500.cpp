/*
    fastest thing is to make all letters as the first one
    if the first one is Y, we'll flip 1 more time
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class LightSwitchingPuzzle
{
public:
    int minFlips(string state)
    {
        int cnt = 0;
        string x = state;
        rep(i, 0, sz(x))
        {
            if (x[i] != state[0])
            {
                cnt++;
                x[i] = x[0];
                for(int j = i; j<sz(state); j+= (i+1))
                {
                    if(x[j] == 'Y') x[j] = 'N';
                    else x[j] = 'Y';
                }
            }
        }
        if (x[0] == 'Y') cnt++;
        return cnt;
    }
};
