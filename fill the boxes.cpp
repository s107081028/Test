#include <iostream>
using namespace std;
int main(void)
{
    long int N;
    while(cin>>N)
    {
        long int ans = 0, num = 0, sum = 0;
        while(1)
        {
            cin>>num;
            if(num == 0) break;
            if(ans == 0) ans++;
            if(sum + num > N)
            {
                ans++;
                sum = num;
            }else sum += num;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
