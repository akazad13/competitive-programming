#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[56];

    int length;

    while(gets(str))
    {

        if(str[0]=='#')
            break;
        length=strlen(str);
        if(next_permutation(str,str+length))
            cout<<str<<endl;
        else
            cout<<"No Successor"<<endl;
    }
    return 0;
}

