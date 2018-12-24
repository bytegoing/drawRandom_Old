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
	cout << "�������...     ";
	freopen("seen.in", "w", stdout);
	cout << "0";
	freopen("CON", "w", stdout);
	for(int i = 1; i<= seenNum;i++) {
		p[i].ifAsked = false;
	}
	seenNum = 0;
	cout << "������!" << endl;
}

int randomNum(int range) {
	srand(time(0));
	return rand()%allNum;
}

void chouqian() {
	if(seenNum == allNum - 1) {
		cout << "ȫ���Ѿ���ȡ���...   ";
		cleanHaveSeen();
	}
	string NM;
	int NUM = randomNum(allNum);
	while(NUM == 0 || NUM > allNum-1 || p[NUM].ifAsked) {
		NUM = randomNum(allNum);
	}
	cout << "���ڳ�ȡ..." << endl;
	p[NUM].ifAsked = true;
	NM = p[NUM].name;
	seenNum++;
	cout << NUM << "��, ����: " << NM << " ����ȡ" << endl;
	
}

void sae() {
	cout << "����....   ";
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
	cout << "�˳�!" << endl;
	system("pause");
	exit(0);
}

void waitIt() {
	cout << "���������(1:������ǩ;2:���沢�˳�;3:����ѳ����,4:�����沢�˳�): ";
	int caozuo;
	scanf("%d", &caozuo);
	cout << endl;
	while(caozuo != 1 && caozuo != 2 && caozuo != 3 && caozuo != 4) {
		cout << "�������,����������." << endl;
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
			cout << "�ޱ��������˳�..." << endl;
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
	cout << "���ڳ�ʼ��..." << endl;
	cout << "���ڵ�������..." << endl;
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
	cout << "���ڶ�ȡ�Ѿ��������..." << endl;
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
	cout << "��ʼ���ɹ�!������" << allNum - 1 << "�ˣ��Ѿ����ʵ���" << seenNum << "�ˡ�" << endl;
	system("pause");
	system("cls");
	while(1) {
		waitIt();
	}
	return 0;
}
