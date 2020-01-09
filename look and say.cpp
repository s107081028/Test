#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string change(string str)
{
    stringstream sout;
    for(int i = 0; i < str.length();)
    {
        char c = str[i++];
        int countt = 1;
        while(str[i] == c)
        {
            countt++;
            i++;
        }
        sout<<countt<<c;
    }
    return sout.str();
}
int main(void)
{
    int n, k;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str>>k;
        while(k--)
        {
            str = change(str);
        }
        cout<<str<<'\n';
    }
}
