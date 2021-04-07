#include<iostream>
#include<bits/stdc++.h>

#define lld long long int

using namespace std;
lld Humble[10000];

 void Humble_Genarator()
 {
     Humble[1]=1;

     int p2=1;
     int p3=1;
     int p5=1;
     int p7=1;

     for(int i=2;i<5850;i++)
     {
         lld a=2*Humble[p2];
         lld b=3*Humble[p3];
         lld c=5*Humble[p5];
         lld d=7*Humble[p7];


         if(a<b&&a<c&&a<d)
         {
             p2++;
             Humble[i]=a;
         }

         else if(b<a&&b<c&&b<d)
         {
             p3++;
             Humble[i]=b;
         }

         else if(c<a&&c<b&&c<d)
         {
             p5++;
             Humble[i]=c;
         }

         else if(d<a&&d<b&&d<c)
         {
             p7++;
             Humble[i]=d;
         }

         else if(a==b)
         {
             i--;
             p3++;
         }
         else if(a==c)
         {
             i--;
             p5++;
         }
         else if(a==d)
         {
             i--;
             p7++;
         }
         else if(b==c)
         {
             i--;
             p5++;
         }
         else if(b==d)
         {
             i--;
             p7++;
         }
         else if(c==d)
         {
             i--;
             p7++;
         }
     }
 }

int main()
{
   Humble_Genarator();

   int n;

   while(cin>>n,n)
    {
        if(n%100>=10 && n%100<=19) cout<<"The "<<n<<"th humble number is "<<Humble[n]<<"."<<endl;

        else if(n%10==1) cout<<"The "<<n<<"st humble number is "<<Humble[n]<<"."<<endl;

        else if(n%10==2) cout<<"The "<<n<<"nd humble number is "<<Humble[n]<<"."<<endl;

        else if(n%10==3) cout<<"The "<<n<<"rd humble number is "<<Humble[n]<<"."<<endl;

        else cout<<"The "<<n<<"th humble number is "<<Humble[n]<<"."<<endl;
    }

    return 0;

}
