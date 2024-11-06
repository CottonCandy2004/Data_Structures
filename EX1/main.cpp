#include "LInear_List.h"
#include "Linear_Algo.h"
#include "File_IO.h"

int main()
{
    const char *locate1 = "Result1.txt";
    const char *locate2 = "Result2.txt";
    const char *locate3 = "Result3.txt";
    const char *locate4 = "Result4.txt";
    const char *locate5 = "Result5.txt";
    const char *locate6 = "Result6.txt";
    lines* books_dat = Linear_Create(30);
    Load_Data(books_dat);
    printf("Type the keyword:");
    char keywords[100];
    scanf("%s", &keywords);
    fflush(stdin);
    search_results* results = Linear_Search(books_dat, keywords);
    Write_Results(results, locate1);
    printf("\nResult sussessful write to Result1.txt\n");
    printf("Please type your data to insert. Devided by space.\n");
    books* inse = new books;
    scanf("%s%s%lf", inse->ISBN, inse->name, &inse->price);
    Linear_Pushback(books_dat, *inse);
    Write_Data(books_dat, locate2);
    printf("\nResult sussessful write to Result2.txt\n");
    books_dat = Linear_Create(30);
    Load_Data(books_dat);
    printf("Your pop ISBN:");
    char isbn[20];
    scanf("%s", isbn);
    Linear_pop(books_dat, Linear_Locate(books_dat, isbn));
    Write_Data(books_dat, locate3);
    printf("\nResult sussessful write to Result3.txt\n");
    books_dat = Linear_Create(30);
    Load_Data(books_dat);
    printf("Your change ISBN:");
    scanf("%s", isbn);
    printf("Your change value:");
    double value;
    scanf("%lf", &value);
    Linear_change(books_dat, Linear_Locate(books_dat, isbn), value);
    Write_Data(books_dat, locate4);
    printf("\nResult sussessful write to Result4.txt\n");
    books_dat = Linear_Create(30);
    Load_Data(books_dat);
    printf("\nSorting...\n");
    Linear_sort(books_dat);
    Write_Data(books_dat, locate5);
    printf("\nResult sussessful write to Result5.txt\n");
    books_dat = Linear_Create(30);
    Load_Data(books_dat);
    FILE *fp;
    fp = fopen("Result6.txt" , "w");
    if (fp == NULL)
    {
        return -1;
    }
    fprintf(fp, "%d", books_dat->n);
    fclose(fp);
    printf("\nCounts sussessful write to Result5.txt\n");
}