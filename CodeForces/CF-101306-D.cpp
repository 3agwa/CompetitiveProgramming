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
#define mapii map<int, int>
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
    string small = "PgEfTYaWGHjDAmxQqFLRpCJBow";
    string capital = "nyUKZXkbvzIdshurMilNSVOtec";
    int n;
    cin >> n;
    string x;
    getline(cin, x);
    getline(cin, x);

    rep(i, 0, sz(x))
    {
        if (isalpha(x[i]))
        {
            if (x[i] >= 'a' && x[i] <= 'z') cout << small[x[i]-'a'];
            else cout << capital[x[i]-'A'];
        }
        else cout << x[i];
    }
    cout << endl;

    return 0;
}
