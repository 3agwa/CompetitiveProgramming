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

class PipeCuts
{
public:
    double probability(vector <int> weldLocations, int L)
    {
        sort(all(weldLocations));
        int n = sz(weldLocations), cnt = 0;
        rep(i, 0, n)
        {
            rep(j, i+1, n)
            {
                int a = weldLocations[i], b = weldLocations[j] - a, c = 100 - weldLocations[j];
                if (a > L || b > L || c > L) cnt++;
            }
        }
        return (double)cnt / (double)(n*(n-1)/2);
    }
};
