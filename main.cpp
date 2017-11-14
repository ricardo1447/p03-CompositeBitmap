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

vector < string > name(vector < string > FileList)
{
  cout << "Please enter name of file. If done, enter 'Done'." << endl;
  string fileInput;
  string firstInput;
  do
  {
    cin >> firstInput;
    startingSize(firstInput);
    FileList.push_back(firstInput);
    cin >> fileInput;
    if(fileInput == "Done")
    {
      break;
    }
    else if(validBmp(fileInput) == true)
    {
      FileList.push_back(fileInput);
    }
    else
    {
      cout << "Please check that all the images are the same size or they're valid Bitmap files and then try again." <<endl;
    }
  }while(FileList.size() <= maxFiles)

  return FileList;
}

bool validBmp(string file)
{
  Bitmap image;
  image.open(file);
  if(image.isImage())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void startingSize(string first)
{
  Bitmap image;
  vector < vector < Pixel > > bmp;
  image.open(first);
  if(validBmp(first) == true)
  {
    bmp = image.toPixelMatrix();
    cout << first << " has been loaded.
  }
}

vector < vector < vector < Pixel > > > regValues(vector < string >& list)
{
  vector < vector < vector < Pixel > > > image3D;
  vector < vector < Pixel > bmp;
  Bitmap image;

  for(int i = 0;i < list.size();i++)
  {
    image.open(list[i]);
    bmp = image.toPixelMatrix();
    image3D.push_back(bmp);
  }

 return image3D;
}
  
Bitmap avgImage(vector < vector < vector < Pixel > > >& List)
{
  Pixel rgb;
  Bitmap image;
  Bitmap CompositeImage;
  for(int z = 0; z < List[0][0].size();z++)
  {
    int sumRed = 0;
    int sumGreen = 0;
    int sumBlue = 0;
    for(int y = 0;y < List[0].size();y++)
    {
      for(int x = 0;x < List.size();x++)
      {
        rgb = List[x][y][z];
        sumRed += rgb.red;
        sumGreen += rgb.green;
        sumBlue += rgb.blue;
        int avgRed = sumRed/List[x][y].size();
        int avgGreen = sumGreen/List[x][y].size();
        int avgBlue = sumBlue/List[x][y].size();
        rgb.red = avgRed;
        rgb.green = avgGreen;
        rgb.blue = avgBlue;
        List[x][y][z] = rgb;
      }
    }
  }
  CompositeImage = image.fromPixelMatrix(List);

  return CompositeImage;
}
