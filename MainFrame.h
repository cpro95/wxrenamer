/*
 * MainFrame.h
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include "wx/wx.h"

#include "wx/listctrl.h"
#include "wx/timer.h"           // for wxStopWatch
#include "wx/colordlg.h"        // for wxGetColourFromUser
#include "wx/settings.h"
#include "wx/sysopt.h"
#include "wx/numdlg.h"

#include "MovSmiData.h"


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxChar *title);
	virtual ~MainFrame();

	void DoSize();
	// IDs for the menu commands

protected:

	void OnSize(wxSizeEvent& event);

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void LogEvent(const wxListEvent& event, const wxChar *eventName);
	void OnEdit(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnButtonItemUpLeft(wxCommandEvent& event);
	void OnButtonItemDownLeft(wxCommandEvent& event);
	void OnButtonItemUpRight(wxCommandEvent& event);
	void OnButtonItemDownRight(wxCommandEvent& event);
	void OnItemDown(wxCommandEvent& event);
	void OnItemUp(wxCommandEvent& event);
	void OnItemSort(wxCommandEvent& event);
	void OnRename(wxCommandEvent& event);
	void OnRenameSmi(wxCommandEvent& event);

	void OnLeftSelected(wxListEvent& event);
	void OnRightSelected(wxListEvent& event);
	void OnLeftFocused(wxListEvent& event);
	void OnRightFocused(wxListEvent& event);

	/*
	void OnListView(wxCommandEvent& event);
	void OnReportView(wxCommandEvent& event);
	void OnIconView(wxCommandEvent& event);
	void OnIconTextView(wxCommandEvent& event);
	void OnSmallIconView(wxCommandEvent& event);
	void OnSmallIconTextView(wxCommandEvent& event);
	void OnVirtualView(wxCommandEvent& event);
	void OnSmallVirtualView(wxCommandEvent& event);

	void OnSetItemsCount(wxCommandEvent& event);

	void OnGoTo(wxCommandEvent& event);
	void OnFocusLast(wxCommandEvent& event);
	void OnToggleFirstSel(wxCommandEvent& event);
	void OnDeselectAll(wxCommandEvent& event);
	void OnSelectAll(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
	void OnEdit(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnDeleteAll(wxCommandEvent& event);
	void OnSort(wxCommandEvent& event);
	void OnSetFgColour(wxCommandEvent& event);
	void OnSetBgColour(wxCommandEvent& event);
	void OnSetRowLines(wxCommandEvent& event);
	void OnToggleMultiSel(wxCommandEvent& event);
	void OnShowColInfo(wxCommandEvent& event);
	void OnShowSelInfo(wxCommandEvent& event);
	void OnShowViewRect(wxCommandEvent& event);
	void OnFreeze(wxCommandEvent& event);
	void OnThaw(wxCommandEvent& event);
	void OnToggleLines(wxCommandEvent& event);
	void OnToggleHeader(wxCommandEvent& event);
	void OnToggleBell(wxCommandEvent& event);

	void OnFind(wxCommandEvent& event);

	void OnUpdateUIEnableInReport(wxUpdateUIEvent& event);
	void OnUpdateToggleMultiSel(wxUpdateUIEvent& event);
	void OnUpdateToggleHeader(wxUpdateUIEvent& event);
	void OnUpdateRowLines(wxUpdateUIEvent& event);
*/
	wxPanel *m_panel;
	wxListCtrl *m_listCtrlLeft;
	wxListCtrl *m_listCtrlRight;
	wxTextCtrl *m_logWindow;
	MovSmiData *m_myMovSmiData;


private:
	// recreate the list control with the new flags
	void RecreateList(long flags, bool withText = true);

	wxLog *m_logOld;

	// number of items to initialize list/report view with
/*
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
*/
	wxDECLARE_NO_COPY_CLASS(MainFrame);
};

enum
{
	LIST_ABOUT,
	LIST_QUIT = wxID_EXIT,
	LIST_OPEN,
	LIST_EDIT,
	LIST_DELETE,
	LIST_DOWN,
	LIST_UP,
	LIST_SORT,
	LIST_RENAME,
	LIST_RENAMESMI,
	ID_BUTTON1,
	ID_BUTTON2,
	ID_BUTTON3,
	ID_BUTTON4,
	ID_BUTTON5,
	ID_BUTTON6,
/*
	LIST_LIST_VIEW = wxID_HIGHEST,
	LIST_ICON_VIEW,
	LIST_ICON_TEXT_VIEW,
	LIST_SMALL_ICON_VIEW,
	LIST_SMALL_ICON_TEXT_VIEW,
	LIST_REPORT_VIEW,
	LIST_VIRTUAL_VIEW,
	LIST_SMALL_VIRTUAL_VIEW,
	LIST_SET_ITEMS_COUNT,

	LIST_DESELECT_ALL,
	LIST_SELECT_ALL,
	LIST_DELETE_ALL,
	LIST_DELETE,
	LIST_ADD,
	LIST_EDIT,
	LIST_SORT,
	LIST_FIND,
	LIST_SET_FG_COL,
	LIST_SET_BG_COL,
	LIST_ROW_LINES,
	LIST_TOGGLE_MULTI_SEL,
	LIST_TOGGLE_HEADER,
	LIST_TOGGLE_BELL,
	LIST_TOGGLE_FIRST,
	LIST_SHOW_COL_INFO,
	LIST_SHOW_SEL_INFO,
	LIST_SHOW_VIEW_RECT,
	LIST_GOTO,
	LIST_FOCUS_LAST,
	LIST_FREEZE,
	LIST_THAW,
	LIST_TOGGLE_LINES,

*/
	LIST_CTRL_LEFT = 1000,
	LIST_CTRL_RIGHT = 1001
};


#endif /* MAINFRAME_H_ */
