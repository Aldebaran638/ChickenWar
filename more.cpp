#include "Data.h"

//����������������������������������������������������,�ӵ�������ء�����������������������������������������������
Plane Enemy1(6/*�ƶ��ٶ�*/, 4/*���(�뾶)*/, 200/*Ѫ��*/, 0/*�ӵ�����*/, 0/*���ҷ�*/, 0/*������ʽ*/, 0/*������ȴ*/, 200/*ײ���˺�*/,1/*����*/, 0,1);
Plane Enemy2(1/*�ƶ��ٶ�*/, 8/*���(�뾶)*/, 1000/*Ѫ��*/, 1/*�ӵ�����*/, 0/*���ҷ�*/, 1/*������ʽ*/, 3000/*������ȴ*/, 1500/*ײ���˺�*/,3/*����*/,0,2);
Plane Enemy3(3/*�ƶ��ٶ�*/, 6/*���(�뾶)*/, 500/*Ѫ��*/, 2/*�ӵ�����*/, 0/*���ҷ�*/, 2/*������ʽ*/, 3000/*������ȴ*/, 100/*ײ���˺�*/, 3/*����*/,1,3);
Plane Enemy4(5/*�ƶ��ٶ�*/, 8/*���(�뾶)*/, 800/*Ѫ��*/, 2/*�ӵ�����*/, 0/*���ҷ�*/, 2/*������ʽ*/, 3000/*������ȴ*/, 800/*ײ���˺�*/, 6/*����*/,1,4);
Plane Enemy5(8/*�ƶ��ٶ�*/, 3/*���(�뾶)*/, 100/*Ѫ��*/, 0/*�ӵ�����*/, 0/*���ҷ�*/, 0/*������ʽ*/, 0/*������ȴ*/, 2000/*ײ���˺�*/, 1/*����*/,0,5);
Plane Boss(600/*x*/, 0/*y*/, 6/*dir*/, 2/*�ƶ��ٶ�*/, 10/*���(�뾶)*/, 20000/*Ѫ��*/, 2/*�ӵ�����*/, 0/*���ҷ�*/, 2/*������ʽ*/, 3000/*������ȴ*/, 99999/*ײ���˺�*/, 60/*����*/, 1,6);

Bullet Enemy_BulTpye1(2/*�ӵ��뾶*/, 4/*�ƶ��ٶ�*/, 200/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,1);
Bullet Enemy_BulTpye2(2/*�ӵ��뾶*/, 3/*�ƶ��ٶ�*/, 350/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,2);
Bullet Enemy_BulTpye3(4/*�ӵ��뾶*/, 4/*�ƶ��ٶ�*/, 500/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,3);
Bullet Enemy_BulTpye4(4/*�ӵ��뾶*/, 10/*�ƶ��ٶ�*/, 500/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,4);
Bullet Enemy_BulTpye5(2/*�ӵ��뾶*/, 1/*�ƶ��ٶ�*/, 300/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,5);
Bullet Enemy_BulTpye6(30/*�ӵ��뾶*/, 4/*�ƶ��ٶ�*/, 1000/*�˺�*/, 0/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,6);
Bullet My_BulTpye1(2/*�ӵ��뾶*/, 3/*�ƶ��ٶ�*/, 20/*�˺�*/, 1/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,1);
Bullet My_BulTpye2(2/*�ӵ��뾶*/, 10/*�ƶ��ٶ�*/, 60/*�˺�*/, 1/*��ʾ�ǵз��ӵ������ҷ��ӵ�*/,2);
//�ӵ����ݸ�����:����
//����������������������������������������������������,�ӵ�������ء�����������������������������������������������
//������������������������������������������������ȫ�ֱ�����ء�����������������������������������������������

