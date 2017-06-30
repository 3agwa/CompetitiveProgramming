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

vb visited;
vvi node;
int k, cnt;

void dfs(int v)
{
    visited[v] = true;
    cnt++;
    rep(i, 0, sz(node[v]))
    {
        if (!visited[node[v][i]]) dfs(node[v][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n && n)
    {
        node = vvi(n+1);
        visited = vb(n+1, false);
        vi vec(n+1, false);
        cin >> m >> k;
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
            node[v].push_back(u);
            vec[u]++, vec[v]++;
        }
        while(true)
        {
            bool temp = false;
            erep(i, 1, n)
            {
                if (!visited[i] && vec[i] < k)
                {
                    visited[i] = true; // mark to disconnect
                    rep(j, 0, sz(node[i])) vec[node[i][j]]--;
                    temp = true;
                }
            }
            if (!temp) break;
        }
        int ret = 0;
        erep(i, 1, n)
        {
            if (!visited[i])
            {
                cnt = 0;
                dfs(i);
                ret = max(ret, cnt);
            }
        }
        cout << ret << endl;
    }
    return 0;
}
