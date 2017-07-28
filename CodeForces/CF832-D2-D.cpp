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

int sparse[100001][18], n, q, timer = 1;

vvi node;
vi in, out, level;

void dfs(int v)
{
    in[v] = timer++;
    for(auto i : node[v])
    {
        level[i] = level[v] + 1;
        dfs(i);
    }
    out[v] = timer++;
}

void preprocess()
{
    for(int j = 1; (1<<j) < n; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if (sparse[i][j-1] != -1) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}

int LCA(int u, int v)
{
    if (level[u] < level[v]) swap(u, v);

    int dist = level[u] - level[v];

    for(int i = 0; (1<<i) < n && u != -1; i++)
    {
        if (dist & (1<<i)) u = sparse[u][i];
    }

    if (u == v) return u;

    for(int i = 17; i >= 0; i--)
    {
        if (sparse[u][i] != -1 && sparse[u][i] != sparse[v][i])
        {
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }

    return sparse[u][0];
}

int solve(int s, int f, int t)
{
    int lca_s_f = LCA(s, f), lca_t_f = LCA(t, f), lca_s_t = LCA(s, t);
    //cout << s << " " << f << " " << t << endl;
    //cout << "LCA(s, f) = " << lca_s_f << endl;
    //cout << "LCA(t, f) = " << lca_t_f << endl << endl;
    int dist1 = level[s] + level[f] - 2*level[lca_s_f];
    int dist2 = level[t] + level[f] - 2*level[lca_t_f];
    int dist3 = level[s] + level[t] - 2*level[lca_s_t];
    dist1 = abs(dist1), dist2 = abs(dist2), dist3 = abs(dist3);
    //cout << "here: " << dist1 << " " << dist2 << " " << dist3 << endl;
    return (dist1 + dist2 - dist3) / 2 + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    reset(sparse, -1), node = vvi(n+1), in = vi(n+1), out = vi(n+1), level = vi(n+1);
    erep(i, 2, n)
    {
        int p;
        cin >> p;
        node[p].push_back(i);
        sparse[i][0] = p;
    }
    dfs(1);
    preprocess();
    while(q--)
    {
        int mx = 0;
        vi vec(3);
        rep(i, 0, 3) cin >> vec[i];
        sort(all(vec));
        do
        {
            int s = vec[0], f = vec[1], t = vec[2];
            mx = max(mx, solve(s, f, t));
        }
        while(next_permutation(all(vec)));
        cout << mx << endl;
    }

    return 0;
}
