#include <stdio.h>

struct Array {
    int A[20];
    int size;
    int length;
};

// O(n)
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


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int* get (struct Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        return &arr->A[index];
    }
}

// O(n)
int max(struct Array *arr) {
    int max = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > max)
            max = arr->A[i];
    return max;
}

// O(n)
int min(struct Array* arr) {
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] < min)
            min = arr->A[i];
    return min;
}

// O(n)
int sum(struct Array* arr) {
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
        sum += arr->A[i];
    return sum;
}

int avg(struct Array* arr) {
    return sum(arr)/arr->length;
}

void set (struct Array* arr, int index, int val) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = val;
    }
}

// binary search, O(log n)
// pre-condition: arr is sorted
int bin_search(struct Array* arr, int key) {
    int low = 0;
    int high = arr->length-1;

    while (low <= high) {
        int mid = ((low+high)/2);
        if (arr->A[mid] == key) {
            return mid;
        } else if (arr->A[mid] < key) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return -1;

}

// linear search O(n)
int find(struct Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i>0)
                swap(&arr->A[i],&arr->A[i-1]); // transposition
            return i;
        }
    }
    return -1;
}

int main() {
    struct Array arr={{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43},20,15};

    printf("%d\n", avg(&arr));


    return 0;
}