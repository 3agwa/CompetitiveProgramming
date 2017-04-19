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

string x;
vector<pair<string, int> > vec;
void trans()
{
    int temp = 0, idx = 1;
    while(x[idx] != ',') temp = temp*10 + x[idx++] - 48;
    string y = "";
    idx++;
    while(x[idx] != ')') y+=x[idx++];
    if (y.empty()) y = "-";
    vec.push_back({y, temp});
}

int main()
{
    //output;
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> x && x != "()")
    {
        vec.clear();
        trans();
        while(cin >> x && x != "()") trans();
        vvi levels(300);
        sort(all(vec));
        bool flag = true;
        map<string, int> mp;
        rep(i, 0, sz(vec))
        {
            if (!mp[vec[i].first]) mp[vec[i].first]++;
            else flag = false;
        }
        if (vec[0].first != "-")
        {
            flag = false;
        }
        else
        {
            levels[0].push_back(vec[0].second);
            rep(i, 1, sz(vec))
            {
                string sub = vec[i].first.substr(0, sz(vec[i].first)-1);
                if (sub.empty()) sub = "-";
                int t = lower_bound(all(vec), pair<string, int>({sub, -1})) - vec.begin();
                if (t == sz(vec)) flag = false;
                else if (vec[t].first != sub) flag = false;
                else levels[sz(vec[i].first)].push_back(vec[i].second);
            }
        }
        if (!flag) cout << "not complete\n";
        else
        {
            bool entered = false;
            rep(i, 0, 300)
            {
                rep(j, 0, sz(levels[i]))
                {
                    if (entered) cout << " ";
                    cout << levels[i][j];
                    entered = true;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
