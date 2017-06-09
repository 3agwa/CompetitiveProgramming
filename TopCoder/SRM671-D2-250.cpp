/*
    iterate over the smallest between L and W
    binary search to get the largest side length such that i*L <= M
    maximize over output values
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class BearPaints
{
public:
    long long maxArea(int W, int H, long long M)
    {
        ll mx = 0;
        if (H < W)
        {
            erep(i, 1, H)
            {
                ll st = i, en = W, mid, ret = 1;
                while(st <= en)
                {
                    mid = (st+en)/2;
                    if ((ll)i*mid <= M) st = mid + 1, ret = mid;
                    else en = mid - 1;
                }
                //cout << i << " " << ret << endl;
                mx = max(mx, i*ret);
            }
        }
        else
        {
            erep(i, 1, W)
            {
                ll st = i, en = H, mid, ret = 1;
                while(st <= en)
                {
                    mid = (st+en)/2;
                    if ((ll)i*mid <= M) st = mid + 1, ret = mid;
                    else en = mid - 1;
                }
                //cout << i << " " << ret << endl;
                mx = max(mx, i*ret);
            }
        }
        return mx;
    }
};
