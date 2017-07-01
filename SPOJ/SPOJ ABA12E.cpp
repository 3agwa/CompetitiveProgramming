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

int n, k;
ll arr[50001];

ll hoba(int l, int r)
{
    ll lef = (l) ? arr[l-1] : 0;
    ll right = arr[r];
    return right - lef;
}

ll solve(ll mid)
{
    ll cnt = 0;
    rep(i, 0, n)
    {
        ll st = i, en = n-1, midd, ret = -1;
        while(st <= en) // get # of intervals
        {
            midd = st + (en-st)/2;
            if (hoba(i, midd) <= mid) st = midd + 1, ret = midd;
            else en = midd-1;
        }
        if (ret != -1) cnt += (ret-i+1);
    }
    //cout << mid << " " << cnt << endl;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (i) arr[i] += arr[i-1];
    }

    ll st = 0, en = 1e15, mid, ret;
    while(st <= en) // BS on answer
    {
        mid = st + (en-st)/2;
        if (solve(mid) >= k) en = mid - 1, ret = mid;
        else st = mid + 1;
    }
    cout << ret;
    return 0;
}
