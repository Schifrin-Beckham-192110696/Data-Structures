#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else {
      if(front == -1)
         front = 0;
      rear++;
      queue[rear] = val;
   }
}

void dequeue() {
   if(front == -1)
      printf("Queue Underflow\n");
   else {
      printf("%d is dequeued\n", queue[front]);
      front++;
   }
}

void display() {
   if(front == -1)
      printf("Queue is Empty\n");
   else {
      for(int i = front; i <= rear; i++)
         printf("%d ", queue[i]);
      printf("\n");
   }
}

int main() {
   enqueue(5);
   enqueue(10);
   enqueue(15);
   display();
   dequeue();
   display();
   return 0;
}
