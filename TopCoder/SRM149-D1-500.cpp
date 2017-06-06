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


class MessageMess
{
public:
    string msg;
    vs dic;
    vs hela;
    vs hoba;
    int memo[51];
    int solve(int i)
    {
        if (i > sz(msg)) return 0;
        if (i == sz(msg))
        {
            hoba = hela;
            return 1;
        }
        if (memo[i] != -1) return memo[i];

        int ret = 0;

        vi temp;
        rep(j, 0, sz(dic))
        {
            if(msg.substr(i, sz(dic[j])) == dic[j])
                temp.push_back(j);
        }
        rep(j, 0, sz(temp))
        {
            hela.push_back(dic[temp[j]]);
            ret += solve(i + sz(dic[temp[j]]));
            ret = min(ret, 2);
            hela.pop_back();
        }
        return memo[i] = ret;
    }

    string restore(vector <string> dictionary, string message)
    {
        reset(memo, -1);
        msg = message;
        dic = dictionary;
        int ret = solve(0);
        if (!ret) return "IMPOSSIBLE!";
        else if (ret > 1) return "AMBIGUOUS!";
        string x = "";
        rep(i, 0, sz(hoba))
        {
            if (i) x += " ";
            x += hoba[i];
        }
        return x;
    } // {"A", "B", "C", "D"}, "BADCAB"}

};

