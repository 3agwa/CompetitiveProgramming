/*
	we'll keep track of the passed weeks and the number of weeks we won
	we can derive the overall sum and the current money i have from these two
	we'll try to pick or leave the weeks, when we arrive at the base case
	simply return the expected money to have given that we won X times
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

vd vec;
double sum, n, pot, week, memo[1001][1001];

double solve(int w, int picked)
{
	if (w == week) return vec[0] + picked*pot;
	if (memo[w][picked] == memo[w][picked]) return memo[w][picked];
	double p = (vec[0] + picked*pot) / (sum + w*pot);
	double ret = solve(w+1, picked+1)*p + solve(w+1, picked) * (1. - p);
	return memo[w][picked] = ret;
}

class BankLottery
{
public:
	double expectedAmount(vector<int> accountBalance, int weeklyJackpot,
			int weekCount)
	{
		reset(memo, -1);
		n = sz(accountBalance), pot = weeklyJackpot, week = weekCount;
		rep(i, 0, n) vec.push_back(accountBalance[i]), sum += vec[i];
		return solve(0, 0);
	}
};
