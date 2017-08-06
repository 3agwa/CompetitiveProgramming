#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

deque<char> dq;

void summation(int n)
{
    rep(i, 0, n) cout << "()";
}

void solve(int n)
{
    if (!n) return;
    ll st = 0, en = 50000, mid, ret = -1;
    while(st <= en)
    {
        mid = (st+en)/2;
        if (mid*(mid+1) / 2 <= n) st = mid + 1, ret = mid;
        else en = mid - 1;
    }
    n -= ((ret * (ret+1))/2);
    rep(i, 0, ret-1) cout << "()";
    cout << "(";
    solve(n);
    cout << ")";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    solve(n);
    //rep(i, 0, sz(dq)) cout << dq[i];

    return 0;
}
