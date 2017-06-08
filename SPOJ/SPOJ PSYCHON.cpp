#include <bits/stdc++.h>

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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

bool visited[10000001];
//int hoba[10000001][2];

int main()
{
    for(int i = 2; i*i <= 10000000; i++)
    {
        if (!visited[i])
        {
            for(int j = 2*i; j<=10000000; j+=i)
            {
                visited[j] = true;
            }
        }
    }
    vi primes;
    erep(i, 2, 10000000) if (!visited[i]) primes.push_back(i);
    /*rep(i, 0, sz(primes))
    {
        int pr = primes[i];
        if (2*pr > 10000000) break;
        for(int j = 2*pr; j<=10000000; j+=pr)
        {
            int temp = j, cnt = 0;
            while(temp%pr == 0) temp/=pr, cnt++;
            if (cnt&1) hoba[j][1]++;
            else hoba[j][0]++;
        }
    }*/


    int tc;
    int n;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        int l = 0, r = 0;
        int t = n;
        rep(i, 0, sz(primes))
        {
            int pr = primes[i];
            if (pr*pr > t) break;
            if (n == 1) break;
            if (n%pr == 0)
            {
                int cnt = 0;
                while(n%pr == 0) n/=pr, cnt++;
                if (cnt&1) r++;
                else l++;
            }
        }
        if (n != 1) r++;
        if (l > r) printf("Psycho Number\n");
        else printf("Ordinary Number\n");
    }

    return 0;
}
