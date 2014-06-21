/***************************************************************
 * Name:      OrbMain.h
 * Purpose:   Defines Application Frame
 * Author:    Samuel Yee (samuelyeewl@gmail.com)
 * Created:   2011-11-10
 * Copyright: Samuel Yee ()
 * License:   GNU GPL v3
 **************************************************************/

#ifndef ORBMAIN_H
#define ORBMAIN_H

//(*Headers(OrbFrame)
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include "GraphPane.h"
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <wx/cmndata.h>
#include <wx/colordlg.h>
#include <vector>
#include "Planet.h"
#include "SolarSystem.h"
#include "ViewInfoDialog.h"

#include <wx/help.h>
#include <wx/helpbase.h>
#include <wx/msw/helpchm.h>
#include <wx/timer.h>
#include <wx/stdpaths.h>

/** \def SCALEMAXTOLERANCE
 *  The increase in scale factor if the maximum coordinate exceeds the current bounds
 */
#define SCALEMAXTOLERANCE 1.3

/** \def SCALEMINTOLERANCE
 *  The graph will be rescaled if the maximum coordinates is less than this factor of the current bounds
 */
#define SCALEMINTOLERANCE 0.3

struct PlanetControls {
    Planet* ControlPlanet;
    wxCheckBox* CheckBox;
    wxStaticText* NameStaticText;
    wxStaticText* MassStaticText;
    wxPanel* ColourPanel;
    wxStaticText* SizeStaticText;

    bool activated;
};

enum SaveType {
    SAVE_ORIGINAL, SAVE_CURRENT
};

class OrbFrame: public wxFrame
{
    public:

        OrbFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~OrbFrame();

        /** \brief Update panel giving information on current planets.
         * Should be called whenever a planet is added, edited or deleted.
         */
        void UpdatePlanetControls();

        /** \brief Opens and loads file of given name.
         * \param Valid filename, must exist.
         */
        void OpenOrbFile(wxString Filename);

        /** \brief Saves file to given name.
         * \param Valid filename
         * \param SaveType: Original parameters or current parameters
         * \return True if successful, false otherwise.
         */
        bool SaveOrbFile(wxString Filename, SaveType FileSaveType);


        // The Solar System that will be used.
        SolarSystem MainSystem;

        // vector of pointers to GraphInfo structures which contain all the coordinates that need to be drawn.
        std::vector<GraphInfo*> Coordinates;

        // Vector containing planet controls
        std::vector<PlanetControls> PlanetCtrlList;


    private:

