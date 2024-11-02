#ifndef _FILE_IO_
#define _FILE_IO_

#include "Basic_Struct.h"
#include <stdio.h>
#include "LInear_List.h"

int Load_Data(lines* line)
{
    FILE *fp;
    fp = fopen("book.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("vip.dat", "wb");
        if (fp == NULL)
            return -1;
    }
    while (1)
    {
        books *book_temp = new books;
        fscanf(fp, "%s%s%f", book_temp->ISBN, book_temp->name, &(book_temp->price));
        if (!feof(fp))
        {
            Linear_Pushback(line, *book_temp);
        }
        else
        {
            break;
        }
        delete(book_temp);
    }
    fclose(fp);
    return 0;
}

int Write_Data(lines* line)
{
    FILE *fp;
    fp = fopen("book.txt", "w");
    if (fp == NULL)
    {
        return -1;
    }
    for (int i = 0; i < line->n; i++)
    {
        fprintf(fp, "%s %s %f", (line->data)[i].ISBN, (line->data)[i].name, (line->data)[i].price);
    }
    fclose(fp);
    Linear_Destroy(line);
}

#endif