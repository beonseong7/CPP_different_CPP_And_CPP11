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