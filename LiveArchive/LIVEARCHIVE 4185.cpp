/*
    for each of the input connections, add an edge between relevent connections (have the same meaning)
    run SCC, if a state and its inverse exist in the same SCC, this is an invalid case (output 0)
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

int n, m, _time, component_num;
vvi node;
vb visited;
vi st, low, num, component;

void SCC(int v)
{
    low[v] = num[v] = ++_time;
    visited[v] = true;
    st.push_back(v);
    for(auto i : node[v])
    {
        if (num[i] == -1) SCC(i);
        if (visited[i]) low[v] = min(low[v], low[i]);
    }
    if (low[v] == num[v])
    {
        while(true)
        {
            int hoba = st.back();
            st.pop_back();
            component[hoba] = component_num;
            visited[hoba] = false;
            if (hoba == v) break;
        }
        component_num++;
    }
}

void init()
{
    int x = 2000;
    node = vvi(x+1);
    visited = vb(x);
    low = vi(x);
    num = vi(x, -1);
    component = vi(x);
    st.clear();
    _time = 0, component_num = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mapii mp;
    int idx = 0;
    erep(i, 1, 1000)
    {
        mp[i] = idx++;
        mp[-i] = idx++;
    }
    while(cin >> n >> m)
    {
        init();
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            int x = mp[u], y = mp[v];
            if (u > 0 && v > 0)
            {
                //cout << x << " " << mp[-v] << endl;
                //cout << y << " " << mp[-u] << endl;
                node[x].push_back(mp[-v]);
                node[y].push_back(mp[-u]);
            }
            else if (u > 0 && v < 0)
            {
                //cout << x << " " << mp[-v] << endl;
                //cout << y << " " << y << endl;
                node[x].push_back(mp[-v]);
                node[y].push_back(y);
            }
            else if (u < 0 && v > 0)
            {
                //cout << x << " " << mp[-v] << endl;
                //cout << y << " " << mp[-u] << endl;
                node[x].push_back(mp[-v]);
                node[y].push_back(mp[-u]);
            }
            else if (u < 0 && v < 0)
            {
                //cout << x << " " << mp[-v] << endl;
                //cout << y << " " << mp[x] << endl;
                node[x].push_back(mp[-v]);
                node[y].push_back(x);
            }
        }

        rep(i, 0, 2*n)
        {
            if (num[i] == -1)
            {
                SCC(i);
            }
        }
        bool yay = true;
        for(int i = 0; i<2*n; i+=2)
        {
            if (component[i] == component[i+1])
            {
                yay = false;
                break;
            }
        }
        cout << yay << endl;
    }

    return 0;
}
