//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
#include <FStream>
//---------------------------------------------------------------------------
struct TFecha{  //tamaño de 4 bits
 byte dia;
 byte mes;
 Word año;
};
struct RegAlumno{  //contiene datos basicos
 Word cod;
 char nom[21];//cadena de 20 caracteres
 char dir[21];//cadena de 20 caracteres
 TFecha fecha;
 char mark; //marca de borrado-pasar a carlos
};
struct RegIdxCod{
	Word    cod;  //codigo del alumno
	Cardinal pos; //posicion en el archivos de datos
};
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TMaskEdit *MaskEdit1;
	TMainMenu *MainMenu1;
	TMenuItem *Indices1;
	TMenuItem *Indices2;
	TMenuItem *PorNombre1;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TMenuItem *Ordenar1;
	TMenuItem *Ordenar2;
	TMenuItem *PorNombre2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Indices2Click(TObject *Sender);
	void __fastcall PorNombre1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Ordenar2Click(TObject *Sender);
private:	// User declarations (aqui se declaran las variables globales)
	   fstream *pf, *pIdx;           //objeto puntero de archivo de la clase fstream
	   AnsiString nomArch,nomIdxCod;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
