


#include <stdio.h>



void insertionSort(int* array, int length)
{
    // Start at index 1 because the first element is already "sorted" in its own subarray
    for (int sortedEndIndex = 1; sortedEndIndex < length; sortedEndIndex++) {
        
        int currentElementIndex = sortedEndIndex; // Start with the first unsorted element
        
        // Move the unsorted element back through the sorted portion if it’s smaller than its predecessors
        while (
            currentElementIndex > 0 &&  // Prevent out-of-bounds access
            array[currentElementIndex] < array[currentElementIndex - 1]
        ) {
            // Swap elements if the current unsorted element is less than the one before it
            int temp = array[currentElementIndex];
            array[currentElementIndex] = array[currentElementIndex - 1];
            array[currentElementIndex - 1] = temp;

            // Move back to keep comparing within the sorted portion until the subarray is sorted
            currentElementIndex--;
        }
    }
}




void printArray(int* array, int length)
{
    for(int i = 0; i < length; i++) printf("%d ", array[i]);
    printf("\n");
}

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    int array[] = {4,7,2,9,1};
    printArray(array, LEN(array));
    insertionSort(array, LEN(array));
    printArray(array, LEN(array));

}
