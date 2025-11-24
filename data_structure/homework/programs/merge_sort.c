#include <stdio.h>
#include <stdlib.h>

typedef struct array{
    int *data;
    struct array* next;
    size_t size;
}array;

void mitad(array arr, array *left, array *right) {
    int mid = arr.size / 2;
    left->size = mid;
    right->size = arr.size - mid;
    left->data = (int*)malloc(left->size * sizeof(int));
    right->data = (int*)malloc(right->size * sizeof(int));
    for (int i = 0; i < mid; i++) {
        left->data[i] = arr.data[i];
    }
    for (int i = mid; i < arr.size; i++) {
        right->data[i - mid] = arr.data[i];
    }
}

array merge(array left, array right) {
    array result;
    result.size = left.size + right.size;
    result.data = (int*)malloc(result.size * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < left.size && j < right.size) {
        if (left.data[i] <= right.data[j]) {
            result.data[k++] = left.data[i++];
        } else {
            result.data[k++] = right.data[j++];
        }
    }
    while (i < left.size) {
        result.data[k++] = left.data[i++];
    }
    while (j < right.size) {
        result.data[k++] = right.data[j++];
    }
    return result;
}

array merge_sort(array arr) {
    if (arr.size <= 1) {
        return arr;
    }
    array left, right;
    mitad(arr, &left, &right);
    left = merge_sort(left);
    right = merge_sort(right);
    array sorted = merge(left, right);
    free(left.data);
    free(right.data);
    return sorted;
}

int main(){
    array arr;
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &arr.size);
    arr.data = (int*)malloc(arr.size * sizeof(int));
    printf("Ingresa los elementos:\n");
    for(int i = 0; i < arr.size; i++){
        scanf("%d", &arr.data[i]);
    }
    array sorted = merge_sort(arr);
    printf("Arreglo ordenado:\n");
    for(int i = 0; i < sorted.size; i++){
        printf("%d ", sorted.data[i]);
    }
    return 0;
}