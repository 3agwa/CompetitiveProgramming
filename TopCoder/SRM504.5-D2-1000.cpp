
/*
    first choice is to pick the first number in queue if it is the desired number
    otherwise i'll have to simulate the 2 operations, if the number is odd then i move the first member to the last of the queue
    if it's even we pop the first element
    so, probability of picking 4 is 1/6
    probability of an even number != 4 is 1/3
    probability of an odd number is 1/2
    one last thing, if the queue has only 1 member, i have to check whether or not this member is the desired one or not
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

int mm;
map< pair< int, deque<int> >, double > memo;

double solve(int rem, deque<int> vec)
{
    if (sz(vec) == 1) return (vec.front() == mm);
    if (vec.empty()) return 0;
    if (!rem) return (vec.front() == mm);
    if (memo.find({rem, vec}) != memo.end()) return memo[{rem, vec}];
    deque<int> a = vec, b = vec;
    a.push_back(a.front()), a.pop_front();
    b.pop_front();
    double ret = 0;
    if (vec.front() == mm)
    {
        deque<int> dq;
        dq.push_back(vec.front());
        ret = (double)1/6 * solve(rem-1, dq);
    }
    ret = ret + solve(rem-1, b) * (double)1/3 + solve(rem-1, a) * (double)1/2;
    return memo[{rem, vec}] = ret;
}

class TheTicketsDivTwo
{
public:
    double find(int n, int m, int k)
    {
        memo.clear();
        mm = m;
        deque<int> vec;
        erep(i, 1, n) vec.push_back(i);
        return solve(k, vec);
    }
};
