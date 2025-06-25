# IntList-C

A simple implementation of a dynamic integer list in C.
It provides functionality similar to std::vector<int> in C++, built from scratch using manual memory management.
## ✨ Features

  - Dynamic resizing (including shrink-to-fit)

  - Push, pop, insert, and remove elements

  - Get and set values by index

  - Simple memory management

  - Easy to extend

## 📦 Data Structure

    typedef struct {
        int *data;       // Pointer to the array
        int numItems;    // Number of elements in use
        int size;        // Indicates how many items fit in the allocated memory
    } IntList;

## 🔧 Available Functions

    void init_vector(IntList *vec);
    void push_back(IntList *vec, int value);
    void pop_back(IntList *vec);
    int resize(IntList *vec, int new_cap);
    int shrink_to_fit(IntList *vec);
    void insert_at(IntList *vec, int index, int value);
    void remove_at(IntList *vec, int index);
    void set(IntList *vec, int index, int value);
    int get(const IntList *vec, int index);
    void free_vector(IntList *vec);

## 🚀 Example Usage

    IntList myList;
    init_vector(&myList);
    
    push_back(&myList, 10);
    insert_at(&myList, 0, 99);
    remove_at(&myList, 1);
    
    shrink_to_fit(&myList);
    free_vector(&myList);

### ✅ See main() in main.c for a full working example.
