#include "wx_pch.h"
#include "ChangeFrameDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ChangeFrameDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ChangeFrameDialog)
//*)

//(*IdInit(ChangeFrameDialog)
const long ChangeFrameDialog::ID_RADIOBUTTON1 = wxNewId();
const long ChangeFrameDialog::ID_RADIOBUTTON2 = wxNewId();
const long ChangeFrameDialog::ID_RADIOBUTTON3 = wxNewId();
const long ChangeFrameDialog::ID_CHOICE1 = wxNewId();
const long ChangeFrameDialog::ID_RADIOBUTTON4 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT1 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL1 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT2 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL2 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT3 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL3 = wxNewId();
const long ChangeFrameDialog::ID_CHECKBOX1 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT4 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT5 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL4 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT6 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL5 = wxNewId();
const long ChangeFrameDialog::ID_STATICTEXT7 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL6 = wxNewId();
const long ChangeFrameDialog::ID_CHECKBOX2 = wxNewId();
const long ChangeFrameDialog::ID_RADIOBUTTON5 = wxNewId();
const long ChangeFrameDialog::ID_RADIOBUTTON6 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL7 = wxNewId();
const long ChangeFrameDialog::ID_TEXTCTRL8 = wxNewId();
const long ChangeFrameDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ChangeFrameDialog,wxDialog)
	//(*EventTable(ChangeFrameDialog)
	//*)
END_EVENT_TABLE()

