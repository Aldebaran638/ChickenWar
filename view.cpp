#define _CRT_SECURE_NO_WARNINGS
#include"Data.h"
extern int Window_Width;
extern int Window_Height;
extern std::string Login_Password;
extern std::string Login_ID;
extern std::string Passback_ID;
extern std::string Passback_Password;
extern string last_id;
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
extern int BaseR;
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
extern class Listelement;

extern Plane Enemy1;
extern Plane Enemy2;
extern Plane Enemy3;
extern Plane Enemy4;
extern Plane Enemy5; 
extern Plane Boss;

extern Bullet Enemy_BulTpye1;
extern Bullet Enemy_BulTpye2;
extern Bullet Enemy_BulTpye3;
extern Bullet Enemy_BulTpye4;
extern Bullet Enemy_BulTpye5;
extern Bullet Enemy_BulTpye6;
extern Bullet My_BulTpye1;
extern Bullet My_BulTpye2;
extern Plane MyPlane;
extern int Game_Mark;//����ȫ�ַ���
extern int cur_round ;//ˢ�����ȫ�ֱ���
extern int state_0, state_1;
extern int renew_flag[8];
extern time_t startTime, currTime;
#pragma comment(lib,"MSIMG32.LIB")

IMAGE m5;

int Plane1_w = Enemy1.getR() * 2;
int Plane1_h = Enemy1.getR() * 2;
int Plane2_w = Enemy2.getR() * 2;
int Plane2_h = Enemy2.getR() * 2;
int Plane3_w = Enemy3.getR() * 2;
int Plane3_h = Enemy3.getR() * 2;
int Plane4_w = Enemy4.getR() * 2;
int Plane4_h = Enemy4.getR() * 2;
int Plane5_w = Enemy5.getR() * 2;
int Plane5_h = Enemy5.getR() * 2;
int Plane6_w = Boss.getR() * 2;//Boss
int Plane6_h = Boss.getR() * 2;
int Bullet1_w = Enemy_BulTpye1.getR() * 2;
int Bullet1_h = Enemy_BulTpye1.getR() * 2;
int Bullet2_w = Enemy_BulTpye2.getR() * 2;
int Bullet2_h = Enemy_BulTpye2.getR() * 2;
int Bullet3_w = Enemy_BulTpye3.getR() * 2;
int Bullet3_h = Enemy_BulTpye3.getR() * 2;
int Bullet4_w = Enemy_BulTpye4.getR() * 2;
int Bullet4_h = Enemy_BulTpye4.getR() * 2;
int Bullet5_w = Enemy_BulTpye5.getR() * 2;
int Bullet5_h = Enemy_BulTpye5.getR() * 2;
int Bullet6_w = Enemy_BulTpye6.getR() * 2;
int Bullet6_h = Enemy_BulTpye6.getR() * 2;
int MyBullet1_w = My_BulTpye1.getR() * 2;
int MyBullet1_h = My_BulTpye1.getR() * 2;
int MyBullet2_w = My_BulTpye2.getR() * 2;
int MyBullet2_h = My_BulTpye2.getR() * 2;
IMAGE EnemyBullet_1, EnemyBullet_2, EnemyBullet_3, EnemyBullet_4, EnemyBullet_5, EnemyBullet_6, EnemyPlane_1, EnemyPlane_2, EnemyPlane_3, EnemyPlane_4, EnemyPlane_5, EnemyPlane_6, MyBullet_1, MyBullet_2;
IMAGE m4;
inline void putimage_Alpha(int x, int y, IMAGE* img) {
    int w = img->getheight();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

string bs_WStringTostring(const std::wstring& wstr)
{
    // ����һ��ת��������
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    // ʹ��ת������ wstring ת��Ϊ string
    return converter.to_bytes(wstr);
}

wstring bs_stringToWString(const std::string& str) {
    wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}
/*
������:�鳤
����{
	��ս���
	��ʼ���������¼��ص�ȫ�ֱ���
	��ӡ����ͼ
	��ӡ��¼,ע��,���������Լ��˳��ĸ���ť
	�ȴ��û��������.���û������Ӧ��ť,�������Ӧ��Show����
}
���:view
����:void
����ֵ:void
*/
void Home_Show();//û����
void Home_Show()
{
    MOUSEMSG Mouse;//�������
    int Window_Width = 752;
    int Window_Height = 1196;
    int GR_Width = 2200;
    int GR_Height = 600;
    int L = 1030;//��������߽�
    int R = 1170;//�������ұ߽�
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    IMAGE img_kun1;
    //
    //ͼƬΪ����·��������ʱ�޸ģ�����
    //
    loadimage(&img_kun1, L".\\�ز�ͼ\\��ҳ.jpg",1200,760,true);
    putimage(0, 0, &img_kun1);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, L"SimHei");
    setfillcolor(RGB(103, 229, 215));//�������������ɫ
    fillroundrect(L, 365, R, 435, 10, 10);//���ƾ��κ��������
    outtextxy(GR_Width / 2 - textwidth(L"��¼") / 2,
        GR_Height / 2 + 100 - textheight(L"��¼") / 2, L"��¼");
    fillroundrect(L, 465, R, 535, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"ע��") / 2,
        GR_Height / 2 + 200 - textheight(L"ע��") / 2, L"ע��");
    fillroundrect(L, 565, R, 635, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"��������") / 2,
        GR_Height / 2 + 300 - textheight(L"��������") / 2, L"��������");
    fillroundrect(L, 665, R, 735, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"�˳�") / 2,
        GR_Height / 2 + 400 - textheight(L"�˳�") / 2, L"�˳�");
    while (1) {
        if (MouseHit()) {
            //��ȡ�����Ϣ
            Mouse = GetMouseMsg();
            //�û�������ڰ�ť��Χ�ڣ����Ұ������
            if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 365 && Mouse.y <= 435 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Login_Show();//��¼
                cout << 0;
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 465 && Mouse.y <= 535 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Enroll_Show();//ע��
                cout << 1;
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 565 && Mouse.y <= 635 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Passback_Show();//��������
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 665 && Mouse.y <= 735 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                exit(0);//ֱ���˳�����
            }
        }
    }
}
/*
������:����
����:��ʼ����Login������ص�����
���:��(ָǰ�����������)
����:void
����ֵ:void
*/
void Login_init();
void Login_init()
{
    Login_Password = " ";
    Login_ID = " ";
}

//
//
int tx_1 = 400, ty_1 = 280;//��һ�����ֵ�λ��
wchar_t text_1[] = L"�������˻�id";//����Ҫ��ӡ�����֣���һ�����֣�
int tx_2 = 390, ty_2 = 350;//���ǵڶ������ֵ�λ�ã�tx_2�������tx_1��10.��Ϊ���������ı�����룩
wchar_t text_2[] = L"�������˻�����";//����Ҫ��ӡ�����֣��ڶ������֣�
wchar_t str[] = L"��¼";//����Ҫ��ӡ�����֣����������֣�
wchar_t str_1[] = L"����";//����Ҫ��ӡ�����֣����ĸ����֣�
//��һ�����ο�id��
int rectX_1 = tx_1 + 90; // 10���ı��;���֮��ļ��
int rectY_1 = ty_1 - 20;
int rectWidth_1 = 150; // ���εĿ��
int rectHeight_1 = 40; // ���εĸ߶�
//�ڶ������ο������
int rectX_2 = tx_2 + 100; // 10���ı��;���֮��ļ��
int rectY_2 = ty_2 - 20;
int rectWidth_2 = 150; // ���εĿ��
int rectHeight_2 = 40; // ���εĸ߶�
//��������--Բ�Ǿ��ο򣨵�¼��
int rx = rectX_2 + 15;
int ry = rectY_2 + 50;
int rw = rectWidth_2 - 40;
int rh = rectHeight_2 + 20;
//���ĸ���----Բ�Ǿ��ο򣨷��ؿ�
int rx_2 = rx;
int ry_2 = ry + 70;
int rw_2 = rw;
int rh_2 = rh;

/*
������:����
����:��ӡ����ͼ,��ӡID������������Լ����غ͵�¼��ť
���:view
����:void
����ֵ:void
*/
void hui_13(int x, int y, int h, const wchar_t str[])//��������
{
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    int vSpace = ((h - textheight(str)) / 2);
    outtextxy(x, y + vSpace, str);
}
void hui_14(int x, int y, int h, LPCWSTR str)//��������
{
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    int vSpace = ((h - textheight(str)) / 2);
    outtextxy(x, y + vSpace, str);
}
//
//
void hui_1()//�����������˻�id�����Լ������
{   //1 ��ӡ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextcolor(BLACK);//����������ɫ
    settextstyle(12, 0, L"����");//���������С����ϸ������
    outtextxy(tx_1, ty_1, text_1);//�������

    //��ƾ��ο�
    setfillcolor(WHITE);//������ɫ
    fillrectangle(rectX_1, rectY_1, rectX_1 + rectWidth_1, rectY_1 + rectHeight_1);
}
void hui_2()//�����������˻����������Լ������
{

    //2 ��ӡ�������˻���������
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextcolor(BLACK);//����������ɫ
    settextstyle(12, 0, L"����");//���������С����ϸ������
    outtextxy(tx_2, ty_2, text_2);//�������
    //��ƾ��ο�
    setfillcolor(WHITE);//������ɫ
    fillrectangle(rectX_2, rectY_2, rectX_2 + rectWidth_2, rectY_2 + rectHeight_2);//����Ĳ�ȫ����2��Ϊ�˺�����Ŀ����
}


