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
    struct node* topptr;
    stack()
    {
        this->num = 0;
        this->head = nullptr;
        this->topptr = nullptr;
    }
    void push(char push_data)
    {
        if(this->head == nullptr)
        {
            this->head = new node;
            this->head->a = push_data;
            this->head->last = nullptr;
            this->topptr = this->head;
            (this->num)++;
        }
        else
        {
            struct node* buff= new node;
            buff->last = this->topptr;
            buff->a = push_data;
            this->topptr = buff;
            (this->num)++;
        }
    }
    void pop()
    {
        if(this->num == 0)
        {
            return;
        }
        if(this->num == 1)
        {
            this->head = nullptr;
            delete this->topptr;
            (this->num)--;
            this->topptr = nullptr;
        }
        else
        {
            struct node* buff;
            buff = this->topptr;
            this->topptr = this->topptr->last;
            delete buff;
            (this->num)--;
            buff = nullptr;
        }
    }
    char top()
    {
        return this->topptr != nullptr ? this->topptr->a : NULL;
    }
    bool empty()
    {
        return this->num == 0 ? true : false;
    }
    ~stack()
    {
        while(!this->empty())
        {
            this->pop();
        }
    }
};
#endif
