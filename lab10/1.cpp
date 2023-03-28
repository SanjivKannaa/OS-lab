#include<bits/stdc++.h>
using namespace std;

struct partition{
	int size, status;
}p[5];

int first_fit(int x){
	for(int i=0;i<5;i++){
		if (p[i].status == 0 && p[i].size>=x){
			p[i].status=1;
			return i+1;
		}
	}
	return -1;
}

bool cmp1(struct partition p1, struct partition p2){
	return p1.size<p2.size;
}

int best_fit(int x){
	sort(p, p+5, cmp1);
	for(int i=0;i<5;i++){
		if (p[i].status == 0 && p[i].size>=x){
			p[i].status=1;
			return i+1;
		}
	}
	return -1;
}

bool cmp2(struct partition p1, struct partition p2){
	return p1.size>p2.size;
}

int worst_fit(int x){
	sort(p, p+5, cmp2);
	for(int i=0;i<5;i++){
		if (p[i].status == 0 && p[i].size>=x){
			p[i].status=1;
			return i+1;
		}
	}
	return -1;
}

int main(){
	p[0].size = 300;
	p[1].size = 650;
	p[2].size = 450;
	p[3].size = 500;
	p[4].size = 800;
	p[0].status = 0;
	p[1].status = 0;
	p[2].status = 0;
	p[3].status = 0;
	p[4].status = 0;
	cout << "FIRST-FIT ALGORITHM" << endl;
	cout << "412K goes into partition: " << first_fit(412) << endl;
	cout << "517K goes into partition: " << first_fit(517) << endl;
	cout << "372K goes into partition: " << first_fit(372) << endl;
	cout << "626K goes into partition: " << first_fit(626) << endl;
	for(int i=0;i<5;i++){
		p[i].status=0;
	}
	cout << "BEST-FIT ALGORITHM" << endl;
	cout << "412K goes into partition: " << best_fit(412) << endl;
	cout << "517K goes into partition: " << best_fit(517) << endl;
	cout << "372K goes into partition: " << best_fit(372) << endl;
	cout << "626K goes into partition: " << best_fit(626) << endl;
	for(int i=0;i<5;i++){
		p[i].status=0;
	}
	cout << "WORST-FIT ALGORITHM" << endl;
	cout << "412K goes into partition: " << worst_fit(412) << endl;
	cout << "517K goes into partition: " << worst_fit(517) << endl;
	cout << "372K goes into partition: " << worst_fit(372) << endl;
	cout << "626K goes into partition: " << worst_fit(626) << endl;
}