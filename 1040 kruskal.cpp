#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define loop(i, a, n)   for(int i=a; i<n; i++)
#define pb              push_back
#define pp              pop_back
#define ll              long long int
#define ld              long double
#define inf             5e18
#define sf              scanf
#define Sf(a)           scanf("%lf",&a)
#define pf              printf
#define Pfc(a)          printf("Case %d: ",a)
#define Pfl(a)          printf("%lld",a)
#define Pfi(a)          printf("%d",a)
#define nl              printf("\n")
#define Vl              vector<ll>
#define Vi              vector<int>
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*b)/gcd(a,b)
#define PS              system("pause")
#define BM              bool mark[M+10]
#define MOD             1000000007
#define M               1000

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

struct Edge
{
    int from, to, cost;
    Edge(int a, int b, int c)
    {
        from=a;
        to=b;
        cost=c;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost < y.cost;
}

vector<Edge>arr;
int parent[60];

void initializeSet(int n)
{
    for(int i=0; i<n; i++)
        parent[i]=i;
}

int findParent(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px=findParent(x);
    int py=findParent(y);

    if(px!=py)
        parent[py]=px;
}

int kruskal(int n)
{
    initializeSet(n);
    int x, y, z, sz=arr.size(), sum=0, cnt=0;

    sort(arr.begin(),arr.end());
    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            unionSet(parent[x],parent[y]);
            sum+=z;

            cnt++;
            if(cnt+1==n)
                break;
        }
    }

    if(cnt+1!=n)
        sum=-1;
    return sum;
}

int main()
{
    int test, n, a, sum, res;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        arr.clear();
        sum=0;

        fs(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                fs(a);
                if(a>0)
                {
                    sum+=a;
                    arr.pb(Edge(i,j,a));
                }
            }
        }

        res=kruskal(n);

        if(res==-1)
            sum=-1;
        else
            sum-=kruskal(n);

        pf("Case %d: %d\n",t,sum);
    }

    return 0;
}
