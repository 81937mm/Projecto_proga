#pragma once
#include <wx/wx.h>

class Interfaz : public wxFrame
{
public:
	Interfaz(const wxString& title);
	~Interfaz();
	void OnButtonClicked(wxCommandEvent& evt);
	void OnMouseEvent(wxMouseEvent& evt);
	wxDECLARE_EVENT_TABLE();

	wxButton** btn;
	int nFieldWidth = 10;
	int nFieldHight = 10;
	int* treasure = nullptr;
	bool firstclick = true;

private:
	wxToolBar* toolbar = nullptr;
	wxMenuBar* menubar = nullptr;
};
