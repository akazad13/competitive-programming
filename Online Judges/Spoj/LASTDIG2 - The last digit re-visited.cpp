#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    long long int b;

    int arr[][4]={
        {0,0,0,0}, {1,1,1,1}, {6,2,4,8}, {1,3,9,7},{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}
                  };

    int test;
    char str[3000];

    scanf("%d",&test);

    while(test--)
    {
        char ch = getchar();
        scanf("%s %lld",str,&b);
        int len=strlen(str);
        if(b==0)
            printf("1\n");
        else
        {
            b = b%4;
            printf("%d\n",arr[str[len-1]-'0'][b]);
        }
    }

    return 0;
}

