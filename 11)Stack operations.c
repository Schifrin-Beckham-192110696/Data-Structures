#include <stdio.h>
#define MAX 5
int stack[MAX],top=-1;

void push(int val) {
   if(top==MAX-1)
      printf("Stack Overflow\n");
   else {
      top++;
      stack[top]=val;
   }
}

void pop() {
   if(top==-1)
      printf("Stack Underflow\n");
   else {
      printf("%d is popped\n",stack[top]);
      top--;
   }
}

void peek() {
   if(top==-1)
      printf("Stack is Empty\n");
   else
      printf("%d\n",stack[top]);
}

int main() {
   push(5);
   push(10);
   push(15);
   peek();
   pop();
   peek();
   return 0;
}
