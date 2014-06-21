#include "wx_pch.h"
#include "ViewInfoDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ViewInfoDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ViewInfoDialog)
//*)

#include <cmath>

//(*IdInit(ViewInfoDialog)
const long ViewInfoDialog::ID_STATICTEXT1 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT2 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT3 = wxNewId();
const long ViewInfoDialog::ID_PANEL2 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT4 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT5 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT6 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT7 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT8 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT11 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT12 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT13 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX2 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT14 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT15 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX1 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT9 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT10 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX3 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT16 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT17 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX4 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT18 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT19 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX5 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT20 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT21 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX6 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT22 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT23 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX7 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT24 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT25 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX8 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT26 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT27 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX9 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT28 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT29 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX10 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT30 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT31 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX11 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT32 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT33 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX12 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT34 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT35 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX13 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT36 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT37 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX14 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT38 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT39 = wxNewId();
const long ViewInfoDialog::ID_CHECKBOX15 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT40 = wxNewId();
const long ViewInfoDialog::ID_STATICTEXT41 = wxNewId();
const long ViewInfoDialog::ID_BUTTON3 = wxNewId();
const long ViewInfoDialog::ID_BUTTON1 = wxNewId();
const long ViewInfoDialog::ID_BUTTON2 = wxNewId();
const long ViewInfoDialog::ID_PANEL1 = wxNewId();
const long ViewInfoDialog::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ViewInfoDialog,wxDialog)
	//(*EventTable(ViewInfoDialog)
	//*)
END_EVENT_TABLE()

