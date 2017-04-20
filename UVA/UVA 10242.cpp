#include <bits/stdc++.h>

                /* I start by sorting the input points then find the common start point between
                   the two input points, then i subtract x2-x1 and y2-y1 to get the required
                   answer, i simply iterate to get the x2 and x1 points from the input as well */

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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int main()
{
    //output;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    vector< pair<double, double> > pt(4);
    while(cin >> pt[0].first >> pt[0].second)
    {
        rep(i, 1, 4) cin >> pt[i].first >> pt[i].second;
        sort(all(pt));
        double x, y;
        rep(i, 0, 3)
        {
            if (pt[i] == pt[i+1])
            {
                rep(j, 0, 4)
                {
                    if (pt[j] != pt[i])
                    {
                        x = pt[j].first;
                        y = pt[j].second;
                        break;
                    }
                }
                double a1 = pt[i].first - x, a2 = pt[i].second - y;
                rep(j, 0, 4)
                {
                    if (pt[j] != pt[i] && pt[j] != pair<double, double> (x, y))
                    {
                        cout << fixed << setprecision(3) << pt[j].first - a1 << " " <<  pt[j].second - a2 << endl;
                        //cout << endl;
                        goto barra;
                    }
                }
            }
        }
barra:;
    }

    return 0;
}
