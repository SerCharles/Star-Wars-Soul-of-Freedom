// HackingGame.cpp : ����Ӧ�ó������ڵ㡣
//

#include "HackingGame.h"

using namespace std;



#pragma region ȫ�ֱ�������

#pragma region ��Ҫ����
#define MAX_LOADSTRING			100		
// ȫ�ֱ���: 
HINSTANCE hInst; // ��ǰ����ʵ��
WCHAR szTitle[MAX_LOADSTRING]; // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING]; // ����������
Stage* currentStage = NULL; //��ǰ����״̬
Hero* theHero = NULL; //����״̬
guardian* boss = NULL;
bricks_breakable* computer = NULL; //�������ϵͳ�ķ�����ʩ
#pragma endregion

#pragma region ͼ����Դ
HBITMAP bmp_Back; 
HBITMAP bmp_Background;			//����ͼ����Դ
HBITMAP bmp_War_bg;             //ս������
HBITMAP bmp_win_bg;             //ʤ������
HBITMAP bmp_lose_bg;            //ʧ�ܱ���
HBITMAP bmp_pass_bg;           //ͨ������
HBITMAP bmp_help_bg;           //��������
HBITMAP bmp_StartButton;		 //��ʼ��ťͼ����Դ
HBITMAP bmp_QuitButton;			 //�˳���ťͼ����Դ
HBITMAP bmp_Continue;			//������ťͼ����Դ
HBITMAP bmp_Return;				//�������˵���ťͼ����Դ
HBITMAP bmp_ChooseJedi;			//ѡ��ְҵ1ͼ����Դ
HBITMAP bmp_melee_attack;        //��ս��Դ
HBITMAP bmp_ChooseSoldier;		//ѡ��ְҵ2ͼ����Դ
HBITMAP bmp_ChooseSpy;			//ѡ��ְҵ3ͼ����Դ
HBITMAP bmp_Hero;				//����ͼ����Դ
HBITMAP bmp_Restart;			//���¿�ʼ��ť��Դ
HBITMAP bmp_Help;				//�������水ť��Դ
HBITMAP bmp_ammo_Hero;			//�ӵ���Դ
HBITMAP bmp_bricks;             //�����ϰ���Դ
HBITMAP bmp_bricks_breakable;   //���ƻ��ϰ���Դ
HBITMAP bmp_laser;               //������Դ
HBITMAP bmp_Soldier_Melee;      //��սʿ����Դ
HBITMAP bmp_Soldier_Ranged;      //Զ��ʿ����Դ
HBITMAP bmp_Health;             //Ѫ����Դ
HBITMAP bmp_Force;               //ԭ����Դ
HBITMAP bmp_Exp;                 //������Դ
HBITMAP bmp_Health_Bag;          //���ư���Դ
HBITMAP bmp_Weapon_Bag;          //��������Դ
HBITMAP bmp_ammo_Enemy;          //�����ӵ���Դ
HBITMAP bmp_shield;              //������Դ
HBITMAP bmp_ammo_paralyze;       //����ӵ���Դ
HBITMAP bmp_bomb;                //ը����Դ
HBITMAP bmp_sneak;               //Ǳ����Դ
HBITMAP bmp_bomb_place;          //��λ����Դ
HBITMAP bmp_boss;                //boss��Դ
HBITMAP bmp_computer;            //�п���Դ
HBITMAP bmp_missile;             //׷�ٵ���Դ
HBITMAP bmp_help_key;            //��������
HBITMAP bmp_help_bkg;            //��������
HBITMAP bmp_help_module;         //ְҵ����
HBITMAP bmp_help_key_word;       //��������
HBITMAP bmp_help_bkg_word;       //��������
HBITMAP bmp_help_module_word;    //ְҵ����
HBITMAP bmp_v;                   //ʤ����ʾ
HBITMAP bmp_d;                   //ʧ����ʾ
HBITMAP bmp_p;                   //ͨ����ʾ
HBITMAP bmp_flame1;                
HBITMAP bmp_flame2;            
HBITMAP bmp_beforewar;
#pragma endregion

#pragma region ����
vector<Button*> buttons; //��ť
vector<ammo*> ammos;//�ӵ�
vector<melee_attack*> attack_melee; //��ս����
vector<bricks_permanent*> brick_p;//����ש��
vector<bricks_breakable*> brick_b;//���ƻ�ש��
vector<laser*> lasers;   //������
vector<Soldier_Melee*> soldier_m;//��սʿ��
vector<Soldier_Ranged*> soldier_r;//Զ��ʿ��
vector<health_bag*> h_bag;   //ҽ�ư�
vector<weapon_bag*>w_bag;    //������
vector<bombard*>Bombs;       //ը��
vector<missile*>Missiles;       //����
vector<Flame*>flms;          //����
#pragma endregion

#pragma region �������¼�
int mouseX = 0;
int mouseY = 0;
int hero_position = 1;                //����ְҵ
int previous_stage = STAGE_STARTMENU;  //��ǰ���������ڴ�����ͣ
bool mouseLeftDown = false;
bool mouseRightDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool skill1 = false;
bool skill2 = false;
int explodetm = 0;
#pragma endregion

#pragma region ��������
struct rt
{
	int dist;
	bool whether;
	int fatherx;
	int fathery;
}route[WINDOW_WIDTH / 5][WINDOW_HEIGHT / 5];
char gun_name[LENGTH1][LENGTH1] = { "","hunter","old gun","war gun","elite gun","destroyer" };
int laser_guns_attack[NUMBER1] = { 0,30,45,60,75,90 };
int laser_guns_ammo[NUMBER1] = { 0,30,35,40,45,50 };
double load_time[NUMBER1] = { 0,2.0,1.8,1.6,1.4,1.2 };
char position_name[LENGTH1][LENGTH1] = { "","Melee","Ranged","Snealth" };
int health_max[NUMBER1] = { 0,240,200,160 };
int health_improve[NUMBER1] = { 0,12,10,8 };
int force_improve = 5;
int attack_improve[NUMBER1] = { 0,6,5,4 };
int stamina_max[NUMBER1] = { 0,120,100,80 };
int force_max[NUMBER1] = { 0,100,100,100 };
int attack[NUMBER1] = { 0,120,100,80 };
int speed_max[NUMBER1] = { 0,5,7,10 };
int exp_require[11] = { 100,200,300,400,500,600,700,800,900,999,0};
double accleration[NUMBER1] = { 0,0.25,0.35,0.5 };
double shooting_bonus[NUMBER1] = { 0,0.8,1.2,1,0 };
double const PI = acos(double(-1));
WCHAR hp[LENGTH1] = {L"Health:"};
WCHAR fc[LENGTH1] = {L"Power:"};
WCHAR am[LENGTH1] = {L"Ammo:"};
WCHAR stg[LENGTH1] = { L"STAGE " };
WCHAR gun[LENGTH1][50] = { L"",L"Current Gun:Hunter",L"Current Gun:Old Gun",L"Current Gun:War Gun",L"Current Gun:Elite Gun",L"Current Gun:Destroyer" };
WCHAR exp1[50] = {L"Level 1  EXP:" };
WCHAR pst[10][50] = { L"",L"Module:Melee",L"Module:Ranged",L"Module:Snealth" };
int lofpst[10] = { 0,12,13,14 };
int lofgun[LENGTH1] = { 0,18,19,19,21,21 };
int lofhp = 0, loffc = 0, lofam = 0,lofexp=0,lofstg=0;
int ht = 0;
int tk = 1;
#pragma endregion

#pragma endregion


#pragma region Win32������



// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HACKINGGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HACKINGGAME));

    MSG msg;
    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HACKINGGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindow(szWindowClass, szTitle,
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������,
	   CW_USEDEFAULT, 
	   CW_USEDEFAULT,
	   WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   //�������뷨
   {
	   HIMC g_hIMC = NULL;                        // g_hIMC ���ڻָ�ʱʹ��
	   g_hIMC = ImmAssociateContext(hWnd, NULL);  // handle ΪҪ���õĴ��ھ��
   }
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		// ��ʼ����Ϸ����
		InitGame(hWnd, wParam, lParam);
		break;
	case WM_KEYDOWN:
		// ���̰����¼�
		KeyDown(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		// �����ɿ��¼�
		KeyUp(hWnd, wParam, lParam);
		break;
	case WM_MOUSEMOVE:
		// ����ƶ��¼�
		MouseMove(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		// �����������¼�
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		// �������ɿ��¼�
		LButtonUp(hWnd, wParam, lParam);
		break;
	case WM_RBUTTONDOWN:
		// ����Ҽ������¼�
		RButtonDown(hWnd, wParam, lParam);
		break;
	case WM_RBUTTONUP:
		// ����Ҽ��ɿ��¼�
		RButtonUp(hWnd, wParam, lParam);
		break;
	case WM_TIMER:
		// ��ʱ���¼�
		if(currentStage!=NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		break;
    case WM_PAINT:
		// ��ͼ
		Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#pragma endregion


#pragma region �¼�������

// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam) 
{
	//����ͼ����Դ
	bmp_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BG));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_START));
	bmp_QuitButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_QUIT));
	bmp_Continue = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONTINUE));
	bmp_Return = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RETURN));
	bmp_Help =   LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP));
	bmp_Restart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RESTART));
	bmp_ChooseJedi = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE_JEDI));
	bmp_ChooseSoldier = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE_SOLDIER));
	bmp_ChooseSpy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE_SPY));
	bmp_Hero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HERO));
	bmp_ammo_Hero= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AMMO_HERO));
	bmp_ammo_Enemy=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AMMO_ENEMY));
	bmp_bricks= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOCK));
	bmp_bricks_breakable = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOCK_BREAKABLE));
	bmp_laser= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LASER));
	bmp_Soldier_Melee = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SOLDIER_MELEE));
	bmp_Soldier_Ranged = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SOLDIER_RANGED));
	bmp_melee_attack= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MELEE_ATTACK));
	bmp_Health= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HEALTH));
	bmp_Force = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_FORCE));
	bmp_Exp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_EXP));
	bmp_Health_Bag= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HEALTH_BAG));
	bmp_Weapon_Bag= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WEAPON_BAG));
	bmp_shield = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SHIELD));
	bmp_ammo_paralyze=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AMMO_P));
	bmp_bomb=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOMB));
	bmp_sneak=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SNEATH));
	bmp_bomb_place=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PLACE_BOMB));
	bmp_boss=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOSS));
	bmp_computer=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_COMPUTER));
	bmp_missile= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MISSILE));
	bmp_Back = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
	bmp_War_bg= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WAR_BG));
	bmp_win_bg= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BG_VICTORY));
	bmp_pass_bg= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_PASS));
	bmp_lose_bg= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_LOST));
	bmp_help_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BG_HELP));
	bmp_help_key = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BTKEY));
	bmp_help_bkg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BTBG));
	bmp_help_module = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BTMD));
	bmp_help_key_word = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HPK));
	bmp_help_bkg_word = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HPBG));
	bmp_help_module_word = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HPMD));
	bmp_v = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_V));
	bmp_d = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_D));
	bmp_p = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_P));
	bmp_flame1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_FLAME1));
	bmp_flame2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_FLAME2));
	bmp_beforewar= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BEFOREWAR));
	//��Ӱ�ť

	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 200); //300,300Ϊ��������
	buttons.push_back(startButton);
	Button* quitButton = CreateButton(BUTTON_QUITGAME, bmp_QuitButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 400); 
	buttons.push_back(quitButton);
	Button* continueButton = CreateButton(BUTTON_CONTINUE, bmp_Continue, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 200);
	buttons.push_back(continueButton);
	Button* returnButton = CreateButton(BUTTON_RETURN, bmp_Return, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 550);
	buttons.push_back(returnButton);
	Button* chooseJedi = CreateButton(BUTTON_JEDI, bmp_ChooseJedi, BUTTON_CHOOSE_WIDTH, BUTTON_CHOOSE_HEIGHT, 50, 300); 
	buttons.push_back(chooseJedi);
	Button* chooseSoldier = CreateButton(BUTTON_SOLDIER, bmp_ChooseSoldier, BUTTON_CHOOSE_WIDTH, BUTTON_CHOOSE_HEIGHT, 300, 300); 
	buttons.push_back(chooseSoldier);
	Button* chooseSpy = CreateButton(BUTTON_SPY, bmp_ChooseSpy, BUTTON_CHOOSE_WIDTH, BUTTON_CHOOSE_HEIGHT, 550, 300); 
	buttons.push_back(chooseSpy);
	Button* restartButton = CreateButton(BUTTON_RESTART, bmp_Restart, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 400);
	buttons.push_back(restartButton);
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_Help, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 300);
	buttons.push_back(helpButton);
	Button* helpcontinueButton = CreateButton(BUTTON_HELP_CONTINUE, bmp_Continue, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 500);
	buttons.push_back(helpcontinueButton);
	Button* nextButton = CreateButton(BUTTON_NEXT, bmp_Continue, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 500);
	buttons.push_back(nextButton);
	Button* HelpKey= CreateButton(HELP_KEY, bmp_help_key, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 200);
	Button* Helpbg = CreateButton(HELP_BG, bmp_help_bkg, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 300);
	Button* Helpmodule = CreateButton(HELP_MD, bmp_help_module, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 400);
	Button* helpbackButton = CreateButton(HELP_BACK, bmp_Continue, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 600);
	Button* skipButton = CreateButton(BUTTON_SKIP, bmp_Continue, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 300, 600);
	buttons.push_back(HelpKey);
	buttons.push_back(Helpbg);
	buttons.push_back(Helpmodule);
	buttons.push_back(helpbackButton);
	buttons.push_back(skipButton);
	//��ʼ����ʼ����
	InitStage(hWnd, STAGE_STARTMENU,0);

	//��ʼ������ʱ��
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_W:
		keyUpDown = true;
		break;
	case VK_S:
		keyDownDown = true;
		break;
	case VK_A:
		keyLeftDown = true;
		break;
	case VK_D:
		keyRightDown = true;
		break;
	case VK_ESCAPE:
		if (currentStage->stageID >= STAGE_1&&currentStage->stageID <= STAGE_BOSS)
		{
			InitStage(hWnd, STAGE_PAUSE, 0);
		}
		break;
	case VK_1:
		skill1 = !skill1;
		break;
	case VK_2:
		skill2 = !skill2;
		break;
	default:
		break;
	}
}

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_W:
		keyUpDown = false;
		break;
	case VK_S:
		keyDownDown = false;
		break;
	case VK_A:
		keyLeftDown = false;
		break;
	case VK_D:
		keyRightDown = false;
		break;
	default:
		break;
	}
}

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseLeftDown = true;

	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_STARTGAME:
				{
					InitStage(hWnd, STAGE_BEFOREWAR,0); //��ʼ--ְҵѡ��
					break;
				}
				case BUTTON_JEDI:
				{
					hero_position = 1;
					InitStage(hWnd, STAGE_1,0);  //�����һ��
					break;
				}	
				case BUTTON_SOLDIER:
				{
					hero_position = 2;
					InitStage(hWnd, STAGE_1,0);       //�����һ��
					break;
				}
				case BUTTON_SPY:
				{
					hero_position = 3;
					InitStage(hWnd, STAGE_1,0);      //�����һ��
					
					break;
				}
				case BUTTON_CONTINUE:
				{
					InitStage(hWnd, previous_stage, 1);  //����֮ǰ�ؿ�
					break;
				}
				case BUTTON_NEXT:
				{
					if (previous_stage == STAGE_BOSS)
					{
						InitStage(hWnd, STAGE_STARTMENU, 0);  //�������˵�
						break;
					}
					else
					{
						InitStage(hWnd, previous_stage + 1, 0);
						break;
					}
				}
				case BUTTON_RETURN:
				{
					InitStage(hWnd, STAGE_STARTMENU,0);  //�������˵�
					break;
				}
				case BUTTON_RESTART:
				{ 
					InitStage(hWnd, previous_stage, 0);  //���¿�ʼ����
					break;
				}
				case BUTTON_HELP:
				{
					InitStage(hWnd,STAGE_HELP,0);       //�����������
					break;
				}
				case HELP_KEY:
				{
					InitStage(hWnd, STAGE_HELP_KEY, 0);       //���������������
					break;
				}
				case HELP_BACK:
				{
					if (previous_stage == STAGE_BEFOREWAR)
					{
						if (tk == 1)
						{
							tk = 2;
							InitStage(hWnd, STAGE_HELP_KEY, 0);
						}
						else if (tk == 2)
						{
							tk = 3;
							InitStage(hWnd, STAGE_HELP_MD, 0);
						}
						else
						{
							InitStage(hWnd, STAGE_CHOOSE, 0);
						}
					}
					else
					{
						InitStage(hWnd, STAGE_HELP, 0);       //���������������
					}
					break;
				}
				case HELP_BG:
				{
					InitStage(hWnd, STAGE_HELP_BG, 0);       //���������������
					break;
				}
				case HELP_MD:
				{
					InitStage(hWnd, STAGE_HELP_MD, 0);       //�������ְҵ����
					break;
				}
				case BUTTON_HELP_CONTINUE:
				{
				  if (previous_stage >= STAGE_1&&previous_stage <= STAGE_BOSS)
					 {
					  InitStage(hWnd, STAGE_PAUSE, 1);
					 }
				  else
					{
						InitStage(hWnd, previous_stage, 1);  //����֮ǰ�ؿ�
					}
					break;
				}
				case BUTTON_QUITGAME:            
				{
					DestroyWindow(hWnd);   //�˳���Ϸ
					PostQuitMessage(0);
					break;
				}
				case BUTTON_SKIP:
				{
					InitStage(hWnd, STAGE_HELP_KEY, 0);       //�������ְҵ����
					break;
				}
				}
				break;
			}
		}
		
	}
}

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseLeftDown = false;
}
//����Ҽ������¼�������
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseRightDown = true;
	Melee_Attack();
}
// ����Ҽ��ɿ��¼�������
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseRightDown = false;
}
// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	currentStage->timeCountDown--;
	if (currentStage->stageID != STAGE_BEFOREWAR)
	{
		if (currentStage->timeCountDown == 0) currentStage->timeCountDown = 10000;
		Hero_Shoot();
		UpdateLasers(hWnd);
		UpdateAmmos(hWnd);
		UpdateBombs(hWnd);
		UpdateMissiles(hWnd);
		UpdateMeleeAttack(hWnd);
		UpdateHero(hWnd);
		UpdateSoldier(hWnd);
		UpdateFlames(hWnd);
		if (currentStage->stageID == STAGE_BOSS&&boss != NULL)
		{
			UpdateBoss(hWnd);
		}
		UpdateDeath(hWnd);

		if (explodetm < 50)
		{
			explodetm++;
		}
		if (explodetm == 50)
		{
			mciSendString(_T("close exp"), NULL, 0, NULL);
		}
		Load_String();
	}
	else
	{
		if (currentStage->timeCountDown >= 9200 && currentStage->timeCountDown % 100 == 0) ht += 45;
		
	}
	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}


#pragma endregion


