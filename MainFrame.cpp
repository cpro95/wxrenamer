/*
 * MainFrame.cpp
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */

#include "MainFrame.h"
#include <algorithm>

#include "sample.xpm"

int wxCALLBACK
MyCompareFunction(wxIntPtr item1, wxIntPtr item2, wxIntPtr WXUNUSED(sortData))
{
	// inverse the order
	if (item1 < item2)
		return 1;
	if (item1 > item2)
		return -1;

	return 0;
}
/*
const long MainFrame::ID_BUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON2 = wxNewId();
const long MainFrame::ID_BUTTON3 = wxNewId();
const long MainFrame::ID_BUTTON4 = wxNewId();
const long MainFrame::ID_BUTTON5 = wxNewId();
const long MainFrame::ID_BUTTON6 = wxNewId();
*/
// Main frame constructor
MainFrame::MainFrame(const wxChar *title) :
		wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
	m_listCtrlLeft = NULL;
	m_listCtrlRight = NULL;
	m_logWindow = NULL;

	// Give it an icon
	SetIcon(wxICON(sample));

	// Make a menubar
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(LIST_OPEN, wxT("&Open\tCtrl-O"));
	menuFile->Append(LIST_ABOUT, wxT("&About"));
	menuFile->AppendSeparator();
	menuFile->Append(LIST_QUIT, wxT("E&xit\tAlt-X"));

	wxMenu *menuEdit = new wxMenu;

	menuEdit->Append(LIST_SORT, wxT("&Sort the item list\tCtrl-S"));
	menuEdit->Append(LIST_EDIT, wxT("&Edit the item\tCtrl-E"));
	menuEdit->Append(LIST_DELETE, wxT("&Delete item\tCtrl-D"));
	menuEdit->Append(LIST_UP, wxT("Up item"));
	menuEdit->Append(LIST_DOWN, wxT("Down item"));

	wxMenu *menuRename = new wxMenu;
	menuRename->Append(LIST_RENAME, wxT("&Rename it base on Mov\tCtrl-R"));
	menuRename->Append(LIST_RENAMESMI, wxT("&Rename base on Smi\tCtrl-M"));

	wxMenuBar *menubar = new wxMenuBar;
	menubar->Append(menuFile, wxT("&File"));
	menubar->Append(menuEdit, wxT("&Edit"));
	menubar->Append(menuRename, wxT("&Rename"));
	SetMenuBar(menubar);

#if wxUSE_STATUSBAR
	CreateStatusBar();
