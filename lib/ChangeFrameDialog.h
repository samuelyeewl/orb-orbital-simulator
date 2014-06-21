#ifndef CHANGEFRAMEDIALOG_H
#define CHANGEFRAMEDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ChangeFrameDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/checkbox.h>
	#include <wx/radiobut.h>
	#include <wx/panel.h>
	#include <wx/choice.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(ChangeFrameDialog)
//*)

class ChangeFrameDialog: public wxDialog
{
	public:

		ChangeFrameDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ChangeFrameDialog();

		//(*Declarations(ChangeFrameDialog)
		wxRadioButton* COMRadioButton;
		wxTextCtrl* ZTextCtrl;
		wxRadioButton* OriginalRadioButton;
		wxRadioButton* CustomRadioButton;
		wxStaticText* StaticText2;
		wxChoice* PlanetChoice;
		wxButton* Button1;
		wxTextCtrl* XTextCtrl;
		wxRadioButton* PlanetRadioButton;
		wxStaticText* StaticText6;
		wxTextCtrl* YTextCtrl;
		wxTextCtrl* vXTextCtrl;
		wxTextCtrl* FreqTextCtrl;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxRadioButton* FreqRadioButton;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxCheckBox* RotationCheckBox;
		wxTextCtrl* vZTextCtrl;
		wxTextCtrl* PeriodTextCtrl;
		wxRadioButton* PeriodRadioButton;
		wxTextCtrl* vYTextCtrl;
		wxStaticText* StaticText4;
		wxCheckBox* TranslationCheckBox;
		//*)

	protected:

		//(*Identifiers(ChangeFrameDialog)
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_RADIOBUTTON3;
		static const long ID_CHOICE1;
		static const long ID_RADIOBUTTON4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL6;
		static const long ID_CHECKBOX2;
		static const long ID_RADIOBUTTON5;
		static const long ID_RADIOBUTTON6;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL8;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ChangeFrameDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnXTextCtrlText(wxCommandEvent& event);
		void OnYTextCtrlText(wxCommandEvent& event);
		void OnZTextCtrlText(wxCommandEvent& event);
		void OnPlanetChoiceSelect(wxCommandEvent& event);
		void OnTranslationCheckBoxClick(wxCommandEvent& event);
		void OnCOMRadioButtonSelect(wxCommandEvent& event);
		void OnPlanetRadioButtonSelect(wxCommandEvent& event);
		void OnOriginalRadioButtonSelect(wxCommandEvent& event);
		void OnCustomRadioButtonSelect(wxCommandEvent& event);
		void OnRotationCheckBoxClick(wxCommandEvent& event);
		void OnPeriodRadioButtonSelect(wxCommandEvent& event);
		void OnFreqRadioButtonSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
