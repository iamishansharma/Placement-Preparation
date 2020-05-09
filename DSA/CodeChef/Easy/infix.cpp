#include <bits/stdc++.h>
using namespace std;

int isOperator(char a){
    if(a=='+' or a=='-' or a=='*' or a=='/' or a=='^')
        return 1;
    else
        return 0;
}

int isopenBracket(char a){
    if(a=='(')
        return 1;
    else
        return 0;
}

int iscloseBracket(char a){
    if(a==')')
        return 1;
    else
        return 0;
}

int isOperand(char a){
    if(a>='A' and a<='Z')
        return 1;
    else
        return 0;
}

int precedence(char a){
    if(a=='+' or a=='-')
        return 1;
    if(a=='*' or a=='/')
        return 2;
    if(a=='^')
        return 3;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string infix;
        string postfix="";
        cin>>infix;
        stack<char> st;
        for(int i=0;i<n;i++){
            char a=infix[i];
            if(isOperand(a)){
                postfix+=infix[i];
                continue;
            }
            if(isopenBracket(a)){
                st.push(a);
                continue;
            }
            if(iscloseBracket(a)){
                x1: char x=st.top();
                if(x=='('){
                    st.pop();
                    continue;
                }
                else{
                    postfix+=x;
                    st.pop();
                    goto x1;
                }
            }
            if(isOperator(a)){
                
               
                while(!st.empty() and precedence(st.top())>=precedence(a)){
                   char x=st.top();
                    
                    postfix+=x;
                    st.pop();
                }
                st.push(a);
                
                
            }
                
        }
        while(!st.empty()){
            char x=st.top();
            postfix+=x;
            st.pop();
        }
        cout<<postfix<<"\n";
    }
    return 0;
}