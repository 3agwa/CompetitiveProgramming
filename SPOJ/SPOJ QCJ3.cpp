/*
 *  we have multiple nim games here, we only consider odd number of boxes
 *  as the rule states N%(M+1) != 0, player 1 wins, since M = 1, we only consider odd boxes
 *  all what's left to do is xor the positions where the above conditions occurs
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while(tc--)
	{
		int n;
		cin >> n;

		int xorr = 0;

		erep(i, 1, n)
		{
			int x;
			cin >> x;
			if (x & 1) // if even, i'll lose: N % (m + 1) = 0
				xorr ^= i;
		}

		if (xorr) cout << "Tom Wins\n";
		else cout << "Hanks Wins\n";

	}

	return 0;
}
