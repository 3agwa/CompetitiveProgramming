#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    while(cin >> n && n)
    {
        int src, sink, e;
        cin >> src >> sink >> e;
        Dinic flow(n+1);
        while(e--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            flow.AddEdge(u, v, c);
            flow.AddEdge(v, u, c);
        }
        cout << "Network " << ++cnt << endl;
        cout << "The bandwidth is " << flow.GetMaxFlow(src, sink) << ".\n\n";
    }


    return 0;
}
