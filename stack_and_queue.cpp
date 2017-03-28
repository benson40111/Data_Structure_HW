#include<iostream>
using namespace std;

int stack[10], top = 0;
int queue[10], rear = 0, front = 0;

void push (int data, int n){
	stack[top] = data;
	top++;
}

void pop (){
	for (int i = top - 1 ; i < top ; i--){
		if (top == 0){
			cout << "stack is empty!" << endl;
			break;
		}

		else{
			cout << stack[i] << " ";
			top--;
			cout << "pop出來一個後目前top為" << top << endl;
		}
	}
}

void enqueue (int data, int n){
	queue[rear] = data;
	rear++;
}

void dequeue (){
	for (int i = 0; i < rear ; i++){ 
		if (front == rear){
			cout << "queue is empty!" << endl;
			break;
		}
		else{
			cout << queue[i] << " ";
			front++;
			cout << "enqueue出後一個後目前front為" << front << " " << "rear為" << rear << endl;
		}
	}
}

int main(){
	int n = 0, data[10];
	cout << "Size = ? MAX = 10" << endl;	
	cin >> n;
	cout << "numbers = ?" << endl;
	
	for (int i = 0 ; i < n ; i++){
		cin >> data[i];
		push(data[i], n);
		enqueue(data[i], n);
	}
	pop();
	cout << endl;
	dequeue();
}
