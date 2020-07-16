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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char arr[202][202];
vector<int>v1, v2, v3;
int n, m;

void bfs1(int a, int b)
{
    queue<pair<int,int> >q;
    bool mark[202][202]={0};
    int level[202][202];

    mark[a][b]=1;
    level[a][b]=1;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        int c=p.first;
        int d=p.second;

        for(int i=0; i<4; i++)
        {
            int x=c+fx[i];
            int y=d+fy[i];

            if(x>=0 && y>=0 && x<n && y<m && !mark[x][y] && arr[x][y]=='.')
            {
                mark[x][y]=1;
                level[x][y]=level[c][d]+1;
                q.push(make_pair(x,y));

                if(x==0 || y==0 || x==n-1 || y==m-1)
                {
                    v1.push_back(x);
                    v2.push_back(y);
                    v3.push_back(level[x][y]);
                }
            }
        }
    }
}

bool bfs2(int a, int b, int c)
{
    queue<pair<int,int> >q;
    bool mark[202][202]={0};
    int level[202][202];

    mark[a][b]=1;
    level[a][b]=1;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        int u=p.first;
        int v=p.second;

        for(int i=0; i<4; i++)
        {
            int x=u+fx[i];
            int y=v+fy[i];

            if(x>=0 && y>=0 && x<n && y<m && !mark[x][y] && arr[x][y]!='#')
            {
                mark[x][y]=1;
                level[x][y]=level[u][v]+1;
                q.push(make_pair(x,y));

                if(level[x][y]>c) return true;
                if(arr[x][y]=='F') return false;
            }
        }
    }
    return true;
}


int main()
{
    int test, a, b;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        v1.clear();
        v2.clear();
        v3.clear();

        scanf("%d %d\n",&n,&m);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf(" %c",&arr[i][j]);
                if(arr[i][j]=='J')
                {
                    a=i;
                    b=j;
                }
            }
        }

        if(a==0 || b==0 || a==n-1 || b==n-1)
        {
            printf("Case %d: 1\n",t);
            continue;
        }

        bfs1(a,b);

        int flag=0;
        for(int i=0; i<v1.size(); i++)
        {
            if(bfs2(v1[i],v2[i],v3[i]))
            {
                printf("Case %d: %d\n",t,v3[i]);
                flag=1;
                break;
            }
        }

        if(flag==0) printf("Case %d: IMPOSSIBLE\n",t);
    }

    return 0;
}
