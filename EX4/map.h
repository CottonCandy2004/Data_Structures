#ifndef __MAP_H__
#define __MAP_H__
struct map_node
{
    char key;
	unsigned long long value; 
};

struct map
{
	map_node* data;
	unsigned int size;
    unsigned int linear_size;
    map()
    {
        data = nullptr;
        size = 0;
    }
    unsigned long long find(char key)
    {
        for(int i = 0; i < this->size; i++)
        {
            if(this->data[i].key == key)
            {
                return this->data[i].value;
            }
        }
        return -1;
    }
    void insert(char key, unsigned long long value)
    {
        map_node node;
        node.key = key;
        node.value = value;
        if(this->size == 0)
        {
            this->data = new map_node[2];
            this->data[0] = node;
            this->size = 1;
            this->linear_size = 2;
        }
        else
        {
            unsigned int locate;
            bool flag = false;
            for(int i = 0; i < this->size; i++)
            {
                if(this->data[i].key == key)
                {
                    locate = i;
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                this->data[locate].value = value;
                return;
            }
            else
            {
                if(this->size == this->linear_size)
                {
                    map_node* temp = new map_node[this->size * 2];
                    for(int i = 0; i < this->size; i++)
                    {
                        temp[i] = this->data[i];
                    }
                    delete[] this->data;
                    temp[this->size] = node;
                    this->data = temp;
                    this->size++;
                    this->linear_size *= 2;
                }
                else
                {
                    this->data[this->size] = node;
                    this->size++;
                }
            }
        }
    }
    void remove(char key)
    {
        for(int i = 0; i < this->size; i++)
        {
            if(this->data[i].key == key)
            {
                for(int j = i; j < this->size - 1; j++)
                {
                    this->data[j] = this->data[j + 1];
                }
                this->size--;
            }
        }
    }
    void quick_sort(map_node* head, map_node* tail)
    {
        if(head >= tail) return;
        map_node* i = head + 1;
        map_node* j = head + 2;
        for(; j <= tail; j++)
        {
            if(j->value < head->value)
            {
                map_node temp = *i;
                *i = *j;
                *j = temp;
                i++;
            }
        }
        i--;
        map_node temp = *i;
        *i = *head;
        *head = temp;
        quick_sort(head, i - 1);
        quick_sort(i + 1, tail);
    }
    void sort()
    {
        map_node* head = data;
        map_node* tail = data + size - 1;
        if(head == tail) return;
        else if(tail - head == 1)
        {
            if(head->value > tail->value)
            {
                map_node temp = *head;
                *head = *tail;
                *tail = temp;
            }
            return;
        }
        else
        {
            quick_sort(head, tail);
        }
        return;
    }
    ~map()
    {
        if (data)
            delete[] data;
    }
};

#endif