#pragma region ��ʼ������
//������ʼ������
weapon Create_laser_gun(char name[LENGTH1], int attack,int ammo_max,double load_time)
{
	weapon gun;
	memcpy(gun.name, name,sizeof(name));
    gun.ranged_attack = attack;
	gun.ammo_max = ammo_max;
	gun.load_time=load_time;
	return gun;
}
//ְҵ��ʼ������
occupation Create_occupation(char name[LENGTH1], int num, int attack, double accleration, int maxspeed, int health, int stamina, int force, double shooting_bonus, int health_imp, int attack_imp)
{
	occupation occ;
	occ.num = num;
	occ.melee_attack = attack;
	occ.accleration = accleration;
	occ.maxspeed = maxspeed;
	occ.health_max = health;
	occ.stamina_max = stamina;
	occ.force_max = force;
	occ.shooting_bonus = shooting_bonus;
	occ.health_improve = health_imp;
	occ.attack_improve = attack_imp;
	memcpy(occ.name, name, sizeof(name));
	return occ;
}
// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;  
	button->y = y;

	button->visible = false;
	return button;
}
// ������Ǻ���
Hero* CreateHero(HBITMAP img, char name[10], int position, int x, int y, int gun)
{
	Hero* hero = new Hero();
	hero->img = img;
	hero->x = x;
	hero->y = y;
	hero->frame = 0;
	hero->vx = 0;
	hero->vy = 0;
	hero->position = Create_occupation(position_name[position],position,attack[position], accleration[position], speed_max[position], health_max[position], stamina_max[position], force_max[position], shooting_bonus[position],health_improve[position],attack_improve[position]);
	hero->laser_guns = gun;
	hero->health_max = hero->position.health_max;
	hero->stamina_max = hero->position.stamina_max;
	hero->force_max = hero->position.force_max;
	hero->melee_attack = hero->position.melee_attack;
	hero->maxspeed = hero->position.maxspeed;
	hero->accleration = hero->position.accleration;
	int(hero->ranged_attack) = double(hero->position.shooting_bonus)*double(laser_guns_attack[hero->laser_guns]);
	hero->ammo_max = laser_guns_ammo[hero->laser_guns];
	hero->load_time = load_time[hero->laser_guns];
	hero->health_current = hero->health_max;
	hero->stamina_current = hero->stamina_max;
	hero->force_current = hero->force_max;
	hero->ammo_current = hero->ammo_max;
	hero->exp = 0;
	hero->level = 0;
	hero->skill_1 = 0;
	hero->skill_2 = 0;
	hero->invincible = 0;
	hero->paralyzed = 0;
	hero->charging = 0;
	hero->sneathed = 0;
	return hero;
}
//���Boss����
guardian* Create_Boss(HBITMAP img, int x, int y, int speed, int health_max, int damage_b, int damage_c)
{
	guardian* boss = new guardian();
	boss->img = img;
	boss->frame = 0;
	boss->x = x;
	boss->y = y;
	boss->width = BOSS_SIZE;
	boss->height = BOSS_SIZE;
	boss->speed = speed;
	boss->health_max = health_max;
	boss->health_current = health_max;
	boss->damage_bullet = damage_b;
	boss->damage_cannon = damage_c;
	boss->state = 1;
	boss->detect = 0;
	boss->paralyzed = 0;
	boss->paralyzed_time = 10000;
	boss->vx = 0;
	boss->vy = 0;
	return boss;
}
// ��ӽ�սС������
/*Soldier_Melee* Create_Soldier_Melee(HBITMAP img, int x, int y)
{
	Soldier_Melee*soldier = new Soldier_Melee();
	soldier->img = img;
	soldier->frame = 0;
	soldier->x = x;
	soldier->y = y;
	soldier->melee_attack = attack[2];
	soldier->health_max = 100;
	soldier->health_current = 100;
	soldier->speed = 2;
	return soldier;
}*/
//���Զ��С������
Soldier_Ranged* Create_Soldier_Ranged(HBITMAP img, int x, int y)
{
	Soldier_Ranged*soldier = new Soldier_Ranged();
	soldier->img = img;
	soldier->frame = 0;
	soldier->x = x;
	soldier->y = y;
	soldier->ranged_attack = 20;
	soldier->ammo_max = laser_guns_ammo[3];
	soldier->ammo_current = laser_guns_ammo[3];
	soldier->health_max = 70;
	soldier->health_current = 70;
	soldier->speed = 2;
	soldier->whether = 0;
	soldier->paralyzed = 0;
	soldier->paralyzed_time = 10000;
	soldier->load_time = load_time[3];
	return soldier;
}
//�������ש�麯��
bricks_permanent* Create_bricks_permanent(HBITMAP img, int x, int y, int width, int height, int laser)
{
	bricks_permanent* brick = new bricks_permanent();
	brick->img = img;
	brick->frame = 0;
	brick->x = x;
	brick->y = y;
	brick->height = height;
	brick->width = width;
	brick->laser = laser;
	return brick;
}
//��ӿ��ƻ�ש�麯��
bricks_breakable* Create_bricks_breakable(HBITMAP img, int x, int y, int width, int height)
{
	bricks_breakable* brick = new bricks_breakable();
	brick->img = img;
	brick->frame = 0;
	brick->x = x;
	brick->y = y;
	brick->height = height;
	brick->width = width;
	brick->health_max = 200;
	brick->health_current = 200;
	return brick;
}
//��Ӽ���������
laser* Create_laser(HBITMAP img, int x, int y, int width, int height,int direction)
{
	laser* trap = new laser();
	trap->img = img;
	trap->frame = 0;
	trap->x = x;
	trap->y = y;
	trap->height = height;
	trap->width = width;
	trap->damage = 10;
	trap->direction = direction;
	return trap;
}
//����ӵ�����
ammo* Create_ammo(HBITMAP img, int x, int y, int damage, double vx, double vy,int side)
{
	ammo* a = new ammo();
	a->img = img;
	a->frame = 0;
	a->x = x;
	a->y = y;
	a->damage = damage;
	a->speed = 30;
	a->vx = vx;
	a->vy = vy;
	a->live = 1;
	a->side = side;
	return a;
}
//���ը������
bombard* Create_bombs(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range, int width, int height)
{
	bombard* b = new bombard();
	b->img = img;
	b->x = x;
	b->y = y;
	b->damage = damage;
	b->type = type;
	b->live = 1;
	b->range = range;
	b->speed = speed;
	b->vx = 0;
	b->vy = 0;
	b->time = time;
	b->width = width;
	b->height = height;
	return b;
}
//��ӵ�������
missile* Create_missiles(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range, int width, int height)
{
	missile* b = new missile();
	b->img = img;
	b->x = x;
	b->y = y;
	b->damage = damage;
	b->type = type;
	b->live = 1;
	b->range = range;
	b->speed = speed;
	b->vx = 0;
	b->vy = 0;
	b->time = time;
	b->width = width;
	b->height = height;
	return b;
}
//��ӽ�ս��������
melee_attack* Create_melee_attack(HBITMAP img,int frame, int x, int y, int damage, bool side)
{
	melee_attack* a = new melee_attack();
	a->img = img;
	a->frame = frame;
	a->x = x;
	a->y = y;
	a->damage = damage;
	a->length = HERO_SIZE_X;
	a->timespan = 6;
	a->side = side;
	a->live = 1;
	return a;
}
//���ҽ�ư�����
health_bag* Create_health_bag(HBITMAP img, int x, int y)
{
	health_bag* a = new health_bag();
	a->img = img;
	a->x = x;
	a->y = y;
	a->live = 1;
	a->restore = 50;
	return a;
}
//�������������
weapon_bag* Create_weapon_bag(HBITMAP img, int x, int y, int weapon)
{
	weapon_bag* a = new weapon_bag();
	a->img = img;
	a->x = x;
	a->y = y;
	a->live = 1;
	a->weapon = weapon;
	return a;
}
//��ӻ��溯��
Flame* Create_flame(int x, int y)
{
	Flame* a = new Flame();
	a->x = x;
	a->y = y;
	a->live = 1;
	a->time = currentStage->timeCountDown;
	return a;
}
// ��ʼ����Ϸ��������
void InitStage(HWND hWnd, int stageID, bool whether)  //whether�ж��費��Ҫ��������
{
	// ��ʼ������ʵ��
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;


	if (stageID == STAGE_STARTMENU) {                         //���˵�
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		//PlaySound(L"res\\MainTheme.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			
			mciSendString(_T("open MainTheme.wav alias main"), NULL, 0, NULL);//���Դ�������·��
			mciSendString(_T("play main"), NULL, 0, NULL);
		//��ʾ��ʼ����İ�ť
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME || button->buttonID == BUTTON_QUITGAME || button->buttonID == BUTTON_HELP)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		previous_stage = STAGE_STARTMENU;
		

	}
	else if (stageID == STAGE_CHOOSE) {                 //ѡ��ְҵ����
		currentStage->bg = bmp_Back;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID >= BUTTON_JEDI && button->buttonID <= BUTTON_SPY)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		previous_stage = STAGE_CHOOSE;
	}
	else if (stageID == STAGE_PAUSE) {                   //��ͣ����
		currentStage->bg = bmp_Back;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		mciSendString(_T("close main"), NULL, 0, NULL);
		mciSendString(_T("close bat"), NULL, 0, NULL);
		mciSendString(_T("close bgm"), NULL, 0, NULL);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_CONTINUE || button->buttonID == BUTTON_RETURN || button->buttonID == BUTTON_HELP || button->buttonID == BUTTON_RESTART)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_WIN) {                   //ʤ������
		if (previous_stage != STAGE_BOSS)
		{
			currentStage->bg = bmp_pass_bg;
		}
		else
		{
			currentStage->bg = bmp_win_bg;
		}
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		mciSendString(_T("close bgm"), NULL, 0, NULL);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if ( button->buttonID == BUTTON_NEXT||button->buttonID==BUTTON_RESTART)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_LOSE) {                   //ʧ�ܳ���
		currentStage->bg = bmp_lose_bg;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		mciSendString(_T("close bat"), NULL, 0, NULL);
		mciSendString(_T("close bgm"), NULL, 0, NULL);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_RETURN || button->buttonID == BUTTON_RESTART)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_HELP) {                 //��������
		currentStage->bg = bmp_help_bg;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_HELP_CONTINUE|| button->buttonID == HELP_KEY ||button->buttonID == HELP_BG ||button->buttonID == HELP_MD)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP_KEY) {                 //��������
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == HELP_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP_BG) {                 //��������
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == HELP_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP_MD) {                 //��������
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == HELP_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_BEFOREWAR)
	{
		ht = 0;
		tk = 1;
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_SKIP)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		previous_stage = STAGE_BEFOREWAR;
	}
	else if (stageID >= STAGE_1 && stageID <= STAGE_5) //��Ϸ�ؿ�
	{
		mciSendString(_T("close main"), NULL, 0, NULL);
		//mciSendString(_T("open ..\\..\\HackingGame\\res\\battle.wav alias bat"), NULL, 0, NULL);
		mciSendString(_T("open battle.wav alias bat"), NULL, 0, NULL);
		mciSendString(_T("play bat"), NULL, 0, NULL);
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		//��ʾ��Ϸ����İ�ť
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (false) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		if (whether == 0)
		{
			// ��ʼ�������Լ�����������
			{
				if (stageID == STAGE_1)
				{
					char n[20] = { "Ser Charles" };
					if (theHero != NULL) delete theHero;
					theHero = CreateHero(bmp_Hero, n, hero_position, 500, 500, 1);
				}
				else
				{
					theHero->health_current = theHero->health_max;
					theHero->force_current = theHero->force_max;
					theHero->ammo_current = theHero->ammo_max;
					theHero->x = 500; theHero->y = 500;
				}
				brick_p.clear();
				ammos.clear();
				attack_melee.clear();
				brick_b.clear();
				lasers.clear();
				soldier_m.clear();
				soldier_r.clear();
				h_bag.clear();
				w_bag.clear();
				Bombs.clear();
				flms.clear();
				Missiles.clear();
				skill1 = 0;
				skill2 = 0;
				theHero->invincible = 0;
				theHero->charging = 0;
				theHero->sneathed = 0;
				theHero->paralyzed = 0;
			}
			//��ʼ���߽�
			{
				bricks_permanent *brick1 = Create_bricks_permanent(bmp_bricks, 0, 0, EDGE_LENGTH, WINDOW_HEIGHT - 105, 0);
				bricks_permanent *brick2 = Create_bricks_permanent(bmp_bricks, 0, 0, WINDOW_WIDTH, EDGE_LENGTH, 0);
				bricks_permanent *brick3 = Create_bricks_permanent(bmp_bricks, 0, WINDOW_HEIGHT - 115, WINDOW_WIDTH, EDGE_LENGTH, 0);
				bricks_permanent *brick4 = Create_bricks_permanent(bmp_bricks, WINDOW_WIDTH - 25, 0, EDGE_LENGTH, WINDOW_HEIGHT - 105, 0);
				brick_p.push_back(brick1);
				brick_p.push_back(brick2);
				brick_p.push_back(brick3);
				brick_p.push_back(brick4);
			}
			int r1, r2;
			blk blkp[8] = { {0,0,0,0},{230,340,50,50},{530,340,50,50},{ 380,225,50,50 },{320,440,150,50},{230,50,50,100},{530,50,50,100},{380,30,50,50} };//����ש��Ĳ���
			blk blkb[6] = { {0,0,0,0},{80,225,50,50},{230,225,50,50 },{ 380,135,50,50 } ,{ 530,225,50,50 } ,{ 680,225,50,50 } };//���ƻ�ש�����
			blk blks[9] = { {0,0,0,0},{80,50,0,0},{ 680,50,0,0 },{ 80,120,0,0 },{ 680,120,0,0 },{ 80,320,0,0 },{ 680,320,0,0 },{ 40,480,0,0 },{ 720,480,0,0 } };//С������
			//�������
			{
				srand((unsigned)time(NULL));
				while (1)  //�����ϰ�����
				{
					r1 = rand();
					if (r1 >= 3 && r1 < 127 && r1 != 4 && r1 != 8 && r1 != 16 && r1 != 32 && r1 != 64) break;
				}
				srand((unsigned)time(NULL));
				while (1)  //���ƻ��ϰ�����
				{
					r2 = rand();
					if (r2 >= 3 && r2 < 31 && r2 != 4 && r2 != 8 && r2 != 16) break;
				}

			}
			//��ʼ�������ϰ�
			{
				int i;
				for (i = 0; i < NUMBER_BRICK_PERMANENT; i++)
				{
					int a = NUMBER_BRICK_PERMANENT;
						if (r1 & two(i))
					{
						int l = 0;
						if (a - i == 1) l = 1;
						if (a - i == 3) l = 2;
						if (a - i == 7) l = 3;
						bricks_permanent* brick = Create_bricks_permanent(bmp_bricks, blkp[a - i].x, blkp[a - i].y, blkp[a - i].width, blkp[a - i].height, l);
						brick_p.push_back(brick);
					}
				}
			}
			//��ʼ�����ƻ��ϰ�
			{
				int i;
				for (i = 0; i < NUMBER_BRICK_BREAKABLE; i++)
				{
					int a = NUMBER_BRICK_BREAKABLE;
						if (r1 & two(i))
					{
						bricks_breakable* brick = Create_bricks_breakable(bmp_bricks_breakable, 
							blkb[a - i].x, blkb[a - i].y, blkb[a - i].width, blkb[a - i].height);
						brick_b.push_back(brick);
					}
				}
			}
			//��ʼ��������
			{
				int i;
				for (i = 0; i < brick_p.size(); i++)
				{
					bricks_permanent* b = brick_p[i];
					if (b->laser == 1)
					{
						laser* l = Create_laser(bmp_laser, b->x + 50, b->y + 15, 1, 20, 1);
						lasers.push_back(l);
					}
					if (b->laser == 2)
					{
						laser* l = Create_laser(bmp_laser, b->x + 50, b->y + 15, 1, 20, 1);
						lasers.push_back(l);
					}
					if (b->laser == 3)
					{
						laser* l = Create_laser(bmp_laser, b->x + 15, b->y + 50, 20, 1, 2);
						lasers.push_back(l);
					}
				}
			}
			//��ʼ��Զ��С��
			{
				int r;
				int hash[9] = { 0 };
				srand((unsigned)time(NULL));//С������	
				while (1)
				{
					r = rand();
					if (r % 9 >= 4&&r%9<=6) break;
				}
				int i;
				for (i = 1; i <= r%9; i++)
				{
					srand((unsigned)time(NULL));
					while (1)
					{
						int rt = rand() % 9;
						if (hash[rt] == 0&&rt>0)
						{
							hash[rt] = 1;
							Soldier_Ranged* s = Create_Soldier_Ranged(bmp_Soldier_Melee, blks[rt].x, blks[rt].y);
							soldier_r.push_back(s);
							break;
						}
					}
				}
			}
			previous_stage = stageID;
		}
		
	}
	else if (stageID == STAGE_BOSS)
	{
		mciSendString(_T("close bat"), NULL, 0, NULL);
		mciSendString(_T("open boss.wav alias bgm"), NULL, 0, NULL);
		mciSendString(_T("play bgm"), NULL, 0, NULL);
		currentStage->bg = bmp_War_bg;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		//��ʾ��Ϸ����İ�ť
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (false) //TODO��������Ϸ������Ҫ�İ�ť
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		//��ʼ�����Ǻ����vector
		if(whether==0)
		{
			theHero->health_current = theHero->health_max;
			theHero->force_current = theHero->force_max;
			theHero->ammo_current = theHero->ammo_max;
			theHero->x = 350; theHero->y = 500;
			brick_p.clear();
			ammos.clear();
			attack_melee.clear();
			brick_b.clear();
			lasers.clear();
			soldier_m.clear();
			soldier_r.clear();
			h_bag.clear();
			w_bag.clear();
			Bombs.clear();
			flms.clear();
			Missiles.clear();
			boss = NULL;
			computer = NULL;
			skill1 = 0;
			skill2 = 0;
			computer = Create_bricks_breakable(bmp_computer, 350, 30, COMPUTER_SIZE_X, COMPUTER_SIZE_Y);
			computer->health_current = 2000;
			computer->health_max = 2000;
			boss = Create_Boss(bmp_boss, 370, 250, 2, 2000, 20, 50);
		}
		//��ʼ���߽����ϰ�
		{
			bricks_permanent *brick1 = Create_bricks_permanent(bmp_bricks, 0, 0, EDGE_LENGTH, WINDOW_HEIGHT - 105, 0);
			bricks_permanent *brick2 = Create_bricks_permanent(bmp_bricks, 0, 0, WINDOW_WIDTH, EDGE_LENGTH, 0);
			bricks_permanent *brick3 = Create_bricks_permanent(bmp_bricks, 0, WINDOW_HEIGHT - 115, WINDOW_WIDTH, EDGE_LENGTH, 0);
			bricks_permanent *brick4 = Create_bricks_permanent(bmp_bricks, WINDOW_WIDTH - 25, 0, EDGE_LENGTH, WINDOW_HEIGHT - 105, 0);
			brick_p.push_back(brick1);
			brick_p.push_back(brick2);
			brick_p.push_back(brick3);
			brick_p.push_back(brick4);
			bricks_permanent *brick= Create_bricks_permanent(bmp_bricks, 350, 460, 50, 40, 0);
			brick_p.push_back(brick);
			brick= Create_bricks_permanent(bmp_bricks,550 , 350, 40, 40, 0);
			brick_p.push_back(brick);
			brick=Create_bricks_permanent(bmp_bricks, 150, 350, 40, 40, 0);
			brick_p.push_back(brick);
		}
		previous_stage = stageID;
	}
	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}
