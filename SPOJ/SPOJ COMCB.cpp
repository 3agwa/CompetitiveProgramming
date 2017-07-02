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
#define mp(x, y, z) {{x, y}, z}

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, m, mx;
vii ans;
vii vec;

bool visited[27][27];

bool valid(int i, int j) {return (i>=1 && j>=1 && i<=n && j<=m);}

vvii xx;

void dfs(int i, int j, int cnt)
{
    if (cnt == mx)
    {
        if (ans.empty()) ans = vec;
        else
        {
            ans = min(ans, vec);
        }
        return;
    }
    rep(a, 0, 8)
    {
        int x = i + dx[a], y = j + dy[a];
        if (!visited[x][y] && valid(x, y))
        {
            visited[i][j] = true;
            vec.push_back({y, x});
            dfs(x, y, cnt + 1);
            vec.pop_back();
            visited[i][j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        ans.clear();
        vec.clear();
        mx = n*m;
        reset(visited, false);
        visited[1][1] = true;
        vec.push_back({1, 1});
        dfs(1, 1, 1);
        if (ans.empty()) cout << -1 << endl;
        else
        {
            rep(i, 0, sz(ans)) cout << (char)(ans[i].first - 1 + 'A') << ans[i].second;
            cout << endl;
        }
    }

    return 0;
}
