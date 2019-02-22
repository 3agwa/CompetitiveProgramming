/*
 *  In this problem, we want to know how many ways to pick a team containing myself + 1 of my classmates
 *  we can loop over the class members and pick 2, 3, 4, .. , n members (myself included) and we pick the remaining randomly 
 *  from any other class
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

ld nCr(unsigned long long n, unsigned long long r)
{
	if (n < r)
		return 0;
	if (n == r)
		return 1;
	return (nCr(n - 1, r) / (n - r)) * n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h;
	cin >> n >> m >> h;
	h--;
	n--;
	int sum = 0;
	vi vec(m);
	rep(i, 0, m)
	{
		cin >> vec[i];
		sum += vec[i];
	}
	sum--;
	vec[h]--;
	if (sum < n)
		return cout << -1, 0;
	ld res = 0;
	erep(i, 1, vec[h])
	{
		int remR = n - i;
		int remN = sum - vec[h];

		ld a = nCr(remN, remR);
		ld b = nCr(vec[h], i);

		ld d = nCr(sum, n);
		res += (a / d) * b;
	}
	cout << fixed << setprecision(9) << res << endl;

	return 0;
}
