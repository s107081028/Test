#include <iostream>
#include <map>
using namespace std;
map<char, int> M;
string last = "";
void gen(char start, int k, string str)
{
     if (k > 0) {
        for(char c = start; c <= 'K'; c++)
        {
            if (M[c] > 0) {
                M[c]--;
                string rstr(1, c);
                gen(c, k-1, str+rstr);
                M[c]++;
            }
        }
     }else{
        if (str != last) {
        last = str;
        cout << str << endl;
        }
     }
}
void histogram(string str, int k)
{
     for (char c = 'A'; c <= 'K'; c++) M[c] = 0;
     for (auto s:str) {
        if (M[s] < k) M[s]++;
     }
}
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int n, k;
    string str;
    cin >> n;
    while(n--)
    {
        cin>>str>>k;
        last = "";
        histogram(str, k);
        gen('A', k, "");
    }
}
