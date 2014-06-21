#ifndef BENCHMARKDIALOG_H
#define BENCHMARKDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(BenchmarkDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/checkbox.h>
	#include <wx/panel.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(BenchmarkDialog)
//*)

class BenchmarkDialog: public wxDialog
{
	public:

		BenchmarkDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BenchmarkDialog();

		//(*Declarations(BenchmarkDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxPanel* Panel1;
		wxTextCtrl* LengthTextCtrl;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		//*)

		void SetCurrentLength(int CurrentLength);

	protected:

		//(*Identifiers(BenchmarkDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(BenchmarkDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
