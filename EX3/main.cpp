#include <iostream>
#include <string>
#include "stacks.h"


bool is_ok(std::string a)
{
    struct stack* st = stack_create();
    for(auto &i : a)
    {
        if(i == '(')
        {
            stack_push(st, '(');
        }
        if(i == ')')
        {
            if(!stack_empty(st))
            {
                stack_pop(st);
            }
            else
            {
                stack_destroy(st);
                return false;
            }
        }
    }
    if(stack_empty(st))
        {stack_destroy(st); return true;}
    else
        {stack_destroy(st); return false;}
}

bool is_ok_st(std::string a)
{
    struct stack* st = stack_create();
    std::string c;
    bool flag = false;
    for(auto &i : a)
    {
        if (i == '@')
            {flag = true; break;}
        stack_push(st, i);
        c.push_back(i);
    }
    if(!flag)
        throw("Not end with '@'!");
    std::string b;
    while(!stack_empty(st))
    {
        char buff = stack_top(st);
        b.push_back(buff);
        stack_pop(st);
    }
    stack_destroy(st);
    if(c == b)
        {return true;}
    else
        {return false;}
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