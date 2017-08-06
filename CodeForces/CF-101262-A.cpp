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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (n*(n-1));
    /*string x;
    cin >> x;
    if (x == "0" || x == "1") cout << -1;
    else
    {
        string y = x;
        while(y.back() == '0') y.pop_back();
        reverse(all(y));
        if (x != y) cout << y;
        else
        {
            char c = y.front();
            int a = c - '0', b = a-1;
            cout << a << b;
            rep(i, 1, sz(y)) cout << y[i];

        }
    }*/

    return 0;
}
