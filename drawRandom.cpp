#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std; 

#define MAXN 100005

int allNum = 1;
int seenNum = 0;
string nm;

struct people{
	string name;
	bool ifAsked;
}p[MAXN];

void cleanHaveSeen() {
	cout << "正在清除...     ";
	freopen("seen.in", "w", stdout);
	cout << "0";
	freopen("CON", "w", stdout);
	for(int i = 1; i<= seenNum;i++) {
		p[i].ifAsked = false;
	}
	seenNum = 0;
	cout << "清除完毕!" << endl;
}

int randomNum(int range) {
	srand(time(0));
	return rand()%allNum;
}

void chouqian() {
	if(seenNum == allNum - 1) {
		cout << "全部已经抽取完毕...   ";
		cleanHaveSeen();
	}
	string NM;
	int NUM = randomNum(allNum);
	while(NUM == 0 || NUM > allNum-1 || p[NUM].ifAsked) {
		NUM = randomNum(allNum);
	}
	cout << "正在抽取..." << endl;
	p[NUM].ifAsked = true;
	NM = p[NUM].name;
	seenNum++;
	cout << NUM << "号, 姓名: " << NM << " 被抽取" << endl;
	
}

void sae() {
	cout << "保存....   ";
	freopen("seen.in", "w", stdout);
	cout << "0";
	freopen("seen.in", "w", stdout);
	cout << seenNum << endl;
	for(int i = 1;i <= allNum;i++) {
		if(p[i].ifAsked) {
			cout << i << endl;
		} 
	}
	freopen("CON", "w", stdout);
	cout << "退出!" << endl;
	system("pause");
	exit(0);
}

void waitIt() {
	cout << "请输入操作(1:继续抽签;2:保存并退出;3:清除已抽过的,4:不保存并退出): ";
	int caozuo;
	scanf("%d", &caozuo);
	cout << endl;
	while(caozuo != 1 && caozuo != 2 && caozuo != 3 && caozuo != 4) {
		cout << "输入错误,请重新输入." << endl;
		scanf("%d", &caozuo);
	}
	switch(caozuo) {
		case 1:
			chouqian();
			break;
		case 2:
			sae();
			break;
		case 3:
			cleanHaveSeen();
			break;
		case 4:
			cout << "无保存正在退出..." << endl;
			system("pause");
			exit(0);
			break;
	}
}

int main() {
	system("@echo off");
	cout << "drawRandom V1.0" << endl;
	cout << "Powered by C++" << endl;
	cout << "2018.12 BYTEGOING" << endl;
	cout << "正在初始化..." << endl;
	cout << "正在导入姓名..." << endl;
	freopen("names.in", "r", stdin);
	nm = "";
	cin >> nm;
	while(!nm.empty()) {
		p[allNum].name = nm;
		p[allNum].ifAsked = false;
		nm = "";
		cin >> nm;
		allNum++;
	}
	cout << "正在读取已经抽过名单..." << endl;
	freopen("seen.in", "r", stdin);
	scanf("%d", &seenNum);
	int temp;
	cout << "[ ";
	for(int i = 0;i < seenNum;i++) {
		scanf("%d", &temp);
		p[temp].ifAsked = true;
		cout << p[temp].name << " ";
	}
	cout << "]" << endl;
	freopen("CON", "r", stdin);
	cout << "初始化成功!共导入" << allNum - 1 << "人，已经提问的有" << seenNum << "人。" << endl;
	system("pause");
	system("cls");
	while(1) {
		waitIt();
	}
	return 0;
}
