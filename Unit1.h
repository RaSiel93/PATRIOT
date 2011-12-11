//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *Timer1;
        TImage *Image2;
        TTimer *Timer2;
        TImage *Raketa1;
        TTimer *TPusk1;
        TTimer *TPusk2;
        TImage *Pusk1;
        TImage *Raketa2;
        TImage *Pusk2;
        TImage *Pushka;
        TLabel *Label1;
        TImage *fire;
        TTimer *Timer3;
        TLabel *Time;
        TLabel *Vremya;
        TLabel *Pobeda;
        TLabel *Score;
        TLabel *lifeP;
        TLabel *lifeK;
        TTimer *TimerPob;
        TLabel *Poragenie;
        TImage *FonMenu;
        TLabel *PATRIOT;
        TButton *Begin;
        TButton *Vibor;
        TButton *Exit;
        TButton *Options;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TPusk1Timer(TObject *Sender);
        void __fastcall Pusk1Click(TObject *Sender);
        void __fastcall TPusk2Timer(TObject *Sender);
        void __fastcall Pusk2Click(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall TimerPobTimer(TObject *Sender);
        void __fastcall BeginClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
