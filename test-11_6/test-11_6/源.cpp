#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <assert.h>

namespace bite
{
	template<class T, size_t N>
	class array
	{
	public:
		T& operator[](size_t index)
		{
			//N = 100;
			assert(index < N);
			return _arr[index];
		}

	private:
		T _arr[N];
		size_t _size;
	};
}


int main()
{
	int N1 = 10;
	int N2 = 20;

	// 编译失败：N1+N2表达式的结果在编译期间无法确认其结果
	// 只有等到代码运行期间才能确认，相当于在编译期间对array的实例化失败
	//bite::array<int, N1+N2> a;
	bite::array<int, 10 + 20> a;
	a[0] = 10;
	return 0;
}
#endif

#if 0
// Max函数对于多数类型可能没有问题，但是对于个别类型处理时可能会得到
// 错误结果，让Max函数模板对特殊类型进行特殊处理
template<class T>
T& Max(T& left, T& right)
{
	if (left > right)
		return left;

	return right;
}


// Max函数模板对于char*类型处理有误
// Max函数模板对char*进行特殊化处理---特化

// 特化的前提：必须先有一个函数模板--->针对于那种类型需要特化
template<>
char*& Max<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}


int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;
	cout << Max(b, a) << endl;

	char* p2 = "world";
	char* p1 = "hello";

	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
T& Max(T& left, T& right)
{
	if (left > right)
		return left;

	return right;
}


// 一般情况函数模板不需要特化，直接写出该类型对应的函数
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}


int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;
	cout << Max(b, a) << endl;

	char* p2 = "world";
	char* p1 = "hello";

	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
const T& Max(const T& left, const T& right)
{
	if (left > right)
		return left;

	return right;
}



// Max函数模板对于char*类型处理有误
// Max函数模板对char*进行特殊化处理---特化

// 特化的前提：必须先有一个函数模板--->针对于那种类型需要特化
template<>
const char*& Max<const char*>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}


int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;
	cout << Max(b, a) << endl;

	const char* p2 = "world";
	const char* p1 = "hello";
	//p1[0] = 'H';

	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
// 类模板的特化：全特化 、 偏特化
// 全特化: 将模板参数列表中所有的类型全部特化
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

// 如果将Data类模板按照int和double的方式来进行实例化
// 编译器就会使用特化的版本，而不会使用类模板
template<>
class Data<int, double>
{
public:
	Data()
	{
		cout << "Date(int, double)" << endl;
	}
private:
	int _d1;
	double _d2;
};

int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	return 0;
}
#endif

// 偏特化：1. 部分特化  2. 对类型更详细的定义
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

// 如果Data类模板在实例化期间，只要第二个参数按照int方式进行实例化，就会执行特化的版本
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}

private:
	T1 _d1;
	int _d2;
};


int main()
{
	Data<double, int> d1;
	Data<char, int> d2;
	Data<int, short> d3;
	return 0;
}
