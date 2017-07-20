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

ll n, t;

vector< pair< char, pii > > data;
map< int, set< pii > > x, y;

vll dist;

void dijkstra()
{
    set< pair< ll, int > > st;
    st.insert({0, 0});
    dist = vll(n, -1);

    while(!st.empty())
    {
        pair< ll, int > a = *st.begin();
        st.erase(st.begin());
        ll cost = a.first;
        int idx = a.second;

        if (dist[idx] != -1) continue;
        dist[idx] = cost;

        int curr_x = data[idx].second.first;
        int curr_y = data[idx].second.second;
        char direction = data[idx].first;
        //cerr << idx << endl;

        if (direction == 'U')
        {
            for(auto i = x[curr_x].lower_bound({curr_y, idx}); i != x[curr_x].end(); i++)
            {
                int new_idx = i->second;
                int new_x = data[new_idx].second.first;
                int new_y = data[new_idx].second.second;
                int new_dir = data[new_idx].first;

                if (dist[new_idx] == -1) st.insert({cost + abs(curr_y-new_y), new_idx});

                if (direction == new_dir && idx != new_idx) break;
            }
        }

        if (direction == 'R')
        {
            for(auto i = y[curr_y].lower_bound({curr_x, idx}); i != y[curr_y].end(); i++)
            {
                int new_idx = i->second;
                int new_x = data[new_idx].second.first;
                int new_y = data[new_idx].second.second;
                int new_dir = data[new_idx].first;

                if (dist[new_idx] == -1) st.insert({cost + abs(curr_x-new_x), new_idx});

                if (direction == new_dir && idx != new_idx) break;

            }
        }

        if (direction == 'D')
        {
            for(auto i = x[curr_x].lower_bound({curr_y, idx}); ; i--)
            {
                int new_idx = i->second;
                int new_x = data[new_idx].second.first;
                int new_y = data[new_idx].second.second;
                int new_dir = data[new_idx].first;

                if (dist[new_idx] == -1) st.insert({cost + abs(curr_y-new_y), new_idx});

                if (direction == new_dir && idx != new_idx) break;

                if (i == x[curr_x].begin()) break;
            }
        }

        if (direction == 'L')
        {
            for(auto i = y[curr_y].lower_bound({curr_x, idx}); ; i--)
            {
                int new_idx = i->second;
                int new_x = data[new_idx].second.first;
                int new_y = data[new_idx].second.second;
                int new_dir = data[new_idx].first;

                if (dist[new_idx] == -1) st.insert({cost + abs(curr_x-new_x), new_idx});

                if (direction == new_dir && idx != new_idx) break;

                if (i == y[curr_y].begin()) break;
            }
        }
    }
}

int main()
{
    /*
    4 1000000000000000000
    0 0 U
    0 1000000000 R
    1000000000 1000000000 D
    1000000000 0 L
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    data.resize(n);
    rep(i, 0, n)
    {
        int u, v; char c;
        cin >> u >> v >> c;
        data[i] = {c, {u, v}};
        x[u].insert({v, i});
        y[v].insert({u, i});
    }

    dijkstra();

    rep(i, 0, n)
    {
        if (dist[i] != -1)
        {
            ll temp = max(0LL, t - dist[i]);

            ll hela = data[i].second.first, hoba = data[i].second.second;

            if (data[i].first == 'U') hoba += temp;
            if (data[i].first == 'D') hoba -= temp;
            if (data[i].first == 'R') hela += temp;
            if (data[i].first == 'L') hela -= temp;

            cout << hela << " " << hoba << endl;
        }
        else cout << data[i].second.first << " " << data[i].second.second << endl;
    }

    return 0;
}
