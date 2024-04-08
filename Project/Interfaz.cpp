#include "Interfaz.h"
#include <wx/wx.h>
#include <wx/sizer.h>

enum button_IDs {
	button1_ID = 2,
	button2_ID = 3,
	button3_ID = 4,
	button4_ID = 5
};

enum panel_IDs {
	panel1_ID = 2,
	panel2_ID = 3,
	panel3_ID = 4,
	panel4_ID = 5
};


wxBEGIN_EVENT_TABLE(Interfaz, wxFrame)
	EVT_BUTTON(button1_ID, Interfaz::OnButtonClicked)
	EVT_BUTTON(button2_ID, Interfaz::OnButtonClicked)
	EVT_BUTTON(button3_ID, Interfaz::OnButtonClicked)
	EVT_BUTTON(button4_ID, Interfaz::OnButtonClicked)
wxEND_EVENT_TABLE();


Interfaz::Interfaz(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//Row 1
	wxPanel* panel1 = new wxPanel(this, panel1_ID, wxDefaultPosition, wxSize(450, 300));
	panel1->SetBackgroundColour(wxColor(255, 0, 0));
	wxButton* button1 = new wxButton(panel1, button1_ID, "Red", wxPoint(150,100), wxSize(100, 100), wxBORDER_NONE);
	button1->SetBackgroundColour(wxColor(255,0,0));
	button1->SetForegroundColour(wxColor(255, 255, 255));

	wxPanel* panel2 = new wxPanel(this, panel2_ID, wxDefaultPosition, wxSize(450, 300));
	panel2->SetBackgroundColour(wxColor(0, 0, 0));
	wxButton* button2 = new wxButton(panel2, button2_ID, "Green", wxPoint(160, 100), wxSize(100, 100), wxBORDER_NONE);
	button2->SetBackgroundColour(wxColor(0, 0, 0));
	button2->SetForegroundColour(wxColor(255, 255, 255));


	wxSizer* sizerTop = new wxBoxSizer(wxHORIZONTAL);
	sizerTop->Add(panel1, 1, wxBOTTOM | wxRIGHT, 3);
	sizerTop->Add(panel2, 1, wxBOTTOM | wxLEFT, 3);



	//Row 2
	wxPanel* panel3 = new wxPanel(this, panel3_ID, wxDefaultPosition, wxSize(450, 300));
	panel3->SetBackgroundColour(wxColor(0, 0, 0));
	wxButton* button3 = new wxButton(panel3, button3_ID, "Blue", wxPoint(160, 100), wxSize(100, 100), wxBORDER_NONE);
	button3->SetBackgroundColour(wxColor(0, 0, 0));
	button3->SetForegroundColour(wxColor(255, 255, 255));

	wxPanel* panel4 = new wxPanel(this, panel4_ID, wxDefaultPosition, wxSize(450, 300));
	panel4->SetBackgroundColour(wxColor(0, 0, 0)); //(100,0,100)
	wxButton* button4 = new wxButton(panel4, button4_ID, "Purple", wxPoint(160, 100), wxSize(100, 100), wxBORDER_NONE);
	button4->SetBackgroundColour(wxColor(0, 0, 0));
	button4->SetForegroundColour(wxColor(255, 255, 255));

	wxBoxSizer* sizermiddle = new wxBoxSizer(wxHORIZONTAL);
	sizermiddle->Add(panel3, 1, wxTOP | wxRIGHT, 3);
	sizermiddle->Add(panel4, 1, wxTOP | wxLEFT, 3);

	wxBoxSizer* sizerALL = new wxBoxSizer(wxVERTICAL);
	sizerALL->Add(sizerTop);
	sizerALL->Add(sizermiddle);

	this->SetSizerAndFit(sizerALL);

}

/*
void Interfaz::OnButtonClicked(wxCommandEvent& evt) { //panel1

	wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 300));
	panel1->SetBackgroundColour(wxColor(255, 0, 0));
	panel1->Refresh();
	panel1->Update();

}
*/

void Interfaz::OnButtonClicked(wxCommandEvent& evt) { //panel2
	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 300));
	panel2->SetBackgroundColour(wxColor(0, 255, 0));
	panel2->Refresh();
	panel2->Update();

}




