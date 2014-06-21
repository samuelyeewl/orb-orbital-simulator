#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(HelpDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/panel.h>
	#include <wx/statbmp.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(HelpDialog)
//*)

class HelpDialog: public wxDialog
{
	public:

		HelpDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~HelpDialog();

		//(*Declarations(HelpDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		//*)

	protected:

		//(*Identifiers(HelpDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(HelpDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
