#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("D:\\10041.txt","r",stdin);
    int t,r,a[500],i,temp,diff,j;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>r;
            diff=0;
            for(i=0;i<r;i++)
            {
                cin>>a[i];
            }

            for(i=0;i<r-1;i++)
            {
                for(j=0;j<r-1;j++)
                {
                    if(a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            for(i=0;i<r;i++)
            {
                diff+=abs(a[r/2]-a[i]);
            }

            cout<<diff<<endl;
        }
    }
    return 0;
}

