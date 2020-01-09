#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int n, m;
    while(cin>>n && n > 0)
    {
        vector<int> N(n);
        for(int i = 0; i < n; i++) cin>>N[i];
        cin>>m;
        vector<int> M(m);
        for(int i = 0 ; i < m; i++) cin>>M[i];
        sort(N.begin(), N.end());
        sort(M.begin(), M.end());
        int i = 0, j = 0;
        bool isempty = true;
        while(i < m && j < n)
        {
            if(M[i] == N [j])
            {
                if(isempty)
                {
                    cout<<M[i];
                    isempty = false;
                }else cout<<" "<<M[i];
                ++i; ++j;
            }else if(M[i] > N[j]) ++j;
            else ++i;
        }
        if(isempty) cout<<"empty";
        cout<<'\n';
    }
    return 0;
}
