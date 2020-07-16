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
#define M               1000
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

vector<int> G[M+5], R[M+5], vec;
bool present[M+5], visited[M+5];
int in[M+5], out[M+10], color[M+5];

void dfs1(int a)
{
    visited[a] = 1;
    for(auto i : G[a]) if(!visited[i]) dfs1(i);
    vec.push_back(a);
}

void dfs2(int a, int b)
{
    color[a] = b;
    for(auto i : R[a]) if(!color[i]) dfs2(i, b);
}

int main()
{
    int test, n, m, a, b, d;
    bool chk;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        d = 0, chk = 1;
        vec.clear();
        for(int i=0; i<M; i++) G[i].clear(), R[i].clear();
        memset(present, 0, sizeof(present));
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));

        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d %d", &a, &b);
                G[a].push_back(b);
                R[b].push_back(a);
                present[a] = present[b] = 1;
            }
        }

        dfs1(0);
        for(int i=0; i<M; i++)
        {
            if(present[i] && !visited[i])
            {
                chk = false;
                break;
            }
        }
        if(!chk)
        {
            printf("Case %d: NO\n", t);
            continue;
        }

        reverse(vec.begin(), vec.end());
        for(auto i : vec) if(!color[i]) dfs2(i, ++d);

        for(int i=0; i<M; i++)
        {
            for(auto j : G[i])
            {
                a = color[i];
                b = color[j];
                if(a != b) out[a]++, in[b]++;
            }
        }

        if(in[1]) chk = false;
        for(int i=1; i<=d; i++) if(in[i] > 1 || out[i] > 1) chk = false;

        if(chk) printf("Case %d: YES\n", t);
        else printf("Case %d: NO\n", t);
    }

    return 0;
}


