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

void __fastcall TForm1::ButtonSave1Click(TObject *Sender)
{
 	if(SaveDialog1->Execute()){
		FILE *f = fopen (AnsiString(SaveDialog1->FileName).c_str(),"wb");
		fwrite (&orderdb[0],sizeof(order),iMax,f);
		fclose(f);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpen1Click(TObject *Sender)
{
 	if(OpenDialog1->Execute()){
		FILE *f = fopen (AnsiString(OpenDialog1->FileName).c_str(),"rb");
		orderdb.clear();
		do{
			order s;
			fread(&s,sizeof(order),1,f);
			if(feof(f)) break;
			orderdb.push_back(s);
		} while(!feof(f));
		iMax=orderdb.size();
		iCur=0;
		ShowRecord();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	if(iMax>0){
		orderdb.erase(orderdb.begin()+iCur);
		iMax--;
		iCur--;
		ShowRecord();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{


  if(orderdb.size()!=0){
		order s;
		std::vector<order>::iterator p;
		strcpy(s.name,AnsiString(EditSearch->Text).c_str());
		strcpy(s.phone,AnsiString(EditSearch->Text).c_str());
		strcpy(s.address,AnsiString(EditSearch->Text).c_str());
		p=std::find(orderdb.begin(),orderdb.end(),s);
		iCur=p-orderdb.begin();
		if(iCur<iMax) ShowRecord();
	}
}
//---------------------------------------------------------------------------

