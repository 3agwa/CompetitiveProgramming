/*
    no idea is associated with this problem, just simulating the required nothing more
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

class BirthdayReminders
{
public:
    vector <string> remind(vector <string> friendNames, vector <int> birthDates, int currentDate, vector <string> occasions, vector <int> days, int k)
    {
        vector< pair< pii, pii > > vec;
        rep(i, 0, sz(birthDates))
        {
            rep(j, 0, sz(days))
            {
                ll a = -1, st = 0, en = 1e5, mid;
                while(st <= en)
                {
                    mid = (st+en)/2;
                    ll date = (ll)birthDates[i] + mid*(ll)days[j];
                    if (date >= currentDate) en = mid - 1, a = mid;
                    else st = mid + 1;
                }
                for(int b = a; b <= a+k; b++)
                {
                    int date = birthDates[i] + b*days[j];
                    vec.push_back({{date, j}, {i, b}});
                }
            }
        }
        sort(all(vec));
        vs ret;
        rep(i, 0, k)
        {
            int parse = vec[i].first.first;
            string x = "";
            while(parse)
            {
                int rem = parse%10;
                parse /= 10;
                x += (rem + '0');
            }
            reverse(all(x));
            x += ". ";
            x += friendNames[vec[i].second.first];
            x += " ";
            x += occasions[vec[i].first.second];
            x += " ";
            string y = "";
            parse = vec[i].second.second;
            while(parse)
            {
                int rem = parse%10;
                parse /= 10;
                y += (rem + '0');
            }
            reverse(all(y));
            x += "(";
            x += y;
            x += ")";
            ret.push_back(x);
        }
        return ret;
    }
};
