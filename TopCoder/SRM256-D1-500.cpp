/*
    generate power set of nodes
    for each set, check if they're all connected with each other or not
    if they are, try adding 1 node, if this node is connected to all of them, then this is not maximal
    otherwise increment as this is a maximal clique
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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}


class CliqueCount
{
public:

    int arr[21][21], ret, n;
    vi vec;
    void solve(int idx)
    {
        if (idx == n)
        {
            if (vec.empty()) return;
            rep(i, 0, sz(vec))
            {
                rep(j, 0, sz(vec))
                {
                    if (i == j) continue;
                    int u = vec[i], v = vec[j];
                    if (!arr[u][v]) return;
                }
            }
            rep(i, 0, n)
            {
                if (binary_search(all(vec), i)) continue;
                int cnt = 0;
                rep(j, 0, sz(vec)) if (arr[i][vec[j]]) cnt++;
                if (cnt == sz(vec)) return;
            }
            ret++;
            return;
        }
        solve(idx+1);
        vec.push_back(idx);
        solve(idx+1);
        vec.pop_back();
    }

    int countCliques(vector <string> graph)
    {
        n = sz(graph[0]);
        reset(arr, 0);
        rep(i, 0, sz(graph)) rep(j, 0, sz(graph[i])) arr[i][j] = (graph[i][j] == '1');
        solve(0);
        return ret;
    }
};

