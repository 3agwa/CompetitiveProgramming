/*
 *  let's run a normal bfs and slide the numbers into empty space
 *  since the grid is small, we can set our whole grid as visited to avoid overlapping 
 *  we'll keep a string indicating the moves so far
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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dz[] = {'R', 'L', 'D', 'U'};

int valid(int i, int j) { return (i>=0 && j>=0 && i<3 && j<3); }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	erep(t, 1, tc)
	{
		vvi arr(3, vi(3));
		rep(i, 0, 3)
		{
			rep(j, 0, 3)
			{
				cin >> arr[i][j];
			}
		}

		map<vvi, int> mp;

		queue< pair< vvi, pair<int, string> > > Q;

		Q.push(mp(arr, 1, ""));

		vvi ret;
		string hoba;

		while(!Q.empty())
		{
			vvi vec = Q.front().first;
			int depth = Q.front().second.first;
			string z = Q.front().second.second;

			Q.pop();

			if (mp[vec]) continue;
			mp[vec] = depth;

			rep(i, 0, 3)
			{
				rep(j, 0, 3)
				{
					if (!vec[i][j])
					{
						rep(a, 0, 4)
						{
							int x = i + dx[a], y = j + dy[a];
							char c = dz[a];

							if (valid(x, y))
							{
								swap(vec[i][j], vec[x][y]);
								if (!mp[vec])
								{
									z.push_back(c);
									hoba = z;
									ret = vec;
									Q.push(mp(vec, depth + 1, z));
									z.pop_back();
								}
								swap(vec[i][j], vec[x][y]);
							}
						}
					}
				}
			}
		}

		cout << "Puzzle #" << t << endl;
		rep(i, 0, 3)
		{
			rep(j, 0, 3)
			{
				if (j) cout << " ";
				cout << ret[i][j];
			}
			cout << endl;
		}
		cout << hoba << endl << endl;
	}

	return 0;
}