void hui_3()//���Ƶ�¼��ť
{


    //3 ��ӡ��¼��ť
    //��һ������
    setfillcolor(RGB(216, 221, 223));
    solidroundrect(rx, ry, rx + rw, ry + rh, 10, 10);
    //��������
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    int wSpace = ((rw - textwidth(str)) / 2);
    int vSpace = ((rh - textheight(str)) / 2);
    outtextxy(rx + wSpace, ry + vSpace, str);
}
void hui_4()//���Ʒ��ذ�ť
{

    //4 ��ӡ���ذ�ť
    //��һ������
    setfillcolor(RGB(216, 221, 223));
    solidroundrect(rx_2, ry_2, rx_2 + rw_2, ry_2 + rh_2, 10, 10);
    //��������
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    int wSpace_2 = ((rw_2 - textwidth(str_1)) / 2);
    int vSpace_2 = ((rh_2 - textheight(str_1)) / 2);
    outtextxy(rx_2 + wSpace_2, ry_2 + vSpace_2, str_1);
}

/*
������:����
����:��ӡ����ͼ,��ӡID������������Լ����غ͵�¼��ť
���:view
����:void
����ֵ:void
*/
void Login_Print();
void Login_Print()
{

    //0����ͼƬ
    IMAGE img;
    loadimage(&img, L".\\�ز�ͼ\\��ҳ��.png", Window_Width, Window_Height); // �滻Ϊ���ͼƬ�ļ���
    // ��ͼƬ���Ƶ������ϣ���Ϊ����
    // ע�⣺Ĭ�ϴ�(0,0)���꿪ʼ���ƣ������ڵ����Ͻ�
    putimage(0, 0, &img);
    hui_1();
    hui_2();
    hui_3();
    hui_4();
}


bool inArea(int mx, int my, int x, int y, int w, int h)
{
    if (mx > x && mx<x + w && my>y && my < y + h)
    {
        return true;
    }
    return false;
}
bool button(int x, int y, int w, int h, ExMessage& msg)//���밴ť��λ�ã��ж�����Ƿ�����ť
{
    if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
    {
        return true;
    }
    return false;
}


/*
������:����
����:
	����while(1)ѭ�����ȴ��û��������.{
		���û����ID�����,�򵯳�ID�����,�����û������ID������ID����������Login_ID��
		���û�������������,�򵯳����������,�����û���������벢�������봢��������Login_Password��
		���û������¼,�����Login_Wait_Judge()�����ж�ID�������Ƿ�Ϸ�.���Ϸ�,�����ʾ��,��Login_ID��ֵ������Menu_ID��,������Menu_Show����;�����Ϸ�,�������ʾ��;
		���û��������,�����Home_Show����;
	}
���:view
����:void
����ֵ:void
*/
void Login_Wait();
void Login_Wait()
{
    //�����û������ID
    ExMessage msg_1;

    msg_1 = getmessage(EX_MOUSE);
    while (1)
    {
        //��ȡ��Ϣ
        if (peekmessage(&msg_1, EX_MOUSE))
        {
            if (button(rectX_1, rectY_1, rectWidth_1, rectHeight_1, msg_1))//������ID�����
            {
                // �����ַ������������������û�����
                wchar_t s[16];
                InputBox(s, 16, L"������ID");
                //���´�ӡ����򣬰�֮ǰ����ĸ��ǵ��������ӾͿ�������������ֲ����ص�
                setfillcolor(WHITE);//������ɫ
                fillrectangle(rectX_1, rectY_1, rectX_1 + rectWidth_1, rectY_1 + rectHeight_1);
                wstring num(s);
                Login_ID = bs_WStringTostring(num);
                const char* cstr = Login_ID.c_str();     // �� std::string ת��Ϊ C ����ַ���
                size_t wideStringLength = mbstowcs(nullptr, cstr, 0) + 1;  // ������ַ�������Ĵ�С
                wchar_t* wideString = new wchar_t[wideStringLength];  // �����ڴ�

                // ʵ��ִ��ת��
                mbstowcs(wideString, cstr, wideStringLength);

                hui_13(rectX_1, rectY_1, rectHeight_1, wideString);
            }
            else if (button(rectX_2, rectY_2, rectWidth_2, rectHeight_2, msg_1))//���������������
            {
                wchar_t s_2[16];
                InputBox(s_2, 16, L"����������");
                //���´�ӡ����򣬰�֮ǰ����ĸ��ǵ��������ӾͿ�������������ֲ����ص�
                setfillcolor(WHITE);//������ɫ
                fillrectangle(rectX_2, rectY_2, rectX_2 + rectWidth_2, rectY_2 + rectHeight_2);
                wstring num_2(s_2);
                Login_Password = bs_WStringTostring(num_2);
                const char* cstr_2 = Login_Password.c_str();     // �� std::string ת��Ϊ C ����ַ���
                size_t wideStringLength = mbstowcs(nullptr, cstr_2, 0) + 1;  // ������ַ�������Ĵ�С
                wchar_t* wideString = new wchar_t[wideStringLength];  // �����ڴ�

                // ʵ��ִ��ת��
                mbstowcs(wideString, cstr_2, wideStringLength);

                hui_14(rectX_2, rectY_2, rectHeight_2, wideString);

            }
            else if (button(rx, ry, rw, rh, msg_1))//��������¼��ť
            {
                if (Login_Wait_Judge())//�ж�ID�������Ƿ�Ϸ�
                {
                    outtextxy(10, 10, L"��¼�ɹ�");
                    Sleep(1000);
                    Menu_init();
                    Menu_Show();
                }
                else
                {
                    outtextxy(10, 10, L"��¼ʧ��");
                    Menu_ID = "";
                }
            }
            else if (button(rx_2, ry_2, rw_2, rh_2, msg_1))//���������ذ�ť
            {
                outtextxy(50, 10, L"���سɹ�");
                Sleep(1000);
                Home_Show();
            }
        }
    }
}

/*
������:����
����:
	��ս���
	Login_Print()
	Login_Wait()
���:view
����:void
����ֵ:void
*/
void Login_Show();
void Login_Show()
{
    cleardevice();
    Login_Print();
    Login_Wait();
}

int width_character3 = 15;//��ʾ�ʿ��
int height_character3 = 30;//��ʾ�ʸ߶�

int width_button1 = 150;//��ť���
int height_button1 = 40;//��ť�߶�
int x_button1 = 600 - 75;//��һ����ť���Ͻǵ�xֵ
int y_button1 = 500;//��һ����ť���Ͻǵ�yֵ
int distance_button1 = 60;//������ť֮��ĸ߶Ȳ�
int n_button1 = 2;//��ť����
int width_character1 = 15;//���ֿ��
int height_character1 = 30;//���ָ߶�
vector<wstring> text_button1 = { L"�һ�", L"����" };//ÿ����ť�ϵ��ı�

void draw0() {//��ӡ��ʾ��
    setfillcolor(WHITE);
    fillroundrect(790, 490, 1100, 600, 10, 10);
}

void draw1() {//�������������ӡn��δ����״̬�İ�ť
    settextstyle(height_character1, width_character1, _T("FangSong"));
    setfillcolor(WHITE);//������ťԭ���ı�����ɫ
    settextcolor(BLACK);//�����ı���ɫ
    for (int i = 0; i < n_button1; i++) {
        fillroundrect(x_button1, y_button1 + i * distance_button1, x_button1 + width_button1, y_button1 + i * distance_button1 + height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((x_button1 + x_button1 + width_button1) / 2 - textwidth(text_button1[i].c_str()) / 2), (y_button1 + i * distance_button1 + y_button1 + i * distance_button1 + height_button1) / 2 - textheight(text_button1[i].c_str()) / 2.0, text_button1[i].c_str());
    }
}

void check1()//��鰴�Ƿ񱻴���.��������ı䰴ť��ʽ
{
    ExMessage m;

    static int POSITION = 0;
    m = getmessage(EX_MOUSE || EX_KEY);
    int sign = 0;
    for (int i = 0; i < n_button1; i++) {
        if (m.x >= x_button1 && m.x <= x_button1 + width_button1 && m.y >= y_button1 + i * distance_button1 && m.y <= y_button1 + i * distance_button1 + height_button1) {
            sign = 1;
            if (POSITION != i) {
                draw1();
                setfillcolor(GREEN);//������ť��ɫ
                settextcolor(RED);//������ť���ı���ɫ
                fillroundrect(x_button1, y_button1 + i * distance_button1, x_button1 + width_button1, y_button1 + i * distance_button1 + height_button1, 10, 10);
                setbkmode(TRANSPARENT);
                outtextxy((int)((x_button1 + x_button1 + width_button1) / 2 - textwidth(text_button1[i].c_str()) / 2), (y_button1 + i * distance_button1 + y_button1 + i * distance_button1 + height_button1) / 2 - textheight(text_button1[i].c_str()) / 2.0, text_button1[i].c_str());
                POSITION = i;
                break;
            }
            if (m.message == WM_LBUTTONDOWN) {
                settextstyle(height_character3, width_character3, _T("FangSong"));
                if (i == 0) {
                    if (Passback_Wait_Judge()) {
                        draw0();
                        outtextxy(800, 500, L"���������ǣ�");
                        outtextxy(800, 550, bs_stringToWString(Passback_Wait_PasswordShow()).c_str());
                    }
                    else {
                        draw0();
                        outtextxy(800, 500, L"�˺Ż��ܱ��𰸴���");

                    }
                }
                else if (i == 1) {
                    Home_Show();
                }
                settextstyle(height_character1, width_character1, _T("FangSong"));
            }
        }
    }
    if (!sign) {
        POSITION = n_button1;
        draw1();
    }

}

