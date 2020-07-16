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
#define M               505
#define MX              100000

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

vector<int>v[1002];
int cost[1002];
bool mark[1002];
int sum, q;

void dfs(int a)
{
    mark[a]=true;
    if(q==0) return;

    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];
        if(mark[b]) continue;

        if(cost[b]<sum)
        {
            int x=sum-cost[b];
            if(q<=x)
            {
                cost[b]+=q;
                q=0;
            }
            else
            {
                cost[b]+=x;
                q-=x;
            }
        }

        dfs(b);
    }
}

int main()
{
    int test, a, b, n, m;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        sum=0;

        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            v[i].clear();
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        printf("Case %d: ",t);

        if(sum%n!=0)
        {
            printf("No\n");
            continue;
        }

        sum/=n;
        for(int i=1; i<=n; i++)
        {
            if(cost[i]>sum)
            {
                memset(mark,0,sizeof(mark));
                q=cost[i]-sum;
                cost[i]=sum;
                dfs(i);
            }
        }

        int flag=1;
        for(int i=1; i<=n; i++)
        {
            if(cost[i]!=sum)
            {
                flag=0;
                break;
            }
        }

        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
