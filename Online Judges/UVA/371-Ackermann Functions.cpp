#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int low, up,num,n,max,i,count;

    while(cin>>low>>up)
    {
        max=0;

        if(low==0&&up==0)
            break;
        if(low>up)
            swap(low,up);
        for(i=low;i<=up;i++)
        {
            count=0;
            n=i;
            do
            {
                if(n%2==1)
                {
                    n=3*n+1;
                    count++;
                }
                else
                {
                    n=n/2;
                    count++;
                }
            }while(n!=1);

            if(count>max){
                    num=i;
                max=count;
            }
        }
        cout<<"Between "<<low<<" and "<<up<<", "<<num<<" generates the longest sequence of "<<max<<" values."<<endl;

    }
    return 0;
}
