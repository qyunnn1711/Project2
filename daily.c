#include <math.h>

void dailymsd(float readings[], float month[][16], int monthno){
    int base;
    float tempt, sum, sqdev, mean, std;

    for (int day = 0; day < 30; day++){              //This finds where the current day starts in the 1D array.
        base = monthno * 1680 + day * 56;        //Each month has 30 x 56 = 1680 readings, and each day has 56

        sum = 0;
        for (int time = 0; time < 56; time++){       //sum all 56 readings to get the mean
            tempt = readings[base + time];
            sum += tempt;
        }
        mean = sum / (float) 56;

        sqdev = 0;
        for (int time = 0; time < 56; time++){       // sum of squared deviations from the mean
            tempt = readings[base + time] - mean;
            sqdev += tempt * tempt;
        }

        std = sqrt(sqdev / (float) 56);         // Population standard deviation: divide by 56, not 55

        month[day][14] = mean;                  // column 14 = daily mean
        month[day][15] = std;                   // column 15 = daily std dev
    }
}
