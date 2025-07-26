#include"Data.h"
extern int Window_Width;
extern int Window_Height;
extern std::string Login_Password;
extern std::string Login_ID;
extern std::string Passback_ID;
extern std::string Passback_Password;
extern std::string last_id;
extern std::string Enroll_Name;
extern std::string Enroll_Password1;
extern std::string Enroll_Password2;
extern std::string Menu_ID;
extern bool Music;
extern int Difficulty;
extern std::string Shop_Password;
extern std::vector<Listelement> List;
extern int Gold;
extern int addGold;

extern class Plane;
extern class Bullet;
extern int BaseV;
extern int CClock;
extern int BaseNumber1;
extern int BaseNumber2;
extern int BaseNumber3;
extern int BaseNumber4;
extern int BaseNumber5;
extern bool isbossalive;
extern int MyPlaneDir;
extern std::vector<Bullet> Enermy_Bullet;
extern std::vector<Plane> Enermy_Plane;
extern std::vector<Bullet> My_Bullet;
extern string Menu_Name;
extern class Listelement;

extern Plane Enemy1;
extern Plane Enemy2;
extern Plane Enemy3;
extern Plane Enemy4;
extern Plane Enemy5;
extern Plane Boss;

extern Bullet Enemy_BulTpye1;
extern Bullet Enemy_BulTpye2;
extern Bullet Boss_BulTpye3;
extern Bullet Boss_BulTpye4;
extern Bullet Boss_BulTpye5;
extern Bullet Enemy_BulTpye6;
extern Bullet My_BulTpye1;
extern Plane MyPlane;
extern int Game_Mark;
/*
负责人:腿毛
功能:
	根据储存用户账号密码的文件,以及全局变量Login_Paassword和Login_ID判断输入的ID与密码是否匹配.
类别:service
参数:void
返回值:bool,true代表登录成功,false代表失败
*/
bool Login_Wait_Judge();
bool Login_Wait_Judge() {
    string Uname;
    string Uid;
    string Upassword;

    fstream file_user;
    file_user.open("user.txt");

    if (!file_user.is_open()) {
        return false;
    }
    int i = 0;/*测试*/
    while (!file_user.eof()&&i<=100) {
        file_user >> Uname >> Uid >> Upassword;
        if (Uid == Login_ID && Upassword == Login_Password) {
            Menu_ID = Login_ID;
            return true;
        }
        i++;
    }
    file_user.close();
    return false;
}

/*
负责人:腿毛
功能:
	根据储存用户账号密码的文件,以及全局变量Passback_Paassword和Passback_ID判断输入的ID与密保是否匹配.
类别:service
参数:void
返回值:bool,true代表登录成功,false代表失败
*/
bool Passback_Wait_Judge();
bool Passback_Wait_Judge() {
    string Upassback_ID;
    string Upassback_Password;

    fstream file_passback;
    file_passback.open("passback.txt");

    if (!file_passback.is_open()) {
        return false;
    }

    while (!file_passback.eof()) {
        file_passback >> Upassback_ID >> Upassback_Password;
        if (Upassback_ID == Passback_ID && Upassback_Password == Passback_Password) {
            return true;
        }
    }
    file_passback.close();
    return false;
}

/*
负责人:腿毛
功能:返回密码
类别:service
参数:void
返回值:string
*/
string Passback_Wait_PasswordShow();
string Passback_Wait_PasswordShow() {
    string Uname;
    string Uid;
    string Upassword;

    fstream file_user;
    file_user.open("user.txt");

    if (!file_user.is_open()) {
        return "false";
    }

    while (!file_user.eof()) {
        file_user >> Uname >> Uid >> Upassword;
        if (Uid == Passback_ID)return Upassword;
    }
    file_user.close();
    return "你号没了";
}

/*
负责人:腿毛
功能:
	将全局变量Enroll_Name,Enroll_Paassword1和Enroll_Password2作为一个账户的三要素储存到文件中.
类别:service
参数:void
返回值:void
*/

