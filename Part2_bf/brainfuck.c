#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char memory[30000] = {0};
int cursor = 0;


int execute(char *input){
    char current_char;
    size_t i, loop;

    for (i = 0; input[i] != 0; i++){
        current_char = input[i];

        switch(current_char){
            case '+':
                memory[cursor]++;
                break;
            case '-':
                memory[cursor]--;
                break;
            case '>':
                cursor++;
                break;
            case '<':
                cursor--;
                break;
            case '.':
                putchar(memory[cursor]);
                break;
            case ',':
                memory[cursor] = getchar();
                break;
            case '[':
                break;
            case ']':
                if (memory[cursor]) {
                    loop = 1;

                    while ( loop > 0){
                        current_char = input[--i];
                        if (current_char == '['){
                            loop--;
                        } else if (current_char == ']'){
                            loop++;
                        }
                    }
                }
                
                break;
            
            // Non-brainfuck functions
            case '0':
                memory[cursor] = 0;
                break;
            case 'E':
                puts("Exit with code 2");
                return 2;
                break;


            default:
                break;
            
        }
    }

    puts("Exit with code 0");
    return 0;
}


int main(){

    return execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
}