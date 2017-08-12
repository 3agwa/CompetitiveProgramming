#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

double memo[8][(1<<7) + 1];
double p[(1<<7) + 1][(1<<7) + 1];
int n;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> n && n != -1)
    {
        //cout << (0^1) << " " << (1^1) << endl;
        int m = (1<<n);
        for(int i = 0; i<m; i++) for(int j = 0; j<m; j++) cin >> p[i][j];
        memset(memo, 0, sizeof memo);
        for(int i = 0; i<m; i++) memo[0][i] = 1; // base case
        for(int i = 1; i<=n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                for(int k = 0; k<m; k++)
                {
                    if((j>>(i-1)^1)==(k>>(i-1))) // two bits are not the same
                    {
                        memo[i][j] += memo[i-1][j]*memo[i-1][k]*p[j][k];
                    }
                }
            }
        }
        double mx = -1;
        int idx;
        for(int i = 0; i<m; i++)
        {
            if (memo[n][i] > mx)
            {
                mx = memo[n][i];
                idx = i+1;
            }
        }
        cout << idx << endl;
    }
    return 0;
}
