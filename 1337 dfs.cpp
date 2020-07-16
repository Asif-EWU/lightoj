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
#define M               1000000000000000000
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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char arr[505][505];
int ans[505][505];
bool mark[505][505];
int n, m;

int dfs(int a, int b)
{
    mark[a][b]=true;
    int cnt=0;

    for(int i=0; i<4; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];
        if(x>0 && y>0 && x<=n && y<=m && !mark[x][y] && arr[x][y]!='#')
        {
            if(arr[x][y]=='C') cnt+=1+dfs(x,y);
            else cnt+=dfs(x,y);
        }
    }

    return cnt;
}

void dfs2(int a, int b, int res)
{
    mark[a][b]=true;
    ans[a][b]=res;

    for(int i=0; i<4; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];
        if(x>0 && y>0 && x<=n && y<=m && !mark[x][y] && arr[x][y]!='#')
        {
            dfs2(x,y,res);
        }
    }
}


int main()
{
    int test, q, a, b, res;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        memset(ans,-1,sizeof(ans));
        scanf("%d %d %d\n",&n,&m,&q);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf(" %c",&arr[i][j]);
            }
        }

        printf("Case %d:\n",t);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&a,&b);

            if(ans[a][b]==-1)
            {
                memset(mark,0,sizeof(mark));
                res=dfs(a,b);
                memset(mark,0,sizeof(mark));
                dfs2(a,b,res);
            }

            printf("%d\n",ans[a][b]);
        }
    }

    return 0;
}
