/*
    brute force on the possible ranges and maximize over the intervals
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

class GerrymanderEasy
{
public:
    double getmax(vector <int> A, vector <int> B, int K)
    {
        int n = sz(A);
        rep(i, 1, n) A[i] += A[i-1], B[i] += B[i-1];

        double ret = 0;
        rep(i, 0, n)
        {
            rep(j, i+K-1, n)
            {
                double a = A[j], b = B[j];
                if (i) a -= A[i-1], b -= B[i-1];
                ret = max(ret, b/a);
            }
        }
        return ret;
    }
};

