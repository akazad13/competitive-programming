#include<stdio.h>
#include<string.h>
int main()
{
    long long int b,c,l,i;
    char a[1002];
    while(1)
    {
        gets(a);
        l=strlen(a);
        if(a[0]=='0' && l==1)
            break;
        b=0;
        c=0;
        for(i=0;i<l;i+=2)
        {
           b+=a[i]-'0';
        }
        for(i=1;i<l;i+=2)
        {
            c+=a[i]-'0';
        }
        if(((b-c)%11)==0)
        {
            printf("%s is a multiple of 11.\n",a);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",a);
        }
    }
    return 0;
}
