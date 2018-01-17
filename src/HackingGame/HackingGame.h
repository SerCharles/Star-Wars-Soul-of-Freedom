#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>
#include <time.h>
#include <imm.h>  
#pragma comment (lib ,"imm32.lib") 
// 资源头文件

#include "resource.h"
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib,"winmm.lib")


// TODO:  在此处引用程序需要的其他头文件
#include<Mmsystem.h>
#include <vector>
#include <math.h>


#pragma endregion


#pragma region 宏定义

#define WINDOW_WIDTH			800		//游戏窗口宽度
#define WINDOW_HEIGHT			700	    //游戏窗口高度
#define EDGE_LENGTH             13      //边界砖块长度
#define WINDOW_TITLEBARHEIGHT	32		//标题栏高度

#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_CHOOSE            1       //选择职业ID
#define STAGE_PAUSE             2       //暂停界面ID
#define STAGE_HELP              3       //帮助界面ID
#define STAGE_WIN               4       //胜利场景ID
#define STAGE_LOSE              5       //失败场景ID
#define STAGE_HELP_KEY          6       //按键帮助
#define STAGE_HELP_BG           7       //背景帮助
#define STAGE_HELP_MD           8       //职业帮助
#define STAGE_BEFOREWAR         9       //开场动画
#define STAGE_1					11	    //第一个游戏场景的ID
#define STAGE_2				    12      //第二个游戏场景的ID
#define STAGE_3				    13      //第二个游戏场景的ID
#define STAGE_4				    14      //第二个游戏场景的ID
#define STAGE_5				    15      //第二个游戏场景的ID
#define STAGE_BOSS              16      //BOSS战场景


#define HERO_SIZE_X				32		//主角的宽度
#define HERO_SIZE_Y				32		//主角的高度
#define BOSS_SIZE               64      //Boss边长
#define COMPUTER_SIZE_X         100     //中控系统宽度
#define COMPUTER_SIZE_Y         50      //中控系统高度
#define AMMO_SIZE_X             10      //子弹的宽度
#define AMMO_SIZE_Y             10      //子弹的高度
#define MISSILE_SIZE            20      //追踪弹边长
#define CLM_WIDTH               100     //条的宽度
#define CLM_HEIGHT              25      //条的高度
#define SMALLCLM_WIDTH         50      //boss血条宽度
#define SMALLCLM_HEIGHT         5       //boss血条高度
#define HERO_FRAME_NUMBER		12		//主角的动画帧数量


#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_STARTGAME_WIDTH		147		//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		60		//开始游戏按钮高度
#define BUTTON_CHOOSE_WIDTH		    100	   //选择职业按钮宽度
#define BUTTON_CHOOSE_HEIGHT		40     //选择职业按钮高度
#define BUTTON_QUITGAME			    1002	//退出游戏按钮ID
#define BUTTON_CONTINUE             1003    //继续游戏按钮ID
#define BUTTON_RETURN               1004    //返回主菜单按钮ID
#define BUTTON_JEDI					1005	//选择职业1按钮ID
#define BUTTON_SOLDIER				1006	//选择职业2按钮ID
#define BUTTON_SPY					1007	//选择职业3按钮ID
#define BUTTON_RESTART              1008    //重新开局按钮ID
#define BUTTON_HELP                 1009    //帮助界面ID
#define BUTTON_HELP_CONTINUE        1010    //帮助界面返回ID
#define BUTTON_NEXT                 1011    //下一关卡ID
#define HELP_KEY                    1012    //按键帮助ID
#define HELP_BG                     1013    //背景故事ID
#define HELP_MD                     1014    //职业介绍ID
#define HELP_BACK                   1015    //返回帮助界面
#define BUTTON_SKIP                 1016    //跳过开场       
#define TIMER_GAMETIMER				1	//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		10	//默认计时器刷新间隔的毫秒数

#define NUMBER1 10  //职业和枪最大数目
#define LENGTH1 20  //名称长度
#define NUMBER_BRICK_PERMANENT 7//永久砖块数目
#define NUMBER_BRICK_BREAKABLE 5//可破坏砖块数目
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