void Enroll_Wait_Save();
void Enroll_Wait_Save() {

    string Enroll_id;
    fstream file_user;
    fstream file_passback;
    file_user.open("user.txt",std::ios::out | std::ios::app);
    file_passback.open("passback.txt", std::ios::out | std::ios::app);
    if (!file_passback.is_open() || !file_user.is_open()) {
        return;
    }
    //利用最后一个用户的id生成新id
    Enroll_id= to_string(stoi(last_id)+1);
    //分别存储到对应的文件中...
    file_user << Enroll_Name <<" " << Enroll_id <<" " << Enroll_Password1<<endl;
    file_passback << Enroll_id << " " << Enroll_Password2 << endl;
    file_passback.close();
    file_user.close();

    fstream file_rank;
    file_rank.open("rank.txt",std::ios::out | std::ios::app);

    //判断文件是否打开
    if (!file_rank.is_open()) {
        return;
    }
    file_rank << "1" << " "<<Enroll_id << " " << "0" << endl;
    file_rank << "2" << " "<<Enroll_id << " " << "0" << endl;
    file_rank << "3" << " "<<Enroll_id << " " << "0" << endl;

    file_rank.close();

    fstream file_gold;
    file_gold.open("gold.txt",std::ios::out | std::ios::app);

    //判断文件是否打开
    if (!file_gold.is_open()) {
        return;
    }
    file_gold << Enroll_id <<" "<< "0"<<endl;
    file_gold.close();

    return;
}
/*
负责人:腿毛
功能{
	返回登录账号的ID
	当前登录账号的ID可以在全局变量Menu_ID中获取
}
类别:service
参数:void
返回值:string
*/
string Menu_Get_ID();
string Menu_Get_ID() {
    return Menu_ID;
}

/*
负责人:腿毛
功能{
	返回登录账号的昵称
}
类别:service
参数:void
返回值:string
*/
string Menu_Get_Name();
string Menu_Get_Name() {
    string Uname;
    string Uid;
    string Upassword;

    fstream file_user;
    file_user.open("user.txt");

    if (!file_user.is_open()) {
        return "false";
    }

    while (!file_user.eof()) {
        file_user >> Uname >> Uid >> Upassword;
        if (Uid == Menu_Get_ID())return Uname;
    }
    file_user.close();
    return "嘻嘻你猜";
}

/*
负责人:腿毛
功能{
	返回登录账号的最高分
}
类别:service
参数:void
返回值:string
*/
string Menu_Get_Highest();
string Menu_Get_Highest() {
    fstream file_rank;
    file_rank.open("rank.txt");
    if (!file_rank.is_open()) {
        return "false";
    }
    int Udiff;
    string Uid;
    string Uhighest;
    while (!file_rank.eof()) {
        file_rank >> Udiff >> Uid >> Uhighest;
        if (Uid == Menu_Get_ID()&&Udiff==Difficulty)return Uhighest;
    }
    return "0";
}

/*
负责人:腿毛
功能:根据当前账号ID初始化全局变量Gold
类别:service
参数:void
返回值:void
*/
void Shop_init();
void Shop_init() {
    fstream file_gold;
    file_gold.open("gold.txt");

    //判断文件是否打开
    if (!file_gold.is_open()) {
        return;
    }

    //获取用户id
    string target_id = Menu_Get_ID();
    //读取文件中的gold
    while (!file_gold.eof()) {
        string uid;
        int ugold;
        file_gold >> uid >> ugold;
        if (uid == target_id) {
            Gold = ugold;
            file_gold.close();
            return;
        }
    }
    file_gold.close();
    return;
}

/*
负责人:腿毛
功能:
	根据储存充值码的文件,以及全局变量Shop_Paassword判断输入的充值码是否正确.
	若充值码正确,则将充值码对应的金币储存至全局变量addGold中
类别:service
参数:void
返回值:bool,true代表登录成功,false代表失败
*/
bool Shop_Wait_Judge();
bool Shop_Wait_Judge() {
    fstream file_recharge;
    file_recharge.open("recharge.txt");

    //判断文件是否打开
    if (!file_recharge.is_open()) {
        return false;
    }

    while (!file_recharge.eof()) {
        string recharge_code;
        cin >> recharge_code;
        if (Shop_Password == recharge_code) {
            file_recharge.close();
            return true;
        }
    }
    file_recharge.close();
    return false;
}

/*
负责人:腿毛
功能:
	根据难度参数,将排行榜信息储存至全局变量List中
类别:service
参数:int,难度参数
返回值:void
*/
void List_init(int);
void List_init(int Difficulty) {
    fstream file_rank;
    file_rank.open("rank.txt");

    //判断文件是否打开
    if (!file_rank.is_open()) {
        return;
    }
    List.clear();
    while (!file_rank.eof()) {
        int diff=0;
        string id;
        int highest=0;
        file_rank >> diff >> id >> highest;
        if (diff == Difficulty) {
            Listelement *other=new Listelement;
            (*other) = Listelement(id, List_Get_Name(id), highest);
            List.push_back(*other);
        }
    }
    for (int i = 0; i < List.size(); i++) {
        for (int j = 0; j < List.size() - 1 - i; j++) {
            if (List[j].gethighest() < List[j + 1].gethighest()) {
                Listelement num;
                num = List[j];
                List[j] = List[j + 1];
                List[j + 1] = num;
            }
        }
    }
    file_rank.close();
    return;
}

