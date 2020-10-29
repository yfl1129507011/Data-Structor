#include <stdio.h>
#include <stdlib.h>

// 单链表的结构
typedef struct Link
{
	int elem;
	struct Link *next;
}link;

// 初始化单链表
link *initLink()
{
	link *node = NULL;
	node = (link *)malloc(sizeof(link));
	node->elem = 0;
	node->next = NULL;

	return node;
}

// 打印链表数据元素
void displayLink(link *p)
{
	link *tmp = p;
	while(tmp)
	{
		printf("%d\t", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}

// 添加链表元素
void addLink(link **p, int elem)
{
	link *node = initLink();
	node->elem = elem;

	link *tmp = *p;

	if (tmp == NULL)
	{
		*p = node;
	}
	else
	{
		while( tmp->next ) tmp = tmp->next;
		tmp->next = node;
	}
}

// 插入链表元素
void insertLink(link **p, int elem, int index)
{
	link *tmp = *p;
	link *node = initLink();
	node->elem = elem;

	if (tmp == NULL)
	{
		*p = node;
	}
	else
	{
		if (index <= 0)
		{
			node->next = tmp;
			*p = node;
		}
		else
		{
			while( --index && tmp) 
			{
				tmp = tmp->next;
			}
			node->next = tmp->next;
			tmp->next = node;
		}
	}

}


// 删除链表元素
void deleteLink(link **p, int index)
{
	link *tmp = *p;
	if (tmp == NULL || index < 0)
	{
		printf("delete Error\n");
		exit(0);
	}

	if (index == 0)
	{
		*p = tmp->next;
		free(tmp);
	}
	else
	{
		while(--index && tmp) tmp = tmp->next;
		link *node = tmp->next;
		tmp->next = node->next;
		free(node);
	}

}


int main()
{
	link *p = NULL;
	addLink(&p, 8);
	addLink(&p, 18);
	addLink(&p, 28);
	addLink(&p, 38);
	insertLink(&p, 59, 0);
	insertLink(&p, 99, 1);
	insertLink(&p, 79, 2);
	deleteLink(&p, 1);
	displayLink(p);
	return 0;
}