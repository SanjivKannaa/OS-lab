#include<bits/stdc++.h>
using namespace std;

struct ganttchart{
	int time;
	int pid;
};
struct process{
	int pid, burst_time, arrival_time, waiting_time, turnaround_time;
};

int cmp(struct process p1, struct process p2){
	return p1.arrival_time > p2.arrival_time;
}

int main(){
	// getting input
	struct process p[5];
	for (int i=0;i<5;i++){
		p[i].pid = i+1;
		cout << "bursttime of process P" << i+1 << " = ";
		cin >> p[i].burst_time;
		cout << "arrival time of process P" << i+1 << " = ";
		cin >> p[i].arrival_time;
		p[i].waiting_time = 0;
		p[i].turnaround_time = 0;
		// p[i].remaining_time = p[i].burst_time;
	}
	sort(p, p+5, cmp);
	for (int i=0;i<5;i++){
		cout << p[i].pid << p[i].burst_time << p[i].arrival_time << endl;
	}
	struct ganttchart gc[100];
	int time=0;
	for (int i=0;i<5;i++){
		p[i].waiting_time = max(0, p[i].arrival_time - time);
		time += p[i].waiting_time;
		for (int j=0;j<p[i].burst_time;j++){
			gc[j].pid = p[i].pid;
		}
		p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;

	}
	for (int i=0;i<50;i++){
		cout << i << " - " << i+1 << "\tP" << gc[i].pid << endl;
	}

	
}
