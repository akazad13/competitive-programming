#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    char line[50];
    int length,i;

    long long int SkewBinary;

    while(gets(line))
    {
        i=0;
        SkewBinary=0;
        length=strlen(line);

        if(length==1&&line[0]=='0')
            break;
        while(length!=0)
        {
            SkewBinary+=(line[i++]-'0')*(pow(2,length)-1);
            length--;
        }

        cout<<SkewBinary<<endl;
    }
    return 0;
}
