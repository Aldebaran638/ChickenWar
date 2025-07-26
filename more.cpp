#include "Data.h"

//————————————————————————怪物,子弹数据相关————————————————————————
Plane Enemy1(6/*移动速度*/, 4/*体积(半径)*/, 200/*血量*/, 0/*子弹类型*/, 0/*敌我方*/, 0/*攻击方式*/, 0/*攻击冷却*/, 200/*撞击伤害*/,1/*分数*/, 0,1);
Plane Enemy2(1/*移动速度*/, 8/*体积(半径)*/, 1000/*血量*/, 1/*子弹类型*/, 0/*敌我方*/, 1/*攻击方式*/, 3000/*攻击冷却*/, 1500/*撞击伤害*/,3/*分数*/,0,2);
Plane Enemy3(3/*移动速度*/, 6/*体积(半径)*/, 500/*血量*/, 2/*子弹类型*/, 0/*敌我方*/, 2/*攻击方式*/, 3000/*攻击冷却*/, 100/*撞击伤害*/, 3/*分数*/,1,3);
Plane Enemy4(5/*移动速度*/, 8/*体积(半径)*/, 800/*血量*/, 2/*子弹类型*/, 0/*敌我方*/, 2/*攻击方式*/, 3000/*攻击冷却*/, 800/*撞击伤害*/, 6/*分数*/,1,4);
Plane Enemy5(8/*移动速度*/, 3/*体积(半径)*/, 100/*血量*/, 0/*子弹类型*/, 0/*敌我方*/, 0/*攻击方式*/, 0/*攻击冷却*/, 2000/*撞击伤害*/, 1/*分数*/,0,5);
Plane Boss(600/*x*/, 0/*y*/, 6/*dir*/, 2/*移动速度*/, 10/*体积(半径)*/, 20000/*血量*/, 2/*子弹类型*/, 0/*敌我方*/, 2/*攻击方式*/, 3000/*攻击冷却*/, 99999/*撞击伤害*/, 60/*分数*/, 1,6);

Bullet Enemy_BulTpye1(2/*子弹半径*/, 4/*移动速度*/, 200/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,1);
Bullet Enemy_BulTpye2(2/*子弹半径*/, 3/*移动速度*/, 350/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,2);
Bullet Enemy_BulTpye3(4/*子弹半径*/, 4/*移动速度*/, 500/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,3);
Bullet Enemy_BulTpye4(4/*子弹半径*/, 10/*移动速度*/, 500/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,4);
Bullet Enemy_BulTpye5(2/*子弹半径*/, 1/*移动速度*/, 300/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,5);
Bullet Enemy_BulTpye6(30/*子弹半径*/, 4/*移动速度*/, 1000/*伤害*/, 0/*表示是敌方子弹还是我方子弹*/,6);
Bullet My_BulTpye1(2/*子弹半径*/, 3/*移动速度*/, 20/*伤害*/, 1/*表示是敌方子弹还是我方子弹*/,1);
Bullet My_BulTpye2(2/*子弹半径*/, 10/*移动速度*/, 60/*伤害*/, 1/*表示是敌方子弹还是我方子弹*/,2);
//子弹数据负责人:丁真
//————————————————————————怪物,子弹数据相关————————————————————————
//————————————————————————全局变量相关————————————————————————

int Window_Width=1200;//窗口宽度
int Window_Height=760;//窗口高度
string Login_Password;//用户在登录界面输入的密码
string Login_ID;//用户在登录界面输入的ID
string Passback_ID;//用户在找回密码界面输入的ID
string Passback_Password;//用户在找回密码界面输入的密保
string last_id;
string Enroll_Name;//用户在注册界面输入的昵称
string Enroll_Password1;//用户在注册界面输入的密码
string Enroll_Password2;//用户在注册界面输入的密保
string Menu_ID;//登录的账户ID

bool Music;//音乐开关状态.1代表开0代表关
int Difficulty;//难度状态.1代表简单,2代表中等,3代表坤难
string Shop_Password;//用户输入的充值码
vector<Listelement> List;//排行榜数组
int Gold;//当前账户的金币数
int addGold;//充值码对应的金币数

int BaseV=0;//游戏界面,移速为1的物体的移速(每一帧移动的格数)
int BaseR=15;//游戏界面,半径为1的物体的像素大小
int CClock;//代表游戏时钟,用于辅助刷怪机制(无用)
int BaseNumber1;//怪1的基础刷新数量
int BaseNumber2;//怪2的基础刷新数量
int BaseNumber3;//怪3的基础刷新数量
int BaseNumber4;//怪4的基础刷新数量
int BaseNumber5;//怪4的基础刷新数量
bool isbossalive;//表示boss是否存活.1代表存活,0代表死亡
int MyPlaneDir;//表示我方飞机的移动方向数据
vector<Bullet> Enermy_Bullet;//储存敌方子弹的全局数组
vector<Plane> Enermy_Plane;//储存敌方飞机的全局数组
vector<Bullet> My_Bullet;//储存我方子弹的全局数组
Plane MyPlane;//我方飞机

int Game_Mark;//储存全局分数

class Listelement;//表示排行榜每一个元素
class Plane;//表示飞机的类
class Bullet;//表示子弹的类
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
    Boss_skillTime = 5; // 初始化Boss技能冷却时间
}

Plane::Plane(int _x, int _y, int _dir,double _v, double _r, int _health, int _type_bullet, bool _type, int _type_attack, int _clock, int _attack, int _mark, bool _isFlexible,int _Enemy_type) :
    x(_x), y(_y), dir(_dir),v(_v), r(_r), health(_health), type_bullet(_type_bullet), type(_type), type_attack(_type_attack), CClock(_clock), attack(_attack), mark(_mark), isFlexible(_isFlexible),Enemy_type(_Enemy_type),
    creationTime(std::chrono::high_resolution_clock::now()) {
    Boss_skillTime = 5; // 初始化Boss技能冷却时间
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

void Plane::time()//飞机时钟计时
{
    auto now = std::chrono::high_resolution_clock::now();
    auto timeSinceLastAttack = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastAttackTime).count();
    //double timeSinceLastAttack = timeSinceCreation() - lastAttackTime;
    if (timeSinceLastAttack >= attackCooldown) {
        Attack();
        lastAttackTime = now; // 更新最后攻击时间  
    }
    if (r == 7)//证明这个飞机是boss,调用boss专有技能
    {
        if ((int)timeSinceCreation() % Boss_skillTime == 0) {
            // 创建一个随机数生成器 ,使得随机发射3或4 
            std::random_device rd; // 用于获取随机种子  
            std::mt19937 gen(rd()); // 以随机种子初始化Mersenne Twister生成器  
            std::uniform_int_distribution<> dis(0, 1); // 定义分布范围[0, 1]
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
void Plane::Attack()//根据飞机时钟,飞机进行攻击
{
    //根据子弹类型,飞机攻击类型,创建并初始化数个子弹类对象,然后push_back入Bullet数组
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
//————————————————————————全局变量相关————————————————————————