#pragma endregion


#pragma region ���ÿ⺯��
//2�ļ��η�����
int two(int i)
{
	int t = 1, j;
	for (j = 1; j <= i; j++) t = t * 2;
	return t;
}
//��ת����
void turn(double* vx, double* vy, double angle)
{
	*vx = cos(angle)*(*vx) + sin(angle)*(*vx);
	*vy = -sin(angle)*(*vy) + cos(angle)*(*vy);
}
//�ж��Ƿ��ཻ����
int judge_cross(int a_x, int a_y, int a_width, int a_height, int b_x, int b_y, int b_width, int b_height)
{
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0;
	if (a_x < b_x + b_width&&a_x > b_x&&a_y < b_y + b_height&&a_y > b_y) p1 = 1;
	if (a_x + a_width < b_x + b_width&&a_x + a_width > b_x&&a_y + a_height < b_y + b_height&&a_y + a_height > b_y) p2 = 1;
	if (a_x < b_x + b_width&&a_x > b_x&&a_y + a_height < b_y + b_height&&a_y + a_height > b_y) p3 = 1;
	if (a_x + a_width < b_x + b_width&&a_x + a_width > b_x&&a_y < b_y + b_height&&a_y > b_y) p4 = 1;
	if (b_x < a_x + a_width&&b_x > a_x&&b_y < a_y + a_height&&b_y > a_y) p5 = 1;
	if (b_x + b_width <a_x + a_width&&b_x + b_width > a_x&&b_y + b_height < a_y + a_height&&b_y + b_height > a_y) p6 = 1;
	if (b_x < a_x + a_width&&b_x >a_x&&b_y + b_height < a_y + a_height&&b_y + b_height > a_y) p7 = 1;
	if (b_x + b_width < a_x + a_width&&b_x + b_width > a_x&&b_y < a_y + a_height&&b_y > a_y) p8 = 1;
	if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0 && p7 == 0 && p8 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//�ж����������Ƿ��ཻ
int judge_line(int a_x, int a_y, int b_x, int b_y, int num)
{
	double vx, vy;
	Calculate_Velocity(&vx, &vy, 30, a_x, a_y, b_x, b_y);
	int distance = sqrt((a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y));
	int j = 0;
	while (j <= distance)
	{
		int i;
		int x = a_x + vx*j; int y = a_y + vy*j;
		for (i = 4; i < brick_p.size(); i++)
		{
			bricks_permanent* p = brick_p[i];
			if (judge_cross(x, y, 0, 0, p->x, p->y, p->width, p->height)) return 1;
		}
		for (i = 0; i < brick_b.size(); i++)
		{
			bricks_breakable *p = brick_b[i];
			if (judge_cross(x, y, 0,0, p->x, p->y, p->width, p->height)) return 1;
		}
		for (i = 0; i < soldier_r.size(); i++)
		{
			if (i != num)
			{
				Soldier_Ranged *p = soldier_r[i];
				if (judge_cross(x, y, AMMO_SIZE_X, AMMO_SIZE_Y, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y)) return 1;
			}
				
		}
		j += 1;
	}
	return 0;
}
//������ٶȺ���
void Calculate_Velocity(double* ptrx, double* ptry, int v, int currentx, int currenty, int mx, int my)
{
	double dx = mx - currentx, dy = my - currenty;
	double d = sqrt(dx*dx + dy*dy);
	double vx, vy;
	double porpx = dx / d; double porpy = dy / d;
	vx = v*porpx; vy = v*porpy;
	*ptrx = vx; *ptry = vy;
}
#pragma endregion


#pragma region ���ǿ�������º���
// �������ǵĵ�ǰ֡��
int GetHeroFrame(double dirX, double dirY)
{
	double dirLen = sqrt(dirX * dirX + dirY * dirY);
	if (dirLen == 0)return 0;
	double cos = -dirY / dirLen;
	double arc = acos(cos);
	if (dirX < 0)arc = 2 * PI - arc;

	int frame = (int)((arc + PI / HERO_FRAME_NUMBER) / (2 * PI / HERO_FRAME_NUMBER));
	if (frame == HERO_FRAME_NUMBER)frame = 0;
	return frame;
}
// ˢ������״̬����
void UpdateHero(HWND hWnd)
{

	if (theHero != NULL) {
		theHero->maxspeed = theHero->position.maxspeed;
		theHero->accleration = theHero->position.accleration;
		theHero->invincible = 0;
		theHero->paralyzed = 0;
		theHero->charging = 0;
		theHero->sneathed = 0;
		//�����ж�
		{
			if (theHero->exp >= exp_require[theHero->level] && theHero->level<10)
			{
				theHero->exp -= exp_require[theHero->level];
				theHero->level++;
				theHero->health_max += theHero->position.health_improve;
				theHero->force_max += force_improve;
				theHero->melee_attack += theHero->position.attack_improve;
			}
		}
		//�����ж�
		{
			static int i = 0;
			i++;
			if (i == 5)
			{
				if (theHero->force_current < theHero->force_max) theHero->force_current++;
				i = 0;
			}
		}
		//�����ж�
		{
			if (theHero->position.num == 1 && skill1 == 1)
			{
				shield();
			}
			if (theHero->position.num == 1 && skill2 == 1)
			{
				charge();
			}
			if (theHero->position.num == 2 && skill1 == 1)
			{
				paralyze();
			}
			if (theHero->position.num == 2 && skill2 == 1)
			{
				bomb();
			}
			if (theHero->position.num == 3 && skill1 == 1)
			{
				sneath();
			}
			if (theHero->position.num == 3 && skill2 == 1)
			{
				trap_bomb();
			}
		}
		//�ƶ��ж�
		if (theHero->charging == 0)
		{
			//y�����ٶ�
			if (keyUpDown && !keyDownDown && theHero->vy > -1 * theHero->maxspeed)
				theHero->vy -= theHero->accleration;
			else if (!keyUpDown && keyDownDown && theHero->vy < theHero->maxspeed)
				theHero->vy += theHero->accleration;
			else if (theHero->vy > 0)theHero->vy -= theHero->accleration;
			else if (theHero->vy < 0)theHero->vy += theHero->accleration;

			//x�����ٶ�
			if (keyLeftDown && !keyRightDown && theHero->vx > -1 * theHero->maxspeed)
				theHero->vx -= theHero->accleration;
			else if (!keyLeftDown && keyRightDown && theHero->vx < theHero->maxspeed)
				theHero->vx += theHero->accleration;
			else if (theHero->vx > 0)theHero->vx -= theHero->accleration;
			else if (theHero->vx < 0)theHero->vx += theHero->accleration;

			theHero->x += (int)(theHero->vx);
			theHero->y += (int)(theHero->vy);
		}
		//�ж������Ƿ������ϰ�
		//������1������ཻ�������ж� 2���������������߲��ཻ������������  3����������ϻ����߲��ཻ������������
		{
			for (int i = 0; i < brick_p.size(); i++)
			{
				bricks_permanent* b = brick_p[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height))
				{
					if (judge_cross(theHero->x - theHero->vx, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height) == 0)
					{

						theHero->x -= theHero->vx;
						theHero->vx = 0;
					}
					if (judge_cross(theHero->x, theHero->y - theHero->vy, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height) == 0)
					{
						theHero->y -= theHero->vy;
						theHero->vy = 0;
					}
				}
			}
			for (int i = 0; i < soldier_r.size(); i++)
			{
				Soldier_Ranged* b = soldier_r[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y))
				{
					if (judge_cross(theHero->x - theHero->vx, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y) == 0)
					{

						theHero->x -= theHero->vx;
						theHero->vx = 0;
					}
					if (judge_cross(theHero->x, theHero->y - theHero->vy, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y) == 0)
					{
						theHero->y -= theHero->vy;
						theHero->vy = 0;
					}
					if (theHero->position.num == 3)
					{
						skill1 = 0;
						theHero->sneathed = 0;
					}
				}
			}
			for (int i = 0; i < brick_b.size(); i++)
			{
				bricks_breakable* b = brick_b[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height))
				{
					if (judge_cross(theHero->x - theHero->vx, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height) == 0)
					{

						theHero->x -= theHero->vx;
						theHero->vx = 0;
					}
					if (judge_cross(theHero->x, theHero->y - theHero->vy, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height) == 0)
					{
						theHero->y -= theHero->vy;
						theHero->vy = 0;
					}
				}
			}
			for (int i = 0; i < lasers.size(); i++)
			{
				laser* l = lasers[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, l->x, l->y, l->width, l->height))
				{
					static int p = 0;
					p++;
					if (p == 10)
					{
						p = 0;
						if (theHero->invincible == 0 && theHero->charging == 0)
						{
							theHero->health_current -= l->damage;
						}
					}
					if (theHero->position.num == 3)
					{
						skill1 = 0;
						theHero->sneathed = 0;
					}
				}
			}
			for (int i = 0; i < w_bag.size(); i++)
			{
				weapon_bag* b = w_bag[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y))
				{
					if (b->weapon > theHero->laser_guns)
					{
						theHero->laser_guns = b->weapon;
						int(theHero->ranged_attack) = double(theHero->position.shooting_bonus)*double(laser_guns_attack[theHero->laser_guns]);
						theHero->ammo_max = laser_guns_ammo[theHero->laser_guns];
						theHero->load_time = load_time[theHero->laser_guns];
						b->live = 0;
					}
				}
			}
			for (int i = 0; i < h_bag.size(); i++)
			{
				health_bag*b = h_bag[i];
				if (judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y))
				{
					theHero->health_current = min(theHero->health_current + b->restore, theHero->health_max);
					b->live = 0;
				}
			}
			if (currentStage->stageID == STAGE_BOSS)
			{
				if (boss != NULL&&judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height))
				{
					if (judge_cross(theHero->x - theHero->vx, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height) == 0)
					{

						theHero->x -= theHero->vx;
						theHero->vx = 0;
					}
					if (judge_cross(theHero->x, theHero->y - theHero->vy, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height) == 0)
					{
						theHero->y -= theHero->vy;
						theHero->vy = 0;
					}
				}
				if (computer != NULL&&judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height))
				{
					if (judge_cross(theHero->x - theHero->vx, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) == 0)
					{

						theHero->x -= theHero->vx;
						theHero->vx = 0;
					}
					if (judge_cross(theHero->x, theHero->y - theHero->vy, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) == 0)
					{
						theHero->y -= theHero->vy;
						theHero->vy = 0;
					}
				}
			}
		}
		//֡���ж�
		{
			int centerX = theHero->x + HERO_SIZE_X / 2;
			int centerY = theHero->y + HERO_SIZE_Y / 2;

			double dirX = mouseX - centerX;
			double dirY = mouseY - centerY;
			theHero->frame = GetHeroFrame(dirX, dirY);
		}

	}
}
//�����������
void Hero_Shoot()
{
	if (currentStage->stageID >= STAGE_1&&currentStage->stageID <= STAGE_BOSS)
	{
		if (theHero->ammo_current == 0)
		{
			static int i = 0;
			i++;
			if (i == 150)
			{
				theHero->ammo_current = theHero->ammo_max;
				i = 0;
			}
		}
		else
		{
			static int t = 0;
			t++;
			if (t == 10) t = 0;
			if (mouseLeftDown == true && t == 0)
			{
				if (theHero->position.num == 1)
				{
					skill1 = 0;
					theHero->invincible = 0;
				}
				if (theHero->position.num == 3)
				{
					skill1 = 0;
					theHero->sneathed = 0;
				}
				double vx, vy;
				Calculate_Velocity(&vx, &vy, 30, theHero->x, theHero->y, mouseX, mouseY);
				if (theHero->paralyzed == 1)
				{
					ammo* am = Create_ammo(bmp_ammo_paralyze, theHero->x + 16, theHero->y + 16, theHero->ranged_attack / 3, vx, vy, 2);
					theHero->force_current -= 10;
					ammos.push_back(am);
				}
				else
				{
					ammo* am = Create_ammo(bmp_ammo_Hero, theHero->x + 16, theHero->y + 16, theHero->ranged_attack, vx, vy, 1);
					ammos.push_back(am);
				}
				theHero->ammo_current--;
			}
		}
	}
}
//��ս����
void Melee_Attack()
{
	if (currentStage->stageID >= STAGE_1&&currentStage->stageID <= STAGE_BOSS)
	{
		if (theHero->position.num == 1)
		{
			skill1 = 0;
			theHero->invincible = 0;
		}
		if (theHero->position.num == 3)
		{
			skill1 = 0;
			theHero->sneathed = 0;
		}
		double dx, dy;
		Calculate_Velocity(&dx, &dy, 1, theHero->x, theHero->y, mouseX, mouseY);
		melee_attack* ml = Create_melee_attack(bmp_melee_attack, 0, theHero->x + dx*HERO_SIZE_X, theHero->y + dy*HERO_SIZE_Y, theHero->melee_attack, 1);
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;

		double dirX = mouseX - centerX;
		double dirY = mouseY - centerY;
		ml->frame = GetHeroFrame(dirX, dirY);
		attack_melee.push_back(ml);
	}
}
#pragma region ���Ǽ��ܺ���
//սʿ����1������
void shield()
{
	if (theHero->vx != 0 || theHero->vy != 0||theHero->force_current<=0)
	{
		theHero->invincible = 0;
		skill1 = 0;
		return;
	}
	theHero->invincible = 1;
	static int i = 0;
	i++;
	if (i == 3)
	{
		theHero->force_current--;
		i = 0;
	}
}
//սʿ����2�����
void charge()
{
	static int i = 0, init = 0;
	if (theHero->force_current >= 40&i==0)
	{
		theHero->force_current -= 40;
		i = 1;
	}
	if (i == 1)
	{
		theHero->charging = 1;
		if (init == 0)
		{
			Calculate_Velocity(&theHero->vx, &theHero->vy, theHero->maxspeed, theHero->x, theHero->y, mouseX, mouseY);
		}
		init = 1;
		for (int j = 1; j <= 6; j++)
		{
			theHero->x += int(theHero->vx);
			theHero->y += int(theHero->vy);
			int distance = int(sqrt((theHero->vx - mouseX)*(theHero->vx - mouseX) + (theHero->vy - mouseY)*(theHero->vy - mouseY)));
			if (judge_soldier(theHero->x,theHero->y, -1)||distance<=20)
			{
				theHero->x -= int(theHero->vx);
				theHero->y -= int(theHero->vy);
				for (int k = 0; k < brick_b.size(); k++)
				{
					bricks_breakable *p = brick_b[k];
					if (judge_cross(theHero->x-16, theHero->y-16, 2*HERO_SIZE_X, 2*HERO_SIZE_Y, p->x, p->y, p->width, p->height)) p->health_current-=30;
				}
				for (int k = 0; k < soldier_r.size(); k++)
				{
					Soldier_Ranged *p = soldier_r[k];
					if (judge_cross(theHero->x - 16, theHero->y - 16, 2 * HERO_SIZE_X, 2 * HERO_SIZE_Y, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y)) p->health_current -= 30;
				}
				if (currentStage->stageID == STAGE_BOSS)
				{
					if (boss != NULL&&judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, BOSS_SIZE, BOSS_SIZE))
					{
						boss->health_current -= 30;
					}
					if (boss == NULL&&computer != NULL&&judge_cross(theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, COMPUTER_SIZE_X, COMPUTER_SIZE_Y))
					{
						computer->health_current -= 30;
					}
				}
				i = 0;
				init = 0;
				theHero->charging = 0;
				theHero->vx = 0; theHero->vy = 0;
				skill2 = 0;
				return;
			}
		}
	}

	
}
//Զ�̼���1��������ѣ���ӵ�
void paralyze()
{
	if (theHero->force_current >= 10)
	{
		theHero->paralyzed = 1;
	}
}
//Զ�̼���2����λ��
void bomb()
{
	if (theHero->force_current >= 40)
	{
		theHero->force_current -= 40;
		bombard* b = Create_bombs(bmp_bomb_place, mouseX-50, mouseY-50, theHero->ranged_attack*3, 1, 0, currentStage->timeCountDown,100,100,100);
		Bombs.push_back(b);
	}
	skill2 = 0;
}
//�������1������
void sneath()
{
	if (theHero->vx != 0 || theHero->vy != 0 || theHero->force_current <= 0)
	{
		theHero->sneathed = 0;
		skill1 = 0;
		return;
	}
	theHero->sneathed = 1;
	static int i = 0;
	i++;
	if (i == 3)
	{
		theHero->force_current--;
		i = 0;
	}
}
//�������2������ը��
void trap_bomb()
{
	if (theHero->force_current >= 30)
	{
		theHero->force_current -= 30;
		bombard* b = Create_bombs(bmp_bomb, theHero->x, theHero->y, theHero->ranged_attack*4, 2, 0, currentStage->timeCountDown, 100, HERO_SIZE_X, HERO_SIZE_Y);
		Bombs.push_back(b);
	}

	skill2 = 0;
}
#pragma endregion
#pragma endregion