int width_button2 = 400;//��ť���
int height_button2 = 50;//��ť�߶�
int x_button2 = 600 - 200;//��һ����ť���Ͻǵ�xֵ
int y_button2 = 200;//��һ����ť���Ͻǵ�yֵ
int distance_button2 = 60;//������ť֮��ĸ߶Ȳ�
int n_button2 = 2;//��ť����
int width_character2 = 15;//���ֿ��
int height_character2 = 30;//���ָ߶�
vector<wstring> text_button2 = { L"������ID",L"�������ܱ�" };//ÿ����ť�ϵ��ı�
void draw2() {//�������������ӡn��δ����״̬�İ�ť
    settextstyle(height_character2, width_character2, _T("FangSong"));
    setfillcolor(WHITE);//������ťԭ���ı�����ɫ
    settextcolor(BLACK);//�����ı���ɫ
    for (int i = 0; i < n_button2; i++) {
        fillroundrect(x_button2, y_button2 + i * distance_button2, x_button2 + width_button2, y_button2 + i * distance_button2 + height_button2, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((x_button2 + x_button2 + width_button2) / 2 - textwidth(text_button2[i].c_str()) / 2), (y_button2 + i * distance_button2 + y_button2 + i * distance_button2 + height_button2) / 2 - textheight(text_button2[i].c_str()) / 2.0, text_button2[i].c_str());
    }
}
void check2()//��鰴�Ƿ񱻴���.��������ı䰴ť��ʽ
{
    ExMessage m;

    static int POSITION = 0;
    m = getmessage(EX_MOUSE || EX_KEY);
    int sign = 0;
    for (int i = 0; i < n_button2; i++) {
        if (m.x >= x_button2 && m.x <= x_button2 + width_button2 && m.y >= y_button2 + i * distance_button2 && m.y <= y_button2 + i * distance_button2 + height_button2) {
            sign = 1;
            if (POSITION != i) {
                if (m.message == WM_LBUTTONDOWN) {
                    wchar_t num[16];
                    if (i == 0) {
                        InputBox(num, 16, L"������ID");
                        wstring num2(num);
                        text_button2[i] = num2;
                        Passback_ID = bs_WStringTostring(num2);
                    }
                    else if (i == 1) {
                        InputBox(num, 16, L"�������ܱ�");
                        wstring num2(num);
                        text_button2[i] = num2;
                        Passback_Password = bs_WStringTostring(num2);
                    }
                }
            }
        }
    }
    if (!sign) {
        POSITION = n_button2;
        draw2();
    }

}

/*
������:����
����:��ʼ����Passback������ص�����
���:��(ָǰ�����������)
����:void
����ֵ:void
*/
void Passback_init();
void Passback_init() {
    string Passback_ID = "";
    string Passback_Password = "";
}

/*
������:����
����:��ӡ����ͼ,��ӡID���ܱ�������Լ����غ��һ����밴ť
���:view
����:void
����ֵ:void
*/
void Passback_Print();
void Passback_Print() {
    IMAGE background;
    loadimage(&background, L".\\�ز�ͼ\\��ҳ��.png", 1200, 760, true);
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    settextstyle(height_character2/1.5, width_character2/1.5, _T("FangSong"));
    outtextxy(350, (y_button2 + 0 * distance_button2 + y_button2 + 0 * distance_button2 + height_button2) / 2 - textheight(text_button2[0].c_str()) / 2.0, L"ID��");
    outtextxy(350, (y_button2 + 1 * distance_button2 + y_button2 + 1 * distance_button2 + height_button2) / 2 - textheight(text_button2[1].c_str()) / 2.0, L"�ܱ���");
    draw1();
    draw2();
}

/*
������:����
����:
	����while(1)ѭ�����ȴ��û��������.{
		���û����ID�����,�򵯳�ID�����,�����û������ID������ID����������Passback_ID��
		���û�����ܱ������,�򵯳��ܱ������,�����û���������벢�������봢��������Passback_Password��
		���û�����һ�,�����Passback_Wait_Judge()�����ж�ID���ܱ��Ƿ�Ϸ�.���Ϸ�,�����ʾ�ʲ�����Passback_Wait_PasswordShow�������;�����Ϸ�,�������ʾ��;
		���û��������,�����Home_Show����;
	}
���:view
����:void
����ֵ:void
*/
void Passback_Wait();
void Passback_Wait() {
    while (1) {
        check1();
        check2();
    }
}

/*
������:����
����:
	��ս���
	Passback_Print()
	Passback_Wait()
���:view
����:void
����ֵ:void
*/
void Passback_Show();
void Passback_Show() {
    cleardevice();
    Passback_init();
    Passback_Print();
    Passback_Wait();
}

/*
������:�
����:��ʼ����Enroll������ص�����
���:��(ָǰ�����������)
����:void
����ֵ:void
*/
void Enroll_init();
void Enroll_init()
{
    Enroll_Name = "";
    Enroll_Password1 = "";
    Enroll_Password2 = "";
    Menu_ID = "10001";
}

/*
������:�
����:��ӡ����ͼ,��ӡ�ǳ�,������ܱ�������Լ����غ�ע�ᰴť
���:view
����:void
����ֵ:void
*/
void Enroll_Print();
void Enroll_Print()
{
    initgraph(1200, 760, 1);
    IMAGE image;
    loadimage(&image, L".\\�ز�ͼ\\��ҳ��.png", 1200, 760);
    putimage(0, 0, &image);


    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(500, 230, 500 + 200, 230 + 42, 10, 10);
    wchar_t text1[] = L"�������˺��ǳ�";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"����");
    outtextxy(530, 240, text1);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(500, 280, 500 + 200, 280 + 42, 10, 10);
    wchar_t text2[] = L"�������˺�����";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"����");
    outtextxy(530, 290, text2);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(500, 330, 500 + 200, 330 + 42, 10, 10);
    wchar_t text3[] = L"�������ܱ���";
    wchar_t text[] = L"���������ǣ�";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"����");
    outtextxy(530, 340, text3);
    outtextxy(390, 340, text);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(530, 380, 530 + 150, 380 + 42, 10, 10);
    wchar_t text4[] = L"ע��";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"����");
    outtextxy(584, 390, text4);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(530, 430, 530 + 150, 430 + 42, 10, 10);
    wchar_t text5[] = L"����";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"����");
    outtextxy(584, 440, text5);
}

bool checkName()
{
    if (Enroll_Name.size() == 0)
    {
        MessageBox(NULL, _T("�ǳ�Ϊ�գ��������ǳƣ�"), _T("�ǳ�"), MB_OK);
        return false;
    }
    return true;

}
bool checkPassword1()//��һ������,��֪Ϊɶ�����ó�������û���⣬һ���Ͼʹ���Ƶ������Ц
{
    int length = Enroll_Password1.size();
    if (length == 0)
    {
        MessageBox(NULL, _T("����Ϊ�գ����������룡"), _T("����"), MB_OK);
        return false;
    }
    else if (length > 16 || length < 5)
    {
        outtextxy(710, 290, L"�����������̣����������룡");
        return false;
    }
    else
    {
        return true;

    }
}
bool checkPassword2()
{
    if (Enroll_Password2.size() == 0)
    {
        MessageBox(NULL, _T("�ܱ�Ϊ�գ��������ܱ���"), _T("�ܱ�"), MB_OK);
        return false;
    }
    return true;

}
/*
������:�
����:
	����while(1)ѭ�����ȴ��û��������.{
		���û�����ǳ������,�򵯳��ǳ������,�����û�������ǳƲ������ǳƴ���������Enroll_Name��
		���û�������������,�򵯳����������,�����û���������벢�������봢��������Enroll_Password1��
		���û�����ܱ������,�򵯳��ܱ������,�����û�������ܱ��������ܱ�����������Enroll_Password2��
		���û����ע��,���ж��ǳ�,�����Լ��ܱ��Ƿ�Ϸ�.���Ϸ�,�����ʾ�ʲ�����Enroll_Wait_Save�������;�����Ϸ�,�������ʾ��;
		���û��������,�����Home_Show����;
	}
���:view
����:void
����ֵ:void
*/
void Enroll_Wait()
{
    int id;
    MOUSEMSG msg;
    while (1)
    {

        if (MouseHit())
        {
            msg = GetMouseMsg();

            switch (msg.uMsg)
            {
            case WM_LBUTTONDOWN:
                if (msg.x > 500 && msg.x < 700 && msg.y>230 && msg.y < 272)
                {
                    wchar_t s1[20];
                    Enroll_Name = InputBox(s1, 20, NULL, NULL, NULL, 200, 30, true);
                    setlinecolor(BLACK);
                    setfillcolor(WHITE);
                    solidroundrect(500, 230, 500 + 200, 230 + 42, 10, 10);
                    setbkmode(TRANSPARENT);
                    settextcolor(BLACK);
                    outtextxy(510, 240, s1);
                    Enroll_Name = bs_WStringTostring(wstring(s1));
                }
                else if (msg.x > 500 && msg.x < 700 && msg.y>280 && msg.y < 322)
                {
                    wchar_t s2[20];
                    Enroll_Password1 = InputBox(s2, 20, NULL, NULL, NULL, 200, 30, true);
                    setfillcolor(WHITE);
                    setlinecolor(BLACK);
                    solidroundrect(500, 280, 500 + 200, 280 + 42, 10, 10);
                    setbkmode(TRANSPARENT);
                    settextcolor(BLACK);
                    settextstyle(20, 0, L"����");
                    outtextxy(510, 290, s2);
                    Enroll_Password1 = bs_WStringTostring(wstring(s2));//�û���ע�����������ǳ�
                }
                else if (msg.x > 500 && msg.x < 700 && msg.y>330 && msg.y < 372)
                {
                    wchar_t s3[20];
                    Enroll_Password2 = InputBox(s3, 20, NULL, NULL, NULL, 200, 30, true);
                    setfillcolor(WHITE);
                    setlinecolor(BLACK);
                    solidroundrect(500, 330, 500 + 200, 330 + 42, 10, 10);
                    setbkmode(TRANSPARENT);
                    settextcolor(BLACK);
                    outtextxy(510, 340, s3);
                    Enroll_Password2 =bs_WStringTostring(wstring(s3));//�û���ע�����������ǳ�
                }
                else if (msg.x > 530 && msg.x < 680 && msg.y>380 && msg.y < 422)
                {
                    int h = 1;
                    if (checkName())
                    {
                        h++;
                    }
                    if (checkPassword1())
                    {
                        h++;
                    }
                    if (checkPassword2())
                    {
                        h++;
                    }

                    if (h == 4)
                    {
                        Enroll_Wait_GetLastId();
                        id = stoi(bs_stringToWString(last_id))+1;
                        MessageBox(NULL, to_wstring(id).c_str(), _T("ע��ɹ�������IDΪ"), MB_OK);
                        Menu_ID = to_string(id);
                        Enroll_Wait_Save();
                        Menu_Show();
                    }
                }
                else if (msg.x > 530 && msg.x < 680 && msg.y>430 && msg.y < 472)
                {

                    Home_Show();
                }

            }

        }
    }


}

