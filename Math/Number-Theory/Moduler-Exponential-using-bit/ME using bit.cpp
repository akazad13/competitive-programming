/**
 * @file ME using bit.cpp
 * @brief Modular Exponentiation using Bitwise Shifts (Last Digit of a^b)
 * 
 * Computes (a^b) % 10 using binary exponentiation by testing bits of b.
 * 
 * Time Complexity:  O(log b)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned int a,b;
    int res;
    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%u %u",&a,&b);
        res=1;
        while(b)
        {
            if(b&1)
                res = (res*a)%10;
            b=b>>1;
            a = (a*a)%10;
        }
        printf("%d\n",res);
    }

    return 0;
}
