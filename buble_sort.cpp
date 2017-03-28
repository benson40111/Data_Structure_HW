#include<iostream>
using namespace std;

int main(){
   int a[999], n, temp;
   cin >> n;
   for (int i = 0 ; i < n ; i++)
       cin >> a[i];
   /*for (int j = 0 ; j < n ; j++)
    cout << a[j] << endl; */
   for (int i = 0 ; i < n-1 ; i++)
   {
       for (int j = i+1 ; j< n ; j++)
       {
        if (a[j] <  a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
       }
   }
   
   while (n--){cout << a[n] << " ";}
   cout << "\n";
   return 0;
}//
