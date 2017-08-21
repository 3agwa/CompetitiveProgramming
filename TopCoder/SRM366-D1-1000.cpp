/*
    the idea is to keep track of the current coordinates, the direction you came from and the remaining time you have
    simulate the process mentioned in the problem, you have to make sure that the new coordinates are not the one you just came from
    use dp to resolve the overlapping problems
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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
vs vec;
double ticket, red;
double memo[50][50][4][101];
bool visited[50][50][4][101];

bool valid(int i, int j)
{
    return (i>=0 && j>=0 && i<n && j < m && vec[i][j] != 'X');
}

double solve(int x, int y, int dir, int rem, int px, int py)
{
    if (rem < 0) return 1e9;
    if (vec[x][y] == 'C') return (!rem ? 0 : 1e9);
    if (visited[x][y][dir][rem]) return memo[x][y][dir][rem];
    visited[x][y][dir][rem] = true;
    double ret = 1e9;
    rep(d, 0, 4)
    {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx == px && yy == py) continue;

        if (valid(xx, yy))
        {
            if (vec[xx][yy] == '.' || vec[xx][yy] == 'Y') ret = min(ret, solve(xx, yy, d, rem - 1, x, y));
            if (vec[xx][yy] == 'S') ret = min(ret, ticket + solve(xx, yy, d, rem - 1, x, y));
            if (vec[xx][yy] == 'T')
            {
                ret = min(ret, 0.7*red + solve(xx, yy, d, rem - 1, x, y));
                ret = min(ret, solve(xx, yy, d, rem - 2, x, y));
            }
            if (vec[xx][yy] == 'C') ret = min(ret, solve(xx, yy, d, rem-1, x, y));
        }
    }
    return memo[x][y][dir][rem] = ret;
}

class LateForConcert
{
public:
    double bestRoute(vector <string> cityMap, int timeLeft, double speedingTicket, double redLight)
    {
        reset(visited, false);
        vec = cityMap, ticket = speedingTicket, red = redLight;
        n = sz(vec), m = sz(vec[0]);
        int a = -1, b = -1;
        rep(i, 0, sz(vec))
        {
            rep(j, 0, sz(vec[i]))
            {
                if (vec[i][j] == 'Y')
                {
                    a = i, b = j;
                    break;
                }
            }
        }
        double ret = solve(a, b, 4, timeLeft, -1, -1);
        if (ret >= 1e9) return -1;
        return ret;
    }
};

