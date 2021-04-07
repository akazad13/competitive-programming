#include<iostream>

using namespace std;

int main()
{
    int n,zeroes,data,i=1;

    while(cin>>n,n)
    {
        zeroes=0;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            if(data==0)
                zeroes++;
        }

        cout<<"Case "<<i<<": "<<(n-(zeroes+zeroes))<<endl;
        i++;
    }

    return 0;
}
