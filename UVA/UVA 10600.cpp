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

vector< pair< int, pii > > node;

int n, m;
int parent[1000000];
bool inside[1000000];
vi second;

void set_parent()
{
    erep(i, 0, n) parent[i] = i;
}

int find_parent(int p)
{
    if (parent[p] == p) return p;
    else return parent[p] = find_parent(parent[p]);
}

void mst(int edge)
{
    int cnt = 0, sum = 0;
    set_parent();
    rep(i, 0, sz(node))
    {
        int u = node[i].second.first, v = node[i].second.second, cost = node[i].first;
        int a = find_parent(u), b = find_parent(v);
        if (a != b && i != edge)
        {
            cnt++;
            sum += cost;
            parent[a] = b;
        }
    }
    if (cnt == n-1) second.push_back(sum);
}


int main()
{
    output;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        node.clear();
        reset(inside, false);
        second.clear();
        rep(i, 0, m)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            node.push_back(mp(c, u, v));
        }
        sort(all(node));
        set_parent();
        int mst1 = 0;

        rep(i, 0, sz(node))
        {
            int u = node[i].second.first, v = node[i].second.second, cost = node[i].first;
            int a = find_parent(u), b = find_parent(v);
            if (a != b)
            {
                mst1 += cost;
                parent[a] = b;
                inside[i] = true;
            }
        }
        rep(i, 0, sz(node))
        {
            if (inside[i]) mst(i);
        }
        sort(all(second));
        cout << mst1 << " " << second.front() << endl;

    }


    return 0;
}
