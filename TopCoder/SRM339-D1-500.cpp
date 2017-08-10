/*
    we'll dp over the states we have, we'll need to keep track of the sum so far, the remaining rounds and the bet value
    the bet is always a power of 2, so it's better to memoize over the size of power instead the whole value 
    we have 2 options, either to win the bet, hence we claim the value and add it to our current sum, and play the next round
    or lose this round, bet is multiplied by 2 and the current value decreases by the old bet
    if our sum is >= target we return 1
    if no rounds are left we return 0
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

int sum, r;
double probb, memo[1010][60][20];
bool visited[1010][60][20];

double solve(int cur_sum, int rounds, int bet)
{
    if (cur_sum >= sum) return 1;
    if (!rounds) return 0;
    if (visited[cur_sum][rounds][bet]) return memo[cur_sum][rounds][bet];
    visited[cur_sum][rounds][bet] = true;
    if (cur_sum - (1<<bet) < 0) return 0.0;
    return memo[cur_sum][rounds][bet] = solve(cur_sum + (1<<bet), rounds-1, 0) * probb + solve(cur_sum - (1<<bet), rounds-1, bet+1) * (1-probb);
}

class TestBettingStrategy
{
public:
    double winProbability(int initSum, int goalSum, int rounds, int prob)
    {
        reset(visited, false);
        sum = goalSum;
        r = rounds;
        probb = (double)prob / 100;
        return solve(initSum, rounds, 0);
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
    cout << "]" << endl;
    TestBettingStrategy *obj;
    double answer;
    obj = new TestBettingStrategy();
    clock_t startTime = clock();
    answer = obj->winProbability(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    int p2;
    int p3;
    double p4;

    {
        // ----- test 0 -----
        p0 = 10;
        p1 = 11;
        p2 = 4;
        p3 = 50;
        p4 = 0.875;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 10;
        p1 = 20;
        p2 = 20;
        p3 = 50;
        p4 = 0.3441343307495117;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 10;
        p1 = 20;
        p2 = 10;
        p3 = 90;
        p4 = 0.34867844010000015;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 24;
        p1 = 38;
        p2 = 24;
        p3 = 60;
        p4 = 0.5940784635646947;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING