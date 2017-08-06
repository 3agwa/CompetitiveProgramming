#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

ld dis(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int dcmp(double a, double b)
{
    return fabs(a-b) <= 1e-9 ? 0 : a < b ? -1 : 1;
}

double fast_hypot(double x, double y)
{
    return sqrt(x*x + y*y);
}

double eps = 1e-10;

ld area(ld ax, ld ay, ld ar, ld bx, ld by, ld br)
{
    double r = min(ar, br);
    double R = max(ar, br);
    double d = fast_hypot(ax-bx, ay-by);

    if (d < R - r + eps) return pi*r*r;
    if (d > R + r - eps) return 0.0;
    double area = r*r*acos((d * d + r * r - R * R) / 2 / d / r) + R*R*acos((d * d + R * R - r * r) / 2 / d / R) - 0.5*sqrt((-d + r + R) * (d + r - R) * (d - r + R) * (d + r + R));
    return area;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    erep(t, 1, n)
    {
        ld gx, gy, gr, wx, wy, wr;
        cin >> gx >> gy >> gr;
        cin >> wx >> wy >> wr;
        //cout << dis(gx, gy, wx, wy) - wr<< endl;
        ld dist = area(gx, gy, gr, wx, wy, wr);
        ld area = pi*gr*gr;
        //cout << dist << endl;
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(9) << (ld)(area - dist) << endl;
    }


    return 0;
}
