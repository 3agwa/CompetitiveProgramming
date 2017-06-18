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

double base[50001], h[50001], w[50001], d[50001], vol;
int n, x;

int dcmp(double a, double b)
{
    return fabs(a-b) <= eps ? 0 : a<b ? -1 : 1;
}

double solve(double mid)
{
    double volume = 0;
    rep(i, 0, x)
    {
        if (base[i] >= mid) continue;
        double hoba = min(mid-base[i], h[i]);
        volume += hoba*w[i]*d[i];
    }

    return volume;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> x;
        double mx = 0, mx_h = 0;
        rep(i, 0, x)
        {
            cin >> base[i] >> h[i] >> w[i] >> d[i];
            mx += h[i]*w[i]*d[i];
            mx_h = max(mx_h, base[i]+h[i]);
        }
        cin >> vol;

        if (vol > mx)
        {
            cout << "OVERFLOW\n";
        }
        else
        {

            double st = 1, en = 1e7, mid, cnt = 0;
            while(cnt++ < 100)
            {
                mid = st + (en-st)/2;
                if (solve(mid) < vol) st = mid;
                else en = mid;
            }

            cout << fixed << setprecision(2) << mid << endl;

        }
    }
    return 0;
}
