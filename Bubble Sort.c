#include<stdio.h>

int main()
{
	int a[32];
	int n,i,j,k,temp;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d Element: ",i+1);
		scanf("%d",&a[i]);
	}
	for(j=1;j<n;j++)
	{
		for(k=0;k<n-1;k++)
		{
			if(a[k] > a[k+1])
			{
				temp = a[k];
				a[k] = a[k+1];
				a[k+1]=temp;
			}
		}
	}
	printf("---After Sorting---\n");
	for(i=0;i<n;i++)
	{
		printf("%d element is %d\n",i+1,a[i]);
	}
	printf("\n");
	return 0;

}

