#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   int i;
   int a = 1, b = 2, c = 3, d = 1;
   float x = 0.1, y = 0.5, z = 0.33;
   printf("%d %d %d %d, %f %f %f\n", a, b, c, d, x, y, z);
   const float INV_1_33 = 1.33f; // Define constant outside the loop
   for (i=0; i<50000000; i++)
   {
      c = d + d;       // Replace d * 2 with d + d
      b = c * 15;      // No direct optimization possible here
      a = b >> 4;      // b / 16 replaced with a right shift
      d = b / a;       // No optimization possible without more context

      z = 0.33f;       // Use "f" suffix for float literals
      y = z + z;       // Replace 2 * z with addition
      x = y / INV_1_33; // Use the constant instead of hardcoding 1.33
      z = x / INV_1_33; // Use the constant instead of hardcoding 1.33
   }
   printf("%d %d %d %d, %f %f %f\n", a, b, c, d, x, y, z);
   return 0;
}
