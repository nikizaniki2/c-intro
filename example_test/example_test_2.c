#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,countOfEven,countOfOdd,swap;
    printf("Count of digits:\n");
    scanf("%d", &n);
    int arr[n];
    FILE *fp;

    if((fp=fopen("FileN","wb"))==NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    countOfEven = 0;
    countOfOdd = 0;
    for(i=0;i<n;i++)
    {
        printf("%d :", i);
        scanf("%d",&arr[i]);
        fwrite(&arr[i],sizeof(int),1,fp);
        if(arr[i]%2==0)
        {
            countOfEven++;
        }
        else
        {
            countOfOdd++;
        }
    }
    fclose(fp);
    printf("Count of even digits: %d\n",countOfEven);
    printf("Count of odd digits: %d\n",countOfOdd);


    if((fp=fopen("fileText","w"))==NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\n",arr[i]);
    }
    fclose(fp);
    return 0;
}
