#include <iostream>
#include <ctime>
using namespace std;

// begins animation
void animate(int mode, int limit, int frequency)
{
  int i = 1;
  // loops forever
  while (true)
  {
    // detects static mode
    if (mode == 4)
    {
      system("cls");
      // row-by-row
      for (int i = 0; i < limit; i++)
      {
        // character-by-character
        for (int j = 0; j < limit; j++)
        {
          rand() % 2 ? cout << char(-37) : cout << ' ';
        }
        cout << endl;
      }
      _sleep(1000.0 / frequency);
    }
    else
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
          cout << char(-37);
          // detects vertical and diagonal mode
          if (mode == 2 || mode == 3)
          {
            cout << endl;
          }
        }
        cout << endl;
        _sleep(1000.0 / frequency);
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
          cout << char(-37);
          // detects vertical and diagonal mode
          if (mode == 2 || mode == 3)
          {
            cout << endl;
          }
        }
        cout << endl;
        _sleep(1000.0 / frequency);
        i--;
      }
    }
  }
}

int main()
{
  // disables cout buffering
  ios::sync_with_stdio(false);

  srand(time(NULL));

  cout << "===== Yau Ho's Animation Test =====" << endl;

  cout << "(1) Horizontal" << endl;
  cout << "(2) Vertical" << endl;
  cout << "(3) Diagonal" << endl;
  cout << "(4) Static" << endl;
  cout << "Animation mode: ";
  int mode;
  cin >> mode;

  cout << "Width/Height: ";
  int limit;
  cin >> limit;

  cout << "Frequency in Hz: ";
  int frequency;
  cin >> frequency;

  animate(mode, limit, frequency);

  return 0;
}