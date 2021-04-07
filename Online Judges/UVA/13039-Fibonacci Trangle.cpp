#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("input.txt","r", stdin);
    int arr[1010];
    int n,j;
    int test;
    int res;
    cin>>test;

    for(int cnt=1; cnt<=test; cnt++)
    {
        res=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(int i=0;i<n;i++)
        {
            res+=arr[i]/3;
            arr[i]%=3;

            if(arr[i]==1)
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(arr[j]>=2)
                    {
                        res++;
                        arr[j]-=2;
                        arr[i]--;
                        break;
                    }
                }
            }



            else if(arr[i]==2)
            {
                bool flag=true;
                int j=i+1;
                while(j!=n)
                {
                    if(arr[j]>0)
                    {
                        flag=false;
                        break;
                    }
                    j++;
                }
                //cout<<j<<endl;
                if(flag==false)
                {
                    res++;
                    arr[i]-=2;
                    arr[j]--;

                }
            }

           /* for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;*/
        }
        printf("%d\n",res);
    }

    return 0;
}
