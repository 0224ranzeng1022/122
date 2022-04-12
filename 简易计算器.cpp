#include<stdio.h>
#include<stdlib.h>

char* getOperand(char* p, double* pnum);
int main()
{
	char exp[]="1-2.5*4+10.2/5.1";
	char * p = exp, op[20];
	int i = 0, j = 0, k = 0;
	double temp, operand[20], result;
	while (*p != '\0')
	{
		if (*p >= '0' && *p <= '9')
		{
			p = getOperand(p, &temp);
			operand[j++] = temp;
			continue;
		}
		else if (*p == '+' || *p == '-')
		{
			op[k++] = *p;
		}
		else if (*p == '*')
		{
			p = getOperand(++p, &temp);
			operand[j - 1] *= temp;
			continue;
		}
		else if (*p == '/')
		{
			p=getOperand(++p,&temp);
			operand[j-1]/=temp;
			continue;
		}
		p++;
	}
	result=operand[0];
		for (i = 0; i < k; i++)
		{
			switch (op[i])
			{
			case '+':
					result += operand[i + 1];
					break;
			case  '-':
					result -= operand[i + 1];
					break;
			}
		}
	printf("result:%.21f\n", result);
	return 0;
}

char* getOperand(char* p, double* pnum)
{
	char buffer[20];
	int i = 0;
	while (*p >= '0' && *p <= '9' || *p == '.')
	{
		buffer[i++] = *p++;
	}
	buffer[i] = '\0';
	*pnum = atof(buffer);
	return p;
}//v4
