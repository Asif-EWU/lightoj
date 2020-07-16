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
#define M               20005
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

map<string, int> mp;
int color[M], chk;
vector<int> v[M];

void dfs(int a)
{
    color[a]++;
    for(int i=0; i<v[a].size(); i++)
    {
        int b = v[a][i];
        if(color[b] == 0) dfs(b);
        else if(color[b] == 1)
        {
            chk = 0;
            return;
        }
    }
    color[a]++;
}

int main()
{
    int test, m, mark;
    string s1, s2;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        mp.clear();
        memset(color, 0, sizeof(color));
        mark = 0;
        for(int i=1; i<M; i++) v[i].clear();

        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            if(mp[s1] == 0) mp[s1] = ++mark;
            if(mp[s2] == 0) mp[s2] = ++mark;
            v[mp[s1]].push_back(mp[s2]);
        }

        chk = 1;
        for(int i=1; i<=mark; i++)
        {
            if(color[i] == 0)
            {
                dfs(i);
                if(chk == 0) break;
            }
        }

        if(chk) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);
    }

    return 0;
}

/*
1
2
soda wine
water wine
*/
