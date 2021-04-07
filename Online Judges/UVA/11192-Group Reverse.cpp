#include<iostream>
#include<cstring>
#include<string.h>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("D:\\Programing code\\ONLINE\\doc\\11192.txt","r",stdin);
    string str1;
    char temp;
    int i,l,a,g,j,k,b,m;

    cin>>g;
    while(g!=0)
    {
        getchar();
        getline(cin,str1);
        l=str1.size();
        //cout<<l<<endl;
        a=l/g;
        k=1;
        b=a;
        //cout<<a<<endl;
        for(i=0;i<l;i+=a,k+=2)
        {
            for(j=i,m=1;j<((a*k)/2);j++,m++)
            {
                temp=str1[j];
                //cout<<temp<<endl;
                  //  cout<<str1[b-1]<<endl;
                str1[j]=str1[b-m];
                str1[b-m]=temp;
            }
           // cout<<str1<<endl;
            b+=a;
           // cout<<k<<endl;
        }
        cout<<str1<<endl;
        cin>>g;
    }

   return 0;
}
