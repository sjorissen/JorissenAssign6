//
// Created by Sarah on 12/6/2018.
//

#ifndef UNTITLED1_HELPERS_H
#define UNTITLED1_HELPERS_H

#include <string>

int search_array(std::string cities_arr[], std::string city, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(cities_arr[i] == city) {
            return i;
        }
    }
    return -1;
}

bool is_adjacent(int **matrix, int row, int col, int max_weight) {
    return matrix[row][col] != max_weight;
}

int min(int arr [], int size) {
    int smallest = INT8_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

bool any(bool arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]) {
            return true;
        }
    }
    return false;
}

#endif //UNTITLED1_HELPERS_H