#pragma region ״̬�������������
//ˢ���ӵ�����
void UpdateAmmos(HWND hWnd)
{
	int i, j;
	for (i = 0; i < ammos.size(); i++)
	{
		ammo* a = ammos[i];
		a->x += (int)a->vx;
		a->y += (int)a->vy;
		for (j = 0; j < brick_p.size(); j++)
		{
			bricks_permanent* b = brick_p[j];
			if (judge_cross(a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y, b->x, b->y, b->width, b->height) && a->live == 1)
			{
				a->live = 0;
				break;
			}
		}
		for (j = 0; j < brick_b.size(); j++)
		{
			bricks_breakable* b = brick_b[j];
			if (judge_cross(a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y, b->x, b->y, b->width, b->height) && a->live == 1)
			{
				a->live = 0;
				b->health_current -= a->damage;
				break;
			}
		}
		if (a->side == 1)
		{
			for (j = 0; j < soldier_r.size(); j++)
			{
				Soldier_Ranged* b = soldier_r[j];
				if (judge_cross(a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y) && a->live == 1)
				{

					b->health_current = b->health_current - a->damage;
					a->live = 0;
					break;
				}
			}
			if (currentStage->stageID == STAGE_BOSS)
			{
				if (computer != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) && a->live == 1 && boss == NULL)
				{
					computer->health_current -= a->damage;
					a->live = 0;
				}
				if (boss != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height) && a->live == 1)
				{
					boss->health_current -= a->damage;
					a->live = 0;
				}
			}
		}
		if (a->side == 2)
		{
			for (j = 0; j < soldier_r.size(); j++)
			{
				Soldier_Ranged* b = soldier_r[j];
				if (judge_cross(a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y) && a->live == 1)
				{
					b->paralyzed = 1;
					b->paralyzed_time = currentStage->timeCountDown;
					b->health_current = b->health_current - a->damage;
					a->live = 0;
					break;
				}
			}
			if (currentStage->stageID == STAGE_BOSS)
			{
				if (computer != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) && a->live == 1 && boss == NULL)
				{
					computer->health_current -= a->damage;
					a->live = 0;
				}
				if (boss != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height) && a->live == 1)
				{
					boss->paralyzed = 1;
					boss->paralyzed_time = currentStage->timeCountDown;
					boss->health_current -= a->damage;
					a->live = 0;
				}
			}
		}
		if (a->side == 0)
		{
			if (judge_cross(a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y) && a->live == 1)
			{
				if (theHero->invincible == 0 && theHero->charging == 0)
				{
					theHero->health_current = theHero->health_current - a->damage;
					if (theHero->position.num == 3)
					{
						skill1 = 0;
						theHero->sneathed = 0;
					}
				}
				a->live = 0;
				break;
			}
			if (currentStage->stageID == STAGE_BOSS)
			{
				if (computer != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) && a->live == 1 && boss == NULL)
				{
					a->live = 0;
				}
			}
		}
	}

}
//��ը����
void explode(int x, int y, int width, int height, int damage)
{
	mciSendString(_T("open explode.wav alias exp"), NULL, 0, NULL);
	mciSendString(_T("play exp"), NULL, 0, NULL);
	explodetm = 0;
	Flame* a = Create_flame(x, y);
	flms.push_back(a);
	for (int i = 0; i < brick_b.size(); i++)
	{
		bricks_breakable *p = brick_b[i];
		if (judge_cross(x, y, width, height, p->x, p->y, p->width, p->height))
		{
			p->health_current -= damage;
		}
	}
	for (int i = 0; i < soldier_r.size(); i++)
	{
		Soldier_Ranged *p = soldier_r[i];
		if (judge_cross(x, y, width, height, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y))
		{
			p->health_current -= damage;
		}
	}
	if (currentStage->stageID == STAGE_BOSS)
	{
		if (computer != NULL&&judge_cross(x, y, width, height, computer->x, computer->y, computer->width, computer->height) && boss == NULL)
		{
			computer->health_current -= damage;
		}
		if (boss != NULL&&judge_cross(x, y, width, height, boss->x, boss->y, boss->width, boss->height))
		{
			boss->health_current -= damage;
		}
	}
	if (judge_cross(x, y, width, height, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y) && theHero->invincible == 0)
	{
		theHero->health_current -= damage;
		if (theHero->position.num == 3)
		{
			skill1 = 0;
			theHero->sneathed = 0;
		}
	}

}
// ˢ��ը������
void UpdateBombs(HWND hwnd)
{
	int i;
	for (i = 0; i < Bombs.size(); i++)
	{
		bombard* b = Bombs[i];
		if (b->type == 1 && b->live == 1)
		{
			if (b->time - currentStage->timeCountDown >= 50)
			{
				explode(b->x, b->y, b->range, b->range, b->damage);
				b->live = 0;
			}
		}
		else if (b->type == 2 && b->live == 1)
		{
			for (int j = 0; j < soldier_r.size(); j++)
			{
				Soldier_Ranged *p = soldier_r[j];
				if (judge_cross(b->x, b->y, b->width, b->height, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y) && b->time - currentStage->timeCountDown >= 50)
				{
					explode(b->x, b->y, b->range, b->range, b->damage);
					b->live = 0;
				}
			}
			if (boss != NULL&&judge_cross(b->x, b->y, b->width, b->height, boss->x, boss->y, BOSS_SIZE, BOSS_SIZE) && b->time - currentStage->timeCountDown >= 50)
			{
				explode(b->x, b->y, b->range, b->range, b->damage);
				b->live = 0;
			}
		}
		/*else if (b->type == 3 && b->live == 1)
		{
			//�ж��Ƿ��ཻ
			{
				if (judge_cross(b->x, b->y, b->width, b->height, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y)) b->live = 0;
				for (i = 0; i < ammos.size(); i++)
				{
					ammo* a = ammos[i];
					if (a->live == 1 && a->side > 0 && judge_cross(b->x, b->y, b->width, b->height, a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y))
					{
						a->live = 0;
						b->live = 0;
					}
				}
			}
			if (b->live == 0)
			{
				explode(b->x, b->y, b->range, b->range, b->damage);
			}
			else
			{
				
				Calculate_Velocity(&b->vx, &b->vy, 5, b->x, b->y, theHero->x, theHero->y);
				b->x = b->x + int(b->vx);
				b->y = b->y + int(b->vy);
			}
		}*/
	}
}
//ˢ�µ�������
void UpdateMissiles(HWND hwnd)
{
	int i;
	for (i = 0; i < Missiles.size(); i++)
	{
		missile* b = Missiles[i];
		if (b->live == 1)
		{
			//�ж��Ƿ��ཻ
			{
				if (judge_cross(b->x, b->y, b->width, b->height, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y)) b->live = 0;
				for (i = 0; i < ammos.size(); i++)
				{
					ammo* a = ammos[i];
					if (a->live == 1 && a->side > 0 && judge_cross(b->x, b->y, b->width, b->height, a->x, a->y, AMMO_SIZE_X, AMMO_SIZE_Y))
					{
						a->live = 0;
						b->live = 0;
					}
				}
			}
			if (b->live == 0)
			{
				explode(b->x, b->y, b->range, b->range, b->damage);
			}
			else
			{

				Calculate_Velocity(&b->vx, &b->vy, 5, b->x, b->y, theHero->x, theHero->y);
				b->x = b->x + int(b->vx);
				b->y = b->y + int(b->vy);
			}
		}
	}
}
//ˢ�½�ս��������
void UpdateMeleeAttack(HWND hWnd)
{
	int i, j;
	for (i = 0; i < attack_melee.size(); i++)
	{
		melee_attack* a = attack_melee[i];
		for (j = 0; j < brick_b.size(); j++)
		{
			bricks_breakable* b = brick_b[j];
			if (judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, b->width, b->height) && a->live == 1)
			{
				b->health_current = b->health_current - a->damage;
				a->live = 0;
				break;
			}
		}
		for (j = 0; j < soldier_r.size(); j++)
		{
			Soldier_Ranged* b = soldier_r[j];
			if (judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, b->x, b->y, HERO_SIZE_X, HERO_SIZE_Y) && a->live == 1)
			{
				b->health_current = b->health_current - a->damage;
				a->live = 0;
				break;
			}
		}
		if (currentStage->stageID == STAGE_BOSS)
		{
			if (computer != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, computer->width, computer->height) && a->live == 1 && boss == NULL)
			{
				computer->health_current -= a->damage;
				a->live = 0;
			}
			if (boss != NULL&&judge_cross(a->x, a->y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, boss->width, boss->height) && a->live == 1)
			{
				boss->health_current -= a->damage;
				a->live = 0;
			}
		}
		a->timespan--;
		if (a->timespan <= 0)   a->live = 0;
	}
}
//�жϼ���������
int judge_laser(int x, int y, int w, int h)
{
	if (judge_cross(x, y, w, h, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y)) return 1;
	int i;
	for (i = 0; i < brick_p.size(); i++)
	{
		bricks_permanent* p = brick_p[i];
		if (judge_cross(x + 1, y + 1, w, h, p->x, p->y, p->width, p->height)) return 1;
	}
	for (i = 0; i < brick_b.size(); i++)
	{
		bricks_breakable *p = brick_b[i];
		if (judge_cross(x + 1, y + 1, w, h, p->x, p->y, p->width, p->height)) return 1;
	}
	for (i = 0; i < soldier_r.size(); i++)
	{
		Soldier_Ranged *p = soldier_r[i];
		if (judge_cross(x + 1, y + 1, w, h, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y)) return 1;
	}
	return 0;
}
//ˢ�¼���������
void UpdateLasers(HWND hWnd)
{
	int i;
	for (i = 0; i < lasers.size(); i++)
	{
		laser* l = lasers[i];
		if (l->direction == 1)
		{

			int dx = 5;
			while (1)
			{
				if (judge_laser(l->x, l->y, dx, 20)) break;
				dx = dx + 5;
			}
			l->width = dx;
		}
		if (l->direction == 2)
		{
			int dy = 5;
			while (1)
			{
				if (judge_laser(l->x, l->y, 20, dy)) break;
				dy = dy + 5;
			}
			l->height = dy;
		}
	}
}
//ˢ�»��溯��
void UpdateFlames(HWND hWnd)
{
	int i;
	for (i = 0; i < flms.size(); i++)
	{
		Flame* a = flms[i];
		if (a->live == 1)
		{
			if (a->time - currentStage->timeCountDown >= 30) a->live = 0;
			else if (a->time - currentStage->timeCountDown <= 5 || a->time - currentStage->timeCountDown >= 25 ||
				(a->time - currentStage->timeCountDown >= 13 && a->time - currentStage->timeCountDown <= 18)
				) a->img = bmp_flame1;
			else a->img = bmp_flame2;
		}
	}
}
//���״̬����
void UpdateDeath(HWND hWnd)
{
	int i, r, wp;
	for (i = 0; i < brick_b.size(); i++)
	{
		bricks_breakable* a = brick_b[i];
		if (a->health_current <= 0)
		{
			srand((unsigned)time(NULL));
			r = rand();
			if (r % 6 == 1 || r % 6 == 2)
			{
				Create_health_bag(bmp_Health_Bag, a->x, a->y);
			}
			else if (r % 6 == 4)
			{
				wp = get_random_weapon();
				Create_weapon_bag(bmp_Weapon_Bag, a->x, a->y, wp);
			}
			brick_b.erase(brick_b.begin() + i);
		}
	}
	for (i = 0; i < soldier_r.size(); i++)
	{
		Soldier_Ranged* a = soldier_r[i];
		if (a->health_current <= 0)
		{
			theHero->exp += EXP_GET;
			srand((unsigned)time(NULL));
			r = rand();
			if (r % 6 == 1 || r % 6 == 2)
			{
				health_bag* b = Create_health_bag(bmp_Health_Bag, a->x, a->y);
				h_bag.push_back(b);
			}
			else if (r % 6 == 4)
			{
				wp = get_random_weapon();
				weapon_bag* b = Create_weapon_bag(bmp_Weapon_Bag, a->x, a->y, wp);
				w_bag.push_back(b);
			}
			soldier_r.erase(soldier_r.begin() + i);
		}
	}
	for (i = 0; i < ammos.size(); i++)
	{
		ammo* a = ammos[i];
		if (a->live == 0) ammos.erase(ammos.begin() + i);
	}
	for (i = 0; i < attack_melee.size(); i++)
	{
		melee_attack* a = attack_melee[i];
		if (a->live == 0) attack_melee.erase(attack_melee.begin() + i);
	}
	for (i = 0; i < h_bag.size(); i++)
	{
		health_bag* a = h_bag[i];
		if (a->live == 0) h_bag.erase(h_bag.begin() + i);
	}
	for (i = 0; i < w_bag.size(); i++)
	{
		weapon_bag* a = w_bag[i];
		if (a->live == 0) w_bag.erase(w_bag.begin() + i);
	}
	for (i = 0; i < Bombs.size(); i++)
	{
		bombard* a = Bombs[i];
		if (a->live == 0) Bombs.erase(Bombs.begin() + i);
	}
	for (i = 0; i < Missiles.size(); i++)
	{
		missile* a = Missiles[i];
		if (a->live == 0) Missiles.erase(Missiles.begin() + i);
	}
	for (i = 0; i < flms.size(); i++)
	{
		Flame* a = flms[i];
		if (a->live == 0) flms.erase(flms.begin() + i);
	}
	if (theHero->health_current <= 0)
	{
		theHero->laser_guns = 1;
		theHero->health_max = theHero->position.health_max;
		theHero->stamina_max = theHero->position.stamina_max;
		theHero->force_max = theHero->position.force_max;
		theHero->melee_attack = theHero->position.melee_attack;
		theHero->maxspeed = theHero->position.maxspeed;
		theHero->accleration = theHero->position.accleration;
		int(theHero->ranged_attack) = double(theHero->position.shooting_bonus)*double(laser_guns_attack[theHero->laser_guns]);
		theHero->ammo_max = laser_guns_ammo[theHero->laser_guns];
		theHero->load_time = load_time[theHero->laser_guns];
		theHero->exp = 0;
		theHero->level = 0;
		InitStage(hWnd, STAGE_LOSE, 0);
	}
	if (currentStage->stageID >= STAGE_1 &&currentStage->stageID <= STAGE_5)
	{
		if (soldier_r.size() == 0) InitStage(hWnd, STAGE_WIN, 0);
	}
	if (currentStage->stageID == STAGE_BOSS)
	{
		if (boss != NULL&&boss->health_current <= 0)
		{
			health_bag* b = Create_health_bag(bmp_Health_Bag, boss->x, boss->y);
			h_bag.push_back(b);
			b = Create_health_bag(bmp_Health_Bag, boss->x + 30, boss->y + 30);
			h_bag.push_back(b);
			b = Create_health_bag(bmp_Health_Bag, boss->x - 30, boss->y - 30);
			h_bag.push_back(b);
			b = Create_health_bag(bmp_Health_Bag, boss->x - 30, boss->y + 30);
			h_bag.push_back(b);
			weapon_bag* b1 = Create_weapon_bag(bmp_Weapon_Bag, boss->x + 30, boss->y - 30, 5);
			w_bag.push_back(b1);
			theHero->exp += 300;
			boss = NULL;
		}
		if (computer != NULL&&computer->health_current <= 0) computer = NULL;
		if (computer == NULL)InitStage(hWnd, STAGE_WIN, 0);
	}
}
//���������������
int get_random_weapon()
{
	int wp, r1;
	srand((unsigned)time(NULL));
	r1 = rand() % 20;
	if (r1 <= 2) wp = 1;
	else if (r1 <= 7) wp = 2;
	else if (r1 <= 15) wp = 3;
	else if (r1 <= 18) wp = 4;
	else wp = 5;
	return wp;
}
#pragma endregion


