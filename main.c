#include <stdio.h>

struct Array {
    int A[20];
    int size;
    int length;
};

void display(struct Array *arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void append(struct Array *arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++]=x;
}

void delete(struct Array *arr, int index)
{
    for (int i = index; i < arr->length; i++)
        arr->A[i] = arr->A[i+1];
    arr->length--;
}

void insert(struct Array *arr, int index, int x) {
    if (index>=0 && index <= arr->length) {
        for (int i = arr->length; i >= index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int find(struct Array *arr, int x) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == x)
            return i;
    }
    return -1;
}

int main() {
    struct Array arr={{2,3,4,5,6},20,5};
    append(&arr,10);
    display(&arr);
    int f = find(&arr,4);
    printf("%d\n", f);

    return 0;
}