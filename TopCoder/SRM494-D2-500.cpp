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

int temp[51][51];
int hoba[51][51];
int n, m;

bool check(int level)
{
    reset(hoba, false);
    for(int i = 0; i+level < n; i++)
    {
        for(int j = 0; j+level < m; j++)
        {
            bool yay = true;
            if (temp[i][j])
            {
                rep(k, i, i+level)
                {
                    rep(l, j, j+level)
                    {
                        if (!temp[k][l])
                        {
                            yay = false;
                            break;
                        }
                    }
                    if (!yay) break;
                }

                if (yay)
                {
                    rep(k, i, i+level)
                    {
                        rep(l, j, j+level)
                        {
                            hoba[k][l] = true;
                        }
                    }
                }
            }
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (hoba[i][j] != temp[i][j]) return false;
        }
    }
    return true;
}

class Painting
{
public:
    int largestBrush(vector <string> picture)
    {
        n = sz(picture), m = sz(picture[0]);
        reset(hoba, 0);
        reset(temp, 0);
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                temp[i][j] = (picture[i][j] == 'B');
            }
        }
        int ret = -1, st = 1, en = min(n, m), mid;
        while(st <= en)
        {
            mid = (st+en)/2;
            if (check(mid)) st = mid + 1, ret = mid;
            else en = mid - 1;
        }
        return ret;
    }
};
