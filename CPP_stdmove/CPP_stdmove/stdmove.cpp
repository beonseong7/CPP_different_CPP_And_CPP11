#include<iostream>
#include<utility>

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
	Useless(const Useless& f);;
	Useless(Useless&& f);
	~Useless();
	Useless operator+(const Useless& f) const;
	Useless& operator=(const Useless& f);
	Useless& operator =(Useless&& f);
	void ShowData() const;
};
int Useless::ct = 0;
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
}
Useless::Useless(int k) : n(k)
{
	++ct;
	pc = new char[n];
}
Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i ++ )
		pc[i] = ch;
}
Useless::Useless(const Useless& f) : n(f.n)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}
Useless::Useless(Useless&& f) :n(f.n)
{
	++ct;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
}
Useless::~Useless()
{
	delete[]pc;
}
Useless& Useless::operator=(const Useless& f)
{
	std::cout << "복사 대입 연산자 호출:\n";
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	return *this;
}