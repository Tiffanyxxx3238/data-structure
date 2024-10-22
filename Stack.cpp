#include <iostream>
using namespace std;

#define MaxSize 100
int stack[MaxSize];//a int array to stack and input 100 elements
int sp = 0;//define a variable-sp(stack point) , it's initial is 0

int push(int);//push element(in)
int pop(int*);//pop element(out)

int main() {  
    char c;    //to restort user put instruction
    int n; //stort will push or pop num

    while ((c = getchar()) != EOF) {  // getchar()=>read everytime input char to c, untiol EOF(ctrl+D/ctrl+z)
        rewind(stdin);//clean buff, avoid left to affect getchar
        //push 
        if (c == 'i' || c == 'I') {  
            scanf("%d", &n);
            rewind(stdin);
            
            if (push(n) == -1) {//if stack full, push will return -1, and print FULL
                printf("FULL\n"); 
            }
        }
        //pop
        if (c == 'o' || c == 'O') {
            if (pop(&n) == -1) {//if stack is empty , pop will return -1, and print EMPTY
                printf("EMPTY\n");
            }
            else {
                printf("stack data --> %d\n", n);
            }
        }
    }
    
    system("pause");//waiting user push any button then over
    return 0;
}
//push function
int push(int n) {
    if (sp < MaxSize) {//if stack not full, then...
        stack[sp] = n;
        sp++;
        return 0;
    }
    else {
        return -1;
    }
}
//pop function 
int pop(int* n) {
    if (sp > 0) {//if stack not empty, then...
        sp--;
        *n = stack[sp];
        return 0;
    }
    else {
        return -1;
    }
}
