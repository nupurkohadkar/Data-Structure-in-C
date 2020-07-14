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
	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(a[j]>a[k])
			{
				temp = a[j];
				a[j] = a[k];
				a[k] = temp;
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

