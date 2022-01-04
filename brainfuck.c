#include <stdio.h>
#include <string.h>
#include <stdlib.h>


unsigned char memory[30000] = {0};
int cursor = 0;



int execute(char *input) {
    char current_char;
    size_t i, loop;

    for (i = 0; input[i] != 0; i++) {
        
        current_char = input[i];

        if (current_char == '>') {
            ++cursor;
        } else if (current_char == '<') {
            --cursor;
        } else if (current_char == '+') {
            memory[cursor]++;
        } else if (current_char == '-') {
            memory[cursor]--;
        } else if (current_char == '.' ) {
            putchar(memory[cursor]);
        } else if (current_char == ',') {
            memory[cursor] = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && memory[cursor]) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}


int main() {
    return execute("+.[+.]");
}