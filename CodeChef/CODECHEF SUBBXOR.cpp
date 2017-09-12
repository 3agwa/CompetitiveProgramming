/*
	we'll use a trie data structure to insert the xor-ed numbers
	we'll query on how many subarrays in the tree who's xor with (number) is < k
	
	a details explanation could be found here:
	https://github.com/MohamedNabil97/CompetitiveProgramming/blob/master/CodeChef/SUBBXOR.cpp
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

struct trie
{
	trie *child[2];
	int cnt;

	trie()
	{
		child[0] = NULL;
		child[1] = NULL;
		cnt = 0;
	}

	void insert(int n, int idx)
	{
		cnt++;
		if (idx == -1)
			return;

		int bit = (n & (1 << idx)) != 0;

		if (child[bit] == NULL)
			child[bit] = new trie();

		child[bit]->insert(n, idx-1);
	}

	int retrieve(int n, int k, int idx)
	{
		if (idx == -1)
			return 0;

		int bitn = (n & (1 << idx)) != 0;
		int bitk = (k & (1 << idx)) != 0;

		if (bitk)
		{
			int hela = 0, hoba = 0;
			if (bitn)
			{
				if (child[1] != NULL)
					hela = child[1]->cnt;
				if (child[0] != NULL)
					hoba = child[0]->retrieve(n, k, idx - 1);
			}
			else
			{
				if (child[0] != NULL)
					hela = child[0]->cnt;
				if (child[1] != NULL)
					hoba = child[1]->retrieve(n, k, idx - 1);
			}

			return hela + hoba;
		}
		else
		{
			if (bitn)
			{
				if (child[1] != NULL)
					return child[1]->retrieve(n, k, idx - 1);
			}
			else
			{
				if (child[0] != NULL)
					return child[0]->retrieve(n, k, idx - 1);
			}
		}
		return 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while(tc--)
	{
		int n, k;
		cin >> n >> k;

		ll sum = 0;
		int xorr = 0;

		trie root;
		root.insert(0, 30);

		while(n--)
		{
			int x;
			cin >> x;

			xorr ^= x;
			sum += root.retrieve(xorr, k, 30);
			root.insert(xorr, 30);

		}
		cout << sum << endl;
	}
	return 0;
}
