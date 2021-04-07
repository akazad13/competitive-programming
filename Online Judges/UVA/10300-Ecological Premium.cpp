#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  
    short int n,f,i;
    long int farmyard, animals, enFri,p;
    while(scanf("%hd",&n)!=EOF)
    {
        while(n--)
        {
            p=0;
            scanf("%hd",&f);
            for(i=0;i<f;i++)
            {
                scanf("%d %d %d",&farmyard,&animals,&enFri);
                p+= farmyard * enFri;
            }
            printf("%d\n",p);
        }

    }
    return 0;
}
