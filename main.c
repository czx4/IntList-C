#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESIZE_STEP 10
typedef struct{
    int *data; // Points to the memory where the list items are stored
    int numItems; // Indicates how many items are currently in the list
    int size; // Indicates how many items fit in the allocated memory
} IntList;
void init_list(IntList *vec);
void push_back(IntList *vec,int value);
int resize(IntList *vec, int new_cap);
void free_list(IntList *vec);
void set(IntList *vec,int index,int value);
int get(const IntList *vec,int index);
void pop_back(IntList *vec);
void insert_at(IntList *vec,int index,int value);
void remove_at(IntList *vec,int index);
int shrink_to_fit(IntList *vec);

int main(void) {

    IntList myList;
    init_list(&myList);

    push_back(&myList,55);
    push_back(&myList,44);
    push_back(&myList,33);
    push_back(&myList,22);

    resize(&myList,6);
    set(&myList,0,10);
    printf("Value at index 0: %d\n",get(&myList,0));
    for (int i=0;i<myList.numItems;i++) {
        printf("\n %d",myList.data[i]);
    }
    printf("\n");

    pop_back(&myList);
    for (int i=0;i<myList.numItems;i++) {
        printf("\n %d",myList.data[i]);
    }
    printf("\n one number popped from end\n");

    insert_at(&myList,1,99);

    remove_at(&myList,0);
    for (int i=0;i<myList.numItems;i++) {
        printf("\n %d",myList.data[i]);
    }
    printf("\n \n 99 inserted into index 1 and removed index 0\n");

    printf("%d numbers can fit, %d numbers are in list\n",myList.size,myList.numItems);
    shrink_to_fit(&myList);
    printf("%d numbers can fit, %d numbers are in list\n",myList.size,myList.numItems);
    free_list(&myList);
    return 0;
}
void init_list(IntList *vec) {
    vec->numItems=0;
    vec->size=RESIZE_STEP;
    vec->data=malloc(vec->size*sizeof(int));
    if(vec->data==NULL) printf("Memory allocation failed\n");
}

void push_back(IntList *vec, const int value) {
    if(vec==NULL) return;
    if(vec->size == vec->numItems) {
        if(!resize(vec,vec->size+RESIZE_STEP)) return;
    }
    vec->data[vec->numItems++]=value;
}

int resize(IntList *vec, const int new_cap) {
    if(vec==NULL) return 0;
    if(vec->numItems>new_cap) {
        printf("Given size is too small to fit all the data\n");
        return 0;
    }
    int *tmp=realloc(vec->data,new_cap*sizeof(int));
    if(tmp==NULL) {
        printf("Memory allocation failed during resize.\n");
        return 0;
    }
    vec->data=tmp;
    vec->size=new_cap;
    return 1;
}

void free_list(IntList *vec) {
    free(vec->data);
    vec->data=NULL;
    vec->size=0;
    vec->numItems=0;
}

void set(IntList *vec, const int index, const int value) {
    if(index<0 || index>=vec->numItems) {
        printf("Index is out of bounds\n");
        return;
    }
    vec->data[index]=value;
}

int get(const IntList *vec, const int index) {
    if(index<0 || index>=vec->numItems) {
        printf("Index is out of bounds\n");
        return 0;
    }
    return vec->data[index];
}

void pop_back(IntList *vec) {
    if(vec==NULL) return;
    if(vec->numItems==0) {
        printf("the list is empty \n");
        return;
    }
    vec->data[vec->numItems-1]=0; //Optional: zero out the removed element for safety (not required)
    vec->numItems--;
}

void insert_at(IntList *vec,int index,int value) {
    if(vec==NULL) return;
    if(index<0) {
        printf("Index out of bounds\n");
        return;
    }
    if(index>vec->numItems) {
        printf("the list is not long enough to have something inserted at that index\n");
        return;
    }
    if(vec->size == vec->numItems) {
        if(!resize(vec,vec->size+RESIZE_STEP)) return;
    }
    for(int i=vec->numItems-1;i>=index;i--) {
        vec->data[i+1]=vec->data[i];
    }
    vec->data[index]=value;
    vec->numItems++;
}

void remove_at(IntList *vec,int index) {
    if(vec==NULL)return;
    if(index<0||index>=vec->numItems) {
        printf("Index out of bounds\n");
        return;
    }
    for(int i=index;i<vec->numItems-1;i++) {
        vec->data[i]=vec->data[i+1];
    }
    vec->data[vec->numItems-1]=0; //Optional: zero out the removed element for safety (not required)
    vec->numItems--;
}

int shrink_to_fit(IntList *vec) {
    if(vec==NULL) return 0;
    if(vec->size>vec->numItems) {
        int *tmp=realloc(vec->data,vec->numItems*sizeof(int));
        if(tmp==NULL) {
            printf("Memory allocation failed during resize.\n");
            return 0;
        }
        vec->data=tmp;
        vec->size=vec->numItems;
    }
    return 1;
}