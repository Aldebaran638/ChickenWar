#pragma once//ÔÚ¸ÃÎÄ¼þÖÐÎÒÃÇ´¢´æËùÓÐÈ«¾Ö±äÁ¿,º¯Êý.

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<graphics.h>
#include<codecvt>
#include<fstream>
#include<chrono>
#include<random>
#include <cwchar>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<string>
#include<locale>
#include<codecvt>
#include<mmsystem.h>
#include<stdbool.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

void Home_Show();//Õ¹Ê¾Ê×Ò³
void Login_Show();//Õ¹Ê¾µÇÂ¼½çÃæ
void Passback_Show();//Õ¹Ê¾ÕÒ»ØÃÜÂë½çÃæ
void Enroll_Show();//Õ¹Ê¾×¢²á½çÃæ
void Menu_Show();//Õ¹Ê¾Ö÷²Ëµ¥
void ListSelect_Show();//Õ¹Ê¾ÅÅÐÐ°ñÑ¡Ôñ½çÃæ
void List_Show(int);//Õ¹Ê¾ÅÅÐÐ°ñ(int´ú±íÅÅÐÐ°ñÖÖÀà)
void Setting_Show();//Õ¹Ê¾ÉèÖÃÒ³Ãæ
void Author_Show();//Õ¹Ê¾ÖÆ×÷ÈËÔ±ÐÅÏ¢Õ¹Ê¾Ò³Ãæ
void Method_Show();//Õ¹Ê¾ÓÎÏ·Íæ·¨½çÃæ
void Game_Show();//Õ¹Ê¾ÓÎÏ·½çÃæ
void Stop_Show();//Õ¹Ê¾ÔÝÍ£½çÃæ
void End_Show();//Õ¹Ê¾ÓÎÏ·½áÊø½çÃæ
//void Accomplishment_Show();//Õ¹Ê¾³É¾Í½çÃæ
void Shop_Show();//Õ¹Ê¾ÉÌµê½çÃæ

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ×Ò³Ïà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Home_Show();

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ×Ò³Ïà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªµÇÂ¼½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Login_init();
void Login_Print();
void Login_Wait();
bool Login_Wait_Judge();
void Login_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªµÇÂ¼½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÕÒ»ØÃÜÂë½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Passback_init();
void Passback_Print();
void Passback_Wait();
bool Passback_Wait_Judge();
string Passback_Wait_PasswordShow();
void Passback_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÕÒ»ØÃÜÂë½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª×¢²á½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Enroll_init();
void Enroll_Print();
void Enroll_Wait();
void Enroll_Wait_GetLastId();
void Enroll_Wait_Save();
void Enroll_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª×¢²á½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÖ÷²Ëµ¥½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Menu_init();
void Menu_Show();
string Menu_Get_ID();
string Menu_Get_Name();
string Menu_Get_Highest();
string Menu_Print_GetHighest();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÖ÷²Ëµ¥½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÉèÖÃ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Setting_Print();
void Setting_Wait();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÉèÖÃ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÅÅÐÐ°ñÑ¡Ôñ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void ListSelect_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÅÅÐÐ°ñÑ¡Ôñ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÉÌµê½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Shop_init();
void Shop_Print();
void Shop_Wait();
bool Shop_Wait_Judge();

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÉÌµê½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÖÆ×÷ÈËÔ±ÐÅÏ¢Õ¹Ê¾½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Author_Print();
void Author_Wait();
void Author_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÖÆ×÷ÈËÔ±ÐÅÏ¢Õ¹Ê¾½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÓÎÏ·Íæ·¨Õ¹Ê¾½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Method_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÓÎÏ·Íæ·¨Õ¹Ê¾½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÅÅÐÐ°ñ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void List_Show(int);
void List_init(int);
string List_Get_Name(string id);
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÅÅÐÐ°ñ½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÓÎÏ·½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª

void Game_init();
void Game_Show();
void Game_Print();
void Game_Run();
void Game_Run_Stop();
void Game_Run_RenewSituation();
void Game_Run_RenewEnermy();
void Game_Run_GetDir();
void Game_Run_SetDir();
void Game_Run_Print();
class Listelement {
private:
    std::string id;
    std::string name;
    int highest;
public:
    Listelement() = default;
    Listelement(std::string _id, std::string _name, int _highest);
    std::string getid();
    std::string getname();
    int gethighest();
    bool operator>(const Listelement& other);
};

