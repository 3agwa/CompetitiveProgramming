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

int _time, n, m, num_components, component_size[1001], mx_count[1001], component[1001];
vvi node, edge;
vb visited;
vi st, num, in, temp;

inline void init()
{
    _time = num_components = 0;
    st = vi(n+5);
    node = vvi(n+5);
    edge = vvi(n+5);
    visited = vb(n+5);
    num = vi(n+5, -1);
    in = vi(n+5);
    reset(component_size, 0);
    reset(mx_count, -1);
    reset(component, 0);
}

void SCC(int v)
{
    num[v] = in[v] = ++_time;
    visited[v] = true;
    st.push_back(v);
    for(auto i : node[v])
    {
        if (num[i] == -1) SCC(i);
        if (visited[i]) in[v] = min(in[v], in[i]);
    }
    if (in[v] == num[v])
    {
        component_size[num_components] = 0;
        while(true)
        {
            int hoba = st.back();
            visited[hoba] = false;
            st.pop_back();
            component[hoba] = num_components;
            component_size[num_components]++;
            if (hoba == v) break;
        }
        num_components++;
    }
}

int get(int v)
{
    if (mx_count[v] == -1)
    {
        mx_count[v] = 0;
        for(auto i : edge[v])
        {
            if (i != v)
                mx_count[v] = max(mx_count[v], get(i));
        }
        mx_count[v] += component_size[v];
    }
    return mx_count[v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        init();
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
        }
        erep(i, 1, n)
        {
            if (num[i] == -1)
            {
                SCC(i);
            }
        }
        erep(i, 1, n)
        {
            for(auto j : node[i])
            {
                edge[component[i]].push_back(component[j]);
            }
        }
        int mx = 0;
        erep(i, 0, num_components) mx = max(mx, get(i));
        cout << mx << endl;
    }
    return 0;
}
