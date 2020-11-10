#include <stdio.h>


struct
{
	char ch;
	char name;
	char bb;
	char cc;
	int i;
	char sex;
	int a;
} stu1;

struct Stu
{
	char *name;
	char sex;
	int age;
	int id;
};

void checkEndian()
{
	union
	{
		int n;
		char ch;
	} data;
	data.n = 1;
	if (data.ch == 1)
	{
		printf("Little-endian\n");
	}
	else
	{
		printf("Big-endian\n");
	}
}


// #pragma message("_X86 macro activated!")

// #pragma pack(push, 4)
// #pragma pack(4)
struct TestStr
{
	char c1;
	char c2;
	char i;
	short s;
};
// #pragma pack(pop)
// #pragma pack()

int main()
{
	// struct Stu stu2;
	// printf("%d\n", sizeof(stu1));
	// printf("%d\n", sizeof(struct Stu));
	// printf("%d\n", sizeof(stu2));
	// checkEndian();

	struct TestStr a;
	printf("c1 %p, s %p, c2 %p, i %p\n",
(unsigned int)(void*)&a.c1 - (unsigned int)(void*)&a,
(unsigned int)(void*)&a.s - (unsigned int)(void*)&a,
(unsigned int)(void*)&a.c2 - (unsigned int)(void*)&a,
(unsigned int)(void*)&a.i - (unsigned int)(void*)&a);

	printf("%d\n", sizeof(a));
	return 1;
}