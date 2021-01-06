#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t MAX_STRING_LENGTH = 100;

typedef struct _smoothie {
    char name[MAX_STRING_LENGTH];
    int number_sold;
    float price;
    float total_sales;
} Smoothie;

Smoothie bestSeller(char *filename) {\
    const size_t MENU_LENGTH = 6;

    FILE *infile = fopen(filename, "r");
    if(infile == NULL) {
        printf("Unable to open %s.\n", filename);
        exit(1);
    }

    // Ignore the header line
    char headerline[4*MAX_STRING_LENGTH+4];
    fgets(headerline, 4*MAX_STRING_LENGTH+4, infile);

    // Read the first smoothie
    Smoothie best_selling;
    fscanf(infile, "%s%d%f%f\n", best_selling.name, &(best_selling.number_sold),
                         &(best_selling.price), &(best_selling.total_sales));

    // Read the rest of the smoothies, remembering that we've already read one.
    Smoothie current;
    for(size_t k=1; k < MENU_LENGTH; k++) {
        fscanf(infile, "%s%d%f%f\n", current.name, &(current.number_sold),
               &(current.price), &(current.total_sales));
        if( current.total_sales > best_selling.total_sales ) {
            strcpy(best_selling.name, current.name);
            best_selling.price = current.price;
            best_selling.number_sold = current.number_sold;
            best_selling.total_sales = current.total_sales;
        }
    }

    return best_selling;
}

int main(){
  Smoothie s;
  s = bestSeller("../Assignment4/bestseller/sales.txt");
  printf("Displaying the best seller for the last weekend:\n");
  printf("Name: %s\n", s.name);
  printf("Price: %f\n", s.price);
  printf("Number sold: %d\n", s.number_sold);
  printf("Total sales: %f\n", s.total_sales);
  return 0;
}
