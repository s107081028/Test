#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct Node{
    int prev;
    int next;
};
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    Node S[100003];
    int N;
    cin>>N;
    for(int i = 0; i <= N + 1; i++){
        S[i].next = i+1;
        S[i].prev = i-1;
    }
    while(1)
    {
        string str;
        cin>>str;
        if(str == "Exit") break;
        int a, b;
        cin>>a>>b;
        int p, q, r;
        p = S[a].next;
        q = S[b].prev;
        if(a == q) continue;
        r = S[0].next;
        S[a].next = b;
        S[b].prev = a;
        S[r].prev = q;
        S[q].next = r;
        S[0].next = p;
        S[p].prev = 0;
    }
    if(N > 0)
    {
        int t = S[0].next;
        cout<<t;
        --N;
        while (N>0) {
            t = S[t].next;
            cout<<" "<<t;
            --N;
        }
    }
    cout<<"\n";
    return 0;
}
