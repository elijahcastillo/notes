# Singly Linked List

- Each node in the list has a value, and a pointer to the next node (or NULL if it is at the tail of the list)

```
   **Head**                                  **Tail**
 ____________         ____________         ____________
|            |       |            |       |            |
|   Pointer  | ----> |   Pointer  | ----> |   Pointer  | ----> NULL
|------------|       |------------|       |------------|
|    Data    |       |    Data    |       |    Data    |
|____________|       |____________|       |____________|

```

## Time Complexity

#### Search O(n)

- There is no random access into the linked list
  - To get to the last elemtn you must start from the head and go though each node
- Since you have to go though each node the worst case sinearo is going through the entire list
  - This is what makes it O(n), where n is the number of nodes in the list

#### Append O(n) / O(1)

- If you keep a tail pointer, then its O(1)
  - Set the tail's pointer to the new node
  - Update the tail to be the new node
- Otherwise its O(n)
  - First you traverse the entire liked list until you get to the tail,
  - Then point the last node to the new node

#### Delete O(n) / O(1)

- O(1) if you are deleting the head node:
  - Simply move the head pointer to the next node.
- O(n) for deleting any other node:
  - First, you need to search for the node to delete or the node just before it.
  - If the node to delete is at the tail, you must traverse the entire list to find it.
  - Once found, adjust the previous node’s pointer to bypass the node to be deleted (Free the memory if needed)

## Space Complexity O(n)

- Each node in the list requires space to store the data and a pointer to the next node.
- The space required for a singly linked list is proportional to the number of nodes, hence the space complexity is O(n).

# Doubly Linked List

```
               **Head**                                  **Tail**
             ____________         ____________         ____________
  NULL  <-- |    Prev    | <---- |    Prev    | <---- |    Prev    |
            |    Next    | ----> |   Next     | ----> |    Next    | ----> NULL
            |------------|       |------------|       |------------|
            |    Data    |       |    Data    |       |    Data    |
            |____________|       |____________|       |____________|

```
