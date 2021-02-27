// advance(), distance() ����

// viter: 10
// liter: 10
// viter: 30
// liter: 30
// viter: 10
// liter: 10
// [vec1.begin(), vec1.end())�� ���� ����: 5
// [lt1.begin(), lt1.end())�� ���� ����: 5

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	auto viter = vec1.begin();
	auto liter = lt1.begin();

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// advance() ����

	// ����� �ݺ����� liter�� advance()�� ���ؼ� `+=` ������ ����
	advance(viter, 2);
	advance(liter, 2);

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// ����� �ݺ����� liter�� advance()�� ���ؼ� `-=` ������ ����
	advance(viter, -2);
	advance(liter, -2);

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// distance() ����
	// ����� �ݺ����� liter�� distance()�� ���ؼ� `-` ������ ����
	cout << "[vec1.begin(), vec1.end())�� ���� ����: " << distance(vec1.begin(), vec1.end()) << endl;
	cout << "[lt1.begin(), lt1.end())�� ���� ����: " << distance(lt1.begin(), lt1.end()) << endl;

	// distance() �Լ��� ��ȯ ������ ��κ� unsigned int Ȥ�� int ������ �ݺ��ڿ� ���� �ٸ���.
	// ��Ȯ�� ǥ���ϸ� �ݺ��� Ư���� difference_type �����̴�. �� ��ȯ Ÿ���� ǥ���� ������ ����.
	iterator_traits<vector<int>::iterator>::difference_type n = distance(lt1.begin(), lt1.end());

	return 0;
}