int Window_Width=1200;//���ڿ��
int Window_Height=760;//���ڸ߶�
string Login_Password;//�û��ڵ�¼�������������
string Login_ID;//�û��ڵ�¼���������ID
string Passback_ID;//�û����һ�������������ID
string Passback_Password;//�û����һ��������������ܱ�
string last_id;
string Enroll_Name;//�û���ע�����������ǳ�
string Enroll_Password1;//�û���ע��������������
string Enroll_Password2;//�û���ע�����������ܱ�
string Menu_ID;//��¼���˻�ID

bool Music;//���ֿ���״̬.1����0�����
int Difficulty;//�Ѷ�״̬.1�����,2�����е�,3��������
string Shop_Password;//�û�����ĳ�ֵ��
vector<Listelement> List;//���а�����
int Gold;//��ǰ�˻��Ľ����
int addGold;//��ֵ���Ӧ�Ľ����

int BaseV=0;//��Ϸ����,����Ϊ1�����������(ÿһ֡�ƶ��ĸ���)
int BaseR=15;//��Ϸ����,�뾶Ϊ1����������ش�С
int CClock;//������Ϸʱ��,���ڸ���ˢ�ֻ���(����)
int BaseNumber1;//��1�Ļ���ˢ������
int BaseNumber2;//��2�Ļ���ˢ������
int BaseNumber3;//��3�Ļ���ˢ������
int BaseNumber4;//��4�Ļ���ˢ������
int BaseNumber5;//��4�Ļ���ˢ������
bool isbossalive;//��ʾboss�Ƿ���.1������,0��������
int MyPlaneDir;//��ʾ�ҷ��ɻ����ƶ���������
vector<Bullet> Enermy_Bullet;//����з��ӵ���ȫ������
vector<Plane> Enermy_Plane;//����з��ɻ���ȫ������
vector<Bullet> My_Bullet;//�����ҷ��ӵ���ȫ������
Plane MyPlane;//�ҷ��ɻ�

int Game_Mark;//����ȫ�ַ���

class Listelement;//��ʾ���а�ÿһ��Ԫ��
class Plane;//��ʾ�ɻ�����
class Bullet;//��ʾ�ӵ�����
// Listelement implementation
Listelement::Listelement(std::string _id, std::string _name, int _highest) : id(_id), name(_name), highest(_highest) {}

std::string Listelement::getid() {
    return id;
}

std::string Listelement::getname() {
    return name;
}

int Listelement::gethighest() {
    return highest;
}

bool Listelement::operator>(const Listelement& other) {
    return highest > other.highest;
}

// Bullet implementation

int Bullet::getX() const {
    return x;
}

int Bullet::getY() const {
    return y;
}

int Bullet::getR() const {
    return r*BaseR;
}

int Bullet::getV() const {
    return v;
}

int Bullet::getDamage() const {
    return damage;
}
int Bullet::getBullet_type()const {
    return Bullet_type;
}
int Bullet::getTime_Live()const {
    return Time_Live;
}
int Bullet::getCClock_Live()const {
    return CClock_Live;
}

Bullet::Bullet(double _r, double _v, int _damage, int _type,int _Bullet_type) : r(_r), v(_v), damage(_damage), type(_type),Bullet_type(_Bullet_type) {
    Time_Live = 100;
    CClock_Live = 0;
    Time_Skill = 4;
    CClock_Skill = 0;
}

Bullet::Bullet(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) {}

void Bullet::setBulletPosition(int plane_x, int plane_y, int _dir) {
    x = plane_x;
    y = plane_y;
    dir = _dir;
}

void Bullet::move_0() {
    x -= v * BaseV;
}
void Bullet::move_1() {
    x -= v * BaseV;
    y -= v * BaseV * 0.577;
}

void Bullet::move_2()
{
    x -= v * BaseV;
    y -= v * BaseV;
}void Bullet::move_3()
{
    y -= v * BaseV;
    x -= v * BaseV * 0.577;
}
void Bullet::move_4() {
    y -= v * BaseV;
}
void Bullet::move_5() {
    y -= v * BaseV;
    x += v * BaseV * 0.577;
}

