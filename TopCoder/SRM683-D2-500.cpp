/*
    if the sum of both arrays are not the same, return -1
    else accumulate the absolute differences and return their value 
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

class MoveStonesEasy
{
public:
    int get(vector <int> a, vector <int> b)
    {
        int sum = 0, n = sz(a);
        rep(i, 0, n) sum += (a[i]-b[i]);
        if (sum) return -1;
        int ret = 0, extra = 0;
        for(int i = n-1; i>=0; i--)
        {
            if (i-1 >= 0) a[i-1] += (a[i] - b[i]), ret += (abs(a[i]-b[i])), a[i] = b[i];
        }

        /*rep(i, 0, n)
        {
            if (a[i] > b[i])
            {
                if (i+1 < n) a[i+1] += (a[i] - b[i]), ret += (a[i]-b[i]), a[i] = b[i];
            }
        }*/
        return ret;
    }
};
