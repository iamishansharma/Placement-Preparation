#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nooftestcases;
    cin>>nooftestcases;

    while(nooftestcases--)
    {
        string s;
        cin>>s;
        int flag = 0;
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            char c = s[i];

            if(c =='{' ||c =='[' || c =='(' )
            {
                st.push(c);
            }
            
            else if( (c =='}' ||c ==']' || c ==')') && st.empty())
            {
                flag =1;
                cout<<"not balanced"<<endl;
                break;
            }
            else
            {
                char topchar = st.top();
                if((topchar == '[' && s[i]==']') ||  (topchar == '(' && s[i]==')') ||  (topchar == '{' && s[i]=='}'))
                {
                    if(!st.empty())
                        st.pop();
                    else{
                        flag = 1;
                        cout<<"not balanced"<<endl;
                        break;
                    }
                }
                else{
                    flag = 1;
                    cout<<"not balanced"<<endl;
                    break;
                }
            }
        }

        if(flag == 0)
        {
            if(st.empty())
            {
                cout<<"balanced"<<endl;
            }
            else
                cout<<"not balanced"<<endl;
        }
        st.empty();
    }
}
