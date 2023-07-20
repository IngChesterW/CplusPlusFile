//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
//direccion del .data
{  nomArch="Alumnos.dat";
   nomIdxCod="codi.idx";
   pf= new fstream(nomArch.c_str(),ios::in|ios::binary);//modo de apertura(lectura y escritura)(Se creo un nuevo objeto de la clase fs)
   if (pf->fail()){
	   delete(pf);
	   pf=new fstream(nomArch.c_str(),ios::out|ios::binary);
   }
   pf->close();
   delete(pf);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action){
 // pf->flush();// se vacia el buffer
 //pf->close();// cerrar el archivo
 //delete pf; // se destruye el objeto que se creo
}
//---------------------------------------------------------------------------
//pasar a carlos brayan 777
void __fastcall TForm1::Button1Click(TObject *Sender){
	bool hallado=false;
	AnsiString cad;
	RegAlumno reg,regNuevo;
	regNuevo.mark='0';//no marcado para borrar
	regNuevo.cod=StrToInt(Edit1->Text);
	//regNuevo.nom=Edit2->Text.c_str();  //estudiar strcpy
	cad=Edit2->Text;
	strcpy(regNuevo.nom,cad.c_str());
	cad=Edit3->Text;
	strcpy(regNuevo.dir,cad.c_str());
	cad=MaskEdit1->Text;
	regNuevo.fecha.dia=StrToInt(cad.SubString(1,2));
	regNuevo.fecha.mes=StrToInt(cad.SubString(4,2));
	regNuevo.fecha.año=StrToInt(cad.SubString(7,4));
	pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary); //app de adicionar
