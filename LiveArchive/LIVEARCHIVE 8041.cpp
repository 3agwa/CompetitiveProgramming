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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int n, m;

vi x;
vi y;

int arr[101][101];

/*
0 based node indices
left nodes are numbered from 0
right nodes are numbered from 0 as well
*/
struct MaximumMatching
{
    vector<int> m1, m2, seen;
    vector<vector<int> > g;
    int seen_id;
    MaximumMatching(int numNodesLeft, int numNodesRight)
    {
        g = vector<vector<int> >(numNodesLeft, vector<int>());
        m1 = vector<int>(numNodesLeft, -1);
        m2 = vector<int>(numNodesRight, -1);
        seen_id = 0;
        seen = vector<int>(numNodesRight, 0);
    }
    void addEdge(int leftNode, int rightNode)
    {
        assert(leftNode < int(m1.size()));
        assert(rightNode < int(m2.size()));
        g[leftNode].push_back(rightNode);
    }
    int getMaxMatching()
    {
        int ans = 0;
        for (int node = 0; node < int(m1.size()); node++)
        {
            seen_id++;
            if (dfs(node)) ans++;
        }
        return ans;
    }
    bool dfs(int node)
    {
        for (int i = 0; i < int(g[node].size()); i++)
        {
            int child = g[node][i];
            // if the child is not matched yet, match it with me
            if (m2[child] == -1)
            {
                m2[child] = node;
                m1[node] = child;
                return true;
            }

            // if the child was seen before (some other node tried to take it), leave it
            if (seen[child] == seen_id) continue;
            seen[child] = seen_id;

            // if the child is already matched with some other node, try to match that other node is some other way
            int enemy = m2[child];
            // take the child for me
            m1[enemy] = -1;
            m1[node] = child;
            m2[child] = node;
            // try to match the enemy
            if (dfs(enemy)) return true;
            // match the child with the enemy if not successful
            m1[enemy] = child;
            m1[node] = -1;
            m2[child] = enemy;
        }
        return  false;
    }

};

bool visited[101][101];

int row(int i)
{
    int mx = 0;
    rep(j, 0, m) mx = max(mx, arr[i][j]);
    return mx;
}

int col(int j)
{
    int mx = 0;
    rep(i, 0, n) mx = max(mx, arr[i][j]);
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    x.resize(n), y.resize(m);

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
            if (arr[i][j]) x[i] = max(x[i], arr[i][j]), y[j] = max(y[j], arr[i][j]);
        }
    }

    MaximumMatching flow(n, m);
    int accum = 0;

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (x[i] == y[j] && arr[i][j]) flow.addEdge(i, j);
        }
    }

    flow.getMaxMatching();

    vi xx(n);
    vi yy(m);

    ll ret = 0;

    rep(i, 0, sz(flow.m1))
    {
        if (flow.m1[i] == -1) continue;
        xx[i] = true;
        yy[flow.m1[i]] = true;
        ret -= max(0, x[i]-1);
    }

    rep(i, 0, n) if (!xx[i]) ret -= max(0, x[i]-1);
    rep(i, 0, m) if (!yy[i]) ret -= max(0, y[i]-1);

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (!arr[i][j]) continue;
            ret += (arr[i][j] - 1);
        }
    }
    cout << ret << endl;


    return 0;
}