/*
负责人:九喜
功能:
	遍历敌方飞机数组{
		若飞机与某个我方子弹相撞,则调用attacked函数扣血.若飞机isalive()==0,那么将该飞机从全局数组中删除
		若飞机与主角相撞,那么主角利用该飞机的attack参数进行撞击掉血,并直接将该飞机从全局数组中删除,
		敌方飞机根据自身移动速度,移动方向调用移动函数进行移动
		}
	我方飞机也要进行发射子弹,判断是否被攻击以及移动这三个操作.若我方飞机isalive()==0,那么调用End_Show()函数转到结束界面
	遍历敌方子弹数组{
		子弹根据自身的移动速度及方向进行移动;
	}
	遍历我方子弹数组{
		子弹根据自身的移动速度及方向进行移动;
	}

类别:service
参数:void
返回值:void
*/
void Game_Run_RenewSituation();
int isattacked(int x1, int x2, int y1, int y2, int r1, int r2) {
    int R = r1 + r2;
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < R * R) {
        return 1;
    }
    else {
        return 0;
    }
}
void Game_Run_RenewSituation() {
    for (int i = 0; i < Enermy_Plane.size()&&i>=0; i++) {
        for (int j = 0; j < My_Bullet.size(); j++) {
            if (isattacked(Enermy_Plane[i].getX(), My_Bullet[j].getX(), Enermy_Plane[i].getY(), My_Bullet[j].getY(), Enermy_Plane[i].getR(), My_Bullet[j].getR()) == 1) {//敌方被击中
                Enermy_Plane[i].attacked(My_Bullet[j]);
                My_Bullet.erase(My_Bullet.begin() + j);
                j--;
                if (Enermy_Plane[i].isalive() == 0) {
                    Game_Mark+=Enermy_Plane[i].getMark();
                    Enermy_Plane.erase(Enermy_Plane.begin() + i);
                    i--;
                    break;
                }
            }//敌机受子弹袭击
        }
        if (i >= Enermy_Plane.size()||i<0) {
            break;
        }
        if (isattacked(Enermy_Plane[i].getX(), MyPlane.getX(), Enermy_Plane[i].getY(), MyPlane.getY(), Enermy_Plane[i].getR(), MyPlane.getR()) == 1) {//撞击
            MyPlane.attacked2(Enermy_Plane[i]);
            Enermy_Plane[i].getMark();
            Enermy_Plane.erase(Enermy_Plane.begin() + i);
            i--;
            continue;
        }//飞机撞击
        if (i >= Enermy_Plane.size() || i < 0) {
            break;
        }
        if (Enermy_Plane[i].isalive() != 0) {
            Enermy_Plane[i].Attack();
            Enermy_Plane[i].move();
            Enermy_Plane[i].RandomDir();
        }//敌机清除后发动进攻并进行移动
        
        if (Enermy_Plane[i].getFlexible() == 0) {
            if (Enermy_Plane[i].getX() < 0 || Enermy_Plane[i].getX() > 1200 || Enermy_Plane[i].getY() < 0 || Enermy_Plane[i].getY() > 760) {
                Enermy_Plane.erase(Enermy_Plane.begin() + i);
                i--;
                continue;
            }
        }//超出边界后erase后当前
        /*
        else {//需要反弹
            if (Enermy_Plane[i].getX() < 0) {
                if (Enermy_Plane[i].getDir() == 0) {
                    Enermy_Plane[i].setDir(4);
                }

                else {
                    if (Enermy_Plane[i].getDir() == 7) {
                        Enermy_Plane[i].setDir(1);
                    }
                    else {
                        Enermy_Plane[i].setDir(7);
                    }
                }
            }//左边
            if (Enermy_Plane[i].getX() > 1200) {
                if (Enermy_Plane[i].getDir() == 4) {
                    Enermy_Plane[i].setDir(0);
                }

                else {
                    if (Enermy_Plane[i].getDir() == 5) {
                        Enermy_Plane[i].setDir(3);
                    }
                    else {
                        Enermy_Plane[i].setDir(5);
                    }
                }
            }//右边
            if (Enermy_Plane[i].getY() < 0) {
                if (Enermy_Plane[i].getDir() == 2) {
                    Enermy_Plane[i].setDir(6);
                }

                else {
                    if (Enermy_Plane[i].getDir() == 1) {
                        Enermy_Plane[i].setDir(3);
                    }
                    else {
                        Enermy_Plane[i].setDir(1);
                    }
                }
            }//上边
            if (Enermy_Plane[i].getY() > 380) {
                if (Enermy_Plane[i].getDir() == 6) {
                    Enermy_Plane[i].setDir(2);
                }

                else {
                    if (Enermy_Plane[i].getDir() == 5) {
                        Enermy_Plane[i].setDir(7);
                    }
                    else {
                        Enermy_Plane[i].setDir(5);
                    }
                }
            }//下边
        }*/
    }

    for (int i = 0; i < Enermy_Bullet.size(); i++) {//遍历Enermy_Bullet
        Enermy_Bullet[i].move();//敌方子弹移动
        if (isattacked(MyPlane.getX(), Enermy_Bullet[i].getX(), MyPlane.getY(), Enermy_Bullet[i].getY(), MyPlane.getR(), Enermy_Bullet[i].getR()) == 1) {
                MyPlane.attacked(Enermy_Bullet[i]);
                Enermy_Bullet.erase(Enermy_Bullet.begin() + i);
                i--;
                continue;
        }//我方plane受击
        if (Enermy_Bullet[i].getBullet_type() == 5) {
            if (Enermy_Bullet[i].getCClock_Live() >= Enermy_Bullet[i].getTime_Live()) {
                Enermy_Bullet.erase(Enermy_Bullet.begin() + i);
                i--;
                continue;
            }
        }
        if (Enermy_Bullet[i].getX() < 0 || Enermy_Bullet[i].getX() > 1200 || Enermy_Bullet[i].getY() < 0 || Enermy_Bullet[i].getY() > 760) {
            Enermy_Bullet.erase(Enermy_Bullet.begin() + i);
            i--;
            continue;//超过边界删除
        }
    }
    if (MyPlane.isalive() == 0) {
        End_Show();
    }
    else {//我方飞机操作
        MyPlane.Attack();
        MyPlane.move();
    }
    for (int i = 0; i < My_Bullet.size(); i++) {//遍历我方子弹
            My_Bullet[i].move();
        if (My_Bullet[i].getX() < 0 || My_Bullet[i].getX() > 1200 || My_Bullet[i].getY() < 0 || My_Bullet[i].getY() > 760) {
            My_Bullet.erase(My_Bullet.begin() + i);//我方子弹移动和超边界删
            i--;
        }
    }
}