/*
������:�
����:
	��ս���
	Passback_Print()
	Passback_Wait()
���:view
����:void
����ֵ:void
*/
void Enroll_Show();
void Enroll_Show()//���Ӧ�þ���ô��ɣ������Ҹ�
{
    cleardevice();
    Enroll_Print();
    Enroll_Wait();
}

/*
������:�
����:��ʼ����ЧΪ��,�Ѷ�Ϊ��
����:void
����ֵ:void
*/
void Menu_init();//��ʼ����ȫ,�ұ�����
void Menu_init()
{
    Difficulty = 1;
    Music = 1;
    /*mciSendString(L"open bgm.mp3 alias BGM", NULL, 0, NULL);
    if (Music == 1)
    {
        mciSendString(L"play BGM repeat", NULL, 0, NULL);
    }
    else if (Music == 0)
    {
        mciSendString(L"pause BGM ", NULL, 0, NULL);
    }
    */
}

/*
������:�
����{
	��ս���
	��ӡ����ͼ
	��ӡ��ʼ��Ϸ,����,���а�,�̵�,�˳��˺�,�˳���Ϸ�Լ��˺���Ϣ��ʾ���߸���ť
	�����Ͻ��ú���Menu_Get_ID(),Menu_Get_Name(),Menu_Get_Highest()����˺���Ϣ
	�ȴ��û��������.���û������Ӧ��ť,�������Ӧ��Show����
}
���:view
����:void
����ֵ:void
*/
void Menu_Show();
void Menu_Show()
{
    cleardevice();
    settextstyle(20, 0, L"΢���ź�");
    IMAGE m2;
    loadimage(&m2, L".\\����ͼƬ\\QQͼƬ20240801174722.jpg", 1200, 760,true);
    putimage(0, 0, &m2);
    setbkmode(TRANSPARENT);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(500, 450, 500 + 200, 450 + 42, 10, 10);//��ʼ��Ϸ
    solidroundrect(400, 500, 400 + 150, 500 + 42, 10, 10);//�˳��˺�
    solidroundrect(650, 500, 650 + 150, 500 + 42, 10, 10);//�˳���Ϸ
    solidroundrect(50, 300, 50 + 150, 300 + 42, 10, 10);//���а�
    solidroundrect(50, 250, 50 + 150, 250 + 42, 10, 10);//����
    solidroundrect(50, 200, 50 + 150, 200 + 42, 10, 10);//�̵�
    wchar_t text1[] = L"��ʼ��Ϸ";
    int x1 = 500 + (200 - textwidth(text1)) / 2;
    int y1 = 450 + (42 - textheight(text1)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x1, y1, text1);
    wchar_t text2[] = L"�˳��˺�";
    int x2 = 400 + (150 - textwidth(text2)) / 2;
    int y2 = 500 + (42 - textheight(text2)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x2, y2, text2);

    wchar_t text3[] = L"�˳���Ϸ";
    int x3 = 650 + (150 - textwidth(text3)) / 2;
    int y3 = 500 + (42 - textheight(text3)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x3, y3, text3);

    wchar_t text4[] = L"���а�";
    int x4 = 50 + (200 - textwidth(text4)) / 2;
    int y4 = 300 + (42 - textheight(text4)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(95, y4, text4);

    wchar_t text5[] = L"����";
    int x5 = 50 + (150 - textwidth(text5)) / 2;
    int y5 = 250 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x5, y5, text5);

    wchar_t text6[] = L"�̵�";
    int x6 = 50 + (150 - textwidth(text5)) / 2;
    int y6 = 200 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x6, y6, text6);
    solidroundrect(10, 10, 10 + 250, 10 + 60, 10, 10);
    outtextxy(10, 10, L"ID:");
    outtextxy(10, 30, L"�ǳ�:");
    outtextxy(10, 50, L"��߷���:");
    outtextxy(100, 10, bs_stringToWString(Menu_Get_ID()).c_str());
    outtextxy(100, 30, bs_stringToWString(Menu_Get_Name()).c_str());
    outtextxy(100, 50, bs_stringToWString(Menu_Get_Highest()).c_str());
    MOUSEMSG msg1;
    while (1)
    {

        if (MouseHit())
        {
            msg1 = GetMouseMsg();


            switch (msg1.uMsg)
            {
            case WM_LBUTTONDOWN:
                if (msg1.x > 500 && msg1.x < 700 && msg1.y>450 && msg1.y < 492)//��ʼ��Ϸ
                {
                    Game_Show();

                }
                else if (msg1.x > 400 && msg1.x < 650 && msg1.y>500 && msg1.y < 542)//�˳��˺�
                {
                    Home_Show();
                }
                else if (msg1.x > 650 && msg1.x < 800 && msg1.y>500 && msg1.y < 542)//�˳���Ϸ
                {
                    exit(0);
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>300 && msg1.y < 342)//���а�
                {

                    ListSelect_Show();
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>250 && msg1.y < 292)//����
                {
                    Setting_Show();
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>200 && msg1.y < 242)//�̵�
                {
                    Shop_Show();
                }
            }
        }
    }
}

/*
������:�
����:��ӡ����ͼ,��ӡ������Ч,�Ѷ��л�,������Ա��Ϣ,��Ϸ�淨�ͷ��ذ�ť
���:view
����:void
����ֵ:void
*/
void Setting_Print();//��������
void Setting_Print()
{
    settextstyle(20, 0, L"΢���ź�");
    IMAGE m3;
    loadimage(&m3, L"./�ز�ͼ/���˵���.jpg", 1200, 760);
    putimage(0, 0, &m3);
    setbkmode(TRANSPARENT);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(10, 10, 10 + 150, 10 + 42, 10, 10);
    solidroundrect(10, 60, 10 + 150, 60 + 42, 10, 10);
    solidroundrect(10, 110, 10 + 150, 110 + 42, 10, 10);
    solidroundrect(10, 160, 10 + 150, 160 + 42, 10, 10);
    solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
    wchar_t text1[] = L"����";
    int x1 = 10 + (150 - textwidth(text1)) / 2;
    int y1 = 10 + (42 - textheight(text1)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x1, y1, text1);
    wchar_t text2[] = L"������Ա����";
    int x2 = 10 + (150 - textwidth(text2)) / 2;
    int y2 = 60 + (42 - textheight(text2)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x2, y2, text2);

    wchar_t text3[] = L"��Ϸ�淨";
    int x3 = 10 + (150 - textwidth(text3)) / 2;
    int y3 = 110 + (42 - textheight(text3)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x3, y3, text3);

    wchar_t text4[] = L"������Ч";
    int x4 = 10 + (150 - textwidth(text4)) / 2;
    int y4 = 160 + (42 - textheight(text4)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x4, y4, text4);

    wchar_t text5[] = L"�Ѷ��л�";
    int x5 = 10 + (150 - textwidth(text5)) / 2;
    int y5 = 210 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x5, y5, text5);
}

/*
������:�
����:
	����while(1)ѭ�����ȴ��û��������.{
		���û������Ч����,�����ȫ�ֱ���Music�����´�ӡ��Ч���ذ�ť(��Ϊ��Ч���ذ�ť��Ҫ��ʾ��ǰ��Ч״̬)
		���û�����Ѷ��л���ť,�����ȫ�ֱ���Difficulty�����´�ӡ�Ѷ��л���ť(��Ϊ�Ѷ��л���ť��Ҫ��ʾ��ǰ�Ѷ�״̬)
		���û����������Ա��Ϣ,�����Author_Show����;
		���û������Ϸ�淨,�����Method_Show����;
		���û��������,�����Menu_Show����;
	}
���:view
����:void
����ֵ:void
*/
void Setting_Wait();
void Setting_Wait()
{
    MOUSEMSG msg2;
    while (1)
    {
        if (MouseHit())
        {


            msg2 = GetMouseMsg();


            switch (msg2.uMsg)
            {
            case WM_LBUTTONDOWN:
                if (msg2.x > 10 && msg2.x < 160 && msg2.y>10 && msg2.y < 52)
                {
                    Menu_Show();

                }
                else if (msg2.x > 10 && msg2.x < 160 && msg2.y>60 && msg2.y < 102)
                {
                    Author_Show();
                }
                else if (msg2.x > 10 && msg2.x < 160 && msg2.y>110 && msg2.y < 152)
                {
                    Method_Show();
                }
                else if (msg2.x > 10 && msg2.x < 160 && msg2.y>160 && msg2.y < 202)
                {
                    if (Music == 1)
                    {
                        Music = 0;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(WHITE);
                        solidroundrect(10, 160, 10 + 150, 160 + 42, 10, 10);
                        settextstyle(20, 0, L"����");
                        outtextxy(40, 170, L"��Ч�ѹ�");
                    }
                    else
                    {
                        Music = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RGB(126, 132, 247));
                        solidroundrect(10, 160, 10 + 150, 160 + 42, 10, 10);
                        settextstyle(20, 0, L"����");
                        outtextxy(40, 170, L"��Ч�ѿ�");
                    }
                    Menu_init();


                }
                else if (msg2.x > 10 && msg2.x < 160 && msg2.y>210 && msg2.y < 252)//����
                {
                    if (Difficulty == 1)
                    {
                        Difficulty = 2;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(GREEN);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"����");
                        outtextxy(40, 220, L"�е�ģʽ");
                    }
                    else if (Difficulty == 2)
                    {
                        Difficulty = 3;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RED);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"����");
                        outtextxy(40, 220, L"����ģʽ");

                    }
                    else if (Difficulty == 3)
                    {
                        Difficulty = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(WHITE);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"����");
                        outtextxy(40, 220, L"��ģʽ");
                    }
                }


            }

        }

    }

}

