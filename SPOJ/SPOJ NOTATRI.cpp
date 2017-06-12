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

class OptimalQueues
{
public:
    int minWaitingTime(vector <int> clientArrivals, int tellerCount, int serviceTime)
    {
        sort(clientArrivals.rbegin(), clientArrivals.rend());
        int curr = 0, mx = 0;
        for(int i = 0; i < sz(clientArrivals); i+= tellerCount)
        {
            curr += serviceTime;
            rep(j, i, min(sz(clientArrivals), i + tellerCount))
            {
                mx = max(mx, curr + clientArrivals[j]);
            }
        }
        return mx;
    }
};


