/*
    we'll use maximum bipartite matching to solve this problem
    1- for each node on the path, find all interesting points that the dog 
    could go to and come pack to node i+1 in the given time
    
    2- match the node on the path to all interesting points that applies the above condition
    
    3- the solution would be the N nodes + maximum matching output
    
    4- for each node, check if it's matched with an interesting place and output the solution accordingly
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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        vii vec(n);
        rep(i, 0, n) cin >> vec[i].first >> vec[i].second;
        MaximumMatching flow(n, m);
        vii hoba(m);
        rep(i, 0, m) cin >> hoba[i].first >> hoba[i].second;
        rep(i, 0, n-1)
        {
            double a = 2*dist(vec[i].first, vec[i].second, vec[i+1].first, vec[i+1].second);
            rep(j, 0, m)
            {
                double b = dist(vec[i].first, vec[i].second, hoba[j].first, hoba[j].second);
                double c = dist(hoba[j].first, hoba[j].second, vec[i+1].first, vec[i+1].second);
                if (b + c <= a) flow.addEdge(i, j);
            }
        }
        cout << n + flow.getMaxMatching() << endl;
        rep(i, 0, n)
        {
            if (i) cout << " ";
            cout << vec[i].first << " " << vec[i].second;
            int idx = flow.m1[i];
            if (idx != -1)
            {
                cout << " " << hoba[idx].first << " " << hoba[idx].second;
            }
        }
        cout << endl;
        if (tc) cout << endl;
    }

    return 0;
}
