#include <windows.h>
#include <time.h>

#define CELL 15
#define W  20
#define H  26
#define MS_NEWBLOCK WM_USER+1
#define MS_DRAW  WM_USER+2
#define MS_NEXTBLOCK WM_USER+3

LRESULT CALLBACK WndProc ( HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR  szCmdLine, int  iCmdShow)
{
	static char AppName[]="ToyBrick";
	HWND  hwnd;
	MSG   msg;
	WNDCLASSEX wndclass;
	int   iScreenWide;

	wndclass.cbSize   = sizeof(wndclass);
	wndclass.style   = CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra  = 0;
	wndclass.cbWndExtra  = 0;
	wndclass.hInstance  = hInstance;
	wndclass.hIcon   = LoadIcon (NULL, IDI_APPLICATION);
	wndclass.hCursor  = LoadCursor (NULL,IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = AppName;
	wndclass.hIconSm  = LoadIcon (NULL, IDI_APPLICATION);

	if(!RegisterClassEx (&wndclass))
	{
		MessageBeep(0);
		return FALSE;
	}

	iScreenWide=GetSystemMetrics (SM_CXFULLSCREEN);
	hwnd =CreateWindow (AppName, "***********", WS_MINIMIZEBOX|WS_SYSMENU ,
		iScreenWide/2-W*CELL/2, CELL, W*CELL, H*CELL, NULL, NULL, hInstance, NULL);
	if(!hwnd) return FALSE;
	ShowWindow (hwnd,iCmdShow);
	UpdateWindow (hwnd);

	MessageBox(hwnd," **\'**p\n\n OH YEAH","**\'",MB_OK);
	SendMessage(hwnd,MS_NEWBLOCK,0,0);
	SetTimer (hwnd, 1, 1000, NULL);

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}

	return msg.wParam;    
}

void DrawRect (HDC hdc, int l, int t, int r, int b)
{
	MoveToEx (hdc, l, t, nullptr);
	LineTo (hdc, r, t);          
	LineTo (hdc, r, b);
	LineTo (hdc, l, b);
	LineTo (hdc, l,t);
}

void DrawCell (HDC hdc, int l, int t, int r, int b)
{ 
	HBRUSH hbrush; 
	hbrush=CreateSolidBrush(RGB(255,0,0));
    SelectObject(hdc,hbrush);
    Rectangle(hdc,l, t, r, b);
    DeleteObject (hbrush);
}

void DrawGamePlace(HDC hdc)
{
	int i,j;
	HPEN hpen1,hpen2;
	hpen1=CreatePen(PS_SOLID,1,RGB(0,255,0));
	hpen2=CreatePen(PS_DASHDOTDOT,3,RGB(0,0,255));
	SelectObject(hdc,hpen2);
	MoveToEx(hdc,(W-8)*CELL,0,NULL); 
	LineTo(hdc,(W-8)*CELL,H*CELL);
	SelectObject(hdc,hpen1);
	for (i=1; i<H-1; i++)
		for(j=1; j<=W-8; j++)
			DrawRect (hdc, (j-1)*CELL, (i-1)*CELL, j*CELL, i*CELL);
	for(i=5;i<9;i++)
		for(j=W-5;j<W-1;j++)
			DrawRect (hdc, (j-1)*CELL, (i-1)*CELL, j*CELL, i*CELL);
    DeleteObject(hpen2);
	DeleteObject(hpen1);
}

void DrawBlock (HDC hdc, int block[4][2])
{
	int i;
	for(i=0; i<4; i++)
		DrawCell (hdc, (block[i][0]-1)*CELL, (block[i][1]-1)*CELL, \
		block[i][0]*CELL, block[i][1]*CELL);
}

void Cover (HDC hdc, int org[4][2])
{
	int i;
	HBRUSH hbrush;
	DrawGamePlace(hdc);
	hbrush=(HBRUSH)GetStockObject (BLACK_BRUSH);
	SelectObject (hdc,hbrush );
	for(i=0; i<4; i++)
		Rectangle ( hdc, (org[i][0]-1)*CELL, (org[i][1]-1)*CELL, \
		org[i][0]*CELL, org[i][1]*CELL); 
	DeleteObject(hbrush);
}