void Setting_Show();
void Setting_Show() {
    cleardevice();
    Setting_Print();
    Setting_Wait();
}

void hui_7(int x, int y, int w, int h)//���Ƽ��ѶȰ�ť
{


    setfillcolor(RGB(216, 221, 223));//������ɫ
    solidroundrect(x, y, x + w, y + h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    wchar_t d_1[] = L"��";
    int wSpace = ((w - textwidth(d_1)) / 2);
    int vSpace = ((h - textheight(d_1)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_1);
}
void hui_8(int x, int y, int w, int h)//�����е��ѶȰ�ť
{


    setfillcolor(RGB(216, 221, 223));//������ɫ
    solidroundrect(x, y, x + w, y + h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    wchar_t d_2[] = L"�е�";
    int wSpace = ((w - textwidth(d_2)) / 2);
    int vSpace = ((h - textheight(d_2)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_2);

}
void hui_9(int x, int y, int w, int h)//���������ѶȰ�ť
{

    setfillcolor(RGB(216, 221, 223));//������ɫ
    solidroundrect(x, y, x + w, y + h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    wchar_t d_3[] = L"����";
    int wSpace = ((w - textwidth(d_3)) / 2);
    int vSpace = ((h - textheight(d_3)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_3);
}

/*
������:����
����{
	��ս���
	��ӡ����ͼ
	��ӡ��,�е�,����������ť
	�ȴ��û��������.���û������Ӧ��ť,�������Ӧ��Show������������Ӧ�Ĳ���(1�����,2�����е�,3��������)
}
���:view
���� : void
����ֵ : void
*/
void ListSelect_Show();
void hui_10(int x, int y, int w, int h)//���Ʒ��ذ�ť
{
    //���Ʒ��ذ�ť
    setfillcolor(RGB(216, 221, 223));//������ɫ
    solidroundrect(x, y, x + w, y + h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    wchar_t d_2[] = L"����";
    int wSpace = ((w - textwidth(d_2)) / 2);
    int vSpace = ((h - textheight(d_2)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_2);
}
// 
// 
void ListSelect_Show()
{
    cleardevice();//��ս���
    //��ӡ����ͼ
    IMAGE img;
    loadimage(&img, L"./�ز�ͼ/���˵���.jpg", Window_Width, Window_Height); // �滻Ϊ���ͼƬ�ļ���
    // ��ͼƬ���Ƶ������ϣ���Ϊ����
    // ע�⣺Ĭ�ϴ�(0,0)���꿪ʼ���ƣ������ڵ����Ͻ�
    putimage(0, 0, &img);
    int x_7 = 500; int y_7 = 200; int w_7 = 100; int h_7 = 50;//���ѶȰ�ťλ��
    int x_8 = 500; int y_8 = 300; int w_8 = 100; int h_8 = 50;//�е��ѶȰ�ťλ��
    int x_9 = 500; int y_9 = 400; int w_9 = 100; int h_9 = 50; //�����ѶȰ�ťλ��
    int x_10 = 500; int y_10 = 550; int w_10 = 100; int h_10 = 50;//���ذ�ťλ��
    hui_7(x_7, y_7, w_7, h_7);//���Ƽ��ѶȰ�ť
    hui_8(x_8, y_8, w_8, h_8);//�����е��ѶȰ�ť
    hui_9(x_9, y_9, w_9, h_9);//���������ѶȰ�ť
    hui_10(x_10, y_10, w_10, h_10);//���Ʒ��ذ�ť
    ExMessage msg_3;
    msg_3 = getmessage(EX_MOUSE);
    while (1)
    {
        //��ȡ��Ϣ
        if (peekmessage(&msg_3, EX_MOUSE))
        {
            if (button(x_7, y_7, w_7, h_7, msg_3))//���������ѶȰ�ť
            {
                List_Show(1);

            }
            else if (button(x_8, y_8, w_8, h_8, msg_3))//�������е��ѶȰ�ť
            {
                List_Show(2);

            }
            else if (button(x_9, y_9, w_9, h_9, msg_3))//�����������ѶȰ�ť
            {
                List_Show(3);

            }
            else if (button(x_10, y_10, w_10, h_10, msg_3)) {
                Menu_Show();
            }
        }
    }
}

/*
������:�鳤
����:��ջ���,��ӡ����ͼ,��ֵ�������,������Ʒ��ť,�鳤��ά���
���:view
����:void
����ֵ:void
*/
void Shop_Print();
//����:��ջ���, ��ӡ����ͼ, ��ֵ�������, ������Ʒ��ť, �鳤��ά���
void Shop_Print()
{
    int L = 30;//��������߽�
    int R = 170;//�������ұ߽�
    int GR_Width = 200;
    int GR_Height = 0;
    int Window_Width = 752;
    int Window_Height = 1196;
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    IMAGE img_kun2;
    //
    //ͼƬΪ����·��������ʱ�޸ģ�����
    //
    loadimage(&img_kun2, L"./�ز�ͼ/�̵�ҳ��.jpg");
    putimage(0, 0, &img_kun2);
    settextstyle(30, 0, L"SimHei");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(103, 229, 215));//�������������ɫ
    fillroundrect(L, 25, R, 75, 10, 10);//���ƾ��κ��������
    outtextxy(GR_Width / 2 - textwidth(L"�˺�����") / 2,
        GR_Height / 2 + 50 - textheight(L"�˺�����") / 2, L"�˺�����");
    fillroundrect(L, 175, R, 225, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"ɢ��ǹ") / 2,
        GR_Height / 2 + 200 - textheight(L"ɢ��ǹ") / 2, L"ɢ��ǹ");
    fillroundrect(L, 325, R, 375, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"�޵е�") / 2,
        GR_Height / 2 + 350 - textheight(L"�޵е�") / 2, L"�޵е�");
    fillroundrect(L, 475, R, 525, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"�һ���") / 2,
        GR_Height / 2 + 500 - textheight(L"�һ���") / 2, L"�һ���");
    fillroundrect(L, 625, R, 675, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"BACK") / 2,
        GR_Height / 2 + 650 - textheight(L"BACK") / 2, L"BACK");

}

/*
������:�鳤
����:
	����while(1)ѭ�����ȴ��û��������.{
		���û������ֵ�������,�򵯳���ֵ�������,�����û�����ĳ�ֵ�벢���ó�ֵ�봢��������Shop_Password��.����Shop_Wait_Judge�����жϳ�ֵ�Ƿ�ɹ�.���ɹ��������ʾ�ʲ�Gold+=addGold,��ʧ���������ʾ��
		���û��������,�����Menu_Show����;
	}
���:view
����:void
����ֵ:void
*/
void Shop_Wait();
void Shop_Wait()
{
    //
    int Recharge = 0;//���ϼǵ�ɾ
    int Gold = 0;//���ϼǵ�ɾ
    int addGold = 6;//���ϼǵ�ɾ

    //
    int L = 30;//��������߽�
    int R = 170;//�������ұ߽�
    MOUSEMSG Mouse;
    while (true)
    {
        if (MouseHit())
        {
            Mouse = GetMouseMsg();
            if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 25 && Mouse.y <= 75 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //�����˺�����
                if (Gold >= 1) {
                    Gold = Gold - 1;
                    Recharge += 1;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 175 && Mouse.y <= 225 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //����ɢ��ǹ
                if (Gold >= 2) {
                    Gold = Gold - 2;
                    Recharge += 2;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 325 && Mouse.y <= 375 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //�����޵�
                if (Gold >= 3) {
                    Gold = Gold - 3;
                    Recharge += 3;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 475 && Mouse.y <= 525 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //�һ���
                wchar_t* rechange_code=nullptr;
                InputBox(rechange_code, 10, L"�������ֵ��");
                if (wstring(rechange_code).size() != 0) {
                    Shop_Password = bs_WStringTostring(wstring(rechange_code));
                    if (Shop_Wait_Judge())
                    {
                        Gold += addGold;
                        //���봽�ɹ�
                    }
                    else
                    {
                        //���봽�ʧ��
                    }
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 625 && Mouse.y <= 675 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //�������˵�
                Menu_Show();
            }
        }


    }
}

/*
������:�鳤
����:
	Shop_init()
	Shop_Print()
	Shop_Wait()
���:��
����:void
����ֵ:void
*/
void Shop_Show();
void Shop_Show() {
    Shop_init();
    Shop_Print();
    Shop_Wait();
}

/*
������:�鳤
����:��ӡ����ͼ,������Ա��Ϣ�뷵�ذ�ť
���:view
����:void
����ֵ:void
*/
void Author_Print();
void Author_Print()
{
    MOUSEMSG Mouse;//�������
    int Window_Width = 752;
    int Window_Height = 1196;
    cleardevice();
    IMAGE img_kun2;
    //
    //ͼƬΪ����·��������ʱ�޸ģ�����
    //
    loadimage(&img_kun2, L".\\����ͼƬ\\kun.jpg");
    putimage(0, 0, &img_kun2);
    settextstyle(30, 0, L"΢���ź�");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(98, 90, 88));//�������������ɫ
    /*
    ��ӡС����Ϣ������
     */
    settextcolor(RGB(119, 103, 255));
    outtextxy(90 - textwidth(L"С����Ϣ��") / 2,
        50 - textheight(L"С����Ϣ��") / 2, L"С����Ϣ��");
    settextcolor(BLACK);
    fillroundrect(1030, 665, 1170, 735, 10, 10);
    outtextxy(1100 - textwidth(L"����") / 2,
        700 - textheight(L"����") / 2, L"����");
    settextstyle(50, 0, L"΢���ź�");
    settextcolor(WHITE);
    outtextxy(300 - textwidth(L"ѩ��: ���Ų���,IKUN����") / 2,
        100 - textheight(L"ѩ��: ���Ų���,IKUN����") / 2, L"ѩ��: ���Ų���,IKUN����");
    outtextxy(265 - textwidth(L"���ޣ��̲�cܳ��ϰ��") / 2,
        175 - textheight(L"���ޣ��̲�cܳ��ϰ��") / 2, L"���ޣ��̲�cܳ��ϰ��");
    outtextxy(240 - textwidth(L"��ë���̴̲�ѧ��") / 2,
        250 - textheight(L"��ë���̴̲�ѧ��") / 2, L"��ë���̴̲�ѧ��");
    outtextxy(350 - textwidth(L"��ϲ���������ݶ�С����������") / 2,
        325 - textheight(L"��ϲ���������ݶ�С����������") / 2, L"��ϲ���������ݶ�С����������");
    outtextxy(270 - textwidth(L"���磺���⣬��ץ��ס") / 2,
        400 - textheight(L"���磺���⣬��ץ��ס") / 2, L"���磺���⣬��ץ��ס");
    outtextxy(315 - textwidth(L"���棺����������߳�-����") / 2,
        475 - textheight(L"���棺����������߳�-����") / 2, L"���棺����������߳�-����");
    outtextxy(230 - textwidth(L"���ϣ�just do  it!") / 2,
        550 - textheight(L"���ϣ�just do  it!") / 2, L"���ϣ�just do  it!");
    outtextxy(310 - textwidth(L"�������ů������η��˪") / 2,
        625 - textheight(L"�������ů������η��˪") / 2, L"�������ů������η��˪");

}

/*
������:�鳤
����:
	����while(1)ѭ��,�ȴ��û��������.���û�������ذ�ť,�����Setting_Show()����
���:view
����:void
����ֵ:void
*/
void Author_Wait();
void Author_Wait()
{
    MOUSEMSG Mouse;
    while (true)
    {

        if (MouseHit()) {
            //��ȡ�����Ϣ
            Mouse = GetMouseMsg();
            //�û�������ڰ�ť��Χ�ڣ����Ұ������
            if (Mouse.x >= 1030 && Mouse.x <= 1170 &&
                Mouse.y >= 665 && Mouse.y <= 735 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Setting_Show();//��������
                break;
            }
        }

    }
}

/*
����:�鳤
	Author_Print();
	Author_Wait();
*/
void Author_Show();
void Author_Show() {
    Author_Print();
    Author_Wait();
}


/*
* ������:�鳤
����:
	Method_Print();
	Method_Wait();
*/
void Method_Show();
void Method_Show() {
    //���������Դ
    int Window_Width = 752;
    int Window_Height = 1196;
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    MOUSEMSG Mouse;
    IMAGE k1;
    loadimage(&k1, L".\\����ͼƬ\\QQͼƬ20240801173825.jpg");
    putimage(0, 0, &k1);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, L"SimHei");
    setfillcolor(RGB(255, 255, 255));
    //�˳�
    settextcolor(RGB(214, 157, 133));
    outtextxy(200 - textwidth(L"��ô�򵥵���Ϸ���ỵ́�") / 2,
       100 - textheight(L"��ô�򵥵���Ϸ���ỵ́�") / 2, L"��ô�򵥵���Ϸ���ỵ́�");
    outtextxy(200 - textwidth(L"������Ů����") / 2,
        150 - textheight(L"������Ů����") / 2, L"������Ů����");
    fillroundrect(1100, 500, 1150, 600, 10, 10);
    outtextxy(1125 - textwidth(L"��") / 2,
        530 - textheight(L"��") / 2,
        L"��");
    outtextxy(1125 - textwidth(L"��") / 2,
        570 - textheight(L"��") / 2,
        L"��");
    FlushBatchDraw();
    while (true) {
        if (MouseHit()) {
            Mouse = GetMouseMsg();
            if (Mouse.x >= 1100 && Mouse.x <= 1150 &&
                Mouse.y >= 500 && Mouse.y <= 600 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //��������
                Setting_Show();
                break;

            }


        }
    }
}

int List_width_button1 = 100;//��ť���
int List_height_button1 = 40;//��ť�߶�
int List_x_button1 = 600 - 50;//��һ����ť���Ͻǵ�xֵ
int List_y_button1 = 600;//��һ����ť���Ͻǵ�yֵ
int List_distance_button1 = 60;//������ť֮��ĸ߶Ȳ�
int List_n_button1 = 1;//��ť����
int List_width_character1 = 15;//���ֿ��
int List_height_character1 = 30;//���ָ߶�
vector<wstring> List_text_button1 = { L"����" };//ÿ����ť�ϵ��ı�

void List_draw1() {//�������������ӡn��δ����״̬�İ�ť
    settextstyle(List_height_character1, List_width_character1, _T("FangSong"));
    setfillcolor(WHITE);//������ťԭ���ı�����ɫ
    settextcolor(BLACK);//�����ı���ɫ
    for (int i = 0; i < List_n_button1; i++) {
        fillroundrect(List_x_button1, List_y_button1 + i * List_distance_button1, List_x_button1 + List_width_button1, List_y_button1 + i * List_distance_button1 + List_height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((List_x_button1 + List_x_button1 + List_width_button1) / 2 - textwidth(List_text_button1[i].c_str()) / 2), (List_y_button1 + i * List_distance_button1 + List_y_button1 + i * List_distance_button1 + List_height_button1) / 2 - textheight(List_text_button1[i].c_str()) / 2.0, List_text_button1[i].c_str());
    }
}

void List_check1()//��鰴�Ƿ񱻴���.��������ı䰴ť��ʽ
{
    ExMessage m;

    static int POSITION = 0;
    m = getmessage(EX_MOUSE || EX_KEY);
    int sign = 0;
    for (int i = 0; i < List_n_button1; i++) {
        if (m.x >= List_x_button1 && m.x <= List_x_button1 + List_width_button1 && m.y >= List_y_button1 + i * List_distance_button1 && m.y <= List_y_button1 + i * List_distance_button1 + List_height_button1) {
            sign = 1;
            if (POSITION != i) {
                List_draw1();
                setfillcolor(GREEN);//������ť��ɫ
                settextcolor(RED);//������ť���ı���ɫ
                fillroundrect(List_x_button1, List_y_button1 + i * List_distance_button1, List_x_button1 + List_width_button1, List_y_button1 + i * List_distance_button1 + List_height_button1, 10, 10);
                setbkmode(TRANSPARENT);
                outtextxy((int)((List_x_button1 + List_x_button1 + List_width_button1) / 2 - textwidth(List_text_button1[i].c_str()) / 2), (List_y_button1 + i * List_distance_button1 + List_y_button1 + i * List_distance_button1 + List_height_button1) / 2 - textheight(List_text_button1[i].c_str()) / 2.0, List_text_button1[i].c_str());
                POSITION = i;
                break;
            }
            if (m.message == WM_LBUTTONDOWN) {
                ListSelect_Show();
            }
        }
    }
    if (!sign) {
        POSITION = List_n_button1;
        List_draw1();
    }

}

/*
������:����
����:
	��ӡ����ͼ,���а����,���а�չʾ��ͷ��ذ�ť
	����List_init����(Ҫ�����ѶȲ���)
	����ȫ�ֱ���List��ӡ���а�
	�ȴ��û��������.���û�������ذ�ť,�����ListSelect_Show����;
���:view
����:int,�ѶȲ���
����ֵ:void
*/
void List_Show(int);
void List_Show(int _Difficulty) {
    List_init(_Difficulty);
    cleardevice();
    IMAGE background;
    loadimage(&background, L"C:\\Users\\XKWL\\source\\repos\\��������_�ɻ���ս\\����ͼƬ\\΢��ͼƬ_20240725221749.jpg", 1200, 760, true);
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    wstring Difficulty_s;
    settextstyle(50, 25, L"FangSong");
    if (_Difficulty == 1) {
        Difficulty_s = L"��ģʽ���а�";
    }
    else if (_Difficulty == 2) {
        Difficulty_s = L"�е�ģʽ���а�";
    }
    else if (_Difficulty == 3) {
        Difficulty_s = L"����ģʽ���а�";
    }
    outtextxy(600 - textwidth(L"��ģʽ���а�") / 2, 30, Difficulty_s.c_str());//����
    settextstyle(30, 15, L"FangSong");
    outtextxy(150 - textwidth(L"����") / 2, 100, L"����");//С����
    outtextxy(300 - textwidth(L"ID") / 2, 100, L"ID");//С����
    outtextxy(600 - textwidth(L"�ǳ�") / 2, 100, L"�ǳ�");//С����
    outtextxy(900 - textwidth(L"��߷�") / 2, 100, L"��߷�");//С����
    for (int i = 0; i < List.size(); i++) {
        const wchar_t* rank_s = to_wstring(i + 1).c_str();
        const wchar_t* ID_s = bs_stringToWString(List[i].getid()).c_str();
        const wchar_t* name_s = bs_stringToWString(List[i].getname()).c_str();
        const wchar_t* highest_s = to_wstring(List[i].gethighest()).c_str();
        outtextxy(150 - textwidth(to_wstring(i + 1).c_str()) / 2, (i+1+4) * 25, to_wstring(i + 1).c_str());//С����
        outtextxy(300 - textwidth(bs_stringToWString(List[i].getid()).c_str()) / 2, (i + 1 + 4) * 25, bs_stringToWString(List[i].getid()).c_str());//С����
        outtextxy(600 - textwidth(bs_stringToWString(List[i].getname()).c_str()) / 2, (i + 1 + 4) * 25, bs_stringToWString(List[i].getname()).c_str());//С����
        outtextxy(900 - textwidth(to_wstring(List[i].gethighest()).c_str()) / 2, (i + 1 + 4) * 25, to_wstring(List[i].gethighest()).c_str());//С����
        if (i == 16) {
            break;
        }
    }
    List_draw1();
    while (1) {
        List_check1();
    }
}

/*
������:�
����:
	��ʼ����������Ϸ��ص�����
����;void
����ֵ:void
*/
void Game_init();
void Game_init()
{
    BaseV = 1;//��Ϸ����,����Ϊ1�����������(ÿһ֡�ƶ��ĸ���)
    BaseR = 10;
    CClock = 0;//������Ϸʱ��,���ڸ���ˢ�ֻ���
    BaseNumber1 = 2;//��1�Ļ���ˢ������
    BaseNumber2 = 1;//��2�Ļ���ˢ������
    BaseNumber3 = 1;//��3�Ļ���ˢ������
    BaseNumber4 = 0;//��4�Ļ���ˢ������
    BaseNumber5 = 3;//��5�Ļ���ˢ������
    isbossalive = 0;//��ʾboss�Ƿ���.1������,0��������
    MyPlaneDir = 0;//��ʾ�ҷ��ɻ����ƶ���������
    Enermy_Bullet.clear(); //����з��ӵ���ȫ������
    Enermy_Plane.clear();//����з��ɻ���ȫ������
    My_Bullet.clear();//�����ҷ��ӵ���ȫ������
    Music = 1;
    MyPlane = Plane(630, 380, 2, 10, 1, 30000,2,1,1,1, 0, 0,0,0);
    isbossalive = 0;
    cur_round = -1;
    state_0 = 1, state_1 = 1;
    renew_flag[8] = { 0 };
    settextstyle(30, 15, L"Fangsong");
    Game_Mark = 0;
    loadimage(&m5, L"./�ز�ͼ/��Ϸҳ��.jpg", 1200, 760);
    loadimage(&EnemyBullet_1, L"./�ز�ͼ/�з��ӵ�1.png", Bullet1_w, Bullet1_h);
    loadimage(&EnemyBullet_2, L"./�ز�ͼ/�з��ӵ�2.png", Bullet2_w, Bullet2_h);
    loadimage(&EnemyBullet_3, L"./�ز�ͼ/�з��ӵ�3.png", Bullet3_w, Bullet3_h);
    loadimage(&EnemyBullet_4, L"./�ز�ͼ/�з��ӵ�4.png", Bullet4_w, Bullet4_h);
    loadimage(&EnemyBullet_5, L"./�ز�ͼ/�з��ӵ�5.png", Bullet5_w, Bullet5_h);
    loadimage(&EnemyBullet_6, L"./�ز�ͼ/�з��ӵ�6.png", Bullet6_w, Bullet6_h);
    loadimage(&MyBullet_1, L"./�ز�ͼ/�ҷ��ӵ�1.jpg", MyBullet1_w, MyBullet1_h, false);
    loadimage(&MyBullet_2, L"./�ز�ͼ/�ҷ��ӵ�2.jpg", MyBullet1_w, MyBullet1_h, false);
    loadimage(&EnemyPlane_1, L"./�ز�ͼ/�л�1.jpg", Plane1_w, Plane1_h);
    loadimage(&EnemyPlane_2, L"./�ز�ͼ/�л�2.jpg", Plane2_w, Plane2_h);
    loadimage(&EnemyPlane_3, L"./�ز�ͼ/�л�3.jpg", Plane3_w, Plane3_h);
    loadimage(&EnemyPlane_4, L"./�ز�ͼ/�л�4.jpg", Plane4_w, Plane4_h);
    loadimage(&EnemyPlane_5, L"./�ز�ͼ/�л�5.png", Plane5_w, Plane5_h);
    loadimage(&EnemyPlane_6, L"./�ز�ͼ/Boss.jpg", Plane6_w, Plane6_h);
    loadimage(&m4, L"./�ز�ͼ/����.jpg", 30, 30, false);
}

/*
������:�
����:
	Game_init();
	Game_Print();
	Game_Run();
���:view
����;void
����ֵ:void
*/
void Game_Show();
void Game_Show()
{
    Game_init();
    Game_Print();
    Game_Run();
}

/*
������:�
����:
	��ӡ��Ϸ���汳��ͼ,��ͣ��ť;
���:view
����;void
����ֵ:void
*/
void Game_Print();
void Game_Print()
{
    IMAGE m4;
    loadimage(&m4, L"./�ز�ͼ/��Ϸҳ��.jpg", 1200, 760);
    putimage(0, 0, &m4);
    setbkcolor(BLUE);
    solidroundrect(1150, 10, 1150 + 42, 10 + 42, 10, 10);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(1168, 25, L"||");
}

/*
������:�
����:
	while(1){
	Game_Run_Stop()
	Game_Run_RenewSituation()
	Game_Run_RenewEnermy()
	Game_Run_GetDir()
	Game_Run_Move()
	}
����;void
����ֵ:void
*/
void Game_Run();
void Game_Run()
{
    clock_t start = clock();
    const int FPS = 60;
    while (1) {
        if (clock() - start < 1000.0 / FPS)continue;
        start = clock();
        Game_Run_Stop();    
        Game_Run_RenewSituation();
        Game_Run_RenewEnermy();
        Game_Run_GetDir();
        Game_Run_Print();
    }
}

/*
������:�
����:�����豸����.����Ұ��¿ո�����������ͣ,��ô����Stop_Showת����ͣҳ��
���:view
����:void
����ֵ:void
*/
void Game_Run_Stop();
void Game_Run_Stop()
{
    ExMessage msg1;
    if (peekmessage(&msg1)) {
        switch (msg1.message) {
        case WM_LBUTTONDOWN:
        {
            // ��ȡ�������   
            if (msg1.x > 1150 && msg1.x < 1192 && msg1.y > 10 && msg1.y < 52) { // ��ʼ��Ϸ  
                Stop_Show();
            }
        }
        break; 
        case WM_KEYDOWN:
            if (msg1.wParam == VK_SPACE) { // VK_SPACE ��ʾ�ո��  
                Stop_Show();
            }
            break;
        }
    }
}

/*
������:�
����:
	���ռ�������,���ƶ����ݴ���ȫ�ֱ���MyPlaneDir��.
	1������,2��������,3������.....�Դ����ư˸�����.
���:view
����:void
����ֵ:void
*/
void Game_Run_GetDir();
void Game_Run_GetDir() {
    MyPlaneDir = 16; // ��ʼ״̬��Ϊĳ��ֵ  

    // ��ⰴ��״̬  
    if (GetAsyncKeyState('A') & 0x8000) {
        MyPlaneDir = 0; // ����  
        if (GetAsyncKeyState('W') & 0x8000) {
            MyPlaneDir = 2;  
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            MyPlaneDir = 14;   
        }
    }
    if (GetAsyncKeyState('W') & 0x8000) {
        MyPlaneDir = 4; // ����  
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        MyPlaneDir = 8; // ����  
        if (GetAsyncKeyState('W') & 0x8000) {
            MyPlaneDir = 6;  
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            MyPlaneDir = 10;  
        }
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        MyPlaneDir = 12; // ����  
    }

    MyPlane.setDir(MyPlaneDir);
}
/*
������:�/�鳤
����:
    �����һ֡��ӡ�ķɻ��Լ��ӵ�,Ȼ����ݵ�ǰ֡�ɻ����ӵ�(��ЩԪ�ض���������Ӧ��ȫ��������)��x,yֵ(�ɻ�����ӵ�������궼�нӿں���),��ӡ�ɻ����ӵ�����ͼ(��ͬ���͵ķɻ������ӵ�Ҫ�в�ͬ����ͼŶ)
����:view
����:void
����ֵ:void
*/
void Game_Run_Print();
void Game_Run_Print() {//����
    BeginBatchDraw();

    putimage(0, 0, &m5);
    setbkcolor(BLUE);
    solidroundrect(1150, 10, 1150 + 42, 10 + 42, 10, 10);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(1168, 25, L"||");
    //����,��ӡ����ͼ�Լ����ذ�ť


    for (int i = 0; i < Enermy_Bullet.size(); i++) {
        if (Enermy_Bullet[i].getBullet_type() == 1) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet1_w / 2, Enermy_Bullet[i].getY() - Bullet1_h / 2, &EnemyBullet_1);
        }
        else if (Enermy_Bullet[i].getBullet_type() == 2) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet2_w / 2, Enermy_Bullet[i].getY() - Bullet2_h / 2, &EnemyBullet_2);
        }
        else if (Enermy_Bullet[i].getBullet_type() == 3) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet3_w / 2, Enermy_Bullet[i].getY() - Bullet3_h / 2, &EnemyBullet_3);
        }
        else if (Enermy_Bullet[i].getBullet_type() == 4) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet4_w / 2, Enermy_Bullet[i].getY() - Bullet4_h / 2, &EnemyBullet_4);
        }
        else if (Enermy_Bullet[i].getBullet_type() == 5) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet5_w / 2, Enermy_Bullet[i].getY() - Bullet5_h / 2, &EnemyBullet_5);
        }
        else if (Enermy_Bullet[i].getBullet_type() == 6) {
            putimage_Alpha(Enermy_Bullet[i].getX() - Bullet6_w / 2, Enermy_Bullet[i].getY() - Bullet6_h / 2, &EnemyBullet_6);
        }

    }
    for (int i =0 ; i < My_Bullet.size(); i++) {
        if (My_Bullet[i].getBullet_type() == 1) {
            putimage_Alpha(My_Bullet[i].getX() - MyBullet1_w / 2, My_Bullet[i].getY() - MyBullet1_h / 2, &MyBullet_1);
        }
        else if (My_Bullet[i].getBullet_type() == 2) {
            putimage_Alpha(My_Bullet[i].getX() - MyBullet2_w / 2, My_Bullet[i].getY() - MyBullet2_h / 2, &MyBullet_2);
        }
    }
    for (int i = 0; i < Enermy_Plane.size(); i++) {
        if (Enermy_Plane[i].getEnemy_type()==1) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane1_w / 2, Enermy_Plane[i].getY() - Plane1_h / 2, &EnemyPlane_1);
        }
        else if (Enermy_Plane[i].getEnemy_type() == 2) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane2_w / 2, Enermy_Plane[i].getY() - Plane2_h / 2, &EnemyPlane_2);
        }
        else if (Enermy_Plane[i].getEnemy_type() == 3) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane3_w / 2, Enermy_Plane[i].getY() - Plane3_h / 2, &EnemyPlane_3);
        }
        else if (Enermy_Plane[i].getEnemy_type() == 4) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane4_w / 2, Enermy_Plane[i].getY() - Plane4_h / 2, &EnemyPlane_4);
        }
        else if (Enermy_Plane[i].getEnemy_type() == 5) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane5_w / 2, Enermy_Plane[i].getY() - Plane5_h / 2, &EnemyPlane_5);
        }
        else if (Enermy_Plane[i].getEnemy_type() == 6) {
            putimage_Alpha(Enermy_Plane[i].getX() - Plane6_w / 2, Enermy_Plane[i].getY() - Plane6_h / 2, &EnemyPlane_6);
        }
        settextcolor(RED);
        outtextxy(Enermy_Plane[i].getX(), Enermy_Plane[i].getY(), bs_stringToWString(to_string(Enermy_Plane[i].getHealth())).c_str());
    }

    putimage_Alpha(MyPlane.getX()-15, MyPlane.getY()-15, &m4);
    settextcolor(RED);
    outtextxy(85,670,bs_stringToWString(to_string(MyPlane.getHealth())).c_str());
    outtextxy(10, 670, L"Ѫ��:");
    outtextxy(10, 700, L"����:");
    outtextxy(85,700,bs_stringToWString(to_string(Game_Mark)).c_str());
    EndBatchDraw();
}



