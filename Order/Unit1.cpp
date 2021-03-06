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
	 Check1->Visible= false;
	 Check2->Visible= false;
	 Check3->Visible= false;
	 Check4->Visible= false;
	 Button2->Visible= false;
	 ButtonSearch ->Visible= false;
     ButtonCancel->Visible=false;
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

	ButtonCancel->Visible=false;
	ButtonRight->Visible= false;
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
	 EditName->Enabled=true;
	 EditOrder->Enabled=true;
	 EditPhone->Enabled=true;
	 EditAddress->Enabled=true;
	 Button2->Visible= true;

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

	}
	ButtonRight->Visible= true;
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
	 EditName->Enabled=false;
	 EditOrder->Enabled=false;
	 EditPhone->Enabled=false;
	 EditAddress->Enabled=false;
     if(iMax>2){
		ButtonSearch ->Visible= true;
	}
	 ShowRecord();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	if(iMax==1){
		iMax=0;
		iCur=0;

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
	 Check1->Visible= false;
	 Check2->Visible= false;
	 Check3->Visible= false;
	 Check4->Visible= false;
	 Button2->Visible= false;
	 ButtonSearch ->Visible= false;
	}
	if(iMax>1){
		orderdb.erase(orderdb.begin()+iCur);
		iMax--;
		if(iCur!=0){
		iCur--;
		}
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
	 Check1->Visible= true;
	 Check2->Visible= true;
	 Check3->Visible= true;
	 Check4->Visible= true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	Form1->EditName->Text="";
	Form1->EditOrder->Text="";
	Form1->EditPhone->Text="";
	Form1->EditAddress->Text="";
	iCur=iMax;
	iMax++;
	LabelCount->Caption = iMax;
	LabelCurrent->Caption = iCur+1;

	ButtonRight->Visible= false;
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
	 EditName->Enabled=true;
	 EditOrder->Enabled=true;
	 EditPhone->Enabled=true;
	 EditAddress->Enabled=true;
	 Button2->Visible= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(EditOrder == "" || EditName->Text == "" || EditAddress->Text == "" || EditPhone->Text == ""){
		MessageBox(0,L"??? ?????????? ?????? ?????????? ????????? ??? ????!", L"??????!", MB_OK + MB_ICONWARNING);
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
	 EditName->Enabled=false;
	 EditOrder->Enabled=false;
	 EditPhone->Enabled=false;
	 EditAddress->Enabled=false;
     if(iMax>2){
		ButtonSearch ->Visible= true;
	}
	 Button2->Visible= false;
	 ButtonCancel->Visible= false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
{
	int i=0;
	order n;
	std::vector<order>::iterator p;
	if (Check1->Checked == true) {
		n.order = EditSearch->Text.ToInt();
	}
	if (Check2->Checked == true) {
		strcpy(n.name,AnsiString(EditSearch->Text).c_str());
	}
	if (Check3->Checked == true) {
		strcpy(n.address,AnsiString(EditSearch->Text).c_str());
	}
	if (Check4->Checked == true) {
		strcpy(n.phone,AnsiString(EditSearch->Text).c_str());
	}

	search:
	p=std::find(orderdb.begin()+i,orderdb.end(),n);
	if(iCur== p - orderdb.begin()){
		i++;
		goto search;
	}
	iCur=p-orderdb.begin();
	if(iCur<iMax){
		ShowRecord();
		LabelCurrent->Caption = iCur+1;
	}else{
		iCur=0;
		LabelCurrent->Caption = 1;
		ShowRecord();
		MessageBox(0,L"?????? ?? ???????", L"", MB_OK);
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
	 Check1->Visible= false;
	 Check2->Visible= false;
	 Check3->Visible= false;
	 Check4->Visible= false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEditClick(TObject *Sender)
{
	 ButtonCancel->Visible=true;
	 EditName->Enabled=true;
	 EditOrder->Enabled=true;
	 EditPhone->Enabled=true;
	 EditAddress->Enabled=true;
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
	 Button2->Visible= false;
	 ButtonAdd->Visible= false;
	 ButtonDelete->Visible= false;
	 ButtonRight->Visible= false;
	 ButtonLeft->Visible= false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(iMax==1){
		iMax=0;
		iCur=0;

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
	 Check1->Visible= false;
	 Check2->Visible= false;
	 Check3->Visible= false;
	 Check4->Visible= false;
	 Button2->Visible= false;
	 ButtonSearch ->Visible= false;
	}
	if(iMax>1){
		iMax--;
		iCur--;
		ShowRecord();

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
	 Button2->Visible= false;
	 EditName->Enabled=false;
	 EditOrder->Enabled=false;
	 EditPhone->Enabled=false;
	 EditAddress->Enabled=false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCancelClick(TObject *Sender)
{
 if(iMax==1){
		iMax=0;
		iCur=0;

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
	 Check1->Visible= false;
	 Check2->Visible= false;
	 Check3->Visible= false;
	 Check4->Visible= false;
	 Button2->Visible= false;
	 ButtonSearch ->Visible= false;
	}
	if(iMax>1){
		ShowRecord();

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
	 ButtonCancel->Visible=false;
	 Button2->Visible= false;
	 EditName->Enabled=false;
	 EditOrder->Enabled=false;
	 EditPhone->Enabled=false;
	 EditAddress->Enabled=false;
	}
}
//---------------------------------------------------------------------------


