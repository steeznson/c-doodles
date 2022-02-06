#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/queue.h>

void printargs(int num, ...) {
    va_list ap;
    va_start(ap, num); 
    for (int i = 0; i < num; ++i){
        printf("%s\n", va_arg(ap, char*));
    }
    va_end(ap);
}

struct Entry {
    LIST_ENTRY(Entry) pointers;
    char* title;
    char* contents;
} *e1, *e2, *ep;

int main(void) {
    LIST_HEAD(listhead, Entry) head =
        LIST_HEAD_INITIALIZER(head);
    LIST_INIT(&head);

    e1 = malloc(sizeof(struct Entry));
    e1->title = "Entry 1";
    e1->contents = "This is my first entry";

    e2 = malloc(sizeof(struct Entry));
    e2->title = "Entry 2";
    e2->contents = "This is my second entry";
    
    LIST_INSERT_HEAD(&head, e1, pointers);
    LIST_INSERT_AFTER(e1, e2, pointers);

    LIST_FOREACH(ep, &head, pointers){
        printargs(2, ep->title, ep->contents);
    }

    LIST_REMOVE(e1, pointers);
    free(e1);
    LIST_REMOVE(e2, pointers);
    free(e2);
    return 0;
}
