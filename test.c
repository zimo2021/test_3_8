#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//qsort的使用和创建  qsort可以排序任意可以比较的数字或字符
//1.void*(空字符指针)-可接收任意类型的地址
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	char* pb = &a;//会有警告，从int*到char*的类型不兼容
//	void*p = &a;//无警告，void*可接收任意类型指针
//	//*p = 1;//不行，因为void*使计算机不知道访问几个字节，所以void*指针不可修改，但可被强制类型转化然后修改
//	*(int*)p = 1;
//	printf("%d\n", a);//1
//	return 0;
//}
//qsort使用 qsort(首元素地址，，字符串长度，字符串宽度（即字节），比较函数（返回值必须为整形，大于0，小于0或等于0）)
//#include<stdlib.h>
//#include<string.h>
//typedef struct stu
//{
//	char name[10];
//	int age;
//}stu;
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//是e1减e2还是e2减e1决定了排列顺序
//}
//int cmp_float(const void* e1, const void* e2)//返回值必须为int
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
//	int arr[10] = { 9,8,7,5,6,4,3,1,2,0 };//整形
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
//	float arr1[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };//浮点型
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
//	stu arr2[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//结构体类型
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
//	stu arr3[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//结构体类型
//	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
//	qsort(arr3, sz3, sizeof(arr3[0]), cmp_name);
//	int i = 0;
//	for (i = 0; i < sz3; i++)
//	{
//		printf("%s ", arr3[i].name);//lisi wangwu zhangsan  按首元素排序
//	}
//}
//int main()
//{
//	test();//成功
//	test1();//成功
//	test2();//用年龄比较，成功
//	test3();//用名字排序，成功
//}————————————————————————————
//自己创建qsort函数-用my_qsort表示    成功
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
//			//判断
//			if(p((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				//交换
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
//	return *(int*)e1 - *(int*)e2;//是e1减e2还是e2减e1决定了排列顺序
//}
//int cmp_float(const void* e1, const void* e2)//返回值必须为int
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
//	int arr[10] = { 9,8,7,5,6,4,3,1,2,0 };//整形
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
//	float arr1[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };//浮点型
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
//	stu arr2[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//结构体类型
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
//	stu arr3[3] = { { "zhangsan",20 },{ "lisi",30 },{ "wangwu",10 } };//结构体类型
//	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
//	my_qsort(arr3, sz3, sizeof(arr3[0]), cmp_name);
//	int i = 0;
//	for (i = 0; i < sz3; i++)
//	{
//		printf("%s ", arr3[i].name);//lisi wangwu zhangsan  按首元素排序
//	}
//}
//int main()
//{
//	test();//成功
//	test1();//成功
//	test2();//用年龄比较，成功
//	test3();//用名字排序，成功
//}
//概念：
/*
除sizeof(数组名)和&数组名  其余用数组名表示的都为数组首元素地址
*/
//int main()
//{
//	int arr[] = { 0,1,2,3 };
//	printf("%d\n", sizeof(arr[0]));//4  电脑为三十二位平台
//	return 0;
//}——————————————————————
//指针笔试题
//int main()
//{
//	char arr[] = "abcdef";//其实为"abcdef\0"
//	printf("%d\n", sizeof(arr));//7  计算字符串的大小（包括\0）
//	printf("%d\n", sizeof(arr+0));//4 计算地址的大小位4或8个字节
//	printf("%d\n", sizeof(*arr));//1 字符
//	printf("%d\n", sizeof(arr[1]));//1 字符
//	printf("%d\n", sizeof(&arr));//4 地址
//	printf("%d\n", sizeof(&arr+1));//4  地址
//	printf("%d\n", sizeof(&arr[0]+1));//4 地址
//	return 0;
//}——————————————————————————

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));//6  strlen中放的东西要为地址 , strlen从该地址往后数，直到出现0或\0;
//	printf("%d\n", strlen(arr+0));//6
//	//printf("%d\n", strlen(*arr));//   *arr为字符，不符合要求，程序挂掉
//	//printf("%d\n", strlen(arr[1]));//  arr[1]为字符，不符合要求，程序挂掉
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr+1));//&arr为整个数组，加一则跳到数组最后，结果为随机值
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