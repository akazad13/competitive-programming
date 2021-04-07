#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int age[2000002];

int main()
{
     long int n,i;

     while(scanf("%ld",&n))
     {
         if(n==0)
            break;
         for(i=0;i<n;i++)
            scanf("%d",&age[i]);
         sort(age,age+n);
          for(i=0;i<n-1;i++)
            printf("%d ",age[i]);
        printf("%d\n",age[n-1]);

     }
     return 0;
}
