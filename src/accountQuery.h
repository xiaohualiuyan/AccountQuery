#pragma once
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;
using std::cerr;
class AccountQuery
{
public:
AccountQuery() :m_totalBalance(0) {}//��ʼ���Ϊ0
	void readData();//�Ǽ�
	void showData();//��ʾ
	void WriteRec();//����
	void readRec();//��ȡ
	void updataRec();//�޸�
	void exitRec();//ע��
	void searchRec();
	void deleteRec();
private:
	char accountNumber[20];//�˺�
	char m_Name[20];
	char accountPassword[20];
	double m_totalBalance;//���.
};
