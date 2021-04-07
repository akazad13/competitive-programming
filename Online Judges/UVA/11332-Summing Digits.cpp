#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string num;

    while(getline(cin,num))
    {
        if(num[0]=='0')
            break;
        int sumDigit=0;

        int l= num.length();

        for(int i=0;i<l;i++)
        {
            sumDigit+=num[i]-'0';
        }
        while(sumDigit>9)
        {
            int num1=0;
            while(sumDigit!=0)
            {
                num1+=sumDigit%10;
                sumDigit/=10;
            }
            sumDigit=num1;
        }

        cout<<sumDigit<<endl;
    }
    return 0;
}