/*
������:����
����:��ӡ��ͣ����ͼ�Լ����ذ�ť
���:view
����:void
����ֵ:void
*/
void Stop_Print();
void Stop_Print()
{

    IMAGE img;
    loadimage(&img, L"./xx.jpg", Window_Width, Window_Height); // �滻Ϊ���ͼƬ�ļ���
    // ��ͼƬ���Ƶ������ϣ���Ϊ����
    // ע�⣺Ĭ�ϴ�(0,0)���꿪ʼ���ƣ������ڵ����Ͻ�
    putimage(0, 0, &img);
    //���Ʒ��ذ�ť
    //��ťλ��
    int f_x = 950;
    int f_y = 50;
    int f_w = 150;
    int f_h = 50;
    setfillcolor(RGB(239, 136, 190));//������ɫ
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    wchar_t d_2[] = L"����";
    int wSpace = ((f_w - textwidth(d_2)) / 2);
    int vSpace = ((f_h - textheight(d_2)) / 2);
    outtextxy(f_x + wSpace, f_y + vSpace, d_2);

    f_x = 950;
    f_y = 120;
    f_w = 150;
    f_h = 50;
    setfillcolor(RGB(239, 136, 190));//������ɫ
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    outtextxy(1000, 135, L"��Ч�ѹ�");

    f_x = 950;
    f_y = 190;
    f_w = 150;
    f_h = 50;
    setfillcolor(RGB(239, 136, 190));//������ɫ
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//���ư�ť
    //���ư�ť�ϵ�����
    settextcolor(BLACK);//����������ɫ
    setbkmode(TRANSPARENT);//���ñ���͸��
    settextstyle(20, 0, L"΢���ź�");
    outtextxy(990, 205, L"�������˵�");

}



