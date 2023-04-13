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
AccountQuery() :m_totalBalance(0) {}//初始余额为0
	void readData();//登记
	void showData();//显示
	void WriteRec();//保存
	void readRec();//读取
	void updataRec();//修改
	void exitRec();//注销
	void searchRec();
	void deleteRec();
private:
	char accountNumber[20];//账号
	char m_Name[20];
	char accountPassword[20];
	double m_totalBalance;//余额.
};
