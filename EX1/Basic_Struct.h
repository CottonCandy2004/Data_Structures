# ifndef _Basic_Struct_
# define _Basic_Struct_
typedef struct book
{
    char ISBN[20];
    char name[100];
    int price;
} books;

typedef struct line
{
    unsigned long long n;
    unsigned long long max;
    books* data;
} lines;

typedef struct search_result
{
    unsigned long long results_num;
    books *result;
} search_results;
# endif