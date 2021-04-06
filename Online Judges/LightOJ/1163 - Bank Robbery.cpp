#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)

int main()
{
   int test;
   READ(test);
   unsigned long long int x;
   for(int i=1;i<=test;i++)
   {
       scanf("%llu",&x);
       //cout<<x<<endl;

       if(x%9==0)
        printf("Case %d: %llu %llu\n",i,x+x/9-1,x+x/9);
       else
        printf("Case %d: %llu\n",i,x+x/9);

   }
    return 0;
}



