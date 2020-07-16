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
#define PS              system("pause")
#define MOD             100000007
#define M               30005
#define MX              505

using namespace std;

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

struct st
{
    int to, cost;
    st(int _to, int _cost)
    {
        to=_to;
        cost=_cost;
    }
};

vector<st>v[M];
bool mark[M];
bool chk[M];
int arr[M];
int x, mx;

void dfs(int a, int sum)
{
    mark[a]=true;

    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i].to;
        int c=v[a][i].cost;

        if(mark[b]) continue;

        if(sum+c>arr[b])
        {
            arr[b]=sum+c;
            if(arr[b]>mx)
            {
                mx=arr[b];
                x=b;
            }
        }
        dfs(b,sum+c);
    }
}


int main()
{
    int test, n, a, b, c;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++) v[i].clear();
        memset(arr,0,sizeof(arr));
        memset(chk,0,sizeof(chk));

        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(st(b,c));
            v[b].push_back(st(a,c));
        }

        x=mx=0;
        while(!chk[x])
        {
            memset(mark,0,sizeof(mark));
            chk[x]=true;
            dfs(x,0);
        }

        printf("Case %d:\n",t);
        for(int i=0; i<n; i++)
        {
            printf("%d\n",arr[i]);
        }
    }

    return 0;
}
