/*
	�㷨������

	
*/

/*
	str: �ַ���
	p���������ַ�
	���أ��ַ�λ��	
	-1��û���ҵ�
*/
int checkContain(char * str, char p)
{
	int size = strlen(str) - 1;
	
	while (size >= 0)
	{
		if (str[size] == p)
		{
			return size;
		}	
		size--;
	}
	return -1;
}


/* 
 s ���ı���
 p ��ģʽ��
*/
int BM(char *s, char *p)
{
	int pSize = strlen(p);
	int sSize = strlen(s);
	int i = 0;
	int j = pSize - 1; // ģʽ��λ��
	while (s[i])
	{
		// ��ģʽ��ĩβ��ʼ��ǰ��ƥ��
		for (j = pSize - 1; j >= 0; j--)
		{		
			// ƥ��ʧ�ܼ����ֻ��ַ�
			
			if (s[i + j] != p[j])
			{
				// ��黵�ַ��Ƿ��а�����ģʽ����
				int ret = checkContain(p, s[i + j]);				
				
				// TODO:�㷨�Ż����Կ��Ǻú�׺���:

				i += j - ret; // j�ǵ�ǰ�����ַ�λ�ã�ret�ǻ��ַ���P���е�λ��

				if (ret == -1) // �����������ı���ָ����ĵ������ƶ�j - retλ���˳�ѭ��
				{					
					break;
				}					
			}			
		}		
		
		if (j == -1) // ƥ��ɹ�
		{
			return i;
		}		
	}
	return -1;
}


void test3()
{
	const char *s = "HERE IS A SIMPLE EXAPLE";
	const char *p = "EXAPLE";

	int ret = BM(s, p);	

	if (ret >= 0)
	{
		for (int i = ret; i < strlen(s); i++)
		{
			printf("%c", s[i]);
		}
	}
	
	printf("\nposition = %d\n", ret);
}


int main()
{
	test3();
	system("pause");
	return 0;
}
