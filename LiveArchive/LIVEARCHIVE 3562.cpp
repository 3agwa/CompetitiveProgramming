#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
//#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long int
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
const int mxN = 110;
const int inf = 1000000010;
struct Edge
{
    int to; double cost; int cap, flow, backEdge;
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

// to convert to doubles, multiply by maximum cost (aw akbar) then divide by it when getting the solution

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0;
    while(cin >> n >> m && n && m)
    {
        cnt++;
        vi pies(n), ice(m);
        rep(i, 0, n) cin >> pies[i];
        rep(i, 0, m) cin >> ice[i];
        MCMF flow(n+m, n+m+1, n+m+2);
        MCMF net(n+m, n+m+1, n+m+2);
        int src = n+m, sink = src + 1;
        rep(i, 0, n) flow.addEdge(src, i, 0, pies[i]), net.addEdge(src, i, 0, pies[i]);
        rep(i, 0, m) flow.addEdge(i+n, sink, 0, ice[i]), net.addEdge(i+n, sink, 0, ice[i]);
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                double x;
                cin >> x;
                if (x == -1) continue;
                flow.addEdge(i, j + n, x*(100.0) + 0.5, inf);
                net.addEdge(i, j + n, -(x*100 + 0.5), inf);
            }
        }
        cout << "Problem " << cnt << ": " << fixed << setprecision(2) << (double)flow.minCostMaxFlow().first / 100.0 << " to " << (double)-net.minCostMaxFlow().first / 100.0 << endl;
    }

    return 0;
}
