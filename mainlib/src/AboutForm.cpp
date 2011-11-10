//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "AboutForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourAboutForm *TourAboutForm;
//---------------------------------------------------------------------------
__fastcall TTourAboutForm::TTourAboutForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourAboutForm::CloseButtonClick(TObject *Sender)
{
  FunctionArgUsedSkip(Sender);
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TTourAboutForm::FormCreate(TObject *Sender)
 {
  DWORD                                Handle;
  DWORD                                Size;

  FunctionArgUsedSkip(Sender);
  Size = GetFileVersionInfoSize(Application->ExeName.c_str(), &Handle);

  if (Size != 0)
   {
    char                              *BufferStrPtr;

    BufferStrPtr = (char*)GlobalAlloc(GMEM_FIXED, Size);

    if(GetFileVersionInfo(Application->ExeName.c_str(),
                          Handle,
                          Size,
                          BufferStrPtr)!=0)
     {
      char                           *ValueBuffer;
      UINT                            ValueLength;

      VerQueryValue(BufferStrPtr,
                    "\\VarFileInfo\\Translation",
                    &(void*)ValueBuffer,
                    &ValueLength);

      if ( ValueLength >= 4)
       {
        AnsiString                     CharSet;

        CharSet = IntToHex((int)MAKELONG(*(int*)(ValueBuffer + 2),
                                         *(int*) ValueBuffer),
                           8);
/*
        if (VerQueryValue(BufferStrPtr,
                          AnsiString("\\StringFileInfo\\"
                                     + CharSet
                                     +"\\ProductName").c_str(),
                          &(void*)ValueBuffer,
                          &Len)!=0)
         {
          ApplicationNameLabel->Caption
          = ApplicationNameLabel->Caption + ValueBuffer;
         }
*/
        if (VerQueryValue(BufferStrPtr,
                          AnsiString("\\StringFileInfo\\"
                                     + CharSet
                                     + "\\FileVersion").c_str(),
                          &(void*)ValueBuffer,
                          &ValueLength)!=0)
         {
          VersionLabel->Caption
          = VersionLabel->Caption + ValueBuffer;
//          VersionLabel->Caption=ValueBuffer;
         }
/*
        if (VerQueryValue(BufferStrPtr,
                          AnsiString("\\StringFileInfo\\"
                                     + CharSet
                                     + "\\LegalCopyright").c_str(),
                          &(void*)ValueBuffer,
                          &Len)!=0)
         {
          CopyrightLabel->Caption
          = CopyrightLabel->Caption + ValueBuffer;
//          Copyright->Caption=ValueBuffer;
         }

        if (VerQueryValue(BufferStrPtr,
                          AnsiString("\\StringFileInfo\\"
                                     + CharSet
                                     + "\\CompanyName").c_str(),
                          &(void*)ValueBuffer,
                          &Len)!=0)
         {
          CompanyNameLabel->Caption
          = CompanyNameLabel->Caption + ValueBuffer;
//          Company->Caption=ValueBuffer;
         }
*/
       }
     }

    GlobalFree(BufferStrPtr);
   }
 }
//---------------------------------------------------------------------------


