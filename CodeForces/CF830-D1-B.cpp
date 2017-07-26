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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int n, tree[400004];

deque<int> arr;

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        tree[node]= val;
        return;
    }

    int mid = (st+en)/2;

    update(2*node, st, mid, shemal, yemeen, val);
    update(2*node+1, mid+1, en, shemal, yemeen, val);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node, int st, int en, int shemal, int yemeen)
{
    if (st > en || st > yemeen || en < shemal) return 0;

    if (shemal <= st && en <= yemeen) return tree[node];

    int mid = (st+en)/2;

    return query(2*node, st, mid, shemal, yemeen) + query(2*node+1, mid+1, en, shemal, yemeen);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.resize(n);
    set< pii > st;
    rep(i, 0, n)
    {
        cin >> arr[i];
        st.insert({arr[i], i});
    }
    ll cnt = 0;
    int j = 0;
    set< pii > ::iterator it;
    rep(i, 0, n)
    {
        it = st.lower_bound({ (*st.begin()).first , j});
        ll subtract = 0, add = 0;
        pii hoba = *it;
        ll idx = hoba.second, mn = hoba.first;

        //if (mn != (*st.begin()).first) cout << "@@@@@@@@@@ " << idx << " " << j << endl;
        if (it == st.end() || (mn != (*st.begin()).first))
        {
            add = add + (n - j);
            subtract += query(1, 0, n-1, j, n-1);
            cnt = cnt + max(0LL, add - subtract);
            //cout << "here2: " << add << " " << subtract << " " << j << endl;
            j = 0, i--;
            continue;
        }
        st.erase(it);

        add = (idx - j + 1);
        subtract += query(1, 0, n-1, j, idx);
        //cout << "here1: " << add << " " << subtract << endl;
        //cout << "here: " << add << " " << subtract << endl;

        cnt = cnt + max(0LL, add - subtract);
        update(1, 0, n-1, idx, idx, 1);
        j = (idx+1)%n;
    }
    cout << cnt;

    return 0;
}
