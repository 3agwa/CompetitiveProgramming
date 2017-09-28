/*
 *  let's think about it this way, how many boxes to open in order to have <= X candies left
 *  we'll sort the vector, subtract the C - H[i] value as we're moving, once C is <= X, we have a solution (remaining of the array)
/*
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

class MysticAndCandiesEasy
{
public:
	int minBoxes(int C, int X, vector<int> high)
	{
		int n = sz(high);

		sort(all(high));

		rep(i, 0, n)
		{
			C -= high[i];
			if (C < X)
				return n - i;
			else if (C == X)
				return n - i - 1;
		}

		return 1;
	}
};
