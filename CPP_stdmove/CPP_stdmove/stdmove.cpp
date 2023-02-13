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
Useless& Useless::operator=(Useless&& f)
{
	std::cout << "이동 대입 연산자 호출:\n";
	if (this == &f)
		return *this;
	delete[]pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
}
Useless Useless::operator+(const Useless& f)const
{
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	return temp;
}
void Useless::ShowObject() const
{
	std::cout << "매개변수 수: " << n;
	std::cout << "데이터 주소: " << (void*)pc << std::endl;
}
void Useless::ShowData() const
{
	if (n == 0)
		std::cout << "(객체 없음)";
	else
		for (int i = 0; i < n; i++)
			std::cout << pc[i];
	std::cout << std::endl;
}
int main()
{
	using std::cout;
	{
		Useless one(10, 'x');
		Useless two =one + one;
		cout << "객체 one: ";
		one.ShowData();
		cout << "객체 two:";
		two.ShowData();
		Useless three, four;
		cout << "three = one\n";
		three = one;
		cout << "현재 객체 three = ";
		three.ShowData();
		cout << "그리고 객체 one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two;
		cout << "현재 객체 four = ";
		four.ShowData();
		cout << "four = move(one)\n";
		four = std::move(one);
		cout << "현재 객체 four = ";
		four.ShowData();
		cout << "그리고 객체 one =";
		one.ShowData();
	}
}
