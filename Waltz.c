// ignore this
#include <stdio.h>
#include <math.h>

float monthhr(int month[][],int hour);

int main(void)
{
    int index, month[];
    printf("Enter month: ");
    scanf("%d",&month);
    printf("Enter hour index: ")// 0 for 7am - 13 for 8pm
    FILE *fpi; // Declare file pointer
    if ((fpi=fopen("proj2_data.txt","r")) == NULL){
        puts("File could not be open");
    }
    else {

    }
}

float monthhr((int month[][],int houe))
{
    float sum = 0.0;
    for (int i = 0; i < 30; i++)
    {
        sum += month[day][hour];
    }
    return sum/30.0;
}
