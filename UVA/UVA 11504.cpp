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

int n, m;
vvi node;
vb visited;

vi topo;

void dfs(int v)
{
    visited[v] = true;
    for(auto i : node[v]) if (!visited[i]) dfs(i);
    topo.push_back(v);
}

void yalla(int v)
{
    visited[v] = true;
    for(auto i : node[v]) if (!visited[i]) yalla(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        topo.clear();
        cin >> n >> m;
        //init();
        node = vvi(n+1);
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
        }
        visited = vb(n+1);
        erep(i, 1, n)
        {
            if (!visited[i])
            {
                dfs(i);
                //SCC(i);
            }
        }
        int cnt = 0;
        visited = vb(n+1);
        for(int i = sz(topo)-1; i>=0; i--)
        {
            if (!visited[topo[i]]) yalla(topo[i]), cnt++;
        }
        cout << cnt << endl;

    }
    return 0;
}
