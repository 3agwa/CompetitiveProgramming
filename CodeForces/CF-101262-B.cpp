#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
    int n, m;
    cin >> n >> m;
    string x;
    cin >> x;
    if (m > n)
    {
        cout << "WRONGANSWER";
        return 0;
    }
    map<char, int> mp;
    rep(i, 0, sz(x)) mp[x[i]]++;
    int mn = INT_MAX;
    erep(i, 'a', 'z') mn = min(mn, mp[i]);
    if (mn > m) cout << "WRONGANSWER";
    else
    {
        char c;
        erep(i, 'a', 'z') if (mp[i] == mn) c = i;
        int rem = m - mn;
        rep(i, 0, sz(x))
        {
            if (rem && x[i] != c)
            {
                cout << x[i];
                rem--;
            }
            else cout << c;
        }
    }


    return 0;
}
