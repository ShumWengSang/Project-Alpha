#ifndef __MVC_CONTROLLER_H__
#define __MVC_CONTROLLER_H__

#ifndef __WINDOWS_H__
#include <Windows.h>
#define __WINDOWS_H__
#endif

class MVC_Model;
class MVC_View;

class MVC_Controller
{
public:
	MVC_Controller(MVC_Model* theModel, MVC_View* theView);
	~MVC_Controller(void);

	// Get the status of the stop game boolean flag
	BOOL RunMainLoop(void);

	// Process input from I/O devices
	bool ProcessInput(void);

	inline void SetHandle(HWND hwnd) { m_handle = hwnd; }

	// Handle to the model
	MVC_Model* m_theModel;

	// Handle to the view
	MVC_View* m_theView;

	bool Init();

protected:
	HWND m_handle;// window handle to map window to controller

	bool m_bContinueLoop;

	//Changes the input keys to its corresponding int values
	int ProcKeys(int);
	
	//Keyboard Handler
	void ProcKeyboard();
	void ProcMouse();


};

#endif