#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_HEIGHT 420
#define MAINFRAME_WIDTH 840
#define AMPL 2.0
#define FREQ 220.0
#define PSI 0.25

#include "wx/frame.h"
#include "wx/textdlg.h"
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/frame.h>
#include "wx/aboutdlg.h"
#include <wx/wxprec.h>
#include <wx/image.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/intl.h>
#include <wx/print.h>
#include <wx/filename.h>

#include "signal.h"
#include <thread>

namespace DigitalFilter {
    class MainFrame : public wxFrame {
    private:
        std::atomic_bool stopFigureDrawing = false;
        Calc::Signal* originalATSignalData;
        Calc::Signal* filteredATSignalData;
        Calc::Signal* originalMFSignalData;
        Calc::Signal* filteredMFSignalData;


        int axesPos[2];
        bool ticks;
        wxDECLARE_EVENT_TABLE();
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        wxRadioButton* m_radioBtn_IIR;
        wxRadioButton* m_radioBtn_FIR;
        wxRadioButton* m_radioBtn_Firstorder;
        wxRadioButton* m_radioBtn_Secondorder;
        wxRadioButton* m_radioBtn_Lowpass;
        wxRadioButton* m_radioBtn_Highpass;
        wxRadioButton* m_radioBtn_Bandpass;
        wxRadioButton* m_radioBtn_Bandstop;
        wxStaticText* m_staticText_Samplefreq;
        wxTextCtrl* m_textCtrl_Samplefreq;
        wxStaticText* m_staticText_Passfreq;
        wxTextCtrl* m_textCtrl_Passfreq;
        wxStaticText* m_staticText_Stopfreq;
        wxTextCtrl* m_textCtrl_Stopfreq;
        wxButton* m_button_Start;
        mpWindow* m_Fig1;
        mpWindow* m_Fig2;

    public:
        MainFrame();
        virtual ~MainFrame();

        // Commands
        void Quit(wxCommandEvent& event);
        void Start(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void LoadingOriginalSignal();
    };
}