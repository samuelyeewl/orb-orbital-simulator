/***************************************************************
 * Name:      OrbMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Samuel Yee (samuelyeewl@gmail.com)
 * Created:   2011-11-10
 * Copyright: Samuel Yee ()
 * License:   GNU GPL v3
 **************************************************************/

#include "wx_pch.h"
#include "OrbMain.h"

//(*InternalHeaders(OrbFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <cmath>
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/msgdlg.h>
#include <climits>

#include "NewPlanetDialog.h"
#include "BenchmarkDialog.h"
#include "ChangeFrameDialog.h"
#include "HelpDialog.h"
#include "ImportPlanetDialog.h"
#include "ZoomDialog.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(OrbFrame)
const long OrbFrame::ID_SIMGRAPH = wxNewId();
const long OrbFrame::ID_STATICTEXT8 = wxNewId();
const long OrbFrame::ID_STATICTEXT4 = wxNewId();
const long OrbFrame::ID_STATICTEXT7 = wxNewId();
const long OrbFrame::ID_STATICTEXT5 = wxNewId();
const long OrbFrame::ID_STATICTEXT6 = wxNewId();
const long OrbFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long OrbFrame::ID_BUTTON3 = wxNewId();
const long OrbFrame::ID_BUTTON6 = wxNewId();
const long OrbFrame::ID_BUTTON7 = wxNewId();
const long OrbFrame::ID_BUTTON9 = wxNewId();
const long OrbFrame::ID_STATICTEXT1 = wxNewId();
const long OrbFrame::ID_SPEEDSLIDER = wxNewId();
const long OrbFrame::ID_STATICTEXT2 = wxNewId();
const long OrbFrame::ID_ACCURACYSLIDER = wxNewId();
const long OrbFrame::ID_STATICTEXT3 = wxNewId();
const long OrbFrame::ID_TRAILSLIDER = wxNewId();
const long OrbFrame::ID_BUTTON8 = wxNewId();
const long OrbFrame::ID_CHECKBOX1 = wxNewId();
const long OrbFrame::ID_BUTTON1 = wxNewId();
const long OrbFrame::ID_BUTTON2 = wxNewId();
const long OrbFrame::ID_BUTTON4 = wxNewId();
const long OrbFrame::ID_BUTTON5 = wxNewId();
const long OrbFrame::ID_PANEL1 = wxNewId();
const long OrbFrame::idOpenFile = wxNewId();
const long OrbFrame::idSaveFile = wxNewId();
const long OrbFrame::idSaveCurrentFile = wxNewId();
const long OrbFrame::idMenuQuit = wxNewId();
const long OrbFrame::idAutoZoomMenuItem = wxNewId();
const long OrbFrame::idCustomZoom = wxNewId();
const long OrbFrame::idZoomIn = wxNewId();
const long OrbFrame::idZoomOut = wxNewId();
const long OrbFrame::idAddPlanetsMenu = wxNewId();
const long OrbFrame::idImportPlanets = wxNewId();
const long OrbFrame::idBenchmark = wxNewId();
const long OrbFrame::idTimeMenu = wxNewId();
const long OrbFrame::idNextStep = wxNewId();
const long OrbFrame::idPartialRefreshCheck = wxNewId();
const long OrbFrame::idClearTrails = wxNewId();
const long OrbFrame::idMenuAbout = wxNewId();
const long OrbFrame::idHelp = wxNewId();
const long OrbFrame::ID_STATUSBAR1 = wxNewId();
//*)
const long OrbFrame::ID_REFRESHTIMER = wxNewId();
const long OrbFrame::ID_CALCTIMER = wxNewId();
const long OrbFrame::ID_STATUSTIMER = wxNewId();

BEGIN_EVENT_TABLE(OrbFrame,wxFrame)
    //(*EventTable(OrbFrame)
    //*)
    EVT_TIMER(ID_REFRESHTIMER, OrbFrame::OnRefreshTimerNotify)
    EVT_TIMER(ID_CALCTIMER, OrbFrame::OnCalcTimerNotify)
    EVT_TIMER(ID_STATUSTIMER, OrbFrame::OnStatusTimerNotify)
END_EVENT_TABLE()

