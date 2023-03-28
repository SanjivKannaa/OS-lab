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
	p[0].size = 100;
	p[1].size = 450;
	p[2].size = 250;
	p[3].size = 300;
	p[4].size = 600;
	p[0].status = 0;
	p[1].status = 0;
	p[2].status = 0;
	p[3].status = 0;
	p[4].status = 0;
	cout << "FIRST-FIT ALGORITHM" << endl;
	cout << "212K goes into partition: " << first_fit(212) << endl;
	cout << "317K goes into partition: " << first_fit(317) << endl;
	cout << "172K goes into partition: " << first_fit(172) << endl;
	cout << "426K goes into partition: " << first_fit(426) << endl;
	for(int i=0;i<5;i++){
		p[i].status=0;
	}
	cout << "BEST-FIT ALGORITHM" << endl;
	cout << "212K goes into partition: " << best_fit(212) << endl;
	cout << "317K goes into partition: " << best_fit(317) << endl;
	cout << "172K goes into partition: " << best_fit(172) << endl;
	cout << "426K goes into partition: " << best_fit(426) << endl;
	for(int i=0;i<5;i++){
		p[i].status=0;
	}
	cout << "WORST-FIT ALGORITHM" << endl;
	cout << "212K goes into partition: " << worst_fit(212) << endl;
	cout << "317K goes into partition: " << worst_fit(317) << endl;
	cout << "172K goes into partition: " << worst_fit(172) << endl;
	cout << "426K goes into partition: " << worst_fit(426) << endl;
}