#include <stdio.h>

float average(float LifeEx[], size_t COUNT)
{
    float avg, sum=0;
    for (size_t i = 0; i < COUNT; ++i) {
        sum += LifeEx[i];
    }

    avg = sum / COUNT;
    printf("Average of the life expectancy values: %.2f\n", avg);
    return 0;
}

float MinMax(float LifeEx[], size_t COUNT)
{
    float max, min;
    max = LifeEx[0];
    min = LifeEx[0];
    for(size_t i = 0; i < COUNT; i++)
    {
        // if value of current element is greater than previous value
        // then assign new value to max
        if(LifeEx[i] > max)
        {
            max = LifeEx[i];
        }

        // if the value of current element is less than previous element
        // then assign new value to min
        if(LifeEx[i] < min)
        {
            min = LifeEx[i];
        }
     }
     printf("Lowest life expectancy value is: %f\n", min);
     printf("Highest life expectancy value is: %f\n", max);
     return 0;
}


float sorting(float LifeEx[], size_t COUNT)
{

    for (size_t i = 0; i < COUNT; ++i)
      {
        for (size_t j = i + 1; j < COUNT; ++j)
      {
            if (LifeEx[i] < LifeEx[j])
              {
                float s = LifeEx[i];
                LifeEx[i] = LifeEx[j];
                LifeEx[j] = s;
              }
          }
        }
          printf("The list of sorted life expectancy values : \n");
          for (size_t i = 0; i < COUNT; ++i)
            {
                printf("%f\n", LifeEx[i]);
            }
      return 0;
}


int main ()
{
    const size_t COUNT = 5;
    float LifeEx[5] = {75.981, 82.675, 68.745, 99.425, 88.442};

    average(LifeEx, COUNT);
    MinMax(LifeEx, COUNT);
    sorting(LifeEx, COUNT);
    return 0;

}
