

#include <stdio.h>
#include <math.h>
#define PI 3.14
double circle_area(double radius)
{
    double circle_area;
    circle_area= PI * pow(radius,2);
    return circle_area;
}
double calc_hypotenuse(int side1, int side2)
{
    double hypotenuse;
    hypotenuse= sqrt(pow(side1,2)+ pow(side2,2));
    return hypotenuse;
}
/* The diameter of the smallest circle that surrounds a rectangle
is the diagonal of rectangle  */
double calc_radius_of_smallest_circle(int side1, int side2)
{
    double small_diameter, small_radius;
    small_diameter=calc_hypotenuse(side1, side2);
    small_radius=small_diameter/2;
    return small_radius;
}
/* The diameter of the largest circle that fits inside a rectangle
is the short edge of rectangle */
double calc_radius_of_largest_circle(int side1, int side2)
{
    double largest_radius;
    if(side1>side2)
    {
        largest_radius=(double)side2/2;
    }
    else
    {
        largest_radius=(double)side1/2;
    }
    return largest_radius;
}
double calc_area_of_square (int side)
{
    double square_area;
    square_area=pow(side,2);
    return square_area;
}
/*The area of the smallest square that surrounds a rectangle
square side= long edge of rectangle */
double calc_area_of_smallest_square(int side1, int side2)
{
    double square_side, square_area;
    if(side1> side2)
    {
        square_side=side1;
    }
    else
    {
        square_side=side2;
    }
    square_area=calc_area_of_square(square_side);
    return square_area;
}
/*The area of the largest square that fits inside the rectangle
square side = short edge of rectangle */
double calc_area_of_largest_square(int side1, int side2)
{
    double square_side, square_area;
    if(side1>side2)
    {
        square_side=side2;
    }
    else
    {
        square_side=side1;
    }
    square_area=calc_area_of_square(square_side);
    return square_area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square )
{
    printf("The area of the largest circle that fits inside a rectangle : %.2f \n", largest_circle);
    printf("The area of the largest square that fits inside the rectangle :%.2f \n", largest_square);
    printf("The area of the smallest circle that surrounds the same rectangle :%.2f \n", smallest_circle);
    printf("The area of the smallest square that surrounds the same rectangle : %.2f \n", smallest_square);
}
int main()
{
    int side1,side2;
    double smallest_radius, largest_radius, largest_circle, largest_square, smallest_circle, smallest_square;
    printf("Enter the first side  for rectangle:");
    scanf("%d", &side1);
    printf("Enter the second side for rectangle :");
    scanf("%d", &side2);
    /* Calculation results for display_results function */
    smallest_radius=calc_radius_of_smallest_circle(side1, side2);
    smallest_circle=circle_area(smallest_radius);
    largest_radius=calc_radius_of_largest_circle(side1, side2);
    largest_circle=circle_area(largest_radius);
    smallest_square=calc_area_of_smallest_square(side1, side2);
    largest_square=calc_area_of_largest_square(side1,side2);
    display_results(largest_circle, largest_square, smallest_circle, smallest_square);

    return 0;
}
