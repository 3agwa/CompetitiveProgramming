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

int dcmp(ld a, ld b)
{
    return fabs(a-b) <= eps ? 0 : a<b ? -1 : 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld n, R, r;
    cin >> n >> R >> r;
    if (r > R)
    {
        cout << "NO";
    }
    else if (n == 1)
    {
        if (R >= r) cout << "YES";
        else cout << "NO";
    }
    else
    {
        ld c = 2.0*(r);
        c *= c;
        ld a = R-r, b = R-r;
        ld theta = c / (2.0*a*b);
        theta = 1 - theta;
        theta = acos(theta)*180 / pie;
        cout << c << " " << a << " " << b << " " << theta << endl;
        theta *= n;
        if (dcmp(theta, (ld)360.0) < 1) cout << "YES";
        else cout << "NO";
    }


    return 0;
}
