# Insertion Sort

- Insertion Sort is a simple sorting algorithm that builds a sorted array one element at a time by shifting elements in the sorted section to insert the current element in the correct position.

## How It Works

1. **Start with the second element**: Since the first is considered sorted because a single element is inherently sorted.
2. **Take each subsequent element** (starting from index 1) and compare it with elements in the sorted section.
3. **Shift elements** in the sorted section to the right until finding the correct position for the current element.
4. **Insert the element** in the sorted section.
5. **Repeat** until the entire array is sorted.

## Example

##### Step 1

- i is the end of the sub array currently being sorted
- We start i at 2nd element since a single item in a subarray is already sorted
- j points to the element before the end of the subarray, and keeps moving down until every element in the subarray has been sorted

```
    Sub Array

    j       i/j+1
    v       v
 |-------------|

[   5   ,   1   ,   3   ]
```

##### Step 2

- Compare j+1 to j
- if j+1 < j, swap so sub-array is sorted
- We would keep moving down the subarray, but there are no more elements to compare against

```
    Sub Array

    j       i/j+1
    v       v
 |-------------|

[   1   ,   5   ,   3   ]
```

##### Step 3

- Increase size of sub-array to include the next element
- Sort this new subarray

```
       Sub Array

            j     i/j+1
            v       v
 |---------------------|

[   1   ,   5   ,   3   ]
```

- j+1 < j, so we swap them

```
       Sub Array

            j      i/j+1
            v       v
 |---------------------|

[   1   ,   5   ,   3   ]
```

- j+1 < j, so we swap them
- Then we decrease j to sort the remaining sub-array

```
       Sub Array

    j      j+1      i
    v       v       v
 |---------------------|

[   1   ,   3   ,   5   ]
```

- This goes on until the entire array is sorted

## Complexity Analysis

#### **Time Complexity** O(n²):

- **Best Case (O(n))**: If the array is already sorted, no swaps are needed.
- **Worst Case (O(n²))**: If the array is reverse-sorted, each element is compared with all previous elements.

#### **Space Complexity**:

- **O(1)**: Insertion Sort is an in-place sorting algorithm, meaning it requires no extra space.