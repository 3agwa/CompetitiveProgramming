/*
    after T swaps, we have 2 options
    either index A was not changed, or it was changed (T-1) times and changed back to desired position in the T-th swap
    so the probability of staying the same is (n-2) / (n)
    probability of the swaps is (1-p)/(n-1) * probability of selected the desired index (1/n) *  remaining indices (n-1)
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

class RandomSwaps
{
public:
    double getProbability(int arrayLength, int swapCount, int a, int b)
    {
        int cnt = swapCount;
        double n = arrayLength*1.0;
        double rat = (((n-1)*(n-2))/2);
        rat /= n*(n-1) / 2;
        double S = n*(n-1) / 2;
        double ret = (a==b) ? 1.0 : 0.0, Q;
        rep(i, 0, swapCount)
        {
            Q = (1-ret) / (n-1);
            ret = ret * rat + Q * (1/S) * (n-1);
        }
        return ret;
    }
};
