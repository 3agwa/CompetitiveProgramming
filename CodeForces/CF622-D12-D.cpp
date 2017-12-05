/*
 *  no proof of the solution, used brute forcing on multiple examples (next permutation)
 *  found a pattern after multiple attempts
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

vi vec;
int n;

int get()
{
	vi di(n + 1);
	int ret = 0;
	rep(i, 0, sz(vec))
	{
		rep(j, i+1, sz(vec))
		{
			if (vec[i] == vec[j])
			{
				di[vec[i]] = j-i;
				break;
			}
		}
	}

	erep(i, 1, n)
	{
		ret += (n - i) * abs((di[i] + i - n));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	if (n&1)
	{
		for(int i = 1; i <= n; i += 2)
			cout << i << " ";
		for(int i = n-2; i>=1; i -= 2)
			cout << i << " ";
		cout << n << " ";
		
		for(int i = 2; i <= n; i += 2)
			cout << i << " ";
		for(int i = n-1; i>=2; i -= 2)
			cout << i << " ";
	}
	else
	{
		for(int i = 1; i <= n; i += 2)
			cout << i << " ";
		
		for(int i = n-1; i>=1; i -= 2)
			cout << i << " ";
		
		for(int i = 2; i <= n; i += 2)
			cout << i << " ";
		
		for(int i = n-2; i>=2; i -= 2)
			cout << i << " ";
		cout << n;
	}


	return 0;
}
