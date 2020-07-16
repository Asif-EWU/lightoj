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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000
#define MX              10003

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

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

struct Edge
{
    int from, to, cost;
    Edge(int f, int t, int c)
    {
        from=f;
        to=t;
        cost=c;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost < y.cost;
}

vector<Edge>arr;
int parent[MX];

void initializeSet(int n)
{
    for(int i=1; i<=n; i++)
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

void kruskal(int city, int road, int airport)
{
    int x, y, z, mn=city*airport, sum=0, d=1, cnt=0;
    bool mark[MX]={0};

    initializeSet(city);
    sort(arr.begin(), arr.end());

    for(int i=0; i<road; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            if(z<airport)
            {
                sum+=z;
                unionSet(parent[x],parent[y]);
            }

            d++;
            if(d==city)
                break;
        }
    }

    for(int i=1; i<=city; i++)
    {
        x=findParent(i);
        if(!mark[x])
        {
            mark[x]=true;
            cnt++;
        }
    }

    sum=sum+(airport*cnt);
    if(mn<=sum)
        pf("%d %d\n",mn,city);
    else
        pf("%d %d\n",sum,cnt);
}


int main()
{
    int test, city, road, airport, a, b, c;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        arr.clear();

        fs(city);fs(road);fs(airport);
        for(int i=0; i<road; i++)
        {
            fs(a);fs(b);fs(c);
            arr.pb(Edge(a,b,c));
        }
        pf("Case %d: ",t);
        kruskal(city, road, airport);
    }

    return 0;
}
