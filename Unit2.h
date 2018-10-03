//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <ADODB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <vector>
#include <map>
#include <exception>
#include <KbmCoef>
//---------------------------------------------------------------------------
class CantFindCoefForClass: public std::exception
{
  virtual const char* what() const throw()
  {
    return "There is no coefficient for class";
  }
};

class TKBM : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DSKbmCoef;
        TDBGrid *GKbmCoef;
        TADOConnection *ADOCKbmCoef;
        TADOTable *kbmTable;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TStringGrid *Input;
        TLabel *userInfoLabel;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations of members
        std::vector<KbmCoefficient> kbmCoefs_;
private:	// User declarations of methods
        bool readAndValidateInput(std::map<int, int> &in);
        bool isDigits(const char* str);
        void calc(std::map<int, int>& in, std::string& cls, double& c);
        void getNextClass(KbmCoefficient& c, int payments);
        double getCoefByClass(const std::string& cls);
public:		// User declarations of methods
        __fastcall TKBM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKBM *KBM;
//---------------------------------------------------------------------------
#endif
