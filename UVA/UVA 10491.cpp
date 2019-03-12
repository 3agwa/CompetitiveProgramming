/*
 * if you start with the usual Monty Hall conditions (that is, that the host knows where the goats are located and always reveals goats),
 * even a single door opened implies that the chances of finding the car increase if you switch doors.
 *
 * If there are n doors with t cars, the probability you choose a car is t/n, and changing door leaves 
 * a probability (t−1)/(n−s−1) to eventually find the car. The probability you choose a goat is (n−t)/n, 
 * and changing door leaves a probability t/(n−s−1) to eventually find the car.
 * So the combined probability is t(t−1)/(n(n−s−1))+t(n−t)/(n(n−s−1)) = t(n−1)/(n(n−s−1))
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

	ld cow, car, open;
	while (cin >> cow >> car >> open)
	{
		ld total = cow + car;

		cout << fixed << setprecision(5)
				<< (car * (total - 1)) / (total * (total - open - 1)) << endl;
	}

	return 0;
}
