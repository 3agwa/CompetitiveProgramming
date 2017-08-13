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

int _time, n, m, sol_num;
vvi node, answer;
vb visited;
vi st, num, in, temp;

inline void init()
{
    temp.clear();
    _time = sol_num = 0;
    st = vi(n+5);
    node = vvi(n+5);
    visited = vb(n+5);
    num = vi(n+5, -1);
    in = vi(n+5);
    answer = vvi(n+5);
}

void SCC(int v)
{
    num[v] = in[v] = ++_time;
    visited[v] = true;
    st.push_back(v);
    for(auto i : node[v])
    {
        if (num[i] == -1) SCC(i);
        if (visited[i]) in[v] = min(in[v], in[i]);
    }
    if (in[v] == num[v])
    {
        while(true)
        {
            int hoba = st.back();
            visited[hoba] = false;
            st.pop_back();
            answer[sol_num].push_back(hoba);
            if (hoba == v) break;
        }
        sol_num++;
    }
}

void dfs(int v)
{
    visited[v] = true;
    for(auto i : node[v]) if (!visited[i]) dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 0;
    bool flag = false;
    while(cin >> n >> m)
    {
        if (!n && !m) break;
        if (flag) cout << endl;
        flag = true, tc++;
        init();
        mapsi mp;
        map<int, string> rev;
        int idx = 1;
        while(m--)
        {
            string x, y;
            cin >> x >> y;
            if (!mp[x])
            {
                rev[idx] = x;
                mp[x] = idx++;
            }
            if (!mp[y])
            {
                rev[idx] = y;
                mp[y] = idx++;
            }
            node[mp[x]].push_back(mp[y]);
        }
        cout << "Calling circles for data set " << tc << ":\n";
        rep(i, 1, idx)
        {
            if (!visited[i])
            {
                temp.push_back(i);
                dfs(i);
            }
        }
        visited = vb(n+5);
        for(auto i : temp) SCC(i);
        rep(i, 0, sol_num)
        {
            if (answer[i].empty()) continue;
            rep(j, 0, sz(answer[i]))
            {
                if (j) cout << ", ";
                cout << rev[answer[i][j]];
            }
            cout << endl;
        }
    }

    return 0;
}
