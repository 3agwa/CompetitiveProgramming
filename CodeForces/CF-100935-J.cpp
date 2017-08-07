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

map< pii, int > compress;
int n, m, sx, sy;
// idx, cost, time
vector< vector< pair< int, pii > > > node;
map< pii, int > mp;
void dijkstra()
{
    // cost, time, idx
    set< pair< pii, int > > st;
    st.insert({{1, 0}, 1});
    while(!st.empty()) // check on time
    {
        pair< pii, int > hoba = *st.begin();
        st.erase(st.begin());
        int timee = hoba.first.second, cost = hoba.first.first;
        int idx = hoba.second;
        if (mp[{idx, timee}]) continue;
        mp[{idx, timee}] = cost;
        for(auto i : node[idx])
        {
            if (abs(i.second.second + timee) <= 100 && !mp[{i.first, i.second.second + timee}])
            {
                st.insert({{cost + i.second.first, timee + i.second.second}, i.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc, out = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> sx >> sy;
        int rakam = 1;
        compress.clear(), mp.clear();
        compress[{sx, sy}] = rakam++;
        node = vector< vector< pair< int, pii > > >(n*m + 1);
        int p;
        cin >> p;
        while(p--)
        {
            int u, v, c, t, x, y;
            cin >> u >> v >> x >> y >> c >> t;
            if (!compress[{u, v}]) compress[{u, v}] = rakam++;
            if (!compress[{x, y}]) compress[{x, y}] = rakam++;
            node[compress[{u, v}]].push_back({compress[{x, y}], {c, t}});
        }
        cout << "Case " << out++ << ":\n";
        dijkstra();
        int q;
        cin >> q;
        while(q--)
        {
            int u, v, w;
            cin >> u >> v >> w;

            int hoba = mp[{compress[{u, v}], w}];
            if (hoba) cout << hoba-1 << endl;
            else cout << "No\n";
        }
    }
    return 0;
}
