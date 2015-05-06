//
//  main.c
//  TargetNumber
//
//  Created by JIAN WANG on 5/5/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>

struct rangeIndices {
    int index;
    int timesOfOccurs;
};

struct rangeIndices binarySearch(int key, int array[], int startingIndex, int endingIndex, struct rangeIndices rangeFinder);

int main(int argc, const char * argv[]) {
    
    int numberArray[] = {1, 1, 1, 1, 1, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 6, 7, 11, 13, 25};
    int endingIndex = sizeof(numberArray)/sizeof(int);
    int targetNumber = 1;
    struct rangeIndices rangeFinder;
    
    rangeFinder = binarySearch(targetNumber, numberArray, 0, endingIndex,  rangeFinder);
    
    printf("Number %d shows up %d times starting at index %d\n", targetNumber, rangeFinder.timesOfOccurs, rangeFinder.index);
    
    return 0;
}

// Refactor of binarySearch to return a struct
struct rangeIndices binarySearch(int key, int array[], int startingIndex, int endingIndex, struct rangeIndices rangeFinder) {
    if (startingIndex > endingIndex) {
        rangeFinder.index = -1;
        rangeFinder.timesOfOccurs = 0;
        return rangeFinder;
        
    } else {
        int midPoint = (startingIndex + endingIndex) / 2;
        if (array[midPoint] < key) {
            return binarySearch(key, array, midPoint + 1, endingIndex, rangeFinder);
        } else if (array[midPoint] > key) {
            return binarySearch(key, array, startingIndex, midPoint - 1, rangeFinder);
        } else {
            while (array[midPoint-1] == key) {
                midPoint--;
            }
            rangeFinder.index = midPoint;
            
            int timesOfOccurs = 0;
            while (array[midPoint] == key) {
                timesOfOccurs += 1;
                midPoint += 1;
            }
            
            rangeFinder.timesOfOccurs = timesOfOccurs;
            return rangeFinder;
        }
    }
}

// Original binary search
/*
int binarySearch(int key, int array[], int startingIndex, int endingIndex) {
    if (startingIndex > endingIndex) {
        return -1;
    } else {
        int midPoint = (startingIndex + endingIndex) / 2;
        if (array[midPoint] < key) {
            return binarySearch(key, array, midPoint + 1, endingIndex);
        } else if (array[midPoint] > key) {
            return binarySearch(key, array, startingIndex, midPoint - 1);
        } else {
            return midPoint;
        }
    }
}
 */
