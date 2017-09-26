/*
 *  the loser is the one who has 1xh grid or wx1 grid
 *  hence, we need to make a cut with i >= 2 and the remaining cut should also be >= 2 to insure a chance of a winning position
 *  calculate the grundy for the 2 new independent games and xor their values for mex
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

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

int grundy[205][205];

int solve(int w, int h)
{
	if (grundy[w][h] != -1) return grundy[w][h];

	int ret = 0;

	vb visited(1005);

	for(int i = 2; w-i >= 2; i++) visited[solve(i, h) ^ solve(w-i, h)] = true;
	for(int i = 2; h-i >= 2; i++) visited[solve(w, i) ^ solve(w, h-i)] = true;

	while(visited[ret]) ret++;

	return grundy[w][h] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	reset(grundy, -1);
	int w, h;
	while(cin >> w >> h)
	{
		if (solve(w, h)) cout << "WIN\n";
		else cout << "LOSE\n";
	}


	return 0;
}
