#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;
bool f3(int x) {return x %13 == 0;}
bool f13(int x) { return x % 13 == 0; }
int main()
{
	using std::cout;
	std::vector<int> numbers(Size1);
	std::srand(std::time(0));
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "샘플 크기 = " << Size1 << '\n';
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "3으로 나누어질 수 있는 개수: " << count3 << '\n';
	int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "13으로 나누어질 수 있는 개수: " << count13 << "\n\n";
	numbers.resize(Size2);
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "Sample size = " << Size2 << '\n';
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) :dv(d) {}
		bool operator()(int x) { return x % dv == 0; }
	};
	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "3으로 나누어질 수 있는 개수: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "13으로 나누어질수 있는 개수: " << count13 << "\n\n";
	numbers.resize(Size3);
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "샘플 크기 = " << Size3 << '\n';
	count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "3으로 나누어질 수 있는 개수: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13 == 0; });
	cout << "13으로 나누어질 수있는 개수: " << count13 << '\n';
	return 0;

}