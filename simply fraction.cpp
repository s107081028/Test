#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int t;
    while(cin>>t)
    {
        unsigned long long int r, s, p = 0, q = 1, g;
        while(t--)
        {
            unsigned long long int a, b;
            cin>>a>>b;
            g = __gcd(b, q);
            r = a * (q / g) + p * (b / g);
            s = (b * q) / g;
            g = __gcd(r, s);
            p = r / g;
            q = s / g;
        }
        cout<<p<<"/"<<q<<'\n';
    }
    return 0;
}
