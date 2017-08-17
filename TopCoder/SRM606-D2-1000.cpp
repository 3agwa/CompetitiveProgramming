/*
    each player will try to maximize his gain, when switching players, reverse the sign of the outcome as if we changed the player 
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

vi hoba;
int n;

int solve(int sum, int boxes)
{
    if (!boxes) return sum;
    int ret = -1e9;
    rep(i, 0, n)
    {
        if (!hoba[i]) continue;
        int a = hoba[i];
        if (i-1 >= 0) hoba[i-1] *= 2;
        if (i+1 < n) hoba[i+1] *= 2;
        hoba[i] = 0;
        ret = max(ret, -solve(-(sum + a), boxes-1));
        hoba[i] = a;
        if (i-1 >= 0) hoba[i-1] /= 2;
        if (i+1 < n) hoba[i+1] /= 2;
    }
    return ret;
}

class EllysCandyGame
{
public:
    string getWinner(vector <int> sweets)
    {
        hoba = sweets, n = sz(sweets);
        int cnt = 0;
        rep(i, 0, n)
            if (sweets[i]) cnt++;
        int ret = solve(0, cnt);
        if (ret > 0) return "Elly";
        if (ret < 0) return "Kris";
        return "Draw";
    }
};
