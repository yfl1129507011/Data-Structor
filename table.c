#include <stdio.h>
#include <stdlib.h>

typedef struct Table
{
	int *head;
	int length;  // 记录当前顺序表的长度
	int size;  // 记录顺序表分配的存储容量
} table;


#define SIZE 5   // 定义顺序表的大小


// 初始化顺序表
table initTable()
{
	table t;
	t.head = (int *)malloc(SIZE*sizeof(int));
	if (!t.head)
	{
		printf("初始化失败（初始化空间错误）");
		exit(0);
	}
	t.length = 0;
	t.size = SIZE;

	return t;
}

// 打印顺序表的信息
void displayTable(table t)
{
	printf("table element is: ");
	for (int i = 0; i < t.length; ++i)
	{
		printf("%d ", t.head[i]);
	}
	printf("\n");
	printf("table length is %d\n", t.length);
	printf("table size is %d\n\n", t.size);
}

// 添加顺序表的元素数据
void addTable(table *t, int elem)
{
	int index = (*t).length + 1;   // 增加一个元素
	if (index > (*t).size)  // 超出顺序表的内存大小，需要重新分配内存空间
	{
		(*t).head = (int *)realloc((*t).head, ((*t).size+1)*sizeof(int));
		if (!(*t).head)
		{
			printf("storage allocation failure！\n");
			exit(0);
		}
		(*t).size += 1;
	}

	(*t).head[(*t).length] = elem;
	(*t).length = index;
}


// 向顺序表中插入指定的数据元素
void insertTable(table *t, int elem, int inx)
{
	if (inx > (*t).length || inx < 0)
	{		
		printf("insert the location ERROR！\n");
		exit(0);
	}

	if ((*t).length >= (*t).size)
	{
		(*t).head = (int *)realloc((*t).head, ((*t).size+1)*sizeof(int));  // 重新分配内存大小，并把原来的值复制到新的内存地址上
		if (!(*t).head)
		{
			printf("storage allocation failure！\n");
			exit(0);
		}

		(*t).size += 1;
	}

	for (int i = (*t).length-1; i > inx-1 ; i--)
	{
		(*t).head[i+1] = (*t).head[i];
	}

	(*t).head[inx] = elem;
	(*t).length += 1;
}

void deleteTable(table *t, int inx)
{
	if (inx > (*t).length-1 || inx < 0)
	{
		printf("delete the location ERROR！\n");
		exit(0);
	}

	for (int i = inx; i < (*t).length-1; ++i)
	{
		(*t).head[i] = (*t).head[i+1];
	}

	(*t).length -= 1;
}


// 查找顺序表指定元素的索引号
int selectTable(table t, int elem)
{
	for (int i = 0; i < t.length; ++i)
	{
		if (t.head[i] == elem)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	table t = initTable();
	addTable(&t, 9);
	displayTable(t);
	addTable(&t, 19);
	displayTable(t);
	addTable(&t, 29);
	displayTable(t);
	insertTable(&t, 39, 0);
	displayTable(t);
	insertTable(&t, 49, 3);
	displayTable(t);
	insertTable(&t, 59, 2);
	displayTable(t);

	deleteTable(&t, 0);
	displayTable(t);

	return 0;
}