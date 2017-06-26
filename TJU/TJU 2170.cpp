#include <bits/stdc++.h>

using namespace std;

/*#define ll long long
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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}*/

int parent[200001], rankk[200001], n, m, u, v, c;
vector< pair< int, pair< int, int > > > edges;

void set_parent()
{
    for(int i = 0; i<n; i++) parent[i] = i, rankk[i] = 0;
}

int find_parent(int p)
{
    if(parent[p] == p) return p;
    return parent[p] = find_parent(parent[p]);
}

void union_both(int x, int y)
{
    if (rankk[x] > rankk[y]) swap(x, y);
    parent[x] = y;
    if (rankk[x] == rankk[y]) rankk[y]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int st, en, mn, a, b, x, y;
    while(cin >> n >> m)
    {
        if (!n || !m) break;
        edges.clear();
        for(int i = 0; i<m; i++)
        {
            cin >> u >> v >> c;
            u--, v--;
            edges.push_back({c, {u, v}});
        }
        sort(edges.begin(), edges.end());
        cin >> st >> en;
        st--, en--;
        mn = INT_MAX;
        for(int i = 0; i<m; i++)
        {
            set_parent();
            for(int j = i; j<m; j++)
            {
                a = edges[j].second.first, b = edges[j].second.second;
                x = find_parent(a), y = find_parent(b);
                if (x != y) union_both(x, y);
                if (find_parent(st) == find_parent(en))
                {
                    mn = min(mn, edges[j].first - edges[i].first);
                    break;
                }
            }
        }
        if (mn == INT_MAX) cout << -1 << endl;
        else cout << mn << endl;
    }
    return 0;
}
