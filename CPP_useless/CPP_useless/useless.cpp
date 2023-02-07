#include<iostream>
using namespace std;
class Useless
{
private:
	int n;
	char* pc;
	static int ct;
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless& f);
	Useless(Useless&& f);
	~Useless();
	Useless operator+(const Useless& f)const;
	void ShowData() const;
};
int Useless::ct = 0;
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "�⺻ ������ ȣ��; ��ü��: " << ct << endl;
	ShowObject();
}
Useless::Useless(int k) : n(k)
{
	++ct;
	cout << "int ������ ȣ��; ��ü ��: " << ct << endl;
	pc = new char[n];
	ShowObject();
}
Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	cout << "int, char ������ ȣ��; ��ü ��: " << ct
		<< endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	ShowObject();
}
Useless::Useless(const Useless& f) :n(f.n)
{
	++ct;
	cout << "���� const ȣ��: ��ü ��: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	ShowObject();
}
Useless::Useless(Useless&& f) :n(f.n)
{
	++ct;
	cout << "�̵� ������ ȣ��; ��ü ��: " << ct << endl;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
	ShowObject();
}
