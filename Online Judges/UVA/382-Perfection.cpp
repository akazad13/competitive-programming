#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void perfection(int num)
{
    if(num==1)
    {
        printf("%5d  DEFICIENT\n",num);
        return ;
    }

    int sum=1;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            if(i!=sqrt(num))
                sum+=i+(num/i);
            else
                sum+=i;
        }
    }

    if(sum==num)
    {
        printf("%5d  PERFECT\n",num);
        return ;
    }
    else if(sum>num)
    {
        printf("%5d  ABUNDANT\n",num);
        return ;
    }
    else
    {
        printf("%5d  DEFICIENT\n",num);
        return ;
    }
}


int main()
{
    int num;
    printf("PERFECTION OUTPUT\n");
    while(cin>>num,num)
    {
        perfection(num);

    }
    printf("END OF OUTPUT\n");

    return 0;
}
