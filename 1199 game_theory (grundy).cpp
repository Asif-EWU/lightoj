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
#define MOD             100000007
#define M               200010
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

int dp[10010];

int mex(unordered_set<int>s)
{
    int ans=0;
    while(s.find(ans) != s.end()) ans++;
    return ans;
}

int fun(int a)
{
    if(a<3) return 0;
    if(dp[a] != -1) return dp[a];

    unordered_set<int>s;

    for(int i=1; i<=a/2; i++)
    {
        if(i == a-i) continue;
        s.insert(fun(i)^fun(a-i));
    }

    return dp[a] = mex(s);
}

int main()
{
    int test, n, a, ans;
    mem(dp,-1);

    fs(test);
    for(int t=1; t<=test; t++)
    {
        ans=0;

        fs(n);
        fl(n)
        {
            fs(a);
            ans^=fun(a);
        }

        if(ans) pf("Case %d: Alice\n",t);
        else pf("Case %d: Bob\n",t);
    }

    return 0;
}
