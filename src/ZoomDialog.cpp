#include "../wx_pch.h"
#include "../lib/ZoomDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ZoomDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ZoomDialog)
//*)

//(*IdInit(ZoomDialog)
const long ZoomDialog::ID_STATICTEXT1 = wxNewId();
const long ZoomDialog::ID_TEXTCTRL1 = wxNewId();
const long ZoomDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ZoomDialog,wxDialog)
	//(*EventTable(ZoomDialog)
	//*)
END_EVENT_TABLE()

ZoomDialog::ZoomDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ZoomDialog)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, _("Custom Zoom Options"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Minimum Dimension \nof Displayed Area (AU)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	ZoomTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("1"), wxDefaultPosition, wxSize(57,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer3->Add(ZoomTextCtrl, 2, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	Button1->SetFocus();
	BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	Button2 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ZoomDialog::OnButton1Click);
	//*)
}

ZoomDialog::~ZoomDialog()
{
	//(*Destroy(ZoomDialog)
	//*)
}


void ZoomDialog::OnButton1Click(wxCommandEvent& event)
{
    wxString TextCtrlInput = ZoomTextCtrl->GetValue();
    double ZoomFactor;
    if (!TextCtrlInput.ToDouble(&ZoomFactor)) {
        wxMessageBox("The width must be a positive number!");
        return;
    }

    event.Skip();

}
