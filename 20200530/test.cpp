#include <iostream>
using namespace std;

void test() {
	//malloc:只进行空间申请,不进行初始化
	int* ptr = (int*)malloc(sizeof(int));
	//calloc:空间申请 + 零初始化
	int* ptr1 = (int*)calloc(1, sizeof(int));
	//realloc:第一个参数为nullptr时,等价于realloc
	int* ptr2 = (int*)realloc(nullptr, sizeof(int));
	//调整空间大小
	//1.直接原地调整大小
	//2.重新开空间: 空间申请,内容拷贝,原有空间释放
	int* ptr3 = (int*)realloc(ptr, sizeof(int) * 4);

	free(ptr);
	free(ptr1);
	free(ptr2);
	free(ptr3); // 如果是重新开空间,则存在内存二次释放
}

void test1() {
	//申请空间
	//单个类型的空间:new + 类型
	//连续类型空间: new + 类型[个数]
	//单个空间类型申请 + 初始化:new +类型 (初始值)
	//基本类型申请连续空间,不能初始化
	int* ptr4 = new (int);
	int* ptr5 = new int[10];
	//释放空间
	//单个空间: delete 指针
	//连续空间: delete [] 指针
	//申请和释放空间的方式必须匹配: malloc+free,new+delete,new[] + delete[]
	delete ptr4;
	delete [] ptr5;
}

class Date {
public:    
	Date(int year = 2210) 
		: _year(year)
		{}
private:
	int _year;
};
void test2() {
	//动态创建自定义类型的对象
	//new : 动态开空间 + 调用构造函数初始化
	//申请单个空间: new + 类型(初始化对象)
	Date* pd1 = new Date(2012);
	Date* pd2 = new Date;  //调用默认构造函数 : 无参 全缺省
	//申请连续的空间: new + 类型[个数]  自动调用默认构造函数,如果没有默认构造函数,则编译器报错
	Date* pd3 = new Date[10];

	//释放自定义类型的空间
	//释放单个空间:delete 指针
	delete pd1;
	delete pd2;
	//释放连续空间:delete [] 指针
	delete[] pd3;
}

void test3() {
	//operator new: 不是运算符重载函数,而是一个全局函数
	            //: 使用方式和malloc类似
	            //: 封装 malloc+异常
	//new的执行过程(自定义类型) : operator new --> malloc --> 构造函数
	char* ptr = (char*)operator new(sizeof(char));
	char* ptr2 = (char*)malloc(sizeof(char));
	//operator delete: 不是运算符重载函数,而是一个全局函数
			       //: 使用方式和free类似
			       //: 封装 free
	//delete的执行过程(自定义类型) : 析构函数 --> operator delete --> free
	operator delete(ptr);
	free(ptr2);
}

void test4()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	//new定位表达式： new (地址) 类型(参数列表)
	//	：在已经开好的空间上显式调用构造函数
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}
int main() {

	system("pause");
	return 0;
}