//here 1 is also a prime number
#include<stdio.h>
#include<string.h>
#include<math.h>
int prime(int a)
{
    int flag=0,i,b;
    if(a==2)
        flag=0;
    else
    {
        b= sqrt(a);
        for(i=2;i<=b;i++)
        {
            if(a%i==0)
            {
                flag=1;
                break;
            }
        }
    }

    if(flag==0)
        return 1;
    else
        return 0;

}

int main()
{
    char L[22];
    int sum,l,i,p;
    while(scanf("%s",&L)!= EOF)
    {
        sum=0;
        l=strlen(L);
        for(i=0;i<l;i++)
        {
            if(L[i]>='a' && L[i]<='z')
                sum += L[i]- 96;
            else if(L[i]>='A' && L[i]<='Z')
                sum += L[i]- 38;
        }
        p = prime(sum);
        if(p)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
