#include<iostream>
#include<bits/stdc++.h>

#define lld long long int

using namespace std;

bool quad(lld a, lld b, lld c, lld d)
{
    if(a<(b+c+d))
        return 1;
    else
        return 0;
}

bool rect(lld a, lld b, lld c, lld d)
{
    if((a==b&&d==c)||(a==c&&b==d)||(a==d&&b==c))
        return 1;
    else
        return 0;
}

int main()
{

    int test;
    cin>>test;
    while(test--)
    {
        lld a,b,c,d;
        cin>>a>>b>>c>>d;

        if(quad(a,b,c,d)&&quad(b,a,c,d)&&quad(c,d,a,b)&&quad(d,a,b,c))
        {
            if(rect(a,b,c,d))
            {
                if(a==b&&a==c&&a==d)
                {
                    printf("square\n");
                }
                else
                {
                    printf("rectangle\n");
                }
            }
            else
                printf("quadrangle\n");
        }
        else
            printf("banana\n");
    }
    return 0;
}
