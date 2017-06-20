/*
    run bellman ford from starting node to all other nodes
    if the cost to a node is <= 0, we don't need to relax this node
    try relaxing one more time, if this happened then there exists a cycle
    then we need to check if we could reach node n-1 from this current node
    case is winnable if the distance to n-1 is > 0 or if the above condition was true
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int grid[501][501];
int n, val, num, v;

bool visited[501];

void dfs(int v)
{
    visited[v] = true;
    rep(i, 0, n) if (grid[v][i] != -1 && !visited[i]) dfs(i);
}

int main()
{
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n && n != -1)
    {
        vii vec;
        vi value(n, 0);

        reset(grid, -1);
        rep(i, 0, n)
        {
            cin >> val >> num;
            value[i] = val;
            rep(j, 0, num)
            {
                cin >> v;
                v--;
                vec.push_back({i, v});
                grid[i][v] = 1;
            }
        }

        vi dist(n, -1e7);
        dist[0] = 100;
        rep(i, 0, n)
        {
            rep(j, 0, sz(vec))
            {
                int u = vec[j].first, v = vec[j].second;
                if (dist[u] > 0 && dist[u] + value[v] > dist[v])
                {
                    dist[v] = dist[u] + value[v];
                }
            }
        }

        bool hoba = false;
        rep(i, 0, sz(vec))
        {
            int u = vec[i].first, v = vec[i].second;
            if (dist[u] > 0 && dist[u] + value[v] > dist[v])
            {
                reset(visited, false);
                dfs(u);
                hoba |= visited[n-1];
            }
        }

        if (dist[n-1] > 0 || hoba) cout << "winnable\n";
        else cout << "hopeless\n";

    }

    return 0;
}