#endif // wxUSE_STATUSBAR

	wxButton* m_buttonUpRight;
	wxButton* m_buttonRenameWithSmi;
	wxBoxSizer* vbox2;
	wxBoxSizer* vbox;
	wxButton* m_buttonRenameWithMov;
	wxBoxSizer* hbox1;
	wxButton* m_buttonDownRight;
	wxButton* m_buttonDownLeft;
	wxButton* m_buttonUpLeft;
	wxBoxSizer* hbox2;
	wxBoxSizer* hbox4;
	wxBoxSizer* hbox3;
	wxBoxSizer* vbox1;

	//Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1024, 768));
	m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0,
			_T("wxID_ANY"));
	vbox = new wxBoxSizer(wxVERTICAL);
	hbox1 = new wxBoxSizer(wxHORIZONTAL);
	vbox1 = new wxBoxSizer(wxVERTICAL);
	hbox3 = new wxBoxSizer(wxHORIZONTAL);
	m_buttonUpLeft = new wxButton(m_panel, ID_BUTTON3, _("Up"),
			wxDefaultPosition, wxSize(44, 22), 0, wxDefaultValidator,
			_T("ID_BUTTON3"));
	hbox3->Add(m_buttonUpLeft, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	m_buttonDownLeft = new wxButton(m_panel, ID_BUTTON4, _("Down"),
			wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator,
			_T("ID_BUTTON4"));
	hbox3->Add(m_buttonDownLeft, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	hbox3->Add(-1, -1, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	m_buttonRenameWithMov = new wxButton(m_panel, ID_BUTTON1,
			_("Rename it with Mov!"), wxDefaultPosition, wxDefaultSize, 0,
			wxDefaultValidator, _T("ID_BUTTON1"));
	m_buttonRenameWithMov->SetMinSize(wxSize(-1, -1));
	m_buttonRenameWithMov->SetMaxSize(wxSize(-1, -1));
	hbox3->Add(m_buttonRenameWithMov, 0,
			wxALL | wxEXPAND | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
	vbox1->Add(hbox3, 0,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	m_listCtrlLeft = new wxListCtrl(m_panel, LIST_CTRL_LEFT, wxDefaultPosition,
			wxDefaultSize, wxLC_LIST | wxLC_EDIT_LABELS | wxSUNKEN_BORDER,
			wxDefaultValidator, _T("LIST_CTRL_LEFT"));
	vbox1->Add(m_listCtrlLeft, 1,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	hbox1->Add(vbox1, 1,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	vbox2 = new wxBoxSizer(wxVERTICAL);
	hbox4 = new wxBoxSizer(wxHORIZONTAL);
	m_buttonUpRight = new wxButton(m_panel, ID_BUTTON5, _("Up"),
			wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator,
			_T("ID_BUTTON5"));
	hbox4->Add(m_buttonUpRight, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	m_buttonDownRight = new wxButton(m_panel, ID_BUTTON6, _("Down"),
			wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator,
			_T("ID_BUTTON6"));
	hbox4->Add(m_buttonDownRight, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	hbox4->Add(0, 0, 1,
			wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	m_buttonRenameWithSmi = new wxButton(m_panel, ID_BUTTON2,
			_("Rename it with Smi!"), wxDefaultPosition, wxDefaultSize, 0,
			wxDefaultValidator, _T("ID_BUTTON2"));
	m_buttonRenameWithSmi->SetMaxSize(wxSize(-1, -1));
	hbox4->Add(m_buttonRenameWithSmi, 0,
			wxALL | wxEXPAND | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
	vbox2->Add(hbox4, 0,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	m_listCtrlRight = new wxListCtrl(m_panel, LIST_CTRL_RIGHT,
			wxDefaultPosition, wxDefaultSize,
			wxLC_LIST | wxLC_EDIT_LABELS | wxSUNKEN_BORDER, wxDefaultValidator,
			_T("LIST_CTRL_RIGHT"));
	vbox2->Add(m_listCtrlRight, 1,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	hbox1->Add(vbox2, 1,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	vbox->Add(hbox1, 1,
			wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL
					| wxALIGN_CENTER_VERTICAL, 5);
	hbox2 = new wxBoxSizer(wxHORIZONTAL);
	m_logWindow = new wxTextCtrl(m_panel, wxID_ANY, _("LogWindow\n"),
			wxDefaultPosition, wxDefaultSize,
			wxTE_MULTILINE | wxTE_READONLY | wxSUNKEN_BORDER,
			wxDefaultValidator, _T("wxID_ANY"));
	hbox2->Add(m_logWindow, 1,
			wxALL | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL, 5);
	vbox->Add(hbox2, 0,
			wxALL | wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL, 5);
	m_panel->SetSizer(vbox);
	vbox->Fit(m_panel);
	vbox->SetSizeHints(m_panel);

	m_logOld = wxLog::SetActiveTarget(new wxLogTextCtrl(m_logWindow));
	// showing ListCtrl

	m_myMovSmiData = new MovSmiData;

	m_myMovSmiData->loadFiles(".");

	RecreateList(wxLC_LIST);

	Connect(LIST_CTRL_LEFT, wxEVT_LIST_ITEM_SELECTED,
	wxListEventHandler(MainFrame::OnLeftSelected));
	Connect(LIST_CTRL_LEFT, wxEVT_LIST_ITEM_FOCUSED,
	wxListEventHandler(MainFrame::OnLeftFocused));
	Connect(LIST_CTRL_RIGHT, wxEVT_LIST_ITEM_SELECTED,
	wxListEventHandler(MainFrame::OnRightSelected));
	Connect(LIST_CTRL_RIGHT, wxEVT_LIST_ITEM_FOCUSED,
	wxListEventHandler(MainFrame::OnRightFocused));

	// connect menu event
	Connect(LIST_OPEN, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnOpen));
	Connect(LIST_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnAbout));
	Connect(LIST_QUIT, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnQuit));
	Connect(LIST_EDIT, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnEdit));
	Connect(LIST_DELETE, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnDelete));

	Connect(LIST_UP, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnItemUp));
	Connect(LIST_DOWN, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnItemDown));

	Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OnButtonItemUpLeft));
	Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OnButtonItemUpRight));

	Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OnButtonItemDownLeft));
	Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OnButtonItemDownRight));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnRename));
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnRenameSmi));

	Connect(LIST_SORT, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnItemSort));

	Connect(LIST_RENAME, wxEVT_COMMAND_MENU_SELECTED,
	wxCommandEventHandler(MainFrame::OnRename));
	Connect(LIST_RENAMESMI, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnRenameSmi));

