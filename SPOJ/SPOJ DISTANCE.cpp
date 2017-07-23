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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int n, d;

vector< set<ll > > hoba;

ll arr[100001][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    hoba.resize(d+1);

    vector< pair<ll, ll > >  temp((1<<d) + 1, {2e9, -2e9});


    rep(i, 0, n)
    {
        rep(j, 0, d)
        {
            cin >> arr[i][j];
        }
    }



    rep(i, 0, 1<<(d-1))
    {
        rep(j, 0, n)
        {
            ll lololey = 0;//arr[j][0];
            rep(k, 0, d)
            {
                if (i & (1<<(k))) lololey += arr[j][k];
                else lololey -= arr[j][k];
            }
            temp[i].first = min(temp[i].first, lololey);
            temp[i].second = max(temp[i].second, lololey);
        }
    }

    ll mx = 0;

    rep(i, 0, 1<<(d-1))
    {
        mx = max(mx, temp[i].second - temp[i].first);
    }
    cout << mx;

    return 0;
}
