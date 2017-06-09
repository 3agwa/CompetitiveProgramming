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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

vll x;
vll y;
vll r;
vi parent;

bool inside(int i, int j)
{
    return ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= (r[i]-r[j])*(r[i]-r[j]));
}
bool visited[1001];

vi node[1001];
bool color[1001];
void dfs(int v, bool col)
{
    visited[v] = true;
    color[v] = col;
    for(auto i : node[v])
    {
        if (!visited[i]) dfs(i, !col);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    x = vll(n), y = vll(n), r = vll(n), parent = vi(n, -1);
    rep(i, 0, n) cin >> x[i] >> y[i] >> r[i];
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (r[j] > r[i] && inside(i, j))
            {
                if (parent[i] == -1 || r[parent[i]] > r[j]) parent[i] = j;
            }
        }
        node[parent[i]].push_back(i);
    }
    rep(i, 0, n) if (parent[i] == -1) dfs(i, 0);
    double sum = 0;
    rep(i, 0, n)
    {
        cout << parent[i] << " " << color[i] << endl;
        sum += r[i]*r[i]*(parent[i] == -1 || (color[i]) ? +1 : -1);
    }
    sum *= pie;
    cout << fixed << setprecision(9) << sum << endl;

    return 0;
}
