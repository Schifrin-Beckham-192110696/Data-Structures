#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if(top == -1) return -1;
    else return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}

int evaluate(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
}

int evalInfix(char exp[]) {
    int len = strlen(exp);
    for(int i = 0; i < len; i++) {
        if(isdigit(exp[i])) {
            int num = 0;
            while(i < len && isdigit(exp[i])) {
                num = num*10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(num);
        }
        else if(exp[i] == '(') {
            push(exp[i]);
        }
        else if(exp[i] == ')') {
            while(stack[top] != '(') {
                int b = pop();
                int a = pop();
                char op = pop();
                push(evaluate(a, b, op));
            }
            pop();
        }
        else if(isOperator(exp[i])) {
            while(top != -1 && precedence(exp[i]) <= precedence(stack[top])) {
                int b = pop();
                int a = pop();
                char op = pop();
                push(evaluate(a, b, op));
            }
            push(exp[i]);
        }
    }
    while(top != -1) {
        int b = pop();
        int a = pop();
        char op = pop();
    }
