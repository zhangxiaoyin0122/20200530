#include <iostream>
using namespace std;

void test() {
	//malloc:ֻ���пռ�����,�����г�ʼ��
	int* ptr = (int*)malloc(sizeof(int));
	//calloc:�ռ����� + ���ʼ��
	int* ptr1 = (int*)calloc(1, sizeof(int));
	//realloc:��һ������Ϊnullptrʱ,�ȼ���realloc
	int* ptr2 = (int*)realloc(nullptr, sizeof(int));
	//�����ռ��С
	//1.ֱ��ԭ�ص�����С
	//2.���¿��ռ�: �ռ�����,���ݿ���,ԭ�пռ��ͷ�
	int* ptr3 = (int*)realloc(ptr, sizeof(int) * 4);

	free(ptr);
	free(ptr1);
	free(ptr2);
	free(ptr3); // ��������¿��ռ�,������ڴ�����ͷ�
}

void test1() {
	//����ռ�
	//�������͵Ŀռ�:new + ����
	//�������Ϳռ�: new + ����[����]
	//�����ռ��������� + ��ʼ��:new +���� (��ʼֵ)
	//�����������������ռ�,���ܳ�ʼ��
	int* ptr4 = new (int);
	int* ptr5 = new int[10];
	//�ͷſռ�
	//�����ռ�: delete ָ��
	//�����ռ�: delete [] ָ��
	//������ͷſռ�ķ�ʽ����ƥ��: malloc+free,new+delete,new[] + delete[]
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
	//��̬�����Զ������͵Ķ���
	//new : ��̬���ռ� + ���ù��캯����ʼ��
	//���뵥���ռ�: new + ����(��ʼ������)
	Date* pd1 = new Date(2012);
	Date* pd2 = new Date;  //����Ĭ�Ϲ��캯�� : �޲� ȫȱʡ
	//���������Ŀռ�: new + ����[����]  �Զ�����Ĭ�Ϲ��캯��,���û��Ĭ�Ϲ��캯��,�����������
	Date* pd3 = new Date[10];

	//�ͷ��Զ������͵Ŀռ�
	//�ͷŵ����ռ�:delete ָ��
	delete pd1;
	delete pd2;
	//�ͷ������ռ�:delete [] ָ��
	delete[] pd3;
}

void test3() {
	//operator new: ������������غ���,����һ��ȫ�ֺ���
	            //: ʹ�÷�ʽ��malloc����
	            //: ��װ malloc+�쳣
	//new��ִ�й���(�Զ�������) : operator new --> malloc --> ���캯��
	char* ptr = (char*)operator new(sizeof(char));
	char* ptr2 = (char*)malloc(sizeof(char));
	//operator delete: ������������غ���,����һ��ȫ�ֺ���
			       //: ʹ�÷�ʽ��free����
			       //: ��װ free
	//delete��ִ�й���(�Զ�������) : �������� --> operator delete --> free
	operator delete(ptr);
	free(ptr2);
}

void test4()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	//new��λ���ʽ�� new (��ַ) ����(�����б�)
	//	�����Ѿ����õĿռ�����ʽ���ù��캯��
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}
int main() {

	system("pause");
	return 0;
}