#ifdef __WXMSW__
	// this is useful to know specially when debugging :)
	wxLogMessage("Your version of comctl32.dll is: %d",
			wxApp::GetComCtl32Version());
#endif

}

MainFrame::~MainFrame()
{
	delete wxLog::SetActiveTarget(m_logOld);
}

void MainFrame::OnSize(wxSizeEvent& event)
{
	DoSize();

	event.Skip();
}

void MainFrame::DoSize()
{

	if (!m_logWindow)
		return;

	wxSize size = GetClientSize();
	wxCoord y = (2 * size.y) / 10;
	m_listCtrlLeft->SetSize(0, 0, (int) size.x / 2, y);
	m_listCtrlRight->SetSize((int) size.x / 2 + 1, 0, size.x, y);
	m_logWindow->SetSize(0, y + 1, size.x, size.y);

}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageDialog dialog(this,
			wxT("wxRenamer\nwxWidget version of Rename which changes subtitle names with movie names\nby cpro95@gmail.com"),
			wxT("About wxRenamer"));

	dialog.ShowModal();
}

void MainFrame::OnEdit(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnEdit Mode"));

	// demonstrate cancelling editing: this currently is wxMSW-only
#if defined(__WXMSW__) && !defined(__WXUNIVERSAL__)
	if (m_listCtrlLeft->GetEditControl())
	{
		m_listCtrlLeft->EndEditLabel(true);

		wxLogMessage(wxT(" Left EndEitLabel(true) \n"));
	}
	if (m_listCtrlRight->GetEditControl())
	{

		m_listCtrlRight->EndEditLabel(true);
		wxLogMessage(wxT(" Right EndEitLabel(true) \n"));
	}
	else // start editing
#endif // __WXMSW__
	{
		if (m_listCtrlLeft->HasFocus())
		{
			long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
			wxLIST_STATE_FOCUSED);

			if (itemCur != -1)
			{
				m_listCtrlLeft->EditLabel(itemCur);
			}
			else
			{
				m_logWindow->WriteText(wxT("No item to edit\n"));
			}
		}
		else if (m_listCtrlRight->HasFocus())
		{
			long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
			wxLIST_STATE_FOCUSED);
			if (itemCur2 != -1)
			{
				m_listCtrlRight->EditLabel(itemCur2);
			}
			else
			{
				m_logWindow->WriteText(wxT("No item to edit\n"));
			}
		}

	}
}

void MainFrame::OnDelete(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnDelete Mode"));
	if (m_listCtrlLeft->HasFocus())
	{
		long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);

		if (itemCur != -1)
		{
			m_listCtrlLeft->DeleteItem(itemCur);
			m_myMovSmiData->delMovItem(itemCur);

			for (int i = 0; i < m_myMovSmiData->getSizeOfVectorMov(); i++)
				m_logWindow->WriteText(
						wxString::Format(wxT("%s\n"),
								m_myMovSmiData->mvMovFiles[i]));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to delete\n"));
		}
	}
	else if (m_listCtrlRight->HasFocus())
	{
		long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);
		if (itemCur2 != -1)
		{
			m_listCtrlRight->DeleteItem(itemCur2);
			m_myMovSmiData->delSmiItem(itemCur2);

			for (int i = 0; i < m_myMovSmiData->getSizeOfVectorSmi(); i++)
				m_logWindow->WriteText(
						wxString::Format(wxT("%s\n"),
								m_myMovSmiData->mvSmiFiles[i]));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to delete\n"));
		}
	}

}

void MainFrame::OnLeftSelected(wxListEvent& event)
{
	LogEvent(event, wxT("Left OnSelected"));
	wxLogMessage(wxT("Left List Ctrl"));
}

void MainFrame::OnRightSelected(wxListEvent& event)
{
	LogEvent(event, wxT("Right OnSelected"));
	wxLogMessage(wxT("Right List Ctrl"));
}

