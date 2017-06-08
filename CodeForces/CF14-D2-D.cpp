/*
    try dropping each edge in the tree, count the # of components
    if the # of components is 2, get the leaves of the 2 components
    lastly, run bfs form the leaves to get the maximum length possible
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

int n;
vvi node;
bool visited[201];
bool drop[201][201];

int bfs(int i)
{
    reset(visited, false);
    queue< pii > Q;
    Q.push({i, 0});
    int mx = 0;
    while(!Q.empty())
    {
        pii temp = Q.front();
        Q.pop();
        int j = temp.first, level = temp.second;
        if (visited[j]) continue;
        mx = max(mx, level);
        visited[j] = true;
        rep(a, 0, sz(node[j]))
        {
            if (drop[j][node[j][a]]) continue;
            if (!visited[node[j][a]]) Q.push({node[j][a], level+1});
        }
    }
    return mx;
}

int get_leaf(int i)
{
    int ret = 0;
    queue<int> Q;
    Q.push(i);
    while(!Q.empty())
    {
        int j = Q.front();
        Q.pop();
        if (visited[j]) continue;
        ret = j;
        visited[j] = true;
        rep(a, 0, sz(node[j]))
        {
            if (drop[j][node[j][a]]) continue;
            if (!visited[node[j][a]]) Q.push(node[j][a]);
        }
    }
    return ret;
}

int dep;
void dfs(int curr_node, int depth)
{
    dep = max(dep, depth);
    visited[curr_node] = true;
    rep(i, 0, sz(node[curr_node]))
    {
        int child = node[curr_node][i];
        if (drop[curr_node][child]) continue;
        if (!visited[child])
        {
            dfs(child, depth+1);
        }
    }
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    node = vvi(n+1);
    rep(i, 0, n-1)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    int mx = 0;
    erep(i, 1, n)
    {
        rep(j, 0, sz(node[i]))
        {
            int child = node[i][j];
            drop[i][child] = drop[child][i] = true;

            int cnt = 1;
            reset(visited, false);

            erep(a, 1, n)
            {
                if (!visited[a])
                {
                    dep = 0;
                    dfs(a, 0);
                    cnt *= dep;
                }
            }
            if (cnt)
            {
                vi temp;
                reset(visited, false);
                erep(a, 1, n)
                {
                    if (!visited[a])
                    {
                        temp.push_back(get_leaf(a));
                    }
                }
                int sum = 1;
                sum *= bfs(temp[0]);
                sum *= bfs(temp[1]);
                mx = max(mx, sum);
            }
            drop[i][child] = drop[child][i] = false;
        }
    }
    cout << mx;

    return 0;
}
