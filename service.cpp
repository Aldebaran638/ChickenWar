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
������:��ë
����:
	���ݴ����û��˺�������ļ�,�Լ�ȫ�ֱ���Login_Paassword��Login_ID�ж������ID�������Ƿ�ƥ��.
���:service
����:void
����ֵ:bool,true�����¼�ɹ�,false����ʧ��
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
    int i = 0;/*����*/
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
������:��ë
����:
	���ݴ����û��˺�������ļ�,�Լ�ȫ�ֱ���Passback_Paassword��Passback_ID�ж������ID���ܱ��Ƿ�ƥ��.
���:service
����:void
����ֵ:bool,true�����¼�ɹ�,false����ʧ��
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
������:��ë
����:��������
���:service
����:void
����ֵ:string
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
    return "���û��";
}

/*
������:��ë
����:
	��ȫ�ֱ���Enroll_Name,Enroll_Paassword1��Enroll_Password2��Ϊһ���˻�����Ҫ�ش��浽�ļ���.
���:service
����:void
����ֵ:void
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
    //�������һ���û���id������id
    Enroll_id= to_string(stoi(last_id)+1);
    //�ֱ�洢����Ӧ���ļ���...
    file_user << Enroll_Name <<" " << Enroll_id <<" " << Enroll_Password1<<endl;
    file_passback << Enroll_id << " " << Enroll_Password2 << endl;
    file_passback.close();
    file_user.close();

    fstream file_rank;
    file_rank.open("rank.txt",std::ios::out | std::ios::app);

    //�ж��ļ��Ƿ��
    if (!file_rank.is_open()) {
        return;
    }
    file_rank << "1" << " "<<Enroll_id << " " << "0" << endl;
    file_rank << "2" << " "<<Enroll_id << " " << "0" << endl;
    file_rank << "3" << " "<<Enroll_id << " " << "0" << endl;

    file_rank.close();

    fstream file_gold;
    file_gold.open("gold.txt",std::ios::out | std::ios::app);

    //�ж��ļ��Ƿ��
    if (!file_gold.is_open()) {
        return;
    }
    file_gold << Enroll_id <<" "<< "0"<<endl;
    file_gold.close();

    return;
}
/*
������:��ë
����{
	���ص�¼�˺ŵ�ID
	��ǰ��¼�˺ŵ�ID������ȫ�ֱ���Menu_ID�л�ȡ
}
���:service
����:void
����ֵ:string
*/
string Menu_Get_ID();
string Menu_Get_ID() {
    return Menu_ID;
}

