#include <stdio.h>
#include <string.h>

typedef unsigned char uint8_t;
typedef struct stack {
uint8_t elements[10];
char top;
}ST_stack_t;

ST_stack_t stack;
ST_stack_t *ptr_stack=&stack;
uint8_t data,i;
char state,expression;
char* ptr_expression=&expression;
uint8_t *ptr_data=&data;
uint8_t topData;
uint8_t *ptr_topData=&topData;


void createEmptyStack(ST_stack_t *stack);
uint8_t push(ST_stack_t *stack, uint8_t data);
uint8_t printStack(ST_stack_t *stack);
uint8_t pop(ST_stack_t *stack, uint8_t *data);
uint8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
char isBalancedParanthethes(char *expression);
uint8_t matching_paranthethesis(uint8_t,uint8_t);

int main(){
createEmptyStack(ptr_stack);
push(ptr_stack,'1');
push(ptr_stack,'2');
push(ptr_stack,'a');
push(ptr_stack,'b');
push(ptr_stack,'!');
printStack(ptr_stack);
pop(ptr_stack,ptr_data);
getStackTop(ptr_stack,ptr_topData);
printStack(ptr_stack);
for (i=0;i<7;i++){
    printf("\nEnter element to push:");
    scanf(" %c",&data);
    push (ptr_stack,data);
}
getStackTop(ptr_stack,ptr_topData);
printStack(ptr_stack);
for (i=0;i<4;i++){
pop(ptr_stack,ptr_data);}
getStackTop(ptr_stack,ptr_topData);
printStack(ptr_stack);
for (i=0;i<7;i++){
pop(ptr_stack,ptr_data);}
getStackTop(ptr_stack,ptr_topData);
printStack(ptr_stack);
for (uint8_t y=0;y<10;y++){
printf ("\n\nEnter expression:");
scanf("%s",&expression);
state=isBalancedParanthethes(ptr_expression);
switch (state){
case 0:  printf("\nThe expression is balanced"); break;
case -1: printf("\nThe expression is not balanced"); break;
case -2: printf("\nThe expression doesn't include paranthethes"); break;}
}
}

void createEmptyStack(ST_stack_t *stack){
for(int i=0;i<10;i++){
stack->elements[i]=0;}
stack->top=-1;
}
uint8_t push(ST_stack_t *stack, uint8_t data){
     if (stack->top==9) return -1;
     else {stack->top++; stack->elements[stack->top]=data; return 0;}
 }//returns -1 if the stack is full/returns 0 otherwise;
uint8_t printStack(ST_stack_t *stack){
 if (stack->top==-1) return -2;
 else if (stack->top==9) {
    for (int j=9;j>-1;j--){
    printf("%c\t",stack->elements[j]); }
    printf("\n");
    return -1;}
 else{
    uint8_t k=stack->top;
    int y;
    for (y=k;y>-1;y--){printf("%c\t",stack->elements[y]);}
    printf("\n");
    return 0;}
 }//returns -1 if the stack is full/returns -2 if the stack is empty/returns 0 otherwise
uint8_t pop(ST_stack_t *stack, uint8_t *data){
 if (stack->top==-1) return -2;
 else {*data=stack->elements[stack->top]; stack->top--; return 0;}
 }//returns -2 if the stack is empty/returns 0 otherwise;
uint8_t getStackTop(ST_stack_t *stack, uint8_t *topData){
  if (stack->top==-1) return -2;
  else {
        *topData=stack->elements[stack->top];
        printf("%c\n",*topData);
        return 0;}
}//returns -2 if the stack is empty/0 otherwise
uint8_t matching_paranthethesis(uint8_t close,uint8_t open){
if (close==')'&&open=='(') return 1;
else if (close=='}'&&open=='{')  return 1;
else  return 0;
}


char isBalancedParanthethes(char *exp){
uint8_t length = strlen(exp);
uint8_t counter=0;
createEmptyStack(ptr_stack);

for(uint8_t c= 0; c<length; c++){
   if (exp[c]!='(' && exp[c]!='{'&&exp[c]!=')' && exp[c]!='}'){
    counter++;
   }}
if (counter==length) return -2;
for(uint8_t c= 0; c<length; c++){
   if( exp[c]=='(' || exp[c]=='{'){
      push(ptr_stack,exp[c]);}
   else if (exp[c]==')' || exp[c]=='}'){
    if (ptr_stack->top==-1) return -1;
    else {
        pop(ptr_stack,ptr_data);
        if(!matching_paranthethesis(exp[c],data)) return -1;
   }
   }
}
if (ptr_stack->top==-1) return 0;
else return -1;
}
