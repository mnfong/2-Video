// main.cpp
// Fong, Madison
// mnfong

#include <iostream>
#include "video.h"

using namespace std;

int main()
{
  // Variables needed to run the program
  const int numberOfVideos = 100;
  Video *videos[numberOfVideos];
  int count = 0;
  string method;
  string tl;
  string url;
  string cmmnt;
  float vidLen;
  int rate;

  // Asks user what sorting method they would like
  getline(cin, method);
  if ((method != "rating") && (method != "title") && (method != "length"))
  {
    cerr << method << " is not a legal sorting method, giving up." << endl;
    return 1;
  }

  // Asks the user for the video's information
  while (cin.peek() != EOF)
  {
    if (count >= numberOfVideos)
    {
      cerr << "Too many videos, giving up." << endl;
      return 1;
    }
    else
    {
      getline(cin, tl);
      getline(cin, url);
      getline(cin, cmmnt);
      cin >> vidLen;
      cin >> rate;
      videos[count] = new Video(tl, url, cmmnt, vidLen, rate);
      ++count;
    }
    cin.ignore();
  }

  // Sorts the array of Videos by rating highest to lowest
  if (method == "rating")
  {
    for (int j = count - 1; j > 0; j--)
    {
      for (int i = 0; i < count - 1; i++) 
      {
        if (videos[i] -> getRating() < videos[i + 1] -> getRating())
        {
          swap(videos[i], videos[i + 1]);
        }
      }
    }
  }

  // Sorts the array of Videos by length from shortest to longest
  else if (method == "length")
  {
    for (int j = count - 1; j > 0; j--)
    {
      for (int i = 0; i < count - 1; i++) 
      {
        if ((videos[i] -> getLength()) > (videos[i + 1] -> getLength()))
        {
          swap(videos[i], videos[i + 1]);
        }
      }
    }
  }

  // Sorts the array of Videos in alphabetical order
  else if (method == "title")
  {
    for (int j = count -1; j > 0; j--)
    {
      for (int i = 0; i < count - 1; i++) 
      {
        if (videos[i] -> getTitle() > videos[i + 1] -> getTitle())
        {
          swap(videos[i], videos[i + 1]);
        }
      }
    }
  }

  // Checks that there are Videos in the array
  if (count > 0)
  {

    // Prints out the now sorted array of Videos
    for (int i = 0; i < count; ++i)
    {
      videos[i] -> print();
    }
  }

  // Deletes the memory allocated to the Video array
  for (int i = count; i < 0; --i)
  {
    delete videos[i];
  }

  return 0;
}
