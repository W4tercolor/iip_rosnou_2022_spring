//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "String.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int iCur=-1, iMax=0;
std:: vector <order> orderdb;


void __fastcall TForm1::ShowRecord(){
	if(orderdb.size()!=0){
		EditOrder->Text=IntToStr(orderdb[iCur].order);
		EditName->Text=orderdb[iCur].name;
		EditAddress->Text=orderdb[iCur].address;
		EditPhone->Text=orderdb[iCur].phone;
	}
	LabelCount->Caption = IntToStr(iMax);
	LabelCurrent->Caption = IntToStr(iCur+1);
}

void __fastcall TForm1::ClearFields(){
	EditOrder->Text="";
	EditName->Text="";
	EditAddress->Text="";
	EditPhone->Text="";
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	if(EditOrder == "" || EditName->Text == "" || EditAddress->Text == "" || EditPhone->Text == ""){
		MessageBox(0,L"��� ���������� ������ ���������� ��������� ��� ����!", L"������!", MB_OK + MB_ICONWARNING);
	}
	orderdb.push_back(order());
	strcpy(orderdb[iMax].name,AnsiString(EditName->Text).c_str());
	orderdb[iMax].order = EditOrder->Text.ToInt();
	strcpy(orderdb[iMax].phone,AnsiString(EditPhone->Text).c_str());
	strcpy(orderdb[iMax].address,AnsiString(EditAddress->Text).c_str());
	iCur=iMax;
	iMax++;
	ShowRecord();
	ClearFields();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonLeftClick(TObject *Sender)
{
	if(iCur > 0) iCur--;
	ShowRecord();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRightClick(TObject *Sender)
{
	if(iCur < iMax-1) iCur++;
	ShowRecord();
}
//---------------------------------------------------------------------------

