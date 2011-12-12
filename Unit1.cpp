//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double Bonus=0,  life=3, vrem; int Image=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Image4->Hide();
B1->Hide();
B2->Hide();
Image1->Hide();
Image2->Hide();
Image3->Hide();
fire->Hide();
Samolet->Hide();
Pushka->Hide();
Pusk1->Hide();
Pusk2->Hide();
Raketa1->Hide();
Raketa2->Hide();
Time->Hide();
Vremya->Hide();
Pobeda->Hide();
Score->Hide();
lifeP->Hide();
lifeK->Hide();
Pobeda->Hide();
Score->Hide();
Poragenie->Hide();
Label1->Hide();

Mini1->Hide();
LBrest->Hide();
Mini2->Hide();
LGrodno->Hide();
Mini3->Hide();
LMinsk->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{vrem-=0.1;
Time->Caption=FloatToStr(ceil(vrem));
if (vrem<=0||life<=0) {
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Samolet->Hide();
        Pushka->Hide();
        Pusk1->Hide();
        Pusk2->Hide();
        Raketa1->Hide();
        Raketa2->Hide();
        Time->Hide();
        Vremya->Hide();
        if (life<=0)    Poragenie->Show();
        if (vrem<=0)    Pobeda->Show();
        Score->Show();
        TimerPob->Enabled=true;
        Label1->Font->Size=40;
        Label1->Top=100;
        Label1->Left=435;
        lifeP->Hide();
        lifeK->Hide();
        }
}
//---------------------------------------------------------------------------
int Speed=10;
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Randomize();
Samolet->Left+=Speed;
if (Samolet->Left>Image1->Width){
        Samolet->Top=random(350);
        Samolet->Left=-180;
        life--;
        lifeK->Caption=FloatToStr(life);
        }
