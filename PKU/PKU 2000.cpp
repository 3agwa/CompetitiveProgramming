/*
    pre-process the data and output the sum at required index
*/
//#include <bits/stdc++.h>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

ll arr[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int idx = 1;
    for(int i = 1; i<=5000; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if (idx > 10000) break;
            arr[idx++] = i;
        }
        if (idx > 10000) break;
    }
    for(int i = 1; i<=10000; i++) arr[i] += arr[i-1];
    int n;
    while(cin >> n && n)
    {
        cout << n << " " << arr[n] << endl;
    }
    return 0;
}
