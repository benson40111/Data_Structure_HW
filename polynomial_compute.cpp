#include<iostream>
#include<string>
using namespace std;

/*初始化*/
void init(int f_coef[], int f_degree[], int g_coef[], int g_degree[], int result_coef[], int result_degree[]){
	cout << "f(x) = x^10 + 6 * x^5 - 2" << endl;
	cout << "g(x) = 3 * x^50 - 2 * x^10 + 1" << endl;

	f_coef[0] = 1;
   	f_coef[1] = 6;
	f_coef[2] = -2;

	f_degree[0] = 10;
	f_degree[1] = 5;
	f_degree[2] = 0;

	g_coef[0] = 3;
	g_coef[1] = -2;
	g_coef[2] = 1;

	g_degree[0] = 50;
	g_degree[1] = 10;	
	g_degree[2] = 0;
}

/*泡沫排序法*/
void buble_sort(int result_coef[], int result_degree[]){
	int temp_coef = 0, temp_degree = 0;
	for (int i = 0 ; i < 9 ; i++){
		for (int j = 0 ; j < 9 ; j++){
			if (result_degree[j] < result_degree[i]){
				temp_degree = result_degree[i];
				result_degree[i] = result_degree[j];
				result_degree[j] = temp_degree;

				temp_coef = result_coef[i];
				result_coef[i] = result_coef[j];
				result_coef[j] = temp_coef;
			}
		}
	}
}

/*印出格式 強迫症使用*/
void print_normal(int result_coef[], int result_degree[], string s){
	for (int i = 0 ; i < 4 ; i++){
		if (result_coef[i] > 0)
			s = " + ";
		else{
			result_coef[i] = result_coef[i] * (-1);
			s = " - ";
		}
		cout << s << result_coef[i] << " * x^" << result_degree[i];
	}
	cout << "\n";
}

/*印出格式 給乘法用的*/
void print_for_mult(int result_coef[], int result_degree[], string s){
	for (int i = 0 ; i < 9 ; i++){
		if (result_coef[i] > 0)
			s = " + ";
		else{
			result_coef[i] = result_coef[i] * (-1);
			s = " - ";
		}
		cout << s << result_coef[i] << " * x^" << result_degree[i];
	}
	cout << "\n";
}

/*加法*/
void add(int f_degree[], int f_coef[], int g_degree[], int g_coef[], int result_coef[], int result_degree[]){
	int i = 0, j = 0, count = 0;
	while((i <= 2 && j <= 2) == true){
		if (f_degree[i] == g_degree[j]){  //當次方一樣時 係數直接加
			result_coef[count] = f_coef[i] + g_coef[j];
			result_degree[count] = f_degree[i];  //次方直接移動 g_degree也可以
			i++;  //往下繼續加
			j++;
			count++;
		}
		else if (f_degree[i] > g_degree[j]){  //當f(x)的次方較高時 一樣直接放進去
			result_coef[count] = f_coef[i];
			result_degree[count] = f_degree[i];
			i++;
			count++;
		}
		else{
			result_coef[count] = g_coef[j];  //當g(x)的次方較高時 一樣直接放進去
			result_degree[count] = g_degree[j];
			j++;
			count++;
		}
	}
}

/*減法 加法直接複製過來 改符號而已*/
void sub(int f_degree[], int f_coef[], int g_degree[], int g_coef[], int result_coef[], int result_degree[]){
	int i = 0, j = 0, count = 0;
	while((i <= 2 && j <= 2) == true){
		if (f_degree[i] == g_degree[j]){
			result_coef[count] = f_coef[i] - g_coef[j];
			result_degree[count] = f_degree[i];
			i++;
			j++;
			count++;
		}
		else if (f_degree[i] > g_degree[j]){
			result_coef[count] = f_coef[i];
			result_degree[count] = f_degree[i];
			i++;
			count++;
		}
		else{
			result_coef[count] = g_coef[j];
			result_degree[count] = g_degree[j];
			j++;
			count++;
		}
	}
}

/*乘法*/
void mult(int f_degree[], int f_coef[], int g_degree[], int g_coef[], int result_coef[], int result_degree[]){
	int next = 0;  //next為繼續往下展開
	for (int i = 0 ; i < 3 ; i++){  //兩個迴圈 各三項總共曜...yosoro 算9次
		for (int j = 0 ; j < 3 ; j++){
			result_coef[next] = f_coef[i] * g_coef[j];  //係數相乘
			result_degree[next] = f_degree[i] + g_degree[j];  //次方相加
			next++;
		}
	}
	buble_sort(result_coef, result_degree);  //使用泡沫排序法 由高到低排序
}

int main(){
	string s;
	int result_coef[9], result_degree[9];
	int f_coef[3], g_coef[3];
	int f_degree[3], g_degree[3];

	init(f_coef, f_degree, g_coef, g_degree, result_coef, result_degree);

	cout << "f(x) + g(x) = \n";
	add(f_degree, f_coef, g_degree, g_coef, result_coef, result_degree);
	print_normal(result_coef, result_degree, s);
	

	cout << "f(x) - g(x) = \n";
	sub(f_degree, f_coef, g_degree, g_coef, result_coef, result_degree);
	print_normal(result_coef, result_degree, s);

	cout << "f(x) * g(x) = \n";
	mult(f_degree, f_coef, g_degree, g_coef, result_coef, result_degree);
	print_for_mult(result_coef, result_degree, s);
}