class Bullet {
private:
    int x, y;
    double r;
    int dir;
    double v;
    int damage;
    int type;
    int Bullet_type;

    //--×Óµ¯4×¨Êô
    int Time_Skill;//×Óµ¯¼¼ÄÜÀäÈ´
    int CClock_Skill;//×Óµ¯¼ÆÊ±Ê±ÖÓ

    //--×Óµ¯5×¨Êô
    int Time_Live;//×Óµ¯´æÔÚÊ±¼ä
    int CClock_Live;//×Óµ¯´æÔÚÊ±ÖÓ

public:
    friend class Plane;
    int getX() const;
    int getY() const;
    int getR() const;
    int getV() const;
    int getDamage() const;
    int getBullet_type()const;
    int getTime_Live()const;
    int getCClock_Live()const;

    Bullet() = default;
    Bullet(double _r, double _v, int _damage, int _type,int Bullet_type);
    Bullet(int _x, int _y, int _dir);
    void setBulletPosition(int plane_x, int plane_y, int _dir);
    void move_0();
    void move_1();
    void move_2();
    void move_3();
    void move_4();
    void move_5();
    void move_6();
    void move_7();
    void move_8();
    void move_9();
    void move_10();
    void move_11();
    void move_12();
    void move_13();
    void move_14();
    void move_15();
    void move();
    void setDir(int);

};

class Plane {
private:
    int x, y;
    double v;
    int health;
    double r;
    int dir;
    int type_bullet;
    int type_attack;
    int CClock=0;
    int CClock2 = 0;
    int Boss_skillTime;
    std::chrono::high_resolution_clock::time_point creationTime;
    int attack;
    int bossSkill_cclock;
    bool type;
    int mark;
    double attackCooldown; // ÆÕÍ¨¹¥»÷µÄÀäÈ´Ê±¼ä£¨Ãë£©
    std::chrono::high_resolution_clock::time_point lastAttackTime; // ¼ÇÂ¼ÉÏ´Î¹¥»÷Ê±¼ä
    bool isFlexible;
    static std::vector<Plane> Enermy_Plane;
    int Enemy_type;

    //--boss×¨Êô--
    int Time_Skill;//bossµÄ¼¼ÄÜ¹¥»÷ÀäÈ´
    int CClock_Skill;//bossµÄ¼¼ÄÜ¼ÆÊ±Ê±ÖÓ
    int Health_Total;//bossµÄ×ÜÑªÁ¿
public:
    friend class Bullet;
    Plane() = default;
    Plane(int _x, int _y, int _dir);
    Plane(double _v, double _r, int _health, int _type_bullet, bool _type, int _type_attack, int _clock, int _attack,int _mark, bool _Flexible,int Enemy_type);
    Plane(int _x, int _y, int _dir,double _v, double _r, int _health, int _type_bullet, bool _type, int _type_attack, int _clock, int _attack, int _mark, bool _Flexible,int Enemy_type);
    double timeSinceCreation() const;
    void time();
    void move_0();
    void move_1();
    void move_2();
    void move_3();
    void move_4();
    void move_5();
    void move_6();
    void move_7();
    void move_8();
    void move_9();
    void move_10();
    void move_11();
    void move_12();
    void move_13();
    void move_14();
    void move_15();
    void move();
    bool isattacked();
    void attacked(Bullet bullet);
    void attacked2(Plane &plane);
    void Attack();
    bool isalive();
    void skill(int bossSkillNumber);
    int getX() const;
    int getY() const;
    double getV() const;
    int getHealth() const;
    double getR() const;
    int getDir() const;
    int getTypeBullet() const;
    int getTypeAttack() const;
    int getCClock() const;
    int getBossSkillTime() const;
    int getMark() const;
    std::chrono::high_resolution_clock::time_point getCreationTime() const;
    int getAttack() const;
    int getBossSkillCclock() const;
    int getEnemy_type()const;
    void setX(int);
    void setY(int);
    void setDir(int);
    bool getFlexible();
    void sethealth(int);
    void RandomDir();
};

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÓÎÏ·½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÔÝÍ£½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Stop_Print();
void Stop_Wait();
void Stop_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÔÝÍ£½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª½áÊø½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void End_Print();
void End_Wait();
void End_Show();
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª½áÊø½çÃæÏà¹Ø¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
