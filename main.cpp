#include <windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{

	// At first let's determine whether there is Kaz layout or not
	bool isKazLayout = false;
	int num = GetKeyboardLayoutList(0,0);
	if (num!=0){
		HKL *lpList = new HKL[num]; 

		num = GetKeyboardLayoutList(num,lpList);
		for(int i=0; i<num; i++){
			if ((UINT)lpList[i] == 0x043F043F){
				isKazLayout = true;
				break;
			}
		}
		delete[] lpList;
	}
	HKL hkl = LoadKeyboardLayout(L"0000043F", KLF_ACTIVATE);

	// if KazLayout is already loaded, then unload it
	if (isKazLayout)
	 UnloadKeyboardLayout (hkl);
	//else
	//ActivateKeyboardLayout(hkl, KLF_REORDER);

	return 0;
}