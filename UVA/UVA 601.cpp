/*
    save the coordinates of the U cells
    1- try moving from first column to last column using floodfill
    2- try moving from first row to last row using floodfill
    for each U, change it to W and repeat (1), change it back to U after finishing
    for each U, change it to B and repeat (2), change it back to U after finishing
    if none generated a msg, then there is no path
    
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

int n;
char arr[100][100];
bool visited[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inside(int i, int j) {return (i>=0 && j>=0 && i<n && j<n);}

bool floodwhite(int i, int j)
{
    if (j == n-1)
    {
        return true;
    }
    if (visited[i][j]) return false;
    visited[i][j] = true;
    bool ret = false;
    rep(a, 0, 4)
    {
        if (inside(i+dx[a], j + dy[a]) && arr[i+dx[a]][j+dy[a]] == 'W') ret |= floodwhite(i+dx[a], j + dy[a]);
    }
    return ret;
}

bool floodblack(int i, int j)
{
    if (i == n-1)
    {
        return true;
    }
    if (visited[i][j]) return false;
    visited[i][j] = true;
    bool ret = false;
    rep(a, 0, 4)
    {
        if (inside(i+dx[a], j + dy[a]) && arr[i+dx[a]][j+dy[a]] == 'B') ret |= floodblack(i+dx[a], j + dy[a]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n && n)
    {
        vii idx;
        reset(visited, 0);
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'U') idx.push_back({i, j});
            }
        }

        rep(i, 0, n)
        {
            if (arr[i][0] == 'W')
            {
                reset(visited, false);
                if (floodwhite(i, 0))
                {
                    cout << "White has a winning path.\n";
                    goto barra;
                }
            }
        }

        rep(i, 0, n)
        {
            if (arr[0][i] == 'B')
            {
                reset(visited, false);
                if (floodblack(0, i))
                {
                    cout << "Black has a winning path.\n";
                    goto barra;
                }
            }
        }

        rep(i, 0, sz(idx))
        {
            int x = idx[i].first, y = idx[i].second;
            arr[x][y] = 'W';
            rep(j, 0, n)
            {
                if (arr[j][0] == 'W')
                {
                    reset(visited, false);
                    if (floodwhite(j, 0))
                    {
                        cout << "White can win in one move.\n";
                        goto barra;
                    }
                }
            }
            arr[x][y] = 'U';
        }

        rep(i, 0, sz(idx))
        {
            int x = idx[i].first, y = idx[i].second;
            arr[x][y] = 'B';
            rep(j, 0, n)
            {
                if (arr[0][j] == 'B')
                {
                    reset(visited, false);
                    if (floodblack(0, j))
                    {
                        cout << "Black can win in one move.\n";
                        goto barra;
                    }
                }
            }
            arr[x][y] = 'U';
        }

        cout << "There is no winning path.\n";

barra:;
    }
    return 0;
}
