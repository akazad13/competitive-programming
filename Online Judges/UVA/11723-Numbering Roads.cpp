#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int main()
{
   double N, R,LetterNo;
   int i=1;
   cin>>N>>R;
   while(N!=0 && R!=0)
   {
       if(R==0)
       {
           cout<<"Case "<<i<<": impossible"<<endl;
       }
       else
       {
           LetterNo=N/R-1;
           if(LetterNo<26)
            cout<<"Case "<<i<<": "<<ceil(LetterNo)<<endl;
           else
            cout<<"Case "<<i<<": impossible"<<endl;
       }

       i++;
       cin>>N>>R;
   }
   return 0;
}
