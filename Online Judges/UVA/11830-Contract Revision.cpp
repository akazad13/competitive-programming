#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int digit;
    char num[102],c;
    vector<int>vec;

    int length,i,val;


    while(cin>>digit)
    {
        int p=0;
        c=getchar();

        gets(num);
        length=strlen(num);
        if(digit==0&&(length==1&&num[0]=='0'))
            break;

        for(i=0;i<length;i++)
        {

            if((num[i]-'0')!=digit){
                vec.push_back((num[i]-'0'));
            }
        }
        for(i=0;i<vec.size();i++)
        {
            if(vec[i]!=0)
            {
                cout<<vec[i];
                p=1;
            }
        }
        if(p==0)
            cout<<"0";
        cout<<"\n";
        vec.clear();
    }
    return 0;
}
