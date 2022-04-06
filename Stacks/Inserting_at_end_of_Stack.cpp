// Inserting at the end of stack
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void insert_at_bottom(int x, stack <int> &st)
{
     if(st.isEmpty())
        st.push(x);

    else{
        /* All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom */

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}
int main()
{

    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    insert_at_bottom(1,st);
    return 0;
}


// TIME: O(n)
// space: O(n)