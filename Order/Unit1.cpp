//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "String.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int iCur=0,iMax=0;
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
	Button1->Hide();
	EditSearch->Hide();
	Search->Visible= false;
		ButtonClose->Visible= false;
	ButtonRight->Visible= false;
	 ButtonLeft->Visible= false;
	 ButtonAdd->Visible= false;
	 ButtonDelete->Visible= false;
	 Button1->Visible= false;
	 EditName->Visible= false;
	 EditOrder->Visible= false;
	 EditPhone->Visible= false;
	 EditAddress->Visible= false;
	 Form1->EditName->Text="";
	 Form1->EditOrder->Text="";
	 Form1->EditPhone->Text="";
	 Form1->EditAddress->Text="";
	 LabelName->Visible= false;
	 LabelOrder->Visible= false;
	 LabelPhone->Visible= false;
	 LabelAddress->Visible= false;
	 LabelCount->Visible= false;
	 LabelCurrent->Visible= false;
	 Label2->Visible= false;
	 Label1->Visible= false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	Form1->EditName->Text="";
	Form1->EditOrder->Text="";
	Form1->EditPhone->Text="";
	Form1->EditAddress->Text="";
	iCur=iMax;
	iMax++;
	LabelCount->Caption = iMax;
	LabelCurrent->Caption = iCur+1;

	ButtonLeft->Visible= false;
	 ButtonAdd->Visible=false;
	 ButtonDelete->Visible= false;
	 Button1->Visible= true;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;
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
		ButtonRight->Visible= true;
	}
	 ButtonLeft->Visible= true;
	 ButtonAdd->Visible= true;
	 ButtonDelete->Visible= true;
	 Button1->Visible= false;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 Form1->EditName->Text="";
	 Form1->EditOrder->Text="";
	 Form1->EditPhone->Text="";
	 Form1->EditAddress->Text="";
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;
	 ShowRecord();

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
	EditSearch->Visible = true;
	Search->Visible= true;
	ButtonClose->Visible= true;
	 ButtonRight->Visible= false;
	 ButtonLeft->Visible= false;
	 ButtonAdd->Visible= false;
	 ButtonDelete->Visible= false;
	 Button1->Visible= false;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{

	 Button1->Visible= true;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 iCur=iMax;
	 iMax++;
	 LabelCount->Caption = iMax;
	 LabelCurrent->Caption = iCur+1;
	 Form1->EditName->Text="";
	 Form1->EditOrder->Text="";
	 Form1->EditPhone->Text="";
	 Form1->EditAddress->Text="";
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(EditOrder == "" || EditName->Text == "" || EditAddress->Text == "" || EditPhone->Text == ""){
		MessageBox(0,L"��� ���������� ������ ���������� ��������� ��� ����!", L"������!", MB_OK + MB_ICONWARNING);
	}
	orderdb.push_back(order());
	strcpy(orderdb[iCur].name,AnsiString(EditName->Text).c_str());
	orderdb[iCur].order = EditOrder->Text.ToInt();
	strcpy(orderdb[iCur].phone,AnsiString(EditPhone->Text).c_str());
	strcpy(orderdb[iCur].address,AnsiString(EditAddress->Text).c_str());

	 ButtonRight->Visible= true;
	 ButtonLeft->Visible= true;
	 ButtonAdd->Visible= true;
	 ButtonDelete->Visible= true;
	 Button1->Visible= false;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
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

void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
	EditSearch->Visible = false;
	Search->Visible= false;
	ButtonClose->Visible= false;
	ButtonRight->Visible= true;
	 ButtonLeft->Visible= true;
	 ButtonAdd->Visible= true;
	 ButtonDelete->Visible= true;
	 Button1->Visible= false;
	 EditName->Visible= true;
	 EditOrder->Visible= true;
	 EditPhone->Visible= true;
	 EditAddress->Visible= true;
	 LabelName->Visible= true;
	 LabelOrder->Visible= true;
	 LabelPhone->Visible= true;
	 LabelAddress->Visible= true;
	 LabelCount->Visible= true;
	 LabelCurrent->Visible= true;
	 Label2->Visible= true;
	 Label1->Visible= true;
}
//---------------------------------------------------------------------------

