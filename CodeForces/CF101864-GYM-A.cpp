/*
 * it's easy to notice that anything in range [l, x-1] is valid
 * we want to count how many occurrences X has in range [l, r]
 * using a simple brute-force approach we could notice a pattern, the numbers are related to the powers of 2
 * after noticing the pattern, we want to count all numbers such that 2^i + pos is in range [max(x, l), r]
 * where pos is X/2 (noticeable from the pattern)
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	erep(t, 1, tc)
	{
		ll x, l, r;
		cin >> x >> l >> r;
		cout << "Case " << t << ": ";
		if (x & 1)
		{
			ll pos = x / 2;
			ll cnt = max(0ll, x - l);
//			cout << cnt << endl;
			ll mx = max(x, l);
			for (ll i = 0; (1ll << i) <= r; i++)
			{
				if (pos > (1ll << i))
					continue;
				ll val = (1ll << i) + pos;
//				cout << (1ll << i) << " " << i << " " << pos << endl;
				if (mx <= val && val <= r)
					cnt++;
			}
			ll den = (r - l + 1);
//			cout << cnt << " " << den << endl;
			ll gcd = __gcd(cnt, den);
			cout << cnt / gcd << "/" << den / gcd << endl;
		}
		else
		{
			ll num = max(0ll, x - l);
			ll den = r - l + 1;
			ll gcd = __gcd(num, den);
			cout << num / gcd << "/" << den / gcd << endl;
		}
	}

	return 0;
}
