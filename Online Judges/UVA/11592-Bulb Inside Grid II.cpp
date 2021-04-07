#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        char ch=getchar();
        map<string , string> myMap;
        for(int i=0;i<n;i++)
        {
            string str1;
            string str2;

            getline(cin,str1);
            getline(cin,str2);

            //cout<<str1<<endl;
            //cout<<str2<<endl;

            myMap[str1]=str2;

        }

        int m;

        string str;
        cin>>m;
        ch=getchar();
        for(int i=0;i<m;i++)
        {
            getline(cin,str);
            cout<<myMap[str]<<"\n";
        }

    }
    return 0;
}
