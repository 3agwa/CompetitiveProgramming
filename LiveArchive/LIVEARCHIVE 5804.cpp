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

const int INF = 2000000000;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail)
        {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if(!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

vvii node;
int x, n, e, src, sink;

bool dijkstra(int mid)
{
    vi dist(n, -1);
    set< pii > st;
    st.insert({0, src});
    while(!st.empty())
    {
        pii hoba = *st.begin();
        st.erase(st.begin());
        int cost = hoba.first, idx = hoba.second;
        if (dist[idx] != -1) continue;
        dist[idx] = cost;
        if (idx == sink) return true;
        for(auto i : node[idx])
        {
            if (i.second >= mid)
            {
                if (dist[i.first] == -1) st.insert({cost + i.second, i.first});
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> x >> n >> e >> src >> sink;
        Dinic flow(2*n + 2);
        node = vvii(n+1);
        while(e--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            flow.AddEdge(u, v, c);
            node[u].push_back({v, c});
        }
        int st = 1, en = 1000, mid; double ret = -1;
        while(st <= en)
        {
            mid = (st+en)/2;
            if (dijkstra(mid)) st = mid + 1, ret = mid;
            else en = mid - 1;
        }
        double hoba = flow.GetMaxFlow(src, sink);
        cout << x << " " << fixed << setprecision(3) << hoba / ret << endl;
    }

    return 0;
}
