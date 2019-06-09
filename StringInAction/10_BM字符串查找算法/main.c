/*
	算法描述：

	
*/

/*
	str: 字符串
	p：待查找字符
	返回：字符位置	
	-1：没有找到
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
 s ：文本串
 p ：模式串
*/
int BM(char *s, char *p)
{
	int pSize = strlen(p);
	int sSize = strlen(s);
	int i = 0;
	int j = pSize - 1; // 模式串位置
	while (s[i])
	{
		// 从模式串末尾开始往前面匹配
		for (j = pSize - 1; j >= 0; j--)
		{		
			// 匹配失败即发现坏字符
			
			if (s[i + j] != p[j])
			{
				// 检查坏字符是否有包含在模式串中
				int ret = checkContain(p, s[i + j]);				
				
				// TODO:算法优化可以考虑好后缀情况:

				i += j - ret; // j是当前检测的字符位置，ret是坏字符在P串中的位置

				if (ret == -1) // 不包含，则将文本串指针放心地往后移动j - ret位后退出循环
				{					
					break;
				}					
			}			
		}		
		
		if (j == -1) // 匹配成功
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
