#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
char *ptr;
int length=0;
FILE *fptr;
int reallocation(int size);
void opt1();
void opt2();
void opt3();
char firstc;
char secondc;
char color[8][8];
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
int main()
{
    strcpy(color[0],BLU);
    strcpy(color[1],RED);
    strcpy(color[2],GRN);
    strcpy(color[3],YEL);
    strcpy(color[4],BLK);
    strcpy(color[5],MAG);
    strcpy(color[6],CYN);
    strcpy(color[7],WHT);

    int option=0;
    fptr=fopen("start.txt","w");
    ptr= (char*)malloc(sizeof(char));
    int size = 0;

    printf("Enter the color option : ");
    scanf("%d",&option);
    printf("Enter the size of triangle : ");
    scanf("%d", &size);
    reallocation(size);
    printf("Enter : ");
    getchar();
    scanf("%c%c",&firstc,&secondc);
    printf("firstc : %c\n",firstc);
    printf("secondc: %c\n",secondc);
//    printf("Length : %d",length);
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int i = 0;
    int j = 0;
    int count=0;
    f = size;
    for (a = 0; a <= size; a++)
    {
        for (b = a; b <= size; b++)
        {
//            printf("*");
//            *(ptr+count)='*';
            *(ptr+count)=firstc;
            count++;
            for (c = b; c <= size; c++)
            {
//                printf("#");
//                *(ptr+count)='#';
                *(ptr+count)=secondc;
                count++;
            }
        }
        if (b > size)
        {
            if (a != 0)
            {

                g = (f + 2);
                j = g + j;
                h = j * 2;
                for (i = 0; i < h; i++)
                {
//                    printf(" ");
                    *(ptr+count)=' ';
                    count++;
                }
                f--;
            }
            for (b = a; b <= size; b++)
            {
                c = size - e;
                d = size - a;
                while (c <= d)
                {
                    d--;
//                    printf("#");
//                    *(ptr+count)='#';
                    *(ptr+count)=secondc;
                    count++;
                }
                e++;
//                printf("*");
//                *(ptr+count)='*';
                *(ptr+count)=firstc;
                count++;
            }
        }
        if (a < size)
        {
//            printf("\n");
            *(ptr+count)='\n';
            count++;
        }


        e = a + 1;
    }
    f=size;b=c=d=g=i=0; j=6;e=e-2;
    a=a-2;
    for (a = a; a >= 0; a--)
    {
//        printf("\n");
        *(ptr+count)='\n';
        count++;
        for (b = a; b <= size; b++)
        {
//            printf("*");
//            *(ptr+count)='*';
            *(ptr+count)=firstc;
            count++;
            for (c = b; c <= size; c++)
            {
//                printf("#");
//                *(ptr+count)='#';
                *(ptr+count)=secondc;
                count++;
            }
        }
        if (b > size)
        {
            if (a != 0)
            {
                h=h-j;
                for (i = 0; i < h; i++)
                {
//                    printf(" ");
                    *(ptr+count)=' ';
                    count++;
                }
                j=j+2;
            }
            for (b = a; b <= size; b++)
            {
                c = size - e;
                d = size - a;
                while (c <= d)
                {
                    d--;
//                    printf("#");
//                    *(ptr+count)='#';
                    *(ptr+count)=secondc;
                    count++;

                }
                e++;
//                printf("*");
//                *(ptr+count)='*';
                *(ptr+count)=firstc;
                count++;
            }
        }

        e = a - 1;
    }
    printf("\n");
    if(option==1)
    {
        opt1();
    }
    else if(option==2)
    {
//        printf("option2");
//        opt2();
//        opt2();
//        opt2();
        opt2();
    }
    else if(option==3)
    {
        opt3();
    }
//    printf("\x1B[31m");
//      printf(RED);
//    printf("%s",ptr);
    free(ptr);
    fclose(fptr);
    getch();
    return 0;
}
int reallocation(int size)
{
    length=4;
    for (int i = 0; i < size; ++i)
    {
        length=(length+(6+(2*i)));
    }
    length=length*((2*(size+1))-1);
    length=length+((2*(size+1))-2);
//    printf("%d",length);
    ptr = (char *)realloc(ptr, length*sizeof(char));
}
void opt1()
{
    srand(time(NULL));
    for (int z = 0; z < length; ++z)
    {
        printf(color[rand()%8]);
        printf("%c",*(ptr+z));
        fputc(*(ptr+z),fptr);
    }
}
void opt2()
{
//    sleep(1);
    srand(time(NULL));
    int r1=rand()%8;
    int r2=rand()%8;
    printf("r1 : %d\n",r1);
    printf("r2 : %d\n",r2);
    for (int z = 0; z < length; ++z)
    {
        if(*(ptr+z)==firstc)
        {
            printf(color[r1]);
        }
        else if (*(ptr+z)==secondc)
        {
            printf(color[r2]);
        }
        printf("%c",*(ptr+z));
        fputc(*(ptr+z),fptr);
    }
}
void opt3()
{

    srand(time(NULL));
    char c;
    for (int i = 0; i < length; ++i)
    {
        c= (char)((rand() % 26)+65);
        if(rand()%2)
        {
            c=(char) (c+32);
        }
        if(*(ptr+i)!=' ' && *(ptr+i)!='\n')
        {
            *(ptr+i)=c;
        }
    }
    for (int z = 0; z < length; ++z)
    {
        printf(color[rand()%8]);
        printf("%c",*(ptr+z));
        fputc(*(ptr+z),fptr);
    }
}