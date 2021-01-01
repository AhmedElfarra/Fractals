
#include <iostream>
#include <string>
#include "Fractal.h"
#include "ComplexNumber.h"

int isNumber(const char* str) {

    if (!str || *str=='\0') {  // NULL str or empty str: not a number
        return 0;
    }

    char* endOfNum;
    strtol(str,&endOfNum,10);

    if (*endOfNum == '\0') { // string is at its end; everything in it was a valid part of the number
        return 1;
    } else {
        return 0;  // something that is not part of a number followed.
    }

}

int main(int argc, char const *argv[]) {
  int x,y;
  if (argc != 3){
    std::cout << "Please enter the size of the Fractal\ni.e. ./output 80 80" << '\n';
    exit(0);
  }
  if ((isNumber(argv[1]) == 1) && (isNumber(argv[2]) == 1) ){
    x = atoi(argv[1]);
    y = atoi(argv[2]);
  }else {
    std::cout << "Please enter a valid number!" << '\n';
    exit(0);
  }
  Fractal A(x,y);
  A.displayJuliaSet(-0.8,0.156);
  A.writeToFile("julia.dat");

  A.displayMandelbrotSet(-0.8,0.156);
  A.writeToFile("Mandelbrot.dat");
  return 0;
}
