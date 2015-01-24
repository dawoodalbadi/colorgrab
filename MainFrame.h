#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wxcrafter.h"

class MainFrame : public MainFrameBaseClass
{
private:
    int magnification;
    bool dragPicker;
	 bool capturing;
    wxString format;
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	 
    wxColour GetColor() const;
	 void SetColor(const wxColor& color, bool updateInputs = true);
	 void SetColorFromMouse();
	 void SetColorFromPixel(wxCoord x, wxCoord y);
	 void UpdateZoomArea();
protected:
    virtual void OnCaptureZoom(wxMouseEvent& event);
    virtual void OnDumpGrabEnd(wxMouseEvent& event);
    virtual void OnDumpGrabMove(wxMouseEvent& event);
    virtual void OnDumpGrabStart(wxMouseEvent& event);
    virtual void OnFormatChoose(wxMenuEvent& event);
    virtual void OnFormatClick(wxCommandEvent& event);
    virtual void OnSettingDrag(wxCommandEvent& event);
    virtual void OnSystemColorPicker(wxCommandEvent& event);
    virtual void OnCaptureMove(wxMouseEvent& event);
    virtual void OnCaptureEnd(wxMouseEvent& event);
    virtual void OnCaptureStart(wxMouseEvent& event);
    virtual void OnLeftDown(wxMouseEvent& event);
    virtual void OnColorPick(wxColourPickerEvent& event);
    virtual void OnColorChange(wxCommandEvent& event);
    virtual void OnGrabClick(wxCommandEvent& event);
    virtual void OnZoomSelect(wxCommandEvent& event);
};
#endif // MAINFRAME_H
