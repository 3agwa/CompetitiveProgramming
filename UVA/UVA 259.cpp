/*
    we'll use max flow to solve this problem
    build a graph where pcs are connected to the sink and programs are connected to source
    connect programs to pcs according to the input
    if the value of max flow isn't the same as the # of programs needed, then we can't match the programs correctly
    else we find which edge was used in the matching and output its letter accordingly
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
#define mp(x, y, z) {x, {y, z}}

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
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(true)
    {
        string x;
        getline(cin, x);
        if (x.empty()) break;

        Dinic flow(38);
        int src = 36, sink = 37, idx = 0, offset = 26;

        rep(i, offset, src) flow.AddEdge(i, sink, 1);
        int total = 0;

        do
        {
            char app = x[0];
            x.erase(0, 1);
            string val = x.substr(0, x.find(" "));
            x.erase(0, x.find(" ") + 1);

            int num = 0;
            rep(i, 0, sz(val)) num = num*10 + val[i] - '0';
            total += num;

            flow.AddEdge(src, app - 'A', num);
            x.pop_back();

            rep(i, 0, sz(x)) flow.AddEdge(app - 'A', offset + x[i] - '0', 1);
        }
        while(getline(cin, x) && sz(x));

        if (flow.GetMaxFlow(src, sink) == total)
        {
            string y;
            rep(i, 0, 10) y.push_back('_');
            rep(i, 0, offset)
            {
                for(auto j : flow.G[i])
                {
                    if (j.flow)
                    {
                        y[j.to-offset] = i + 'A';
                    }
                }
            }
            cout << y << endl;
        }
        else cout << "!\n";
    }

    return 0;
}
