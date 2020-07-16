#include<bits/stdc++.h>
#define M 10000005

using namespace std;

bool arr[M+10];
vector<int> brr;

void sieve()
{
    long long int i, j, ck=sqrt(M)+1;

    brr.push_back(2);
    for(i=3; i<=M; i+=2)
    {
        if(!arr[i])
        {
            for(j=i; i*j<=M; j+=2)
            {
                arr[i*j]=true;
            }

            brr.push_back(i);
        }
    }
}


int main()
{
    sieve();

    long long int t, n, sum, i, j, left, right;

    scanf("%lld",&t);

    for(i=1; i<=t; i++)
    {
        sum=0, left=3;

        scanf("%lld",&n);

        if(n==4)
            sum=1;
        else
        {
            for(j=1; ; j++)
            {
                left=brr[j];
                right=n-left;

                if(left>right)
                    break;

                if(!arr[right] && left+right==n)
                    sum++;
            }
        }

        printf("Case %lld: %lld\n", i, sum);
    }

    return 0;
}
