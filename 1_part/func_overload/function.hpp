#ifndef FUNC_OVERLOAD_FUNCTION_HPP
#define FUNC_OVERLOAD_FUNCTION_HPP

#include <iostream>

/**
 * @arg pointer to array, array size, pointer to function
 *
 */
void my_slow_sort(int* arr, int size, bool (*qualFunc) (int , int)) {
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(!qualFunc(arr[j], arr[j + 1])) 
                std::swap(arr[j], arr[j + 1]);
}
/**
 * @arg pointer to array, array size, pointer to function
 *
 */
void my_sort(int* arr, int size, bool (*qualFunc) (int , int)) {

    int i = 0;
    int j = size - 1;

    int mid = arr[size / 2];

    do {
        while(qualFunc(arr[i], mid)) {
            i++;
        }
        
        while(!qualFunc(arr[j], mid) && arr[j] != mid) {
            j--;
        }

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        my_sort(arr, j + 1, qualFunc);
    }
    if (i < size) {
        my_sort(&arr[i], size - i, qualFunc);
    }
}

#endif //FUNC_OVERLOAD_FUNCTION_HPP


