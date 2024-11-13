#ifndef __STACKS_H__
#define __STACKS_H__

struct node
{
    char a;
    struct node* last;
};

struct stack
{
    int num;
    struct node* head;
    struct node* top;
};

struct stack* stack_create()
{
    struct stack* a = new struct stack;
    a->num = 0;
    a->head = nullptr;
    a->top = nullptr;
    return a;
}

void stack_push(struct stack* stack, char push_data)
{
    if(stack->head == nullptr)
    {
        stack->head = new node;
        stack->head->a = push_data;
        stack->head->last = nullptr;
        stack->top = stack->head;
        (stack->num)++;
    }
    else
    {
        struct node* buff= new node;
        buff->last = stack->top;
        buff->a = push_data;
        stack->top = buff;
        (stack->num)++;
    }
}

void stack_pop(struct stack* stack)
{
    if(stack->num == 0)
    {
        return;
    }
    if(stack->num == 1)
    {
        stack->head = nullptr;
        delete stack->top;
        (stack->num)--;
        stack->top = nullptr;
    }
    else
    {
        struct node* buff;
        buff = stack->top;
        stack->top = stack->top->last;
        delete buff;
        (stack->num)--;
        buff = nullptr;
    }
}

char stack_top(struct stack* stack)
{
    if(stack->top != nullptr)
    {
        return stack->top->a;
    }else
    {
        throw "Empty stack!";
    }
}

bool stack_empty(struct stack* stack)
{
    if(stack->num == 0)
        {return true;}
    else
        {return false;}
}

int stack_destroy(struct stack* stack)
{
    while(!stack_empty(stack))
    {
        stack_pop(stack);
    }
    delete stack;
    return 0;
}
#endif