void Bullet::move_6()
{
    x += v * BaseV;
    y -= v * BaseV;
}
void Bullet::move_7() {
    x += v * BaseV;
    y -= v * BaseV * 0.577;
}

void Bullet::move_8() {
    x += v * BaseV;
}
void Bullet::move_9() {
    x += v * BaseV;
    y += v * BaseV * 0.577;
}

void Bullet::move_10()
{
    x += v * BaseV;
    y += v * BaseV;
}
void Bullet::move_11() {
    y += v * BaseV;
    x += v * BaseV * 0.577;
}

void Bullet::move_12() {
    y += v * BaseV;
}
void Bullet::move_13() {
    x -= v * BaseV * 0.577;
    y += v * BaseV;
}

void Bullet::move_14()
{
    x -= v * BaseV;
    y += v * BaseV;
}
void Bullet::move_15() {
    x -= v * BaseV;
    y += v * BaseV * 0.577;
}

void Bullet::move() {
    switch (dir) {
    case 0:   
        move_0();
        break;
    case 1:   
        move_1();
        break;
    case 2:   
        move_2();
        break;
    case 3:   
        move_3();
        break;
    case 4:   
        move_4();
        break;
    case 5:   
        move_5();
        break;
    case 6:   
        move_6();
        break;
    case 7:   
        move_7();
        break;
    case 8:   
        move_8();
        break;
    case 9:   
        move_9();
        break;
    case 10:   
        move_10();
        break;
    case 11:   
        move_11();
        break;
    case 12:   
        move_12();
        break;
    case 13:   
        move_13();
        break;
    case 14:   
        move_14();
        break;
    case 15:   
        move_15();
        break;
    }
    if (Bullet_type == 4) {
        if (CClock_Skill >= Time_Skill) {
            Bullet* bullet = new Bullet;
                bullet = new Bullet;
                (*bullet) = Enemy_BulTpye5;
                bullet->setBulletPosition(x, y, dir);
                Enermy_Bullet.push_back(*bullet);
                CClock_Skill = 0;
        }
        CClock_Skill++;
    }
}
void Bullet::setDir(int _Dir) {
    dir = _Dir;
}

// Plane implementation
std::vector<Plane> Plane::Enermy_Plane;

Plane::Plane(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) {}

Plane::Plane(double _v, double _r, int _health, int _type_bullet, bool _type, int _type_attack, int _clock, int _attack, int _mark, bool _isFlexible, int _Enemy_type) :
    v(_v), r(_r), health(_health), type_bullet(_type_bullet), type(_type), type_attack(_type_attack), CClock(_clock), attack(_attack), mark(_mark), isFlexible(_isFlexible), Enemy_type(_Enemy_type),
    creationTime(std::chrono::high_resolution_clock::now()) {
    Health_Total = health;
    Boss_skillTime = 5; // ��ʼ��Boss������ȴʱ��
}

Plane::Plane(int _x, int _y, int _dir,double _v, double _r, int _health, int _type_bullet, bool _type, int _type_attack, int _clock, int _attack, int _mark, bool _isFlexible,int _Enemy_type) :
    x(_x), y(_y), dir(_dir),v(_v), r(_r), health(_health), type_bullet(_type_bullet), type(_type), type_attack(_type_attack), CClock(_clock), attack(_attack), mark(_mark), isFlexible(_isFlexible),Enemy_type(_Enemy_type),
    creationTime(std::chrono::high_resolution_clock::now()) {
    Boss_skillTime = 5; // ��ʼ��Boss������ȴʱ��
    Health_Total = health;
    Time_Skill = 100;
    attackCooldown = 1;
    lastAttackTime = creationTime;
}

double Plane::timeSinceCreation() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(now - creationTime);
    return duration.count();
}

