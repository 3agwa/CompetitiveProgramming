/*
    after writing a recursive dp approach memoizing on level and sum, it lead to memory limit
    i had to transer this code into iterative dp
    now we still have the same memory, we have to drop a parameter
    since the building is based on the next state, then i could only keep track of that state
    so we decrease from [max_level][max_sum] to [2][max_sum]
    we only need to keep track of the following level, and build this level's answer based on it
    again, had some help with the idea, wasted a lot of time on this but i gained a good amount of experience from it
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

int r, g, h, modulo = 1e9 + 7;
int memo[2][200001];

int solve(int i, int sum)
{
    if (sum > r) return 0;
    if (i > h)
    {
        int total = h*(h+1)/2;
        return (total-sum <= g);
    }

    if (memo[i][sum] != -1)
        return memo[i][sum];

    int ret = 0;
    ret += solve(i+1, sum + i);
    ret %= modulo;
    ret += solve(i+1, sum);
    ret %= modulo;
    return memo[i][sum] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(memo, 0);
    cin >> r >> g;
    for(int i = 1; ; i++)
    {
        if ((i*(i+1))/2 <= (r+g)) h = i;
        else break;
    }
    erep(j, 0, r)
    {
        memo[1][j] = ((h*(h+1)/2 - j) <= g);
        //cout << memo[1][j] << " ";
    }

    for(int i = h; i>=1; i--)
    {
        erep(j, 0, r)
        {
            if (i+j <= r) memo[0][j] += memo[1][j+i];
            memo[0][j] += memo[1][j];
            memo[0][j] %= modulo;
        }
        erep(j, 0, r) memo[1][j] = memo[0][j], memo[0][j] = 0;
    }
    cout << memo[1][0];

    return 0;
}
