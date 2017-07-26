//将类的成员做模版参数
#include <iostream>
#include <string>

using namespace std;

class Rate
{
	public:
		Rate() {}
		Rate(int t) { m_i = t;}
		~Rate() {}
	public:
		int m_i;
};

template<typename T>
class A
{
	public:
		virtual int setAttr(T &t) = 0;
		virtual T* GetAttr() = 0;
	public:
		T t;
};

template<typename T, int T::*m_i>
class B : public A<T>
{
	public:
		virtual int setAttr(T &t) { t1 = t;}
		virtual T* GetAttr() { return &t1; }
		virtual void GetRate() { cout <<  t1.*m_i << endl; }

	private:
		T t1;

};

int main()
{
	Rate r(35);
	B<Rate, &Rate::m_i> b;
	b.setAttr(r);
	b.GetRate();

	return 0;
}

