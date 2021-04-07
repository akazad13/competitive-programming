#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int compre[100]={0};
    compre['A']=1;
    compre['G']=2;
    compre['M']=3;
    compre['R']=4;
    compre['T']=5;
    compre['I']=6;

    int test;
    cin>>test;
    char ch=getchar();
    while(test--)
    {
        char str[1000];
        int arr[10];
        memset(arr,0,sizeof(arr));
        gets(str);

        int len = strlen(str);

        for(int i=0;i<len;i++)
        {
            arr[compre[str[i]]]++;
        }

        arr[1]=arr[1]/3;
        arr[4]=arr[4]/2;

        sort(arr+1,arr+7);

        cout<<arr[1]<<"\n";


    }
    return 0;
}