ViewInfoDialog::ViewInfoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ViewInfoDialog)
	Create(parent, wxID_ANY, _("Planet Info"), pos, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetFocus();
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Planet Info"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	NameStaticText = new wxStaticText(Panel1, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(NameStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Colour"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	ColourPanel = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	ColourPanel->SetMinSize(wxSize(60,3));
	ColourPanel->SetMaxSize(wxSize(60,3));
	FlexGridSizer1->Add(ColourPanel, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Mass"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	MassStaticText = new wxStaticText(Panel1, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(MassStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Basic"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2->AddGrowableCol(2);
	BlankStaticText = new wxStaticText(Panel1, ID_STATICTEXT6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(BlankStaticText, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Orbital Period"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	PeriodStaticText = new wxStaticText(Panel1, ID_STATICTEXT8, _("Calculating..."), wxDefaultPosition, wxSize(100,-1), 0, _T("ID_STATICTEXT8"));
	FlexGridSizer2->Add(PeriodStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BlankStaticText2 = new wxStaticText(Panel1, ID_STATICTEXT11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer2->Add(BlankStaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT12, _("No. of Revolutions"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	RevStaticText = new wxStaticText(Panel1, ID_STATICTEXT13, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer2->Add(RevStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	DistanceCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	DistanceCheckBox->SetValue(false);
	FlexGridSizer2->Add(DistanceCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT14, _("Distance from COM"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	DistanceStaticText = new wxStaticText(Panel1, ID_STATICTEXT15, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer2->Add(DistanceStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	XCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	XCheckBox->SetValue(false);
	FlexGridSizer2->Add(XCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Current X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	XStaticText = new wxStaticText(Panel1, ID_STATICTEXT10, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(XStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	YCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	YCheckBox->SetValue(false);
	FlexGridSizer2->Add(YCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT16, _("Current Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	YStaticText = new wxStaticText(Panel1, ID_STATICTEXT17, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	FlexGridSizer2->Add(YStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	ZCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	ZCheckBox->SetValue(false);
	FlexGridSizer2->Add(ZCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT18, _("Current Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	ZStaticText = new wxStaticText(Panel1, ID_STATICTEXT19, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	FlexGridSizer2->Add(ZStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	SpeedCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	SpeedCheckBox->SetValue(false);
	FlexGridSizer2->Add(SpeedCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT20, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	SpeedStaticText = new wxStaticText(Panel1, ID_STATICTEXT21, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	FlexGridSizer2->Add(SpeedStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vXCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
	vXCheckBox->SetValue(false);
	FlexGridSizer2->Add(vXCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT22, _("Current vX"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	FlexGridSizer2->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vXStaticText = new wxStaticText(Panel1, ID_STATICTEXT23, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	FlexGridSizer2->Add(vXStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vYCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
	vYCheckBox->SetValue(false);
	FlexGridSizer2->Add(vYCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT24, _("Current vY"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	FlexGridSizer2->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vYStaticText = new wxStaticText(Panel1, ID_STATICTEXT25, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	FlexGridSizer2->Add(vYStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vZCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
	vZCheckBox->SetValue(false);
	FlexGridSizer2->Add(vZCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT26, _("Current vZ"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	FlexGridSizer2->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	vZStaticText = new wxStaticText(Panel1, ID_STATICTEXT27, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	FlexGridSizer2->Add(vZStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer4->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Advanced"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	AccelCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
	AccelCheckBox->SetValue(false);
	FlexGridSizer3->Add(AccelCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT28, _("Acceleration"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	FlexGridSizer3->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelStaticText = new wxStaticText(Panel1, ID_STATICTEXT29, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
	FlexGridSizer3->Add(AccelStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelXCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
	AccelXCheckBox->SetValue(false);
	FlexGridSizer3->Add(AccelXCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText16 = new wxStaticText(Panel1, ID_STATICTEXT30, _("Acceleration in X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	FlexGridSizer3->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelXStaticText = new wxStaticText(Panel1, ID_STATICTEXT31, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	FlexGridSizer3->Add(AccelXStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelYCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX11"));
	AccelYCheckBox->SetValue(false);
	FlexGridSizer3->Add(AccelYCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT32, _("Acceleration in Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
	FlexGridSizer3->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelYStaticText = new wxStaticText(Panel1, ID_STATICTEXT33, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	FlexGridSizer3->Add(AccelYStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelZCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX12"));
	AccelZCheckBox->SetValue(false);
	FlexGridSizer3->Add(AccelZCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText18 = new wxStaticText(Panel1, ID_STATICTEXT34, _("Acceleration in Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
	FlexGridSizer3->Add(StaticText18, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	AccelZStaticText = new wxStaticText(Panel1, ID_STATICTEXT35, _("Calcuating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	FlexGridSizer3->Add(AccelZStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	GPECheckBox = new wxCheckBox(Panel1, ID_CHECKBOX13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX13"));
	GPECheckBox->SetValue(false);
	FlexGridSizer3->Add(GPECheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText19 = new wxStaticText(Panel1, ID_STATICTEXT36, _("Grav. Potential Energy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
	FlexGridSizer3->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	GPEStaticText = new wxStaticText(Panel1, ID_STATICTEXT37, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
	FlexGridSizer3->Add(GPEStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	KECheckBox = new wxCheckBox(Panel1, ID_CHECKBOX14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX14"));
	KECheckBox->SetValue(false);
	FlexGridSizer3->Add(KECheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText20 = new wxStaticText(Panel1, ID_STATICTEXT38, _("Kinetic Energy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
	FlexGridSizer3->Add(StaticText20, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	KEStaticText = new wxStaticText(Panel1, ID_STATICTEXT39, _("Calculating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
	FlexGridSizer3->Add(KEStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	TECheckBox = new wxCheckBox(Panel1, ID_CHECKBOX15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX15"));
	TECheckBox->SetValue(false);
	FlexGridSizer3->Add(TECheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText21 = new wxStaticText(Panel1, ID_STATICTEXT40, _("Total Energy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
	FlexGridSizer3->Add(StaticText21, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	TEStaticText = new wxStaticText(Panel1, ID_STATICTEXT41, _("Calcuating..."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
	FlexGridSizer3->Add(TEStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer3->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer4->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ShowMoreButton = new wxButton(Panel1, ID_BUTTON3, _("Show More >>"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	ShowMoreButton->SetDefault();
	BoxSizer3->Add(ShowMoreButton, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	OpenGraphButton = new wxButton(Panel1, ID_BUTTON1, _("Open Graph"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	OpenGraphButton->Disable();
	BoxSizer3->Add(OpenGraphButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ExportButton = new wxButton(Panel1, ID_BUTTON2, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	ExportButton->Disable();
	BoxSizer3->Add(ExportButton, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	SetSizer(BoxSizer1);
	InfoCalcTimer.SetOwner(this, ID_TIMER1);
	InfoCalcTimer.Start(500, false);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	ColourPanel->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&ViewInfoDialog::OnKeyDown,0,this);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewInfoDialog::OnShowMoreButtonClick);
	Panel1->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&ViewInfoDialog::OnKeyDown,0,this);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&ViewInfoDialog::OnInfoCalcTimerTrigger);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&ViewInfoDialog::OnKeyDown);
	//*)

	connectKeyDownEvent(this);
	AdvancedShown = false;
	HideAdvancedPanel();
}

ViewInfoDialog::~ViewInfoDialog()
{
	//(*Destroy(ViewInfoDialog)
	//*)

	MyPlanet->ViewInfo = false;
}

void ViewInfoDialog::connectKeyDownEvent(wxWindow* pclComponent)
{
  if(pclComponent)
  {
    pclComponent->Connect(wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler(ViewInfoDialog::OnKeyDown), (wxObject*) NULL, this);

    wxWindowListNode* pclNode = pclComponent->GetChildren().GetFirst();
    while(pclNode)
    {
      wxWindow* pclChild = pclNode->GetData();
      this->connectKeyDownEvent(pclChild);

      pclNode = pclNode->GetNext();
    }
  }
}

bool ViewInfoDialog::HideAdvancedPanel()
{
    BoxSizer4->Hide(StaticBoxSizer3, true);
	BoxSizer4->Layout();
	StaticBoxSizer1->Layout();
	BoxSizer2->Layout();
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	this->Fit();
	return true;
}

bool ViewInfoDialog::ShowAdvancedPanel()
{
    BoxSizer4->Show(StaticBoxSizer3, true, true);
	BoxSizer4->Layout();
	StaticBoxSizer1->Layout();
	BoxSizer2->Layout();
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	this->Fit();
	return true;
}

void ViewInfoDialog::SetPlanet(Planet* PlanetPtr)
{
    if (PlanetPtr == NULL) {
        this->Close();
        return;
    }
    MyPlanet = PlanetPtr;
    InitializeDialog();
}

void ViewInfoDialog::InitializeDialog()
{
    // Set dialog title
    this->SetLabel(wxString("Planet Info: ") << MyPlanet->PName);

    // Set name
    NameStaticText->SetLabel(MyPlanet->PName);

    // Set background colour
    ColourPanel->SetBackgroundColour(MyPlanet->PlanetInfo.TrailColour);

    // Set mass
    MassStaticText->SetLabel(wxString::Format("%.5e kg", MyPlanet->Mass));

    // Set calculations
    MyPlanet->ViewInfo = true;
}

void ViewInfoDialog::OnKeyDown(wxKeyEvent& event)
{
    if (event.GetModifiers() == wxMOD_CONTROL) {
        switch(event.GetKeyCode()) {
        case 'W':
            this->Close();
            break;
        default:
            break;
        }
    }
}

void ViewInfoDialog::OnInfoCalcTimerTrigger(wxTimerEvent& event)
{
    // Display Orbital Period
    if (MyPlanet->Revolution == 0) {
        PeriodStaticText->SetLabel("Calculating...");
    } else {
        PeriodStaticText->SetLabel(wxString::Format("%.3f days", MyPlanet->OrbitalPeriod / 86400));
    }

    // Display No. of Revolutions
    RevStaticText->SetLabel(wxString::Format("%d", MyPlanet->Revolution));

    // Display Distance from COM
    DistanceStaticText->SetLabel(wxString::Format("%.5e km", MyPlanet->DistanceCOM /1000));

    // Display Positions
    XStaticText->SetLabel(wxString::Format("%.5e km", MyPlanet->CurrentX / 1000));
    YStaticText->SetLabel(wxString::Format("%.5e km", MyPlanet->CurrentY / 1000));
    ZStaticText->SetLabel(wxString::Format("%.5e km", MyPlanet->CurrentZ / 1000));

    // Display Speed
    SpeedStaticText->SetLabel(wxString::Format("%.5e km/s", std::sqrt((MyPlanet->CurrentvX) * (MyPlanet->CurrentvX)
                                                                    + (MyPlanet->CurrentvY) * (MyPlanet->CurrentvY)
                                                                    + (MyPlanet->CurrentvZ) * (MyPlanet->CurrentvZ)) / 1000));

    // Display Velocities
    vXStaticText->SetLabel(wxString::Format("%.5e km/s", MyPlanet->CurrentvX / 1000));
    vYStaticText->SetLabel(wxString::Format("%.5e km/s", MyPlanet->CurrentvY / 1000));
    vZStaticText->SetLabel(wxString::Format("%.5e km/s", MyPlanet->CurrentvZ / 1000));

    // Display Accelerations
    AccelStaticText->SetLabel(wxString::Format("%.5e m/s²", std::sqrt((MyPlanet->AccelX * MyPlanet->AccelX +
                                                                       MyPlanet->AccelY * MyPlanet->AccelY +
                                                                       MyPlanet->AccelZ * MyPlanet->AccelZ ))));
    AccelXStaticText->SetLabel(wxString::Format("%.5e m/s²", MyPlanet->AccelX));
    AccelYStaticText->SetLabel(wxString::Format("%.5e m/s²", MyPlanet->AccelY));
    AccelZStaticText->SetLabel(wxString::Format("%.5e m/s²", MyPlanet->AccelZ));

    // Display Energy
    GPEStaticText->SetLabel(wxString::Format("%.5e MJ", MyPlanet->GPE / 1000000));
    KEStaticText->SetLabel(wxString::Format("%.5e MJ", MyPlanet->KE / 1000000));
    TEStaticText->SetLabel(wxString::Format("%.5e MJ", MyPlanet->TE / 1000000));
}

void ViewInfoDialog::OnShowMoreButtonClick(wxCommandEvent& event)
{
    if (AdvancedShown) {
        HideAdvancedPanel();
        ShowMoreButton->SetLabel("Show More >>");
        AdvancedShown = false;
    } else {
        ShowAdvancedPanel();
        ShowMoreButton->SetLabel("<< Show Less");
        AdvancedShown = true;
    }
}
