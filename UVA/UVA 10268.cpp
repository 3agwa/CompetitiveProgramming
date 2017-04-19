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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

ll fast_pow(ll base, ll pow)
{
    if (!pow) return 1;

    ll temp = fast_pow(base, pow/2);
    temp = temp*temp;
    if (pow&1) temp = temp*base;
    return temp;
}

int main()
{
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    while(getline(cin, x))
    {
        stringstream ss(x);
        vll coeff;
        ll hoba;
        while(ss >> hoba) coeff.push_back(hoba);
        ss.clear();
        getline(cin, x);
        stringstream s(x);
        vll values;
        while(s >> hoba) values.push_back(hoba);
        vll ans;
        rep(i, 0, sz(values))
        {
            ll sum = 0;
            rep(j, 0, sz(coeff))
            {
                sum += fast_pow(values[i], sz(coeff)-j-1)*coeff[j];
            }
            ans.push_back(sum);
        }

        rep(i, 0, sz(ans))
        {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
