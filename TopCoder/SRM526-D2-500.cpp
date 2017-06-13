/*
    try to form N ducks from each cell vertically and horizontally (if possible)
    calculate the distance required for that formation
    return minimum distance
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

class DucksAlignment
{
public:
    int minimumTime(vector <string> grid)
    {
        int ducks = 0;
        vii yucky_ducky;
        vii sucky_ducky;
        rep(i, 0, sz(grid)) rep(j, 0, sz(grid[i])) if (grid[i][j] == 'o') ducks++, yucky_ducky.push_back({i, j}), sucky_ducky.push_back({j, i});
        sort(all(sucky_ducky));
        sort(all(yucky_ducky));
        int ret = INT_MAX;
        rep(i, 0, sz(grid))
        {
            int sum = 0;
            rep(j, 0, sz(sucky_ducky)) sum += abs(i - sucky_ducky[j].second);
            for(int j = 0; j + ducks <= sz(grid[0]); j++)
            {
                int sum2 = 0, idx = 0;
                rep(k, j, j+ducks)
                {
                    sum2 += abs(sucky_ducky[idx++].first - k);
                }
                ret = min(ret, sum2 + sum);
            }
        }

        rep(i, 0, sz(grid[0]))
        {
            int sum = 0;
            rep(j, 0, sz(yucky_ducky)) sum += abs(i - yucky_ducky[j].second);
            for(int j = 0; j + ducks <= sz(grid); j++)
            {
                int sum2 = 0, idx = 0;
                rep(k, j, j+ducks)
                {
                    sum2 += abs(yucky_ducky[idx++].first - k);
                }
                ret = min(ret, sum2 + sum);
            }
        }
        return ret;
    }
};
