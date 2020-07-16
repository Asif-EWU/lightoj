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

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
char arr[12][12];
int n, a, b;

int bfs(char c)
{
    queue<pair<int,int> >q;
    bool mark[12][12]={0};
    int level[12][12];

    level[a][b]=0;
    mark[a][b]=true;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        int x=p.first;
        int y=p.second;

        for(int i=0; i<4; i++)
        {
            int tx=x+fx[i];
            int ty=y+fy[i];

            if(tx>=0 && ty>=0 && tx<n && ty<n && !mark[tx][ty] && (arr[tx][ty]=='.' || arr[tx][ty]==c))
            {
                if(arr[tx][ty]=='.')
                {
                    mark[tx][ty]=true;
                    level[tx][ty]=level[x][y]+1;
                    q.push(make_pair(tx,ty));
                }
                else
                {
                    arr[a][b]='.';
                    a=tx, b=ty;
                    return level[x][y]+1;
                }
            }
        }
    }

    return -1;
}


int main()
{
    int test, res, sum, cnt;
    cin >> test;

    for(int t=1; t<=test; t++)
    {
        cnt=0;

        cin >> n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]!='#' && arr[i][j]!='.')
                    cnt++;
                if(arr[i][j]=='A')
                {
                    a=i;
                    b=j;
                }
            }
        }

        sum=0;
        while(cnt>1)
        {
            res=bfs(arr[a][b]+1);
            if(res==-1) break;
            sum+=res;
            cnt--;
        }

        printf("Case %d: ",t);
        if(cnt==1)
            printf("%d\n",sum);
        else
            printf("Impossible\n");
    }

    return 0;
}
