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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int dcmp(double a, double b)
{
    return fabs(a-b) <= eps ? 0 : a<b ? -1 : 1;
}

class JarBox
{
public:
    int numJars(int radius, int woodlength)
    {
        double hoba = woodlength, r = radius;
        int mx = 0;
        erep(i, 0, 100)
        {
            int h = i+1;
            double d1 = (double)i*sqrt(3)*r + 2*r;
            double rem = hoba - (2*d1);
            rem /= 2;
            if (dcmp(2*r, rem) <= 0)
            {
                int odd = rem / (2*r);
                int even = odd - 1;
                int temp = 0;
                if (h&1)
                {
                    temp += ((h/2) + 1)*odd + (h/2)*even;
                }
                else
                {
                    temp += (h/2)*odd + (h/2)*even;
                //    cout << (h/2) + 1 << " " << i << endl;
                    //rem -= 2*(h/2)*r;
                }
                rem = hoba - (2*d1) - eps;
                rem /= 2;
                rem -= 2*r*odd;
                mx = max(mx, temp);
                if (dcmp(r, rem) <= 0 && i)
                {
                    temp = 0;
                    if (h&1)
                        temp += ((h/2) + 1)*odd + (h/2)*odd;
                    else temp += (h/2)*odd + (h/2)*odd;
                    mx = max(mx, temp);
                }
                // << i << " " << mx << endl;
            }
        }
        return mx;
    }
};
