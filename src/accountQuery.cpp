#include"accountQuery.h"
/*
AccountQuery() :m_totalBalance(0) {}//初始余额为0
	void readData();//登记
	void showData();//显示
	void WriteRec();//保存
	void updataRec();//修改
	void putRec();//入账
	void outRec();//出账
*/

void AccountQuery::readData() 
{
	cout << "Enter your accountNumber:";
	cin >> accountNumber;
	cout << "Enter your password:";
	cin >> accountPassword;
	cout << "Enter your name:";
	cin >> m_Name;
	cout << endl;
}
void AccountQuery::showData() 
{
	cout << "your accountNumber:" << accountNumber<<endl;
	cout << "your password:" << accountPassword<<endl;
	cout << "your name:" << m_Name<<endl;
	cout << "your balance:" << m_totalBalance<<endl;
	cout << "--------------------"<<endl;
}

void AccountQuery::WriteRec()//保存.
{
	ofstream ofs("record.bank",ios::out|ios::app);
	if (!ofs)
	{
		cerr << "open error!" << endl;
		abort();
	}
	readData();
	ofs.write((char*)(this), sizeof(*this));
	ofs.close();
}
void AccountQuery::readRec()
{
	ifstream ifs("record.bank", ios::binary|ios::in);
	if (!ifs)
	{
		cerr << "open error!" << endl;
		abort();
	}
	cout << "\n********Data From File*************\n";
	cout << "--------------------\n";
	while (!ifs.fail())
	{
if(ifs.read((char*)(this), sizeof(*this)))showData();
	}
	ifs.close();
}
void AccountQuery::updataRec()
{
	int n,count;
	fstream iofs("record.bank", ios::in|ios::out | ios::binary);
	if (!iofs.is_open())
	{
		cerr << "open error!" << endl;
		abort();
	}
	iofs.seekg(0, ios::end);
	count = (int)iofs.tellg() / sizeof(*this);
	if (count == 0)abort();
	cout << "\nThere are " << count << " Number\n";
	cout << "\nEnter Updata Number:";
	cin >> n;
	cout << "\nBefore Updata:\n";
	iofs.seekg(static_cast<int64_t>(n - 1) * sizeof(*this));
	iofs.read((char*)this, sizeof(*this));
	showData();
	cout << "\nAfter Updata:\n";
	readData();
	iofs.seekp(static_cast<int64_t>(n - 1) * sizeof(*this));
	iofs.write((char*)this, sizeof(*this));
	iofs.close();
}

void AccountQuery::exitRec()
{
	ofstream ofs("record.bank",ios::out);
	ofs.clear();
}

void AccountQuery::searchRec()
{
	ifstream ifs("record.bank", ios::in | ios::binary);
	if (!ifs)
	{
		cerr << "open error!" << endl;
		abort();
	}
	int n,count;
	ifs.seekg(0, ios::end);
	count = (int)ifs.tellg() / sizeof(*this);
	cout << "\n There are " << count << " Records in File\n";
	cout << "\nEnter Record Number:";
	cin >> n;
	cout << endl;
	if (n <= count) {
		ifs.seekg(static_cast<int64_t>(n - 1) * sizeof(*this));
		ifs.read((char*)this, sizeof(*this));
		showData();
	}
	else cout << "Record Data Not Exist.\n";
}

void AccountQuery::deleteRec()
{
	int n,count;
	ifstream ifs("record.bank", ios::in | ios::binary);
	ofstream ofs("replace.bank", ios::out | ios::binary);
	if (!ifs)
	{
		cerr << "open error!" << endl;
		abort();
	}
	ifs.seekg(0, ios::end);
	count = (int)ifs.tellg() / sizeof(*this);
	cout << "\n There are " << count << " Records in File\n";
	cout << "\n Enter record Number to Delect:";
	cin >> n;
	ifs.seekg(0, ios::beg);
	for(int i=0;i<count;i++)
	{
		ifs.read((char*)this, sizeof(*this));
		if (i == n - 1)continue;
		ofs.write((char*)this, sizeof(*this));
	}
	ifs.close();
	ofs.close();
	remove("record.bank");
	rename("replace.bank", "record.bank");
}
