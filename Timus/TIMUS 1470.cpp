/*
    this is a 3D BIT problem, the trick is to find the proper sets to use inclusion/exclusion princple 
*/
#include <iostream>

using namespace std;

const int MX = 130;

int bit[MX][MX][MX];

void update(int x, int y, int z, int val)
{
	while(x < MX)
	{
		int y1 = y;
		while(y1 < MX)
		{
			int z1 = z;
			while(z1 < MX)
			{
				bit[x][y1][z1] += val;
				z1 += (z1 & -z1);
			}
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x, int y, int z)
{
	int ret = 0;
	while(x > 0)
	{
		int y1 = y;
		while(y1 > 0)
		{
			int z1 = z;
			while(z1 > 0)
			{
				ret += bit[x][y1][z1];
				z1 -= (z1 & -z1);
			}
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
		cin.tie(0);

		int n;
		cin >> n;

		int op;

		while(cin >> op && op != 3)
		{
			if (op == 1)
			{
				int x, y, z, k;
				cin >> x >> y >> z >> k;
				update(x+1, y+1, z+1, k);
			}
			else
			{
				int x, y, z, xx, yy, zz;
				cin >> x >> y >> z >> xx >> yy >> zz;

				x++, y++, z++, xx++, yy++, zz++;

				cout << query(xx, yy, zz) - query(xx, yy, z - 1) - query(xx, y-1, zz) - query(x-1, yy, zz) + query(x-1, y-1, zz)
						+ query(x-1, yy, z-1) + query(xx, y-1, z-1) - query(x-1, y-1, z-1) << endl;
			}
		}
		return 0;
}
