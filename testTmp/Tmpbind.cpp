#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;
template<typename _Res, typename... _ArgTypes>
class myMod
{
	typedef std::function<_Res(_ArgTypes...)> HandleFunc;
	public:
	myMod(){}
	virtual ~myMod(){}
	void SetHandle(HandleFunc handler) { myhandler = handler;}
	_Res Handle(_ArgTypes... args) { myhandler(args...); }
	private:
	HandleFunc myhandler;
};

int single(int a)
{
	return a;
}

int sum(int a, int b)
{
	return a+b;
}

class test
{
	public:
		double testFunc(int a,int b){ return 0.01*a*b; }
};

int main()
{
	myMod< int, int > m1;
	m1.SetHandle(&single);
	cout << m1.Handle(2) << endl;

	myMod< int, int, int > m2;
	m2.SetHandle(&sum);
	cout << m2.Handle(4,8) << endl;

	test t1;
	myMod<double, int, int> m3;
	m3.SetHandle(std::bind(&test::testFunc,&t1,_1,_2));
	cout << m3.Handle(4,9) << endl;

	return 0;
}