#pragma region 结构体声明
//火焰结构体
struct Flame
{
	HBITMAP img;
	int x;
	int y;
	int time;
	bool live;
};
// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};
// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};
//远程武器结构体
struct weapon
{
	HBITMAP img;
	char name[LENGTH1];     //名称
	int ranged_attack;  //远程攻击力
	int ammo_max;       //最大弹量
	double load_time;   //装填时间
};  //远程激光枪
//职业结构体
struct occupation
{
	char name[LENGTH1];
	int num;
	double accleration; //加速度
	int maxspeed; //最大速度
	int health_max;		//最大生命值
	int stamina_max; //最大体力
	int force_max;  //最大原力
	int melee_attack; //近战攻击力
	int attack_improve;//升级攻击力
	int health_improve;//升级生命
	double shooting_bonus; //射击伤害奖励
};
// 主角结构体
struct Hero
{
	HBITMAP img;	//图片
	occupation position; //职业
	char name[LENGTH1];
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	double accleration; //加速度
	int maxspeed; //最大速度
	int health_max;		//最大生命值
	int stamina_max; //最大体力
	int force_max;  //最大原力
	int ammo_max;   //最大弹药
	double load_time;  //装弹时间
	int melee_attack; //近战攻击力
	int ranged_attack; //远程攻击力
	int health_current;  //当前生命值
	int stamina_current; //当前体力
	int force_current;  //当前原力
	int ammo_current;  //现在弹量
	int level;         //当前等级
	int exp;           //当前经验
	int laser_guns; //武器
	bool skill_1;    //技能1
	bool skill_2;   //技能2
	bool invincible; //是否无敌
	bool paralyzed;  //是否能麻痹他人
	bool charging;   //是否正在冲锋
	bool sneathed;   //是否正在潜行
};
//近战士兵结构体
struct Soldier_Melee
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int speed;      //速度
	int health_max;		//最大生命值
	int health_current; //当前生命值
	int melee_attack;    //近战攻击力
};
//远程士兵结构体
struct Soldier_Ranged
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int speed; //速度
	int ranged_attack; //远程攻击力
	int ammo_max;  //最大弹量
	int ammo_current; //当前弹量
	double load_time; //装弹时间
	int health_max;		//最大生命值
	int health_current; //当前生命值
	bool whether;     //是否发现
	bool paralyzed;   //是否麻痹
	int paralyzed_time;//麻痹时间
	weapon laser_guns; //远程武器
};
//永久砖块结构体
struct bricks_permanent
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int width;      //宽度
	int height;     //高度
	int laser;      //是否发射激光束
};
//可破坏砖块结构体
struct bricks_breakable
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int width;      //宽度
	int height;     //高度
	int health_max;		//最大生命值
	int health_current; //当前生命值
};
//激光束结构体
struct laser
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int width;      //宽度
	int height;     //高度
	int damage;     //伤害
	int direction;   //方向(右1下2左3上4）
};
//子弹
struct ammo
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int damage;     //伤害
	double vx;		//速度x
	double vy;		//速度y
	int speed;      //速度
	bool live;       //是否有效
	int side;      //我方还是敌方
};
//炸弹
struct bombard
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	bool live;       //是否有效
	int damage;     //伤害
	int range;      //爆炸范围
	int type;       //种类：1：相位炮 2：陷阱炸弹 3：可抵消火箭弹（boss）
	int speed;      //速度
	int width;      //图形长度
	int height;     //图形高度
	double vx;      //x分速度
	double vy;      //y分速度
	int time;        //放置时间
};
//导弹
struct missile
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	bool live;       //是否有效
	int damage;     //伤害
	int range;      //爆炸范围
	int type;       //种类：1：相位炮 2：陷阱炸弹 3：可抵消火箭弹（boss）
	int speed;      //速度
	int width;      //图形长度
	int height;     //图形高度
	double vx;      //x分速度
	double vy;      //y分速度
	int time;        //放置时间
};
// 近战攻击
struct melee_attack
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int damage;     //伤害
	int length;     //边长
	int timespan;   //时间周期
	bool live;       //是否有效
	int side;      //我方还是敌方
};
//医疗包
struct health_bag
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	bool live;      //是否有效
	int restore;    //恢复生命
};
//武器包
struct weapon_bag
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	bool live;      //是否有效
	int weapon;     //武器标号
};
//存储刷新位置
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
	int state; //四种状态 1：移动 2：发射子弹弹幕 3：发射炮弹
	int damage_bullet;
	int damage_cannon;
	bool paralyzed;   //是否麻痹
	int paralyzed_time;//麻痹时间
};
#pragma endregion


