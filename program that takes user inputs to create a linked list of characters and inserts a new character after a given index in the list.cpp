#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

typedef struct Node* Polynomial;

Polynomial create_node(int coefficient, int exponent) {
    Polynomial newNode = (Polynomial) malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void add_term(Polynomial* poly, int coefficient, int exponent) {
    Polynomial newNode = create_node(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Polynomial ptr = *poly;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display_poly(Polynomial poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
}

Polynomial simplify_poly(Polynomial poly) {
    if (poly == NULL || poly->next == NULL) {
        return poly;
    }
    Polynomial ptr1 = poly, ptr2, prev = NULL;
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        prev = ptr1;
        while (ptr2 != NULL) {
            if (ptr1->exponent == ptr2->exponent) {
                ptr1->coefficient += ptr2->coefficient;
                prev->next = ptr2->next;
                free(ptr2);
                ptr2 = prev->next;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return poly;
}

int main() {
    Polynomial poly = NULL;
    int coefficient, exponent, terms;
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &exponent);
        add_term(&poly, coefficient, exponent);
    }
    printf("Original polynomial: ");
    display_poly(poly);
    printf("\nSimplified polynomial: ");
    poly = simplify_poly(poly);
    display_poly(poly);
    return 0;
}
