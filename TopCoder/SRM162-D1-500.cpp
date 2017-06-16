/*
    first thing to notice is that we could add N circles in the ith row
    and either add N-1 circles in the I+1th row or add N circles in the I+1th row
    adding N circles in the following row comes with a price
    
    the idea is, given some height H, calculate the number of circles that could fit in a 2(H+W)
    since we don't have W, we'll get it from the equation woodLength = 2*(H+W), solve for W
    now to calculate the # of circles in a row, it'll simply be W/(2*r)
    
    now Case1: circles placed as N, N-1, N, N-1
    since we already know the height, we could deduce the # of odd and even heights
    odd heights will contain N circles, even heights will contain N-1
    
    Case2: circles places as N, N, N, N
    from the test case, we could notice that the above allignment could occur
    if we have extra R space in the row
    so we need to check the remaining width after placing the N circles
    if it's greater than R, then we the placement could go as N, N, N, N
    
    finally, maximize the output over the 2 cases
*/
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
