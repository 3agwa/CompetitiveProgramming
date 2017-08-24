/*
    try all possible combinations of 0s and 1s
    0 will indicate that the ball will move towards the right, 1 indicates otherwise
    for each 0, check the closest 1 to it and calculate the time they'll meet at
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

class BouncingBalls
{
public:
    double expectedBounces(vector <int> x, int T)
    {
        sort(all(x));
        int mask = 1<<sz(x);
        // 0 = yemeen, 1 = shemal
        double bounces = 0;
        rep(i, 0, mask)
        {
            string y = "";
            int temp = i;
            while(temp)
            {
                int rem = temp%2;
                y += rem + '0';
                temp /= 2;
            }
            while(sz(y) < sz(x)) y += "0";
            reverse(all(y));
            rep(j, 0, sz(y))
            {
                if (y[j] == '0')
                {
                    rep(k, j+1, sz(y))
                    {
                        if (y[k] != y[j])
                        {
                            double yay = (x[k]-x[j])/2.0;
                            if (yay <= (double)T)
                            {
                                bounces++;
                            }
                        }
                    }
                }
            }
        }
        return bounces / (1<<sz(x))*1.;
    }
};

