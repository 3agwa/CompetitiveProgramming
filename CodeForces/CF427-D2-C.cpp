#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define erep(i, x, n) for (int i = x; i<=(int)(n); i++)
#define rep(i, x, n) for(int i = x; i<(int)(n); i++)
#define vi vector<int>
#define vii vector< pair<int, int> >
#define vvi vector< vi >
#define vll vector<long long>
#define vc vector<char>
#define vb vector<bool>
#define vvii vector< vector< pii > >
#define pii pair<int, int>
#define mapii map<int, int>
#define mapsi map<string, int>
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)

int n, m, scc_cnt;
ull money, ways;
vi cost;
vvi node;
vi low, num, st;
vb visited;
vi num_of_ways;

void init(int x)
{
    cost = vi(x);
    low = vi(x, 0);
    num = vi(x, -1);
    st.clear();
    visited = vb(n, false);
    node = vvi(n);
}

void SCC(int curr_node)
{
    low[curr_node] = num[curr_node] = scc_cnt++;
    visited[curr_node] = true;
    st.push_back(curr_node);
    rep(i, 0, sz(node[curr_node]))
    {
        int child = node[curr_node][i];
        if (num[child] == -1) SCC(child);
        if (visited[child]) low[curr_node] = min(low[curr_node], low[child]);
    }
    if (low[curr_node] == num[curr_node])
    {
        int mn = INT_MAX;
        mapii mp;
        while(true)
        {
            int v = st.back();
            mn = min(mn, cost[v]);
            mp[cost[v]]++;
            st.pop_back();
            visited[v] = false;
            if (v == curr_node) break;
        }
        money += mn;
        num_of_ways.push_back(mp[mn]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    init(n);
    rep(i, 0, n) cin >> cost[i];
    cin >> m;
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        node[u].push_back(v);
    }
    rep(i, 0, n)
    {
        if (num[i] == -1) SCC(i);
    }
    ways = num_of_ways.front();
    rep(i, 1, sz(num_of_ways))
    {
        ways*=num_of_ways[i];
        ways%= 1000000007;
    }
    cout << money << " " << ways;
    return 0;
}
