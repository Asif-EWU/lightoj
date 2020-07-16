#include<bits/stdc++.h>
#define fl(n) for(int i=0; i<n; i++)
#define loop(i, a, n) for(int i=a; i<n; i++)
#define pb push_back
#define pp pop_back
#define ll long long int
#define ld long double
#define inf 5e18
#define sf scanf
#define Sf(a) scanf("%d",&a)
#define pf printf
#define Pf(a) printf("Case %d: ",a)
#define mod 1000000007

using namespace std;

int main()
{
    int t, ans, n, m;

    Sf(t);

    fl(t)
    {
        sf("%d%d",&m,&n);

        if(m==1 || n==1)
            ans=m*n;
        else if(m==2 || n==2)
        {
            if(max(m,n)%4==0)
                ans=max(m,n);
            else if((m*n/2)%2==0)
                ans=m*n/2+2;
            else
                ans=m*n/2+1;
        }
        else if(m*n%2==0)
            ans=m*n/2;
        else
            ans=(m*n+1)/2;

        pf("Case %d: %d\n",i+1, ans);
    }

    return 0;
}
