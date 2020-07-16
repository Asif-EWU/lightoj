#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             5e18
#define sf              scanf
#define pf              printf
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define nl              printf("\n")
#define PS              system("pause")
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

char arr[21][21];

int bfs(int a, int b, int row, int col)
{
    int fx[]={1,-1,0,0};
    int fy[]={0,0,1,-1};
    queue<pair<int,int> >q;
    bool visited[21][21]={0};
    int level[21][21];
    int tx, ty, m, n;

    visited[a][b]=true;
    level[a][b]=0;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        m=p.F;
        n=p.S;

        for(int i=0; i<4; i++)
        {
            tx=m+fx[i];
            ty=n+fy[i];

            if(!visited[tx][ty] && arr[tx][ty]!='#' && arr[tx][ty]!='m' && tx>=0 && tx<row && ty>=0 && ty<col)
            {
                visited[tx][ty]=true;
                level[tx][ty]=level[m][n]+1;
                q.push(make_pair(tx,ty));

                if(arr[tx][ty]=='h')
                    return level[tx][ty];
            }
        }
    }
}

int main()
{
    int kase, row, col, ans1, ans2, ans3;
    int x1, y1, x2, y2, x3, y3;
    char ch;

    fs(kase);
    fl(kase)
    {
        memset(arr,0,sizeof(arr[0][0])*21*21);

        fs(row);fs(col);
        for(int j=0; j<row; j++)
        {
            for(int k=0; k<col; k++)
            {
                scanf(" %c",&ch);

                if(ch=='a')
                    x1=j,y1=k;
                if(ch=='b')
                    x2=j,y2=k;
                if(ch=='c')
                    x3=j,y3=k;

                arr[j][k]=ch;
            }
        }

        ans1=bfs(x1,y1,row,col);
        ans2=bfs(x2,y2,row,col);
        ans3=bfs(x3,y3,row,col);

        pf("Case %d: %d\n",i+1,max(ans1,max(ans2,ans3)));
    }

    return 0;
}
