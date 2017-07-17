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
#define mp(x, y, z) {{x, y}, z}

int n, arr[9], mid;
vi vec;
vvi hoba(9);

int memo[1001][(1<<8)+1];

int solve(int idx, int mask)
{
    if (idx > n)
    {
        if (mask == (1<<8)-1) return 0;
        return (mid == 1 ? 0 : -1e9);
    }
    if (mask == (1<<8)-1) return 0;
    if (memo[idx][mask] != -1) return memo[idx][mask];
    int ret = -1e9;
    ret = max(ret, solve(n+1, mask));
    rep(i, 0, 8)
    {
        if (mask & (1<<i)) continue;
        int temp = upper_bound(all(hoba[i]), idx) - hoba[i].begin();
        if (temp == sz(hoba[i])) continue;
        temp += mid - 2; // -1 inclusive -1 lower
        if (temp >= sz(hoba[i])) continue;
        if (temp >= 0)
        {
            int nmask = mask;
            nmask |= (1<<i);
            ret = max(ret, mid - 1 + solve(hoba[i][temp], nmask));
            temp++;
            if (temp == sz(hoba[i])) continue;
            ret = max(ret, mid + solve(hoba[i][temp], nmask));
        }
    }
    return memo[idx][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec = vi(n);
    rep(i, 0, 8) hoba[i].push_back(0);
    rep(i, 0, n)
    {
        cin >> vec[i];
        vec[i]--;
        arr[vec[i]]++;
        hoba[vec[i]].push_back(i+1);
    }
    int st = 1, en = n, ret = -1;
    while(st <= en)
    {
        mid = (st+en)/2;
        reset(memo, -1);
        int temp = solve(0, 0);
        if (temp > 0)
        {
            st = mid + 1, ret = temp;
        }
        else en = mid-1;
    }
    cout << ret;


    return 0;
}
