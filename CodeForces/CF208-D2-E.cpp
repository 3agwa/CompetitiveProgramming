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

vvi node;

vvii hoba;

int lev[100001], in[100001], out[100001], t = 1;

void dfs(int i)
{
    in[i] = t++;
    hoba[lev[i]].push_back(make_pair(in[i], i));
    for(int j = 0; j < node[i].size(); j++)
    {
        int u = node[i][j];
        lev[u] = lev[i] + 1;
        dfs(u);
    }
    out[i] = t++;
}

int sparse[100001][18];
void buildSparse(int n)
{
    for(int j = 1; j < 18; j++)
    {
        for(int i = 0; i <= n; i++)
        {
            if(sparse[i][j - 1] != -1)
                sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
        }
    }
}

int pth(int u, int p)
{
    for(int i = 0; i < 18 && u != -1; i++)
    {
        if(p & (1 << i)) u = sparse[u][i];
    }
    return u;
}

int solve(int v, int p)
{
    int l = lev[v];
    int par = pth(v, p);
    if(par <= 0)
        return 0;
    int tin = in[par], tout = out[par];
    return lower_bound(hoba[l].begin(), hoba[l].end(), make_pair(tout, 0))
           - lower_bound(hoba[l].begin(), hoba[l].end(), make_pair(tin, 0)) - 1;
}

int lca(int u, int v) // betgeeb awel level ta7t el lca
{
    if (lev[u] > lev[v]) swap(u, v);
    int p = lev[v] - lev[u];

    v = pth(v, p);

    for(int i = 17; i>=0; i--)
    {
        if (sparse[u][i] != sparse[v][i])
        {
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }

    return sparse[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    node = vvi(n+1);
    hoba = vvii(n+1);
    erep(i, 1, n)
    {
        int x;
        cin >> x;
        sparse[i][0] = x;
        node[x].push_back(i);
    }

    dfs(0);
    buildSparse(n);

    int m;
    cin >> m;
    while(m--)
    {
        int v, aa;
        cin >> v >> aa;
        cout << solve(v, aa) << " ";
    }

    return 0;
}
