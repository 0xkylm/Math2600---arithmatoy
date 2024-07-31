#include <stdio.h>
#include "./include/arithmatoy.h"
#include <stdlib.h>
int main() {
    const char *lhs = "10";
    const char *rhs = "1";
    unsigned int base = 10;

    char *result = arithmatoy_sub(base, lhs, rhs);
    if (result != NULL) {
        printf("Result of %s - %s in base %d is %s\n", lhs, rhs, base, result);
        free(result);
    } else {
        printf("Subtraction result is invalid (e.g., negative result not handled).\n");
    }

    return 0;
}

