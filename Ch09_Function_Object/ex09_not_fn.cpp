// 부정자 not1, not2는 C++17부터 삭제됨.
// not_fn()가 이 둘을 대체함
// 사용 예제

#include <iostream>
#include <functional>
using namespace std;

int main()
{
	less<int> oLess;

	//not2 사용
	// C++17 이전
	//binary_negate<less<int>> negate = not2(less<int>());
	//cout << negate(05, 10)<< not2(oLess) (05, 10) << ':' << not2(less<int>())(05, 10) << endl; // 모두 같다
	//cout << negate(05, 10)<< not2(oLess) (10, 10) << ':' << not2(less<int>())(10, 10) << endl; // 모두 같다
	//cout << negate(05, 10)<< not2(oLess) (20, 10) << ':' << not2(less<int>())(20, 10) << endl; // 모두 같다


	// C++17 이후
	auto negate = not_fn(less<int>()); // 임시객체는 왜 안됨??
	cout << negate(05, 10) << ':' << not_fn(oLess) (05, 10) << ':' << not_fn(less<int>())(05, 10) << endl; // 모두 같다
	cout << negate(10, 10) << ':' << not_fn(oLess) (10, 10) << ':' << not_fn(less<int>())(10, 10) << endl; // 모두 같다
	cout << negate(20, 10) << ':' << not_fn(oLess) (20, 10) << ':' << not_fn(less<int>())(20, 10) << endl; // 모두 같다

	//not1 사용
	// C++17 이전
	//binder2nd<less<int>> binder = bind2nd(less<int>(), 10);
	//unary_negate<binder2nd<less<int>>> negate = not1(binder);
	//cout << negate(05) << ':' << not1(binder) (05) << ':' << not1(bind2nd(less<int>(), 10)) (05) << endl; // 모두 같다 
	//cout << negate(10) << ':' << not1(binder) (10) << ':' << not1(bind2nd(less<int>(), 10)) (10) << endl; // 모두 같다
	//cout << negate(20) << ':' << not1(binder) (20) << ':' << not1(bind2nd(less<int>(), 10)) (20) << endl; // 모두 같다

	// C++17 이후
	auto binder = bind(less<int>(), placeholders::_1, 10);
	auto negate2 = not_fn(binder);
	cout << negate2(05) << ':' << not_fn(binder) (05) << ':' << not_fn(bind(less<int>(), placeholders::_1, 10))(05) << endl;
	cout << negate2(10) << ':' << not_fn(binder) (10) << ':' << not_fn(bind(less<int>(), placeholders::_1, 10))(10) << endl;
	cout << negate2(20) << ':' << not_fn(binder) (20) << ':' << not_fn(bind(less<int>(), placeholders::_1, 10))(20) << endl;

	return 0;
}