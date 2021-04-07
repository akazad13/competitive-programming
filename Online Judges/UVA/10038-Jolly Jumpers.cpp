#include<iostream>
#include<cmath>
#include<cstdio>


using namespace std;

int main()
{
    //freopen("D:\\10038.txt","r",stdin);
    int a[3000],b[3000];

    int n,i,j,temp,jolly;

    while(cin>>n)
    {
        jolly=1;
        cin>>a[0];

        for(i=1;i<n;i++)
        {
            cin>>a[i];
            b[i-1]=abs(a[i-1]-a[i]);
        }
    //    for(i=0;i<n-1;i++)
        //    cout<<b[i]<<endl;
        for(j=0;j<n-2;j++)
        {
            for(i=0;i<n-2;i++)
            {
                if(b[i]>b[i+1])
                {
                    temp=b[i];
                    b[i]=b[i+1];
                    b[i+1]=temp;
                }
            }
        }

        for(i=0;i<n-1;i++)
        {
            //cout<<b[i]<<" "<<i+1<<endl;
            if(b[i]!=i+1)
            {
                jolly=0;
                break;
            }
        }
        if(jolly)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }

    return 0;
}