OrbFrame::OrbFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(OrbFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer5;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxMenuItem* MenuItem1;
    //wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Orb: An Orbital Simulator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Simulation"));
    SimGraph = new GraphPane(Panel1,ID_SIMGRAPH,wxDefaultPosition,wxDefaultSize, this);
    StaticBoxSizer1->Add(SimGraph, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Planets"));
    ScrolledWindow1 = new wxScrolledWindow(Panel1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxSize(345,34), wxHSCROLL|wxVSCROLL, _T("ID_SCROLLEDWINDOW1"));
    ScrolledWindow1->SetMinSize(wxSize(345,34));
    ScrolledWindow1->SetMaxSize(wxSize(345,34));
    FlexGridSizer2 = new wxFlexGridSizer(0, 5, 0, 0);
    FlexGridSizer2->AddGrowableCol(2);
    StaticText8 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticText8->SetMinSize(wxSize(15,0));
    FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText4 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT4, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText4->SetMinSize(wxSize(160,13));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText7 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT7, _("Mass (kg)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText7->SetMinSize(wxSize(50,13));
    FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText5 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT5, _("Colour"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText6 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT6, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    ScrolledWindow1->SetSizer(FlexGridSizer2);
    FlexGridSizer2->SetSizeHints(ScrolledWindow1);
    StaticBoxSizer2->Add(ScrolledWindow1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Add Planet"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(Button3, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button6 = new wxButton(Panel1, ID_BUTTON6, _("Edit Planet"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    BoxSizer4->Add(Button6, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button7 = new wxButton(Panel1, ID_BUTTON7, _("Delete Planet"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer4->Add(Button7, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button9 = new wxButton(Panel1, ID_BUTTON9, _("View Info"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    BoxSizer4->Add(Button9, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Global Settings"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpeedSlider = new wxSlider(Panel1, ID_SPEEDSLIDER, 60, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SPEEDSLIDER"));
    FlexGridSizer1->Add(SpeedSlider, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Accuracy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    AccuracySlider = new wxSlider(Panel1, ID_ACCURACYSLIDER, 12, 0, 20, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ACCURACYSLIDER"));
    AccuracySlider->SetTickFreq(5);
    FlexGridSizer1->Add(AccuracySlider, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Trail Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TrailSlider = new wxSlider(Panel1, ID_TRAILSLIDER, 60, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TRAILSLIDER"));
    TrailSlider->SetTickFreq(5);
    FlexGridSizer1->Add(TrailSlider, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer4->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    Button8 = new wxButton(Panel1, ID_BUTTON8, _("Change Frame"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    BoxSizer5->Add(Button8, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    InvertColourCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Invert Colours"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    InvertColourCheckBox->SetValue(false);
    BoxSizer5->Add(InvertColourCheckBox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(BoxSizer5, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer3->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Global Controls"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Go"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer3->Add(Button1, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Pause"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer3->Add(Button2, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer3->Add(Button4, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer3->Add(Button5, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer3->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    OpenMenuItem = new wxMenuItem(Menu1, idOpenFile, _("&Open File\tCtrl+O"), _("Open Orb System"), wxITEM_NORMAL);
    Menu1->Append(OpenMenuItem);
    SaveMenuItem = new wxMenuItem(Menu1, idSaveFile, _("&Save File\tCtrl+S"), _("Save System"), wxITEM_NORMAL);
    Menu1->Append(SaveMenuItem);
    MenuItem4 = new wxMenuItem(Menu1, idSaveCurrentFile, _("Save &Current Positions\tCtrl+Shift+S"), _("Save System in Current State"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt+F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu4 = new wxMenu();
    AutoZoomMenuItem = new wxMenuItem(Menu4, idAutoZoomMenuItem, _("&Automatic Zoom"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(AutoZoomMenuItem);
    AutoZoomMenuItem->Check(true);
    CustomZoomMenuItem = new wxMenuItem(Menu4, idCustomZoom, _("&Custom Zoom"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(CustomZoomMenuItem);
    ZoomInMenuItem = new wxMenuItem(Menu4, idZoomIn, _("Zoom &In\tCtrl+Shift+="), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(ZoomInMenuItem);
    ZoomOutMenuItem = new wxMenuItem(Menu4, idZoomOut, _("Zoom &Out\tCtrl+-"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(ZoomOutMenuItem);
    MenuBar1->Append(Menu4, _("&View"));
    Menu5 = new wxMenu();
    AddPlanetMenuItem = new wxMenuItem(Menu5, idAddPlanetsMenu, _("&Add Planet\tCtrl+N"), _("Add a Planet"), wxITEM_NORMAL);
    Menu5->Append(AddPlanetMenuItem);
    MenuItem5 = new wxMenuItem(Menu5, idImportPlanets, _("&Import Planet\tCtrl+I"), _("Import planetary data from NASA Horizons ephemerides"), wxITEM_NORMAL);
    Menu5->Append(MenuItem5);
    MenuBar1->Append(Menu5, _("&Planets"));
    Menu3 = new wxMenu();
    BenchmarkMenuItem = new wxMenuItem(Menu3, idBenchmark, _("&Benchmark"), _("Run benchmarking tools to test performance"), wxITEM_NORMAL);
    Menu3->Append(BenchmarkMenuItem);
    TimeMenuItem = new wxMenuItem(Menu3, idTimeMenu, _("&Time Refresh"), _("Time Refresh Speed"), wxITEM_NORMAL);
    Menu3->Append(TimeMenuItem);
    NextStepMenuItem = new wxMenuItem(Menu3, idNextStep, _("&Next Step\tCtrl+Right"), _("Advance one step"), wxITEM_NORMAL);
    Menu3->Append(NextStepMenuItem);
    PartialRefreshMenuItem = new wxMenuItem(Menu3, idPartialRefreshCheck, _("&Partial Refresh (Beta)"), _("Enable partial panel refresh"), wxITEM_CHECK);
    Menu3->Append(PartialRefreshMenuItem);
    ClearTrailsMenuItem = new wxMenuItem(Menu3, idClearTrails, _("&Clear Trails\tF5"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(ClearTrailsMenuItem);
    MenuBar1->Append(Menu3, _("&Advanced"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("&About"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(Menu2, idHelp, _("&Help\tF1"), _("Opens the manual for Orb"), wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuBar1->Append(Menu2, _("&Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { 100, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton3Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton7Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton9Click);
    Connect(ID_SPEEDSLIDER,wxEVT_SCROLL_THUMBRELEASE,(wxObjectEventFunction)&OrbFrame::OnSpeedSliderCmdScrollThumbRelease);
    Connect(ID_SPEEDSLIDER,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OrbFrame::OnSpeedSliderCmdScrollChanged);
    Connect(ID_SPEEDSLIDER,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&OrbFrame::OnSpeedSliderCmdSliderUpdated);
    Connect(ID_ACCURACYSLIDER,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OrbFrame::OnAccuracySliderCmdScrollChanged);
    Connect(ID_TRAILSLIDER,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OrbFrame::OnTrailSliderCmdScrollChanged);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton8Click);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&OrbFrame::OnInvertColourCheckBoxClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton2Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OrbFrame::OnButton5Click);
    Connect(idOpenFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnOpenMenuItemSelected);
    Connect(idSaveFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnSaveMenuItemSelected);
    Connect(idSaveCurrentFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnSaveCurrentMenuItemSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnQuit);
    Connect(idAutoZoomMenuItem,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnAutoZoomMenuItemSelected);
    Connect(idCustomZoom,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnCustomZoomMenuItemSelected);
    Connect(idZoomIn,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnZoomInMenuItemSelected);
    Connect(idZoomOut,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnZoomOutMenuItemSelected);
    Connect(idAddPlanetsMenu,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnAddPlanetMenuItemSelected);
    Connect(idImportPlanets,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnImportPlanetMenuItemClick);
    Connect(idBenchmark,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnBenchmarkMenuItemSelected);
    Connect(idTimeMenu,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnTimeMenuItemSelected);
    Connect(idNextStep,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnNextStepMenuItemSelected);
    Connect(idPartialRefreshCheck,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnPartialRefreshMenuItemSelected);
    Connect(idClearTrails,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnClearTrailsMenuItemSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnAbout);
    Connect(idHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OrbFrame::OnHelpMenuItemSelected);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&OrbFrame::OnClose);
    //*)

    StdPaths = wxStandardPaths::Get();

    // Initialize Graph Pane
    SimGraph->SetGraphInfoAddress(&Coordinates);

    // Initialize Timers
    RefreshTimer = new wxTimer(this, ID_REFRESHTIMER);
    RefreshTimerInterval = 50;

    CalcTimer = new wxTimer(this, ID_CALCTIMER);
    CalcTimerInterval = 50;
    CalcFrequency = 10;
    SimGraph->SetNewPointNum(CalcFrequency);

    StatusTimer = new wxTimer(this, ID_STATUSTIMER);
    StatusTimer->Start(500, false);

    BenchmarkLength = 100000;
    FullRefreshBool = true;

    // Overall Speed = Frequency x 50 / Calc Interval
    OverallSpeed = 5;
    SpeedConfirmed = false;

    // Initialize other variables
    MaxXCoord = 0;
    MaxYCoord = 0;
    MaxXExtent = 0;
    MaxYExtent = 0;
    CustomColourData = NULL;
    FirstDialogOpened = false;

    ScrolledWindow1->SetSizer(FlexGridSizer2);
    ScrolledWindow1->SetScrollRate(2, 2);

    wxString FileName = StdPaths.GetResourcesDir();
    FileName.Append("\\OrbIcon.ico");
    wxIcon OrbIcon;
    OrbIcon.LoadFile(FileName, wxBITMAP_TYPE_ICO);
    this->SetIcon(OrbIcon);

    helpController = new wxCHMHelpController(this);
    FileName = StdPaths.GetResourcesDir();
    FileName.Append("\\Orb.chm");
    helpController->Initialize(FileName);

    AutoZoomBool = true;
}

OrbFrame::~OrbFrame()
{
    //(*Destroy(OrbFrame)
    //*)
    StatusTimer->Stop();
}


void OrbFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void OrbFrame::OnAbout(wxCommandEvent& event)
{
    HelpDialog* HelpDlg = new HelpDialog(this);

    wxString FileName = StdPaths.GetResourcesDir();
    FileName.Append("\\OrbIcon.png");
    wxImage AboutImage;
    AboutImage.AddHandler(new wxPNGHandler);
    AboutImage.LoadFile(FileName, wxBITMAP_TYPE_PNG);

    wxBitmap AboutBitmap(AboutImage);

    (*HelpDlg).StaticBitmap1->SetBitmap(AboutBitmap);
    HelpDlg->ShowModal();

    delete HelpDlg;
}

// Go Button
void OrbFrame::OnButton1Click(wxCommandEvent& event)
{
    StartSystem();
}

void OrbFrame::StartSystem()
{
    if (MainSystem.IsEmpty()) return;

    if (RefreshTimer == NULL) wxMessageBox("NULL");
    RefreshTimer->Start(RefreshTimerInterval, false);
    CalcTimer->Start(CalcTimerInterval, false);

    SimGraph->SetNewPointNum(CalcFrequency);

    RefreshSimulation();
}

void OrbFrame::OnRefreshTimerNotify(wxTimerEvent& event)
{
    RefreshSimulation(FullRefreshBool);
}

void OrbFrame::RefreshSimulation(bool FullRefresh)
{
    // Do nothing if no planets
    if (MainSystem.IsEmpty()) return;
    // True if scale was changed, or moving/rotating origin.
    MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);

    GetMaxExtent();

    if (FullRefresh) {
        SimGraph->CalculateScale(MaxXExtent, MaxYExtent);
        SimGraph->Refresh();
    }
    else SimGraph->PartialRefresh();
}

void OrbFrame::GetMaxExtent()
{
    if (AutoZoomBool) {
        if (MaxXCoord > 0.5 * SCALEMAXTOLERANCE * MaxXExtent || MaxXCoord < 0.5 * SCALEMINTOLERANCE * MaxXExtent) {
            MaxXExtent = 2 * SCALEMAXTOLERANCE * MaxXCoord;
        }
        if (MaxYCoord > 0.5 * SCALEMAXTOLERANCE * MaxYExtent || MaxYCoord < 0.5 * SCALEMINTOLERANCE * MaxYExtent) {
            MaxYExtent = 2 * SCALEMAXTOLERANCE * MaxYCoord;
        }
    }
}

void OrbFrame::OnCalcTimerNotify(wxTimerEvent& event)
{
    int i;
    for (i = 0; i < CalcFrequency; i++) {
        MainSystem.NextStep();
    }
}

// Pause Button
void OrbFrame::OnButton2Click(wxCommandEvent& event)
{
    PauseSystem();
}

void OrbFrame::PauseSystem()
{
    // Pause the Simulation
    if (RefreshTimer != NULL && RefreshTimer->IsRunning()) {
        RefreshTimer->Stop();
    }
    if (CalcTimer != NULL && CalcTimer->IsRunning()) {
        CalcTimer->Stop();
    }
}

// Add Planet Button
void OrbFrame::OnButton3Click(wxCommandEvent& event)
{
    AddPlanet();
}

void OrbFrame::AddPlanet()
{
     PauseSystem();

    /*
        Create dialog to ask for planet parameters
    */
    NewPlanetDialog dlg(this);
    dlg.SetColourData(CustomColourData);
    long returnvalue = dlg.ShowModal();

    /*
        If OK is clicked, create new planet.
        If close is clicked, do nothing.
    */
    if (returnvalue == wxID_OK) {
        // Get Input Data
        double x, y, z, vX, vY, vZ, mass;
        wxString PlanetName;
        wxString textctrlinput;

        textctrlinput = dlg.XTextCtrl->GetValue();
        textctrlinput.ToDouble(&x);
        textctrlinput = dlg.YTextCtrl->GetValue();
        textctrlinput.ToDouble(&y);
        textctrlinput = dlg.ZTextCtrl->GetValue();
        textctrlinput.ToDouble(&z);
        textctrlinput = dlg.VxTextCtrl->GetValue();
        textctrlinput.ToDouble(&vX);
        textctrlinput = dlg.VyTextCtrl->GetValue();
        textctrlinput.ToDouble(&vY);
        textctrlinput = dlg.VzTextCtrl->GetValue();
        textctrlinput.ToDouble(&vZ);
        textctrlinput = dlg.MassTextCtrl->GetValue();
        textctrlinput.ToDouble(&mass);

        PlanetName = dlg.NameTxtCtrl->GetValue();

        // Get Colour
        int ColourSelection = dlg.ColourChoice->GetSelection();
        const wxColour* ColourSelected;
        switch (ColourSelection) {
            case 0:
                ColourSelected = wxBLACK;
                break;
            case 1:
                ColourSelected = wxRED;
                break;
            case 2:
                ColourSelected = wxBLUE;
                break;
            case 3:
                ColourSelected = wxGREEN;
                break;
            case 4:
                ColourSelected = &(dlg.ColourDlgData->GetColour());
                break;
            default:
                ColourSelected = wxBLACK;
                break;
        }

        // Get Custom Colour Data
        CustomColourData = dlg.ColourDlgData;

        // Get Terminator Size
        int TerminatorSize = dlg.SizeChoice->GetSelection();

        // Call Planet Constructor
        Planet* NewPlanet = MainSystem.CreateNewPlanet(x * pow(10, 6), y * pow(10, 6), z * pow(10, 6),
                                                       vX * pow(10, 3), vY * pow(10, 3), vZ * pow(10, 3),
                                                       mass * pow(10, 20), const_cast<wxColour*>(ColourSelected), TerminatorSize, PlanetName);

        // Update Coordinates
        MainSystem.UpdateCoordinates(&Coordinates);
        MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);

        // New set of Planet Controls
        NewPlanetControl(NewPlanet);

        RefreshSimulation();

    } else if (returnvalue == wxID_CANCEL) {

    }
}

void OrbFrame::NewPlanetControl(Planet* NewPlanet)
{
    PlanetControls NewPlanetControl;
    NewPlanetControl.ControlPlanet = NewPlanet;
    NewPlanetControl.activated = false;
    PlanetCtrlList.push_back(NewPlanetControl);
    UpdatePlanetControls();
}

// Reset System Button
void OrbFrame::OnButton4Click(wxCommandEvent& event)
{
    if (MainSystem.IsEmpty()) return;

    // Stop the Simulation
    PauseSystem();

    // Clear Coordinates
    MainSystem.ResetCoordinates();
    MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);

    // Refresh Screen
    RefreshSimulation();
}

// Clear Button
void OrbFrame::OnButton5Click(wxCommandEvent& event)
{
    if (MainSystem.IsEmpty()) return;

    // Stop the Simulation
    PauseSystem();

    // Close info dialogs
    std::vector<ViewInfoDialog*>::iterator DlgIterator = InfoDialogs.begin();
    while (DlgIterator != InfoDialogs.end()) {
        (*DlgIterator)->Close();
        DlgIterator++;
    }

    // Clear System
    MainSystem.ResetSystem();

    // Clear controls
    ClearPlanetControls();
    UpdatePlanetControls();

    // Update Coordinates
    MainSystem.UpdateCoordinates(&Coordinates);
    MaxXCoord = 0;
    MaxYCoord = 0;

    // Refresh Screen
    RefreshSimulation();
    RefreshStatusBar();
}

void OrbFrame::ClearPlanetControls()
{
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        (*PlanetCtrlIt).ControlPlanet = NULL;
        PlanetCtrlIt++;
    }
    UpdatePlanetControls();
}

void OrbFrame::OnClose(wxCloseEvent& event)
{
    // Stop Simulation
    PauseSystem();
    StatusTimer->Stop();

    event.Skip();
}

void OrbFrame::OnTrailSliderCmdScrollChanged(wxScrollEvent& event)
{
    ChangeTrailLength();
}

void OrbFrame::ChangeTrailLength()
{
    // SliderValue is from 0 to 100.
    // Trail Length should vary from 1 to 1,000,000
    // Use a logarithmic scale
    double SliderValue = TrailSlider->GetValue();
    double ActualLength = std::pow(double(10), double(SliderValue*3/50));

    MainSystem.SetTrailLength(int(ActualLength));

    // Slow down refresh rate as trail length increases
    /*
    if (ActualLength > 50000) {
        RefreshTimerInterval = int(ActualLength / 100000 * 100);
    } else {
        RefreshTimerInterval = 50;
    }
    if (RefreshTimer != NULL && RefreshTimer->IsRunning()) {
        RefreshTimer->Start(RefreshTimerInterval, false);
    }
    */
}

void OrbFrame::OnAccuracySliderCmdScrollChanged(wxScrollEvent& event)
{
    ChangeAccuracy();
}

void OrbFrame::ChangeAccuracy()
{
    // SliderValue is from 0 to 100.
    // Accuracy should vary from a timestep of 100s to 10,000,000 seconds (~ 10 months)
    // Use a logarithmic scale
    // Reverse order
    double SliderValue = 20 - AccuracySlider->GetValue();
    double ActualAccuracy = std::pow(double(10), double(SliderValue/3+2));

    MainSystem.SetStepSize(int(ActualAccuracy));
}

void OrbFrame::OnSpeedSliderCmdScrollChanged(wxScrollEvent& event)
{
    ChangeSpeed();
}

void OrbFrame::ChangeSpeed()
{
    // SliderValue is from 0 to 100.
    double SliderValue = SpeedSlider->GetValue();
    double ActualSpeed = SliderValue/10;

    if (SliderValue > 80 && SpeedConfirmed == false) {
        // if (CalcTimer != NULL) CalcTimer->Stop();

        int answer = wxMessageBox("Are you sure you want to raise the speed? Your computer may become unstable.", "Confirm Speed", wxYES_NO | wxICON_EXCLAMATION, this);
        if (answer == wxYES) {
            // Continue
        } else {
            SpeedSlider->SetValue(79);
            ActualSpeed = 7.9;
        }
        SpeedConfirmed = true;
    }
    /* Uncomment if warning should be repeated more than once in a session.
    else if (SliderValue <= 80 && SpeedConfirmed == true) {
        SpeedConfirmed = false;
    }
    */

    if (ActualSpeed >= 5) {
        CalcTimerInterval = 50;
        CalcFrequency = int(pow(double(10), double(ActualSpeed-5)));
        OverallSpeed = int(ActualSpeed);
    } else if (ActualSpeed == 0) {
        CalcTimerInterval = INT_MAX;
    } else {
        CalcTimerInterval = int(250/ActualSpeed);
        CalcFrequency = 1;
        OverallSpeed = int(ActualSpeed);
    }

    if (CalcTimer != NULL && CalcTimer->IsRunning()) {
        CalcTimer->Start(CalcTimerInterval, false);
    }

    SimGraph->SetNewPointNum(CalcFrequency);

}

void OrbFrame::OnSpeedSliderCmdSliderUpdated(wxScrollEvent& event)
{
    // Do nothing
}

void OrbFrame::OnSpeedSliderCmdScrollThumbRelease(wxScrollEvent& event)
{
    // Do nothing
}


void OrbFrame::OnStatusTimerNotify(wxTimerEvent& event)
{
    RefreshStatusBar();
}

void OrbFrame::RefreshStatusBar()
{
    // Get Time
    double TimeRemainder, days;
    int years;
    double TimeGone = MainSystem.GetTimeElapsed();

    if (TimeGone == 0) {
        return;
    } else {
        TimeRemainder = std::fmod(TimeGone, double(365.256363004*86400));
        days = TimeRemainder/86400;

        TimeGone -= TimeRemainder;
        years = int(TimeGone / (365.256363004*86400));
    }

    wxString OutputTime;
    if (years == 0) {
        OutputTime = wxString::Format("%.2f days", days);
    } else {
        OutputTime = wxString::Format("%d years, %.2f days", years, days);
    }

    // Get Scale
    double ScaleInAU = SimGraph->GetXExtent() / METRE_PER_AU;
    wxString OutputScale = wxString::Format("Scale: %.2f AU\t\t", ScaleInAU);

    StatusBar1->PushStatusText(OutputScale, 0);
    StatusBar1->PushStatusText(OutputTime, 1);
}

void OrbFrame::UpdatePlanetControls()
{
    if (PlanetCtrlList.empty()) return;
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    bool CurrentDeleted = false;

    // If PlanetControl is activated but ControlPlanet = NULL, it will be deleted.
    // If PlanetControl is activated with ControlPlanet is non-NULL, it will be updated.
    // If PlanetControl is deactivated but ControlPlanet is non-NULL, it will be added.
    // It is not possible to reach a state of deactivation and NULL because it would have been deleted.

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        CurrentDeleted = false;
        if ((*PlanetCtrlIt).activated == false && (*PlanetCtrlIt).ControlPlanet != NULL) {
            // For first time activation
            // Checkbox
            (*PlanetCtrlIt).CheckBox = new wxCheckBox(ScrolledWindow1, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
            (*PlanetCtrlIt).CheckBox->SetValue(false);
            FlexGridSizer2->Add((*PlanetCtrlIt).CheckBox, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTRE_VERTICAL, 5);

            // NameTextCtrl
            (*PlanetCtrlIt).NameStaticText = new wxStaticText(ScrolledWindow1, -1, (*PlanetCtrlIt).ControlPlanet->PName, wxDefaultPosition, wxDefaultSize, 0);
            FlexGridSizer2->Add((*PlanetCtrlIt).NameStaticText, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTRE_VERTICAL, 5);

            // MassTextCtrl
            wxString NumberString;
            NumberString = wxString::Format("%.2e", (*PlanetCtrlIt).ControlPlanet->Mass);
            (*PlanetCtrlIt).MassStaticText = new wxStaticText(ScrolledWindow1, -1, NumberString, wxDefaultPosition, wxDefaultSize, 0);
            FlexGridSizer2->Add((*PlanetCtrlIt).MassStaticText, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTRE_VERTICAL, 5);

            // ColourPanel
            (*PlanetCtrlIt).ColourPanel = new wxPanel(ScrolledWindow1, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
            (*PlanetCtrlIt).ColourPanel->SetMinSize(wxSize(40, 3));
            (*PlanetCtrlIt).ColourPanel->SetMaxSize(wxSize(40, 3));
            (*PlanetCtrlIt).ColourPanel->SetBackgroundColour(((*PlanetCtrlIt).ControlPlanet->PlanetInfo).TrailColour);
            FlexGridSizer2->Add((*PlanetCtrlIt).ColourPanel, 1, wxALL|wxALIGN_CENTRE_HORIZONTAL|wxALIGN_CENTRE_VERTICAL, 0);

            // SizeTextCtrl
            NumberString = wxString::Format("%d", (*PlanetCtrlIt).ControlPlanet->PlanetInfo.TermSize);
            (*PlanetCtrlIt).SizeStaticText = new wxStaticText(ScrolledWindow1, -1, NumberString, wxDefaultPosition, wxDefaultSize, 0);
            FlexGridSizer2->Add((*PlanetCtrlIt).SizeStaticText, 1, wxALL|wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTRE_VERTICAL|wxALIGN_CENTRE_HORIZONTAL, 5);

            (*PlanetCtrlIt).activated = true;

        } else if ((*PlanetCtrlIt).activated == true && (*PlanetCtrlIt).ControlPlanet == NULL) {
            // For deletion
            // First, detach and delete all controls
            FlexGridSizer2->Detach((*PlanetCtrlIt).CheckBox);
            delete (*PlanetCtrlIt).CheckBox;

            FlexGridSizer2->Detach((*PlanetCtrlIt).NameStaticText);
            delete (*PlanetCtrlIt).NameStaticText;

            FlexGridSizer2->Detach((*PlanetCtrlIt).MassStaticText);
            delete (*PlanetCtrlIt).MassStaticText;

            FlexGridSizer2->Detach((*PlanetCtrlIt).ColourPanel);
            delete (*PlanetCtrlIt).ColourPanel;

            FlexGridSizer2->Detach((*PlanetCtrlIt).SizeStaticText);
            delete (*PlanetCtrlIt).SizeStaticText;

            // Erase Planet Controls struct
            PlanetCtrlList.erase(PlanetCtrlIt);

            CurrentDeleted = true;
        } else if ((*PlanetCtrlIt).activated == true && (*PlanetCtrlIt).ControlPlanet != NULL) {
            // For updating of controls
            (*PlanetCtrlIt).NameStaticText->SetLabel((*PlanetCtrlIt).ControlPlanet->PName);

                wxString NumberString;
            NumberString = wxString::Format("%.2e", (*PlanetCtrlIt).ControlPlanet->Mass);
            (*PlanetCtrlIt).MassStaticText->SetLabel(NumberString);

            NumberString = wxString::Format("%d", (*PlanetCtrlIt).ControlPlanet->PlanetInfo.TermSize);
            (*PlanetCtrlIt).SizeStaticText->SetLabel(NumberString);

            (*PlanetCtrlIt).ColourPanel->SetBackgroundColour((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour);
            (*PlanetCtrlIt).ColourPanel->Refresh();
        }

        if (PlanetCtrlIt == PlanetCtrlList.end()) break;

        // Only increment if current planet was not deleted, as the iterator will point to a non-deleted control.
        if (CurrentDeleted == false) PlanetCtrlIt++;
    }
    // Refresh Sizer
    ScrolledWindow1->SetSizer(FlexGridSizer2);
    FlexGridSizer2->FitInside(ScrolledWindow1);
}

// Delete Planet Button
void OrbFrame::OnButton7Click(wxCommandEvent& event)
{
    if (MainSystem.IsEmpty()) return;

    // Stop the Simulation
    PauseSystem();

    // Delete Planets
    // Declare iterator
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        if ((*PlanetCtrlIt).CheckBox->IsChecked()) {
            // Delete Planet
            int PlanetId = (*PlanetCtrlIt).ControlPlanet->PlanetId;
            MainSystem.DeletePlanet(PlanetId);

            // Remove Planet from Planet Controls
            (*PlanetCtrlIt).ControlPlanet = NULL;
        }

        PlanetCtrlIt++;
    }
    UpdatePlanetControls();
    MainSystem.UpdateCoordinates(&Coordinates);

    MainSystem.ResetCoordinates();

    // Refresh Screen
    RefreshSimulation();
}

// Edit Planet Button
void OrbFrame::OnButton6Click(wxCommandEvent& event)
{
    // Declare iterator
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    // Stop the Simulation
    PauseSystem();

    // Reset Coordinates
    MainSystem.ResetCoordinates();

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        if ((*PlanetCtrlIt).CheckBox->IsChecked()) {
            /*
                Create dialog to ask for new planet parameters
            */
            NewPlanetDialog dlg(this);
            if (CustomColourData != NULL) dlg.SetColourData(CustomColourData);
            dlg.SetLabel("Edit Planet");
            // Put in existing numbers.
            wxString TempString;
            dlg.NameTxtCtrl->SetValue((*PlanetCtrlIt).ControlPlanet->PName);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialX / std::pow(double(10), double(6)));
            dlg.XTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialY / std::pow(double(10), double(6)));
            dlg.YTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialZ / std::pow(double(10), double(6)));
            dlg.ZTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialvX/ std::pow(double(10), double(3)));
            dlg.VxTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialvY/ std::pow(double(10), double(3)));
            dlg.VyTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->InitialvZ/ std::pow(double(10), double(3)));
            dlg.VzTextCtrl->SetValue(TempString);

            TempString = wxString::Format("%e", (*PlanetCtrlIt).ControlPlanet->Mass/ std::pow(double(10), double(20)));
            dlg.MassTextCtrl->SetValue(TempString);

            dlg.SizeChoice->SetSelection((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TermSize);

            if ((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour == *wxBLACK) {
                dlg.ColourChoice->SetSelection(0);
            } else if ((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour == *wxRED) {
                dlg.ColourChoice->SetSelection(1);
            } else if ((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour == *wxBLUE) {
                dlg.ColourChoice->SetSelection(2);
            } else if ((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour == *wxGREEN) {
                dlg.ColourChoice->SetSelection(3);
            } else {
                dlg.ColourChoice->SetSelection(4);
                dlg.ColourDlgData->SetColour((*PlanetCtrlIt).ControlPlanet->PlanetInfo.TrailColour);
            }


            long returnvalue = dlg.ShowModal();


            /*
                If OK is clicked, create new planet.
                If close is clicked, do nothing.
            */
            if (returnvalue == wxID_OK) {
                // Get Input Data
                double x, y, z, vX, vY, vZ, mass;
                wxString PlanetName;
                wxString textctrlinput;

                textctrlinput = dlg.XTextCtrl->GetValue();
                textctrlinput.ToDouble(&x);
                textctrlinput = dlg.YTextCtrl->GetValue();
                textctrlinput.ToDouble(&y);
                textctrlinput = dlg.ZTextCtrl->GetValue();
                textctrlinput.ToDouble(&z);
                textctrlinput = dlg.VxTextCtrl->GetValue();
                textctrlinput.ToDouble(&vX);
                textctrlinput = dlg.VyTextCtrl->GetValue();
                textctrlinput.ToDouble(&vY);
                textctrlinput = dlg.VzTextCtrl->GetValue();
                textctrlinput.ToDouble(&vZ);
                textctrlinput = dlg.MassTextCtrl->GetValue();
                textctrlinput.ToDouble(&mass);

                PlanetName = dlg.NameTxtCtrl->GetValue();

                // Get Colour
                int ColourSelection = dlg.ColourChoice->GetSelection();
                const wxColour* ColourSelected;
                switch (ColourSelection) {
                    case 0:
                        ColourSelected = wxBLACK;
                        break;
                    case 1:
                        ColourSelected = wxRED;
                        break;
                    case 2:
                        ColourSelected = wxBLUE;
                        break;
                    case 3:
                        ColourSelected = wxGREEN;
                        break;
                    case 4:
                        ColourSelected = &(dlg.ColourDlgData->GetColour());
                        break;
                    default:
                        ColourSelected = wxBLACK;
                        break;
                }

                // Get Custom Colour Data
                CustomColourData = dlg.ColourDlgData;

                // Get Terminator Size
                int TerminatorSize = dlg.SizeChoice->GetSelection();

                // Call Planet Editor
                MainSystem.EditPlanet((*PlanetCtrlIt).ControlPlanet->PlanetId, x * pow(10, 6), y * pow(10, 6), z * pow(10, 6),
                                        vX * pow(10, 3), vY * pow(10, 3), vZ * pow(10, 3),
                                      mass * pow(10, 20), const_cast<wxColour*>(ColourSelected), TerminatorSize, PlanetName);

                // Update Coordinates
                MainSystem.UpdateCoordinates(&Coordinates);
                MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);


            } else if (returnvalue == wxID_CANCEL) {

            }
        }

        PlanetCtrlIt++;
    }

    MainSystem.ResetCoordinates();
    MainSystem.UpdateCoordinates(&Coordinates);
    MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);

    UpdatePlanetControls();

    // Refresh Screen
    RefreshSimulation();
    RefreshStatusBar();
}

void OrbFrame::OnSaveMenuItemSelected(wxCommandEvent& event)
{
    wxFileDialog* SaveFileDialog;
    // Access original application directory on first open
    if (FirstDialogOpened == false) {
        wxString SamplesDir = StdPaths.GetUserDataDir();
        SamplesDir.append("\\samples");
        SaveFileDialog = new wxFileDialog(this, "Choose a file", SamplesDir, wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_SAVE | wxFD_OVERWRITE_PROMPT | wxFD_CHANGE_DIR);
        FirstDialogOpened= true;
    } else {
        SaveFileDialog = new wxFileDialog(this, "Choose a file", wxGetCwd(), wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_SAVE | wxFD_OVERWRITE_PROMPT | wxFD_CHANGE_DIR);
    }


    if (SaveFileDialog->ShowModal() == wxID_OK) {
        SaveOrbFile(SaveFileDialog->GetPath(), SAVE_ORIGINAL);
    }

}

bool OrbFrame::SaveOrbFile(wxString Filename, SaveType FileSaveType)
{
    if (Filename != wxEmptyString) {
        wxTextFile SaveFile(Filename);
        if (SaveFile.Exists()) {
            SaveFile.Open(Filename);
            SaveFile.Clear();
        } else {
            SaveFile.Create();
        }

        /*
            Save Global Parameters to file first
        */
        wxString TempOutputString;
        wxString NumString;
        // Header
        SaveFile.AddLine("<System Settings>");
        // Reference Frame
        TempOutputString = "ReferenceFrame=";
        NumString = wxString::Format("%d", MainSystem.FrameChoice);
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        if (MainSystem.FrameChoice == CUSTOMORIGIN) {
            // Output custom origin coordinates
            TempOutputString = "CustomX=";
            NumString = wxString::Format("%.15e", MainSystem.CustomX);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);

            TempOutputString = "CustomY=";
            NumString = wxString::Format("%.15e", MainSystem.CustomY);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);

            TempOutputString = "CustomZ=";
            NumString = wxString::Format("%.15e", MainSystem.CustomZ);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);
        } else if (MainSystem.FrameChoice == PLANETORIGIN) {
            // Output custom planet id
            TempOutputString = "CustomPlanetOriginId=";
            NumString = wxString::Format("%d", MainSystem.CustomPlanetOriginId);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);
        }
        // Translation of Origin
        TempOutputString = "TranslatingOrigin=";
        NumString = wxString::Format("%d", MainSystem.TranslatingOrigin);
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        if (MainSystem.TranslatingOrigin) {
            TempOutputString = "OriginvX=";
            NumString = wxString::Format("%.15e", MainSystem.OriginvX);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);

            TempOutputString = "OriginvY=";
            NumString = wxString::Format("%.15e", MainSystem.OriginvY);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);

            TempOutputString = "OriginvZ=";
            NumString = wxString::Format("%.15e", MainSystem.OriginvZ);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);
        }
        // Rotation about Origin
        TempOutputString = "Rotation=";
        NumString = wxString::Format("%d", MainSystem.Rotation);
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        if (MainSystem.Rotation) {
            TempOutputString = "RotationFrequency=";
            NumString = wxString::Format("%.15e", MainSystem.RotationFrequency);
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);
        }
        // Speed
        TempOutputString = "Speed=";
        NumString = wxString::Format("%d", SpeedSlider->GetValue());
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        // Accuracy
        TempOutputString = "Accuracy=";
        NumString = wxString::Format("%d", AccuracySlider->GetValue());
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        // Trail Length
        TempOutputString = "TrailLength=";
        NumString = wxString::Format("%d", TrailSlider->GetValue());
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        // Zooming
        TempOutputString = "AutoZoom=";
        NumString = wxString::Format("%d", AutoZoomBool);
        TempOutputString << NumString;
        SaveFile.AddLine(TempOutputString);
        if (!AutoZoomBool) {
            TempOutputString = "ZoomFactor=";
            NumString = wxString::Format("%.15f", SimGraph->GetXExtent());
            TempOutputString << NumString;
            SaveFile.AddLine(TempOutputString);
        }
        // Closer
        SaveFile.AddLine("</System Settings>");

        /*
            Write planets to file
        */
        // Check if 0 planets
        if (!MainSystem.IsEmpty()) {

            // Declare iterator for PlanetList
            std::map<int, Planet*>::const_iterator PlanetIt = MainSystem.PlanetList.begin();

            while (PlanetIt != MainSystem.PlanetList.end()) {
                // Header
                SaveFile.AddLine("<Planet>");

                // PlanetName
                TempOutputString = "PlanetName=";
                TempOutputString.Append((*PlanetIt).second->PName);
                SaveFile.AddLine(TempOutputString);

                // Colour
                TempOutputString = "Colour=";
                TempOutputString.Append((*PlanetIt).second->PlanetInfo.TrailColour.GetAsString());
                SaveFile.AddLine(TempOutputString);

                // Size
                TempOutputString = "Size=";
                NumString = wxString::Format("%d", (*PlanetIt).second->PlanetInfo.TermSize);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                // Initial X, Y, vX, vY
                TempOutputString = "X=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialX : (*PlanetIt).second->CurrentX);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                TempOutputString = "Y=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialY : (*PlanetIt).second->CurrentY);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                TempOutputString = "Z=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialZ : (*PlanetIt).second->CurrentZ);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                TempOutputString = "vX=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialvX : (*PlanetIt).second->CurrentvX);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                TempOutputString = "vY=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialvY : (*PlanetIt).second->CurrentvY);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                TempOutputString = "vZ=";
                NumString = wxString::Format("%.15e", (FileSaveType == SAVE_ORIGINAL) ? (*PlanetIt).second->InitialvZ : (*PlanetIt).second->CurrentvZ);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                // Mass
                TempOutputString = "Mass=";
                NumString = wxString::Format("%.15e", (*PlanetIt).second->Mass);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                // PlanetID
                TempOutputString = "ID=";
                NumString = wxString::Format("%d", (*PlanetIt).second->PlanetId);
                TempOutputString.Append(NumString);
                SaveFile.AddLine(TempOutputString);

                // Closer
                SaveFile.AddLine("</Planet>");
                PlanetIt++;
            }
        }

        SaveFile.AddLine("END OF FILE");

        SaveFile.Write();
    }

    return true;
}


void OrbFrame::OnOpenMenuItemSelected(wxCommandEvent& event)
{
    wxFileDialog* OpenFileDialog;
    // Access original application directory on first open
    if (FirstDialogOpened == false) {
        wxString SamplesDir = StdPaths.GetUserDataDir();
        SamplesDir.append("\\samples");
        OpenFileDialog = new wxFileDialog(this, "Choose a file", SamplesDir, wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
    } else {
        OpenFileDialog = new wxFileDialog(this, "Choose a file", wxGetCwd(), wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
    }

    if (OpenFileDialog->ShowModal() == wxID_OK) {
        FirstDialogOpened = true;
        OpenOrbFile(OpenFileDialog->GetPath());
    }
}

// Open .orb file with the given name
void OrbFrame::OpenOrbFile(wxString Filename)
{
    wxTextFile OpenedFile(Filename);
    if (!OpenedFile.Exists()) {
        wxMessageBox("File does not exist!", "Error: No file", wxOK | wxICON_EXCLAMATION);
        return;
    }

    OpenedFile.Open();

    /**
        Reset the system and all controls
    **/
    // Stop the Simulation
    if (RefreshTimer != NULL && RefreshTimer->IsRunning()) {
        RefreshTimer->Stop();
    }
    if (CalcTimer != NULL && CalcTimer->IsRunning()) {
        CalcTimer->Stop();
    }
    AutoZoomBool = true;

    // Clear System
    MainSystem.ResetSystem();

    // Clear controls
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        (*PlanetCtrlIt).ControlPlanet = NULL;
        PlanetCtrlIt++;
    }
    UpdatePlanetControls();

    // Update Coordinates
    MainSystem.UpdateCoordinates(&Coordinates);
    MaxXCoord = 0;
    MaxYCoord = 0;

    /**
        Load Global Parameters
    **/
    wxString CurrentInputString;
    wxString RestOfString;
    long TempGlobal;
    CurrentInputString = OpenedFile.GetFirstLine();
    FrameType Choice = COMORIGIN;
    double CustomX, CustomY, CustomZ;
    int CustomId = 0;
    bool Moving = false;
    double OriginvX, OriginvY, OriginvZ;
    bool Rotating = false;
    double AngularFreq = 0;

    while (CurrentInputString != "<System Settings>" && !OpenedFile.Eof()) {
        CurrentInputString = OpenedFile.GetNextLine();
    }

    while (CurrentInputString != "</System Settings>" && !OpenedFile.Eof()) {
        CurrentInputString = OpenedFile.GetNextLine();

        // COMFrame maintained for backward compatibility
        if (CurrentInputString.StartsWith("COMFrame=", &RestOfString)) {
            RestOfString.ToLong(&TempGlobal, 10);
            if (TempGlobal == 0) {
                Choice = ORIGINAL;
            } else {
                Choice = COMORIGIN;
            }
        } else if (CurrentInputString.StartsWith("ReferenceFrame=", &RestOfString)) {
            RestOfString.ToLong(&TempGlobal, 10);
            Choice = FrameType(TempGlobal);
        } else if (CurrentInputString.StartsWith("Speed=", &RestOfString)) {
            RestOfString.ToLong(&TempGlobal, 10);
            SpeedSlider->SetValue(TempGlobal);
            ChangeSpeed();
        } else if (CurrentInputString.StartsWith("Accuracy=", &RestOfString)) {
            RestOfString.ToLong(&TempGlobal, 10);
            AccuracySlider->SetValue(TempGlobal);
            ChangeAccuracy();
        } else if (CurrentInputString.StartsWith("TrailLength=", &RestOfString)) {
            RestOfString.ToLong(&TempGlobal, 10);
            TrailSlider->SetValue(TempGlobal);
            ChangeTrailLength();
        } else if (CurrentInputString.StartsWith("CustomX=", &RestOfString)) {
            RestOfString.ToDouble(&CustomX);
        } else if (CurrentInputString.StartsWith("CustomY=", &RestOfString)) {
            RestOfString.ToDouble(&CustomY);
        } else if (CurrentInputString.StartsWith("CustomZ=", &RestOfString)) {
            RestOfString.ToDouble(&CustomZ);
        } else if (CurrentInputString.StartsWith("CustomPlanetOriginId=", &RestOfString)) {
            CustomId = wxAtoi(RestOfString);
        } else if (CurrentInputString.StartsWith("TranslatingOrigin=", &RestOfString)) {
            Moving = wxAtoi(RestOfString);
        } else if (CurrentInputString.StartsWith("OriginvX=", &RestOfString)) {
            RestOfString.ToDouble(&OriginvX);
        } else if (CurrentInputString.StartsWith("OriginvY=", &RestOfString)) {
            RestOfString.ToDouble(&OriginvY);
        } else if (CurrentInputString.StartsWith("OriginvZ=", &RestOfString)) {
            RestOfString.ToDouble(&OriginvZ);
        } else if (CurrentInputString.StartsWith("Rotation=", &RestOfString)) {
            Rotating = wxAtoi(RestOfString);
        } else if (CurrentInputString.StartsWith("RotationFrequency=", &RestOfString)) {
            RestOfString.ToDouble(&AngularFreq);
        } else if (CurrentInputString.StartsWith("AutoZoom=", &RestOfString)) {
            AutoZoomBool = wxAtoi(RestOfString);
        } else if (CurrentInputString.StartsWith("ZoomFactor=", &RestOfString)) {
            RestOfString.ToDouble(&MaxXExtent);
            RestOfString.ToDouble(&MaxYExtent);
        }
    }

    if (Choice == ORIGINAL || Choice == COMORIGIN) {
        MainSystem.ChangeReferenceFrame(Choice);
    } else if (Choice == CUSTOMORIGIN) {
        MainSystem.ChangeReferenceFrame(CUSTOMORIGIN, CustomX, CustomY, CustomZ);
    } else if (Choice == PLANETORIGIN) {
        MainSystem.ChangeReferenceFrame(PLANETORIGIN, CustomId);
    }

    if (Moving) {
        MainSystem.ChangeOriginSpeed(true, OriginvX, OriginvY, OriginvZ);
    } else {
        MainSystem.ChangeOriginSpeed(false);
    }

    if (Rotating) {
        MainSystem.ChangeRotation(true, AngularFreq);
    } else {
        MainSystem.ChangeRotation(false);
    }

    if (!AutoZoomBool) {
        AutoZoomMenuItem->Check(false);
        CustomZoomMenuItem->Check(true);
    } else {
        AutoZoomMenuItem->Check(true);
        CustomZoomMenuItem->Check(false);
    }

    /**
        Load planet settings
    **/
    while (!OpenedFile.Eof()) {
        /*
            Each loop opens one planet
        */
        while (CurrentInputString != "<Planet>" && !OpenedFile.Eof()) {
            CurrentInputString = OpenedFile.GetNextLine();
        }

        if (OpenedFile.Eof()) break;
        // Default value for all
        wxString PlanetName = "NewPlanet";
        wxColour ColourTemp = *wxBLACK;
        wxColour* ColourSelected = &ColourTemp;
        long int TermSize = 0;
        double X = 200.0;
        double Y = 200.0;
        double Z = 0.0;
        double vX = 1.0;
        double vY = 1.0;
        double vZ = 0.0;
        double Mass = 200;
        int PlanetID = 0;

        while (CurrentInputString != "</Planet>" && !OpenedFile.Eof()) {
            CurrentInputString = OpenedFile.GetNextLine();

            if (CurrentInputString.StartsWith("X=", &RestOfString)) {
                RestOfString.ToDouble(&X);
            } else if (CurrentInputString.StartsWith("Y=", &RestOfString)) {
                RestOfString.ToDouble(&Y);
            } else if (CurrentInputString.StartsWith("Z=", &RestOfString)) {
                RestOfString.ToDouble(&Z);
            } else if (CurrentInputString.StartsWith("vX=", &RestOfString)) {
                RestOfString.ToDouble(&vX);
            } else if (CurrentInputString.StartsWith("vY=", &RestOfString)) {
                RestOfString.ToDouble(&vY);
            } else if (CurrentInputString.StartsWith("vZ=", &RestOfString)) {
                RestOfString.ToDouble(&vZ);
            } else if (CurrentInputString.StartsWith("Mass=", &RestOfString)) {
                RestOfString.ToDouble(&Mass);
            } else if (CurrentInputString.StartsWith("PlanetName=", &RestOfString)) {
                PlanetName = RestOfString;
            } else if (CurrentInputString.StartsWith("Colour=", &RestOfString)) {
                ColourSelected->Set(RestOfString);
            } else if (CurrentInputString.StartsWith("Size=", &RestOfString)) {
                RestOfString.ToLong(&TermSize);
            } else if (CurrentInputString.StartsWith("ID=", &RestOfString)) {
                PlanetID = wxAtoi(RestOfString);
            }
        }
        // Call Planet constructor
        Planet* NewPlanet;
        if (PlanetID == 0) {
            NewPlanet = MainSystem.CreateNewPlanet(X, Y, Z, vX, vY, vZ, Mass, (wxColour*)(ColourSelected), TermSize, PlanetName);
        } else {
            NewPlanet = MainSystem.CreateNewPlanet(X, Y, Z, vX, vY, vZ, Mass, (wxColour*)(ColourSelected), TermSize, PlanetName, PlanetID);
        }

        /*
            Update rest of System
        */
        // Update Coordinates
        MainSystem.UpdateCoordinates(&Coordinates);


        // New set of Planet Controls
        PlanetControls NewPlanetControl;
        NewPlanetControl.ControlPlanet = NewPlanet;
        NewPlanetControl.activated = false;
        PlanetCtrlList.push_back(NewPlanetControl);

        UpdatePlanetControls();
    }
    RefreshStatusBar();

    OpenedFile.Close();

    RefreshSimulation();
}


void OrbFrame::OnHelpMenuItemSelected(wxCommandEvent& event)
{
    helpController->LoadFile();
    helpController->DisplayContents();
}

void OrbFrame::OnBenchmarkMenuItemSelected(wxCommandEvent& event)
{
    RunBenchmark();
    RefreshSimulation();
}

void OrbFrame::RunBenchmark()
{
    BenchmarkDialog* dlg = new BenchmarkDialog(this);
    dlg->SetCurrentLength(BenchmarkLength);
    long returnvalue = dlg->ShowModal();

    if (returnvalue == wxID_OK) {
        wxString TextReturn = (dlg->LengthTextCtrl)->GetValue();
        BenchmarkLength = wxAtoi(TextReturn);
        int i, j;
        int MinLength = MainSystem.GetTrailLength();
        long Time0, RunTime[5];

        // Reset System
        PauseSystem();
        // Clear Coordinates
        MainSystem.ResetCoordinates();

        RefreshSimulation();

        // Start Timing
        wxStopWatch BenchmarkStopwatch;
        // Initial run
        for (j = 0; j <= MinLength; j++) {
            MainSystem.NextStep();
        }
        Time0 = BenchmarkStopwatch.Time();
        BenchmarkStopwatch.Pause();

        // Proper runs
        for (i = 0; i < 5; i++) {
            BenchmarkStopwatch.Start();
            for (j = 0; j < BenchmarkLength; j++) {
                MainSystem.NextStep();
            }

            RunTime[i] = BenchmarkStopwatch.Time();
            BenchmarkStopwatch.Pause();
        }

        wxMessageBox(wxString::Format("Number of Steps:       %d\n"
                                      "Number of Planets:     %d\n"
                                      "Initial Run Time (ms): %ld\n"
                                      "Run 1 (ms):            %ld\n"
                                      "Run 2 (ms):            %ld\n"
                                      "Run 3 (ms):            %ld\n"
                                      "Run 4 (ms):            %ld\n"
                                      "Run 5 (ms):            %ld\n"
                                      , BenchmarkLength, MainSystem.NumPlanets(), BenchmarkStopwatch.Time(),
                                      RunTime[0], RunTime[1], RunTime[2], RunTime[3], RunTime[4]));
    } else {
        // Do Nothing
    }

    delete dlg;
}


// Change Frame of Reference Button
void OrbFrame::OnButton8Click(wxCommandEvent& event)
{
    ChangeFrameDialog* dlg = new ChangeFrameDialog(this);

    // Populate with planets.
    // Declare iterator
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        dlg->PlanetChoice->Append((*PlanetCtrlIt).ControlPlanet->PName);

        PlanetCtrlIt++;
    }
    dlg->PlanetChoice->SetSelection(0);

    int PlanetSelection = 0;

    // Set current choice
    if (MainSystem.FrameChoice == COMORIGIN) {
        dlg->COMRadioButton->SetValue(true);
        dlg->TranslationCheckBox->Disable();
    } else if (MainSystem.FrameChoice == ORIGINAL) {
        dlg->OriginalRadioButton->SetValue(true);
    } else if (MainSystem.FrameChoice == PLANETORIGIN) {
        dlg->PlanetRadioButton->SetValue(true);
        dlg->TranslationCheckBox->Disable();

        // Find currently selected planet
        PlanetCtrlIt = PlanetCtrlList.begin();
        while (PlanetCtrlIt != PlanetCtrlList.end()) {
            PlanetSelection++;
            if ((*PlanetCtrlIt).ControlPlanet->PlanetId == MainSystem.CustomPlanetOriginId) {
                break;
            }
            PlanetCtrlIt++;
        }
        dlg->PlanetChoice->SetSelection(--PlanetSelection);

    } else if (MainSystem.FrameChoice == CUSTOMORIGIN) {
        dlg->CustomRadioButton->SetValue(true);
        dlg->XTextCtrl->SetValue(wxString::Format("%e", MainSystem.CustomX));
        dlg->YTextCtrl->SetValue(wxString::Format("%e", MainSystem.CustomY));
        dlg->ZTextCtrl->SetValue(wxString::Format("%e", MainSystem.CustomZ));
    }

    // Set translating speed
    if (MainSystem.FrameChoice == ORIGINAL || MainSystem.FrameChoice == CUSTOMORIGIN) {
        if (MainSystem.TranslatingOrigin) {
            dlg->TranslationCheckBox->SetValue(true);
            dlg->vXTextCtrl->Enable();
            dlg->vYTextCtrl->Enable();
            dlg->vZTextCtrl->Enable();

            dlg->vXTextCtrl->SetValue(wxString::Format("%e", MainSystem.OriginvX));
            dlg->vYTextCtrl->SetValue(wxString::Format("%e", MainSystem.OriginvY));
            dlg->vZTextCtrl->SetValue(wxString::Format("%e", MainSystem.OriginvZ));
        } else {
            // Do nothing
        }
    }

    // Set rotation
    if (MainSystem.Rotation) {
        dlg->RotationCheckBox->SetValue(true);
        dlg->PeriodRadioButton->Enable();
        dlg->FreqRadioButton->Enable();
        dlg->PeriodTextCtrl->Enable();

        double TempValue = ((MainSystem.RotationFrequency == 0) ? 2*PI*86400 : MainSystem.RotationFrequency);

        dlg->PeriodTextCtrl->SetValue(wxString::Format("%e", (2*PI/TempValue)/86400));
        dlg->FreqTextCtrl->SetValue(wxString::Format("%e", MainSystem.RotationFrequency));
    }

    long returnvalue = dlg->ShowModal();

    wxString TextCtrlInput;

    if (returnvalue == wxID_OK) {
        if (dlg->COMRadioButton->GetValue()) {
            MainSystem.ChangeReferenceFrame(COMORIGIN);
        } else if (dlg->OriginalRadioButton->GetValue()) {
            MainSystem.ChangeReferenceFrame(ORIGINAL);
        } else if (dlg->PlanetRadioButton->GetValue()) {
            // Get ID of currently selected planet.
            PlanetCtrlIt = PlanetCtrlList.begin();
            int selected = dlg->PlanetChoice->GetSelection();
            PlanetCtrlIt += selected;

            MainSystem.ChangeReferenceFrame(PLANETORIGIN, (*PlanetCtrlIt).ControlPlanet->PlanetId);
        } else if (dlg->CustomRadioButton->GetValue()) {
            double x = 0;
            double y = 0;
            double z = 0;

            TextCtrlInput = dlg->XTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&x);
            TextCtrlInput = dlg->YTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&y);
            TextCtrlInput = dlg->ZTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&z);

            MainSystem.ChangeReferenceFrame(CUSTOMORIGIN, x, y, z);
        }

        if (MainSystem.FrameChoice == COMORIGIN || MainSystem.FrameChoice == PLANETORIGIN || !(dlg->TranslationCheckBox->GetValue())) {
            MainSystem.ChangeOriginSpeed(false);
        } else {
            double vX = 0;
            double vY = 0;
            double vZ = 0;

            TextCtrlInput = dlg->vXTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&vX);
            TextCtrlInput = dlg->vYTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&vY);
            TextCtrlInput = dlg->vZTextCtrl->GetValue();
            TextCtrlInput.ToDouble(&vZ);

            MainSystem.ChangeOriginSpeed(true, vX, vY, vZ);
        }

        if (dlg->RotationCheckBox->GetValue()) {
            double AngularFreq = 0;
            if (dlg->PeriodRadioButton->GetValue()) {
                double i;
                TextCtrlInput = dlg->PeriodTextCtrl->GetValue();
                TextCtrlInput.ToDouble(&i);
                AngularFreq = 2*PI/(i*86400);
            } else if (dlg->FreqRadioButton->GetValue()) {
                TextCtrlInput = dlg->FreqTextCtrl->GetValue();
                TextCtrlInput.ToDouble(&AngularFreq);
            }
            MainSystem.ChangeRotation(true, AngularFreq);
        } else {
            MainSystem.ChangeRotation(false);
        }

    } else {
        // Do Nothing
    }

    delete dlg;
}

void OrbFrame::OnInvertColourCheckBoxClick(wxCommandEvent& event)
{
    SimGraph->InvertColours();
    RefreshSimulation();
}

void OrbFrame::OnNextStepMenuItemSelected(wxCommandEvent& event)
{
    // Do nothing if no planets
    if (MainSystem.IsEmpty()) return;

    SimGraph->SetNewPointNum(1);

    MainSystem.NextStep();

    RefreshSimulation();
}

void OrbFrame::OnPartialRefreshMenuItemSelected(wxCommandEvent& event)
{
    if (PartialRefreshMenuItem->IsChecked()) {
        FullRefreshBool = false;
    } else {
        FullRefreshBool = true;
    }
}

// View Info Button
void OrbFrame::OnButton9Click(wxCommandEvent& event)
{
    // Declare iterator
    std::vector<PlanetControls>::iterator PlanetCtrlIt = PlanetCtrlList.begin();

    // Handle position of new dialogs
    // Begin by finding centre of screen
    int width, height;
    wxDisplaySize(&width, &height);
    // Count no. of dialogs produced
    int i = 0;

    while (PlanetCtrlIt != PlanetCtrlList.end()) {
        if ((*PlanetCtrlIt).CheckBox->IsChecked()) {
            /*
                Create dialog to show info
            */
            ViewInfoDialog* dlg = new ViewInfoDialog(this, wxID_ANY, wxPoint(width/4 + i*30, height/4 + i*30));
            dlg->SetPlanet((*PlanetCtrlIt).ControlPlanet);
            dlg->Show();
            InfoDialogs.push_back(dlg);
            i++;
        }
        PlanetCtrlIt++;
    }
}

void OrbFrame::OnSaveCurrentMenuItemSelected(wxCommandEvent& event)
{
    wxFileDialog* SaveFileDialog;
    // Access original application directory on first open
    if (FirstDialogOpened == false) {
        wxString SamplesDir = StdPaths.GetUserDataDir();
        SamplesDir.append("\\samples");
        SaveFileDialog = new wxFileDialog(this, "Choose a file", SamplesDir, wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_SAVE | wxFD_OVERWRITE_PROMPT | wxFD_CHANGE_DIR);
        FirstDialogOpened= true;
    } else {
        SaveFileDialog = new wxFileDialog(this, "Choose a file", wxGetCwd(), wxEmptyString, "Orb Files (*.orb) | *.orb", wxFD_SAVE | wxFD_OVERWRITE_PROMPT | wxFD_CHANGE_DIR);
    }

    CalcTimer->Stop();
    if (SaveFileDialog->ShowModal() == wxID_OK) {
        SaveOrbFile(SaveFileDialog->GetPath(), SAVE_CURRENT);
    }
    CalcTimer->Start(CalcTimerInterval, false);
}

// Import planets from NASA Horizons Ephemerides Interface
void OrbFrame::OnImportPlanetMenuItemClick(wxCommandEvent& event)
{
    PauseSystem();

    // Create dialog to ask for parameters
    ImportPlanetDialog dlg(this);
    dlg.SetColourData(CustomColourData);
    long returnvalue = dlg.ShowModal();

    // Create new planet if OK is clicked.
    if (returnvalue == wxID_OK) {
        // Get Input Data
        wxString PlanetName;
        PlanetName = dlg.NameTextCtrl->GetValue();

        double x, y, z, vX, vY, vZ, mass;
        x = dlg.x * METRE_PER_AU;
        y = dlg.y * METRE_PER_AU;
        z = dlg.z * METRE_PER_AU;
        vX = dlg.vX * MPS_PER_AUDAY;
        vY = dlg.vY * MPS_PER_AUDAY;
        vZ = dlg.vZ * MPS_PER_AUDAY;
        mass = dlg.mass * pow(10, 20);

        // Get Colour
        int ColourSelection = dlg.ColourChoice->GetSelection();
        const wxColour* ColourSelected;
        switch (ColourSelection) {
            case 0:
                ColourSelected = wxBLACK;
                break;
            case 1:
                ColourSelected = wxRED;
                break;
            case 2:
                ColourSelected = wxBLUE;
                break;
            case 3:
                ColourSelected = wxGREEN;
                break;
            case 4:
                ColourSelected = &(dlg.ColourDlgData->GetColour());
                break;
            default:
                ColourSelected = wxBLACK;
                break;
        }

        // Get Custom Colour Data
        CustomColourData = dlg.ColourDlgData;

        // Get Terminator Size
        int TerminatorSize = dlg.SizeChoice->GetSelection();

        // Call Planet Constructor
        Planet* NewPlanet = MainSystem.CreateNewPlanet(x, y, z, vX, vY, vZ, mass, const_cast<wxColour*>(ColourSelected), TerminatorSize, PlanetName);

        // Update Coordinates
        MainSystem.UpdateCoordinates(&Coordinates);
        MainSystem.GetMaxElements(&MaxXCoord, &MaxYCoord);

        // New set of Planet Controls
        NewPlanetControl(NewPlanet);

        RefreshSimulation();
    } else {
        // Do nothing
    }
}

void OrbFrame::OnTimeMenuItemSelected(wxCommandEvent& event)
{
    wxStopWatch RefreshStopwatch;
    PauseSystem();
    RefreshStopwatch.Start();
    int i;
    for (i = 1; i < 1000; i++) {
        SimGraph->Refresh();
    }
    RefreshStopwatch.Pause();
    long TimeTaken = RefreshStopwatch.Time();
    wxMessageBox(wxString::Format("Number of Planets:           %d\n"
                                  "Trail Length:                %d\n"
                                  "Number of Refreshes:         %d\n"
                                  "Time Taken:                  %ld\n",
                                  MainSystem.NumPlanets(), MainSystem.GetTrailLength(),1000,TimeTaken));
}

void OrbFrame::OnAddPlanetMenuItemSelected(wxCommandEvent& event)
{
    AddPlanet();
}

void OrbFrame::OnClearTrailsMenuItemSelected(wxCommandEvent& event)
{
    if (!FullRefreshBool) {
        SimGraph->Refresh();
    }
}

void OrbFrame::OnAutoZoomMenuItemSelected(wxCommandEvent& event)
{
    AutoZoomBool = true;
    AutoZoomMenuItem->Check(true);
    CustomZoomMenuItem->Check(false);

    RefreshSimulation();
}

void OrbFrame::OnCustomZoomMenuItemSelected(wxCommandEvent& event)
{
    ZoomDialog* dlg = new ZoomDialog(this);

    double ScaleInAU = SimGraph->GetXExtent() / METRE_PER_AU;
    (dlg->ZoomTextCtrl)->SetValue(wxString::Format("%.6f", ScaleInAU));

    long returnvalue = dlg->ShowModal();



    if (returnvalue == wxID_OK) {
        AutoZoomBool = false;
        AutoZoomMenuItem->Check(false);
        CustomZoomMenuItem->Check(true);

        wxString TextCtrlInput = (dlg->ZoomTextCtrl)->GetValue();
        double TempValue;
        TextCtrlInput.ToDouble(&TempValue);
        MaxXExtent = TempValue * METRE_PER_AU;
        MaxYExtent = TempValue * METRE_PER_AU;
        RefreshSimulation(true);
    } else {
        CustomZoomMenuItem->Check(!AutoZoomBool);
        AutoZoomMenuItem->Check(AutoZoomBool);
    }
}

void OrbFrame::OnZoomInMenuItemSelected(wxCommandEvent& event)
{
    if (AutoZoomBool) {
        AutoZoomBool = false;
        AutoZoomMenuItem->Check(false);
        CustomZoomMenuItem->Check(true);
    }
    MaxXExtent = MaxXExtent * 0.5;
    MaxYExtent = MaxYExtent * 0.5;

    RefreshSimulation();
}

void OrbFrame::OnZoomOutMenuItemSelected(wxCommandEvent& event)
{
    if (AutoZoomBool) {
        AutoZoomBool = false;
        AutoZoomMenuItem->Check(false);
        CustomZoomMenuItem->Check(true);
    }
    MaxXExtent = MaxXExtent * 2;
    MaxYExtent = MaxYExtent * 2;

    RefreshSimulation();
}
