#pragma once

#pragma region ͷ�ļ�����

// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>
#include <time.h>
#include <imm.h>  
#pragma comment (lib ,"imm32.lib") 
// ��Դͷ�ļ�

#include "resource.h"
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib,"winmm.lib")


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include<Mmsystem.h>
#include <vector>
#include <math.h>


#pragma endregion


#pragma region �궨��

#define WINDOW_WIDTH			800		//��Ϸ���ڿ��
#define WINDOW_HEIGHT			700	    //��Ϸ���ڸ߶�
#define EDGE_LENGTH             13      //�߽�ש�鳤��
#define WINDOW_TITLEBARHEIGHT	32		//�������߶�

#define STAGE_STARTMENU			0		//��ʼ�����ID
#define STAGE_CHOOSE            1       //ѡ��ְҵID
#define STAGE_PAUSE             2       //��ͣ����ID
#define STAGE_HELP              3       //��������ID
#define STAGE_WIN               4       //ʤ������ID
#define STAGE_LOSE              5       //ʧ�ܳ���ID
#define STAGE_HELP_KEY          6       //��������
#define STAGE_HELP_BG           7       //��������
#define STAGE_HELP_MD           8       //ְҵ����
#define STAGE_BEFOREWAR         9       //��������
#define STAGE_1					11	    //��һ����Ϸ������ID
#define STAGE_2				    12      //�ڶ�����Ϸ������ID
#define STAGE_3				    13      //�ڶ�����Ϸ������ID
#define STAGE_4				    14      //�ڶ�����Ϸ������ID
#define STAGE_5				    15      //�ڶ�����Ϸ������ID
#define STAGE_BOSS              16      //BOSSս����


#define HERO_SIZE_X				32		//���ǵĿ��
#define HERO_SIZE_Y				32		//���ǵĸ߶�
#define BOSS_SIZE               64      //Boss�߳�
#define COMPUTER_SIZE_X         100     //�п�ϵͳ���
#define COMPUTER_SIZE_Y         50      //�п�ϵͳ�߶�
#define AMMO_SIZE_X             10      //�ӵ��Ŀ��
#define AMMO_SIZE_Y             10      //�ӵ��ĸ߶�
#define MISSILE_SIZE            20      //׷�ٵ��߳�
#define CLM_WIDTH               100     //���Ŀ��
#define CLM_HEIGHT              25      //���ĸ߶�
#define SMALLCLM_WIDTH         50      //bossѪ�����
#define SMALLCLM_HEIGHT         5       //bossѪ���߶�
#define HERO_FRAME_NUMBER		12		//���ǵĶ���֡����


#define BUTTON_STARTGAME			1001	//��ʼ��Ϸ��ťID
#define BUTTON_STARTGAME_WIDTH		147		//��ʼ��Ϸ��ť���
#define BUTTON_STARTGAME_HEIGHT		60		//��ʼ��Ϸ��ť�߶�
#define BUTTON_CHOOSE_WIDTH		    100	   //ѡ��ְҵ��ť���
#define BUTTON_CHOOSE_HEIGHT		40     //ѡ��ְҵ��ť�߶�
#define BUTTON_QUITGAME			    1002	//�˳���Ϸ��ťID
#define BUTTON_CONTINUE             1003    //������Ϸ��ťID
#define BUTTON_RETURN               1004    //�������˵���ťID
#define BUTTON_JEDI					1005	//ѡ��ְҵ1��ťID
#define BUTTON_SOLDIER				1006	//ѡ��ְҵ2��ťID
#define BUTTON_SPY					1007	//ѡ��ְҵ3��ťID
#define BUTTON_RESTART              1008    //���¿��ְ�ťID
#define BUTTON_HELP                 1009    //��������ID
#define BUTTON_HELP_CONTINUE        1010    //�������淵��ID
#define BUTTON_NEXT                 1011    //��һ�ؿ�ID
#define HELP_KEY                    1012    //��������ID
#define HELP_BG                     1013    //��������ID
#define HELP_MD                     1014    //ְҵ����ID
#define HELP_BACK                   1015    //���ذ�������
#define BUTTON_SKIP                 1016    //��������       
#define TIMER_GAMETIMER				1	//��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_GAMETIMER_ELAPSE		10	//Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����

#define NUMBER1 10  //ְҵ��ǹ�����Ŀ
#define LENGTH1 20  //���Ƴ���
#define NUMBER_BRICK_PERMANENT 7//����ש����Ŀ
#define NUMBER_BRICK_BREAKABLE 5//���ƻ�ש����Ŀ
#define WEIGHT_ROAD 1
#define WEIGHT_BRICK 2000
#define WEIGHT_LASER 20

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0X44
#define VK_1 0X31
#define VK_2 0X32

#define EXP_GET 100
#define MUSIC_MAIN L"res/MainTheme.wav"
#define MUSIC_BATTLE L"res/battle.wav"
#define MUSIC_BOSS L"res/boss.wav"
#pragma endregion


