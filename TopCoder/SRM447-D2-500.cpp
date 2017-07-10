/*
    after tracing some samples, you can find out that it's a normal floodfill with extra steps
    if the level is even, we should check the lower and upper left corners
    if the level is odd, we should check the lower and upper right corners
    count the number of times you collide with a '#' and return the answer
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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class Islands
{
public:
    vector< vector< char > > vec;
    bool visited[51][51];
    int n, m, ret;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int i, int j) {return (i >= 0 && j >= 0 && i < n && j < m);}

    void solve(int i, int j)
    {
        visited[i][j] = true;
        if (i%2 == 0)
        {
            if (valid(i-1, j-1) && vec[i-1][j-1] == '#') ret++;
            if (valid(i+1, j-1) && vec[i+1][j-1] == '#') ret++;
        }
        else
        {
            if (valid(i-1, j+1) && vec[i-1][j+1] == '#') ret++;
            if (valid(i+1, j+1) && vec[i+1][j+1] == '#') ret++;
        }
        rep(a, 0, 4)
        {
            int x = i + dx[a], y = j + dy[a];
            if (!visited[x][y] && valid(x, y))
            {
                if (vec[x][y] == '#') ret++;
                else solve(x, y);
            }
        }
    }

    int beachLength(vector <string> kingdom)
    {
        n = sz(kingdom), m = sz(kingdom[0]);
        cout << n << " " << m << endl;
        reset(visited, false);
        vec = vector< vector< char > > (sz(kingdom));
        rep(i, 0, sz(kingdom)) rep(j, 0, sz(kingdom[i])) vec[i].push_back(kingdom[i][j]);
        ret = 0;
        rep(i, 0, sz(kingdom))
        {
            rep(j, 0, sz(kingdom[i]))
            {
                if (kingdom[i][j] == '.' && !visited[i][j]) solve(i, j);
            }
        }
        return ret;
    }
};
