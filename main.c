#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLEN 100
void main(void)
{
	FILE *fpin;
	FILE *fpout;
	char line[MAXLEN]; // ������� �� �����
	char *ptr = NULL; // ��������� �� �������
	char *begin = NULL;
	char *end = NULL;
	char *tmp;
	int flag = -1;
	fpin = fopen("test.txt", "r");
	fpout = fopen("resut.txt", "w");
	while(ptr = fgets(line, MAXLEN, fpin))
	{
		flag = -1;
		while (*ptr != '\0')
		{
			if ((*ptr == '_')) 
			{
				if (flag == -1)
				{
					flag = -2; //���������, ���� ������ ������,
					begin = &*ptr;// ����� ������� ������� ����� ������ ������
				}
				if (flag == 0)
				{
					begin = &*ptr; //���������� ������ ������
					flag = 1; //���� ��������, ��� ������ ��� 
				}		     //������� ��� ��������� ��������
			}
			else {
				if (flag == -1) flag = 0;
				if (flag == -2) {//���������, ���� ������ ������
					ptr++;
					flag = 1; //������� �� ��������� "������ ������"
				}			 //, ��������� � ���������� �������
				if (flag == 1) {
					ptr--;//��� ����� �� '_'
					end = &*ptr;//���������� ��������� ������
					ptr = &*begin;       //������ ��������� �� ��������� ������,
					tmp = begin;
					if (begin != end) {// ��� ��� ������ ����� ������
						while (*begin++ = *end++)
							;
					}
					ptr = tmp;
					end = NULL;	//���������
					begin = NULL;
					flag = 0;
				}
			}	
			ptr++;
		}
		if (flag == 1) {
			ptr--;//��� ����� �� '_'
			end = &*ptr;//���������� ��������� ������
			ptr = &*begin;       //������ ��������� �� ��������� ������,
			tmp = begin;
			if (begin != end) {// ��� ��� ������ ����� ������
				while (*begin++ = *end++)
					;
			}
			ptr = tmp;
			end = NULL;	//���������
			begin = NULL;
			flag = 0;
		}
		flag = -1;
		fprintf(fpout,"%s",line);
	}
	fclose(fpin);
	fclose(fpout);
}
