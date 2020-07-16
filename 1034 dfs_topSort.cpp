#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define sync            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause");
#define MOD             998244353
#define M               10000
#define MX              50005

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>  using ordered_set =
    tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>  using orderedSet =
    tree<pair<int,int>, null_type, less<pair<int,int> >,
    rb_tree_tag, tree_order_statistics_node_update>;
// *s.find_by_order(); s.order_of_key();

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

vector<int>v[M+10];
bool color[M+10];
stack<int> st;

void dfs(int a)
{
    color[a] = 1;
    for(int i=0; i<v[a].size(); i++) if(color[v[a][i]] == 0) dfs(v[a][i]);
    st.push(a);
}

int main()
{
    int test, n, m, a, b, cnt;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        cin >> n >> m;

        for(int i=1; i<=n; i++) v[i].clear();
        memset(color, 0, sizeof(color));

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
        }

        for(int i=1; i<=n; i++) if(color[i] == 0) dfs(i);

        memset(color, 0, sizeof(color));
        cnt = 0;
        while(!st.empty())
        {
            a = st.top();
            st.pop();
            if(color[a] == 0) cnt++, dfs(a);
        }

        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
