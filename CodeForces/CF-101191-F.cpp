#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    string x;
    cin >> x;
    string yay = x;
    string yalla = x;
    ll n = 0;
    if (x == "0")
    {
        cout << -1;
        return 0;
    }

    if (x.find("0") != -1)
    {
        x.erase(x.find("0"), 1);
        cout << x;
        return 0;
    }

    map<char, int> mp;
    rep(i, 0, sz(x))
    {
        mp[x[i]]++;
        n = n*10 + x[i] - '0';
    }

    n = n*10;
    if (n <= 1000000000)
    {
        cout << n;
        return 0;
    }

    erep(i, 1, 4)
    {
        for(int j = 1; (i+j) <= 9; j++)
        {
            char a = i + '0', b = j + '0', c = (i+j) + '0';
            if (mp[a])
            {
                mp[a]--;
                if (mp[b])
                {
                    x.erase(x.find(a), 1);
                    x.erase(x.find(b), 1);
                    x.push_back(c);
                    cout << x;
                    return 0;
                }
                mp[a]++;
            }
        }
    }

    sort(all(x));
    reverse(all(x));
    while(x.back() == '0') x.pop_back();
    rep(i, 0, sz(x))
    {
        if (x[i] == '1') break;
        char c = x[i];
        string y = x;
        y.erase(i, 1);
        int temp = c + '0';
        if(temp & 1)
        {
            temp/=2;
            y.push_back(temp + '0');
            temp++;
            y.push_back(temp + '0');
        }
        else
        {
            temp/=2;
            y.push_back(temp + '0');
            y.push_back(temp + '0');
        }
        sort(all(y));
        ll hoba = 0;
        rep(j, 0, sz(y)) hoba = hoba*10 + y[j] - 48;
        if (hoba <= 1000000000)
        {
            cout << hoba;
            return 0;
        }
    }
    n/=10;
    sort(all(yay));
    do
    {
        if (yay == x) continue;
        ll hoba = 0;
        rep(i, 0, sz(yay)) hoba = hoba*10 + yay[i] - 48;
        if (hoba != n)
        {
            cout << hoba;
            return 0;
        }
    }
    while(next_permutation(all(yay)));
    int sum = 0;
    rep(i, 0, sz(yalla)) sum += yalla[i] - 48;
    ll last = 0;
    while(sum)
    {
        if (sum >= 9)
        {
            sum -= 9;
            last = last * 10 + 9;
        }
        else
        {
            last = last*10 + sum;
            sum = 0;
        }
    }

    if (last != n) cout << last;
    else cout << -1;
    return 0;
}
