#include "Linked_List.h"
#include "File_IO.h"

int main()
{
    const char *locate1 = "Result1.txt";
    const char *locate2 = "Result2.txt";
    const char *locate3 = "Result3.txt";
    const char *locate4 = "Result4.txt";
    linked_lists linked_list;
    Load_Data(&linked_list);
    int id;
    char search[100];
    printf("Enter ISBN to search: ");
    scanf("%s", search);
    nodes* node = linked_list.find(search, &id);
    if (node != nullptr)
    {
        printf("Book found at %d\n", id);
        printf("ISBN: %s\n", node->data.ISBN);
        printf("Name: %s\n", node->data.name);
        printf("Price: %.2f\n", node->data.price);
    }
    else
    {
        printf("Book not found\n");
    }
    printf("Enter name to search: ");
    scanf("%s", search);
    node = linked_list.find_by_name(search, &id);
    if (node != nullptr)
    {
        printf("Book found at %d\n", id);
        printf("ISBN: %s\n", node->data.ISBN);
        printf("Name: %s\n", node->data.name);
        printf("Price: %.2f\n", node->data.price);
    }
    else
    {
        printf("Book not found\n");
    }
    node = new nodes;
    printf("Enter ISBN to add: ");
    scanf("%s", node->data.ISBN);
    printf("Enter name: ");
    scanf("%s", node->data.name);
    printf("Enter price: ");
    scanf("%lf", &node->data.price);
    linked_list.push_back(node->data);
    Write_Data(&linked_list, locate1);
    printf("Enter ISBN to remove: ");
    scanf("%s", search);
    linked_list.remove(search);
    Write_Data(&linked_list, locate2);
    printf("Enter ISBN to change: ");
    scanf("%s", search);
    printf("Enter new price: ");
    scanf("%lf", &node->data.price);
    linked_list.change(search, node->data.price);
    Write_Data(&linked_list, locate3);
    linked_list.quick_sort(linked_list.head, linked_list.tail);
    Write_Data(&linked_list, locate4);
    printf("Size: %d", linked_list.size);
    linked_list.del();
}