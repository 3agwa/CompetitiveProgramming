#include <bits/stdc++.h>
/*
    for each point, check the segments which it may fall onto
    then, get Y-coordinate if the point falls onto the segment
    this could be done using slope, since we have slope of segment
    and slope X coordinate of intersection
    then get the closest segment to the point (highest Y <= Point.Y)
    lastly, check which edge the point will fall off from (lowest Y)
*/

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

ll memo[34][34][101];
int tc, n, k;

ll solve(int one, int zero, int mask)
{
    if ((one > n/2) || (zero > n/2)) return 0;
    if (one == n/2 && zero == n/2)
    {
        return !(mask%k);
    }

    if (memo[one][zero][(mask%k)] != -1)
    {
        return memo[one][zero][(mask%k)];
    }

    ll ret = 0;
    ret += solve(one, zero+1, (mask<<1)%k);
    ret += solve(one+1, zero, ((mask<<1) + 1)%k );
    return memo[one][zero][(mask%k)] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    erep(t, 1, tc)
    {
        reset(memo, -1);
        cin >> n >> k;
        cout << "Case " << t << ": ";
        if ((k == 0) || (n&1)) cout << 0 << endl;
        else cout << solve(1, 0, 1) << endl;
    }

    return 0;
}
