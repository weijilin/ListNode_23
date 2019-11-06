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

	// ����ʧ�ܣ�N1+N2���ʽ�Ľ���ڱ����ڼ��޷�ȷ������
	// ֻ�еȵ����������ڼ����ȷ�ϣ��൱���ڱ����ڼ��array��ʵ����ʧ��
	//bite::array<int, N1+N2> a;
	bite::array<int, 10 + 20> a;
	a[0] = 10;
	return 0;
}
#endif

#if 0
// Max�������ڶ������Ϳ���û�����⣬���Ƕ��ڸ������ʹ���ʱ���ܻ�õ�
// ����������Max����ģ����������ͽ������⴦��
template<class T>
T& Max(T& left, T& right)
{
	if (left > right)
		return left;

	return right;
}


// Max����ģ�����char*���ʹ�������
// Max����ģ���char*�������⻯����---�ػ�

// �ػ���ǰ�᣺��������һ������ģ��--->���������������Ҫ�ػ�
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


// һ���������ģ�岻��Ҫ�ػ���ֱ��д�������Ͷ�Ӧ�ĺ���
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



// Max����ģ�����char*���ʹ�������
// Max����ģ���char*�������⻯����---�ػ�

// �ػ���ǰ�᣺��������һ������ģ��--->���������������Ҫ�ػ�
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
// ��ģ����ػ���ȫ�ػ� �� ƫ�ػ�
// ȫ�ػ�: ��ģ������б������е�����ȫ���ػ�
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

// �����Data��ģ�尴��int��double�ķ�ʽ������ʵ����
// �������ͻ�ʹ���ػ��İ汾��������ʹ����ģ��
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

// ƫ�ػ���1. �����ػ�  2. �����͸���ϸ�Ķ���
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

// ���Data��ģ����ʵ�����ڼ䣬ֻҪ�ڶ�����������int��ʽ����ʵ�������ͻ�ִ���ػ��İ汾
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
