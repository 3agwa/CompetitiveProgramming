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

struct graph
{
    int L, R;
    vector<vector<int>> adj;
    graph(int L, int R) : L(L), R(R), adj(L+R) { }
    void add_edge(int u, int v)
    {
        adj[u].push_back(v+L);
        adj[v+L].push_back(u);
    }
    int maximum_matching()
    {
        vector<int> level(L), mate(L+R, -1);

        function<bool(void)> levelize = [&]()   // BFS
        {
            queue<int> Q;
            for (int u = 0; u < L; ++u)
            {
                level[u] = -1;
                if (mate[u] < 0)
                {
                    level[u] = 0;
                    Q.push(u);
                }
            }
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int w: adj[u])
                {
                    int v = mate[w];
                    if (v < 0) return true;
                    if (level[v] < 0)
                    {
                        level[v] = level[u] + 1;
                        Q.push(v);
                    }
                }
            }
            return false;
        };
        function<bool(int)> augment = [&](int u)   // DFS
        {
            for (int w: adj[u])
            {
                int v = mate[w];
                if (v < 0 || (level[v] > level[u] && augment(v)))
                {
                    mate[u] = w;
                    mate[w] = u;
                    return true;
                }
            }
            return false;
        };
        int match = 0;
        while (levelize())
            for (int u = 0; u < L; ++u)
                if (mate[u] < 0 && augment(u))
                    ++match;
        return match;
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        int n, m;
        cin >> n >> m;
        graph flow(n, m);

        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                int x;
                cin >> x;
                if (x) flow.add_edge(i, j);
            }
        }
        cout << "Case " << t << ": a maximum of " << flow.maximum_matching() << " nuts and bolts can be fitted together\n";
    }

    return 0;
}
