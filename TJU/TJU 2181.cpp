/*
    trivial MST problem, direct implementation of prim or kruskal's algorithms
*/

#include <bits/stdc++.h>

using namespace std;
/*
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
#define mp(x, y, z) {x, {y, z}}*/

vector< pair< int, pair<int, int> > > node;

int n, m;
int parent[1000000];

void set_parent()
{
    for(int i = 0; i<=n; i++) parent[i] = i;
}

int find_parent(int p)
{
    if (parent[p] == p) return p;
    else return parent[p] = find_parent(parent[p]);
}


int main()
{
    while(cin >> n)
    {
        node = vector< pair< int, pair<int, int> > >(n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int c;
                cin >> c;
                if (c == -1) c = 1e6;
                node.push_back({c, {i, j}});
            }
        }
        sort(node.begin(), node.end());
        set_parent();
        long long sum = 0;
        for(int i = 0; i<(int)node.size(); i++)
        {
            int u = node[i].second.first, v = node[i].second.second, cost = node[i].first;
            int a = find_parent(u), b = find_parent(v);
            if (a != b)
            {
                parent[a] = b;
                sum += cost;
            }
        }
        cout << sum << endl;
    }


    return 0;
}
