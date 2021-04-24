/******************************************************************************
Sort a stack
1> Using multiset
2> Using another temporary stack
*******************************************************************************/

#include <iostream>
#include <stack>
#include <set>

using namespace std;

void sortStackUsingMultiSet(stack<int>& s1)
{
    multiset<int> s2;
    while(!s1.empty())
    {
        s2.insert(s1.top());
        s1.pop();
    }
    
    for(auto& x: s2)
    {
        cout<<x<<endl;
    }
}

stack<int> sortStackUsingTemp2ndStack(stack<int>& s1)
{
    stack<int> s2{};
    
    while(!s1.empty())
    {
        if(s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
            continue;
        }
        
        if(s1.top() > s2.top())
        {
            auto t1 = s1.top();
            s1.pop();
            
            auto t2=s2.top();
            s2.pop();
            
            if(s2.empty())
            {
                s2.push(t1);
                s1.push(t2);
                continue;
            }
            
            while(!s2.empty() && s2.top() < t1)
            {
                s1.push(s2.top());
                s2.pop();
            }
            
            s1.push(t2);
            s2.push(t1);
        }
        else
        {
            auto t1=s1.top();
            s1.pop();
            s2.push(t1);
        }
    }
    return s2;
}

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(70);
    s.push(120);
    s.push(30);
    s.push(45);
    
    print(sortStackUsingTemp2ndStack(s));
    //sortStackUsingMultiSet(s);
    return 0;
}
