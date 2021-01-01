#ifndef FRACTALHEADERDEF
#define FRACTALHEADERDEF
#include "ComplexNumber.h"



class Fractal {
private:
  int mRow;
  int mCol;
  double mMinReal;
  double mMaxReal;
  double mMinImag;
  double mMaxImag;
  double** mA;

public:
  /* Constructor that sets a bunch a instance variables to whatever is in the arugments and creates a contgious array*/
  Fractal(int rows = 80, int cols = 80, double minReal = -2, double maxReal = 2, double minImag = -2,double maxImag = 2);
  void SetReal(double minReal,double maxReal); /* Setter method that "resets" both min and max values for Real numbers*/
  void SetImag(double minImag,double maxImag); /* Setter method that "resets" both min and max values for imaginary numbers*/
  double DistanceReal(); // maxReal - minReal/cols -1
  double DistanceImag(); //maxImag- minImag/rows -1
  double** contigous_array(); /* Creates a contigous Array */


  int Iterator(ComplexNumber A,ComplexNumber c,int max_iteration); /* Iteration over the quadratic map*/
  void JuliaSet(ComplexNumber c,int max_iteration = 80); /* Calcuates the Julia Set*/

  void displayJuliaSet(double re, double im); /*Displays the Julia Set*/

  void MandelbrotSet(ComplexNumber c,int max_iteration = 80); /* Calcuates the Mandelbrot Set*/
  void displayMandelbrotSet(double re, double im); /*Displays the mandelbrot set*/
  void writeToFile(std::string file_name); /* Writes to file and accepts a string file as a name*/

  ~Fractal(); /* Desctructor to dellocate the memory*/


};

#endif
