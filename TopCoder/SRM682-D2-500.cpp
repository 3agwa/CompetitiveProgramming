/*
    push components of DNA in a queue, if the current string could be found as a substring of sequence
    this means that i could erase some letters from the beginning and the end to reach that string
    keep adding characters till we can't find that substring in the sequence and return it
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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class TopBiologist
{
public:
    string findShortestNewSequence(string sequence)
    {
        queue<string> Q;
        Q.push("A");
        Q.push("C");
        Q.push("G");
        Q.push("T");
        string ret = "";
        while(!Q.empty())
        {
            string x = Q.front();
            Q.pop();
            if (sequence.find(x) == -1) return x;
            else
            {
                Q.push(x + "A");
                Q.push(x + "C");
                Q.push(x + "G");
                Q.push(x + "T");
            }
        }
        return ret;
    }
};
