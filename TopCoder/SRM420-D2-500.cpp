/*
    simulate the passing of months/days, increment the time (in seconds) accordingly
    increment the months array (index 1) by 1 if the year is a leap year
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

class YearProgressbar
{
public:
    double percentage(string currentDate)
    {
        int h1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string hoba[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        bool leap = false;
        currentDate += " ";
        string month = currentDate.substr(0, currentDate.find(" "));
        currentDate.erase(0, currentDate.find(" ") + 1);
        string day = currentDate.substr(0, currentDate.find(","));
        currentDate.erase(0, currentDate.find(" ") + 1);
        string year = currentDate.substr(0, currentDate.find(" "));
        currentDate.erase(0, currentDate.find(" ") + 1);
        string hrs = currentDate.substr(0, currentDate.find(":"));
        currentDate.erase(0, currentDate.find(":") + 1);
        string mins = currentDate.substr(0, currentDate.find(" "));
        int yr = 0;
        rep(i, 0, sz(year)) yr = yr*10 + year[i] - 48;
        if ((yr % 400 == 0) || (yr%4 == 0 && yr%100 != 0)) leap = true;
        double total = 0;
        rep(i, 0, 12) total += h1[i];
        if (leap) total++;
        total *= 24;
        total *= 60;
        total *= 60;
        double sub_total = 0;
        rep(i, 0, 12)
        {
            if (month == hoba[i])
            {
                int dy = 0;
                rep(j, 0, sz(day)) dy = dy*10 + day[j] - 48;
                rep(j, 0, dy-1) sub_total += 60*60*24;
                int secs = 0;
                rep(j, 0, sz(mins)) secs = secs*10 + mins[j]-48;
                secs *= 60;
                int hrss = 0;
                rep(j, 0, sz(hrs)) hrss = hrss*10 + hrs[j]-48;
                hrss *= 60;
                hrss *= 60;
                sub_total += hrss;
                sub_total += secs;
                break;
            }
            else
            {
                if (leap && hoba[i] == "February") sub_total += 60*60*24*(1+h1[i]);
                else
                    sub_total += 60*60*24*h1[i];
            }
        }
        double ret = sub_total*100 / total;



        return ret;
    }
};
