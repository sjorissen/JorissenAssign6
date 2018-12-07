//
// Created by Sarah on 12/6/2018.
//

#ifndef UNTITLED1_HELPERS_H
#define UNTITLED1_HELPERS_H

int search_array(std::string cities_arr[], std::string city, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(cities_arr[i] == city) {
            return i;
        }
    }
    return -1;
}

#endif //UNTITLED1_HELPERS_H
