/*
 * MainApp.cpp
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */

#include "MainApp.h"
#include "MainFrame.h"

IMPLEMENT_APP(MainApp)

MainApp::MainApp()
{
	// TODO Auto-generated constructor stub

}

bool MainApp::OnInit()
{
	if(!wxApp::OnInit())
	{
		return false;
	}

	MainFrame* frame = new MainFrame(wxT("wxRenamer Ver : 0.1"));

	frame->Show(true);

	return true;
}



