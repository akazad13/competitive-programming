#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char ab[10000];
int l;
int cheak_div(int num)
{
    int sum=0;
    for(int i=0;i<l;i++)
        {
            sum=(sum*10+(ab[i]-'0'))%num;
        }
    if(sum)
        return 1;
    else
        return 0;

}

int main()
{
    int test;
    char c;
    int a[13],n;

    cin>>test;
    c=getchar();

    while(test--)
    {
        int p=0;
        gets(ab);
        l=strlen(ab);
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        c=getchar();
        for(int i=0;i<n;i++)
        {
            int k= cheak_div(a[i]);
            if(k!=0)
            {
                p=1;
                break;
            }
        }

       if(p==1)
        cout<<ab<<" - Simple."<<endl;
       else
        cout<<ab<<" - Wonderful."<<endl;
    }
    return 0;
}

