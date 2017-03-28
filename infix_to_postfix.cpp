#include <stdio.h> 
#include <stdlib.h> 

//一定要在前面定義 不然會噴錯
void convert(char*, char*); //中序轉後序 
int who_first(char); //優先權

int main() { 
	char infix[100] = {}; 
	char postfix[100]= {}; 

	printf("Input infix: \n"); 
	scanf("%s", infix); //用字元方式讀入 
	convert(infix, postfix); //轉換

	for(int i = 0; postfix[i] != '\0'; i++) //輸出到螢幕上 
		printf("%c", postfix[i]); 
} 

void convert(char* infix, char* postfix) { 
	char stack[999] = {'\0'}; //清空堆疊 不然會噴錯
	int j = 0, top = 0;
	for(int i = 0 ; infix[i] != '\0'; i++) 
		switch(infix[i]){  //開始讀取運算子
		case '(':              
			stack[++top] = infix[i]; //使用++top 先放入後再++ 
			break; 
		case '+': case '-': case '*': case '/': 
			while(who_first(stack[top]) >= who_first(infix[i])) //當優先權大時 就從堆疊拿出來
				postfix[j++] = stack[top--];
			stack[++top] = infix[i]; //沒有的話就放入堆疊
			break; 
		case ')': 
			while(stack[top] != '(')  //當讀到)的時候將堆疊輸出 一直到(為止
				postfix[j++] = stack[top--];
			top--; //不--會指到空的 也就是剛剛存這個(的 
			break; 
		default:  //直接輸出 
			postfix[j++] = infix[i];
	}
	while(top > 0) //輸出運算子
		postfix[j++] = stack[top--];
} 

int who_first(char first){ 
	switch(first){  //'+' '-' 最低 '*' '/' 最高
		case '+': 
			return 1;
		case '-': 
			return 1;
		case '*': 
			return 2;
		case '/': 
			return 2;
		default:            
			return 0;
	} 
} 
