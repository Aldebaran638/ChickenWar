#pragma once//�ڸ��ļ������Ǵ�������ȫ�ֱ���,����.

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

void Home_Show();//չʾ��ҳ
void Login_Show();//չʾ��¼����
void Passback_Show();//չʾ�һ��������
void Enroll_Show();//չʾע�����
void Menu_Show();//չʾ���˵�
void ListSelect_Show();//չʾ���а�ѡ�����
void List_Show(int);//չʾ���а�(int�������а�����)
void Setting_Show();//չʾ����ҳ��
void Author_Show();//չʾ������Ա��Ϣչʾҳ��
void Method_Show();//չʾ��Ϸ�淨����
void Game_Show();//չʾ��Ϸ����
void Stop_Show();//չʾ��ͣ����
void End_Show();//չʾ��Ϸ��������
//void Accomplishment_Show();//չʾ�ɾͽ���
void Shop_Show();//չʾ�̵����

//��������������������������������������������������ҳ��ء�����������������������������������������������
void Home_Show();

//��������������������������������������������������ҳ��ء�����������������������������������������������
//��������������������������������������������������¼������ء�����������������������������������������������
void Login_init();
void Login_Print();
void Login_Wait();
bool Login_Wait_Judge();
void Login_Show();
//��������������������������������������������������¼������ء�����������������������������������������������
//�������������������������������������������������һ����������ء�����������������������������������������������
void Passback_init();
void Passback_Print();
void Passback_Wait();
bool Passback_Wait_Judge();
string Passback_Wait_PasswordShow();
void Passback_Show();
//�������������������������������������������������һ����������ء�����������������������������������������������
//������������������������������������������������ע�������ء�����������������������������������������������
void Enroll_init();
void Enroll_Print();
void Enroll_Wait();
void Enroll_Wait_GetLastId();
void Enroll_Wait_Save();
void Enroll_Show();
//������������������������������������������������ע�������ء�����������������������������������������������
//���������������������������������������������������˵�������ء�����������������������������������������������
void Menu_init();
void Menu_Show();
string Menu_Get_ID();
string Menu_Get_Name();
string Menu_Get_Highest();
string Menu_Print_GetHighest();
//���������������������������������������������������˵�������ء�����������������������������������������������
//���������������������������������������������������ý�����ء�����������������������������������������������
void Setting_Print();
void Setting_Wait();
//���������������������������������������������������ý�����ء�����������������������������������������������
//���������������������������������������������������а�ѡ�������ء�����������������������������������������������
void ListSelect_Show();
//���������������������������������������������������а�ѡ�������ء�����������������������������������������������
//�������������������������������������������������̵������ء�����������������������������������������������
void Shop_init();
void Shop_Print();
void Shop_Wait();
bool Shop_Wait_Judge();

//�������������������������������������������������̵������ء�����������������������������������������������
//������������������������������������������������������Ա��Ϣչʾ������ء�����������������������������������������������
void Author_Print();
void Author_Wait();
void Author_Show();
//������������������������������������������������������Ա��Ϣչʾ������ء�����������������������������������������������
//��������������������������������������������������Ϸ�淨չʾ������ء�����������������������������������������������
void Method_Show();
//��������������������������������������������������Ϸ�淨չʾ������ء�����������������������������������������������
//���������������������������������������������������а������ء�����������������������������������������������
void List_Show(int);
void List_init(int);
string List_Get_Name(string id);
//���������������������������������������������������а������ء�����������������������������������������������
//��������������������������������������������������Ϸ������ء�����������������������������������������������

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

    //--�ӵ�4ר��
    int Time_Skill;//�ӵ�������ȴ
    int CClock_Skill;//�ӵ���ʱʱ��

    //--�ӵ�5ר��
    int Time_Live;//�ӵ�����ʱ��
    int CClock_Live;//�ӵ�����ʱ��

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
    double attackCooldown; // ��ͨ��������ȴʱ�䣨�룩
    std::chrono::high_resolution_clock::time_point lastAttackTime; // ��¼�ϴι���ʱ��
    bool isFlexible;
    static std::vector<Plane> Enermy_Plane;
    int Enemy_type;

    //--bossר��--
    int Time_Skill;//boss�ļ��ܹ�����ȴ
    int CClock_Skill;//boss�ļ��ܼ�ʱʱ��
    int Health_Total;//boss����Ѫ��
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

//��������������������������������������������������Ϸ������ء�����������������������������������������������

//��������������������������������������������������ͣ������ء�����������������������������������������������
void Stop_Print();
void Stop_Wait();
void Stop_Show();
//��������������������������������������������������ͣ������ء�����������������������������������������������
//����������������������������������������������������������ء�����������������������������������������������
void End_Print();
void End_Wait();
void End_Show();
//����������������������������������������������������������ء�����������������������������������������������
