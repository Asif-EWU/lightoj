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
#define M               50000
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

int dist[M+10];
bool visited[M+10];
vector<int> vec1, vec2, arr1[M+10], arr2[M+10];

void dfs1(int a)
{
    visited[a] = 1;
    for(auto i : arr1[a]) if(!visited[i]) dfs1(i);
    vec1.push_back(a);
}

void dfs2(int a)
{
    visited[a] = 1;
    for(auto i : arr2[a]) if(!visited[i]) dfs2(i);
    vec2.push_back(a);
}

int dfs3(int a)
{
    if(dist[a] != -1) return dist[a];
    return dist[a] = 1 + dfs3(arr1[a][0]);
}

int main()
{
    int test, n, a, b, mx, res;

    scanf("%d", &test);
    for(int t=1; t<=test; t++)
    {
        vec1.clear();
        mx = 0;

        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            arr1[i].clear();
            arr2[i].clear();
            visited[i] = 0;
            dist[i] = -1;
        }

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d", &a, &b);
            arr1[a].push_back(b);
            arr2[b].push_back(a);
        }
        for(int i=1; i<=n; i++) if(!visited[i]) dfs1(i);
        reverse(vec1.begin(), vec1.end());
        memset(visited, 0, sizeof(visited));
        for(auto i : vec1)
        {
            if(!visited[i])
            {
                vec2.clear();
                dfs2(i);
                a = vec2.size();
                if(a > 1) for(auto j : vec2) dist[j] = a;
            }
        }

        for(int i=1; i<=n; i++)
        {
            a = dfs3(i);
            if(a > mx) mx = a, b = i;
        }

        printf("Case %d: %d\n", t, b);
    }

    return 0;
}
