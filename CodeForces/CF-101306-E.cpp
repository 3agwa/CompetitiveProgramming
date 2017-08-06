#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int n, m, k;
char arr[501][501];
bool visited[501][501], visited_mar[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool valid(int i, int j) {return (i>=0 && j>=0 && i<n && j<m);}

int bfs_mar()
{
    queue< pair< pii, int > > Q;
    Q.push({{0, 0}, 0});
    while(!Q.empty())
    {
        int x = Q.front().first.first, y = Q.front().first.second;
        int lev = Q.front().second;
        Q.pop();
        if (visited_mar[x][y]) continue;
        visited_mar[x][y] = true;
        if (x == n-1 && y == m-1) return lev;

        rep(i, 0, 4)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (valid(xx, yy) && !visited_mar[xx][yy]) Q.push({{xx, yy}, lev+1});
        }
    }
    return 1e9;
}

// guess what? ma3amaltesh copy/paste zaii ma olt ya nouro :v (i lied)

int bfs()
{
    queue< pair< pii, int > > Q;
    Q.push({{0, 0}, 0});
    while(!Q.empty())
    {
        int x = Q.front().first.first, y = Q.front().first.second;
        int lev = Q.front().second;
        Q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (x == n-1 && y == m-1) return lev;

        rep(i, 0, 4)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (valid(xx, yy) && !visited[xx][yy]) Q.push({{xx, yy}, lev+1});
        }
    }
    return 1e9;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'x') visited[i][j] = true, visited_mar[i][j] = true;
        }
    }
    while(k--)
    {
        int a, b;
        cin >> a >> b;
        visited[a][b] = 0;
    }

    int martians = bfs_mar();
    if (martians != 1e9) martians-=5;
    int yay = bfs();

    if (yay < martians) cout << "YES";
    else cout << "NO";

    return 0;
}
