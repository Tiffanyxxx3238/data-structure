#include <iostream>
using namespace std;

#define MaxSize 100
int queue[MaxSize];
int front = 0;    // Added front pointer
int rear = 0;     // Added rear pointer

// Function declarations
int enqueue(int);
int dequeue(int*);

int main() {  
    char c;    
    int n;
    
    while ((c = getchar()) != EOF) {  
        rewind(stdin);
        
        if (c == 'i' || c == 'I') {  
            printf("data-->"); 
            scanf("%d", &n);
            rewind(stdin);
            
            if (enqueue(n) == -1) {
                printf("FULL\n"); 
            }
        }
        
        if (c == 'o' || c == 'O') {
            if (dequeue(&n) == -1) {
                printf("EMPTY\n");
            }
            else {
                printf("queue data --> %d\n", n);
            }
        }
    }
    
    system("pause");
    return 0;
}

int enqueue(int n) {
    if ((rear + 1) % MaxSize != front) {
        rear = (rear + 1) % MaxSize;
        queue[rear] = n;
        return 0;
    }
    else {
        return -1;
    }
}

int dequeue(int* n) {
    if (rear != front) {
        front = (front + 1) % MaxSize;
        *n = queue[front];
        return 0;
    }
    else {
        return -1;
    }
}
