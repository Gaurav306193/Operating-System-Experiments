#include<stdio.h>
int main()
{
    char pro[10]={'A','B','C','D','E','F','G','H','I','J'},seq[10];
    int avlbl[10],resrc[10],max[10][10],alloc[10][10],need[10][10],i,j,flag=0;
    int proc,res,count=0,temp[10],temp1[10];
    printf("Enter the number of process : ");
    scanf("%d",&proc);
    printf("Enter the types of resourses : ");
    scanf("%d",&res);
    for(i=0;i<proc;i++)
    {
        temp[i]=0;
        temp1[i]=0;
    }
    printf("Enter the currently available resourses of each process (Allocation Matrix) : \n ");
    for(i=0;i<proc;i++)
    {
        printf("For process %c",pro[i]);
        for(j=0;j<res;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("Enter the Maximum Required Resources of each process (Maximum Matrix) : \n");
        for(i=0;i<proc;i++)
        {
            printf("For process %c : ",pro[i]);
            for(j=0;j<res;j++)
            {
                scanf("%d",&max[i][j]);
            }
            printf("Need of Resources of each process ( Need Matrix) : \n");
            for(i=0;i<proc;i++)
            {
                printf("For process %c : ",pro[i]);
                for(j=0;j<res;j++)
                {
                    need[i][j]=max[i][j]-alloc[i][j];
                    printf("\t %d",need[i][j]);
                }
                printf("\n Enter the Resource Instances : ");
                for(i=0;i<res;i++)
                {
                    scanf("%d",&resrc[i]);
                    for(i=0;i<res;i++)
                    {
                        for(j=0;j<proc;j++)
                        {
                            temp1[i]=temp1[i]+alloc[j][i];
                            printf("Available: ");
                            for(i=0;i<res;i++)
                            {
                                avlbl[i]=resrc[i]-temp1[i];
                                printf("%d \t",avlbl[i]);
                            }
                            for(i=0;i<proc;i++)
                            {
                                if(temp[i]!=1)
                                {
                                    for(j=0;j<res;j++)
                                    {
                                        if(avlbl[j]<need[i][j])
                                        {
                                            flag=1;
                                        }
                                    }
                                    if(flag==0)
                                    {
                                        printf("\n Process %c Executed",pro[i]);
                                        printf("\n Available :\t");
                                    }
                                    for(j=0;j<res;j++)
                                    {
                                        avlbl[j]=avlbl[j]+alloc[i][j];
                                        printf("%d \t",avlbl[j]);
                                    }
                                    count++;
                                    temp[i]=1;
                                    seq[count-1]=pro[i];
                                    
                                }
                                else{
                                    flag=0;
                                }
                            }
                            if(count!=proc)
                           
                            for(i=0;i<res;i++)
                            {
                                if(avlbl[i]==resrc[i])
                                {
                                    printf("\n Safe Sequence: ");
                                    for(i=0;i<proc;i++)
                                    {
                                        printf("%c \t",seq[i]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }
    }

}