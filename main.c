#include <stdio.h>
#include <math.h>

int days = 30, hrs = 14, col = 16;

void hourave(float readings[], float month[][col], int m);                                           //calculates 14 hourly averages for each day of month
void dailymsd(float readings[], float month[][col], int m);                                          //calculates daily mean and std dev for each day of month
float monthhr(float months[][col], int hour);                                                        //calculates average temperature for each hour of the month 

int main(void) 
{
    float readings[5040];
    float april[days][col], may[days][col], june[days][col];
    float (*months[3])[col] = {april, may, june};                                       // array of 3 month, so one loop handles April, May and June

    const char *names[3] = {"April", "May", "June"};                                    //month names for printing
    const char *labels[hrs] = {"7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM",                  //column labels for printing
                                 "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM"};

    FILE *fpi = fopen("proj2_data.txt", "r");                                                       //open the file for reading
    if (fpi == NULL)                                                                                //check if the file opened successfully
    {                          
        printf("Error opening file");
        return 1;
    }
    for (int i = 0; i < 5040; i++)                                                                  //read 5040 values and mark if there is a read failure
    { 
        if (fscanf(fpi, "%f", &readings[i]) != 1) 
            {
                printf("Read failed at reading %d\n", i + 1);
                fclose(fpi);
                return 1;
            }
    }
    fclose(fpi);   
    

    for (int m = 0; m < 3; m++) 
    {                                                                                               //loop through the months
hourave(readings, months[m], m);                                                             //fill hourly average column 
dailymsd(readings, months[m], m);                                                            //fill mean column and std dev column 

        printf("\n%s Data:\n", names[m]);                                                          //print the month header
        printf("Hourly Average Temperatures (with Daily Mean and Standard Deviation)\n\n");

        printf("%-8s|", "Day");                                                                    
        for (int h = 0; h < hrs; h++)                                                              //print the hour labels
            printf(" %-6s|", labels[h]);
        printf(" %-6s| %s\n", "Mean", "Std Dev");                                                  //print the mean and std dev labels

        printf("--------|");                                                                       // print divider line       
        for (int h = 0; h < hrs + 1; h++)
            printf("-------|");
        printf("--------\n");

        for (int d = 0; d < days; d++) 
        {                                                                                          //print one row per day with 14 hourly averages, mean, std dev
            printf("%7d |", d + 1);                                                                //formatting the day column
            for (int h = 0; h < hrs; h++)
                printf(" %5.2f |", months[m][d][h]);                                               //print the hourly averages 
            printf(" %5.2f | %5.2f\n", months[m][d][14], months[m][d][15]);
        }

        printf("--------|");
        for (int h = 0; h < hrs + 1; h++)
            printf("-------|");
        printf("--------\n");

        printf("%-8s|", "Avg temp");                                                                
        for (int h = 0; h < hrs; h++)                                                             //print the monthly average for each hour using month
            printf(" %5.2f |", monthhr(months[m], h));
        printf("\n");
    }
    return 0;
}