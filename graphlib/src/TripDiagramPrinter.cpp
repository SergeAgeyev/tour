//---------------------------------------------------------------------------
#include <vcl.h>
#include <printers.hpp>
#pragma hdrstop

#include "TripDiagramPrinter.h"

#pragma package(smart_init)

//---------------------------------------------------------------------------
void     TripDiagramPrint(TCanvas   *SourceCanvasDataPtr,
                          TRect     *FullCanvasRectPtr)
 {
  TPrinter   *PrinterPtr;
  TRect       PaperRect;

  PrinterPtr  = Printer();
  PaperRect   = Rect(10,10,PrinterPtr->PageHeight-10,PrinterPtr->PageWidth-10);

  PrinterPtr->Orientation = poLandscape;
  PrinterPtr->BeginDoc();

  if (FullCanvasRectPtr == NULL)
   {
    PrinterPtr->Canvas->CopyRect(PaperRect,
                                 SourceCanvasDataPtr,
                                 SourceCanvasDataPtr->ClipRect);
   }
  else
   {
    PrinterPtr->Canvas->CopyRect(PaperRect,
                                 SourceCanvasDataPtr,
                                 (*FullCanvasRectPtr));
   }

  PrinterPtr->Canvas->DrawFocusRect(PaperRect);
  PrinterPtr->EndDoc();
 }
//---------------------------------------------------------------------------
