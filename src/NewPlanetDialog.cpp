#include "wx_pch.h"
#include "NewPlanetDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(NewPlanetDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(NewPlanetDialog)
//*)

//(*IdInit(NewPlanetDialog)
const long NewPlanetDialog::ID_STATICTEXT1 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL1 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT2 = wxNewId();
const long NewPlanetDialog::ID_CHOICE1 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT13 = wxNewId();
const long NewPlanetDialog::ID_CHOICE2 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT3 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL2 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT7 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT4 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL3 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT8 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT14 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL7 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT15 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT5 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL4 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT9 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT6 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL5 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT10 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT16 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL8 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT17 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT11 = wxNewId();
const long NewPlanetDialog::ID_TEXTCTRL6 = wxNewId();
const long NewPlanetDialog::ID_STATICTEXT12 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewPlanetDialog,wxDialog)
	//(*EventTable(NewPlanetDialog)
	//*)

END_EVENT_TABLE()

NewPlanetDialog::NewPlanetDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(NewPlanetDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, _("Create New Planet"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetFocus();
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	NameTxtCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, _("NewPlanet"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(NameTxtCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Colour"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	ColourChoice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ColourChoice->SetSelection( ColourChoice->Append(_("Black")) );
	ColourChoice->Append(_("Red"));
	ColourChoice->Append(_("Blue"));
	ColourChoice->Append(_("Green"));
	ColourChoice->Append(_("Custom"));
	BoxSizer8->Add(ColourChoice, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer8->Add(StaticText13, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SizeChoice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(47,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	SizeChoice->SetSelection( SizeChoice->Append(_("0")) );
	SizeChoice->Append(_("1"));
	SizeChoice->Append(_("2"));
	SizeChoice->Append(_("3"));
	SizeChoice->Append(_("4"));
	BoxSizer8->Add(SizeChoice, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer1->Add(BoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Initial X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	XTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL2, _("200"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer2->Add(XTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("x 10³ km"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer2->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Initial Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	YTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL3, _("200"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer3->Add(YTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("x 10³ km"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer3->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Initial Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer1->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	ZTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer9->Add(ZTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("x 10³ km"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	BoxSizer9->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer9, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Initial Vx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	VxTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL4, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer4->Add(VxTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("km / s"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer4->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Initial Vy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	VyTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL5, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer5->Add(VyTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("km / s"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer5->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer5, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Initial Vz"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	FlexGridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	VzTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL8, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer10->Add(VzTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("km / s"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	BoxSizer10->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer10, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Mass"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	MassTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL6, _("700"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer6->Add(MassTextCtrl, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("x 10²º kg"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer6->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	Button1->SetFocus();
	BoxSizer7->Add(Button1, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Button2 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer7->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer1->Add(BoxSizer7, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&NewPlanetDialog::OnColourChoiceSelect);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewPlanetDialog::OnButton1Click);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewPlanetDialog::OnButton2Click);
	//*)

	SetEscapeId(wxID_CANCEL);

	ColourDlgData = new wxColourData();
}

NewPlanetDialog::~NewPlanetDialog()
{
	//(*Destroy(NewPlanetDialog)
	//*)
}



void NewPlanetDialog::OnButton1Click(wxCommandEvent& event)
{
    double x, y, z, vX, vY, vZ, mass;
    wxString textctrlinput;

    /* Check that x is double */
    textctrlinput = XTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&x)) {
        wxMessageBox("X must be a floating-point number!");
        return;
    }

    /* Check that y is double */
    textctrlinput = YTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&y)) {
        wxMessageBox("Y must be a floating-point number!");
        return;
    }

    /* Check that z is double */
    textctrlinput = ZTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&z)) {
        wxMessageBox("Z must be a floating-point number!");
        return;
    }

    /* Check that vX is double */
    textctrlinput = VxTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&vX)) {
        wxMessageBox("vX must be a floating-point number!");
        return;
    }

    /* Check that vY is double */
    textctrlinput = VyTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&vY)) {
        wxMessageBox("vY must be a floating-point number!");
        return;
    }

    /* Check that vZ is double */
    textctrlinput = VzTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&vZ)) {
        wxMessageBox("vZ must be a floating-point number!");
        return;
    }

    /* Check that mass is non-negative double */
    textctrlinput = MassTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&mass) || mass <= 0) {
        wxMessageBox("The mass must be a positive floating-point number!");
        return;
    }

    event.Skip();

}

void NewPlanetDialog::OnButton2Click(wxCommandEvent& event)
{
    event.Skip();
}

void NewPlanetDialog::OnColourChoiceSelect(wxCommandEvent& event)
{
    int selected = ColourChoice->GetSelection();
    if (selected == 4) {
        ColourDlg = new wxColourDialog(this, ColourDlgData);
        while (ColourDlg->ShowModal() == wxID_CANCEL) {
            // Continue to show dialog until colour is selected.
        }

        ColourDlgData = &(ColourDlg->GetColourData());
    }
}

void NewPlanetDialog::SetColourData(wxColourData* CustomColourData)
{
    ColourDlgData = CustomColourData;
}
