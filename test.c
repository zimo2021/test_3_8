#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//qsort��ʹ�úʹ���  qsort��������������ԱȽϵ����ֻ��ַ�
//1.void*(���ַ�ָ��)-�ɽ����������͵ĵ�ַ
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	char* pb = &a;//���о��棬��int*��char*�����Ͳ�����
//	void*p = &a;//�޾��棬void*�ɽ�����������ָ��
//	//*p = 1;//���У���Ϊvoid*ʹ�������֪�����ʼ����ֽڣ�����void*ָ�벻���޸ģ����ɱ�ǿ������ת��Ȼ���޸�
//	*(int*)p = 1;
//	printf("%d\n", a);//1
//	return 0;
//}
//qsortʹ�� qsort(��Ԫ�ص�ַ�����ַ������ȣ��ַ�����ȣ����ֽڣ����ȽϺ���������ֵ����Ϊ���Σ�����0��С��0�����0��)
//#include<stdlib.h>
//#include<string.h>
//typedef struct stu
//{
//	char name[10];
//	int age;
//}stu;
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//��e1��e2����e2��e1����������˳��
//}
//int cmp_float(const void* e1, const void* e2)//����ֵ����Ϊint
//{
//	return (int)(*(float*)e1 - *(float*)e2);
//}
//int cmp_age(const void*e1,const void*e2)
//{
//	return ((stu*)e1)->age - ((stu*)e2)->age;
//}
//int cmp_name(const void*e1, const void*e2)
//{
//	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
//}
//void test()
//{
//	int arr[10] = { 9,8,7,5,6,4,3,1,2,0 };//����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test1()
//{
//	float arr1[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };//������
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	qsort(arr1, sz1, sizeof(arr1[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz1; i++)
//	{
//		printf("%f ", arr1[i]);
//	}
//}
//void test2()
//{
//	stu arr2[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//�ṹ������
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	qsort(arr2, sz2, sizeof(arr2[0]), cmp_age);
//	int i = 0;
//	for (i = 0; i < sz2; i++)
//	{
//		printf("%d ", arr2[i].age);
//	}
//}
//void test3()
//{
//	stu arr3[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//�ṹ������
//	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
//	qsort(arr3, sz3, sizeof(arr3[0]), cmp_name);
//	int i = 0;
//	for (i = 0; i < sz3; i++)
//	{
//		printf("%s ", arr3[i].name);//lisi wangwu zhangsan  ����Ԫ������
//	}
//}
//int main()
//{
//	test();//�ɹ�
//	test1();//�ɹ�
//	test2();//������Ƚϣ��ɹ�
//	test3();//���������򣬳ɹ�
//}��������������������������������������������������������
//�Լ�����qsort����-��my_qsort��ʾ    �ɹ�
//#include<stdlib.h>
//#include<string.h>
//void swap(char* e1, char* e2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		int tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//void my_qsort(void* base,int sz,int width,int (*p)(void* e1,void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//�ж�
//			if(p((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				//����
//				swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
//			}
//		}
//	}
//}
//typedef struct stu
//{
//	char name[10];
//	int age;
//}stu;
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//��e1��e2����e2��e1����������˳��
//}
//int cmp_float(const void* e1, const void* e2)//����ֵ����Ϊint
//{
//	return (int)(*(float*)e1 - *(float*)e2);
//}
//int cmp_age(const void*e1,const void*e2)
//{
//	return ((stu*)e1)->age - ((stu*)e2)->age;
//}
//int cmp_name(const void*e1, const void*e2)
//{
//	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
//}
//void test()
//{
//	int arr[10] = { 9,8,7,5,6,4,3,1,2,0 };//����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test1()
//{
//	float arr1[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };//������
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	my_qsort(arr1, sz1, sizeof(arr1[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz1; i++)
//	{
//		printf("%f ", arr1[i]);
//	}
//}
//void test2()
//{
//	stu arr2[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//�ṹ������
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	my_qsort(arr2, sz2, sizeof(arr2[0]), cmp_age);
//	int i = 0;
//	for (i = 0; i < sz2; i++)
//	{
//		printf("%d ", arr2[i].age);
//	}
//}
//void test3()
//{
//	stu arr3[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//�ṹ������
//	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
//	my_qsort(arr3, sz3, sizeof(arr3[0]), cmp_name);
//	int i = 0;
//	for (i = 0; i < sz3; i++)
//	{
//		printf("%s ", arr3[i].name);//lisi wangwu zhangsan  ����Ԫ������
//	}
//}
//int main()
//{
//	test();//�ɹ�
//	test1();//�ɹ�
//	test2();//������Ƚϣ��ɹ�
//	test3();//���������򣬳ɹ�
//}
//���
/*
��sizeof(������)��&������  ��������������ʾ�Ķ�Ϊ������Ԫ�ص�ַ
*/
//int main()
//{
//	int arr[] = { 0,1,2,3 };
//	printf("%d\n", sizeof(arr[0]));//4  ����Ϊ��ʮ��λƽ̨
//	return 0;
//}��������������������������������������������
//ָ�������
//int main()
//{
//	char arr[] = "abcdef";//��ʵΪ"abcdef\0"
//	printf("%d\n", sizeof(arr));//7  �����ַ����Ĵ�С������\0��
//	printf("%d\n", sizeof(arr+0));//4 �����ַ�Ĵ�Сλ4��8���ֽ�
//	printf("%d\n", sizeof(*arr));//1 �ַ�
//	printf("%d\n", sizeof(arr[1]));//1 �ַ�
//	printf("%d\n", sizeof(&arr));//4 ��ַ
//	printf("%d\n", sizeof(&arr+1));//4  ��ַ
//	printf("%d\n", sizeof(&arr[0]+1));//4 ��ַ
//	return 0;
//}����������������������������������������������������

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));//6  strlen�зŵĶ���ҪΪ��ַ , strlen�Ӹõ�ַ��������ֱ������0��\0;
//	printf("%d\n", strlen(arr+0));//6
//	//printf("%d\n", strlen(*arr));//   *arrΪ�ַ���������Ҫ�󣬳���ҵ�
//	//printf("%d\n", strlen(arr[1]));//  arr[1]Ϊ�ַ���������Ҫ�󣬳���ҵ�
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr+1));//&arrΪ�������飬��һ������������󣬽��Ϊ���ֵ
//	printf("%d\n", strlen(&arr[0]+1));//5
//	return 0;
//}
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//		printf("%d\n", sizeof(arr));//6
//		printf("%d\n", sizeof(arr+0));//4
//		printf("%d\n", sizeof(*arr));//1
//		printf("%d\n", sizeof(arr[1]));//1
//		printf("%d\n", sizeof(&arr));//4
//		printf("%d\n", sizeof(&arr+1));//4
//		printf("%d\n", sizeof(&arr[0]+1));//4
//	return 0;
//}