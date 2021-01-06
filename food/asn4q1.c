/**
 * C program to find calculate the cost difference in 2018 and 2020
 */

#include <stdio.h>

int main()
{
    const size_t NUM_PRODUCTS = 10; // Size of the array
    const size_t MAX_STRING_LENGTH = 1000;
    char headerline[4*MAX_STRING_LENGTH+4];

    FILE *infile = fopen("../Assignment4/food/food.txt", "r");
    if(infile == NULL) {
        printf("Couldn't open food.txt.");
        return 1;
    }

    // Ignore header line - you could also do this with fscanf using the format specifier
    // "%s%s%s%s\n", and four separate string arrays of length MAX_STRING_LENGTH.
    fgets(headerline, 4*MAX_STRING_LENGTH+4 , infile);

    // Arrays of prices
    float shopping2018[NUM_PRODUCTS];
    float shopping2020[NUM_PRODUCTS];
    char item_name_temp[MAX_STRING_LENGTH], unit_temp[MAX_STRING_LENGTH];

    /* Read in all data values */
    for(size_t k=0; k < NUM_PRODUCTS; k=k+1)
    {
        fscanf(infile, "%s%s%f%f\n", item_name_temp, unit_temp, &shopping2018[k], &shopping2020[k]);
    }
    fclose(infile);

    /* Find total costs for 2018 and 2020 */
    float total_cost2018 = 0.0;
    float total_cost2020 = 0.0;
    for(size_t k=0; k < NUM_PRODUCTS; k = k + 1)
    {
        printf("%f, %f\n", shopping2018[k], shopping2020[k]);
        total_cost2018 = total_cost2018 + shopping2018[k];
        total_cost2020 = total_cost2020 + shopping2020[k];
    }


    /* Print the total cost for 2018, 2020 and difference in cost*/
    printf("total cost in 2018 = %.2f\n", total_cost2018);
    printf("total cost in 2020 = %.2f\n", total_cost2020);
    printf("Difference in price between 2018 and 2020 is = %.2f\n", total_cost2020 - total_cost2018);

    return 0;
}

