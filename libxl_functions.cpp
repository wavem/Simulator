//---------------------------------------------------------------------------

#pragma hdrstop

#include "libxl_functions.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



libxl::Sheet* __fastcall TFormMain::getSheetByName(libxl::Book* book, const wchar_t* name) {

	int temp = book->sheetCount();
	for(unsigned short i = 0; i < book->sheetCount(); ++i)
	{
		if(wcscmp(book->getSheet(i)->name(), name) == 0)
		{
			return book->getSheet(i);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
