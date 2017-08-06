#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define mapii map<int, int>
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int arr[400005], vec[400005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(arr, -1);
    int n;
    cin >> n;

    rep(i, 0, n) cin >> vec[i];
    for(int i = n-1; i>=0; i--)
    {
        for(int j = i; j>=0; j--)
        {
            int temp = vec[i]+vec[j];
            if (temp < 0) temp*=-1, temp+=2e5;
            arr[temp] = i;
        }
    }
    int cnt = 0;
    rep(i, 1, n)
    {
        for(int j = i-1; j>=0; j--)
        {
            int temp = vec[i]-vec[j];
            if (temp < 0) temp*=-1, temp+=2e5;
            if (arr[temp] != -1 && arr[temp] < i)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
