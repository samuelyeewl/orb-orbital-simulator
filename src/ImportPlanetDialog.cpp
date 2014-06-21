#include "../wx_pch.h"
#include "../lib/ImportPlanetDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ImportPlanetDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ImportPlanetDialog)
//*)

//(*IdInit(ImportPlanetDialog)
const long ImportPlanetDialog::ID_STATICTEXT1 = wxNewId();
const long ImportPlanetDialog::ID_TEXTCTRL1 = wxNewId();
const long ImportPlanetDialog::ID_STATICTEXT2 = wxNewId();
const long ImportPlanetDialog::ID_CHOICE1 = wxNewId();
const long ImportPlanetDialog::ID_STATICTEXT3 = wxNewId();
const long ImportPlanetDialog::ID_CHOICE2 = wxNewId();
const long ImportPlanetDialog::ID_STATICTEXT4 = wxNewId();
const long ImportPlanetDialog::ID_TEXTCTRL2 = wxNewId();
const long ImportPlanetDialog::ID_STATICTEXT5 = wxNewId();
const long ImportPlanetDialog::ID_STATICTEXT6 = wxNewId();
const long ImportPlanetDialog::ID_TEXTCTRL3 = wxNewId();
const long ImportPlanetDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ImportPlanetDialog,wxDialog)
	//(*EventTable(ImportPlanetDialog)
	//*)
END_EVENT_TABLE()

ImportPlanetDialog::ImportPlanetDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ImportPlanetDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, _("Import Planet"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	NameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, _("NewPlanet"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(NameTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Colour"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ColourChoice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ColourChoice->SetSelection( ColourChoice->Append(_("Black")) );
	ColourChoice->Append(_("Red"));
	ColourChoice->Append(_("Blue"));
	ColourChoice->Append(_("Green"));
	ColourChoice->Append(_("Custom"));
	BoxSizer3->Add(ColourChoice, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SizeChoice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(47,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	SizeChoice->SetSelection( SizeChoice->Append(_("0")) );
	SizeChoice->Append(_("1"));
	SizeChoice->Append(_("2"));
	SizeChoice->Append(_("3"));
	SizeChoice->Append(_("4"));
	BoxSizer3->Add(SizeChoice, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Mass"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	MassTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL2, _("700"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(MassTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("x 10²º kg"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(FlexGridSizer1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Vector Ephemerides"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer5->Add(StaticText6, 0, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	EphemeridesTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(276,126), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer5->Add(EphemeridesTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	Button1->SetFocus();
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	Button2 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	Button3 = new wxButton(this, ID_BUTTON1, _("Help"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ImportPlanetDialog::OnColourChoiceSelect);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ImportPlanetDialog::OnButton1Click);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ImportPlanetDialog::OnButton2Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ImportPlanetDialog::OnButton3Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ImportPlanetDialog::OnInit);
	//*)
}

ImportPlanetDialog::~ImportPlanetDialog()
{
	//(*Destroy(ImportPlanetDialog)
	//*)
}


void ImportPlanetDialog::OnInit(wxInitDialogEvent& event)
{
}

void ImportPlanetDialog::SetColourData(wxColourData* CustomColourData)
{
    ColourDlgData = CustomColourData;
}

void ImportPlanetDialog::OnColourChoiceSelect(wxCommandEvent& event)
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

void ImportPlanetDialog::OnButton1Click(wxCommandEvent& event)
{
    wxString textctrlinput, tempoutputstring;

    /* Check that mass is non-negative double */
    textctrlinput = MassTextCtrl->GetValue();
    if (!textctrlinput.ToDouble(&mass) || mass <= 0) {
        wxMessageBox("The mass must be a positive floating-point number!");
        return;
    }

    /* Check for valid ephemerides */
    textctrlinput = EphemeridesTextCtrl->GetValue();
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check X Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar(' '));
    if (!tempoutputstring.ToDouble(&x)) {
        wxMessageBox("Invalid Ephemerides!\nCheck X Value");
        return;
    }
    textctrlinput = textctrlinput.AfterFirst(wxUniChar(' '));
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check Y Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar(' '));
    if (!tempoutputstring.ToDouble(&y)) {
        wxMessageBox("Invalid Ephemerides!\nCheck Y Value");
        return;
    }
    textctrlinput = textctrlinput.AfterFirst(wxUniChar(' '));
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check Z Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar('\n'));
    if (!tempoutputstring.ToDouble(&z)) {
        wxMessageBox("Invalid Ephemerides!\nCheck Z Value");
        return;
    }
    textctrlinput = textctrlinput.AfterFirst(wxUniChar('\n'));
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check vX Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar(' '));
    if (!tempoutputstring.ToDouble(&vX)) {
        wxMessageBox("Invalid Ephemerides!\nCheck vX Value");
        return;
    }
    textctrlinput = textctrlinput.AfterFirst(wxUniChar(' '));
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check vY Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar(' '));
    if (!tempoutputstring.ToDouble(&vY)) {
        wxMessageBox("Invalid Ephemerides!\nCheck vY Value");
        return;
    }
    textctrlinput = textctrlinput.AfterFirst(wxUniChar(' '));
    // Strip out leading spaces and newlines
    while (textctrlinput.StartsWith(" ") || textctrlinput.StartsWith("\n")) {
        textctrlinput = textctrlinput.Mid(1);
    }

    // Check vZ Value
    tempoutputstring = textctrlinput.BeforeFirst(wxUniChar(' '));
    if (!tempoutputstring.ToDouble(&vZ)) {
        wxMessageBox("Invalid Ephemerides!\nCheck vZ Value");
        return;
    }



    event.Skip();

}

void ImportPlanetDialog::OnButton2Click(wxCommandEvent& event)
{
    event.Skip();
}

void ImportPlanetDialog::OnButton3Click(wxCommandEvent& event)
{
    wxMessageBox("This dialog allows for easy copy-and-paste from the NASA HORIZONS Ephemerides web interface.\n\
The data must contain 6 parameters, in the following format:\n\
 X     Y    Z\n\
 vX    vY   vZ\n\
 The units for X, Y and Z are in AU; the units for vX, vY, vZ are in AU/day.\n\
 For additional help, refer to the manual.","Help", wxICON_INFORMATION | wxOK);
}
