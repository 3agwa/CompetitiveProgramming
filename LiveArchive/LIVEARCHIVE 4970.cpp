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

long long knight_distance(long long x1, long long y1, long long x2, long long y2)
{
    long long x = abs(x2 - x1), y = abs(y2 - y1);
    if (x > y) swap(x, y);
    assert(x <= y);
    if (x == 0 and y == 1) return 3;
    if (x == 2 and y == 2) return 4;
    long long d = max((y + 1) / 2, (x + y + 2) / 3);
    if (d % 2 != (x + y) % 2) d++;
    return d;
}

//Minimum Cost Max Flow SPFA implementation
const int mxN = 110;
const ll inf = LLONG_MAX;
struct Edge
{
    ll to, cost, cap, flow, backEdge;
};
struct MCMF
{
    ll s, t, n;
    vector<Edge> g[mxN];
    MCMF(ll _s, ll _t, ll _n)
    {
        s = _s, t = _t, n = _n;
    }
    void addEdge(ll u, ll v, ll cost, ll cap)
    {
        Edge e1 = { v, cost, cap, 0, g[v].size() };
        Edge e2 = { u, -cost, 0, 0, g[u].size() };
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    pair<ll, ll> minCostMaxFlow()
    {
        ll flow = 0, cost = 0;
        vector<ll> state(n), from(n), from_edge(n), d(n);
        deque<ll> q;
        while (true)
        {
            for (ll i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1;
            q.clear();
            q.push_back(s);
            d[s] = 0;
            while (!q.empty())
            {
                ll v = q.front();
                q.pop_front();
                state[v] = 0;
                for (ll i = 0; i < (ll) g[v].size(); i++)
                {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    ll to = e.to;
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
            ll it = t, addflow = inf;
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
    int n, cnt = 0;
    while(cin >> n && n)
    {
        int src = 2*n, sink = src + 1;
        MCMF flow(src, sink, sink + 1);
        vector< pair< ll, ll > > st(n), en(n);
        rep(i, 0, n)
        {
            cin >> st[i].first >> st[i].second;
            flow.addEdge(src, i, 0, 1);
        }
        rep(i, 0, n)
        {
            cin >> en[i].first >> en[i].second;
            flow.addEdge(i + n, sink, 0, 1);
        }

        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                ll dist = knight_distance(st[i].first, st[i].second, en[j].first, en[j].second);
                flow.addEdge(i, j + n, dist, 1);
            }
        }

        cout << ++cnt << ". " << flow.minCostMaxFlow().first << endl;
    }

    return 0;
}
