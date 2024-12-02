#include <iostream>
#include <string>
#include "stacks.h"


bool is_ok(std::string a)
{
    struct stack st;
    for(auto &i : a)
    {
        if(i == '(')
        {
            st.push('(');
        }
        if(i == ')')
        {
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty() ? true : false;
}

bool is_ok_st(std::string a)
{
    struct stack st;
    std::string c;
    bool flag = false;
    for(auto &i : a)
    {
        if (i == '@')
            {flag = true; break;}
        st.push(i);
        c.push_back(i);
    }
    if(!flag)
        throw("Not end with '@'!");
    std::string b;
    while(!st.empty())
    {
        char buff = st.top();
        b.push_back(buff);
        st.pop();
    }
    return c == b ? true : false;
}
int main()
{
    printf("Put your data here:");
    std::string a;
    std::cin >> a;
    if(is_ok(a))
        printf("True\n");
    else
        printf("False\n");
    printf("Put your string here with '@' end:");
    std::cin >> a;
    try
    {
    if(is_ok_st(a))
        printf("True\n");
    else
        printf("False\n");
    }
    catch(const char* msg)
    {std::cerr << msg << std::endl;}
}