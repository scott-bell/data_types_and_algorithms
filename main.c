#include <stdio.h>

struct Array {
    int A[20];
    int size;
    int length;
};

// O(n)
void display(struct Array* arr) {
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

// pre-condition: arr is sorted
void insert_sorted(struct Array* arr, int x) {
    int i = arr->length -1;
    while (arr->A[i]>x && i>=0)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int is_sorted(struct Array* arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        if (arr->A[i] > arr->A[i+1])
            return 0;
    }
    return 1;
}

// pre-condition: both arrays are sorted
struct Array combine(struct Array* a, struct Array* b, int size)
{
    struct Array c ={{},size,a->length + b->length};
    int* p_a = a->A;
    int* p_a_end = a->A+a->length;
    int* p_b = b->A;
    int* p_b_end = b->A+b->length;
    int* p_c = c.A;

    while ((p_b != p_b_end) || (p_a != p_a_end)) {
        if (
                ((*p_a <= *p_b) || (p_b == p_b_end)) &&
                (p_a != p_a_end)
            ) {
            *(p_c++) = *(p_a++);
        } else {
            *(p_c++) = *(p_b++);
        }
    }

    return c;
}

// pre-condition: both arrays are sorted and contain only unique values
struct Array make_union(struct Array* a, struct Array* b, int size) {
    struct Array c = {{}, size, 0};
    int *p_a = a->A;
    int *p_a_end = a->A + a->length;
    int *p_b = b->A;
    int *p_b_end = b->A + b->length;
    int *p_c = c.A;

    while ((p_b != p_b_end) && (p_a != p_a_end)) {
        if (*p_a < *p_b) {
            *p_c++ = *p_a++;
            c.length++;
        }
        else if (*p_a > *p_b) {
            *p_c++ = *p_b++;
            c.length++;
        }
        else {
            *p_c++ = *p_a++;
            c.length++;
            p_b++;
        }
    }
    while (p_a != p_a_end) {
        *p_c++ = *p_a++;
        c.length++;
    }
    while (p_b != p_b_end) {
        *p_c++ = *p_b++;
        c.length++;
    }
    return c;
}

// pre-condition: both arrays are sorted and contain only unique values
struct Array intersection(struct Array* a, struct Array* b, int size) {
    struct Array c = {{}, size, 0};
    int *p_a = a->A;
    int *p_a_end = a->A + a->length;
    int *p_b = b->A;
    int *p_b_end = b->A + b->length;
    int *p_c = c.A;

    while ((p_b != p_b_end) && (p_a != p_a_end)) {
        if (*p_a < *p_b)
            p_a++;
        else if (*p_a > *p_b)
            p_b++;
        else {
            *p_c++ = *p_a++;
            c.length++;
            p_b++;
        }
    }
    return c;
}

// pre-condition: both arrays are sorted and contain only unique values
struct Array difference(struct Array* a, struct Array* b, int size) {
    struct Array c = {{}, size, 0};
    int *p_a = a->A;
    int *p_a_end = a->A + a->length;
    int *p_b = b->A;
    int *p_b_end = b->A + b->length;
    int *p_c = c.A;

    while ((p_b != p_b_end) && (p_a != p_a_end)) {
        if (*p_a < *p_b) {
            *p_c++ = *p_a++;
            c.length++;
        }
        else if (*p_a > *p_b) {
            *p_c++ = *p_b++;
            c.length++;
        }
        else {
            p_a++;
            p_b++;
        }
    }
    while (p_a != p_a_end) {
        *p_c++ = *p_a++;
        c.length++;
    }
    return c;
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// move neg items to left
void neg_pos(struct Array* arr) {
    int* i = arr->A;
    int* j = arr->A+arr->length-1;
    while (i < j) {
        while (*i < 0) {
            i++;
        }
        while (*j >= 0) {
            j--;
        }
        if (i < j)
            swap(i,j);
    }

}

void left_shift(struct Array* arr) {
    int t = arr->A[0];
    delete(arr, 0);
    append(arr, t);
}


void reverse(struct Array* arr) {
    int i = 0, j = arr->length-1;
    while (i < j)
        swap(&arr->A[i++],&arr->A[j--]);
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
    struct Array b={{1,2,3},20,3};
    struct Array a={{2,3,4},20,3};
    struct Array c=difference(&a,&b,20);
    display(&c);


    return 0;
}