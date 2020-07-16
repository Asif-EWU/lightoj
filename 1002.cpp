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
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define BM              bool mark[M+10]
#define MOD             1000000007
#define M               1000000000

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
    int city, cost;
    Edge(int a, int b)
    {
        city=a;
        cost=b;
    }
};
bool operator<(Edge a, Edge b)
{
    return a.cost>b.cost;
}

map<int,vector<Edge> >arr;

void dijkstra(int node, int from)
{
    priority_queue<Edge>pq;
    map<int,int>dist;

    for(int i=0; i<node; i++)
        dist[i]=M;

    dist[from]=0;
    pq.push(Edge(from,0));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(top.cost!=dist[top.city])
            continue;

        for(int i=0; i<arr[top.city].size(); i++)
        {
            Edge x=arr[top.city][i];

            if(dist[top.city]<dist[x.city] && x.cost<dist[x.city])
            {
                dist[x.city]=max(dist[top.city],x.cost);
                pq.push(Edge(x.city,dist[x.city]));
            }
        }
    }

    for(int i=0; i<node; i++)
    {
        if(dist[i]==M)
            printf("Impossible\n");
        else
            printf("%d\n",dist[i]);
    }

}

int main()
{
    //fin;
    int cas, node, edge, from;
    int a, b, c, ans;

    fs(cas);
    for(int i=0; i<cas; i++)
    {
        printf("Case %d:\n",i+1);
        arr.clear();

        fs(node);fs(edge);
        for(int j=0; j<edge; j++)
        {
            fs(a);fs(b);fs(c);
            arr[a].pb(Edge(b,c));
            arr[b].pb(Edge(a,c));
        }
        fs(from);

        dijkstra(node,from);
    }

    return 0;
}
