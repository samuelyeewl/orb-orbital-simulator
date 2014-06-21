#ifndef ZOOMDIALOG_H
#define ZOOMDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ZoomDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/panel.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(ZoomDialog)
//*)

class ZoomDialog: public wxDialog
{
	public:

		ZoomDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ZoomDialog();

		//(*Declarations(ZoomDialog)
		wxButton* Button1;
		wxTextCtrl* ZoomTextCtrl;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		//*)

	protected:

		//(*Identifiers(ZoomDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ZoomDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
