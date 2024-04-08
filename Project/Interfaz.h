#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>

class Interfaz : public wxFrame
{
public:
	Interfaz(const wxString& title);
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

private:

};