        //(*Handlers(OrbFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnTrailSliderCmdScrollChanged(wxScrollEvent& event);
        void OnAccuracySliderCmdScrollChanged(wxScrollEvent& event);
        void OnSpeedSliderCmdScrollChanged(wxScrollEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnSpeedSliderCmdSliderUpdated(wxScrollEvent& event);
        void OnSpeedSliderCmdScrollThumbRelease(wxScrollEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnSaveMenuItemSelected(wxCommandEvent& event);
        void OnOpenMenuItemSelected(wxCommandEvent& event);
        void OnHelpMenuItemSelected(wxCommandEvent& event);
        void OnBenchmarkMenuItemSelected(wxCommandEvent& event);
        void OnButton8Click(wxCommandEvent& event);
        void OnInvertColourCheckBoxClick(wxCommandEvent& event);
        void OnNextStepMenuItemSelected(wxCommandEvent& event);
        void OnPartialRefreshMenuItemSelected(wxCommandEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void OnSaveCurrentMenuItemSelected(wxCommandEvent& event);
        void OnImportPlanetMenuItemClick(wxCommandEvent& event);
        void OnTimeMenuItemSelected(wxCommandEvent& event);
        void OnAddPlanetMenuItemSelected(wxCommandEvent& event);
        void OnClearTrailsMenuItemSelected(wxCommandEvent& event);
        void OnAutoZoomMenuItemSelected(wxCommandEvent& event);
        void OnCustomZoomMenuItemSelected(wxCommandEvent& event);
        void OnZoomInMenuItemSelected(wxCommandEvent& event);
        void OnZoomOutMenuItemSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(OrbFrame)
        static const long ID_SIMGRAPH;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON9;
        static const long ID_STATICTEXT1;
        static const long ID_SPEEDSLIDER;
        static const long ID_STATICTEXT2;
        static const long ID_ACCURACYSLIDER;
        static const long ID_STATICTEXT3;
        static const long ID_TRAILSLIDER;
        static const long ID_BUTTON8;
        static const long ID_CHECKBOX1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_PANEL1;
        static const long idOpenFile;
        static const long idSaveFile;
        static const long idSaveCurrentFile;
        static const long idMenuQuit;
        static const long idAutoZoomMenuItem;
        static const long idCustomZoom;
        static const long idZoomIn;
        static const long idZoomOut;
        static const long idAddPlanetsMenu;
        static const long idImportPlanets;
        static const long idBenchmark;
        static const long idTimeMenu;
        static const long idNextStep;
        static const long idPartialRefreshCheck;
        static const long idClearTrails;
        static const long idMenuAbout;
        static const long idHelp;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(OrbFrame)
        wxMenuItem* ClearTrailsMenuItem;
        wxSlider* SpeedSlider;
        wxCheckBox* InvertColourCheckBox;
        wxButton* Button4;
        wxMenuItem* MenuItem5;
        wxMenuItem* TimeMenuItem;
        wxStaticText* StaticText2;
        wxMenuItem* ZoomOutMenuItem;
        wxScrolledWindow* ScrolledWindow1;
        wxSlider* TrailSlider;
        wxSlider* AccuracySlider;
        wxMenu* Menu3;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxMenuItem* MenuItem4;
        GraphPane* SimGraph;
        wxMenuItem* AutoZoomMenuItem;
        wxStaticText* StaticText8;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxMenuItem* OpenMenuItem;
        wxButton* Button2;
        wxButton* Button6;
        wxButton* Button5;
        wxMenuItem* MenuItem3;
        wxButton* Button3;
        wxMenuItem* BenchmarkMenuItem;
        wxStaticText* StaticText5;
        wxButton* Button7;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxMenuItem* AddPlanetMenuItem;
        wxButton* Button9;
        wxMenuItem* SaveMenuItem;
        wxMenuItem* ZoomInMenuItem;
        wxMenuItem* NextStepMenuItem;
        wxStaticText* StaticText4;
        wxMenuItem* CustomZoomMenuItem;
        wxMenuItem* PartialRefreshMenuItem;
        wxButton* Button8;
        wxMenu* Menu5;
        wxMenu* Menu4;
        //*)
        wxFlexGridSizer* FlexGridSizer2;

        // Refresh Timer: Refreshes screen
        void OnRefreshTimerNotify(wxTimerEvent& event);
        static const long ID_REFRESHTIMER;
        wxTimer* RefreshTimer;
        int RefreshTimerInterval;

        // Calculate Timer: Moves to next time step
        void OnCalcTimerNotify(wxTimerEvent& event);
        static const long ID_CALCTIMER;
        wxTimer* CalcTimer;
        int CalcTimerInterval;

        // Status Timer: Refreshes Status Bar
        void OnStatusTimerNotify(wxTimerEvent& event);
        static const long ID_STATUSTIMER;
        wxTimer* StatusTimer;

        int OverallSpeed;
        int CalcFrequency;
        bool SpeedConfirmed;
        bool FirstDialogOpened;
        int BenchmarkLength;
        bool FullRefreshBool;
        bool AutoZoomBool;

        // Colour Data
        wxColourData* CustomColourData;

        // wxStandardPaths
        wxStandardPaths StdPaths;

        // Functions that affect the rest of the system, unlinked from buttonclicks.
        void ChangeSpeed();
        void ChangeAccuracy();
        void ChangeTrailLength();
        void RefreshStatusBar();
        void StartSystem();
        void PauseSystem();
        void NewPlanetControl(Planet* NewPlanet);
        void ClearPlanetControls();
        void RunBenchmark();
        void ChangeFrame();
        void AddPlanet();
        void RefreshSimulation(bool FullRefresh=true);

        wxCHMHelpController* helpController;

        // View Info Dialog vector
        std::vector<ViewInfoDialog*> InfoDialogs;

        // Convey maximum coordinate bounds to the GraphPane
        double MaxXCoord, MaxYCoord;
        double MaxXExtent, MaxYExtent;
        void GetMaxExtent();

        DECLARE_EVENT_TABLE()
};


#endif // ORBMAIN_H