LRESULT CALLBACK WndProc ( HWND  hwnd, UINT  iMsg, WPARAM wParam, LPARAM lParam )
{
	int   i,j,k,lines,r;
	static int top, sel, flag;
	static int cells[W-6][H];
	static int org[4][2], block[4][2],org2[4][2];
	HDC   hdc;
	HPEN  hpen;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
		case WM_CREATE:
			top=H-1;
			for(i=0; i<H; i++)
			{ 
				cells[0][i]=1;
				cells[W-7][i]=1;
			}
			for(i=0; i<W-6; i++)
				cells[i][H-1]=1;
			for(i=1; i<=W-8; i++)
				for(j=0; j<H-1; j++)
					cells[i][j]=0;
			return 0;
		case MS_NEWBLOCK:
			flag=0;
			for(i=top; i<H-1; i++)
			{
				lines =0;
				for(j=1; j<=W-7; j++)
					if(! cells[j][i]) 
					{
						lines=1;
						break;
					}
				if(!lines)
				{
					for(j=1;j<W-7; j++)
						for(k=i; k>=top; k--)
							cells[j][k]=cells[j][k-1];
					top++;
					InvalidateRect(hwnd, NULL, TRUE);
				}
			}
			srand( (unsigned)time( NULL ) );
			sel =rand()%7;
			switch(sel)
			{
				case 0:
					org[0][0]=block[0][0] =5; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =6; org[1][1]=block[1][1] =0;
					org[2][0]=block[2][0] =5; org[2][1]=block[2][1] =1;
					org[3][0]=block[3][0] =6; org[3][1]=block[3][1] =1;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 1:
					org[0][0]=block[0][0] =4; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =5; org[1][1]=block[1][1] =0;
					org[2][0]=block[2][0] =6; org[2][1]=block[2][1] =0;
					org[3][0]=block[3][0] =7; org[3][1]=block[3][1] =0;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 2:
					org[0][0]=block[0][0] =5; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =5; org[1][1]=block[1][1] =1;
					org[2][0]=block[2][0] =6; org[2][1]=block[2][1] =1;
					org[3][0]=block[3][0] =6; org[3][1]=block[3][1] =2;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 3:
					org[0][0]=block[0][0] =6; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =6; org[1][1]=block[1][1] =1;
					org[2][0]=block[2][0] =5; org[2][1]=block[2][1] =1;
					org[3][0]=block[3][0] =5; org[3][1]=block[3][1] =2;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 4:
					org[0][0]=block[0][0] =5; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =5; org[1][1]=block[1][1] =1;
					org[2][0]=block[2][0] =5; org[2][1]=block[2][1] =2;
					org[3][0]=block[3][0] =6; org[3][1]=block[3][1] =2;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 5:
					org[0][0]=block[0][0] =5; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =5; org[1][1]=block[1][1] =1;
					org[2][0]=block[2][0] =5; org[2][1]=block[2][1] =2;
					org[3][0]=block[3][0] =4; org[3][1]=block[3][1] =2;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					break;
				case 6:
					org[0][0]=block[0][0] =5; org[0][1]=block[0][1] =0;
					org[1][0]=block[1][0] =4; org[1][1]=block[1][1] =1;
					org[2][0]=block[2][0] =5; org[2][1]=block[2][1] =1;
					org[3][0]=block[3][0] =6; org[3][1]=block[3][1] =1;
					for(i=0;i<4;i++)
					{
						org2[i][0]=org[i][0]+11;
						org2[i][1]=org[i][1]+5;
					}
					SendMessage (hwnd, MS_NEXTBLOCK, 0, 0);
					break;
				default:
					SendMessage (hwnd, MS_NEWBLOCK, 0, 0);
					SendMessage (hwnd, MS_NEXTBLOCK, 0, 0);
					break;
			}
			return 0;
		case WM_TIMER:
			for(i=0; i<4; i++)
				block[i][1]++;
			for(i=0; i<4; i++)
				if(cells[ block[i][0] ][ block[i][1] ])
				{ 
					SendMessage (hwnd, MS_NEXTBLOCK, 0, 0);
					for(i=0; i<4; i++)
						cells[ org[i][0] ][ org[i][1] ]=1;
					if(top>org[0][1]-2)
						top=org[0][1]-2;
					if (top<1)
					{
						KillTimer (hwnd, 1);
						MessageBox (hwnd, "**p*********˳* !\n    *******", "*˳*", MB_OK);
						PostQuitMessage (0);
					}
					SendMessage (hwnd, MS_NEWBLOCK, 0, 0);
					return 0;
				}
			SendMessage (hwnd, MS_DRAW, 0, 0);
			return 0;
		case WM_KEYDOWN:
			r=0;
			switch((int)wParam)
			{
				case VK_LEFT:
					for(i=0; i<4; i++)
						block[i][0]--;
					break;
				case VK_RIGHT:
					for(i=0; i<4; i++)
						block[i][0]++;
					break;
				case VK_DOWN:
					for(i=0; i<4; i++)
						block[i][1]++;
					break;
				case VK_UP:
					r=1;
					flag++;
					switch(sel)
					{
						case 0: break;
						case 1: 
							flag =flag%2;
							for(i=0; i<4; i++)
							{
								block[i][(flag+1)%2] =org[2][(flag+1)%2];
								block[i][flag] =org[2][flag]-2+i;
							}
							break;
						case 2:
							flag =flag%2;
							if(flag)
							{ block[0][1] +=2; block[3][0] -=2; }
							else
							{ block[0][1] -=2; block[3][0] +=2; }
							break;
						case 3:
							flag =flag%2;
							if(flag)
							{ block[0][1] +=2; block[3][0] +=2; }
							else
							{ block[0][1] -=2; block[3][0] -=2; }
							break;
						case 4:
							flag=flag%4;
							switch(flag)
							{
								case 0:
									block[2][0] +=2; block[3][0] +=2;
									block[2][1] +=1; block[3][1] +=1;
									break;
								case 1:
									block[2][0] +=1; block[3][0] +=1;
									block[2][1] -=2; block[3][1] -=2;
									break;
								case 2:
									block[2][0] -=2; block[3][0] -=2;
									block[2][1] -=1; block[3][1] -=1;
									break;
								case 3:
									block[2][0] -=1; block[3][0] -=1;
									block[2][1] +=2; block[3][1] +=2;
									break;
							}
							break;
						case 5:
							flag=flag%4;
							switch(flag)
							{
								case 0:
									block[2][0] +=1; block[3][0] +=1;
									block[2][1] +=2; block[3][1] +=2;
									break;
								case 1:
									block[2][0] +=2; block[3][0] +=2;
									block[2][1] -=1; block[3][1] -=1;
									break;
								case 2:
									block[2][0] -=1; block[3][0] -=1;
									block[2][1] -=2; block[3][1] -=2;
									break;
								case 3:
									block[2][0] -=2; block[3][0] -=2;
									block[2][1] +=1; block[3][1] +=1;
									break;
							}
							break;
						case 6:
							flag =flag%4;
							switch(flag)
							{
								case 0:
									block[0][0]++; block[0][1]--;
									block[1][0]--; block[1][1]--;
									block[3][0]++; block[3][1]++;
									break;
								case 1:
									block[1][0]++; block[1][1]++; break;
								case 2:
									block[0][0]--; block[0][1]++; break;
								case 3:
									block[3][0]--; block[3][1]--; break;
							}
							break;
						}
						break;
					}
					for(i=0; i<4; i++)
						if(cells[ block[i][0] ][ block[i][1] ])
						{ 
							if(r) flag +=3;
							for(i=0; i<4; i++)
								for(j=0; j<2; j++)
									block[i][j]=org[i][j];
							return 0;
						}
					SendMessage(hwnd, MS_DRAW, 0, 0);;
					return 0;
				case MS_NEXTBLOCK:
					hdc=GetDC(hwnd);   
					Cover(hdc,org2);
					return 0;
				case MS_DRAW:
					hdc =GetDC (hwnd);
					Cover (hdc, org);
					DrawBlock(hdc,org2);
					for(i=0; i<4; i++)
						for(j=0; j<2; j++)
							org[i][j]=block[i][j];
					DrawBlock (hdc,block);
					ReleaseDC (hwnd, hdc);
					return 0;
				case WM_PAINT:
					hdc =BeginPaint (hwnd, &ps);
					DrawGamePlace(hdc);
					TextOut(hdc,15*CELL,12*CELL,"Score",lstrlen("Score"));
					TextOut(hdc,15*CELL,13*CELL,"i",lstrlen("i"));
					TextOut(hdc,15*CELL,15*CELL,"Level",lstrlen("Level"));
					TextOut(hdc,15*CELL-5,19*CELL,"*******",lstrlen("*******"));
					hpen =CreatePen (PS_SOLID,1,RGB(0,255,0));
					SelectObject (hdc,hpen);
					for (i=top; i<H-1; i++)
						for(j=1; j<=W-8; j++)
							if( cells[j][i] ) 
								DrawCell (hdc, (j-1)*CELL, (i-1)*CELL, j*CELL, i*CELL);
					DeleteObject (hpen);
					EndPaint (hwnd, &ps);
					return 0;
				case WM_DESTROY:
					KillTimer (hwnd, 1);
					PostQuitMessage (0);
					return 0;
			}
	return DefWindowProc (hwnd, iMsg, wParam, lParam);
}