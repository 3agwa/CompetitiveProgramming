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

vii edge;
vi arr;
int n, m;

bool solve(int mid)
{
    arr.clear();
    arr.resize(n+1); // always clear before resizing :)
    vvi node(n+1);
    rep(i, 0, mid)
    {
        node[edge[i].first].push_back(edge[i].second);
        arr[edge[i].second]++;
    }

    set<int> st; // could be done using queue
    erep(i, 1, n) if (!arr[i]) st.insert(i);
    while(!st.empty())
    {
        if (sz(st) > 1) return false;
        int hoba = *st.begin();
        st.erase(st.begin());
        for(auto i : node[hoba])
        {
            arr[i]--;
            if (!arr[i]) st.insert(i);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
    }

    int st = 0, en = m, ret = -1, mid;

    while(st <= en)
    {
        mid = (st+en)/2;
        if (solve(mid)) en = mid - 1, ret = mid;
        else st = mid + 1;
    }
    cout << ret;


    return 0;
}
