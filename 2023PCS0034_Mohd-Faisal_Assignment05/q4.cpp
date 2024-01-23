#include <iostream>
#include <algorithm>
using namespace std;
int main() {
 int n;
 cout << "Enter number of processes: ";
 cin >> n;
 int* finish = new int[n];
 int** maxi = new int*[n];
 int** alloc = new int*[n];
 int** need = new int*[n];
 int work[3] = {3, 2, 2};
 for (int i = 0; i < n; i++) {
 maxi[i] = new int[3];
 cout << "Enter 1st resource required for process " << i << ": ";
 cin >> maxi[i][0];
 cout << "Enter 2nd resource required for process " << i << ": ";
 cin >> maxi[i][1];
 cout << "Enter 3rd resource required for process " << i << ": ";
 cin >> maxi[i][2];
 }
 for (int i = 0; i < n; i++) {
 alloc[i] = new int[3];
 cout << "Enter 1st resource allocated for process " << i << ": ";
 cin >> alloc[i][0];
 cout << "Enter 2nd resource allocated for process " << i << ": ";
 cin >> alloc[i][1];
 cout << "Enter 3rd resource allocated for process " << i << ": ";
 cin >> alloc[i][2];
 }
 for (int i = 0; i < n; i++) {
 need[i] = new int[3];
 for (int j = 0; j < 3; j++) {
 need[i][j] = maxi[i][j] - alloc[i][j];
 }
 }
 int i = 0;
 int j = 0;
 while (j < 3 * n && (std::find(finish, finish + n, 0) != finish + n)) {
 int flag = 0;
 j++;
 if (need[i][0] <= work[0] && need[i][1] <= work[1] && need[i][2] <= work[2]) {
 work[0] += alloc[i][0];
 work[1] += alloc[i][1];
 work[2] += alloc[i][2];
 finish[i] = 1;
 flag = 1;
 i = (i + 1) % n;
 }
 if (flag == 0) {
 i = (i + 1) % n;
 }
 }
 int nflag = 0;
 for (int i = 0; i < n; i++) {
 if (finish[i] == 0) {
 nflag = 1;
 break;
 }
 }
 if (nflag == 0) {
 cout << "System is in safe state" << endl;
 } else {
 cout << "System is in deadlock" << endl;
 }
 // Free allocated memory
 delete[] finish;
 for (int i = 0; i < n; i++) {
 delete[] maxi[i];
 delete[] alloc[i];
 delete[] need[i];
 }
 delete[] maxi;
 delete[] alloc;
 delete[] need;
 return 0;
}