#include<stdio.h>
#include<stdlib.h>

char* get_name(char* name){
    printf("Hello, what is your name?\n");
    scanf("%15s", name); 
    return name;
}

int get_age(){
    int age;
    printf("What age are you?\n");
    scanf("%d", &age);
    return age;
}

int calculate_years_till_hundred(int age){
    return 100 - age;
}

void print_greeting(char* name, int age, int till_hundred){
    printf("Hey what's up, %s?\n", name);
    printf("You are %d years old\n", age);
    printf("You will be 100 in %d years lol\n", till_hundred);
}

int main(void){
    char* name;
    int age, till_hundred;

    name = (char*) malloc(16 * sizeof(char));
    name = get_name(name);
    
    age = get_age();
    till_hundred = calculate_years_till_hundred(age);
    print_greeting(name, age, till_hundred);

    free(name);
    return 0;
}
