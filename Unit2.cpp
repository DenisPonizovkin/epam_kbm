//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <algorithm>
#include <sstream>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKBM *KBM;
//---------------------------------------------------------------------------
__fastcall TKBM::TKBM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TKBM::BitBtn1Click(TObject *Sender)
{
        Input->RowCount++;
}
//---------------------------------------------------------------------------
void __fastcall TKBM::FormCreate(TObject *Sender)
{
        Input->Cells[1][0] = "Year";
        Input->Cells[2][0] = "Number of paymants";

        kbmTable->First();
        for (int i = 0; i < kbmTable->RecordCount; i++) {
                if (i) Input->Cells[0][i] = i;

                KbmCoefficient kc;
                kc.class_ = std::string(
                                kbmTable->FieldByName("class")->AsString.c_str()
                                );
                std::string floatRu(
                        kbmTable->FieldByName("coef")->AsString.c_str()
                );
                std::replace(floatRu.begin(), floatRu.end(), ',', '.');
                kc.coef_ = atof(floatRu.c_str());
                kc.payment0 = std::string(
                                kbmTable->FieldByName("payment0")->AsString
                                .c_str()
                                );
                kc.payment1 = std::string(
                                kbmTable->FieldByName("payment1")->AsString
                                .c_str());
                kc.payment2 = std::string(
                                kbmTable->FieldByName("payment2")->AsString
                                .c_str());
                kc.payment3 = std::string(
                                kbmTable->FieldByName("payment3")->AsString
                                .c_str());
                kc.paymentOver3 = std::string(
                                kbmTable->FieldByName("payment_over_3")->AsString
                                .c_str());
                kbmCoefs_.push_back(kc);
                kbmTable->Next();
        }
        std::sort(kbmCoefs_.begin(), kbmCoefs_.end());
}
//---------------------------------------------------------------------------

void __fastcall TKBM::BitBtn2Click(TObject *Sender)
{
        std::map<int, int> in; // It is sorted by keys by default in ascending order.
        if (!readAndValidateInput(in)) {
                userInfoLabel->Color = clRed;
                userInfoLabel->Caption = "Your input is invalid";
        }

        userInfoLabel->Color = clBlack;
        std::string cls;
        double c = 0;
        try {
                calc(in, cls, c);
                std::stringstream ss;
                ss << "Class = " << cls << ", coef = " << c;
                userInfoLabel->Color = clGreen;
                userInfoLabel->Caption = ss.str().c_str();
        } catch (const std::exception& e) {
                userInfoLabel->Color = clRed;
                userInfoLabel->Caption = e.what();
        }
}
//---------------------------------------------------------------------------
bool  TKBM::readAndValidateInput(std::map<int, int> &in)
{
        for (int i = 1; i < Input->RowCount; i++) {
                const char* y = Input->Cells[1][i].c_str();
                const char* p = Input->Cells[2][i].c_str();

                if (!strlen(y) || !strlen(p)) {
                        return true;
                }

                if (isDigits(y) && isDigits(p)) {
                        std::pair<int, int> pair(atoi(y), atoi(p));
                        in.insert(pair);
                } else {
                        return false;
                }
        }
        return true;
}
//---------------------------------------------------------------------------
bool TKBM::isDigits(const char* str)
{
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
                if (!isdigit(str[i])) return false; 
        }
        return true;
}
//---------------------------------------------------------------------------
void TKBM::calc(std::map<int, int>& in, std::string& cls, double& c)
{
        if (in.size() == 0) { // See paragraph 5.
                cls = "3";
                c = 1;
                return;
        }

        KbmCoefficient current = kbmCoefs_[0];
        typedef std::map<int, int>::const_iterator cit;
        for (cit it = in.begin(); it != in.end(); ++it) {
                getNextClass(current, it->second);
        }
        cls = current.class_.c_str();
        c = current.coef_;
}
//---------------------------------------------------------------------------
void TKBM::getNextClass(KbmCoefficient& c, int payments)
{
        typedef std::vector<KbmCoefficient>::const_iterator cit;
        for (cit it = kbmCoefs_.begin(); it != kbmCoefs_.end(); ++it) {
                if (it->class_ == c.class_) {
                        std::string cls = "";
                        switch (payments) {
                                case 0:
                                        cls = it->payment0;
                                        break;
                                case 1:
                                        cls = it->payment1;
                                        break;
                                case 2:
                                        cls = it->payment2;
                                        break;
                                case 3:
                                        cls = it->payment3;
                                        break;
                                default:
                                        cls = it->paymentOver3;
                                        break;
                        }
                        c.class_ = cls;
                        c.coef_ = getCoefByClass(cls);
                        return;
                }
        }
}
//---------------------------------------------------------------------------
double TKBM::getCoefByClass(const std::string& cls)
{
        typedef std::vector<KbmCoefficient>::const_iterator cit;
        for (cit it = kbmCoefs_.begin(); it != kbmCoefs_.end(); ++it) {
                std::string clsTable = it->class_;
                if (clsTable == cls) {
                        return it->coef_;
                }
        }
        throw new CantFindCoefForClass();
}

