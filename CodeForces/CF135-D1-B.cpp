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

double x[8], y[8];

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
}

bool sha2labaz(vector< pair<double, double> >  vec)
{
    set<ll> st;
    rep(i, 0, 4)
    {
        vll temp;
        rep(j, 0, 4)
        {
            if (i == j) continue;
            temp.push_back(dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
            st.insert(dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
        }
        sort(all(temp));
        if (temp[0] + temp[1] != temp[2]) return false;
    }
    return (sz(st) == 2);
}

bool sha2labaz2(vector< pair<double, double> >  vec)
{
    set<ll> st;
    rep(i, 0, 4)
    {
        vll temp;
        rep(j, 0, 4)
        {
            if (i == j) continue;
            temp.push_back(dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
            st.insert(dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
        }
        sort(all(temp));
        if (temp[0] + temp[1] != temp[2]) return false;
    }
    return (sz(st) == 2 || sz(st) == 3);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    rep(i, 0, 8) cin >> x[i] >> y[i];
    rep(i, 0, 8)
    {
        rep(j, 0, 8)
        {
            if (i == j) continue;
            rep(k, 0, 8)
            {
                if (i == k || j == k) continue;
                rep(l, 0, 8)
                {
                    if (i == l || j == l || k == l) continue;
                    vector< pair< double, double > > vec;
                    vec.push_back({x[i], y[i]});
                    vec.push_back({x[j], y[j]});
                    vec.push_back({x[k], y[k]});
                    vec.push_back({x[l], y[l]});
                    if (sha2labaz(vec))
                    {
                        vector< pair< double, double > > hoba;
                        rep(a, 0, 8)
                        {
                            if (a == i || a == j || a == k || a == l) continue;
                            hoba.push_back({x[a], y[a]});
                        }
                        if(sha2labaz2(hoba))
                        {
                            cout << "YES\n";
                            cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << endl;
                            rep(a, 0, 8)
                            {
                                if (a == i || a == j || a == k || a == l) continue;
                                cout << a+1 << " " ;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";

    return 0;
}