void Plane::time()//�ɻ�ʱ�Ӽ�ʱ
{
    auto now = std::chrono::high_resolution_clock::now();
    auto timeSinceLastAttack = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastAttackTime).count();
    //double timeSinceLastAttack = timeSinceCreation() - lastAttackTime;
    if (timeSinceLastAttack >= attackCooldown) {
        Attack();
        lastAttackTime = now; // ������󹥻�ʱ��  
    }
    if (r == 7)//֤������ɻ���boss,����bossר�м���
    {
        if ((int)timeSinceCreation() % Boss_skillTime == 0) {
            // ����һ������������� ,ʹ���������3��4 
            std::random_device rd; // ���ڻ�ȡ�������  
            std::mt19937 gen(rd()); // ��������ӳ�ʼ��Mersenne Twister������  
            std::uniform_int_distribution<> dis(0, 1); // ����ֲ���Χ[0, 1]
            int randomNumber = dis(gen);
            skill(randomNumber);
        }
    }
}

void Plane::move_0() {
    if (x > 0) {
        x -= v * BaseV;
    }
}
void Plane::move_1() {
    if (x > 0) {
        x -= v * BaseV;
    }
    if (y > 0) {
        y -= v * BaseV * 0.577;
    }
}
void Plane::move_2()
{
    move_4();
    move_0();
}
void Plane::move_3()
{
    if (y > 0) {
        y -= v * BaseV;
    }
    if (x > 0) {
        x -= v * BaseV * 0.577;
    }
}
void Plane::move_4() {
    if (y > 0) {
        y -= v * BaseV;
    }
}
void Plane::move_5() {
    if (y > 0) {
        y -= v * BaseV;
    }
    if (x < Window_Width) {
        x += v * BaseV * 0.577;
    }
}
void Plane::move_6()
{
    move_4();
    move_8();
}
void Plane::move_7() {
    if (x < Window_Width) {
        x += v * BaseV;
    }
    if (y > 0) {
        y -= v * BaseV * 0.577;
    }
}
void Plane::move_8() {
    if (x < Window_Width) {
        x += v * BaseV;
    }
}
void Plane::move_9() {
    if (x < Window_Width) {
        x += v * BaseV;
    }
    if (y < Window_Height) {
        y += v * BaseV * 0.577;
    }
}
void Plane::move_10()
{
    move_12();
    move_8();
}
void Plane::move_11() {
    if (x < Window_Width) {
        x += v * BaseV * 0.577;
    }
    if (y < Window_Height) {
        y += v * BaseV;
    }
}
void Plane::move_12() {
    if ((y < Window_Height / 2 && isFlexible) || !isFlexible) {
        y += v * BaseV;
    }
}
void Plane::move_13() {
    if (x > 0) {
        x -= v * BaseV * 0.577;
    }
    if (y < Window_Height) {
        y += v * BaseV;
    }
}
void Plane::move_14()
{
    move_12();
    move_0();
}
void Plane::move_15() {
    if (x > 0) {
        x -= v * BaseV ;
    }
    if (y < Window_Height) {
        y += v * BaseV * 0.577;
    }
}

void Plane::move() {
    switch (dir) {
    case 0:
        move_0();
        break;
    case 1:
        move_1();
        break;
    case 2:
        move_2();
        break;
    case 3:
        move_3();
        break;
    case 4:
        move_4();
        break;
    case 5:
        move_5();
        break;
    case 6:
        move_6();
        break;
    case 7:
        move_7();
        break;
    case 8:
        move_8();
        break;
    case 9:
        move_9();
        break;
    case 10:
        move_10();
        break;
    case 11:
        move_11();
        break;
    case 12:
        move_12();
        break;
    case 13:
        move_13();
        break;
    case 14:
        move_14();
        break;
    case 15:
        move_15();
        break;
    }
}

bool Plane::isattacked() {
    bool isattackedFlag = false;
    for (const Bullet& _bullet : Enermy_Bullet) {
        if (_bullet.getX() * _bullet.getX() + _bullet.getY() * _bullet.getY() - x * x - y * y < _bullet.getR() + r)
            isattackedFlag = true;
    }
    return isattackedFlag;
}

