#include "App.h"
#include "Interfaz.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	Interfaz* interfaz = new Interfaz("Treasure Hunt");
	interfaz->SetClientSize(900,600);
	interfaz->Center();
	interfaz->Show(true);
	return true;
}
