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
#define mp(x, y, z) {{x, y}, z}

vvi node;
int hoba[100001];

int main()
{
    /*
    6 5
    3 1
    1 2
    2 4
    5 6
    6 4
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    node.resize(n+1);
    vi arr(n+1);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        node[v].push_back(u);
        arr[u]++;
    }

    int cnt = n;
    set<int> st;
    erep(i, 1, n) if (!arr[i]) st.insert(i);
    set<int> :: iterator it;
    while(!st.empty())
    {
        it = st.end();
        it--;
        //cout << *it << endl;
        hoba[*it] = cnt--;
        int temp = *it;
        st.erase(it);
        rep(i, 0, sz(node[temp]))
        {
            arr[node[temp][i]]--;
            if (!arr[node[temp][i]]) st.insert(node[temp][i]);
        }
    }

    erep(i, 1, n) cout <<  hoba[i] << " ";

    return 0;
}
