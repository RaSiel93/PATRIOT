//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double Bonus, life, vrem=60;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
fire->Hide();
Image2->Hide();
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

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{vrem-=0.1;
Time->Caption=FloatToStr(ceil(vrem));
if (vrem<=0||life<=0) {
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Image2->Hide();
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
Image2->Left+=Speed;
if (Image2->Left>Image1->Width){
        Image2->Top=random(350);
        Image2->Left=-180;
        life--;
        lifeK->Caption=FloatToStr(life);
        }
if (Image2->Left<-Image2->Width) {
        Image2->Top=random(350);
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
sx1=Image2->Left;
sx2=Image2->Left+Image2->Width;
sy1=Image2->Top;
sy2=Image2->Top+Image2->Height;
rx1=Raketa1->Left;
rx2=Raketa1->Left+Raketa1->Width;
ry1=Raketa1->Top;
ry2=Raketa1->Top+Raketa1->Height;
if (!(rx1>sx2 || rx2<sx1 || ry1>sy2 || ry2<sy1)) {
        TPusk1->Enabled=false;
        Timer3->Enabled=true;
        fire->Top=Image2->Top;
        fire->Left=Raketa1->Left;
        fire->Show();
        Image2->Left=-180;
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
sx1=Image2->Left;
sx2=Image2->Left+Image2->Width;
sy1=Image2->Top;
sy2=Image2->Top+Image2->Height;
rx1=Raketa2->Left;
rx2=Raketa2->Left+Raketa2->Width;
ry1=Raketa2->Top;
ry2=Raketa2->Top+Raketa2->Height;
if (!(rx1>sx2 || rx2<sx1 || ry1>sy2 || ry2<sy1)) {
        TPusk2->Enabled=false;
        Timer3->Enabled=true;
        fire->Top=Image2->Top;
        fire->Left=Raketa2->Left;
        fire->Show();
        Image2->Left=-180;
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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BeginClick(TObject *Sender)
{
FonMenu->Hide();
PATRIOT->Hide();
Begin->Hide();
Vibor->Hide();
Options->Hide();
Exit->Hide();
life=3;
Bonus=0;

Timer1->Enabled=true;
Timer2->Enabled=true;
Image2->Show();
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

