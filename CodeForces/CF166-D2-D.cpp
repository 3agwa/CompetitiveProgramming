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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

ll n, m, memo[100001][2][2];
vector< pair< pii, int > > vec;
vi cnt;
vi price;
mapii compress;
mapii rev;

mapii mp;

// vec.first = size, vec.second = money

ll solve(int idx, int rem1, int rem2)
{
    if (idx == m) return 0;
    if (memo[idx][rem1][rem2] != -1) return memo[idx][rem1][rem2];

    ll ret = 0;
    int sizee = vec[idx].first.first, money = vec[idx].first.second;
    int c1 = cnt[sizee], c2 = cnt[sizee+1];
    int cost1 = price[sizee], cost2 = price[sizee+1];

    ret = max(ret, solve(idx+1, c1, c2));

    if (money >= cost1 && c1)
    {
        cnt[sizee]--;
        ret = max(ret, cost1 + solve(idx+1, c1-1, c2));
        cnt[sizee]++;
    }

    if (money >= cost2 && c2)
    {
        cnt[sizee+1]--;
        ret = max(ret, cost2 + solve(idx+1, c1, c2-1));
        cnt[sizee+1]++;
    }

    return memo[idx][rem1][rem2] = ret;
}

set< pii > lololey;

vii sol;

void trace(int idx, int rem1, int rem2)
{
    if(idx == m) return;
    ll ans = solve(idx,rem1,rem2);
    ll sizee = vec[idx].first.first, money = vec[idx].first.second;
    ll c1 = cnt[sizee], c2 = cnt[sizee+1];
    ll cost1 = price[sizee], cost2 = price[sizee+1];
    if(ans == solve(idx+1,c1,c2))
    {
        // ana d5lt hna fl answer el optimal bt3ti
        trace(idx+1,c1,c2);
        return;
    }
    if(money >= cost1 && c1)
    {
        cnt[sizee]--;
        if(ans == cost1+solve(idx+1,c1-1,c2))
        {
            // ana d5lt hna fl answer el optimal bt3ti
            //cout << vec[idx].first << " " << mp[vec[idx].first] << endl;
            sol.push_back({vec[idx].second, mp[sizee]});
            trace(idx+1,c1-1,c2);
            cnt[sizee]++;
            return;
        }
        cnt[sizee]++;
    }
    if (money >= cost2 && c2)
    {
        cnt[sizee+1]--;
        if(ans == cost2+solve(idx+1,c1,c2-1))
        {
            // ana d5lt hna fl answer el optimal bt3ti
            sol.push_back({vec[idx].second, mp[sizee+1]});
            trace(idx+1,c1,c2-1);
            cnt[sizee+1]++;
            return;
        }
        cnt[sizee+1]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(memo, -1);
    cin >> n;

    cnt.resize(2e5 + 10), price.resize(2e5 + 10);

    int id = 1;

    vi x(n), y(n);
    set<int> st;
    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        x[i] = a, y[i] = b;
        st.insert(b);

    }

    cin >> m;

    vi xx(m), yy(m);

    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        xx[i] = a, yy[i] = b;
        st.insert(b);
    }
    int prev = -1;
    while(!st.empty())
    {
        int hoba = *st.begin();
        st.erase(st.begin());
        if (hoba - prev == 1) compress[hoba] = id++;
        else
        {
            id++;
            compress[hoba] = id++;
        }
        prev = hoba;
    }

    rep(i, 0, n)
    {
        cnt[compress[y[i]]]++;
        price[compress[y[i]]] = x[i];
        mp[compress[y[i]]] = i+1; // link size to index
    }

    rep(i, 0, m)
    {
        //before_sort[compress[yy[i]], xx[i]] = i+1;
        vec.push_back(mp(compress[yy[i]], xx[i], i+1));
    }

    sort(vec.rbegin(), vec.rend());

    cout << solve(0, cnt[vec[0].first.first], cnt[vec[0].first.first+1]) << endl;

    trace(0, cnt[vec[0].first.first], cnt[vec[0].first.first+1]);

    cout << sz(sol) << endl;
    rep(i, 0, sz(sol)) cout << sol[i].first << " " << sol[i].second << endl;
    return 0;
    while(!lololey.empty())
    {
        pii hoba = *lololey.begin();
        lololey.erase(lololey.begin());
        cout << hoba.first << " " << hoba.second << endl;
    }


    return 0;
}
