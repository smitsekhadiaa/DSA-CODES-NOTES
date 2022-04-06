// You are given a string S, the task is to reverse the string using stack.

 

// Example 1:


// Input: S="GeeksforGeeks"
// Output: skeeGrofskeeG
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack <int> stk;
    for (int i=0;i<len;i++)
    {
        stk.push(S[i]);
        
    }
    char* a=new char [len];
    int i=0;
    while(!stk.empty())
    {
        a[i]=stk.top();
        i++;
        stk.pop();
        
    }
    a[i]='/0';
    return a;
}

// ANALYSIS:
// time:O(n)
// space:O(n)
 