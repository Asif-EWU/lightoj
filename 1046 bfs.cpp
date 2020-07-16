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

int fx[]={1,1,2,2,-1,-1,-2,-2};
int fy[]={2,-2,1,-1,2,-2,1,-1};
char arr[12][12];
int n, m, sum, knt;

void bfs(int a, int b)
{
    queue<pair<int,int> >q;
    int level[12][12];
    bool mark[12][12]={0};
    int x, y, u, v, d, e;

    level[a][b]=0;
    mark[a][b]=true;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        x=p.first;
        y=p.second;

        for(int i=0; i<8; i++)
        {
            u=x+fx[i];
            v=y+fy[i];

            if(u>=0 && v>=0 && u<n && v<m && !mark[u][v])
            {
                mark[u][v]=true;
                level[u][v]=level[x][y]+1;
                q.push(make_pair(u,v));

                if(arr[u][v]!='.')
                {
                    knt--;
                    d=arr[u][v]-'0';
                    e=ceil((double)level[u][v]/d);
                    sum+=e;
                }
                if(knt==0) return;
            }
        }
    }
}

int main()
{
    int test, mn, cnt;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        mn=INT_MAX;
        cnt=0;

        scanf("%d %d\n",&n, &m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf(" %c",&arr[i][j]);
                if(arr[i][j]!='.') cnt++;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum=0;

                if(arr[i][j]!='.') knt=cnt-1;
                else knt=cnt;

                bfs(i,j);
                if(knt==0) mn=min(mn,sum);
            }
        }

        if(mn==INT_MAX) printf("Case %d: -1\n",t);
        else printf("Case %d: %d\n",t,mn);
    }

    return 0;
}
