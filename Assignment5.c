#include <stdio.h>
#include <stdbool.h>
int main()
{
    int i, j, k, total_blocks, blocks, files, sb[50], length[50];
    printf("\n Enter the total number of blocks : ");
    scanf("%d", &total_blocks);
    int memory[total_blocks];
    for (i = 0; i < total_blocks; i++)
        memory[i] = -1;
    printf(" Enter the number of files : ");
    scanf("%d", &files);
    bool file_alloc[files];
    int alloc_info[files];
    printf("\n");
    for (i = 0; i < files; i++)
    {
        printf(" Enter the starting block number of file %d : ", i + 1);
        scanf("%d", &sb[i]);
        printf(" Enter the length of file %d : ", i + 1);
        scanf("%d", &length[i]);
        sb[i]--;
        file_alloc[i] = 0;
        alloc_info[i] = -1;
    }
    for (i = 0; i < files; i++)
    {
        j = sb[i];
        alloc_info[i] = j;
        file_alloc[i] = 1;
        if (memory[j] != -1)
        {
            printf("\n Cannot allocate file %d.", i + 1);
            alloc_info[i] = -1;
            file_alloc[i] = 0;
            continue;
        }
        else
        {
            for (j = sb[i]; j < sb[i] + length[i]; j++)
            {
                if (memory[j] != -1)
                {
                    //printf("\n j : %d", j);
                    printf("\n Not enough space to allocate file %d.",i+1);
                    file_alloc[i] = 0;
                    for(k = j-1;k>=sb[i];k--)
                    {
                        memory[k] = -1;
                    }
                    alloc_info[i] = -1;
                    break;
                }
                memory[j] = i + 1;
            }
        }
    }
    printf("\n\n File allocation information : ");
    printf("\n File no. Starting block no. Length \n");
    for (i = 0; i < files; i++)
    {
    	//. If the location is allocated, set the flag to 1, otherwise set the flag to 0.
        if (file_alloc[i] == 1)
        {
            printf(" %d %d %d \n", i + 1,
                   alloc_info[i] + 1, length[i]);
        }
        else if (file_alloc[i] == 0)
        {
            printf(" %d Not allocated %d \n", i + 1,length[i]);
        }
    }
    printf("\n");
    for (i = 0; i < total_blocks; i++)
        printf(" %d ", memory[i]);
    printf("\n");

        return 0;
}