void MainFrame::OnLeftFocused(wxListEvent& event)
{
	LogEvent(event, wxT("Left OnFocused"));
	wxLogMessage(wxT("Left List Ctrl"));
}

void MainFrame::OnRightFocused(wxListEvent& event)
{
	LogEvent(event, wxT("Right OnFocused"));
	wxLogMessage(wxT("Right List Ctrl"));
}

void MainFrame::LogEvent(const wxListEvent& event, const wxChar *eventName)
{
	wxLogMessage(wxT("Item %ld: %s (item text = %s, data = %ld)"),
			event.GetIndex(), eventName, event.GetText().c_str(),
			event.GetData());
}

void MainFrame::OnItemDown(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnItemDown Mode"));
	if (m_listCtrlLeft->HasFocus())
	{
		long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);

		if ((itemCur != -1)
				&& itemCur < (m_myMovSmiData->getSizeOfVectorMov() - 1))
		{
			std::iter_swap(m_myMovSmiData->mvMovFiles.begin() + itemCur,
					m_myMovSmiData->mvMovFiles.begin() + itemCur + 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Left has Focus"));
		}
		else
		{
			m_logWindow->WriteText(wxT("No item to down\n"));
		}
	}
	else if (m_listCtrlRight->HasFocus())
	{
		long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);
		if ((itemCur2 != -1)
				&& itemCur2 < (m_myMovSmiData->getSizeOfVectorSmi() - 1))
		{
			std::iter_swap(m_myMovSmiData->mvSmiFiles.begin() + itemCur2,
					m_myMovSmiData->mvSmiFiles.begin() + itemCur2 + 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Right has Focus"));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to down\n"));
		}
	}

}

void MainFrame::OnItemUp(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnItemUp Mode"));
	if (m_listCtrlLeft->HasFocus())
	{
		long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);

		if ((itemCur != -1) && (itemCur != 0))
		{
			std::iter_swap(m_myMovSmiData->mvMovFiles.begin() + itemCur,
					m_myMovSmiData->mvMovFiles.begin() + itemCur - 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Left has Focus"));
		}
		else
		{
			m_logWindow->WriteText(wxT("No item to up\n"));
		}
	}
	else if (m_listCtrlRight->HasFocus())
	{
		long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);
		if ((itemCur2 != -1) && (itemCur2 != 0))
		{
			std::iter_swap(m_myMovSmiData->mvSmiFiles.begin() + itemCur2,
					m_myMovSmiData->mvSmiFiles.begin() + itemCur2 - 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Right has Focus"));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to up\n"));
		}
	}
}

void MainFrame::OnItemSort(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnItemSort Mode"));
	m_myMovSmiData->sortFiles(true);
	RecreateList(wxLC_LIST);
}

void MainFrame::OnRename(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnRename Mode"));
	m_myMovSmiData->renameSmiFiles();
	m_myMovSmiData->clearVector();
	m_myMovSmiData->loadFiles(".");
	RecreateList(wxLC_LIST);
	wxLogMessage(wxT("Rename Operation has been done."));
}

void MainFrame::OnRenameSmi(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnRenameSmi Mode"));
	m_myMovSmiData->renameMovFiles();
	m_myMovSmiData->clearVector();
	m_myMovSmiData->loadFiles(".");
	RecreateList(wxLC_LIST);
	wxLogMessage(wxT("Rename Operation has been done."));
}

