/*
 *  consider each 2 consecutive coins as a pile, this could be done using cancellation rule
 *  if the ith pile makes a move, i+1th pile could cancel this move by mirroring the same movement
 *  xor the values of the pile to find who's the winner
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while(tc--)
	{
		int n;
		cin >> n;
		vector<int> vec(n);

		for(int i = 0; i<n; i++) cin >> vec[i];
		sort(vec.begin(), vec.end());

		int xorr = n&1 ? vec[0]-1 : 0;

		for(int i = n&1; i<n; i+= 2)
		{
			xorr ^= (vec[i + 1] - vec[i] - 1);
		}

		if (xorr) cout << "Georgia will win\n";
		else cout << "Bob will win\n";
	}

	return 0;
}
