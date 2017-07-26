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

int n, m, arr[200000], tree[600000];

void build(int node, int st, int en, bool level)
{
    if (st > en) return;
    if (st == en)
    {
        tree[node] = arr[st];
        return;
    }

    int mid = (st+en)/2;

    build(2*node, st, mid, !level);
    build(2*node + 1, mid + 1, en, !level);
    if (!level) tree[node] = tree[2*node]^tree[2*node+1];
    else tree[node] = tree[2*node] | tree[2*node+1];
}

void update(int node, int st, int en, int shemal, int yemeen, int val, bool level)
{
    if (st > en || st > yemeen || en < shemal) return;

    if (st == en)
    {
        tree[node] = val;
        return;
    }

    int mid = (st+en)/2;

    update(node*2, st, mid, shemal, yemeen, val, !level);
    update(node*2 + 1, mid + 1, en, shemal, yemeen, val, !level);

    if (!level) tree[node] = tree[2*node]^tree[2*node+1];
    else tree[node] = tree[2*node] | tree[2*node+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x = (1<<n);
    rep(i, 0, x) cin >> arr[i];
    build(1, 0, (1<<n)-1, n&1);
    while(m--)
    {
        int p, q;
        cin >> p >> q;
        p--;
        update(1, 0, (1<<n)-1, p, p, q, n&1);
        cout << tree[1] << endl;
    }
    return 0;
}
