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
	cout << "���� ũ�� = " << Size1 << '\n';
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "3���� �������� �� �ִ� ����: " << count3 << '\n';
	int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "13���� �������� �� �ִ� ����: " << count13 << "\n\n";
}