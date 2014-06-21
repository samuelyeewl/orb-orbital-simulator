#include "wx_pch.h"
#include "HelpDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(HelpDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(HelpDialog)
#include <wx/settings.h>
#include <wx/font.h>
//*)

//(*IdInit(HelpDialog)
const long HelpDialog::ID_STATICBITMAP1 = wxNewId();
const long HelpDialog::ID_STATICTEXT1 = wxNewId();
const long HelpDialog::ID_STATICTEXT2 = wxNewId();
const long HelpDialog::ID_STATICTEXT3 = wxNewId();
const long HelpDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HelpDialog,wxDialog)
	//(*EventTable(HelpDialog)
	//*)
END_EVENT_TABLE()

HelpDialog::HelpDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(HelpDialog)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, _("About Orb"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(493,196), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(278,300), wxNO_BORDER, _T("ID_STATICBITMAP1"));
	BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Orb: An Orbital Simulator"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Arial Black"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("v 1.2\nCreated by Samuel Yee"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
	if ( !StaticText2Font.Ok() ) StaticText2Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
	StaticText2Font.SetPointSize(12);
	StaticText2Font.SetStyle(wxFONTSTYLE_NORMAL);
	StaticText2Font.SetWeight(wxNORMAL);
	StaticText2Font.SetUnderlined(false);
	StaticText2Font.SetFamily(wxSWISS);
	StaticText2Font.SetFaceName(_T("Arial"));
	StaticText2->SetFont(StaticText2Font);
	BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("\nIcon based on Blue Marble and Expedition 10 Photographs by NASA."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Button1 = new wxButton(Panel1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelpDialog::OnButton1Click);
	//*)
}

HelpDialog::~HelpDialog()
{
	//(*Destroy(HelpDialog)
	//*)
}


void HelpDialog::OnButton1Click(wxCommandEvent& event)
{
    event.Skip();
}
