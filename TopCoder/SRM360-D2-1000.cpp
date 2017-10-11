/*
 *  our target is to find a losing position from our current position
 *  thus we need to find all proper substrings and check if any of those lead to a losing position
 *  our base case would be the numbers from 0->9, as there are no proper substrings in this range, they're all losing positions
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

bool memo[1000001];

void get(int num)
{
	string x = "";
	int temp = num;
	while(num != 0)
	{
		int rem = num%10;
		num /= 10;

		x.push_back(rem + '0');
	}

	reverse(all(x));

	rep(i, 1, sz(x))
	{
		rep(j, 0, sz(x))
		{
			string y = x.substr(j, i);
			if (sz(y) != i) break;
			if (y[0] == '0') continue;

			int raqam = 0;
			rep(k, 0, sz(y))
				raqam = raqam*10 + y[k]-'0';

			if (!memo[temp - raqam])
			{
				memo[temp] = true;
				return;
			}

		}
	}
}

int modifiedGet(int num)
{
	string x = "";
	int temp = num, mn = 1e9;
	while(num != 0)
	{
		int rem = num%10;
		num /= 10;

		x.push_back(rem + '0');
	}

	reverse(all(x));

	rep(i, 1, sz(x))
	{
		rep(j, 0, sz(x))
		{
			string y = x.substr(j, i);
			if (sz(y) != i) break;
			if (y[0] == '0') continue;

			int raqam = 0;
			rep(k, 0, sz(y))
				raqam = raqam*10 + y[k]-'0';

			if (!memo[temp - raqam])
				mn = min(mn, raqam);
		}
	}

	return (mn == 1e9 ? -1 : mn);
}


class TakeSubstringGame
{
public:
	int winningMove(int n)
	{
		rep(i, 10, n)
			get(i);


		return modifiedGet(n);
	}
};

