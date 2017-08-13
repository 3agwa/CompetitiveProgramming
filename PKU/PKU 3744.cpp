/*
    first thing is to compress our path, since elements can reach upto 1e8, we should compress this path
    then we iterate over the points, if it's not a mine then we could calculate its probability
    probabilities are usual pick/leave with (p, 1-p)
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

double p, memo[502];
int n, arr[12], mx;
bool mine[502];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> n >> p)
    {
        for(int i = 1; i<=n; i++) cin >> arr[i];
        sort(arr+1, arr+n+1);

        for(int i = 0; i<n; i++)
        {
            if (arr[i+1]-arr[i] > 50)
            {
                for(int j = n; j>i; j--) arr[j] -= (arr[i+1] - arr[i] - 50);
            }
        }
        mx = arr[n];
        memset(mine, false, sizeof mine);
        memset(memo, false, sizeof memo);
        for(int i = 1; i<=n; i++) mine[arr[i]] = true;
        memo[1] = true;
        for(int i = 0; i<=mx; i++)
        {
            if (!mine[i])
            {
                memo[i+1] += memo[i] * p;
                memo[min(i+2, mx+1)] += memo[i] * (1. - p);
            }
        }
        cout << fixed << setprecision(7) << memo[mx+1] << endl;
    }
    return 0;
}