#pragma region AI��������º���
//�ж�С������
int judge_soldier(int x, int y, int num)
{
	int i;
	for (i = 0; i < brick_p.size(); i++)
	{
		bricks_permanent* p = brick_p[i];
		if (judge_cross(x, y, HERO_SIZE_X, HERO_SIZE_Y, p->x, p->y, p->width, p->height)) return 1;
	}
	for (i = 0; i < brick_b.size(); i++)
	{
		bricks_breakable *p = brick_b[i];
		if (judge_cross(x, y, HERO_SIZE_X, HERO_SIZE_Y, p->x, p->y, p->width, p->height)) return 1;
	}
	for (i = 0; i < soldier_r.size(); i++)
	{
		if (i != num)
		{
			Soldier_Ranged *p = soldier_r[i];
			if (judge_cross(x, y, HERO_SIZE_X, HERO_SIZE_Y, p->x, p->y, HERO_SIZE_X, HERO_SIZE_Y)) return 1;
		}
	}
	if (currentStage->stageID == STAGE_BOSS)
	{
		if (boss != NULL&&judge_cross(x, y, HERO_SIZE_X, HERO_SIZE_Y, boss->x, boss->y, BOSS_SIZE, BOSS_SIZE)) return 1;
		if (computer != NULL&&judge_cross(x, y, HERO_SIZE_X, HERO_SIZE_Y, computer->x, computer->y, COMPUTER_SIZE_X, COMPUTER_SIZE_Y))	return 1;
	}
	return 0;
}
//�ж�boss����
int judge_boss(int x, int y)
{
	int i;
	for (i = 0; i < brick_p.size(); i++)
	{
		bricks_permanent* p = brick_p[i];
		if (judge_cross(x - 40, y - 40, BOSS_SIZE + 80, BOSS_SIZE + 80, p->x, p->y, p->width, p->height)) return 1;
	}
	if (judge_cross(x, y, BOSS_SIZE, BOSS_SIZE, theHero->x, theHero->y, HERO_SIZE_X, HERO_SIZE_Y)) return 1;
	if (judge_cross(x - 40, y - 40, BOSS_SIZE + 80, BOSS_SIZE + 80, computer->x, computer->y, COMPUTER_SIZE_X, COMPUTER_SIZE_Y)) return 1;
	return 0;
}
//ˢ��С��״̬����
void UpdateSoldier(HWND hWnd)
{
	int i, j;
	blk blks[5] = { { 80,550,0,0 },{ 220,550,0,0 },{ 400,550,0,0 },{ 550,550,0,0 },{ 700,550,0,0 } };
	if (currentStage->stageID == STAGE_BOSS)
	{
		if (boss == NULL&&soldier_r.size() <= 2)
		{
			static int i = 0;
			Soldier_Ranged*s = Create_Soldier_Ranged(bmp_Soldier_Melee, blks[i].x, blks[i].y);
			s->whether = 1;
			soldier_r.push_back(s);
			i++;
			if (i == 5) i = 0;
		}
	}
	for (i = 0; i < soldier_r.size(); i++)
	{
		Soldier_Ranged* s = soldier_r[i];
		if (s->paralyzed == 1)
		{
			s->vx = 0; s->vy = 0;
			if (s->paralyzed_time - currentStage->timeCountDown >= 200) s->paralyzed = 0;
		}
		else
		{
			int distance = sqrt((s->x - theHero->x)*(s->x - theHero->x) + (s->y - theHero->y)*(s->y - theHero->y));
			int vx[8] = { 2,1,0,-1,-2,-1,0,1 };
			int vy[8] = { 0,1,2,1,0,-1,-2,-1 };
			if (judge_line(s->x, s->y, theHero->x, theHero->y, i) == 0)
			{
				s->whether = 1;
			}
			if (theHero->sneathed == 1)
			{
				s->whether = 0;
			}
			//Ѱ·����
			{
				if (s->whether == 1 && distance >= 50)
				{
					Calculate_Velocity(&s->vx, &s->vy, s->speed, s->x, s->y, theHero->x, theHero->y);
					int j = 0;
					if (judge_soldier(s->x + int(2.0 * s->vx), s->y + int(2.0 * s->vy), i))
					{
						srand((unsigned)time(NULL));
						int begin = (rand() + i * 3) % 8;
						for (j = 0; j <= 7; j++)
						{
							s->vx = s->speed*vx[(j + begin) % 8] / 2;
							s->vy = s->speed*vy[(j + begin) % 8] / 2;
							if (judge_soldier(s->x + int(2.0 * s->vx), s->y + int(2.0 * s->vy), i) == 0) break;
						}
						if (judge_soldier(s->x + int(2.0 * s->vx), s->y + int(2.0 * s->vy), i))
						{
							s->x = s->x - int(s->vx); s->y = s->y - int(s->vy);
							s->vx = 0; s->vy = 0;
						}
					}

					s->x = s->x + int(s->vx); s->y = s->y + int(s->vy);
				}
				else if (s->whether == 1 && distance < 50 && judge_line(s->x, s->y, theHero->x, theHero->y, i) == 0)
				{
					s->vx = 0; s->vy = 0;
				}
				else
				{
					int j = 0;
					srand((unsigned)time(NULL));
					int begin = (rand() + i * 3) % 8;
					s->vx = s->speed*vx[(begin) % 8] / 4;
					s->vy = s->speed*vy[(begin) % 8] / 4;
					if (judge_soldier(s->x + int(4.0*s->vx), s->y + int(4.0*s->vy), i))
					{
						for (j = 0; j <= 7; j++)
						{
							s->vx = s->speed*vx[(j + begin) % 8] / 4;
							s->vy = s->speed*vy[(j + begin) % 8] / 4;
							if (judge_soldier(s->x + int(4.0*s->vx), s->y + int(4.0*s->vy), i) == 0) break;
						}
						if (judge_soldier(s->x + int(4.0*s->vx), s->y + int(4.0*s->vy), i))
						{
							s->vx = 0; s->vy = 0;
						}
					}
					s->x = s->x + int(s->vx); s->y = s->y + int(s->vy);
				}
				//����С��֡��
				if (s->vx != 0 || s->vy != 0)
				{
					double dirX = s->vx;
					double dirY = s->vy;
					s->frame = GetHeroFrame(dirX, dirY);
				}
			}
			//�������
			if (judge_line(s->x, s->y, theHero->x, theHero->y, i) == 0 && distance <= 500 && s->whether == 1)
			{
				s->load_time -= 0.05;
				if (s->load_time <= 0.1)
				{
					s->load_time = load_time[3];
					double vx, vy;
					Calculate_Velocity(&vx, &vy, 20, s->x, s->y, theHero->x, theHero->y);
					ammo* am = Create_ammo(bmp_ammo_Enemy, s->x + 16, s->y + 16, s->ranged_attack, vx, vy, 0);
					ammos.push_back(am);
					//s->ammo_current--;
				}
			}
			/*for (int i = 0; i < lasers.size(); i++)
			{
			laser* l = lasers[i];
			if (judge_cross(s->x, s->y, HERO_SIZE_X, HERO_SIZE_Y, l->x, l->y, l->width, l->height))
			{
			static int p = 0;
			p++;
			if (p == 10)
			{
			p = 0;
			s->health_current -= l->damage / 5;
			}
			}
			}
			*/
		}
	}
}
//ˢ��BOSS״̬����
void UpdateBoss(HWND hWnd)
{
	if (currentStage->timeCountDown % 200 == 0)
	{
		boss->state++;
		if (boss->state == 5) boss->state = 1;
	}
	if (judge_line(boss->x, boss->y, theHero->x, theHero->y, -1) == 0)
	{
		boss->detect = 1;

	}
	if (theHero->sneathed == 1)
	{
		boss->detect = 0;
	}
	if (boss->detect == 0)
	{
		boss->state = 1;
	}
	else
	{
		int centerX = theHero->x + HERO_SIZE_X / 2; int centerY = theHero->y + HERO_SIZE_Y / 2;
		double dirX = centerX - (boss->x + BOSS_SIZE / 2);
		double dirY = centerY - (boss->y + BOSS_SIZE / 2);
		boss->frame = GetHeroFrame(dirX, dirY);
	}
	if (boss->paralyzed == 1)
	{
		boss->damage_bullet = 10;
		boss->damage_cannon = 25;
		if (boss->paralyzed_time - currentStage->timeCountDown >= 200)
		{
			boss->paralyzed = 0;
			boss->damage_bullet = 20;
			boss->damage_cannon = 50;
		}
	}
	//Ѱ·
	if (boss->paralyzed == 0)
	{
		int vx[8] = { 2,1,0,-1,-2,-1,0,1 };
		int vy[8] = { 0,1,2,1,0,-1,-2,-1 };
		int j = 0;
		srand((unsigned)time(NULL));
		int begin = rand() % 8;
		boss->vx = boss->speed*vx[(begin) % 8] / 4;
		boss->vy = boss->speed*vy[(begin) % 8] / 4;
		if (judge_boss(boss->x + int(boss->vx), boss->y + int(boss->vy)))
		{
			for (j = 0; j <= 7; j++)
			{
				boss->vx = boss->speed*vx[(j + begin) % 8] / 4;
				boss->vy = boss->speed*vy[(j + begin) % 8] / 4;
				if (judge_boss(boss->x + int(boss->vx), boss->y + int(boss->vy)) == 0) break;
			}
			if (judge_boss(boss->x + int(boss->vx), boss->y + int(boss->vy)))
			{
				boss->vx = 0; boss->vy = 0;
			}
		}
		boss->x = boss->x + int(boss->vx); boss->y = boss->y + int(boss->vy);
	}
	//����׷���ڵ�
	if (boss->state == 3&&theHero->position.num!=3)
	{

		if (currentStage->timeCountDown % 100 == 0)
		{
			double vx, vy;
			Calculate_Velocity(&vx, &vy, 5, boss->x + 32, boss->y + 32, theHero->x, theHero->y);
			missile* b = Create_missiles(bmp_missile, boss->x + 32, boss->y + 32, boss->damage_cannon, 3, 10, currentStage->timeCountDown, 40, MISSILE_SIZE, MISSILE_SIZE);
			b->vx = vx; b->vy = vy;
			Missiles.push_back(b);
		}
	}
	//�����ӵ�1
	if (boss->state == 2)
	{
		static int t = 0;
		t++;
		if (t == 10) t = 0;
		if (t == 0)
		{
			double vx, vy;
			Calculate_Velocity(&vx, &vy, 20, boss->x, boss->y, theHero->x, theHero->y);
			ammo* am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet, vx, vy, 0);
			ammos.push_back(am);
			turn(&vx, &vy, 0.25);
			am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet, vx, vy, 0);
			ammos.push_back(am);
			turn(&vx, &vy, -0.5);
			am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet, vx, vy, 0);
			ammos.push_back(am);
		}
	}
	//�����ӵ�2
	if (boss->state == 4)
	{
		static int t = 0;
		t++;
		if (t == 5) t = 0;
		if (t == 0)
		{
			double vx, vy;
			Calculate_Velocity(&vx, &vy, 20, boss->x, boss->y, theHero->x, theHero->y);
			turn(&vx, &vy, 0.15);
			ammo* am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet / 2, vx, vy, 0);
			ammos.push_back(am);
			turn(&vx, &vy, -0.3);
			am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet / 2, vx, vy, 0);
			ammos.push_back(am);
			turn(&vx, &vy, 0.45);
			am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet / 2, vx, vy, 0);
			ammos.push_back(am);
			turn(&vx, &vy, -0.6);
			am = Create_ammo(bmp_ammo_Enemy, boss->x + 32, boss->y + 32, boss->damage_bullet / 2, vx, vy, 0);
			ammos.push_back(am);
		}
	}
}
#pragma endregion


