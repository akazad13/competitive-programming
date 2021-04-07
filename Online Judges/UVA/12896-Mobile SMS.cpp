#include<bits/stdc++.h>

using namespace std;

int main()
{
    char arr[10][4]={
        {' '},
        {'.',',','?','"'},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };


    int test,length,i;

    int input1[102];
    int input2[102];

    cin>>test;
    while(test--)
    {
        cin>>length;
        for(i=0;i<length;i++)
            cin>>input1[i];
        //cout<<"end of 1st loop"<<endl;
        for(i=0;i<length;i++)
            cin>>input2[i];


        for(i=0;i<length;i++)
            cout<<arr[input1[i]][input2[i]-1];
        cout<<"\n";
    }
    return 0;
}
