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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}


class ProgrammingDevice
{
public:

    ll n, mx;
    ll memo[51];
    vii vec;

    ll solve(int i)
    {
        if (i == n) return 0;

        ll &ret = memo[i];
        if (ret != -1) return ret;
        ret = 1e15;
        ll sum = 0, packs;
        rep(j, i, n)
        {
            sum = vec[j].first + vec[j].second - vec[i].first;
            packs = ceil((double)sum/(double)mx);
            cout << j << " " << i << " " << sum << " " << packs << endl;
            ret = min(ret, packs + solve(j+1));
        }
        return memo[i] = ret;
    }

    int minPackets(vector <int> offset, vector <int> size, int maxData)
    {
        vec.clear();
        n = sz(offset);
        mx = maxData;
        reset(memo, -1);
        rep(i, 0, sz(size)) vec.push_back({offset[i], size[i]});
        sort(all(vec));
        return solve(0);
    }
};
