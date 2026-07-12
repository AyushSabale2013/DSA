// https://takeuforward.org/plus/dsa/problems/reverse-a-stack?source=strivers-a2z-dsa-track

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushAtBottom(int top1, stack<int> &st)
    {
        if (st.empty())
        {
            st.push(top1);
            return;
        }
        int top2 = st.top();
        st.pop();
        pushAtBottom(top1, st);
        st.push(top2);
    }
    void reverseStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int top1 = st.top();
        st.pop();
        reverseStack(st);
        pushAtBottom(top1, st);
    }
};

int main()
{

    return 0;
}