#pragma region �ṹ������
//����ṹ��
struct Flame
{
	HBITMAP img;
	int x;
	int y;
	int time;
	bool live;
};
// �����ṹ��
struct Stage
{
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��

};
// ��ť�ṹ��
struct Button
{
	int buttonID;	//��ť���
	bool visible;	//��ť�Ƿ�ɼ�
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int width;		//���
	int height;		//�߶�
};
//Զ�������ṹ��
struct weapon
{
	HBITMAP img;
	char name[LENGTH1];     //����
	int ranged_attack;  //Զ�̹�����
	int ammo_max;       //�����
	double load_time;   //װ��ʱ��
};  //Զ�̼���ǹ
//ְҵ�ṹ��
struct occupation
{
	char name[LENGTH1];
	int num;
	double accleration; //���ٶ�
	int maxspeed; //����ٶ�
	int health_max;		//�������ֵ
	int stamina_max; //�������
	int force_max;  //���ԭ��
	int melee_attack; //��ս������
	int attack_improve;//����������
	int health_improve;//��������
	double shooting_bonus; //����˺�����
};
// ���ǽṹ��
struct Hero
{
	HBITMAP img;	//ͼƬ
	occupation position; //ְҵ
	char name[LENGTH1];
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double accleration; //���ٶ�
	int maxspeed; //����ٶ�
	int health_max;		//�������ֵ
	int stamina_max; //�������
	int force_max;  //���ԭ��
	int ammo_max;   //���ҩ
	double load_time;  //װ��ʱ��
	int melee_attack; //��ս������
	int ranged_attack; //Զ�̹�����
	int health_current;  //��ǰ����ֵ
	int stamina_current; //��ǰ����
	int force_current;  //��ǰԭ��
	int ammo_current;  //���ڵ���
	int level;         //��ǰ�ȼ�
	int exp;           //��ǰ����
	int laser_guns; //����
	bool skill_1;    //����1
	bool skill_2;   //����2
	bool invincible; //�Ƿ��޵�
	bool paralyzed;  //�Ƿ����������
	bool charging;   //�Ƿ����ڳ��
	bool sneathed;   //�Ƿ�����Ǳ��
};
//��սʿ���ṹ��
struct Soldier_Melee
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int speed;      //�ٶ�
	int health_max;		//�������ֵ
	int health_current; //��ǰ����ֵ
	int melee_attack;    //��ս������
};
//Զ��ʿ���ṹ��
struct Soldier_Ranged
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int speed; //�ٶ�
	int ranged_attack; //Զ�̹�����
	int ammo_max;  //�����
	int ammo_current; //��ǰ����
	double load_time; //װ��ʱ��
	int health_max;		//�������ֵ
	int health_current; //��ǰ����ֵ
	bool whether;     //�Ƿ���
	bool paralyzed;   //�Ƿ����
	int paralyzed_time;//���ʱ��
	weapon laser_guns; //Զ������
};
//����ש��ṹ��
struct bricks_permanent
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int width;      //���
	int height;     //�߶�
	int laser;      //�Ƿ��伤����
};
//���ƻ�ש��ṹ��
struct bricks_breakable
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int width;      //���
	int height;     //�߶�
	int health_max;		//�������ֵ
	int health_current; //��ǰ����ֵ
};
//�������ṹ��
struct laser
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int width;      //���
	int height;     //�߶�
	int damage;     //�˺�
	int direction;   //����(��1��2��3��4��
};
//�ӵ�
struct ammo
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int damage;     //�˺�
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int speed;      //�ٶ�
	bool live;       //�Ƿ���Ч
	int side;      //�ҷ����ǵз�
};
//ը��
struct bombard
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	bool live;       //�Ƿ���Ч
	int damage;     //�˺�
	int range;      //��ը��Χ
	int type;       //���ࣺ1����λ�� 2������ը�� 3���ɵ����������boss��
	int speed;      //�ٶ�
	int width;      //ͼ�γ���
	int height;     //ͼ�θ߶�
	double vx;      //x���ٶ�
	double vy;      //y���ٶ�
	int time;        //����ʱ��
};
//����
struct missile
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	bool live;       //�Ƿ���Ч
	int damage;     //�˺�
	int range;      //��ը��Χ
	int type;       //���ࣺ1����λ�� 2������ը�� 3���ɵ����������boss��
	int speed;      //�ٶ�
	int width;      //ͼ�γ���
	int height;     //ͼ�θ߶�
	double vx;      //x���ٶ�
	double vy;      //y���ٶ�
	int time;        //����ʱ��
};
// ��ս����
struct melee_attack
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int damage;     //�˺�
	int length;     //�߳�
	int timespan;   //ʱ������
	bool live;       //�Ƿ���Ч
	int side;      //�ҷ����ǵз�
};
//ҽ�ư�
struct health_bag
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	bool live;      //�Ƿ���Ч
	int restore;    //�ָ�����
};
//������
struct weapon_bag
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	bool live;      //�Ƿ���Ч
	int weapon;     //�������
};
//�洢ˢ��λ��
struct blk  
{
	int x;
	int y;
	int width;
	int height;
};
//boss
struct guardian
{
	HBITMAP img;
	int frame;
	int x;
	int y;
	int width;
	int height;
	int speed;
	int vx;
	int vy;
	int health_max;
	int health_current;
	bool detect;
	int state; //����״̬ 1���ƶ� 2�������ӵ���Ļ 3�������ڵ�
	int damage_bullet;
	int damage_cannon;
	bool paralyzed;   //�Ƿ����
	int paralyzed_time;//���ʱ��
};
#pragma endregion