/*
负责人:腿毛
功能:
	1.全局变量计时器clock刷新.
		clock从30s开始往0s计时.当clock==0s且场上小怪都死了后刷新boss,clock刷新为30s.且在boss死亡(boss是否死亡记录在全局变量isbossalive中)之前clock不会继续计时.
	2.刷新敌机.
		刷新机制:
			从前一个boss死,到第二个boss出生中间30秒.
			这三十秒分为8个刷怪时间点:6秒(1),9秒(1),12秒(1,2),15秒(1,2),18秒(1,2,3),21秒(1,2,3),24秒(1,2,3,4),27秒(1,2,3,4).
			秒数的括号代表刷怪的种类.
			刷怪的基础数量储存在全局变量BaseNumber(数字,代表怪的种类)中.每进过一轮,每一个刷怪点刷出来的同种怪的数量+2
			刷怪的位置全为屏幕最上方,且水平位置随机
			刷新的怪全部要push_back入敌方战机数组中.
			当这一轮后所有的怪都死完后就刷boss,并将isbossalive调整为1;
类别:service
参数:void
返回值:void
*/
void Game_Run_RenewEnermy();
/*
    state_0表示前状态, state_1表示后状态.    1表示存活，0表示坠毁
    cur_round用于记录目前boss刷新的轮数
    startTime记录开始时间 currTime记录目前时间
*/
int cur_round = -1;
int state_0 = 1, state_1 = 1;
int renew_flag[8] = { 0 };
time_t startTime, currTime;
void Game_Run_RenewEnermy() {
    //保存前一个状态
    state_0 = state_1;

    //如果boss活着，直接退出刷新函数
    if (isbossalive) {
        state_1 = 1;
        return;
    }

    //boss坠毁记录最后状态
    state_1 = 0;

    //std::time(nullptr)函数返回当前的时间戳（自1970年1月1日以来的秒数），然后将其转换为无符号整数并作为srand()的参数，以设置随机数生成器的种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //判断boss坠毁瞬间,开始计时
    if (!state_1 && state_0) {
        for (int i = 0; i < 8; i++)renew_flag[i] = 0;
        cur_round++;
        startTime = time(NULL);
    }

    //获取目前时间并刷新敌机
    currTime = time(NULL);
    switch (currTime - startTime) {
    case 6: {
        if (!renew_flag[0]) {
            renew_flag[0] = 1;
            Plane* enemy;
            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++) {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 9: {
        if (!renew_flag[1]) {
            renew_flag[1] = 1;
            Plane* enemy;
            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 12: {
        if (!renew_flag[2]) {
            renew_flag[2] = 1;

            Plane* enemy;

            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 15: {
        if (!renew_flag[3]) {
            renew_flag[3] = 1;
            Plane* enemy;


            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }

            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 18: {
        if (!renew_flag[4]) {
            renew_flag[4] = 1;
            Plane* enemy;


            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }



            for (int i = 1; i <= BaseNumber3 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy3;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber5; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy5;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 21: {
        if (!renew_flag[5]) {
            renew_flag[5] = 1;
            Plane* enemy;

            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }



            for (int i = 1; i <= BaseNumber3 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy3;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber5 + 1; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy5;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            break;
        }
    }
    case 24: {
        if (!renew_flag[6]) {
            renew_flag[6] = 1;
            Plane* enemy;

            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }



            for (int i = 1; i <= BaseNumber3 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy3;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber4 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy4;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber5 + 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy5;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    case 27: {
        if (!renew_flag[7]) {
            renew_flag[7] = 1;
            Plane* enemy;

            for (int i = 1; i <= BaseNumber1 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy1;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }


            for (int i = 1; i <= BaseNumber2 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy2;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber3 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy3;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber4 + cur_round * 2; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy4;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
            for (int i = 1; i <= BaseNumber5 + 3; i++)
            {
                enemy = new Plane;
                *(enemy) = Enemy5;
                enemy->setX(rand() % 1200);
                enemy->setY(0);
                enemy->setDir(12);
                Enermy_Plane.push_back((*enemy));
            }
        }
        break;
    }
    default:break;
    }
           //怪都死完并且时间超过30s刷新boss
        if ((currTime - startTime) >= 30 && Enermy_Plane.empty()) {
            Plane* enemy = new Plane;
            isbossalive = 1;
            (*enemy) = Boss;
            (*enemy).sethealth(10000 + (cur_round + 1) * 2500);
            Enermy_Plane.push_back(*enemy);
        }
    }


/*
负责人:毕宿
功能:
	根据全局变量MyPlaneDir,修改我方飞机的移动方向;
类别:service
参数:void
返回值:void
*/
void Game_Run_SetDir();
void Game_Run_SetDir() {
    MyPlane.setDir(MyPlaneDir);
}


void Enroll_Wait_GetLastId() {//毕宿版权意识很强
    string Uname;
    string Uid;
    string Upassword;
    fstream file_user;
    file_user.open("user.txt");
    if (!file_user.is_open()) {
        return;
    }
    while (!file_user.eof()) {
        file_user >> Uname >> Uid >> Upassword;
    }
    if (Uid == "" || stoi(Uid) < 10000) {
        last_id = "10000";
    }
    else {
        last_id = to_string(stoi(Uid));
    }
}

string Menu_Print_GetHighest() {//毕宿版权意识很强
    string Uid;
    string Uhighest;
    fstream file_rank;
    file_rank.open("rank.txt");
    if (!file_rank.is_open()) {
        return "false";
    }
    while (!file_rank.eof()) {
        file_rank >> Uid >> Uhighest;
    }
    if (Uhighest == "") {
        Uhighest = "0";
    }

    file_rank.close();
    return Uhighest;
}
string List_Get_Name(string id) {
    string Uname;
    string Uid;
    string Upassword;

    fstream file_user;
    file_user.open("user.txt");

    if (!file_user.is_open()) {
        return "false";
    }

    while (!file_user.eof()) {
        file_user >> Uname >> Uid >> Upassword;
        if (Uid == id)return Uname;
    }
    file_user.close();
    return "嘻嘻你猜";
}