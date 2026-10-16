/**
 * @file GCD iterative.cpp
 * @brief Euclidean Algorithm for Greatest Common Divisor (Iterative)
 * 
 * Computes gcd(a, b) using the iterative Euclidean remainder method.
 * 
 * Time Complexity:  O(log(min(a, b)))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    int rem;
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }

    return a;
}

int main()
{
   int a,b;

   while(scanf("%d %d",&a,&b)==2)
   {
       int res = gcd(a,b);
       printf("GCD = %d\n",res);
   }

    return 0;
}