#pragma region ��������
// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
//����Ҽ������¼�������
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ����Ҽ��ɿ��¼�������
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
// ��ӻ��溯��
Flame* Create_flame(int x, int y);
// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);
// �����������
weapon Create_laser_gun(char name[LENGTH1], int attack, int ammo_max, double load_time);
//���ְҵ����
occupation Create_occupation(char name[LENGTH1], int num, int attack, double accleration, int maxspeed, int health, int stamina, int force, double shooting_bonus, int health_imp, int attack_imp);
// ������Ǻ���
Hero* CreateHero(HBITMAP img, char name[10], int position, int x, int y, int gun);
// ���Boss����
guardian* Create_Boss(HBITMAP img, int x, int y,int speed,int health_max,int damage_b,int damage_c);
// ��ӽ�սС������
Soldier_Melee* Create_Soldier_Melee(HBITMAP img, int x, int y);
//���Զ��С������
Soldier_Ranged* Create_Soldier_Ranged (HBITMAP img, int x, int y);
//�������ש�麯��
bricks_permanent* Create_bricks_permanent(HBITMAP img, int x, int y, int width,int height,int laser);
//��ӿ��ƻ�ש�麯��
bricks_breakable* Create_bricks_breakable(HBITMAP img, int x, int y, int width, int height);
//��Ӽ���������
laser* Create_laser(HBITMAP img, int x, int y, int width, int height,int direction);
//��������ӵ�����
ammo* Create_ammo(HBITMAP img, int x, int y, int damage, double vx, double vy, int side);
//��ӽ�ս��������
melee_attack* Create_melee_attack(HBITMAP img,int frame, int x, int y, int damage, bool side);
//���ҽ�ư�����
health_bag* Create_health_bag(HBITMAP img, int x, int y);
//�������������
weapon_bag* Create_weapon_bag(HBITMAP img, int x, int y, int weapon);
//���ը������
bombard* Create_bombs(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range,int width,int height);
//��ӵ�������
missile* Create_missiles(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range, int width, int height);
//�������
void srand(unsigned int seed);
//�����������
int get_random_weapon();
//�������ַ�ת������
int convert_num_to_ch(int num, char ch[]);
//2�ļ��η�
int two(int i);
//��ת����
void turn(double* vx, double* vy, double angle);
//������ʾ�ַ�������
void Load_String();
// ��ʼ����������
void InitStage(HWND hWnd, int stageID,bool whether);
// ˢ������״̬����
void UpdateHero(HWND hWnd);
//ˢ��С��״̬����
void UpdateSoldier(HWND hWnd);
//ˢ��BOSS״̬����
void UpdateBoss(HWND hWnd);
// ˢ���ӵ�״̬����
void UpdateAmmos(HWND hWnd);
// ˢ��ը��״̬����
void UpdateBombs(HWND hwnd);
//ˢ�µ�������
void UpdateMissiles(HWND hwnd);
//ˢ�½�ս��������
void UpdateMeleeAttack(HWND hWnd);
//ˢ�¼���������
void UpdateLasers(HWND hWnd);
//ˢ�»��溯��
void UpdateFlames(HWND hWnd);
//ˢ��С���������ϰ���պ���
void UpdateDeath(HWND hWnd);
//�ж��Ƿ��ཻ����
int judge_cross(int a_x, int a_y, int a_width, int a_height, int b_x, int b_y, int b_width, int b_height);
//�ж����������Ƿ��ཻ
int judge_line(int a_x, int a_y, int b_x, int b_y,int num);
//��ը����
void explode(int x, int y, int width, int height, int damage);
//�жϼ���������
int judge_laser(int x, int y, int w, int h);
//�ж�С������
int judge_soldier(int x, int y, int num);
//�ж�BOSS����
int judge_boss(int x, int y);
// ������ٶȺ���
void Calculate_Velocity(double* ptrx, double* ptry, int v, int currentx, int currenty, int mx, int my);
// �������ǵĵ�ǰ֡��
int GetHeroFrame(double dirX, double dirY);
//�����������
void Hero_Shoot();
//���Ǽ��ܷ�������
void shield();//սʿ����1������
void charge();//սʿ����2�����
void paralyze();//Զ�̼���1��������ѣ���ӵ�
void bomb();//Զ�̼���2����λ��
void sneath();//�������1������
void trap_bomb();//�������2������ը��
//��ս��������
void Melee_Attack();
// ��ͼ����
void Paint(HWND hWnd);
#pragma endregion