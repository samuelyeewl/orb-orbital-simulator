#include "wx_pch.h"
#include "BenchmarkDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(BenchmarkDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(BenchmarkDialog)
//*)

//(*IdInit(BenchmarkDialog)
const long BenchmarkDialog::ID_STATICTEXT1 = wxNewId();
const long BenchmarkDialog::ID_TEXTCTRL1 = wxNewId();
const long BenchmarkDialog::ID_STATICTEXT2 = wxNewId();
const long BenchmarkDialog::ID_CHECKBOX1 = wxNewId();
const long BenchmarkDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BenchmarkDialog,wxDialog)
	//(*EventTable(BenchmarkDialog)
	//*)
END_EVENT_TABLE()

BenchmarkDialog::BenchmarkDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(BenchmarkDialog)
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Run Benchmark"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Benchmark Length (No. of steps)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	LengthTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("100000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	LengthTextCtrl->SetFocus();
	FlexGridSizer1->Add(LengthTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("No Refresh"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(true);
	FlexGridSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2->Add(FlexGridSizer1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	Button1 = new wxButton(Panel1, wxID_OK, _("Go"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Button2 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	FlexGridSizer2->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BenchmarkDialog::OnButton1Click);
	//*)
}

BenchmarkDialog::~BenchmarkDialog()
{
	//(*Destroy(BenchmarkDialog)
	//*)
}


void BenchmarkDialog::OnButton1Click(wxCommandEvent& event)
{
    long BenchmarkLength = 0;
    wxString TextCtrlInput = LengthTextCtrl->GetValue();

    if (!TextCtrlInput.ToLong(&BenchmarkLength) || BenchmarkLength <= 0) {
        wxMessageBox("Benchmark Time Period must be a positive integer!");
    } else {
        event.Skip();
    }
}

void BenchmarkDialog::SetCurrentLength(int CurrentLength)
{
    LengthTextCtrl->SetValue(wxString::Format("%d", CurrentLength));
}
