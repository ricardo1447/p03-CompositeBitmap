#include <iostream>
#include <string>
#include "bitmap.h"
#include <vector>

using namespace std;

//prototypes

vector < string > name(vector < string >);//asks user for file name

bool validBmp(string);//checks if input is a valid file

void startingSize(string);//gets starting size for first file

vector < vector < vector <Pixel> > > rgbValues(vector < string >&);//used for the rgb values of each pixel

Bitmap avgImage(vector < vector < vector < Pixel > > >&);//averages each image pixel by pixel

const int maxFiles = 9;

int main()
{
  Bitmap image;
  vector < vector < vector < Pixel > > > image3D;
  vector < string > list;
  vector < vector < Pixel> > CompositeImage;
  name(list);
  rgbValues(list);
  avgImage(image3D);
  image.save("Composite-rflores42.bmp");


  return 0;
}

//functions

