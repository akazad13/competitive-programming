#include<iostream>
#include<stdio.h>
#include<cstdio>

using namespace std;

unsigned long long int reverse(unsigned long long int a)
{
    unsigned long long int revNum=0;
    int i=0;
    while(a!=0)
    {
        revNum=revNum*10+a%10;
        a/=10;
        i++;
    }
    return revNum;
}
int main()
{
    int t,count;

    unsigned long long int p,q,sum;

    while(cin >> t)
    {
        while(t--)
        {
            cin >> p;

            sum=p+reverse(p);
            count=1;
            while(sum!=(q=reverse(sum)))
            {
                count++;
                sum+=q;
            }
            cout << count <<" "<<sum<< endl;

        }
    }
    return 0;
}
