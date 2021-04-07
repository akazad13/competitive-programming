#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//#define for(n) for(int i=1;i<=n;i++)

int main()
{
    string vec[20];
    vec[1]=vec[5]=vec[9]=vec[13]="Happy";
    vec[2]=vec[6]=vec[10]=vec[14]="birthday";
    vec[3]=vec[7]=vec[11]=vec[15]="to";
    vec[4]=vec[8]=vec[16]="you";
    vec[12]="Rujia";

    map<int,string> myMap;
    string str;

    int n;
    cin>>n;
    char ch=getchar();

    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        myMap[i]=str;
    }

    int m = n+(16-n%16);
    for(int j=0;j<m;j++)
    {
        cout<<myMap[(j%n)+1]<<": "<<vec[(j%16)+1]<<endl;
    }


    return 0;
}
