#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DataArray;

DataArray* create_array(size_t initial_capacity) {
    DataArray* arr = (DataArray*)malloc(sizeof(DataArray));
    if (!arr) return NULL;
    
    arr->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void add_element(DataArray* arr, int value) {
    if (!arr) return;
    
    if (arr->size >= arr->capacity) {
        size_t new_capacity = arr->capacity * 2;
        int* new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
        if (!new_data) return;
        
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    
    arr->data[arr->size++] = value;
}

void print_array(const DataArray* arr) {
    if (!arr) return;
    
    printf("Array [%zu/%zu]: ", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void free_array(DataArray* arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

int main() {
    DataArray* arr = create_array(4);
    
    add_element(arr, 10);
    add_element(arr, 20);
    add_element(arr, 30);
    
    print_array(arr);
    
    free_array(arr);
    return 0;
}
