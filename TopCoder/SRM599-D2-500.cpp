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


class BigFatInteger2
{
public:
    string isDivisible(int A, int B, int C, int D)
    {
        set<ll> s1, s2;
        map<ll, ll> m1, m2;
        while(A%2 == 0)
        {
            s1.insert(2);
            m1[2]++;
            A/=2;
        }
        while(C%2 == 0)
        {
            s2.insert(2);
            m2[2]++;
            C/=2;
        }
        for(int i = 3; i*i <= A; i+=2)
        {
            while(A%i == 0)
            {
                A/=i;
                m1[i]++;
                s1.insert(i);
            }
        }
        if (A != 1) m1[A]++, s1.insert(A);

        for(int i = 3; i*i <= C; i+=2)
        {
            while(C%i == 0)
            {
                C/=i;
                m2[i]++;
                s2.insert(i);
            }
        }
        if (C != 1) m2[C]++, s2.insert(C);

        while(!s2.empty())
        {
            int hoba = *s2.begin();
            s2.erase(s2.begin());
            if (m2[hoba]*D > m1[hoba]*B) return "not divisible";
        }
        return "divisible";
    }
};