void MainFrame::OnOpen(wxCommandEvent& event)
{
	wxLogMessage(wxT("OnOpen Mode"));
	/*
	 wxFileDialog openFileDialog(this, _("Open Movie file"), "", "",
	 "Movie files (*.*)|*.*", wxFD_OPEN | wxFD_CHANGE_DIR);
	 if (openFileDialog.ShowModal() == wxID_CANCEL)
	 return;     // the user changed idea...
	 */

	wxDirDialog dirDialog(this, wxT("Choose Directory"), "",
	wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	if (dirDialog.ShowModal() == wxID_CANCEL)
		return;
	wxLogMessage(wxString::Format("%s\n", dirDialog.GetPath()));

	if (!wxSetWorkingDirectory(dirDialog.GetPath()))
		perror("cannot change directory");

	m_myMovSmiData->clearVector();
	m_myMovSmiData->loadFiles(dirDialog.GetPath().c_str());
	if (m_myMovSmiData->getSizeOfVectorMov() <= 0)
	{
		wxLogMessage(wxT("There is no movie files and smi files"));
		return;
	}
	// showing ListCtrl
	RecreateList(wxLC_LIST);
}

void MainFrame::OnButtonItemUpLeft(wxCommandEvent& event)
{
	{
		long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);

		if ((itemCur != -1) && (itemCur != 0))
		{
			std::iter_swap(m_myMovSmiData->mvMovFiles.begin() + itemCur,
					m_myMovSmiData->mvMovFiles.begin() + itemCur - 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Left has Focus"));
		}
		else
		{
			m_logWindow->WriteText(wxT("No item to up\n"));
		}
	}
}

void MainFrame::OnButtonItemDownLeft(wxCommandEvent& event)
{
	{
		long itemCur = m_listCtrlLeft->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);

		if ((itemCur != -1)
				&& itemCur < (m_myMovSmiData->getSizeOfVectorMov() - 1))
		{
			std::iter_swap(m_myMovSmiData->mvMovFiles.begin() + itemCur,
					m_myMovSmiData->mvMovFiles.begin() + itemCur + 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Left has Focus"));
		}
		else
		{
			m_logWindow->WriteText(wxT("No item to down\n"));
		}
	}
}

void MainFrame::OnButtonItemUpRight(wxCommandEvent& event)
{
	{
		long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);
		if ((itemCur2 != -1) && (itemCur2 != 0))
		{
			std::iter_swap(m_myMovSmiData->mvSmiFiles.begin() + itemCur2,
					m_myMovSmiData->mvSmiFiles.begin() + itemCur2 - 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Right has Focus"));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to up\n"));
		}
	}
}

void MainFrame::OnButtonItemDownRight(wxCommandEvent& event)
{

	{
		long itemCur2 = m_listCtrlRight->GetNextItem(-1, wxLIST_NEXT_ALL,
		wxLIST_STATE_FOCUSED);
		if ((itemCur2 != -1)
				&& itemCur2 < (m_myMovSmiData->getSizeOfVectorSmi() - 1))
		{
			std::iter_swap(m_myMovSmiData->mvSmiFiles.begin() + itemCur2,
					m_myMovSmiData->mvSmiFiles.begin() + itemCur2 + 1);
			RecreateList(wxLC_LIST);
			wxLogMessage(wxT("Right has Focus"));

		}
		else
		{
			m_logWindow->WriteText(wxT("No item to down\n"));
		}
	}
}

// ----------------------------------------------------------------------------
// changing listctrl modes
// ----------------------------------------------------------------------------

void MainFrame::RecreateList(long flags, bool withText)
{

//	delete m_listCtrlLeft;
//	delete m_listCtrlRight;

	if (m_myMovSmiData->getSizeOfVectorMov() <= 0)
	{
		wxLogMessage(wxT("There is no movie files and smi files"));
		return;
	}

	m_listCtrlLeft->ClearAll();
	m_listCtrlRight->ClearAll();

	switch (flags & wxLC_MASK_TYPE)
	{
	case wxLC_LIST:
		for (int i = 0; i < m_myMovSmiData->getSizeOfVectorMov(); i++)
		{
			//		m_listCtrl->InsertItem(i, wxString::Format(wxT("Item %d"), i));

			m_listCtrlLeft->InsertItem(i,
					wxString::Format(wxT("%s"), m_myMovSmiData->mvMovFiles[i]));
			m_listCtrlRight->InsertItem(i,
					wxString::Format(wxT("%s"), m_myMovSmiData->mvSmiFiles[i]));

		}

		break;

	default:
		wxFAIL_MSG(wxT("unknown listctrl mode"));
	}

	//DoSize();

	m_logWindow->Clear();

	wxLogMessage(wxT("Movie Data is loaded"));
//	m_logWindow->WriteText(wxString::Format(wxT("%s\n"), m_myMovSmiData->mvMovFiles[0]));
}
// ----------------------------------------------------------------------------
// MainFrame
// ----------------------------------------------------------------------------
/*
 BEGIN_EVENT_TABLE(MainFrame, wxFrame)
 EVT_SIZE(MainFrame::OnSize)
 EVT_MENU(LIST_QUIT, MainFrame::OnQuit)
 EVT_MENU(LIST_ABOUT, MainFrame::OnAbout)
 EVT_MENU(LIST_EDIT, MainFrame::OnEdit)
 END_EVENT_TABLE()
 */
