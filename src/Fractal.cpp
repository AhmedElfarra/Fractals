#include <iostream>
#include "ComplexNumber.h"
#include "Fractal.h"
#include <fstream>
#include <cassert>
#include <cmath>

/* Constructor that sets a bunch a instance variables to whatever is in the arugments and creates a contgious array*/
Fractal::Fractal(int rows, int cols, double minReal, double maxReal, double minImag,double maxImag)
{
  mRow = rows;
  mCol = cols;
  mMinReal = minReal;
  mMaxReal = maxReal;
  mMinImag = minImag;
  mMaxImag = maxImag;

  mA = contigous_array();

}

/* Creates a contigous Array */
double** Fractal::contigous_array()
{
  double **L; // Double Pointer Array
  L = new double*[mRow];
  L[0] = new double[mRow*mCol];// Setting the first element of the array to a new array

  // Iterarting through the array to make a bigger array
  for(int i = 1; i < mRow ;i++)
  {
    L[i] = L[i-1] + mCol;
  }

  return L;
}

/* Setter method that "resets" both min and max values for Real numbers*/
void Fractal::SetReal(double minReal,double maxReal)
{
  mMinReal = minReal;
  mMaxReal = maxReal;
}

/* Setter method that "resets" both min and max values for imaginary numbers*/
void Fractal::SetImag(double minImag,double maxImag)
{
  mMinImag = minImag;
  mMaxImag = maxImag;
}

/* Distance between two adjacent pixels for the real part*/
double Fractal::DistanceReal()
{
  return (mMaxReal - mMinReal)/(mCol -1);
}

/* Distance between two adjacent pixels for the imaginary part*/
double Fractal::DistanceImag()
{
  return (mMaxImag - mMinImag)/(mRow -1);
}


/* Iteration over the quadratic map*/
int Fractal::Iterator(ComplexNumber z,ComplexNumber c,int max_iteration)
{
  int iteration = 0;
  while((z.CalculateModulus() < 2.0) && (iteration < max_iteration))
  {
    z = z.CalculatePower(2) + c;
    iteration++;
  }
  return iteration;
}

/* Calcuates the Julia Set*/
void Fractal::JuliaSet(ComplexNumber c,int max_iteration)
{

  for (int i = 0;i <mRow;i++)
  {
    for(int j = 0;j <mCol;j++)
    {
      double re = mMinReal + j*DistanceReal();
      double im = mMaxImag - i*DistanceImag();
      ComplexNumber z(re,im);
      mA[i][j] = Iterator(z,c,max_iteration);
    }
  }
}

/* Calcuates the Mandelbrot Set*/
void Fractal::MandelbrotSet(ComplexNumber c,int max_iteration)
{
  ComplexNumber z;
  for (int i = 0;i <mRow;i++)
  {
    for(int j = 0;j <mCol;j++)
    {
      double re = mMinReal + j*DistanceReal();
      double im = mMaxReal - i*DistanceImag();
      ComplexNumber c(re,im);
      mA[i][j] = Iterator(z,c,max_iteration);
    }
  }
}

/*Displays the Julia Set*/
void Fractal::displayJuliaSet(double re,double im)
{
  ComplexNumber c(re,im);
  JuliaSet(c);
  for (int i = 0;i <mRow;i++)
  {
    for(int j = 0;j <mCol;j++)
    {
      if( mA[i][j] == 80)
        std::cout << "X ";
      else if(mA[i][j])
        std::cout << "  ";
    }
    std::cout << "\n";
  }

}

/*Displays the mandelbrot set*/
void Fractal::displayMandelbrotSet(double re, double im)
{
  ComplexNumber c(re,im);
  MandelbrotSet(c);
  for (int i = 0;i <mRow;i++)
  {
    for(int j = 0;j <mCol;j++)
    {
      if( mA[i][j] == 80)
        std::cout << "X ";
      else if(mA[i][j])
        std::cout << "  ";
    }
    std::cout << "\n";
  }
}

/* Writes to file and accepts a string file as a name*/
void Fractal::writeToFile(std::string file_name)
{
  std::ofstream write_file(file_name); // Write to a file by taking the parameter.
  assert(write_file.is_open()); // Checks if the File is open

  // Iterating the through matrix and writing it row by row and inserting a new line every time the row is done
    for (int i = 0; i < mRow; i++)
    {
        for (int j = 0; j < mCol; j++)
        {
            write_file << mA[i][j] << "\t";
        }
        write_file << "\n";
    }
}


/* Desctructor to dellocate the memory*/
Fractal::~Fractal()
{
  delete[] mA[0];
  delete[] mA;
}