ChangeFrameDialog::ChangeFrameDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ChangeFrameDialog)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxGridSizer* GridSizer1;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, _("Choose Frame of Reference"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Choose Origin"));
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	COMRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Centre of Mass"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	COMRadioButton->SetValue(true);
	BoxSizer5->Add(COMRadioButton, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	OriginalRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Original"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	BoxSizer5->Add(OriginalRadioButton, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	PlanetRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("Planet"), wxDefaultPosition, wxSize(100,13), 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	BoxSizer3->Add(PlanetRadioButton, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	PlanetChoice = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxSize(123,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	BoxSizer3->Add(PlanetChoice, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	CustomRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("Custom (m)"), wxDefaultPosition, wxSize(80,13), 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
	BoxSizer4->Add(CustomRadioButton, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("X:"), wxDefaultPosition, wxSize(14,13), 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	XTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(68,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(XTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Y:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	YTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(68,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(YTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Z:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ZTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(65,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer4->Add(ZTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Translation"));
	TranslationCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Translation of Origin"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	TranslationCheckBox->SetValue(false);
	StaticBoxSizer2->Add(TranslationCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Speed (m/s):"), wxDefaultPosition, wxSize(68,13), 0, _T("ID_STATICTEXT4"));
	BoxSizer7->Add(StaticText4, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("vX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer7->Add(StaticText5, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	vXTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxSize(61,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	vXTextCtrl->Disable();
	BoxSizer7->Add(vXTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("vY:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer7->Add(StaticText6, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	vYTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxSize(68,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	vYTextCtrl->Disable();
	BoxSizer7->Add(vYTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("vZ"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer7->Add(StaticText7, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	vZTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxSize(68,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	vZTextCtrl->Disable();
	BoxSizer7->Add(vZTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer2->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Rotation"));
	RotationCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Rotation about Z-axis"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	RotationCheckBox->SetValue(false);
	StaticBoxSizer3->Add(RotationCheckBox, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	GridSizer1 = new wxGridSizer(0, 2, 0, 0);
	PeriodRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON5, _("Orbital Period (days)"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
	PeriodRadioButton->SetValue(true);
	PeriodRadioButton->Disable();
	GridSizer1->Add(PeriodRadioButton, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FreqRadioButton = new wxRadioButton(Panel1, ID_RADIOBUTTON6, _("Angular Frequency (rad/s)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
	FreqRadioButton->Disable();
	GridSizer1->Add(FreqRadioButton, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	PeriodTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	PeriodTextCtrl->Disable();
	GridSizer1->Add(PeriodTextCtrl, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_TOP, 7);
	FreqTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FreqTextCtrl->Disable();
	GridSizer1->Add(FreqTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 7);
	StaticBoxSizer3->Add(GridSizer1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer2->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	Button2 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer6->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2->Add(BoxSizer6, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnCOMRadioButtonSelect);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnOriginalRadioButtonSelect);
	Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnPlanetRadioButtonSelect);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnPlanetChoiceSelect);
	Connect(ID_RADIOBUTTON4,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnCustomRadioButtonSelect);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ChangeFrameDialog::OnXTextCtrlText);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ChangeFrameDialog::OnYTextCtrlText);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ChangeFrameDialog::OnZTextCtrlText);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ChangeFrameDialog::OnTranslationCheckBoxClick);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ChangeFrameDialog::OnRotationCheckBoxClick);
	Connect(ID_RADIOBUTTON5,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnPeriodRadioButtonSelect);
	Connect(ID_RADIOBUTTON6,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ChangeFrameDialog::OnFreqRadioButtonSelect);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ChangeFrameDialog::OnButton1Click);
	//*)
}

ChangeFrameDialog::~ChangeFrameDialog()
{
	//(*Destroy(ChangeFrameDialog)
	//*)
}


void ChangeFrameDialog::OnButton1Click(wxCommandEvent& event)
{
    wxString TextCtrlInput;
    double TempValue;

    // Check that x, y, z are doubles.
    if (CustomRadioButton->GetValue()) {
        TextCtrlInput = XTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("X must be a floating-point number!");
            return;
        }

        TextCtrlInput = YTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("Y must be a floating-point number!");
            return;
        }

        TextCtrlInput = ZTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("Z must be a floating-point number!");
            return;
        }
    }

    // Check if vX, vY, vZ are doubles
    if (TranslationCheckBox->GetValue()) {
        TextCtrlInput = vXTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("vX must be a floating point number!");
            return;
        }

        TextCtrlInput = vYTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("vY must be a floating point number!");
            return;
        }

        TextCtrlInput = vZTextCtrl->GetValue();
        if (!TextCtrlInput.ToDouble(&TempValue)) {
            wxMessageBox("vZ must be a floating point number!");
            return;
        }
    }

    // Check if Freq/Period are doubles
    if (RotationCheckBox->GetValue()) {
        if (PeriodRadioButton->GetValue()) {
            TextCtrlInput = PeriodTextCtrl->GetValue();
            if (!TextCtrlInput.ToDouble(&TempValue)) {
                wxMessageBox("Rotation period must be a floating point number!");
                return;
            }
        } else if (FreqRadioButton->GetValue()) {
            TextCtrlInput = FreqTextCtrl->GetValue();
            if (!TextCtrlInput.ToDouble(&TempValue)) {
                wxMessageBox("Angular frequency must be a floating point number!");
                return;
            }
        }
    }

    event.Skip();
}

void ChangeFrameDialog::OnXTextCtrlText(wxCommandEvent& event)
{
    CustomRadioButton->SetValue(true);
}

void ChangeFrameDialog::OnYTextCtrlText(wxCommandEvent& event)
{
    CustomRadioButton->SetValue(true);
}

void ChangeFrameDialog::OnZTextCtrlText(wxCommandEvent& event)
{
    CustomRadioButton->SetValue(true);
}

void ChangeFrameDialog::OnPlanetChoiceSelect(wxCommandEvent& event)
{
    PlanetRadioButton->SetValue(true);
}

void ChangeFrameDialog::OnTranslationCheckBoxClick(wxCommandEvent& event)
{
    if (TranslationCheckBox->GetValue()) {
        vXTextCtrl->Enable();
        vYTextCtrl->Enable();
        vZTextCtrl->Enable();
    } else {
        vXTextCtrl->Disable();
        vYTextCtrl->Disable();
        vZTextCtrl->Disable();
    }
}

void ChangeFrameDialog::OnCOMRadioButtonSelect(wxCommandEvent& event)
{
    if (COMRadioButton->GetValue()) {
        // Disable translation
        TranslationCheckBox->Disable();
        vXTextCtrl->Disable();
        vYTextCtrl->Disable();
        vZTextCtrl->Disable();
    }
}

void ChangeFrameDialog::OnPlanetRadioButtonSelect(wxCommandEvent& event)
{
    if (PlanetRadioButton->GetValue()) {
        // Disable translation
        TranslationCheckBox->Disable();
        vXTextCtrl->Disable();
        vYTextCtrl->Disable();
        vZTextCtrl->Disable();
    }
}

void ChangeFrameDialog::OnOriginalRadioButtonSelect(wxCommandEvent& event)
{
    if (OriginalRadioButton->GetValue()) {
        // Enable translation
        TranslationCheckBox->Enable();
        if (TranslationCheckBox->GetValue()) {
            vXTextCtrl->Enable();
            vYTextCtrl->Enable();
            vZTextCtrl->Enable();
        } else {
            vXTextCtrl->Disable();
            vYTextCtrl->Disable();
            vZTextCtrl->Disable();
        }
    }
}

void ChangeFrameDialog::OnCustomRadioButtonSelect(wxCommandEvent& event)
{
    if (CustomRadioButton->GetValue()) {
        // Enable translation
        TranslationCheckBox->Enable();
        if (TranslationCheckBox->GetValue()) {
            vXTextCtrl->Enable();
            vYTextCtrl->Enable();
            vZTextCtrl->Enable();
        } else {
            vXTextCtrl->Disable();
            vYTextCtrl->Disable();
            vZTextCtrl->Disable();
        }
    }
}

void ChangeFrameDialog::OnRotationCheckBoxClick(wxCommandEvent& event)
{
    if (RotationCheckBox->GetValue()) {
        // Enable rotation
        PeriodRadioButton->Enable();
        FreqRadioButton->Enable();
        if (PeriodRadioButton->GetValue()) {
            PeriodTextCtrl->Enable();
        } else {
            FreqTextCtrl->Enable();
        }
    } else {
        PeriodRadioButton->Disable();
        FreqRadioButton->Disable();
        PeriodTextCtrl->Disable();
        FreqTextCtrl->Disable();
    }
}

void ChangeFrameDialog::OnPeriodRadioButtonSelect(wxCommandEvent& event)
{
    if (PeriodRadioButton->GetValue()) {
        PeriodTextCtrl->Enable();
        FreqTextCtrl->Disable();
    }
}

void ChangeFrameDialog::OnFreqRadioButtonSelect(wxCommandEvent& event)
{
    if (FreqRadioButton->GetValue()) {
        PeriodTextCtrl->Disable();
        FreqTextCtrl->Enable();
    }
}