void Plane::attacked(Bullet bullet) {
    health -= bullet.getDamage();
    if (health <= 10000 && r == 7)
        Boss_skillTime = 3;
}

void Plane::attacked2(Plane &plane) {
    if (type == 0 && plane.type == 1) {
        health = 0;
        plane.health -= attack;
    }
    else if (type == 1 && plane.type == 0) {
        health -= plane.attack;
        plane.health = 0;
    }
}
void Plane::RandomDir() {
    if (CClock2 >= 100&&isFlexible) {
        dir = rand() % 16;
        CClock2 = 0;
    }
    CClock2++;
}
void Plane::Attack()//���ݷɻ�ʱ��,�ɻ����й���
{
    //�����ӵ�����,�ɻ���������,��������ʼ�������ӵ������,Ȼ��push_back��Bullet����
    if (type == 0) {
        if (CClock >= 60) {
            Bullet* bullet = new Bullet;
            Bullet* bulletleft = new Bullet;
            Bullet* bulletmiddle = new Bullet;
            Bullet* bulletright = new Bullet;
            switch (type_bullet) {
            case 0:
                break;
            case 1:
                (*bullet) = Enemy_BulTpye1;
                bullet->setBulletPosition(x, y, 12);
                Enermy_Bullet.push_back(*bullet);
                break;
            case 2:
                (*bulletleft) = Enemy_BulTpye2;
                (*bulletmiddle) = Enemy_BulTpye2;
                (*bulletright) = Enemy_BulTpye2;
                bulletleft->setBulletPosition(x, y, 14);
                bulletmiddle->setBulletPosition(x, y, 12);
                bulletright->setBulletPosition(x, y, 10);
                Enermy_Bullet.push_back(*bulletleft);
                Enermy_Bullet.push_back(*bulletright);
                Enermy_Bullet.push_back(*bulletmiddle);
                break;
            case 6:
                // pass
                break;
            }
        CClock = 0;
        }
        if (Enemy_type == 6) {
            if (CClock_Skill >= Time_Skill) {
                Bullet* bullet = new Bullet;
                if (health >= Health_Total / 2) {
                    for (int i = 0; i <= 15; i++) {
                        bullet = new Bullet;
                        (*bullet) = Enemy_BulTpye3;
                        bullet->setBulletPosition(x, y, i);
                        Enermy_Bullet.push_back(*bullet);
                    }
                }
                else {
                    switch (rand() % 3) {
                    case 0:
                        for (int i = 0; i <= 15; i++) {
                            bullet = new Bullet;
                            (*bullet) = Enemy_BulTpye3;
                            bullet->setBulletPosition(x, y, i);
                            Enermy_Bullet.push_back(*bullet);
                        }
                        break;
                    case 1:
                        for (int i = 9; i <= 15; i++) {
                            bullet = new Bullet;
                            (*bullet) = Enemy_BulTpye4;
                            bullet->setBulletPosition(x, y, i);
                            Enermy_Bullet.push_back(*bullet);
                        }
                        break;
                    case 2:
                            bullet = new Bullet;
                            (*bullet) = Enemy_BulTpye6;
                            bullet->setBulletPosition(x, y, 12);
                            Enermy_Bullet.push_back(*bullet);
                        break;
                        
                    }
                }
                CClock_Skill = 0;
            }
        }
        CClock_Skill++;
    }
    else {
        if (CClock >= 3) {
            Bullet* bullet = new Bullet;
            Bullet* bulletleft = new Bullet;
            Bullet* bulletmiddle = new Bullet;
            Bullet* bulletright = new Bullet;
            Bullet* bulletleft2 = new Bullet;
            Bullet* bulletright2 = new Bullet;

            switch (type_bullet) {
            case 0:
                break;
            case 1:

                (*bullet) = Enemy_BulTpye1;
                bullet->setBulletPosition(x, y, 6);
                My_Bullet.push_back(*bullet);
                break;
            case 2:
                (*bulletleft) = My_BulTpye2;
                (*bulletmiddle) = My_BulTpye2;
                (*bulletright) = My_BulTpye2;
                (*bulletleft2) = My_BulTpye2;
                (*bulletright2) = My_BulTpye2;

                bulletleft->setBulletPosition(x, y, 2);
                bulletmiddle->setBulletPosition(x, y, 4);
                bulletright->setBulletPosition(x, y, 6);
                bulletleft2->setBulletPosition(x, y, 3);
                bulletright2->setBulletPosition(x, y, 5);

                My_Bullet.push_back(*bulletleft);
                My_Bullet.push_back(*bulletright);
                My_Bullet.push_back(*bulletleft2);
                My_Bullet.push_back(*bulletright2);
                My_Bullet.push_back(*bulletmiddle);
                break;
            case 6:
                // pass
                break;
            }
            CClock = 0;
        }

    }
    CClock++;

}

