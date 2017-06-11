/*
    traced the input on paper, found that it'll output correctly if we iterate till sqrt(sqrt(n))
    solve for b (if exists) given the current index
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        ll n;
        cin >> n;
        ll temp = n;
        n = sqrt(n);
        n = sqrt(n);
        bool found = false;
        vector< pair< ll, ll > > vec;
        erep(i, 2, n)
        {
            ll val = (i*i)-1;
            if (temp%val == 0)
            {
                ll hoba = temp/val;
                hoba++;
                ll hela = sqrt(hoba);
                if (hela*hela == hoba)
                {
                    found = true;
                    vec.push_back({i, hela});
                }
            }
        }
        cout << "Case #" << t << ":\n";
        if (!found) cout << "For n=" << temp <<" there is no almost square factorisation.\n";
        else
        {
            cout << temp;
            rep(i, 0, sz(vec))
            {
                cout << "=(" << vec[i].first << "^2-1)*(" << vec[i].second << "^2-1)";
            }
            cout << endl;
        }
    }

    return 0;
}