/*
������:��ë
����{
	���ص�¼�˺ŵ��ǳ�
}
���:service
����:void
����ֵ:string
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
    return "�������";
}

/*
������:��ë
����{
	���ص�¼�˺ŵ���߷�
}
���:service
����:void
����ֵ:string
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
������:��ë
����:���ݵ�ǰ�˺�ID��ʼ��ȫ�ֱ���Gold
���:service
����:void
����ֵ:void
*/
void Shop_init();
void Shop_init() {
    fstream file_gold;
    file_gold.open("gold.txt");

    //�ж��ļ��Ƿ��
    if (!file_gold.is_open()) {
        return;
    }

    //��ȡ�û�id
    string target_id = Menu_Get_ID();
    //��ȡ�ļ��е�gold
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
������:��ë
����:
	���ݴ����ֵ����ļ�,�Լ�ȫ�ֱ���Shop_Paassword�ж�����ĳ�ֵ���Ƿ���ȷ.
	����ֵ����ȷ,�򽫳�ֵ���Ӧ�Ľ�Ҵ�����ȫ�ֱ���addGold��
���:service
����:void
����ֵ:bool,true�����¼�ɹ�,false����ʧ��
*/
bool Shop_Wait_Judge();
bool Shop_Wait_Judge() {
    fstream file_recharge;
    file_recharge.open("recharge.txt");

    //�ж��ļ��Ƿ��
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
������:��ë
����:
	�����ѶȲ���,�����а���Ϣ������ȫ�ֱ���List��
���:service
����:int,�ѶȲ���
����ֵ:void
*/
void List_init(int);
void List_init(int Difficulty) {
    fstream file_rank;
    file_rank.open("rank.txt");

    //�ж��ļ��Ƿ��
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
������:��ϲ
����:
	�����з��ɻ�����{
		���ɻ���ĳ���ҷ��ӵ���ײ,�����attacked������Ѫ.���ɻ�isalive()==0,��ô���÷ɻ���ȫ��������ɾ��
		���ɻ���������ײ,��ô�������ø÷ɻ���attack��������ײ����Ѫ,��ֱ�ӽ��÷ɻ���ȫ��������ɾ��,
		�з��ɻ����������ƶ��ٶ�,�ƶ���������ƶ����������ƶ�
		}
	�ҷ��ɻ�ҲҪ���з����ӵ�,�ж��Ƿ񱻹����Լ��ƶ�����������.���ҷ��ɻ�isalive()==0,��ô����End_Show()����ת����������
	�����з��ӵ�����{
		�ӵ�����������ƶ��ٶȼ���������ƶ�;
	}
	�����ҷ��ӵ�����{
		�ӵ�����������ƶ��ٶȼ���������ƶ�;
	}

���:service
����:void
����ֵ:void
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
            if (isattacked(Enermy_Plane[i].getX(), My_Bullet[j].getX(), Enermy_Plane[i].getY(), My_Bullet[j].getY(), Enermy_Plane[i].getR(), My_Bullet[j].getR()) == 1) {//�з�������
                Enermy_Plane[i].attacked(My_Bullet[j]);
                My_Bullet.erase(My_Bullet.begin() + j);
                j--;
                if (Enermy_Plane[i].isalive() == 0) {
                    Game_Mark+=Enermy_Plane[i].getMark();
                    Enermy_Plane.erase(Enermy_Plane.begin() + i);
                    i--;
                    break;
                }
            }//�л����ӵ�Ϯ��
        }
        if (i >= Enermy_Plane.size()||i<0) {
            break;
        }
        if (isattacked(Enermy_Plane[i].getX(), MyPlane.getX(), Enermy_Plane[i].getY(), MyPlane.getY(), Enermy_Plane[i].getR(), MyPlane.getR()) == 1) {//ײ��
            MyPlane.attacked2(Enermy_Plane[i]);
            Enermy_Plane[i].getMark();
            Enermy_Plane.erase(Enermy_Plane.begin() + i);
            i--;
            continue;
        }//�ɻ�ײ��
        if (i >= Enermy_Plane.size() || i < 0) {
            break;
        }
        if (Enermy_Plane[i].isalive() != 0) {
            Enermy_Plane[i].Attack();
            Enermy_Plane[i].move();
            Enermy_Plane[i].RandomDir();
        }//�л�����󷢶������������ƶ�
        
        if (Enermy_Plane[i].getFlexible() == 0) {
            if (Enermy_Plane[i].getX() < 0 || Enermy_Plane[i].getX() > 1200 || Enermy_Plane[i].getY() < 0 || Enermy_Plane[i].getY() > 760) {
                Enermy_Plane.erase(Enermy_Plane.begin() + i);
                i--;
                continue;
            }
        }//�����߽��erase��ǰ
        /*
        else {//��Ҫ����
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
            }//���
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
            }//�ұ�
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
            }//�ϱ�
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
            }//�±�
        }*/
    }

    for (int i = 0; i < Enermy_Bullet.size(); i++) {//����Enermy_Bullet
        Enermy_Bullet[i].move();//�з��ӵ��ƶ�
        if (isattacked(MyPlane.getX(), Enermy_Bullet[i].getX(), MyPlane.getY(), Enermy_Bullet[i].getY(), MyPlane.getR(), Enermy_Bullet[i].getR()) == 1) {
                MyPlane.attacked(Enermy_Bullet[i]);
                Enermy_Bullet.erase(Enermy_Bullet.begin() + i);
                i--;
                continue;
        }//�ҷ�plane�ܻ�
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
            continue;//�����߽�ɾ��
        }
    }
    if (MyPlane.isalive() == 0) {
        End_Show();
    }
    else {//�ҷ��ɻ�����
        MyPlane.Attack();
        MyPlane.move();
    }
    for (int i = 0; i < My_Bullet.size(); i++) {//�����ҷ��ӵ�
            My_Bullet[i].move();
        if (My_Bullet[i].getX() < 0 || My_Bullet[i].getX() > 1200 || My_Bullet[i].getY() < 0 || My_Bullet[i].getY() > 760) {
            My_Bullet.erase(My_Bullet.begin() + i);//�ҷ��ӵ��ƶ��ͳ��߽�ɾ
            i--;
        }
    }
}

