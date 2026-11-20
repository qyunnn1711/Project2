float monthhr((float month[][],int hour))
{
    float sum = 0.0;
    for (int day = 0; day < 30; day++) // increase from day 1 to day 30
    {
        sum += month[day][hour]; // calculate the sum of day 1 to day 30 of specific hour and month
    }
    return sum/30.0;
}