#pragma region 函数声明
// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
//鼠标右键按下事件处理函数
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标右键松开事件处理函数
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 添加火焰函数
Flame* Create_flame(int x, int y);
// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);
// 添加武器函数
weapon Create_laser_gun(char name[LENGTH1], int attack, int ammo_max, double load_time);
//添加职业函数
occupation Create_occupation(char name[LENGTH1], int num, int attack, double accleration, int maxspeed, int health, int stamina, int force, double shooting_bonus, int health_imp, int attack_imp);
// 添加主角函数
Hero* CreateHero(HBITMAP img, char name[10], int position, int x, int y, int gun);
// 添加Boss函数
guardian* Create_Boss(HBITMAP img, int x, int y,int speed,int health_max,int damage_b,int damage_c);
// 添加近战小兵函数
Soldier_Melee* Create_Soldier_Melee(HBITMAP img, int x, int y);
//添加远程小兵函数
Soldier_Ranged* Create_Soldier_Ranged (HBITMAP img, int x, int y);
//添加永久砖块函数
bricks_permanent* Create_bricks_permanent(HBITMAP img, int x, int y, int width,int height,int laser);
//添加可破坏砖块函数
bricks_breakable* Create_bricks_breakable(HBITMAP img, int x, int y, int width, int height);
//添加激光束函数
laser* Create_laser(HBITMAP img, int x, int y, int width, int height,int direction);
//添加主角子弹函数
ammo* Create_ammo(HBITMAP img, int x, int y, int damage, double vx, double vy, int side);
//添加近战攻击函数
melee_attack* Create_melee_attack(HBITMAP img,int frame, int x, int y, int damage, bool side);
//添加医疗包函数
health_bag* Create_health_bag(HBITMAP img, int x, int y);
//添加武器包函数
weapon_bag* Create_weapon_bag(HBITMAP img, int x, int y, int weapon);
//添加炸弹函数
bombard* Create_bombs(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range,int width,int height);
//添加导弹函数
missile* Create_missiles(HBITMAP img, int x, int y, int damage, int type, int speed, int time, int range, int width, int height);
//随机函数
void srand(unsigned int seed);
//随机生成武器
int get_random_weapon();
//数字与字符转换函数
int convert_num_to_ch(int num, char ch[]);
//2的几次方
int two(int i);
//旋转函数
void turn(double* vx, double* vy, double angle);
//加载显示字符串函数
void Load_String();
// 初始化场景函数
void InitStage(HWND hWnd, int stageID,bool whether);
// 刷新主角状态函数
void UpdateHero(HWND hWnd);
//刷新小兵状态函数
void UpdateSoldier(HWND hWnd);
//刷新BOSS状态函数
void UpdateBoss(HWND hWnd);
// 刷新子弹状态函数
void UpdateAmmos(HWND hWnd);
// 刷新炸弹状态函数
void UpdateBombs(HWND hwnd);
//刷新导弹函数
void UpdateMissiles(HWND hwnd);
//刷新近战攻击函数
void UpdateMeleeAttack(HWND hWnd);
//刷新激光束函数
void UpdateLasers(HWND hWnd);
//刷新火焰函数
void UpdateFlames(HWND hWnd);
//刷新小兵死亡与障碍清空函数
void UpdateDeath(HWND hWnd);
//判断是否相交函数
int judge_cross(int a_x, int a_y, int a_width, int a_height, int b_x, int b_y, int b_width, int b_height);
//判断线与多边形是否相交
int judge_line(int a_x, int a_y, int b_x, int b_y,int num);
//爆炸函数
void explode(int x, int y, int width, int height, int damage);
//判断激光束函数
int judge_laser(int x, int y, int w, int h);
//判断小兵函数
int judge_soldier(int x, int y, int num);
//判断BOSS函数
int judge_boss(int x, int y);
// 计算分速度函数
void Calculate_Velocity(double* ptrx, double* ptry, int v, int currentx, int currenty, int mx, int my);
// 计算主角的当前帧数
int GetHeroFrame(double dirX, double dirY);
//主角射击函数
void Hero_Shoot();
//主角技能发动函数
void shield();//战士技能1：护盾
void charge();//战士技能2：冲锋
void paralyze();//远程技能1：发射电击眩晕子弹
void bomb();//远程技能2：相位炮
void sneath();//间谍技能1：隐身
void trap_bomb();//间谍技能2：放置炸弹
//近战攻击函数
void Melee_Attack();
// 绘图函数
void Paint(HWND hWnd);
#pragma endregion