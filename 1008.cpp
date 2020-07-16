#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int kase, n, cl, center, x, y, i;

    scanf("%lld",&kase);
    for(i=0; i<kase; i++)
    {
        scanf("%lld",&n);
        cl = ceil(sqrt(n));
        center = (cl*cl)-(cl-1);

        if(n==center)
            x=cl,y=cl;

        else if(cl%2!=0)
        {
            if(n>center)
            {
                y=cl;
                x=cl-(n-center);
            }
            else
            {
                x=cl;
                y=cl-(center-n);
            }
        }

        else
        {
            if(n>center)
            {
                x=cl;
                y=cl-(n-center);
            }
            else
            {
                y=cl;
                x=cl-(center-n);
            }
        }

        printf("Case %lld: %lld %lld\n",i+1,x,y);
    }

    return 0;
}

