/*
 *  first thing to notice is that, if we had an array with 1 stones, we'd pick every other treasure
 *  we'll do the same here, now the extra step, we don't want the second player to get the current treasure
 *  this means that if the treasure has 2 remaining stones, he'll lose for sure (winning state for us)
 *  we'll calculate the total number of steps taken to arrive at such state, if that number is odd
 *  then player 2 will play first, since all remaining stones are 2, the first player will get all the remaining trasures
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

class StoneGame
{
public:
	int getScore(vector<int> treasure, vector<int> stones)
	{
		vi vec;
		int sum = 0, steps = 0;
		rep(i, 0, sz(stones))
		{
			if (stones[i] == 1) vec.push_back(treasure[i]), treasure[i] = 0, steps++;
			else
			{
				sum += treasure[i];
				steps += stones[i] - 2;
			}
		}

		sort(all(vec));
		int ret = 0;
		for(int i = sz(vec)-1; i>=0; i-=2) ret += vec[i];

		if (steps & 1) ret += sum;

		return ret;
	}
};
