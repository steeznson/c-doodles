#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_palindrome(char *word, int length){
    length -= 1;
    for (int i = 0; i < (length / 2); ++i){
        if (word[i] != word[length - i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    int result;
    int length;
    char *word;

    // clean input
    if (argc != 2){
        puts("This program takes one string argument");
        exit(1);
    }

    // grab arg
    length = strlen(argv[1]);
    word = malloc((length + 1) * sizeof(char));
    strcpy(word, argv[1]);

    // compute result and print
    result = is_palindrome(word, length);
    if (result){
        printf("%s is a palindrome\n", word);
    } else {
        printf("%s is not a palindrome\n", word);
    }

    // tidy up and exit
    free(word);
    return 0;
}
