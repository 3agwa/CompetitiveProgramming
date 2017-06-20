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
#define mp(x, y, z) {{x, y}, z}

int n, mx_dist, last;
vvi node;
int dist[5001];

void dfs(int v, int mx, int par)
{
    dist[v] = max(mx, dist[v]);
    if (mx > mx_dist)
    {
        mx_dist = mx;
        last = v;
    }
    for(auto i : node[v]) if (i != par) dfs(i, mx+1, v);
}

int main()
{
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n)
    {
        node = vvi(n);
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            rep(j, 0, x)
            {
                int v;
                cin >> v;
                node[i].push_back(v-1);
            }
        }
        reset(dist, 0);
        mx_dist = 0;
        dfs(0, 1, -1);
        mx_dist = 0;
        dfs(last, 1, -1);
        mx_dist = 0;
        dfs(last, 1, -1);
        //rep(i, 0, n) bfs(i);
        int mn = INT_MAX, mx = INT_MIN;
        rep(i, 0, n)
        {
            mn = min(mn, dist[i]);
            mx = max(mx, dist[i]);
        }
        cout << "Best Roots  :";
        rep(i, 0, n)
        {
            if (dist[i] == mn) cout << " " << i+1;
        }
        cout << endl;
        cout << "Worst Roots :";
        rep(i, 0, n)
        {
            if (dist[i] == mx) cout << " " << i+1;
        }
        cout << endl;
    }
    return 0;
}
