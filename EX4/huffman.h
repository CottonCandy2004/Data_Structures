#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <stdio.h>
#include "map.h"
#include <string>
#include "queue.h"

struct Huffman_Tree {
    Huffman_node* root;
    Huffman_Tree() : root(nullptr) {}
    void Encode(FILE* input)
    {
        map m;
        while (true) {
            char c = fgetc(input);
            if (c == EOF) {
                break;
            }
            unsigned long long count = m.find(c);
            if (count == -1)
                m.insert(c, 1);
            else
                m.insert(c, count + 1);
        }
        m.sort();
        queues q;
        for (unsigned int i = 0; i < m.size; i++) {
            Huffman_node* node = new Huffman_node;
            node->data = m.data[i].key;
            node->weight = m.data[i].value;
            node->right = node->left = nullptr;
            q.push(node);
        }
        while (q.size > 1) {
            Huffman_node* left = q.top();
            q.pop();
            Huffman_node* right = q.top();
            q.pop();
            Huffman_node* node = new Huffman_node;
            node->data = '\0';
            node->weight = left->weight + right->weight;
            node->left = left;
            node->right = right;
            q.push(node);
        }
        this->root = q.top();
    }
    void buildcode(Huffman_node* node, std::string &code, std::string &buff, bool &flag, char c)
    {
        if (flag)
            return;
        if (node->data != '\0') 
        {
            if (node->data == c)
            {
                code = buff;
                flag = true;
                return;
            }
            else
                return;
        }
        buff.append("0");
        buildcode(node->left, code, buff, flag, c);
        buff.pop_back();
        buff.append("1");
        buildcode(node->right, code, buff, flag, c);
        buff.pop_back();
    }
    std::string code(char c)
    {
        std::string code = "", buff = "";
        bool flag = false;
        buildcode(this->root, code, buff, flag, c);
        return code;
    }
    void delete_tree(Huffman_node* node)
    {
        if (node == nullptr)
            return;
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
        node = nullptr;
    }
    void Decode(FILE* input, FILE* output)
    {
        Huffman_node* currentNode = this->root;
        while (true) {
            char c = fgetc(input);
            if (c == EOF)
                break;
            if (c == '0') {
                currentNode = currentNode->left;
            }
            else {
                currentNode = currentNode->right;
            }
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                fputc(currentNode->data, output);
                currentNode = this->root;
            }
        }
    }
    ~Huffman_Tree() {
        delete_tree(this->root);
    }
};
#endif