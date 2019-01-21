/*
 *  we want to count the frequency for each color in a subtree and for the colors with maximum frequency we want the sum of those colors
 *  since we're dealing with an operation regarding subtrees, we could use the idea of small to large to compute our result
 *  
 *  small to large basically finds the child with maximum size and merges the rest of the children with that child
 *  this could be done in NlogN time
 *  
 *  i maintain a map for colors, frequency and sum (sum[freq])
 *  i update the maps as i merge, reducing the old sum and updating the new one as well as the frequencies
 *  the answer for each node will be the sum of the biggest frequency is the sum map
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 1e5 + 5;
int n, c[N];
ll res[N];
vi node[N];
map<int, int> *col[N];
map<int, int> *freq[N];
map<int, ll> *sum[N];

void dfs(int v, int p)
{
	int mx = -1;

	for (auto i : node[v])
	{
		if (i == p)
			continue;
		dfs(i, v);
		if (mx == -1 || col[i]->size() > col[mx]->size())
			mx = i;
	}

	if (mx == -1)
	{
		col[v] = new map<int, int>();
		freq[v] = new map<int, int>();
		sum[v] = new map<int, ll>();
	}
	else
	{
		col[v] = col[mx];
		freq[v] = freq[mx];
		sum[v] = sum[mx];
	}

	{
		if (col[v]->find(c[v]) != col[v]->end())
		{
			int f = (*freq[v])[c[v]];
			(*sum[v])[f] -= (1 * 1ll * c[v]);
			if ((*sum[v])[f] == 0)
			{
				sum[v]->erase(f);
			}
			(*freq[v])[c[v]]++;
			f++;
			(*sum[v])[f] += (1 * 1ll * c[v]);
		}
		else
		{
			(*col[v])[c[v]] = true;
			(*freq[v])[c[v]] = 1;
			(*sum[v])[1] += c[v];
		}
	}

	for (auto i : node[v])
	{
		if (i == mx || i == p)
			continue;

		for (auto it : *col[i])
		{
			// color exists in heavy child
			if (col[v]->find(it.first) != col[v]->end())
			{
				int f = (*freq[v])[it.first];
				(*sum[v])[f] -= (1 * 1ll * it.first);
				if ((*sum[v])[f] == 0)
				{
					sum[v]->erase(f);
				}
				(*freq[v])[it.first] += (*freq[i])[it.first];
				f = (*freq[v])[it.first];
				(*sum[v])[f] += (1 * 1ll * it.first);
			}
			else
			{
				(*col[v])[it.first] = true;
				(*freq[v])[it.first] = (*freq[i])[it.first];
				int f = (*freq[v])[it.first];
				(*sum[v])[f] += (1 * 1ll * it.first);
			}
		}

		sum[i]->clear();
		freq[i]->clear();
		col[i]->clear();
		delete sum[i];
		delete freq[i];
		delete col[i];
	}

	map<int, ll>::iterator it = sum[v]->end();
	it--;
	int f = it->first;

	res[v] = (*sum[v])[f];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	erep(i, 1, n)
		cin >> c[i];

	rep(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	dfs(1, 0);

	erep(i, 1, n)
		cout << res[i] << " ";

	return 0;
}
