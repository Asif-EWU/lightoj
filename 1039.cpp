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
    #define M               10000000000
    #define MX              1000007

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

    struct st
    {
        char u, v, w;
        st(char _u, char _v, char _w)
        {
            u=_u;
            v=_v;
            w=_w;
        }
    };

    bool arr[125][125][125];
    bool visited[125][125][125];
    int level[125][125][125];

    int bfs(char a, char b, char c, char x, char y, char z)
    {
        int fx[]={1,-1,0,0,0,0};
        int fy[]={0,0,1,-1,0,0};
        int fz[]={0,0,0,0,1,-1};
        char p, q, r, tx, ty, tz;
        queue<st>Q;

        level[a][b][c]=0;
        visited[a][b][c]=true;
        Q.push(st(a,b,c));

        while(!Q.empty())
        {
            st s=Q.front();
            Q.pop();
            p=s.u;
            q=s.v;
            r=s.w;

            for(int i=0; i<6; i++)
            {
                tx=p+fx[i];
                ty=q+fy[i];
                tz=r+fz[i];
                if(tx=='z'+1) tx='a';
                if(ty=='z'+1) ty='a';
                if(tz=='z'+1) tz='a';
                if(tx=='a'-1) tx='z';
                if(ty=='a'-1) ty='z';
                if(tz=='a'-1) tz='z';

                if(!visited[tx][ty][tz] && !arr[tx][ty][tz])
                {
                    visited[tx][ty][tz]=true;
                    level[tx][ty][tz]=level[p][q][r]+1;
                    Q.push(st(tx,ty,tz));

                    if(tx==x && ty==y && tz==z)
                        return level[x][y][z];
                }
            }
        }

        return -1;
    }


    int main()
    {
        int test, n, res;
        char a, b, c, x, y, z, u, v, w;
        string s1, s2, s3;

        scanf("%d\n",&test);
        for(int t=1; t<=test; t++)
        {
            memset(arr,0,sizeof(arr));
            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));

            scanf(" %c%c%c",&a,&b,&c);  //pf("%c%c%c\n",a,b,c);
            scanf(" %c%c%c",&x,&y,&z);  //pf("%c%c%c\n\n",x,y,z);

            scanf("%d\n",&n);
            for(int i=0; i<n; i++)
            {
                cin >> s1 >> s2 >> s3;

                for(int j=0; s1[j]; j++)
                {
                    for(int k=0; s2[k]; k++)
                    {
                        for(int l=0; s3[l]; l++)
                        {
                            u=s1[j];
                            v=s2[k];
                            w=s3[l];
                            arr[u][v][w]=true;
                        }
                    }
                }
            }

            if(arr[a][b][c] || arr[x][y][z])
                res=-1;
            else if(a==x && b==y && c==z)
                res=0;
            else
                res=bfs(a,b,c,x,y,z);

            printf("Case %d: %d\n",t,res);
        }

        return 0;
    }
