#include <windows.h>
#include <stdio.h>

char text1[100]={0};
char text2[100]={0};
char resultText[100];
double x,y,result;
HWND num1,num2;
HWND textfield,button1,button2,button3,button4 ;

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:
        textfield = CreateWindow("STATIC",
                                 "Please input two numbers",
                                 WS_VISIBLE | WS_CHILD ,
                                 30, 20 ,170 ,20,
                                 hwnd, NULL, NULL, NULL);
        num1 = CreateWindow("EDIT",
                               "",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40, 50, 150, 20,
                               hwnd, (HMENU) 5, NULL, NULL);

        num2 = CreateWindow("EDIT",
                               "",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40, 80, 150, 20,
                               hwnd, (HMENU) 6, NULL, NULL);

       button1 = CreateWindow("BUTTON",
                     "+",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     40, 110, 30, 30,
                     hwnd, (HMENU) 1 ,NULL,NULL);

		button2 = CreateWindow("BUTTON",
                     "-",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     80, 110, 30, 30,
                     hwnd, (HMENU) 2 ,NULL,NULL);

		 button3 = CreateWindow("BUTTON",
                     "*",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     120, 110, 30, 30,
                     hwnd, (HMENU) 3 ,NULL,NULL);

		 button4 = CreateWindow("BUTTON",
                     "/",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     160, 110, 30, 30,
                     hwnd, (HMENU) 4 ,NULL,NULL);

        break;

    case WM_COMMAND:
	GetWindowText(GetDlgItem(hwnd,5), text1, sizeof(text1));
       GetWindowText(GetDlgItem(hwnd,6), text2, sizeof(text2));
	    x = atof(text1);
    	 y = atof(text2);

    switch (LOWORD(wParam))
    {
	
        case 1:
        {
            result = x + y;   
            sprintf(resultText, "%.3f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 2:
        {
			 result = x - y;   
            sprintf(resultText, "%.3f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 3:
        {
			 result = x * y;   
            sprintf(resultText, "%.3f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 4:
        {
			
			 result = x / y;   
            sprintf(resultText, "%.3f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }
    }
    break;

		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreateSolidBrush(RGB(20, 255, 0));
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
