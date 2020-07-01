//---------------------------------------------------------------------------

#pragma hdrstop

#include "libxl_functions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Sheet* __fastcall getSheetByName(Book* book, const wchar_t* name) {

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
