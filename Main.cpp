//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Define.h"
#include "libxl_functions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxBar"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinsdxBarPainter"
#pragma link "dxSkinsdxRibbonPainter"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvMemo"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
#pragma link "libxl.lib"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	InitProgram();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitProgram() {

	// Default Page Setting
	Notebook_Main->PageIndex = 0; // Default Page.

	// Init Grid
	InitGrid();

	// Init Libxl
	InitConfigExcelFile();

	PrintMsg(L"Init Complete");
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitConfigExcelFile() {

	m_Book = xlCreateXMLBook();
	if(m_Book) {
		m_Book->setKey(L"JungWook Son", L"windows-2124230806c1e30f66bf6365a7l1hdm8");
		if(m_Book->load(L"Config.xlsx")) {
			if(LoadSheet(L"Test")) PrintMsg(L"Success to load sheet");
		} else {
			PrintMsg(L"Fail to Load Excel File");
			return;
		}
	} else {
		PrintMsg(L"Fail to Create Book");
		return;
	}
	PrintMsg(L"Config Init Complete");
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitGrid() {
	grid_Protocol->Cells[0][0] = L"Idx";
	grid_Protocol->Cells[1][0] = L"Bit 7";
	grid_Protocol->Cells[2][0] = L"Bit 6";
	grid_Protocol->Cells[3][0] = L"Bit 5";
	grid_Protocol->Cells[4][0] = L"Bit 4";
	grid_Protocol->Cells[5][0] = L"Bit 3";
	grid_Protocol->Cells[6][0] = L"Bit 2";
	grid_Protocol->Cells[7][0] = L"Bit 1";
	grid_Protocol->Cells[8][0] = L"Bit 0";
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ExitProgram() {

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PrintMsg(UnicodeString _str) {
	int t_Line = memo->Lines->Add(_str);
	memo->SetCursor(0, t_Line);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ClickMenuButton(TObject *Sender)
{
	TdxBarLargeButton* p_Btn = (TdxBarLargeButton*)Sender;
	int t_Tag = p_Btn->Tag;
	Notebook_Main->PageIndex = t_Tag;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::grid_ProtocolGetAlignment(TObject *Sender, int ARow, int ACol,
		  TAlignment &HAlign, TVAlignment &VAlign)
{
	HAlign = taCenter;
	VAlign = vtaCenter;
}
//---------------------------------------------------------------------------

bool __fastcall TFormMain::LoadSheet(UnicodeString _SheetName) {
#if 0
	libxl::Format* format = NULL;
	libxl::Sheet* p_Sheet = getSheetByName(m_Book, L"Sheet1");
	PrintMsg(p_Sheet->readNum(0, 0, &format));
#endif

	// Common
	UnicodeString tempStr = L"";
	libxl::Sheet* t_pSheet = NULL;
	libxl::Format* t_pFormat = NULL;
	int t_RowLast = 0;
	int t_TotalByteCount = 0;
	bool t_bIsMerge = false;

	int t_RowStart = 0;
	int t_RowEnd = 0;
	int t_ColStart = 0;
	int t_ColEnd = 0;

	int t_gridRow = 0;
	int t_gridCol = 0;

	int t_merge_row_first = 0;
	int t_merge_col_first = 0;
	int t_merge_row_last = 0;
	int t_merge_col_last = 0;

	int t_H_gap = 0;
	int t_V_gap = 0;

	// Load Sheet
	t_pSheet = getSheetByName(m_Book, _SheetName.w_str());
	if(!t_pSheet) {
		tempStr = L"Fail to Load sheet : ";
		tempStr += _SheetName;
		PrintMsg(tempStr);
		return false;
	}

	// Get Last Row Information
	t_RowLast = t_pSheet->lastRow();
	tempStr.sprintf(L"Last Row : %d", t_RowLast);
	PrintMsg(tempStr);

	// Get Row/Col Information
	t_RowStart = DEFAULT_PROTOCOL_INFO_LINE_COUNT;
	t_RowEnd = t_RowLast;
	t_ColStart = DEFAULT_PROTOCOL_COL_START;
	t_ColEnd = DEFAULT_PROTOCOL_COL_START + 7;

	// Set Row Count
	t_TotalByteCount = t_RowLast - DEFAULT_PROTOCOL_INFO_LINE_COUNT;
	grid_Protocol->RowCount = t_TotalByteCount + 1; // +1 is Fixed Row

	// Merge Sync
	t_gridRow = 1;
	t_gridCol = 1;
	for(int row = t_RowStart ; row < t_RowEnd ; row++) {
		for(int col = t_ColStart ; col < t_ColEnd ; col++) {
			t_bIsMerge = t_pSheet->getMerge(row, col, &t_merge_row_first, &t_merge_row_last, &t_merge_col_first, &t_merge_col_last);
			t_gridCol = col - t_ColStart + 1;
			if(t_bIsMerge) {
				t_H_gap = t_merge_col_last - t_merge_col_first + 1; // +1 is essential
				t_V_gap = t_merge_row_last - t_merge_row_first;
				grid_Protocol->MergeCells(t_gridCol, t_gridRow, t_H_gap, t_V_gap + 1);
				col += (t_H_gap - 1);
				row += t_V_gap;
				t_gridRow += t_V_gap;
			}
		}
		t_gridRow++;
		//t_gridCol = 1;
	}



	//t_bIsMerge = t_pSheet->getMerge(row, col, &t_merge_row_first, &t_merge_row_last, &t_merge_col_first, &t_merge_col_last);


	// Load Text Data
	for(int i = 0 ; i < t_TotalByteCount ; i++) {
		tempStr = getCellValue(t_pSheet, i + DEFAULT_PROTOCOL_INFO_LINE_COUNT, 2);
		grid_Protocol->Cells[0][i + 1] = tempStr;

		for(int j = 1 ; j < 9 ; j++) {
			tempStr = getCellValue(t_pSheet, i + DEFAULT_PROTOCOL_INFO_LINE_COUNT, j + 2);
			grid_Protocol->Cells[j][i + 1] = tempStr;
		}
	}



	return true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshGrid() {

	// Init belows...
	// Color
	// Merge
	// Text
}
//---------------------------------------------------------------------------
