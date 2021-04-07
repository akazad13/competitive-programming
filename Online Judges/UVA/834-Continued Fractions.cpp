#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b,c;

    while(cin>>a>>b)
   {
       int arr[10000];
       int i=0,j;

       while(b!=0)
        {
            arr[i++]=a/b;
            c=a;
            a=b;
           // b=c-(arr[i-1]*b);

           b=c%b;

          //  cout<<arr[i-1]<<endl;

            //cout<<b<<" "<<a<<endl;

        }

       // cout<<34<<endl;



        if(i==1)
        {
            cout<<"["<<arr[i-1]<<"]"<<endl;
            continue;
        }

        //cout<<i<<endl;

        for(j=0;j<i;j++)
        {
            if(j==0)
                cout<<"["<<arr[j];
            else if(j==1)
                cout<<";"<<arr[j];
            else
                cout<<","<<arr[j];

        }
        cout<<"]\n";

   }
   return 0;
}
