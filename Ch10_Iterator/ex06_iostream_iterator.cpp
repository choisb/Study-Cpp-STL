// ostream_iterator<T>�� istream_iterator<T> ����

// [��� ���]
// vec1 :1020304050
// vec1 :10, 20, 30, 40, 50,
// lt + v : 110 220 330
// 10 20 30 50 40 80 10^D
// vec2: 10 20 30 50 40 80 10

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	// ostream_iterator<T> ����
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	// ostream_iterator<int>(cout): cout�� ����Ǿ� �����鼭 ������ ����ϴ� �ݺ��ڸ� ����
	cout << "vec1 :";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout));
	cout << endl;

	// ostream_iterator<int>(cout, ", "): cout�� ����Ǿ� �����鼭 ������ ����ϴ� �ݺ��ڸ� ����. ��� �� ������ ", "�� ����.
	cout << "vec1 :";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	list<int> lt;
	lt.push_back(100);
	lt.push_back(200);
	lt.push_back(300);

	//transform(b, e, b2, t, f)��
	// ���� [b, e) �������� [b2, b2+(e-b))�� �������� �ݺ��ڸ� p, q�� �Ҷ� f(*p, *q)�� ����
	// ������ [t, t+(e-b))�� �����Ѵ�.
	cout << "lt + v : ";
	transform(lt.begin(), lt.end(), vec1.begin(), ostream_iterator<int>(cout, " "), plus<int>());
	cout << endl;


	// istream_iterator<T> ����
	// ǥ�� �Է� ��Ʈ������ ������ �Է¹޾� vec2�� �����ϴ� ����

	vector<int> vec2;

	// istream_iterator<int>(cin): ǥ�� �Է� ��Ʈ���� ����� �ݺ��ڸ� ����
	// istream_iterator<int>(): �Է� ��Ʈ���� �� �ݺ��ڸ� ����
	// end-of-file (Ctrl+D)�� �Էµɶ� ���� ������ �Է¹���
	// back_inserter<vector<int>>(vec2): vec2�� push_back() ��� �Լ��� ȣ���ϴ� ���� �ݺ��ڸ� ����
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(vec2));
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}



