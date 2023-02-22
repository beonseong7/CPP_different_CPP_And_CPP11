#include<iostream>
#include<string>
#include "boost/lexical_cast.hpp"
int main()
{
	using namespace std;
	cout << "몸무게를 입력하세요: ";
	float weight;
	cin >> weight;
	string gain = "10% 증가하면";
	string wt = boost::lexical_cast<string>(weight);
	gain = gain + wt + "이 ";
	weight = 1.1 * weight;
	gain = gain + boost::lexical_cast<string>(weight) + "이 됩니다";
	cout << gain << endl;
	return 0;
}