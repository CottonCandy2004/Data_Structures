#ifndef __QUEUE_H__
#define __QUEUE_H__
struct Huffman_node {
    char data;
    unsigned long long weight;
    Huffman_node* left;
    Huffman_node* right;
};
typedef struct queue {
    Huffman_node** data;
    unsigned int size;
    unsigned int Linear_size;
    queue()
    {
        data = nullptr;
        size = 0;
        Linear_size = 0;
    }
    void push(Huffman_node* data)
    {
        if(size == Linear_size)
        {
            Linear_size += 10;
            Huffman_node **buff = new Huffman_node*[Linear_size];
            for(int i = 0; i < size; i++)
                buff[i] = this->data[i];
            delete[] this->data;
            this->data = buff;
        }
        int buff = size;
        for(int i = 0; i < size; i++)
        {
            if(this->data[i]->weight > data->weight)
            {
                buff = i;
                break;
            }
        }
        for(int i = size; i > buff; i--)
        {
            this->data[i] = this->data[i-1];
        }
        this->data[buff] = data;
        size++;
    }
    void pop()
    {
        size--;
        for(int i = 0; i < size; i++)
            this->data[i] = this->data[i+1];
    }
    Huffman_node* top()
    {
        return this->size > 0 ? this->data[0] : nullptr;
    }
    bool empty()
    {
        return this->size == 0;
    }
} queues;

#endif