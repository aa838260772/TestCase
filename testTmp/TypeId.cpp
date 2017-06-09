#include <typeinfo>
#include <stdint.h>
#include <cxxabi.h>

using namespace std;

class testClass
{
	public:
		testClass(int a) {m_i = a;}
		friend ostream & operator<<(ostream &out, testClass &a){
			out << a.m_i;
			return out;
		}

	private:
		int m_i;

};
	template<typename T1, typename T2>
void DebugPrint(T1 t1, T2 t2)
{
	cout << abi::__cxa_demangle(typeid(t1).name(),NULL,NULL,NULL) << " " << t1 << endl;
	cout << abi::__cxa_demangle(typeid(t2).name(),NULL,NULL,NULL) << " " << t2 << endl;
}

int main()
{
	/*	DebugPrint<int, double>(3, 4);
	 *		DebugPrint(3, 4);
	 *			DebugPrint<double, double>(3, 4);
	 *				DebugPrint<uint64_t, uint32_t>(3, 4);
	 *				*/
	string tt = "hello world";
	DebugPrint<string, int>(tt, 1);

	DebugPrint<string, int>(tt, 1);
	testClass a1(3);
	DebugPrint<testClass, int>(a1, 4);

	return 0;
}

