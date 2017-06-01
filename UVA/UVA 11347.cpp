/*
    
    using prime factorization
    we're able to determine the divisors of each number in the factorial series
    multiply them all together to get the accepted solution
    
*/
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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

set<int> st;
mapii mp;


ull hoba(ull n, int s)
{
    int stop = n%s;
    ull cnt = 2;
    ull val = 1;
    if (stop)
    {
        for(int i = (int)n; i>=stop; i-=s)
        {
            val *= i, cnt = 2;
            while(val != 1)
            {
                while(val%cnt == 0)
                {
                    st.insert(cnt);
                    mp[cnt]++;
                    val/=cnt;
                }
                cnt++;
            }
        }
    }
    else
    {
        for(int i = (int)n; i>=1; i-=s)
        {
            val *= i, cnt = 2;
            while(val != 1)
            {
                while(val%cnt == 0)
                {
                    st.insert(cnt);
                    mp[cnt]++;
                    val/=cnt;
                }
                cnt++;
            }
        }
    }

    ull res = 1;
    while(!st.empty())
    {
        ull hoba = *st.begin();
        st.erase(st.begin());
        res *= (mp[hoba]+1);
        if (res > powl(10, 18))
        {
            return -1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        st.clear();
        mp.clear();
        ull n;
        cin >> n;
        string x;
        cin >> x;
        ull ret = hoba(n, sz(x));
        cout << "Case " << t << ": ";
        if (ret == -1) cout << "Infinity\n";
        else cout << ret << endl;
    }

    return 0;
}
