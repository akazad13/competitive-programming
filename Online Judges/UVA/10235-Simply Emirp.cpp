#include<stdio.h>
#include<math.h>
int find_prime( long int n)
{
    long int i;
    int p=1;
    if(n==1)
        p=0;
    else
    {
        for(i=2;i<=sqrt(n);i++)
        {
            if(n==2)
                p=1;
            else if(n%i==0)
            {
                p=0;
                break;
            }
        }
    }
    if(p)
        return 0;
    else
        return 1;
}
int main()
{
    
    long int n,num,p;
    int result1,result2;
   while(scanf("%ld",&n)==1)
    {
        num=n;
    result1= find_prime(n);
    p=0;
    if(result1==0)
    {
        while(num>0)
        {
            p=p*10+num%10;
            num/=10;
        }
        if(n==p)
            printf("%ld is prime.\n",n);
        else{result2= find_prime(p);
        if(result1==0&&result2==0)
            printf("%ld is emirp.\n",n);
        else
            printf("%ld is prime.\n",n);}
    }
    else
        printf("%ld is not prime.\n",n);
        }
        return 0;
}

