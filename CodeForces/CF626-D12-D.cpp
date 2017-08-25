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

bool cmp(pair< int, double > a, pair< int, double > b)
{
    return b.first*b.second*(1.-a.second) < (1.-b.second)*a.first*a.second;
}

int n;
vector<pair< int, double > > vec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec = vector<pair< int, double > >(n);
    rep(i, 0, n) cin >> vec[i].first >> vec[i].second, vec[i].second /= 100.0;
    sort(all(vec), cmp);
    double sum = 0, ratioo = 0;
    rep(i, 0, n)
    {
        //cout << vec[i].first << " " << vec[i].second << endl;
        sum += vec[i].first;
        sum += ratioo*(1. - vec[i].second);
        ratioo += vec[i].first*vec[i].second;
    }
    cout << fixed << setprecision(9) << sum << endl;

    return 0;
}


