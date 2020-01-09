#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    string str;
    queue<string> q;
    while(cin>>str)
    {
        if(str == "Push")
        {
            cin>>str;
            q.push(str);
        }else if(str == "Pop")
        {
            if(!q.empty())  q.pop();
        }else if(str == "Front")
        {
            if(q.empty()) cout<<"empty"<<'\n';
            else cout<<q.front()<<'\n';
        }
    }
    return 0;
}
