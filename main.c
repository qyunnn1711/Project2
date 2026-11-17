#include <stdio.h>

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

    /*
     * Functions....
     */

    return 0;
}