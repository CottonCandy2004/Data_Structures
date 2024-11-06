# ifndef _LINEAR_LIST_
# define _LINEAR_LIST_

#include "Basic_Struct.h"
#include <string.h>
lines* Linear_Create(unsigned int size)
{
    books* list = new books[size];
    lines* line = new lines;
    line->data = list;
    line->max = size;
    line->n = 0;
    return line;
}

int Linear_Pushback(lines* line, book data)
{
    if(line->n == line->max)
    {
        books* new_books = new books[(line->max)*2];
        for (int i = 0; i < (line->n); i++)
        {
            new_books[i] = (line->data)[i];
        }
        line->max = (line->max) * 2;
        delete[] (line->data);
        line->data = new_books;
    }
    (line->data)[line->n] = data;
    (line->n)++;
    return 0;
}

int Linear_pop(lines* line, unsigned long long id)
{
    if(id > (line->n) || id < 0)
        return -1;
    for (int i = id + 1; i < (line->n); i++)
    {
        (line->data)[i-1] = (line->data)[i];
    }
    (line->n)--;
    return 0;
}

int Linear_change(lines* line, unsigned long long id, double price)
{
    if(id > (line->n))
        return -1;
    line->data[id].price = price;
    return 0;
}

int Linear_Destroy(lines* line)
{
    delete[](line->data);
    delete(line);
    return 0;
}

int Results_Destroy(search_results* line)
{
    delete[](line->result);
    delete(line);
    return 0;
}


int Linear_Change(lines* line, unsigned long long id, book change_data)
{
    (line->data)[id] = change_data;
    return 0;
}
# endif