/*
������:��ë
����:
	1.ȫ�ֱ�����ʱ��clockˢ��.
		clock��30s��ʼ��0s��ʱ.��clock==0s�ҳ���С�ֶ����˺�ˢ��boss,clockˢ��Ϊ30s.����boss����(boss�Ƿ�������¼��ȫ�ֱ���isbossalive��)֮ǰclock���������ʱ.
	2.ˢ�µл�.
		ˢ�»���:
			��ǰһ��boss��,���ڶ���boss�����м�30��.
			����ʮ���Ϊ8��ˢ��ʱ���:6��(1),9��(1),12��(1,2),15��(1,2),18��(1,2,3),21��(1,2,3),24��(1,2,3,4),27��(1,2,3,4).
			���������Ŵ���ˢ�ֵ�����.
			ˢ�ֵĻ�������������ȫ�ֱ���BaseNumber(����,����ֵ�����)��.ÿ����һ��,ÿһ��ˢ�ֵ�ˢ������ͬ�ֵֹ�����+2
			ˢ�ֵ�λ��ȫΪ��Ļ���Ϸ�,��ˮƽλ�����
			ˢ�µĹ�ȫ��Ҫpush_back��з�ս��������.
			����һ�ֺ����еĹֶ�������ˢboss,����isbossalive����Ϊ1;
���:service
����:void
����ֵ:void
*/
void Game_Run_RenewEnermy();
/*
    state_0��ʾǰ״̬, state_1��ʾ��״̬.    1��ʾ��0��ʾ׹��
    cur_round���ڼ�¼Ŀǰbossˢ�µ�����
    startTime��¼��ʼʱ�� currTime��¼Ŀǰʱ��
*/
int cur_round = -1;
int state_0 = 1, state_1 = 1;
int renew_flag[8] = { 0 };
time_t startTime, currTime;
void Game_Run_RenewEnermy() {
    //����ǰһ��״̬
    state_0 = state_1;

    //���boss���ţ�ֱ���˳�ˢ�º���
    if (isbossalive) {
        state_1 = 1;
        return;
    }

    //boss׹�ټ�¼���״̬
    state_1 = 0;

    //std::time(nullptr)�������ص�ǰ��ʱ�������1970��1��1����������������Ȼ����ת��Ϊ�޷�����������Ϊsrand()�Ĳ����������������������������
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //�ж�boss׹��˲��,��ʼ��ʱ
    if (!state_1 && state_0) {
        for (int i = 0; i < 8; i++)renew_flag[i] = 0;
        cur_round++;
        startTime = time(NULL);
    }

    //��ȡĿǰʱ�䲢ˢ�µл�
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
           //�ֶ����겢��ʱ�䳬��30sˢ��boss
        if ((currTime - startTime) >= 30 && Enermy_Plane.empty()) {
            Plane* enemy = new Plane;
            isbossalive = 1;
            (*enemy) = Boss;
            (*enemy).sethealth(10000 + (cur_round + 1) * 2500);
            Enermy_Plane.push_back(*enemy);
        }
    }


/*
������:����
����:
	����ȫ�ֱ���MyPlaneDir,�޸��ҷ��ɻ����ƶ�����;
���:service
����:void
����ֵ:void
*/
void Game_Run_SetDir();
void Game_Run_SetDir() {
    MyPlane.setDir(MyPlaneDir);
}


void Enroll_Wait_GetLastId() {//���ް�Ȩ��ʶ��ǿ
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

string Menu_Print_GetHighest() {//���ް�Ȩ��ʶ��ǿ
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
    return "�������";
}