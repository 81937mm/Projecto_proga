#include "Interfaz.h"
#include <wx/wx.h>

wxBEGIN_EVENT_TABLE(Interfaz, wxFrame)
wxEND_EVENT_TABLE();
	

Interfaz::Interfaz(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	
	btn = new wxButton * [nFieldWidth * nFieldHight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHight, 0, 0);
	treasure = new int[nFieldWidth * nFieldHight];
	
	for (int x = 0; x < nFieldWidth; x++) {
	
		for (int y = 0; y < nFieldHight; y++) {

			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Interfaz::OnButtonClicked, this);
			treasure[y * nFieldWidth + x] = 0;

		}
		
	}
	
	this->SetSizer(grid);
	grid->Layout();
	wxStatusBar* statusbar = CreateStatusBar();

	menubar = new wxMenuBar();
	this->SetMenuBar(menubar);

	wxMenu* menufile = new wxMenu();
}

void Interfaz::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;

	if (firstclick)
	{
		int bounty = 1;

		while (bounty)
		{
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHight;

			if (treasure[ry * nFieldWidth + rx] == 0 && rx != x && ry != y)
			{
				treasure[ry * nFieldWidth + rx] = -1;
				bounty--;
				if (bounty == 0)
				{
					evt.Skip();
				}
			}
			else
			{
				if (btn[y * nFieldWidth + x] == 0)
				{
					treasure[ry * nFieldWidth + rx] = -1;
					bounty--;
					if (bounty == 0)
					{
						evt.Skip();
					}
				}
			}
		}

		firstclick = false;
	}

	btn[y * nFieldWidth + x]->Enable(false);

	if (treasure[y * nFieldWidth + x] == -1)
	{
		wxMessageBox("YOU WIN!!!");

		firstclick = true;
		for (int x = 0; x < nFieldWidth; x++) {
			for (int y = 0; y < nFieldHight; y++)
			{
				treasure[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
		}
	}
	evt.Skip();
}


Interfaz::~Interfaz()
{
	delete[]btn;
}


