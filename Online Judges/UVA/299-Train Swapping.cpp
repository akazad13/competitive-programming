#include<iostream>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        int count=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(a[i]>a[j])
                    {
                        swap(a[i],a[j]);
                        count++;
                    }

            }
        }

        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }

    return 0;
}
