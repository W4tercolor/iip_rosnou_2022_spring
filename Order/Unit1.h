//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <vector>
#include <String.h>
//---------------------------------------------------------------------------

class order{
	public:
		char name [150];
		char phone [50];
		int order;
		char address [50] ;
};

extern int iCur, iMax;
extern std:: vector <order> orderdb;


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelCurrent;
	TButton *ButtonRight;
	TButton *ButtonLeft;
	TLabel *Label2;
	TLabel *LabelCount;
	TLabel *LabelOrder;
	TLabel *LabelName;
	TLabel *LabelPhone;
	TLabel *LabelAddress;
	TEdit *EditName;
	TEdit *EditAddress;
	TEdit *EditPhone;
	TButton *ButtonAdd;
	TButton *ButtonDelete;
	TEdit *EditOrder;
	void __fastcall ShowRecord();
	void __fastcall ClearFields();
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonLeftClick(TObject *Sender);
	void __fastcall ButtonRightClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif