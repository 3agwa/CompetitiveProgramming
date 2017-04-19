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
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
}

int main()
{
    //input;
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double x[101], y[101], z;
    vi arrows(n);
    vvi hoba(n);
    rep(i, 0, n)
    {
        cin >> x[i] >> y[i];
        cin >> arrows[i];
        rep(j, 0, n-1)
        {
            cin >> z;
            hoba[i].push_back(z);
        }
    }
    vvi node(n);

    rep(i, 0, n)
    {
        rep(j, 0, sz(hoba[i]))
        {
            node[i].push_back(hoba[i][j]-1);
        }
    }
    vector<double> masafa(n, INT_MAX);
    set< pair<double, int> > st;
    st.insert({0, 0});
    while(!st.empty())
    {
        pair<double, int> temp = *st.begin();
        st.erase(st.begin());
        int idx = temp.second;
        double cost = temp.first;
        if (masafa[idx] != INT_MAX) continue;
        masafa[idx] = cost;
        rep(i, 0, sz(node[idx]))
        {
            if (arrows[idx])
            {
                int child = node[idx][i];
                double hela = dist(x[idx], y[idx], x[child], y[child]);
                if (masafa[child] > cost + hela)
                {
                    arrows[idx]--;
                    st.insert({cost + hela, child});
                }
            }
        }
    }

    cout << fixed << setprecision(6);
    rep(i, 0, n) cout << masafa[i] << "\n";

    return 0;
}