/*
������:����
����:
    ����while(1)ѭ�����ȴ��û��������.{
        ���û��������,�������Ļ,����Game_Print()��ӡ��Ϸ����������������ѭ��;
    }
���:view
����:void
����ֵ:void
*/
void Stop_Wait();
void Stop_Wait()
{
    MOUSEMSG msg_4;
    while (1)
    {
        int i = 0;
        if (MouseHit())
        {
            msg_4 = GetMouseMsg();

            switch (msg_4.uMsg)
            {
            case WM_LBUTTONDOWN:
                if (msg_4.x > 950 && msg_4.x < 1100 && msg_4.y>50 && msg_4.y < 100)
                {
                    i = 1;
                    break;
                }
                else if (msg_4.x > 950 && msg_4.x < 1100 && msg_4.y>120 && msg_4.y < 170)
                {
                    if (Music == 1)
                    {
                        Music = 0;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(WHITE);
                        solidroundrect(950, 120, 950 + 150, 120 + 50, 10, 10);
                        settextstyle(20, 0, L"΢���ź�");
                        outtextxy(1000, 135, L"��Ч�ѹ�");
                    }
                    else
                    {
                        Music = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RGB(239, 136, 190));
                        solidroundrect(950, 120, 950 + 150, 120 + 50, 10, 10);
                        settextstyle(20, 0, L"΢���ź�");
                        outtextxy(1000, 135, L"��Ч�ѿ�");
                    }
                    // Menu_init();


                }
                else if (msg_4.x > 950 && msg_4.x < 1100 && msg_4.y>190 && msg_4.y < 240)
                {
                    Menu_Show();
                }
            }
            if (i == 1) {
                break;
            }
        }
    }

}

