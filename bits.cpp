#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int n, nbits, m;
    cin>>n;
    while(n--){
        cin>>nbits;
        string a, b, s(10005, 0);
        cin>>a>>b;
        int c = 0;
        for(int j = nbits - 1; j >= 0; j--){
            int sum = a[j] - '0' + b[j] - '0' + c;
            c =  sum / 2;
            s[j] = sum % 2 + '0';
        }
        cout<<s.substr(0, nbits)<<'\n';
    }
	return 0;
}
