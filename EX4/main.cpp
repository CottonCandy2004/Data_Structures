#include <stdio.h>
#include <string>
#include "map.h"
#include "queue.h"
#include "huffman.h"

int main()
{
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    Huffman_Tree tree;
    tree.Encode(input);
    rewind(input);
    while (true) {
        char c = fgetc(input);
        if (c == EOF) {
            break;
        }
        fputs(tree.code(c).c_str(), output);
    }
    fclose(input);
    fclose(output);
    FILE* input2 = fopen("output.txt", "r");
    FILE* output2 = fopen("output2.txt", "w");
    tree.Decode(input2, output2);
    fclose(input2);
    fclose(output2);
}