bool Plane::isalive() {
    if (Enemy_type == 6 && health <= 0) {
        isbossalive = 0;
    }
    return health > 0;
}

void Plane::skill(int bossSkillNumber) {
    if (bossSkillNumber == 0) {
        Bullet Boss_BulTpye3_1(2, 4, 500, 0,1);
        Bullet Boss_BulTpye3_2(2, 4, 500, 0,2);
        Bullet Boss_BulTpye3_3(2, 4, 500, 0,3);
        Bullet Boss_BulTpye3_4(2, 4, 500, 0,4);
        if (y - 6 >= 0) {
            Boss_BulTpye3_1.setBulletPosition(x, y - 6, 0);
            Enermy_Bullet.push_back(Boss_BulTpye3_1);
        }
        if (y + 6 <= 760) {
            Boss_BulTpye3_2.setBulletPosition(x, y + 6, 1);
            Enermy_Bullet.push_back(Boss_BulTpye3_2);
        }
        if (x - 6 >= 0) {
            Boss_BulTpye3_3.setBulletPosition(x - 6, y, 2);
            Enermy_Bullet.push_back(Boss_BulTpye3_3);
        }
        if (x + 6 <= 1200) {
            Boss_BulTpye3_4.setBulletPosition(x + 6, y, 3);
            Enermy_Bullet.push_back(Boss_BulTpye3_4);
        }
    }
    else {
        Bullet Boss_BulTpye4(1, 3, 500, 0,4);
        Boss_BulTpye4.setBulletPosition(x, y, 1);
        Enermy_Bullet.push_back(Boss_BulTpye4);
    }
}

int Plane::getX() const {
    return x;
}

int Plane::getY() const {
    return y;
}

double Plane::getV() const {
    return v;
}

int Plane::getHealth() const {
    return health;
}

double Plane::getR() const {
    return r*BaseR;
}

int Plane::getDir() const {
    return dir;
}

int Plane::getTypeBullet() const {
    return type_bullet;
}

int Plane::getTypeAttack() const {
    return type_attack;
}

int Plane::getCClock() const {
    return CClock;
}

int Plane::getBossSkillTime() const {
    return Boss_skillTime;
}

std::chrono::high_resolution_clock::time_point Plane::getCreationTime() const {
    return creationTime;
}

int Plane::getAttack() const {
    return attack;
}

int Plane::getBossSkillCclock() const {
    return bossSkill_cclock;
}

int Plane:: getMark() const {
    return mark;
}
void Plane::setX(int _x) {
    x = _x;
}
void Plane::setY(int _x) {
    y = _x;
}

void Plane::setDir(int _x) {
    dir = _x;
}
void Plane::sethealth(int _health) {
    health = _health;
    Health_Total = _health;
}

bool Plane::getFlexible() {
    return isFlexible;
}

int Plane::getEnemy_type()const {
    return Enemy_type;
}
//������������������������������������������������ȫ�ֱ�����ء�����������������������������������������������

