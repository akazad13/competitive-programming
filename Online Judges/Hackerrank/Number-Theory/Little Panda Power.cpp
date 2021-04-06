            /************************************************/
            /************************************************/
            /**                                            **/
            /**                 *           *    *         **/
            /**                * *          *   *          **/
            /**               *   *         *  *           **/
            /**              *     *        * *            **/
            /**             *********       * *            **/
            /**            *         *      *  *           **/
            /**           *           *     *   *          **/
            /**          *             *    *    *         **/
            /**                                            **/
            /**             Md. Abul Kalam Azad            **/
            /**           CSE - 13 series , RUET,BD        **/
            /**        Email : akazad.cse13@gmail.com      **/
            /**                cell-01686871012            **/
            /**           Cool Ur head & Think :-)         **/
            /**        codeforce & uva id: akazad133032    **/
            /**         fb id: facebook.com/akazad.cse13   **/
            /**                                            **/
            /**                                            **/
            /**                                            **/
            /************************************************/
            /************************************************/



#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define lld long long int

lld x, y;
lld extendedEulid(lld a, lld b)
{
    if(b==0)
    {
        x=1; y=0;
        return 1;
    }
    lld ret = extendedEulid(b, a%b);     // GCD function
    lld x1 = y;
    lld y1 = x - (a/b) *y;
    x = x1;
    y = y1;
    return ret;
}

int main()
{
    int test;
    lld a,b,mod,res;
    scanf("%lld",&test);

    while(test--)
    {
        scanf("%lld %lld %lld",&a,&b,&mod);

        if(b<0)
        {
            extendedEulid(a,mod);
            if(x<0)
                a = (x+mod);
            else
                a = x;
            b=-1*b;
        }

        res=1;

        while(b)
        {
            if(b&1)
                res = (res*a)%mod;
            b=b>>1;
            a = (a*a)%mod;
        }

        printf("%lld\n",res);


    }
    return 0;
}