/*
������:����
����:
    Stop_Print()
    Stop_Wait()
���:view
����:void
����ֵ:void
*/
void Stop_Show();
void Stop_Show()
{
    Stop_Print();
    Stop_Wait();
}

int End_width_button1 = 400;//��ť���
int End_height_button1 = 50;//��ť�߶�
int End_x_button1 = 600 - 200;//��һ����ť���Ͻǵ�xֵ
int End_y_button1 = 500;//��һ����ť���Ͻǵ�yֵ
int End_distance_button1 = 60;//������ť֮��ĸ߶Ȳ�
int End_n_button1 = 2;//��ť����
int End_width_character1 = 15;//���ֿ��
int End_height_character1 = 30;//���ָ߶�
vector<wstring> End_text_button1 = { L"����һ��",L"����" };//ÿ����ť�ϵ��ı�
void End_draw1() {//�������������ӡn��δ����״̬�İ�ť
    settextstyle(End_height_character1, End_width_character1, _T("FangSong"));
    setfillcolor(WHITE);//������ťԭ���ı�����ɫ
    settextcolor(BLACK);//�����ı���ɫ
    for (int i = 0; i < End_n_button1; i++) {
        fillroundrect(End_x_button1, End_y_button1 + i * End_distance_button1, End_x_button1 + End_width_button1, End_y_button1 + i * End_distance_button1 + End_height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((End_x_button1 + End_x_button1 + End_width_button1) / 2 - textwidth(End_text_button1[i].c_str()) / 2), (End_y_button1 + i * End_distance_button1 + End_y_button1 + i * End_distance_button1 + End_height_button1) / 2 - textheight(End_text_button1[i].c_str()) / 2.0, End_text_button1[i].c_str());
    }
}
void End_check1()//��鰴�Ƿ񱻴���.��������ı䰴ť��ʽ
{
    ExMessage m;

    static int POSITION = 0;
    m = getmessage(EX_MOUSE || EX_KEY);
    int sign = 0;
    for (int i = 0; i < End_n_button1; i++) {
        if (m.x >= End_x_button1 && m.x <= End_x_button1 + End_width_button1 && m.y >= End_y_button1 + i * End_distance_button1 && m.y <= End_y_button1 + i * End_distance_button1 + End_height_button1) {
            sign = 1;
            if (POSITION != i) {
                End_draw1();
                setfillcolor(GREEN);//������ť��ɫ
                settextcolor(RED);//������ť���ı���ɫ
                fillroundrect(End_x_button1, End_y_button1 + i * End_distance_button1, End_x_button1 + End_width_button1, End_y_button1 + i * End_distance_button1 + End_height_button1, 10, 10);
                setbkmode(TRANSPARENT);
                outtextxy((int)((End_x_button1 + End_x_button1 + End_width_button1) / 2 - textwidth(End_text_button1[i].c_str()) / 2), (End_y_button1 + i * End_distance_button1 + End_y_button1 + i * End_distance_button1 + End_height_button1) / 2 - textheight(End_text_button1[i].c_str()) / 2.0, End_text_button1[i].c_str());
                POSITION = i;
                break;
            }
            if (m.message == WM_LBUTTONDOWN) {
                if (i == 0) {
                    Game_Show();
                }
                else if (i == 1) {
                    Menu_Show();
                }
            }
        }
    }
    if (!sign) {
        POSITION = End_n_button1;
        End_draw1();
    }

}

void End_Print();
void End_Print()
{
    IMAGE End_background;
    loadimage(&End_background, L"./�ز�ͼ/����ҳ��.jpg", 1200, 760, TRUE);
    putimage(0, 0, &End_background);
    End_draw1();
    settextstyle(50, 25,L"Fangsong");
    settextcolor(BLACK);
    outtextxy(10, 10, L"���ķ�����:");
    outtextxy(10, 45, bs_stringToWString(to_string(Game_Mark)).c_str());
}

void End_Wait();
void End_Wait(){
    while (1) {
        End_check1();
    }
}
void End_Show();
void End_Show() {
    End_Print();
    std::fstream file_rank;
    file_rank.open("rank.txt");

    if (!file_rank.is_open()) {
        return;
    }

    std::vector<int> Group_diff;
    std::vector<std::string> Group_id;
    std::vector<int> Group_highest;
    int End_diff;
    std::string End_id;
    int End_highest;

    while (file_rank >> End_diff >> End_id >> End_highest) {
        Group_diff.push_back(End_diff);
        Group_id.push_back(End_id);
        Group_highest.push_back(End_highest);

        // �������������  
        if (End_id == Menu_Get_ID() && End_diff == Difficulty && End_highest < Game_Mark) {
            Group_highest.back() = Game_Mark; // ������߷�  
        }
    }

    file_rank.close(); // �ر��ļ��Ա��������д  

    // ���ļ�����������ݲ�д����µ�����  
    file_rank.open("rank.txt", std::fstream::out | std::fstream::trunc);
    if (!file_rank.is_open()) {
        return;
    }

    // д����µ�����  
    for (size_t i = 0; i < Group_diff.size(); ++i) {
        file_rank << Group_diff[i] << " " << Group_id[i] << " " << Group_highest[i] << std::endl;
    }

    file_rank.close(); // �ر��ļ�
    End_Wait();
}