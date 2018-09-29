// SoS DP: Given an array, we want to count the # of ways to pick elements who's first bit is turned on
// then count the # of ways to pick elements who's 2nd bit is turned on
// in case there are values counted twice, we have to remove them
// hence, we need cnt[1], cnt[2] and cnt[3], to get cnt[3] we use sum over subsets dp
// 00 - 0
// 01 - 1
// 10 - 2
// 11 - 3
// # of subsets such that their OR is 1 1-2-3-3, we need to remove the additional 3 as it's counted twice
// using inclusion exclusion principle we could do the mentioned above, all we need to have is cnt[3] 
// cnt[3] could be provided using SoS dp
// Complexity O(NlogN)

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
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int mod = 1e9 + 7, N = 2e6 + 5;
ll pw[N], cnt[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	pw[0] = 1;
	rep(i, 1, N)
		pw[i] = (2ll * pw[i - 1]) % mod;
//	rep(i, 1, N)
//		pw[i] = mod(pw[i]-1, mod);

	int n;
	cin >> n;
	rep(i, 0, n)
	{
		int x;
		cin >> x;
		cnt[x]++;         // taba3 el sos dp
	}
  
  // taba3 el sos dp
  {
    rep(i, 0, 20)
    {
      rep(mask, 0, (1<<20))
      {
        if (mask & (1 << i))
        {
          int idx = mask ^ (1 << i);
          cnt[idx] = (cnt[idx] + cnt[mask]) % mod;
        }
      }
    }
  }
  
	ll ans = 0;
  // inclusion exclusion
	erep(i, 1, 1e6)
	{
		int sign = __builtin_popcount(i) & 1 ? 1 : -1;
		ans = (ans + sign * (pw[cnt[i]] - 1) % mod) % mod;
	}

	cout << ((pw[n] - 1 - ans) % mod + mod) % mod << endl;

	return 0;
}
