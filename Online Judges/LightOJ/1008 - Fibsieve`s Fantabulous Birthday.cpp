#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
   long long int Mid_point, Mid_value, time, x,y;
   int test;
   cin>>test;

   for(int i=1;i<=test;i++)
   {
       cin>>time;
       Mid_point=ceil(sqrt(time));
       Mid_value=((Mid_point)*(Mid_point))-Mid_point+1;

       if(time>Mid_value)
       {
           x=Mid_point-(time-Mid_value);
           y=Mid_point;
       }
       else
       {
           y=Mid_point-(Mid_value-time);
           x=Mid_point;
       }
       if(Mid_point%2==1)
            cout<<"Case "<<i<<": "<<x<<" "<<y<<endl;
       else
            cout<<"Case "<<i<<": "<<y<<" "<<x<<endl;
   }

   return 0;
}
