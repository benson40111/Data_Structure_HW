#include<iostream>
using namespace std;

void print_init (int list[]){
	for (int i = 0 ; i < 6 ; i++)
		cout << list[i] << " ";
	cout << "初始陣列" << endl;
}
void swap(int list[], int i, int min){
	int temp = list[i];
	list[i] = list[min];
	list[min] = temp;
}
void print_for_teacher(int list[], int index_list[], int min){
	for (int k = 0 ; k < 6 ; k++)
		cout << list[k] << " ";
	cout << "將" << list[min] << "與" << index_list[0] << "交換" << endl;
}
int main(){
	int list[] = {86, 17, 72, 5, 27, 58};
	int index_list[1];
	print_init(list); //印出初始化值
	for (int i = 0 ; i < 6 ; i++){  //選擇排序法
		int min = i;
		for (int j = i + 1 ; j < 6 ; j++){
			if (list[j] < list[min]){
				index_list[0] = list[j];
				min = j;
			}
		}
		if (i != min){
			swap(list, i, min);  //交換用
			print_for_teacher(list, index_list, min);  //印出詳細過程
		}
	}
}//
