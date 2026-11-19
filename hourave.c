#include <stdio.h>
#include <math.h>

void hourave(float readings[], float month[][16], int monthno);

int main(void)
{
    /* Exactly four arrays, all local to main. */
    float readings[5040];
    float april[30][16] = {0};
    float may[30][16] = {0};
    float june[30][16] = {0};

    FILE *fpi;
    int i;

    fpi = fopen("proj2_data.txt", "r");

    if (fpi == NULL)
    {
        perror("Unable to open proj2.txt");
        return 1;
    }

    for (i = 0; i < 5040; i++)
    {
        if (fscanf(fpi, "%f", &readings[i]) != 1)
        {
            fprintf(stderr,
                    "Error: could not read reading %d of 5040.\n",
                    i + 1);

            fclose(fpi);
            return 1;
        }
    }

    fclose(fpi);

    printf("Successfully read %d readings.\n", i);


    return 0;
}


void hourave(float readings[], float month[][16], int monthno)
{
    //r is the specific 15 min interval of the hour
    int day, time, r;

    for (day = 0; day < 30; day++)
    {
        for (time = 0; time < 14; time++)
        {
            float sumtime = 0.00;

            for (r = 0; r < 4; r++)
            {

                //Calculate the exact position of the data (month x total readings a month) + (day x total readings a day) + (hour x total readings an hour) + specific 15 min interval in the hour
                int position = (monthno * 1680) + (day * 56) + (time * 4) + r;
                sumtime += readings[position];
            }

            //Store the hourly avg in columns 0 - 13 (14 columns)
            month[day][time] = sumtime/4.00;
        }
    }

}
