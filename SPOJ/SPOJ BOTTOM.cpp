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

int _time, n, m, num_components, component[5001];
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
        //cout << "NODE: " << v << endl;
        while(true)
        {
            int hoba = st.back();
            visited[hoba] = false;
            st.pop_back();
            component[hoba] = num_components;
            if (hoba == v) break;
        }
        num_components++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n && n)
    {
        cin >> m;
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
        set<int> st;
        mapii mp;
        erep(i, 1, n)
        {
            if (mp[component[i]]) continue;
            for(auto j : node[i])
            {
                if (component[i] != component[j])
                {
                    mp[component[i]] = true;
                    break;
                }
            }
        }
        erep(i, 1, n) if (!mp[component[i]]) cout << i << " ";
        cout << endl;
    }
    return 0;
}
