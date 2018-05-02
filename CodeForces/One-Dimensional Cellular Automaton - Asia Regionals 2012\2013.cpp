/*
 *  It's easy to notice that if T was smaller, it would've been easily solved using DP
 *  But since T is really large, we could think about changing our dp into a matrix power
 *  For constructing the transition matrix, it's easy to notice that each cell is the sum of the 3 cells above it
 *  The only exception to that is if we're standing in the first/last column, answer to our cell would be the sum of the above 2 cells
 *  This is enough for us to construct the transition matrix, base matrix would be the input
 *  The answer would be the first column of the matrix(base * (transition ^ T))
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvii;
typedef long double ld;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) { x, {y, z } }

const int N = 1000;
ll n, m, a, b, c, t;
ll s[N][500];
ll mod;

vvi matrixUnit(int n)
{
	vvi res(n, vi(n));
	for (int i = 0; i < n; i++)
		res[i][i] = 1;
	return res;
}

vvi matrixAdd(const vvi &a, const vvi &b)
{
	int n = a.size();
	int m = a[0].size();
	vvi res(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = (a[i][j] + b[i][j]) % mod;
	return res;
}

vvi matrixMul(const vvi &a, const vvi &b)
{
	int n = a.size();
	int m = a[0].size();
	int k = b[0].size();
	vvi res(n, vi(k));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int p = 0; p < m; p++)
				res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % mod;
	return res;
}

vvi matrixPow(const vvi &a, int p)
{
	if (p == 0)
		return matrixUnit(a.size());
	if (p & 1)
		return matrixMul(a, matrixPow(a, p - 1));
	return matrixPow(matrixMul(a, a), p / 2);
}

vvi matrixPowSum(const vvi &a, int p)
{
	int n = a.size();
	if (p == 0)
		return vvi(n, vi(n));
	if (p % 2 == 0)
		return matrixMul(matrixPowSum(a, p / 2),
				matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
	return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

//5 100000 1 2 3 5
//1 2 3 4 5

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n >> mod >> a >> b >> c >> t)
	{
		if (!n && !mod && !a && !b && !c && !t)
			break;
		vvi mul(n, vi(n)), x(n, vi(n));
		mul[0][0] = b, mul[1][0] = c;
		mul[n - 1][n - 1] = b, mul[n - 2][n - 1] = a;

		rep(i, 1, n-1)
		{
			int cnt = 0;
			rep(j, i - 1, i + 2)
			{
	//			mul[j][i] = 1;
				if (!cnt)
					mul[j][i] = a;
				else if (cnt == 1)
					mul[j][i] = b;
				else
					mul[j][i] = c;
				cnt++;
			}
		}

		for (int i = 0; i < n; i++)
			cin >> x[0][i];

		vvi ret = matrixMul(x, matrixPow(mul, t));

		rep(i, 0, n)
		{
			cout << ret[0][i] << " ";
		}
		cout << endl;

	}

	return 0;
}
