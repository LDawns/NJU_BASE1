
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	char s[1005];
	int a[1005];
	while (scanf("%s%d", s, &n) != EOF)
	{
		int i, j, len, flag;
		len = strlen(s);
		memset(a, 0, sizeof(a));   //ÖØÒª£¡£¡£¡
		for (i = 0; i<len; i++)
		{
			a[i] = s[i] - '0';
		}
		while (n--)
		{
			for (i = 0; i<len; i++)
			{
				if (a[i]>0)
				{
					for (j = i + 1; j<len; j++)
					{
						if (a[j] >= 0)
						{
							break;
						}
					}
					if (a[i]>a[j])
					{
						a[i] = -1;
						break;
					}
				}
			}
		}
		flag = 0;
		for (i = 0; i<len; i++)
		{
			if (!(a[i]<0 || (flag == 0 && a[i] == 0)))
			{
				printf("%d", a[i]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("0");
		}
		printf("\n");
	}
	return (0);
}