#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main () {
   double min_height, max_degrees;

	 scanf("%lf %lf", &min_height, &max_degrees);
	 int ladder_length = ceil(min_height / sin(max_degrees * PI / 180));
   printf("%d", ladder_length);
   
   return(0);
}