if (pf->is_open()) {
   do {
	  pf->read((char *)&reg,sizeof(reg)); //el metodo sizeof da el tamños de la cadena en bynario
	  hallado=(reg.cod==regNuevo.cod)&&(reg.mark!='*');
   }while(!hallado && !pf->eof());
   if (hallado) {
	   pf->seekg(-sizeof(reg),ios::cur);//Investigar seekg,seekp
   }else{
	   pf->seekg(0,ios::end);
   }
   pf->write((char *)&regNuevo,sizeof(regNuevo));
   Edit1->Text="";Edit2->Text="";Edit3->Text="";MaskEdit1->Text="  /  /  ";
   Edit1->SetFocus();
   pf->close();
}
/*
if (pf->is_open()) {
   pf->write((char *)&regNuevo,sizeof(regNuevo)); //el metodo sizeof da el tamños de la cadena en bynario
   Edit1->Text="";Edit2->Text="";Edit3->Text="";MaskEdit1->Text="  /  /  ";
   Edit1->SetFocus();
   pf->close();
}
*/
pf->flush();
delete pf;
}
//---------------------------------------------------------------------------
 //pasar a carlos
 Cardinal StrtoInt(AnsiString cad){
 Cardinal nu=0;
 for (byte i = 1; i <=cad.Length(); i++) {
	  if ((cad[i]>='0')&&(cad[i]<='9')) {
		  nu=nu*10+cad[i]-48;
	  }
 }
 return nu;
}
 void __fastcall TForm1::Edit1Exit(TObject *Sender)
{//este edit busca a los alumnos popr registro al momento de salir de edit1
//es recomendable apagar este codigo cuando estas metiendo los datos de alumno
 bool hallado=false;
 RegAlumno reg;
 Word codi=StrtoInt(Edit1->Text);
 pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
 if (pf->is_open()){
	do { //busca el codigo en el archivo
	  pf->read((char*)&reg,sizeof(reg));
	  hallado=(reg.cod==codi)&&(reg.mark!='*');
	}while(!hallado && !pf->eof());
	if (hallado) {//si lo encuentra, pone los datos en pantalla
		Edit2->Text=reg.nom;
		Edit3->Text=reg.dir;
		MaskEdit1->Text=IntToStr(reg.fecha.dia)+'/'+IntToStr(reg.fecha.mes)+'/'+IntToStr(reg.fecha.año);
		Edit2->SetFocus();//investigar como funciona los mask edit, la funcion setfocus
	}else{// sino, limpia la pantalla, setfocus sirve para que el cursor vaya hacia allañññ
		Edit2->Text="";Edit3->Text="";MaskEdit1->Text="";
	}
 }
 pf->close();
 delete pf;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender){
bool hallado=false;
RegAlumno reg;
Word cod; reg.mark='0';
cod=StrToInt(Edit1->Text);
pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
  if (pf->is_open()){
	do { //busca el codigo en el archivo
	  pf->read((char*)&reg,sizeof(reg));
	  hallado=(reg.cod==cod)&&(reg.mark!='*');
	}while(!hallado && !pf->eof());
	if (hallado) {//si lo encuentra, pone los datos en pantalla
	   reg.mark='*';//marcado como borrado
	   pf->seekg(-sizeof(reg),ios::cur);
	   pf->write((char*)&reg,sizeof(reg));
	   //limpiar
	   Edit1->Text="";Edit2->Text="";Edit3->Text="";MaskEdit1->Text="";
	   Edit1->SetFocus();
	}
  }
 pf->flush();//cuano hay write poner flush
 pf->close();
 delete pf;
}
//corregir y añadir el codigo del final del video
//---------------------------------------------------------------------------
void __fastcall TForm1::Indices2Click(TObject *Sender)
{//por codigo
//"codi.idx" se llama el archivo que se crea del indice
RegAlumno reg;
RegIdxCod regIdx;
fstream pix (nomIdxCod.c_str(), ios::out|ios::trunc|ios::binary);
pf=new fstream (nomArch.c_str(), ios::in|ios::binary);
//HACER LA TAREA
	do{
		regIdx.pos=pf->tellp();
		pf->read((char *)&reg, sizeof (reg));
		if (!pf->eof() && (reg.mark!='*')){
			regIdx.cod=reg.cod;
			pix.write((char *) &regIdx, sizeof (regIdx));
		}
	}while (!pf->eof());
	pf->close();
	delete(pf);
	pix.flush();
	pix.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PorNombre1Click(TObject *Sender)
{
//por nombre
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender){
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
MaskEdit1->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender){
//NavegadorIdx
  RegIdxCod reg;
  RegAlumno regA;
  Button5->Enabled=true;
  Button6->Enabled=true;
  Button7->Enabled=true;
  pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
  pIdx=new fstream(nomIdxCod.c_str(),ios::in|ios::binary);
  if (pIdx->is_open()) {
	  pIdx->read((char*)&reg,sizeof(reg));
	  if (!pIdx->eof()) {
		  pf->seekp(reg.pos,ios::beg);
		  pf->read((char *)&regA,sizeof(regA));
		  Edit1->Text=regA.cod;
		  Edit2->Text=regA.nom;
		  Edit3->Text=regA.dir;
		  MaskEdit1->Text=IntToStr(regA.fecha.dia)+"/"+IntToStr(regA.fecha.mes)+"/"+IntToStr(regA.fecha.año);
	  }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender){
	pf->close();
	pIdx->close();
	delete (pf);
	delete(pIdx);
	Button5->Enabled=false;
	Button6->Enabled=false;
	Button7->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender){
  RegIdxCod reg;
  RegAlumno regA;
  if (pIdx->is_open()) {
	  pIdx->read((char*)&reg,sizeof(reg));
	  if (!pIdx->eof()) {
		  pf->seekp(reg.pos,ios::beg);
		  pf->read((char *)&regA,sizeof(regA));
		  Edit1->Text=regA.cod;
		  Edit2->Text=regA.nom;
		  Edit3->Text=regA.dir;
		  MaskEdit1->Text=IntToStr(regA.fecha.dia)+"/"+IntToStr(regA.fecha.mes)+"/"+IntToStr(regA.fecha.año);
		  Button6->Enabled=true;
		  Button5->Enabled=true;
	  } else {
		 pIdx->close();
		 delete(pIdx);
		 pIdx=new fstream(nomIdxCod.c_str(),ios::in|ios::binary);
		 pIdx->seekp(0,ios::end);
		 Button6->Enabled=false;  //anulamos el avance adelante
		 Button5->Enabled=true;//habilitamos el retroceso
	  }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender){
RegIdxCod reg;
  RegAlumno regA;
  Cardinal p;
 if (pIdx->is_open()) {
	p=pIdx->tellp();
	if (p<=sizeof(reg)){ //si está en el primer registro del idx
	  Button5->Enabled=false;
	}else {
	  pIdx->seekp(-2*sizeof(reg),ios::cur);
	  pIdx->read((char*)&reg,sizeof(reg));
	  if (!pIdx->eof()) {
		  pf->seekp(reg.pos,ios::beg);
		  pf->read((char *)&regA,sizeof(regA));
		  Edit1->Text=regA.cod;
		  Edit2->Text=regA.nom;
		  Edit3->Text=regA.dir;
		  MaskEdit1->Text=IntToStr(regA.fecha.dia)+"/"+IntToStr(regA.fecha.mes)+"/"+IntToStr(regA.fecha.año);
		  Button5->Enabled=true;
		  Button6->Enabled=true;
	  }
	}
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ordenar2Click(TObject *Sender)
{
fstream f(nomIdxCod.c_str(),ios::in|ios::out|ios::binary);
  RegIdxCod reg,regM;
  bool fin=false;
  Cardinal p,i,pm,z;
  if (f.is_open()) {
	p=0;
	while (!fin){
	  i=0; pm=p;
	  f.seekg(p);//,ios::beg);//al inicio del archivo
	  while (!f.eof()){ //busca el menor
		 if (p==f.tellp()){//si es el primer registro
			f.read((char *)&reg,sizeof(reg));
			regM=reg;
			z=f.tellp();
		 } else {
			f.read((char *)&reg,sizeof(reg));
			z=f.tellp();
		 }
		 if (!f.eof()) {
			i++;
			if (reg.cod<regM.cod) {
			   regM=reg;
			   pm=f.tellp()-sizeof(reg);
			}
		 }
	  }
	  fin= i<=1;
	  if (!fin) {
		  //f.flush();
		  f.close();
		  f.open(nomIdxCod.c_str(),ios::in|ios::out|ios::binary);
		  f.seekg(p);
		  f.seekp(p);
		  z=f.tellp();
		if(p!=pm){//intercambia el menor con el de la pos.p
		  f.read((char *)&reg,sizeof(reg));
		  z=f.tellp();
		  f.seekp(p);//,ios::beg);
		  z=f.tellp();
		  f.write((char *)&regM,sizeof(reg));
		  z=f.tellp();
		  f.seekp(pm);//,ios::beg);
		  z=f.tellp();
		  f.write((char *)&reg,sizeof(reg));
		  z=f.tellp();
		}
	  }
	  p=p+sizeof(reg);
	}
  }
	f.flush();
	f.close();
/*	RegIdxCod reg;
	reg.cod=20; reg.pos=150; f.write((char*)&reg,sizeof(reg));
	reg.cod=25; reg.pos=50;  f.write((char*)&reg,sizeof(reg));
	reg.cod=30; reg.pos=300; f.write((char*)&reg,sizeof(reg));
	reg.cod=40; reg.pos=250; f.write((char*)&reg,sizeof(reg));
	reg.cod=50; reg.pos=200; f.write((char*)&reg,sizeof(reg));
	reg.cod=70; reg.pos=350; f.write((char*)&reg,sizeof(reg));
	f.close();*/
}
//---------------------------------------------------------------------------

