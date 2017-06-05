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


class PlaneGame
{
public:
    int bestShot(vector <int> x, vector <int> y)
    {
        if (sz(x) < 4) return sz(x);
        int ret = 0;
        rep(i, 0, sz(x))
        {
            rep(j, i+1, sz(y))
            {
                int dx = x[j] - x[i];
                int dy = y[j] - y[i];
                rep(k, j+1, sz(x))
                {
                    int cnt = 0;
                    rep(l, 0, sz(x))
                    {
                        if ((x[l] - x[i])*dy - (y[l] - y[i])*dx == 0) cnt++;
                        else if ((x[k] - x[l])*dx + (y[k] - y[l])*dy == 0) cnt++;
                    }
                    ret = max(ret, cnt);
                }
            }
        }
        return ret;
    }
};
