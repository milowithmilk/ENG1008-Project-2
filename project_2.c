#include <stdio.h>
#include <math.h>

 float readings[255];

// int april [][];
// int may [][];
// int june [][];

// void hourave(int parameterList)
// {
//     return;
// }

// void dailymsd(int parameterlist)
// {
//     return;
// }

// float monthhr(int parameterList)
// {
//     return;
// }

int readTextFile() 
{
    FILE    *textfile;
   
    float buff, buff1, buff2, buff3, buff4 , buff5;

    int index=0;
     
    textfile = fopen("proj2.txt", "r");

    if(textfile == NULL)
        return 0;

    while (!feof(textfile) && !ferror(textfile))
    {
        fscanf(textfile, "%f %f %f %f %f %f",&buff, &buff1, &buff2, &buff3, &buff4 , &buff5);

        readings[index] = buff;
        readings[index+1] = buff1;
        readings[index+2] = buff2;
        readings[index+3] = buff3;
        readings[index+4] = buff4;
        readings[index+5] = buff5;

        printf("%d : %.2f %.2f %.2f %.2f %.2f %.2f\n", index, buff, buff1, buff2, buff3, buff4 , buff5);

        index += 6;
    }
    
    fclose(textfile);
    return 1;
}

void main() 
{
    readTextFile();
    printf("%.2f\n", readings[1]);
}