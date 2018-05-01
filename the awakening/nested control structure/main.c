#include <stdio.h>
#include <stdlib.h>

void main()
{
	int student;//counter for students
	int pass;//counter for passes
	int fail;//counter for fails
	int grade;
	
	pass=0;
	fail=0;
	student=0;
	while (student<10)
	{
		printf("enter a grade:");
		scanf("%d",&grade);
		
		if (grade==1)
		{
			printf("the student passed\n");
			pass=pass+1;
		}
		else if (grade==2)
		{
			printf("the student failed\n");
			fail=fail+1;
		}
		
		student=student+1;
	}
	
	printf("%d students passed while %d students failed\n",pass,fail);
	
	if (pass>8)
	{
		printf("the teacher gets a bonus!!!\n");
	}
	else if (pass<8)
	{
		printf("the teacher gets no bonus!!!\n");
	}
}
