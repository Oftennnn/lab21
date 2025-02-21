#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <stdio.h>


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
HWND textfield, button ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

char text1[100];
char text2[100];
char t1[100] ;
char t2[100] ;
double x,y;
HWND num1,num2;
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = CreateSolidBrush(RGB(20, 255, 0));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("My Calculator"),       /* Title Text */
           WS_SYSMENU,          /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           250,                 /* The programs width */
           200,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
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
                               hwnd, NULL, NULL, NULL);

        num2 = CreateWindow("EDIT",
                               "",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40, 80, 150, 20,
                               hwnd, NULL, NULL, NULL);

        CreateWindow("BUTTON",
                     "+",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     40, 110, 30, 30,
                     hwnd, (HMENU) 1 ,NULL,NULL);

        CreateWindow("BUTTON",
                     "-",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     80, 110, 30, 30,
                     hwnd, (HMENU) 2 ,NULL,NULL);

        CreateWindow("BUTTON",
                     "*",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     120, 110, 30, 30,
                     hwnd, (HMENU) 3 ,NULL,NULL);

        CreateWindow("BUTTON",
                     "/",
                     WS_BORDER | WS_CHILD | WS_VISIBLE,
                     160, 110, 30, 30,
                     hwnd, (HMENU) 4 ,NULL,NULL);

        break;

    case WM_COMMAND:
    switch (LOWORD(wParam))
    {
        case 1:
        {
            char text1[100] = {0};
            char text2[100] = {0};

            int gwtstat1 = GetWindowText(num1, text1, sizeof(text1));
            int gwtstat2 = GetWindowText(num2, text2, sizeof(text2));

            double x = atof(text1);
            double y = atof(text2);

            double result = x + y;

            char resultText[100];
            sprintf(resultText, "%f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 2:
        {
            char text1[100] = {0};
            char text2[100] = {0};

            int gwtstat1 = GetWindowText(num1, text1, sizeof(text1));
            int gwtstat2 = GetWindowText(num2, text2, sizeof(text2));

            double x = atof(text1);
            double y = atof(text2);

            double result = x - y;

            char resultText[100];
            sprintf(resultText, "%f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 3:
        {
            char text1[100] = {0};
            char text2[100] = {0};

            int gwtstat1 = GetWindowText(num1, text1, sizeof(text1));
            int gwtstat2 = GetWindowText(num2, text2, sizeof(text2));

            double x = atof(text1);
            double y = atof(text2);

            double result = x * y;

            char resultText[100];
            sprintf(resultText, "%f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }

        case 4:
        {
            char text1[100] = {0};
            char text2[100] = {0};

            int gwtstat1 = GetWindowText(num1, text1, sizeof(text1));
            int gwtstat2 = GetWindowText(num2, text2, sizeof(text2));

            double x = atof(text1);
            double y = atof(text2);


            double result = x / y;

            char resultText[100];
            sprintf(resultText, "%f", result);
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hwnd, resultText, "Result", MB_OK);
            break;
        }
    }
    break;





        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
