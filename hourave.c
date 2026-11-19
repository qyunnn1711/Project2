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
