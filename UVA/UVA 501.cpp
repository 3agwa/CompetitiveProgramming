/*
    after taking the input, sort it and do path compression on its values
    then for each (add) query, increment the compressed position in the segment tree
    in the (get) query, we'll get the k-th smallest element in the tree
    we traverse the tree according to remaining K
    for each range we need to find the K-th smallest element in it
    we move to left/right child depending on their values
    when we reach our node, return its value (compressed index)
    we'll have to add a reverse map to get the original index of the compressed index
    as we return a compressed index from query, print the rev[qry()]
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
#define mp(x, y, z) {{x, y}, z}

int n, m;
vi arr;
deque<int> vec;
vi tree;

void update(int node, int st, int en, int shemal, int yemeen)
{
    if (st > en || st > yemeen || en < shemal) return;
    if (shemal <= st && en <= yemeen)
    {
        tree[node]++;
        return;
    }
    int mid = (st+en)/2;
    update(2*node, st, mid, shemal, yemeen);
    update(2*node+1, mid+1, en, shemal, yemeen);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int st, int en, int k)
{
    if (st == en) return st;
    int mid = (st+en)/2, ret = 0;
    if (k > tree[2*node]) ret = query(2*node+1, mid+1, en, k - tree[2*node]);
    else ret = query(2*node, st, mid, k);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> m >> n;
        tree = vi(4*m);
        arr = vi(m), vec = deque<int>(n);
        mapii pos;
        int c = 0;
        vi temp;
        mapii rev;
        rep(i, 0, m)
        {
            cin >> arr[i];
            temp.push_back(arr[i]);
        }
        sort(all(temp));
        rep(i, 0, m)
        {
            if (!pos[temp[i]]) rev[c] = temp[i], pos[temp[i]] = c++;
        }
        rep(i, 0, n)
        {
            cin >> vec[i];
            vec[i]--;
        }
        int idx = 1;
        rep(i, 0, m)
        {
            int temp = pos[arr[i]];
            update(1, 0, m-1, temp, temp);
            while(!vec.empty() && vec.front() == i)
            {
                cout << rev[query(1, 0, m-1, idx)] << endl;
                idx++;
                vec.pop_front();
            }
        }
        if (tc) cout << endl;
    }
    return 0;
}