if (Samolet->Left<-Samolet->Width) {
        Samolet->Top=random(350);
        Speed=(random(15)+8);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Form1->DoubleBuffered=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TPusk1Timer(TObject *Sender)
{Raketa1->Top-=10;
int sx1,sx2,sy1,sy2,rx1,rx2,ry1,ry2;
sx1=Samolet->Left;
sx2=Samolet->Left+Samolet->Width;
sy1=Samolet->Top;
sy2=Samolet->Top+Samolet->Height;
rx1=Raketa1->Left;
rx2=Raketa1->Left+Raketa1->Width;
ry1=Raketa1->Top;
ry2=Raketa1->Top+Raketa1->Height;
if (!(rx1>sx2 || rx2<sx1 || ry1>sy2 || ry2<sy1)) {
        TPusk1->Enabled=false;
        Timer3->Enabled=true;
        fire->Top=Samolet->Top;
        fire->Left=Raketa1->Left;
        fire->Show();
        Samolet->Left=-180;
        Raketa1->Top=Pusk1->Top-48;}
if (ry2<0){
        TPusk1->Enabled=false;
        Raketa1->Top=Pusk1->Top-48;}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pusk1Click(TObject *Sender)
{
TPusk1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TPusk2Timer(TObject *Sender)
{Raketa2->Top-=10;
int sx1,sx2,sy1,sy2,rx1,rx2,ry1,ry2;
sx1=Samolet->Left;
sx2=Samolet->Left+Samolet->Width;
sy1=Samolet->Top;
sy2=Samolet->Top+Samolet->Height;
rx1=Raketa2->Left;
rx2=Raketa2->Left+Raketa2->Width;
ry1=Raketa2->Top;
ry2=Raketa2->Top+Raketa2->Height;
if (!(rx1>sx2 || rx2<sx1 || ry1>sy2 || ry2<sy1)) {
        TPusk2->Enabled=false;
        Timer3->Enabled=true;
        fire->Top=Samolet->Top;
        fire->Left=Raketa2->Left;
        fire->Show();
        Samolet->Left=-180;
        Raketa2->Top=Pusk2->Top-48;}
if (ry2<0){
        TPusk2->Enabled=false;
        Raketa2->Top=Pusk2->Top-48;}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pusk2Click(TObject *Sender)
{
TPusk2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{double dh=3,dw=3;
  fire->Height+=dh;
  fire->Top-=dh*0.6;
  fire->Width+=dw;
  fire->Left-=dw*0.33;
  Bonus+=10;
  Label1->Caption=FloatToStr(Bonus);
  if (Bonus==5000) {Image4->Show();
                        Timer1->Enabled=0;
                        Timer2->Enabled=0;
                        Timer3->Enabled=0;
                        TimerPob->Enabled=0;}
  if (fire->Height>38)  {
        fire->Hide();
        Timer3->Enabled=false;
        fire->Height=10;
        fire->Width=10;
        }
}
//---------------------------------------------------------------------------
double B=0;
void __fastcall TForm1::TimerPobTimer(TObject *Sender)
{
if (B!=Bonus) {B+=10;
Label1->Caption=FloatToStr(B);}
if (B==Bonus) {
        B1->Show();
        if (life!=0) B2->Show();}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BeginClick(TObject *Sender)
{vrem=30; Bonus=0; life=3; B=0;
Samolet->Left=-180;
Label1->Left=670; Label1->Top=0;
Label1->Caption=FloatToStr(Bonus);
lifeK->Caption=FloatToStr(life);

FonMenu->Hide();
PATRIOT->Hide();
Begin->Hide();
Vibor->Hide();
Options->Hide();
Exit->Hide();

if (Image==1) Image1->Show();
if (Image==2) Image2->Show();
if (Image==3) Image3->Show();

Timer1->Enabled=true;
Timer2->Enabled=true;

Samolet->Show();
Pushka->Show();
Pusk1->Show();
Pusk2->Show();
Raketa1->Show();
Raketa2->Show();
Time->Show();
Vremya->Show();
lifeP->Show();
lifeK->Show();
Label1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExitClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ViborClick(TObject *Sender)
{
PATRIOT->Hide();
Begin->Hide();
Vibor->Hide();
Options->Hide();
Exit->Hide();

Mini1->Show();
LBrest->Show();
Mini2->Show();
LGrodno->Show();
Mini3->Show();
LMinsk->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mini1Click(TObject *Sender)
{Image=1;
PATRIOT->Show();
Begin->Show();
Vibor->Show();
Options->Show();
Exit->Show();

Mini1->Hide();
LBrest->Hide();
Mini2->Hide();
LGrodno->Hide();
Mini3->Hide();
LMinsk->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mini2Click(TObject *Sender)
{Image=2;
PATRIOT->Show();
Begin->Show();
Vibor->Show();
Options->Show();
Exit->Show();

Mini1->Hide();
LBrest->Hide();
Mini2->Hide();
LGrodno->Hide();
Mini3->Hide();
LMinsk->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mini3Click(TObject *Sender)
{Image=3;
PATRIOT->Show();
Begin->Show();
Vibor->Show();
Options->Show();
Exit->Show();

Mini1->Hide();
LBrest->Hide();
Mini2->Hide();
LGrodno->Hide();
Mini3->Hide();
LMinsk->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B1Click(TObject *Sender)
{
TimerPob->Enabled=false;
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;

FonMenu->Show();
PATRIOT->Show();
Begin->Show();
Vibor->Show();
Options->Show();
Exit->Show();

Image1->Hide();
Image2->Hide();
Image3->Hide();
B1->Hide();
B2->Hide();

fire->Hide();
Samolet->Hide();
Pushka->Hide();
Pusk1->Hide();
Pusk2->Hide();
Raketa1->Hide();
Raketa2->Hide();
Time->Hide();
Vremya->Hide();
Pobeda->Hide();
Score->Hide();
lifeP->Hide();
lifeK->Hide();
Pobeda->Hide();
Score->Hide();
Poragenie->Hide();
Label1->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B2Click(TObject *Sender)
{vrem=30; life+=1; B=0; Image+=1; if(Image==4) Image=1;

Samolet->Left=-180;
Label1->Hide(); Label1->Left=650; Label1->Top=0;
Label1->Caption=FloatToStr(Bonus);
lifeK->Caption=FloatToStr(life);

Image1->Hide();
Image2->Hide();
Image3->Hide();
B1->Hide();
B2->Hide();

if (Image==1) Image1->Show();
if (Image==2) Image2->Show();
if (Image==3) Image3->Show();

Timer1->Enabled=true;
Timer2->Enabled=true;
TimerPob->Enabled=false;
Score->Hide();
Pobeda->Hide();

Samolet->Show();
Pushka->Show();
Pusk1->Show();
Pusk2->Show();
Raketa1->Show();
Raketa2->Show();
Time->Show();
Vremya->Show();
lifeP->Show();
lifeK->Show();
Label1->Show();
}
//---------------------------------------------------------------------------

