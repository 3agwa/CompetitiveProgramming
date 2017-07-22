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

const int INF = 2000000000;

int n, m;
vi a;
vi b;

vvi node;

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

int arr[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    a.resize(n), b.resize(n);
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    rep(i, 0, n) cin >> b[i];
    node.resize(n);

    Dinic flow((2*n) + 3);

    int src = 2*n + 1, dest = 2*n + 2, cnt = 0;

    rep(i, 0, n)
    {
        cnt += b[i];
        flow.AddEdge(i, i+n, INF);
        flow.AddEdge(src, i, a[i]);
        flow.AddEdge(i+n, dest, b[i]);
    }

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        flow.AddEdge(u, v + n, INF);
        flow.AddEdge(v, u + n, INF);
    }

    ll hoba = flow.GetMaxFlow(src, dest);
    if (sum != hoba || cnt != hoba)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";

    rep(i, 0, n)
    {
        for(auto j : flow.G[i])
        {
            int u = j.from, v = j.to;
            if (u == src || u == dest || v == src || v == dest) continue;
            node[u].push_back(j.flow);
            arr[u][v-n] = j.flow;
            //cout << j.flow << " " << u << " " << v << endl;
        }
    }

    rep(i, 0, n)
    {
        rep(j, 0, n) cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}
