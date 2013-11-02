/*
 * MainApp.h
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */

#ifndef MAINAPP_H_
#define MAINAPP_H_

#include "wx/wx.h"

class MainApp : public wxApp
{
public:
	MainApp();
	virtual bool OnInit();
private:
	wxDECLARE_NO_COPY_CLASS(MainApp);
};

#endif /* MAINAPP_H_ */
