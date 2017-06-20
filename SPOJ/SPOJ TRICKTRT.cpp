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
#define mp(x, y, z) {{x, y}, z}

double x[50001], y[50001];
int n;

double solve(double mid)
{
    double ret = DBL_MIN;
    rep(i, 0, n)
    {
        ret = max(ret, (x[i]-mid)*(x[i]-mid) + (y[i]*y[i]));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n && n)
    {
        double mn = DBL_MAX, mx = DBL_MIN;
        rep(i, 0, n)
        {
            cin >> x[i] >> y[i];
            mn = min(mn, x[i]);
            mx = max(mx, x[i]);
        }
        double st = mn, en = mx, l, r, cnt = 0;
        rep(a, 0, 100)
        {
            l = st + (en-st) / 3.0;
            r = en - (en - st) / 3.0;
            if (solve(l) >= solve(r)) st = l;
            else en = r;
        }
        cout << fixed << setprecision(7) << st << " " << sqrt(solve(st)) << endl;
    }


    return 0;
}
