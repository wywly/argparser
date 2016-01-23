#include <stdio.h>

#include "argparser.h"

void help_func() {
    printf("You passed the help flag\n");
}

void verbose_func() {
    printf("You passed the verbose flag\n");
}

void string_func() {
    printf("Non-void args can have callbacks too!\n");
}

int main(int argc, char* argv[]) {
    int i = 0;
    double d = 0.0;
    char s[50] = "Zero";

    printf("i is now %d\n", i);
    printf("d is now %f\n", d);
    printf("s is now %s\n\n", s);

    argparser ap = argparser_create(argc, argv);

    argparser_add(&ap, "-h", "--help",    ARGTYPE_VOID,   NULL, help_func);
    argparser_add(&ap, "-v", "--verbose", ARGTYPE_VOID,   NULL, verbose_func);
    argparser_add(&ap, "-i", "--integer", ARGTYPE_INT,    &i,   NULL);
    argparser_add(&ap, "-d", "--double",  ARGTYPE_DOUBLE, &d,   NULL);
    argparser_add(&ap, "-s", "--string",  ARGTYPE_STRING, &s,   string_func);

    argparser_parse(&ap);

    printf("i is now %d\n", i);
    printf("d is now %f\n", d);
    printf("s is now %s\n", s);

    argparser_destroy(&ap);

    return 0;
}