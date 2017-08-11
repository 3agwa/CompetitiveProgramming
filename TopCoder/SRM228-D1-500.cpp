/*
    if we were player 1, we'd like to maximize our profit
    if we were player 2, we'd like to minimize player 1's profit
    hence, if we need to subtract the greatest value of both ends
    dp on those states along with player's turn and return the solution
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

vi vec;
int memo[51][51][2];
bool visited[51][51][2];

int solve(int i, int j, bool turn)
{
    if (i > j || j < i) return 0;
    if (visited[i][j][turn]) return memo[i][j][turn];
    visited[i][j][turn] = true;
    int ret = -1e9;
    if (turn)
    {
        ret = max(ret, solve(i+1, j, !turn) + vec[i]);
        ret = max(ret, solve(i, j-1, !turn) + vec[j]);
    }
    else
    {
        ret = 1e9;
        ret = min(ret, solve(i+1, j, !turn) - vec[i]);
        ret = min(ret, solve(i, j-1, !turn) - vec[j]);
    }
    return memo[i][j][turn] = ret;
}

class BagsOfGold
{
public:
    int netGain(vector <int> bags)
    {
        reset(visited, false);
        vec = bags;
        return solve(0, sz(bags)-1, 1);
    }
};
