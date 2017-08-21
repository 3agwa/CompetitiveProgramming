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

class ElevatorLimit
{
public:
    vector <int> getRange(vector <int> enter, vector <int> exit, int physicalLimit)
    {
        int sum = 0, l = 0, r = 0;
        rep(i, 0, sz(enter))
        {
            sum -= exit[i];
            l = min(l, sum);
            sum += enter[i];
            r = max(r, sum);
        }
        vi vec;
        if (r <= physicalLimit && r-l <= physicalLimit) vec.push_back(-l), vec.push_back(physicalLimit-r);
        return vec;
    }
};

