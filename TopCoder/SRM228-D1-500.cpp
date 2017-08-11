/*
    if we were player 1, we'd like to maximize our profit
    if we were player 2, we'd like to minimize player 1's profit
    hence, if we need to subtract the greatest value of both ends
    dp on those states along with player's turn and return the solution
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int total, n, memo[1000001][2];
bool visited[1000001];
vi vec;

int solve(int rem, bool player)
{
    if (rem == total)
    {
        return (!player);
    }
    if (memo[rem][player] != -1) return memo[rem][player];
    int ret = 0;
    rep(i, 0, n)
    {
        if (rem + vec[i] <= total)
        {
            if (!player && !visited[rem + vec[i]])
            {
                visited[rem + vec[i]] = true;
                ret |= solve(rem + vec[i], !player);
                visited[rem + vec[i]] = false;
                if (ret) break;
            }
            else if (player && visited[rem + vec[i]])
            {
                visited[rem + vec[i]] = false;
                ret |= solve(rem + vec[i], !player);
                visited[rem + vec[i]] = true;
            }
        }

    }
    return memo[rem][player] = ret;

}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> total >> n)
    {
        reset(visited, false);
        reset(memo, -1);
        vec = vi(n);
        rep(i, 0, n) cin >> vec[i];
        cout << solve(0, 0) << endl;
    }
    return 0;
}
