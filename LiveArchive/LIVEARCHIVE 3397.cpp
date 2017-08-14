/*
    split all the cells, flow would represent the value on the cell
    if a cell could reach outside the borders, link it to the sink with flow infinity
    if a cell has a lizard, link it with the source with flow 1
    link each cell to its adjacent (diagonals included) cells within a jumping distance
    running max flow would return the number of living lizards
    compare it to the total number of lizards and output the solution accordingly
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

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, -1, 1};
int n, d, m;

bool escape(int i, int j)
{
    if(i+d >= n || i-d < 0 || j+d >= m || j-d < 0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        cin >> n >> d;
        vector<string> vec(n);
        rep(i, 0, n) cin >> vec[i];
        m = sz(vec[0]);

        int rakam[25][25];
        reset(rakam, 0);
        int idx = 1;
        int tot = n*m + 1;

        Dinic flow(2*tot + 2);
        int src = 0, sink = 2*tot + 1;

        int sum = 0;
        char arr[26][26];
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'L')
                {
                    sum++;
                    flow.AddEdge(src, i*m + j + 1, 1);
                }
            }
        }

        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                flow.AddEdge(i*m + j + 1, i*m + j + tot, vec[i][j]-'0');
                if (escape(i, j))
                {
                    flow.AddEdge(i*m + j  + tot, sink, INF);
                }
            }
        }

        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                erep(a, max(0, i-3), min(n-1, i+3))
                {
                    erep(b, max(0, j-3), min(m-1, j+3))
                    {
                        if(abs(i-a)+abs(j-b) <= d && abs(i-a)+abs(j-b) > 0)
                        {
                            flow.AddEdge(i*m + j + tot, a*m + b + 1, INF);
                        }
                    }
                }
            }
        }

        sum -= flow.GetMaxFlow(src, sink);
        cout << "Case #" << t << ": ";
        if (!sum) cout << "no lizard was left behind.\n";
        else if (sum == 1) cout << "1 lizard was left behind.\n";
        else cout << sum << " lizards were left behind.\n";
    }
    return 0;
}
