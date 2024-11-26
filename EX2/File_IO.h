#ifndef _FILE_IO_
#define _FILE_IO_

#include "Basic_Struct.h"
#include <stdio.h>
#include "Linked_List.h"

int Load_Data(linked_lists* linked_list)
{
    FILE *fp;
    fp = fopen("books.txt", "rb");
    if (fp == NULL)
    {
        fp = fopen("books.txt", "wb");
        if (fp == NULL)
            return -1;
    }
    while (1)
    {
        books *book_temp = new books;
        fscanf(fp, "%s %s %lf\n", book_temp->ISBN, book_temp->name, &(book_temp->price));
        linked_list->push_back(*book_temp);
        if (feof(fp))
            break;
        delete(book_temp);
    }
    fclose(fp);
    return 0;
}

int Write_Data(linked_lists* linked_list, const char* locate)
{
    FILE *fp;
    fp = fopen(locate, "w");
    if (fp == NULL)
    {
        return -1;
    }
    for (node* buff = linked_list->head; buff != nullptr; buff = buff->next)
    {
        fprintf(fp, "%s %s %f\n", buff->data.ISBN, buff->data.name, buff->data.price);
    }
    fclose(fp);
    return 0;
}
#endif