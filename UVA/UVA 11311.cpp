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

int n, m, x, y;
bool visited[50][50][50][50][2], memo[50][50][50][50][2];

int solve(int rn, int rm, int x, int y, bool turn)
{
    if (rn == 1 && rm == 1) return 0; // player X lost
    if (visited[rn][rm][x][y][turn]) return memo[rn][rm][x][y][turn];
    int ret = 0;
    visited[rn][rm][x][y][turn] = true;
    rep(i, 1, rn)
    {
        if (x < i) ret |= 1-solve(i, rm, x, y, !turn);
        else ret |= 1-solve(rn-i, rm, x-i, y, !turn);
        if (ret) return memo[rn][rm][x][y][turn] = ret;
    }
    rep(i, 1, rm)
    {
        if (y < i) ret |= 1-solve(rn, i, x, y, !turn);
        else ret |= 1-solve(rn, rm-i, x, y-i, !turn);
        if (ret) return memo[rn][rm][x][y][turn] = ret;
    }
    return memo[rn][rm][x][y][turn] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> x >> y;
        int ret = solve(n, m, x, y, 0);
        if (ret) cout << "Gretel\n";
        else cout << "Hansel\n";
    }

    return 0;
}
