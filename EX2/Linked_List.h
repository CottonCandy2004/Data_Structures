#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Basic_Struct.h"
#include <iostream>
#include <cstring>

typedef struct node {
    books data;
    struct node* prev;
    struct node* next;
} nodes;

typedef struct linked_list {
    int size = 0;
    nodes* tail = nullptr;
    nodes* head = nullptr;
    void push_back(books data){
        nodes* new_node = new nodes;
        new_node->data = data;
        new_node->next = nullptr;
        new_node->prev = tail;
        if(head == nullptr){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void pop_back()
    {
        if(tail->prev == nullptr)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            nodes* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    void del()
    {
        nodes* temp = head;
        while (temp != nullptr)
        {
            nodes* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }
    nodes* find(const char* ISBN)
    {
        nodes* temp = head;
        while (temp != nullptr)
        {
            if (strcmp(temp->data.ISBN, ISBN) == 0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    nodes* find(const char* ISBN, int* id)
    {
        nodes* temp = head;
        *id = 0;
        while (temp != nullptr)
        {
            if (strcmp(temp->data.ISBN, ISBN) == 0)
            {
                return temp;
            }
            temp = temp->next;
            (*id)++;
        }
        (*id) = -1;
        return nullptr;
    }
    nodes* find_by_name(const char* name, int* id)
    {
        nodes* temp = head;
        *id = 0;
        while (temp != nullptr)
        {
            if (strstr(temp->data.name, name)== 0)
            {
                return temp;
            }
            temp = temp->next;
            (*id)++;
        }
        (*id) = -1;
        return nullptr;
    }
    void remove(const char* ISBN)
    {
        nodes* temp = this->find(ISBN);
        if (temp != nullptr)
        {
            if (temp->prev == nullptr)
            {
                head = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }

            if (temp->next == nullptr)
            {
                tail = temp->prev;
            }
            else
            {
                temp->next->prev = temp->prev;
            }
            delete temp;
            size--;
            return;
        }
        std::cerr << ISBN << " not found" << std::endl;
        return;
    }
    void quick_sort(nodes* head, nodes* tail)
    {
        if (head == nullptr || tail == nullptr || head == tail || head->prev == tail)
            return;
        nodes* pivot = partition(head, tail);
        if (pivot != nullptr && pivot->prev != nullptr)
            quick_sort(head, pivot->prev);
        if (pivot != nullptr && pivot->next != nullptr)
            quick_sort(pivot->next, tail);
    }
    nodes* partition(nodes* low, nodes* high)
    {
        const char* pivot_value = high->data.ISBN;
        nodes* i = low->prev;
        for (nodes* j = low; j != high; j = j->next)
        {
            if (strcmp(j->data.ISBN, pivot_value) <= 0)
            {
                i = (i == nullptr) ? low : i->next;
                books temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
        i = (i == nullptr) ? low : i->next;
        books temp = i->data;
        i->data = high->data;
        high->data = temp;
        return i;
    }
    void change(const char* ISBN, double price)
    {
        nodes* temp = this->find(ISBN);
        if (temp != nullptr)
        {
            temp->data.price = price;
            return;
        }
        std::cerr << ISBN << " not found" << std::endl;
        return;
    }
} linked_lists;

#endif