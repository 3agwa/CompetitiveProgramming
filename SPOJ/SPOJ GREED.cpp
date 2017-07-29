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

//Minimum Cost Max Flow SPFA implementation
const int mxN = 505;
const int inf = 1000000010;
struct Edge
{
    int to, cost, cap, flow, backEdge;
};
struct MCMF
{
    int s, t, n;
    vector<Edge> g[mxN];
    MCMF(int _s, int _t, int _n)
    {
        s = _s, t = _t, n = _n;
    }
    void addEdge(int u, int v, int cost, int cap)
    {
        Edge e1 = { v, cost, cap, 0, g[v].size() };
        Edge e2 = { u, -cost, 0, 0, g[u].size() };
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    pair<int, int> minCostMaxFlow()
    {
        int flow = 0, cost = 0;
        vector<int> state(n), from(n), from_edge(n), d(n);
        deque<int> q;
        while (true)
        {
            for (int i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1;
            q.clear();
            q.push_back(s);
            d[s] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop_front();
                state[v] = 0;
                for (int i = 0; i < (int) g[v].size(); i++)
                {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    int to = e.to;
                    d[to] = d[v] + e.cost;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf) break;
            int it = t, addflow = inf;
            while (it != s)
            {
                addflow = min(addflow,
                              g[from[it]][from_edge[it]].cap
                              - g[from[it]][from_edge[it]].flow);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].flow += addflow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
                cost += g[from[it]][from_edge[it]].cost * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return {cost,flow};
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        MCMF flow(0, n+1, n+3);
        vi cnt(n+1);
        erep(i, 1, n)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        erep(i, 1, n)
        {
            flow.addEdge(0, i, 0, cnt[i]);
            flow.addEdge(i, n+1, 0, 1);
        }

        int m;
        cin >> m;
        rep(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            flow.addEdge(a, b, 1, m);
            flow.addEdge(b, a, 1, m);
        }

        pii hoba = flow.minCostMaxFlow();
        cout << hoba.first << endl;
    }

    return 0;
}
