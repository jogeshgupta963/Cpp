#include <iostream>
#include <queue>
using namespace std;

class stack
{
    queue<int> q1;
    queue<int> q2;
    int n;

public:
    stack()
    {
        n = 0;
    }

    void push(int val)
    {

        q1.push(val);
        n++;
    }
    void pop()
    {

        if (q1.empty())
            return;

        while (q1.size() != 1)
        {

            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top()
    {

        if (!q1.empty())
            return -1;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size()
    {
        return n;
    }
};
int main()
{
    stack st;
    st.push(5);
    st.push(7);
    cout << st.top();
    // st.pop();
    // cout<<st.top();
    // cout<<st.size();
    return 0;
}