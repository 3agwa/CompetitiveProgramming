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
    int tc;
    cin >> tc;
    while(tc--)
    {
        string x;
        cin >> x;
        if (x == "A" || x == "P") cout << "YES\n";
        else if (sz(x)&1) cout << "NO\n";
        else
        {
            bool flag = false;
            erep(i, 0, 10) if ((1<<i) == sz(x)) flag = true;
            if (flag)
            {
                for(int i = 0; i<sz(x); i+=2)
                {
                    if (x[i] == 'P' || x[i+1] == 'P') continue;
                    cout << "NO\n";
                    goto barra;
                }
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
barra:;
    }


    return 0;
}
