#ifndef _LINEAR_ALGO_
#define _LINEAR_ALGO_

#include "LInear_List.h"

search_results* Linear_Search(lines* line, char* search)
{
    search_results* results = new search_results;
    lines* buff = Linear_Create(1);
    for(int i = 0; i < (line->n); i++)
    {
        if(strstr((line->data)[i].ISBN, search) || strstr((line->data)[i].name, search))
        {
            Linear_Pushback(buff, (line->data)[i]);
            (results->results_num)++;
        }
    }
    books* resultdata = new books[(buff->n)];
    for(int i = 0; i < (buff->n); i++)
    {
        resultdata[i] = (buff->data)[i];
    }
    results->result = resultdata;
    Linear_Destroy(buff);
    return 0;
}

void Books_Sort(books* head, books* tail, bool is_greated)
{
    if(head>=tail) return;
    books *p,*q=head+1;
    for(p=head+1;p!=tail+1;p++)
    {
        if (is_greated)
            if(p->price > head->price)
            {
                book temp=*p;
                *p=*q;
                *q=temp;
                q++;
            }
        else
            if(p->price < head->price)
            {
                book temp=*p;
                *p=*q;
                *q=temp;
                q++;
            }
    }
    q--;
    books temp=*head;
    *head=*q;
    *q=temp;
    Books_Sort(head, q, is_greated);
    Books_Sort(q+1, tail, is_greated);
    return;
}

int Linear_sort(lines* line)
{
    Books_Sort(&(line->data)[0], &(line->data)[(line->n)], false);
    return 0;
}
#endif