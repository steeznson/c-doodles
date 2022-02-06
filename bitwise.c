/*
Simple bitwise operation calculator
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct OpMap {
    char is_and[3], is_or[2], is_sleft[5], is_sright[6];
};

int main(int argc, char* argv[]){
    // force correct positional args
    if (argc != 3){
        puts("Enter provide an operation argument");
        puts("and a numerical value.");
        puts("Accepted operation args: and or sleft sright.");
        exit(1);
    }
    int value = atoi(argv[2]);
    int length = strlen(argv[1]);
    char *op = (char*) malloc(length*sizeof(char));
    struct OpMap op_map = {"and", "or", "sleft", "sright"};

    // save op choice and parrot input
    strcpy(op, argv[1]);
    printf("You entered '%s'\n", op);

    // print results
    if (strcmp(op, op_map.is_and) <= 0){
        puts("Computed symbol &");
        for (int i = 0; i < 10; ++i){
            printf("%d & %d = %d\n", i, value, i & value);
        }
    } else if (strcmp(op, op_map.is_or) <= 0){
        puts("Computed symbol |");
        for (int i = 0; i < 10; ++i){
            printf("%d | %d = %d\n", i, value, i | value);
        }
    } else if (strcmp(op, op_map.is_sleft) <= 0){
        puts("Computed symbol <<");
        for (int i = 0; i < 10; ++i){
            printf("%d << %d = %d\n", i, value, i << value);
        }
    } else if (strcmp(op, op_map.is_sright) <= 0){
        puts("Computed symbol >>");
        for (int i = 0; i < 10; ++i){
            printf("%d >> %d = %d\n", i, value, i >> value);
        }
    }

    // tidy up
    free(op);
    return 0;
}
