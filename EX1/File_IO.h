#ifndef _FILE_IO_
#define _FILE_IO_

#include "Basic_Struct.h"
#include <stdio.h>
#include "LInear_List.h"

int Load_Data(lines* line)
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
        Linear_Pushback(line, *book_temp);
        if (feof(fp))
            break;
        delete(book_temp);
    }
    fclose(fp);
    return 0;
}

int Write_Data(lines* line, const char* locate)
{
    FILE *fp;
    fp = fopen(locate, "w");
    if (fp == NULL)
    {
        return -1;
    }
    for (int i = 0; i < line->n; i++)
    {
        fprintf(fp, "%s %s %f\n", (line->data)[i].ISBN, (line->data)[i].name, (line->data)[i].price);
    }
    fclose(fp);
    Linear_Destroy(line);
    return 0;
}

int Write_Results(search_result* line, const char* locate)
{
    FILE *fp;
    fp = fopen(locate , "w");
    if (fp == NULL)
    {
        return -1;
    }
    for (int i = 0; i < line->results_num; i++)
    {
        fprintf(fp, "%s %s %f\n", (line->result)[i].ISBN, (line->result)[i].name, (line->result)[i].price);
    }
    fclose(fp);
    Results_Destroy(line);
    return 0;
}


#endif