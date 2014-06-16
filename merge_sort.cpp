/*
    功能：归并排序实现
    时间：2014年6月16日
*/

# include <stdio.h>     //scanf() / printf()
# include <stdlib.h>    //srand() / rand()
# include <time.h>      //time()
# define N 100

void test(int *array, int n, int which);
void merge_sort(int *p, int *begin, int *end);

int main(void)
{
	int n = 10; //待排序元素个数
	int p[100]; //待排序数组

	srand(time(NULL));  //初始化随机函数种子

    test(p, n, 1);	//测试归并排序

	return 0;
}

/*
    用于测试排序函数，
    which为测试哪种排序
    1为归并排序/2为快速排序/3为希尔排序

    p为待排序数组，n为待排序元素个数
    生成的测试数据全部为非负整数
*/
void test(int *p, int n, int which)
{
    int i;
    //for()生成n个小于N的正整数
	for(i = 0; i < n; ++i)
		p[i] = rand()%N;

    //打印排序前元素
    printf("Before Sorting: ");
	for(i = 0; i < n; ++i)
		printf("%d ", p[i]);
	printf("\n");

    switch(which)
    {
        case 1:
            merge_sort(p, &p[0], &p[n]);
            break;
//        case 2:
//        	quick_sort(p);
//        	break;
//        case 3:
//        	shell_sort(p);
    }


    //打印排序后元素
    printf("After Sorting: ");
	for(i = 0; i < n; ++i)
		printf("%d ", p[i]);
	printf("\n\n");
}

/*
    merge_sort()，归并排序函数实现
*/
void merge_sort(int *p, int *begin, int *end)
{
	int size = end-begin;		//size是当前排序区间长度
	int *mid = begin+size/2;	//mid是当前排序区间的中点

	if(size<=1) //递归结束条件
		return;

	merge_sort(p, begin, mid);
	merge_sort(p, mid, end);

    //临时申请长度为size的空间进行归并，节省空间但浪费时间
	int *tarray = (int *)malloc(size*sizeof(int));
	int *p1, *p2;

    //进行归并，这样写看起来简洁但不太容易理解：++运算符的优先级比*的高
	for(p1 = begin, p2 = mid; p1!=mid || p2!=end; )
		*tarray++ = ((p2==end) || (p1!=mid && *p1<=*p2))?*p1++:*p2++;	//注意这里的<=是稳定的关键

    //for()将归并好的元素填回原数组
	for(tarray-=size; begin!=end; )
		*begin++ = *tarray++;

	free(tarray-size);  //不要忘记释放临时空间
}
