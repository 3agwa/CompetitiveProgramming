/*
    if k is 1, then this is the basic game, player 1 wins of the piles are odd
    if we can finish the game using only K moves, we output the answer according to the number of steps
    taken to finish the game
    
    else we use all our K moves and we reach a smaller version of the game where we can't move K steps
    so we're back as if K = 1, apply the same conditions, the only difference is that if it was 
    second player's turn to start the game, we flip the outcome of the "normal" game
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

int k, n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc >> k;
	while(tc--)
	{
		cin >> n >> m;
		if (n > m) swap(n, m);

		if (n%(k+1) == 0) cout << "+\n";
		else
		{
			int d = (m-n);
			if (k == 1)
			{
				if (d&1) cout << "+\n";
				else cout << "-\n";
			}
			else
			{
				if ((n / (k+1))&1)
				{
					if (d&1) cout << "-\n";
					else cout << "+\n";
				}
				else
				{
					if (d&1) cout << "+\n";
					else cout << "-\n";
				}
			}
		}
	}

	return 0;
}
