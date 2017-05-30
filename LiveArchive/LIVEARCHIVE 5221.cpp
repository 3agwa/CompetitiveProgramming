/*
    run bfs from each node to calculate the clicks required to reach 
    all nodes in the component, then divide the sum by n*(n-1)
    where N is the number of different nodes in the graph
    
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

int main()
{
    output;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n, m, tc = 0;
    while(cin >> n >> m && n && m)
    {
        n--, m--;
        vvi node(101);
        tc++;
        int cnt = 1;
        node[n].push_back(m);
        int mx = 0;
        set<int> st;
        while(cin >> n >> m && n && m)
        {
            mx = max(mx, n);
            mx = max(mx, m);
            st.insert(n);
            st.insert(m);
            cnt++;
            n--, m--;
            node[n].push_back(m);
        }
        double sum = 0;
        rep(i, 0, mx)
        {
            bool visited[101] = {};
            queue< pii > Q;
            Q.push({i, 0});
            int t = 0;
            while(!Q.empty())
            {
                int idx = Q.front().first, cost = Q.front().second;
                Q.pop();
                if (visited[idx]) continue;
                visited[idx] = true;
                sum += cost;
                rep(j, 0, sz(node[idx]))
                {
                    int child = node[idx][j];
                    if (!visited[child]) Q.push({child, cost + 1});
                }
            }
        }
        int t = sz(st);
        sum /= (t*(t-1));
        cout << "Case " << tc << ": average length between pages = " << fixed << setprecision(3) << sum << " clicks\n";
    }


    return 0;
}
