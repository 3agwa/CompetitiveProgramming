/*
 *  let's say we'll flip all white cells to our left
 *  this automatically changes the game into a nim game
 *  get the xor of white spots between the black ones and return the solution based on the xor's value
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

class CatAndRabbit
{
public:
	string getWinner(string tiles)
	{
		if (tiles.find("#") == -1) return "Rabbit";

		int xorr = 0, sum = 0;
		tiles += "#";
		rep(i, 0, sz(tiles))
		{
			if (tiles[i] == '.')
				sum++;
			else
				xorr ^= sum, sum = 0;
		}

		return xorr ? "Cat" : "Rabbit";
	}
};
