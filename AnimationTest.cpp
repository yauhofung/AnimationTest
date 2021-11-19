#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// begins animation
void animate(int mode, char character, int limit, int frequency)
{
  int i = 1;
  // loops forever
  while (true)
  {
    // loops forward
    while (i < limit)
    {
      system("cls");
      // prints characters for each step
      for (int j = 0; j < i; j++)
      {
        // detects diagonal mode
        if (mode == 3)
        {
          // indents each line
          for (int k = 0; k < j; k++)
          {
            cout << ' ';
          }
        }
        cout << character;
        // detects vertical and diagonal mode
        if (mode == 2 || mode == 3)
        {
          cout << endl;
        }
      }
      this_thread::sleep_for(chrono::milliseconds(1000 / frequency));
      i++;
    }
    // loops backward
    while (i > 1)
    {
      system("cls");
      // prints characters for each step
      for (int j = 0; j < i; j++)
      {
        // detects diagonal mode
        if (mode == 3)
        {
          // indents each line
          for (int k = 0; k < j; k++)
          {
            cout << ' ';
          }
        }
        cout << character;
        // detects vertical and diagonal mode
        if (mode == 2 || mode == 3)
        {
          cout << endl;
        }
      }
      this_thread::sleep_for(chrono::milliseconds(1000 / frequency));
      i--;
    }
  }
}

int main()
{
  cout << "===== Yau Ho's Animation Test =====" << endl;

  cout << "(1) Horizontal" << endl;
  cout << "(2) Vertical" << endl;
  cout << "(3) Diagonal" << endl;
  cout << "Animation mode: ";
  int mode;
  cin >> mode;

  cout << "Character to animate: ";
  char character;
  cin >> character;

  cout << "Number of characters: ";
  int limit;
  cin >> limit;

  cout << "Frequency in Hz: ";
  int frequency;
  cin >> frequency;

  animate(mode, character, limit, frequency);

  return 0;
}