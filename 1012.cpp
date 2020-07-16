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

int bfs(int x, int y, int col, int row)
{
    int fx[]={1,-1,0,0};
    int fy[]={0,0,1,-1};
    int tx, ty, a, b, cnt;
    bool visited[21][21]={0};
    queue<pair<int,int> >q;

    cnt=1;
    visited[x][y]=true;
    q.push(make_pair(x,y));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        a=p.F;
        b=p.S;

        for(int i=0; i<4; i++)
        {
            tx=a+fx[i];
            ty=b+fy[i];

            if(!visited[tx][ty] && arr[tx][ty]=='.' && tx>=0 && ty>=0 && tx<col && ty<row)
            {
                cnt++;
                visited[tx][ty]=true;
                q.push(make_pair(tx,ty));
            }
        }
    }

    return cnt;
}

int main()
{
    int kase, row, col, x, y, ans;
    char ch;

    fs(kase);
    fl(kase)
    {
        fl(21)
            memset(arr,0,sizeof(arr[0][0])*21*21);

        fs(row);fs(col);
        for(int j=0; j<col; j++)
        {
            for(int k=0; k<row; k++)
            {
                scanf(" %c",&ch);
                if(ch=='@')
                {
                    x=j;
                    y=k;
                }
                arr[j][k]=ch;
            }
        }

        ans=bfs(x,y,col,row);
        pf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}
