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

int n, m, timer;

int sparse[50001][18], cost[50001][18];

vvii node;
vb visited;
vi in, out, level;

void dfs(int v)
{
    visited[v] = true;
    in[v] = ++timer;
    for(auto i : node[v])
    {
        if (!visited[i.first])
        {
            level[i.first] = level[v]+1;
            sparse[i.first][0] = v;
            cost[i.first][0] = i.second;
            dfs(i.first);
        }
    }
    out[v] = ++timer;
}

void preprocess()
{
    for(int j = 1; (1<<j) < n; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if (sparse[i][j-1] != -1)
            {
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
                cost[i][j] = cost[i][j-1] + cost[sparse[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int u, int v)
{
    if (level[u] < level[v]) swap(u, v);

    int dist = level[u] - level[v];

    int sum = 0;

    for(int i = 0; i < 17 && u != -1; i++)
    {
        if (dist & (1<<i))
        {
            sum += cost[u][i], u = sparse[u][i];
        }
    }

    if (u == v)
    {
        return sum;
    }

    for(int i = 17; i >= 0; i--)
    {
        if (sparse[u][i] != -1 && sparse[u][i] != sparse[v][i])
        {
            sum += cost[u][i];
            sum += cost[v][i];
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }

    return sum + cost[u][0] + cost[v][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    reset(sparse, -1);
    cost[0][0] = -1;
    node = vvii(n+1), visited = vb(n+1), in = vi(n+1), out = vi(n+1), level = vi(n+1);
    rep(i, 0, n-1)
    {
        int u, v, c;
        cin >> u >> v >> c;
        node[u].push_back({v, c});
        node[v].push_back({u, c});
    }
    rep(i, 0, n) if (!visited[i]) dfs(i);
    preprocess();

    cin >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}
