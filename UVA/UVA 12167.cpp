/*
    a correct implication refers to a SCC with no in/out edges from this component
    idea: get all SCCs, iterate over the vertices
    if vertex A is connected to vertex B and they're not in the same component
    mark out degree of vertex A and in degree of vertex B
    implications that needs to be proven would be the max(non-marked in degrees, non-marked out degrees)
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

int n, m, _time, SCC_num;
vvi node;
vb visited;
vi in_time, num, st, component;

void SCC(int v)
{
    in_time[v] = num[v] = ++_time;
    visited[v] = true;
    st.push_back(v);
    for(auto i : node[v])
    {
        if (num[i] == -1) SCC(i);
        if (visited[i]) in_time[v] = min(in_time[v], in_time[i]);
    }
    if (in_time[v] == num[v])
    {
        while(true)
        {
            int hoba = st.back();
            st.pop_back();
            component[hoba] = SCC_num;
            visited[hoba] = false;
            if (hoba == v) break;
        }
        SCC_num++;
    }
}

void init()
{
    SCC_num = 0;
    node = vvi(n+1);
    visited = vb(n+1);
    in_time = vi(n+1);
    _time = 0;
    num = vi(n+1, -1);
    component = vi(n+1);
    st.clear();
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
            if (num[i] == -1) SCC(i);
        }
        vb in(n+1), out(n+1);
        erep(i, 1, n)
        {
            for(auto j : node[i])
            {
                if (component[i] != component[j])
                {
                    out[component[i]] = in[component[j]] = true;
                }
            }
        }
        int c1 = 0, c2 = 0;
        rep(i, 0, SCC_num)
        {
            if (!out[i]) c2++;
            if (!in[i]) c1++;
        }
        if (SCC_num == 1) cout << 0 << endl;
        else cout << max(c1, c2) << endl;
    }
    return 0;
}