#pragma region ��ʾ����
//����ת��Ϊ�ַ�������
int convert_num_to_ch(int num, char ch[])
{
	int n = 0;
	if (num == 0)
	{
		ch[1] = '0';
		return 1;
	}
	while (num != 0)
	{
		n++;
		ch[n] = num % 10 + 48;
		num = num / 10;
	}
	return n;
}
//������ʾ�ַ�������
void Load_String()
{
	//��Ϸ�������ʾ
	{
		//����������ʾ
		{
			int num1 = 6, len1 = 0, i;
			char ch[20] = { 0 };
			len1 = convert_num_to_ch(theHero->health_current, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				hp[num1] = ch[len1 + 1 - i];
			}
			num1++;
			hp[num1] = '/';
			memset(ch, 0, sizeof(ch));
			len1 = convert_num_to_ch(theHero->health_max, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				hp[num1] = ch[len1 + 1 - i];
			}
			lofhp = num1 + 1;
		}
		//����ԭ����ʾ
		{
			int num1 = 5, len1 = 0, i;
			char ch[20] = { 0 };
			len1 = convert_num_to_ch(theHero->force_current, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				fc[num1] = ch[len1 + 1 - i];
			}
			num1++;
			fc[num1] = '/';
			memset(ch, 0, sizeof(ch));
			len1 = convert_num_to_ch(theHero->force_max, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				fc[num1] = ch[len1 + 1 - i];
			}
			loffc = num1 + 1;
		}
		//���ؾ�����ʾ
		{
			int num1 = 12, len1 = 0, i;
			if (theHero->level < 10) exp1[6] = theHero->level + 48;
			else
			{
				exp1[6] = (theHero->level) / 10 + 48;
				exp1[7] = (theHero->level) % 10 + 48;
			}
			char ch[20] = { 0 };
			len1 = convert_num_to_ch(theHero->exp, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				exp1[num1] = ch[len1 + 1 - i];
			}
			num1++;
			exp1[num1] = '/';
			memset(ch, 0, sizeof(ch));
			len1 = convert_num_to_ch(exp_require[theHero->level], ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				exp1[num1] = ch[len1 + 1 - i];
			}
			lofexp = num1 + 1;
		}
		//�����ӵ���ʾ
		{
			int num1 = 4, len1 = 0, i;
			char ch[20] = { 0 };
			len1 = convert_num_to_ch(theHero->ammo_current, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				am[num1] = ch[len1 + 1 - i];
			}
			num1++;
			am[num1] = '/';
			memset(ch, 0, sizeof(ch));
			len1 = convert_num_to_ch(theHero->ammo_max, ch);
			for (i = 1; i <= len1; i++)
			{
				num1++;
				am[num1] = ch[len1 + 1 - i];
			}
			lofam = num1 + 1;
		}
		//���عؿ�������ʾ
		{
			if (currentStage->stageID != STAGE_BOSS)
			{
				stg[6] = currentStage->stageID - 10 + 48;
				lofstg = 7;
			}
			else
			{
				stg[6] = 'B'; stg[7] = 'O'; stg[8] = 'S'; stg[9] = 'S';
				lofstg = 10;
			}
		}
	}
}
// ��ͼ����
void Paint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// ���Ʊ���������
	SelectObject(hdc_loadBmp, currentStage->bg);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

	// ����������������ݵ�����
	if (currentStage->stageID == STAGE_STARTMENU) {
	}
	else if (currentStage->stageID == STAGE_LOSE)
	{
		SelectObject(hdc_loadBmp, bmp_d);
		TransparentBlt(
			hdc_memBuffer, 350, 20,
			100, 50,
			hdc_loadBmp, 0, 0, 100, 50,
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_WIN)
	{
		if (previous_stage != STAGE_BOSS)
		{
			SelectObject(hdc_loadBmp, bmp_p);
			TransparentBlt(
				hdc_memBuffer, 350, 20,
				100, 50,
				hdc_loadBmp, 0, 0, 100, 50,
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_v);
			TransparentBlt(
				hdc_memBuffer, 350, 20,
				100, 50,
				hdc_loadBmp, 0, 0, 100, 50,
				RGB(255, 255, 255)
			);
		}
	}
	else if (currentStage->stageID == STAGE_HELP_KEY)
	{
		SelectObject(hdc_loadBmp, bmp_help_key_word);
		TransparentBlt(
			hdc_memBuffer, 0, 50,
			800, 500,
			hdc_loadBmp, 0, 0, 800, 500,
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_HELP_BG)
	{
		SelectObject(hdc_loadBmp, bmp_help_bkg_word);
		TransparentBlt(
			hdc_memBuffer, 50, 100,
			750, 400,
			hdc_loadBmp, 0, 0, 750, 400,
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_HELP_MD)
	{
		SelectObject(hdc_loadBmp, bmp_help_module_word);
		TransparentBlt(
			hdc_memBuffer, 0, 50,
			800, 500,
			hdc_loadBmp, 0, 0, 800, 500,
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_BOSS) 
	{
		int i;
		//����Ѫ��������
		TextOut(hdc_memBuffer, 270, 610, stg, lofstg);
		TextOut(hdc_memBuffer, 50, 650,hp ,lofhp);
		TextOut(hdc_memBuffer, 270, 650,fc, loffc);
		TextOut(hdc_memBuffer, 650, 610, am, lofam);
		TextOut(hdc_memBuffer, 500, 650, exp1, lofexp);
		TextOut(hdc_memBuffer, 450, 610, gun[theHero->laser_guns], lofgun[theHero->laser_guns]);
		TextOut(hdc_memBuffer, 50, 610, pst[theHero->position.num], lofpst[theHero->position.num]);
		double a=double(theHero->health_current)/double(theHero->health_max);
		double b = double(theHero->force_current) / double(theHero->force_max);
		double c = double(theHero->exp) / double(exp_require[theHero->level]);
		if (theHero->level > 10) c = 1;
		//������ʾ
		if (theHero->invincible == 1)
		{
			SelectObject(hdc_loadBmp, bmp_shield);
			TransparentBlt(
				hdc_memBuffer, theHero->x - 8, theHero->y - 8,
				48, 48,
				hdc_loadBmp, 0, 0, 48, 48,
				RGB(255, 255, 255)
			);
		}
		//Ǳ����ʾ
		if (theHero->sneathed == 1)
		{
			SelectObject(hdc_loadBmp, bmp_sneak);
			TransparentBlt(
				hdc_memBuffer, theHero->x - 8, theHero->y - 8,
				48, 48,
				hdc_loadBmp, 0, 0, 48, 48,
				RGB(255, 255, 255)
			);
		}
		//����Ѫ��������
		SelectObject(hdc_loadBmp, bmp_Health);
		TransparentBlt(
			hdc_memBuffer, 150, 650,
			CLM_WIDTH*a,CLM_HEIGHT,
			hdc_loadBmp, 0, 0, CLM_WIDTH*a, CLM_HEIGHT,
			RGB(255, 255, 255)
		);
		if (currentStage->stageID == STAGE_BOSS)
		{
			if (boss != NULL)
			{
				double a1 = double(boss->health_current) / double(boss->health_max);
				SelectObject(hdc_loadBmp, bmp_Health);
				TransparentBlt(
					hdc_memBuffer, boss->x, boss->y-10,
					SMALLCLM_WIDTH*a1, SMALLCLM_HEIGHT,
					hdc_loadBmp, 0, 0, SMALLCLM_WIDTH*a1, SMALLCLM_HEIGHT,
					RGB(255, 255, 255)
				);
			}
			if(computer!=NULL)
				{
				double b1 = double(computer->health_current) / double(computer->health_max);
					SelectObject(hdc_loadBmp, bmp_Force);
					TransparentBlt(
						hdc_memBuffer, computer->x, computer->y - 10,
						SMALLCLM_WIDTH*b1, SMALLCLM_HEIGHT,
						hdc_loadBmp, 0, 0, SMALLCLM_WIDTH*b1, SMALLCLM_HEIGHT,
						RGB(255, 255, 255)
					);
				}
		}
		//��������������
		SelectObject(hdc_loadBmp, bmp_Force);
		TransparentBlt(
			hdc_memBuffer, 370, 650,
			CLM_WIDTH*b, CLM_HEIGHT,
			hdc_loadBmp, 0, 0, CLM_WIDTH*b,CLM_HEIGHT,
			RGB(255, 255, 255)
		);
		//���ƾ�����������
		SelectObject(hdc_loadBmp, bmp_Exp);
		TransparentBlt(
			hdc_memBuffer, 650, 650,
			CLM_WIDTH*c, CLM_HEIGHT,
			hdc_loadBmp, 0, 0, CLM_WIDTH*c, CLM_HEIGHT,
			RGB(255, 255, 255)
		);
		// �������ǵ�����
		SelectObject(hdc_loadBmp, theHero->img);
		TransparentBlt(
			hdc_memBuffer, theHero->x, theHero->y,
			HERO_SIZE_X, HERO_SIZE_Y,
			hdc_loadBmp, 0, HERO_SIZE_Y * theHero->frame, HERO_SIZE_X, HERO_SIZE_Y,
			RGB(255, 255, 255)
		);
		if (currentStage->stageID == STAGE_BOSS)
		{
			// ����BOSS������
			if (boss != NULL)
			{
				SelectObject(hdc_loadBmp, boss->img);
				TransparentBlt(
					hdc_memBuffer, boss->x, boss->y,
					BOSS_SIZE, BOSS_SIZE,
					hdc_loadBmp,0, BOSS_SIZE*boss->frame, BOSS_SIZE, BOSS_SIZE,
					RGB(255, 255, 255)
				);
			}
			// �����п�ϵͳ������
			if (computer != NULL)
			{
				SelectObject(hdc_loadBmp, computer->img);
				TransparentBlt(
					hdc_memBuffer, computer->x, computer->y,
					COMPUTER_SIZE_X, COMPUTER_SIZE_Y,
					hdc_loadBmp, 0, 0, COMPUTER_SIZE_X, COMPUTER_SIZE_Y,
					RGB(255, 255, 255)
				);
			}
		}
		// ����С��������
		for (i = 0; i < soldier_r.size(); i++)
		{
			SelectObject(hdc_loadBmp, soldier_r[i]->img);
			TransparentBlt(
				hdc_memBuffer, soldier_r[i]->x, soldier_r[i]->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, soldier_r[i]->frame*HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
		//���������ϰ�������
		for (i = 0; i < brick_p.size(); i++)
		{
			SelectObject(hdc_loadBmp, brick_p[i]->img);
			TransparentBlt(
				hdc_memBuffer, brick_p[i]->x, brick_p[i]->y,
				brick_p[i]->width, brick_p[i]->height,
				hdc_loadBmp, 0, 0, brick_p[i]->width, brick_p[i]->height,
				RGB(255, 255, 255)
			);
		}
		//���ƿ��ƻ��ϰ�������
		for (i = 0; i < brick_b.size(); i++)
		{
			SelectObject(hdc_loadBmp, brick_b[i]->img);
			TransparentBlt(
				hdc_memBuffer, brick_b[i]->x, brick_b[i]->y,
				brick_b[i]->width, brick_b[i]->height,
				hdc_loadBmp, 0, 0, brick_b[i]->width, brick_b[i]->height,
				RGB(255, 255, 255)
			);
		}
		//���Ƽ�����������
		for (i = 0; i < lasers.size(); i++)
		{
			SelectObject(hdc_loadBmp, lasers[i]->img);
			TransparentBlt(
				hdc_memBuffer, lasers[i]->x, lasers[i]->y,
				lasers[i]->width, lasers[i]->height,
				hdc_loadBmp, 0, 0, lasers[i]->width, lasers[i]->height,
				RGB(255, 255, 255)
			);
		}
		//���ƻ��浽����
		for (i = 0; i < flms.size(); i++)
		{
			SelectObject(hdc_loadBmp, flms[i]->img);
			TransparentBlt(
				hdc_memBuffer, flms[i]->x, flms[i]->y,
				40, 40,
				hdc_loadBmp, 0, 0, 40, 40,
				RGB(255, 255, 255)
			);
		}
		// �����ӵ�������
		for (i = 0; i < ammos.size(); i++)
		{
			SelectObject(hdc_loadBmp, ammos[i]->img);
			TransparentBlt(
				hdc_memBuffer, ammos[i]->x, ammos[i]->y,
				AMMO_SIZE_X, AMMO_SIZE_Y,
				hdc_loadBmp, 0, 0, AMMO_SIZE_X, AMMO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
		// ����ը��������
		for (i = 0; i < Bombs.size(); i++)
		{
			SelectObject(hdc_loadBmp, Bombs[i]->img);
			TransparentBlt(
				hdc_memBuffer, Bombs[i]->x, Bombs[i]->y,
				Bombs[i]->width, Bombs[i]->height,
				hdc_loadBmp, 0, 0, Bombs[i]->width, Bombs[i]->height,
				RGB(255, 255, 255)
			);
		}
		// ���Ƶ���������
		for (i = 0; i < Missiles.size(); i++)
		{
			SelectObject(hdc_loadBmp, Missiles[i]->img);
			TransparentBlt(
				hdc_memBuffer, Missiles[i]->x, Missiles[i]->y,
				Missiles[i]->width, Missiles[i]->height,
				hdc_loadBmp, 0, 0, Missiles[i]->width, Missiles[i]->height,
				RGB(255, 255, 255)
			);
		}
		//���ƽ�ս������
		for (i = 0; i < attack_melee.size(); i++)
		{
			SelectObject(hdc_loadBmp, attack_melee[i]->img);
			TransparentBlt(
				hdc_memBuffer, attack_melee[i]->x, attack_melee[i]->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, HERO_SIZE_Y * attack_melee[i]->frame, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
		//����ҽ�ư�������
		for (i = 0; i < h_bag.size(); i++)
		{
			SelectObject(hdc_loadBmp, h_bag[i]->img);
			TransparentBlt(
				hdc_memBuffer, h_bag[i]->x, h_bag[i]->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, 0, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
		//����������������
		for (i = 0; i < w_bag.size(); i++)
		{
			SelectObject(hdc_loadBmp, w_bag[i]->img);
			TransparentBlt(
				hdc_memBuffer, w_bag[i]->x, w_bag[i]->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, 0, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
			);
		}
	}
	else if (currentStage->stageID == STAGE_BEFOREWAR)
	{
		SelectObject(hdc_loadBmp, bmp_beforewar);
		TransparentBlt(
			hdc_memBuffer, 0, 50,
			732, ht,
			hdc_loadBmp, 0, 0, 732, ht,
			RGB(255, 255, 255)
		);
	}
	// ���ư�ť������

	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	
	
	
	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// ��������
	EndPaint(hWnd, &ps);
}
#pragma endregion