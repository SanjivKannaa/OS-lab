// create process as per the following hierarchy and print their pid and parent pid

#include<bits/stdc++.h>
#include<sys/wait.h>
using namespace std;

int main(){
	int pid;
	cout << "P1 => pid=" << getpid() << " and ppid=" << getppid() << endl;
	pid = fork();
	if (pid==0){
		cout << "P2 => pid=" << getpid() << " and ppid=" << getppid() << endl;
		int pid2;
		pid2 = fork();
		if (pid2==0){
			cout << "P4 => pid=" << getpid() << " and ppid=" << getppid() << endl;
		}
	}else{
		wait(NULL);
		int pid3;
	       	pid3 = fork();
    		if (pid3==0){
			cout << "P3 => pid=" << getpid() << " and ppid=" << getppid() << endl;
			int pid4;
			pid4 = fork();
			if (pid4==0){
				cout << "P5 => pid=" << getpid() << " and ppid=" << getppid() << endl;
			}
		}
	}

}
