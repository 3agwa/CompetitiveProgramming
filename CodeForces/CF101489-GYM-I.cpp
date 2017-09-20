/*
    after some analysis, you can see that the player that reaches an even number wins the game
    hence, the first player will win if either A or B are odd, he can take 1 away and reach a winning state for himself
    otherwise the second player wins
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

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int tc;
	cin >> tc;
	while(tc--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);

		int turns = 0;

		if (!a) turns = b&1;
		else
		{
			if ((a & 1) || (b & 1)) turns = 1;
			else turns = 0;
		}

		if (!turns) cout << "abdullah\n";
		else cout << "hasan\n";
	}

	return 0;
}
