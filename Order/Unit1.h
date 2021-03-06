//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <vector>
#include <String.h>
#include <algorithm>
//---------------------------------------------------------------------------

class order{
	public:
		char name [150];
		char phone [50];
		int order;
		char address [50] ;

		bool friend operator==(const order &a, const order &b){
		return(
			strcmp (a.name, b.name)==0 ||
			strcmp (a.phone, b.phone)==0 ||
			strcmp (a.address, b.address)==0 ||
			a.order==b.order
		);
	}
};



extern int iCur, iMax;
extern std:: vector <order> orderdb;


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelCurrent;
	TButton *ButtonRight;
	TButton *ButtonLeft;
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
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TImageList *ImageList1;
	TMainMenu *MainMenu1;
	TMenuItem *ButtonFile;
	TMenuItem *ButtonSave1;
	TMenuItem *ButtonOpen1;
	TMenuItem *N2;
	TMenuItem *ButtonEdit;
	TButton *Button1;
	TLabel *Label1;
	TImageList *ImageList2;
	TMenuItem *ButtonSearch;
	TEdit *EditSearch;
	TLabel *Label2;
	TButton *Search;
	TButton *ButtonClose;
	TCheckBox *Check1;
	TCheckBox *Check2;
	TCheckBox *Check3;
	TCheckBox *Check4;
	TButton *Button2;
	TButton *ButtonCancel;
	void __fastcall ShowRecord();
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonLeftClick(TObject *Sender);
	void __fastcall ButtonRightClick(TObject *Sender);
	void __fastcall ButtonSave1Click(TObject *Sender);
	void __fastcall ButtonOpen1Click(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall ButtonEditClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
