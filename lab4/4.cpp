// Create 3 processes (parent, child process, grandchild) and 2 pipes. Child process read N integers and puts in to the pipe1 then Parent process reads those integers from pipe1 and display the prime numbers only and child process put all odd numbers in pipe2 and grandchild process reads all odd numbers from pipe2 and finds the sum of those numbers.

#include<bits/stdc++.h>
using namespace std;


bool check_prime(int n) {
  bool is_prime = true;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}


int main(){
	int pl1[2];
	int pl2[2];
	int pid;
	if (pipe(pl1) == -1 || pipe(pl2) == -1){
		return 0;
	}
	pid = fork();
	int n=6;
	int data[n];
	if (pid==0){
		//child
		close(pl1[0]);
		close(pl2[0]);
		for (int i=0;i<n;i++){
			cin >> data[i];
		}
		write(pl1[1], data, n);
		close(pl1[1]);
		int odd_arr[n];
		int length = 0;
		for (int i=0;i<n;i++){
			if (data[n]%2 != 0){
				odd_arr[length++] = data[i];
			}
		}
		write(pl2[1], );
		write(pl2[1], odd_arr, length);
		close(pl2[1]);
		int pid2;
		pid2 = fork();
		if (pid2==0){
			// grandchild
			close(pl1[1]);
			close(pl1[0]);
			close(pl2[1]);
			read(pl2[0], odd_arr, length);
			for (int i=0;i<length;i++){
				cout << odd_arr[i] << " ";
			}
			cout << "i am grandchild";
			close(pl2[0]);
		}
		
	}else{
		//parent
		int data1[n];
		close(pl2[0]);
		close(pl2[1]);
		close(pl1[1]);
		read(pl1[0], data, n);
		for (int i=0;i<n;i++){
			if (check_prime(i)==true){
				cout << i << " ";
			}
		}
		cout << "i am parent" << endl;
		close(pl1[0]);
	}
}
