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
extern int Game_Mark;//储存全局分数
extern int cur_round ;//刷怪相关全局变量
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
    // 创建一个转换器对象
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    // 使用转换器将 wstring 转换为 string
    return converter.to_bytes(wstr);
}

wstring bs_stringToWString(const std::string& str) {
    wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}
/*
负责人:组长
功能{
	清空界面
	初始化所有与登录相关的全局变量
	打印背景图
	打印登录,注册,忘记密码以及退出四个按钮
	等待用户鼠标输入.若用户点击相应按钮,则调用相应的Show函数
}
类别:view
参数:void
返回值:void
*/
void Home_Show();//没问题
void Home_Show()
{
    MOUSEMSG Mouse;//定义鼠标
    int Window_Width = 752;
    int Window_Height = 1196;
    int GR_Width = 2200;
    int GR_Height = 600;
    int L = 1030;//按键的左边界
    int R = 1170;//按键的右边界
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    IMAGE img_kun1;
    //
    //图片为绝对路径，整合时修改！！！
    //
    loadimage(&img_kun1, L".\\素材图\\首页.jpg",1200,760,true);
    putimage(0, 0, &img_kun1);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, L"SimHei");
    setfillcolor(RGB(103, 229, 215));//背景矩形填充颜色
    fillroundrect(L, 365, R, 435, 10, 10);//绘制矩形和输出文字
    outtextxy(GR_Width / 2 - textwidth(L"登录") / 2,
        GR_Height / 2 + 100 - textheight(L"登录") / 2, L"登录");
    fillroundrect(L, 465, R, 535, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"注册") / 2,
        GR_Height / 2 + 200 - textheight(L"注册") / 2, L"注册");
    fillroundrect(L, 565, R, 635, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"忘记密码") / 2,
        GR_Height / 2 + 300 - textheight(L"忘记密码") / 2, L"忘记密码");
    fillroundrect(L, 665, R, 735, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"退出") / 2,
        GR_Height / 2 + 400 - textheight(L"退出") / 2, L"退出");
    while (1) {
        if (MouseHit()) {
            //获取鼠标消息
            Mouse = GetMouseMsg();
            //用户的鼠标在按钮范围内，并且按下左键
            if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 365 && Mouse.y <= 435 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Login_Show();//登录
                cout << 0;
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 465 && Mouse.y <= 535 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Enroll_Show();//注册
                cout << 1;
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 565 && Mouse.y <= 635 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Passback_Show();//忘记密码
                break;
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 665 && Mouse.y <= 735 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                exit(0);//直接退出程序
            }
        }
    }
}
/*
负责人:听风
功能:初始化与Login界面相关的数据
类别:无(指前后端做都可以)
参数:void
返回值:void
*/
void Login_init();
void Login_init()
{
    Login_Password = " ";
    Login_ID = " ";
}

//
//
int tx_1 = 400, ty_1 = 280;//第一个文字的位置
wchar_t text_1[] = L"请输入账户id";//设置要打印的文字（第一个文字）
int tx_2 = 390, ty_2 = 350;//这是第二个文字的位置（tx_2比上面的tx_1少10.是为了让两个文本框对齐）
wchar_t text_2[] = L"请输入账户密码";//设置要打印的文字（第二个文字）
wchar_t str[] = L"登录";//设置要打印的文字（第三个文字）
wchar_t str_1[] = L"返回";//设置要打印的文字（第四个文字）
//第一个矩形框（id框）
int rectX_1 = tx_1 + 90; // 10是文本和矩形之间的间距
int rectY_1 = ty_1 - 20;
int rectWidth_1 = 150; // 矩形的宽度
int rectHeight_1 = 40; // 矩形的高度
//第二个矩形框（密码框）
int rectX_2 = tx_2 + 100; // 10是文本和矩形之间的间距
int rectY_2 = ty_2 - 20;
int rectWidth_2 = 150; // 矩形的宽度
int rectHeight_2 = 40; // 矩形的高度
//第三个框--圆角矩形框（登录框）
int rx = rectX_2 + 15;
int ry = rectY_2 + 50;
int rw = rectWidth_2 - 40;
int rh = rectHeight_2 + 20;
//第四个框----圆角矩形框（返回框）
int rx_2 = rx;
int ry_2 = ry + 70;
int rw_2 = rw;
int rh_2 = rh;

/*
负责人:听风
功能:打印背景图,打印ID和密码输入框以及返回和登录按钮
类别:view
参数:void
返回值:void
*/
void hui_13(int x, int y, int h, const wchar_t str[])//绘制字体
{
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    int vSpace = ((h - textheight(str)) / 2);
    outtextxy(x, y + vSpace, str);
}
void hui_14(int x, int y, int h, LPCWSTR str)//绘制字体
{
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    int vSpace = ((h - textheight(str)) / 2);
    outtextxy(x, y + vSpace, str);
}
//
//
void hui_1()//绘制请输入账户id文字以及输入框
{   //1 打印
    setbkmode(TRANSPARENT);//设置背景透明
    settextcolor(BLACK);//设置字体颜色
    settextstyle(12, 0, L"宋体");//设置字体大小，粗细，字体
    outtextxy(tx_1, ty_1, text_1);//输出文字

    //设计矩形框
    setfillcolor(WHITE);//设置颜色
    fillrectangle(rectX_1, rectY_1, rectX_1 + rectWidth_1, rectY_1 + rectHeight_1);
}
void hui_2()//绘制请输入账户密码文字以及输入框
{

    //2 打印请输入账户密码文字
    setbkmode(TRANSPARENT);//设置背景透明
    settextcolor(BLACK);//设置字体颜色
    settextstyle(12, 0, L"宋体");//设置字体大小，粗细，字体
    outtextxy(tx_2, ty_2, text_2);//输出文字
    //设计矩形框
    setfillcolor(WHITE);//设置颜色
    fillrectangle(rectX_2, rectY_2, rectX_2 + rectWidth_2, rectY_2 + rectHeight_2);//这里的不全都是2是为了和上面的框对齐
}


void hui_3()//绘制登录按钮
{


    //3 打印登录按钮
    //来一个矩形
    setfillcolor(RGB(216, 221, 223));
    solidroundrect(rx, ry, rx + rw, ry + rh, 10, 10);
    //绘制文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    int wSpace = ((rw - textwidth(str)) / 2);
    int vSpace = ((rh - textheight(str)) / 2);
    outtextxy(rx + wSpace, ry + vSpace, str);
}
void hui_4()//绘制返回按钮
{

    //4 打印返回按钮
    //来一个矩形
    setfillcolor(RGB(216, 221, 223));
    solidroundrect(rx_2, ry_2, rx_2 + rw_2, ry_2 + rh_2, 10, 10);
    //绘制文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    int wSpace_2 = ((rw_2 - textwidth(str_1)) / 2);
    int vSpace_2 = ((rh_2 - textheight(str_1)) / 2);
    outtextxy(rx_2 + wSpace_2, ry_2 + vSpace_2, str_1);
}

/*
负责人:听风
功能:打印背景图,打印ID和密码输入框以及返回和登录按钮
类别:view
参数:void
返回值:void
*/
void Login_Print();
void Login_Print()
{

    //0加载图片
    IMAGE img;
    loadimage(&img, L".\\素材图\\首页等.png", Window_Width, Window_Height); // 替换为你的图片文件名
    // 将图片绘制到窗口上，作为背景
    // 注意：默认从(0,0)坐标开始绘制，即窗口的左上角
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
bool button(int x, int y, int w, int h, ExMessage& msg)//传入按钮的位置，判断鼠标是否点击按钮
{
    if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
    {
        return true;
    }
    return false;
}


/*
负责人:听风
功能:
	建立while(1)循环并等待用户鼠标输入.{
		若用户点击ID输入框,则弹出ID输入框,接收用户输入的ID并将该ID储存至数据Login_ID中
		若用户点击密码输入框,则弹出密码输入框,接收用户输入的密码并将该密码储存至数据Login_Password中
		若用户点击登录,则调用Login_Wait_Judge()函数判断ID与密码是否合法.若合法,输出提示词,将Login_ID的值储存至Menu_ID中,并调用Menu_Show函数;若不合法,则输出提示词;
		若用户点击返回,则调用Home_Show函数;
	}
类别:view
参数:void
返回值:void
*/
void Login_Wait();
void Login_Wait()
{
    //接收用户输入的ID
    ExMessage msg_1;

    msg_1 = getmessage(EX_MOUSE);
    while (1)
    {
        //获取消息
        if (peekmessage(&msg_1, EX_MOUSE))
        {
            if (button(rectX_1, rectY_1, rectWidth_1, rectHeight_1, msg_1))//左键点击ID输入框
            {
                // 定义字符串缓冲区，并接收用户输入
                wchar_t s[16];
                InputBox(s, 16, L"请输入ID");
                //重新打印输入框，把之前输入的覆盖掉，这样子就可以让输入的数字不会重叠
                setfillcolor(WHITE);//设置颜色
                fillrectangle(rectX_1, rectY_1, rectX_1 + rectWidth_1, rectY_1 + rectHeight_1);
                wstring num(s);
                Login_ID = bs_WStringTostring(num);
                const char* cstr = Login_ID.c_str();     // 将 std::string 转换为 C 风格字符串
                size_t wideStringLength = mbstowcs(nullptr, cstr, 0) + 1;  // 计算宽字符串所需的大小
                wchar_t* wideString = new wchar_t[wideStringLength];  // 分配内存

                // 实际执行转换
                mbstowcs(wideString, cstr, wideStringLength);

                hui_13(rectX_1, rectY_1, rectHeight_1, wideString);
            }
            else if (button(rectX_2, rectY_2, rectWidth_2, rectHeight_2, msg_1))//左键点击密码输入框
            {
                wchar_t s_2[16];
                InputBox(s_2, 16, L"请输入密码");
                //重新打印输入框，把之前输入的覆盖掉，这样子就可以让输入的数字不会重叠
                setfillcolor(WHITE);//设置颜色
                fillrectangle(rectX_2, rectY_2, rectX_2 + rectWidth_2, rectY_2 + rectHeight_2);
                wstring num_2(s_2);
                Login_Password = bs_WStringTostring(num_2);
                const char* cstr_2 = Login_Password.c_str();     // 将 std::string 转换为 C 风格字符串
                size_t wideStringLength = mbstowcs(nullptr, cstr_2, 0) + 1;  // 计算宽字符串所需的大小
                wchar_t* wideString = new wchar_t[wideStringLength];  // 分配内存

                // 实际执行转换
                mbstowcs(wideString, cstr_2, wideStringLength);

                hui_14(rectX_2, rectY_2, rectHeight_2, wideString);

            }
            else if (button(rx, ry, rw, rh, msg_1))//左键点击登录按钮
            {
                if (Login_Wait_Judge())//判断ID与密码是否合法
                {
                    outtextxy(10, 10, L"登录成功");
                    Sleep(1000);
                    Menu_init();
                    Menu_Show();
                }
                else
                {
                    outtextxy(10, 10, L"登录失败");
                    Menu_ID = "";
                }
            }
            else if (button(rx_2, ry_2, rw_2, rh_2, msg_1))//左键点击返回按钮
            {
                outtextxy(50, 10, L"返回成功");
                Sleep(1000);
                Home_Show();
            }
        }
    }
}

/*
负责人:听风
功能:
	清空界面
	Login_Print()
	Login_Wait()
类别:view
参数:void
返回值:void
*/
void Login_Show();
void Login_Show()
{
    cleardevice();
    Login_Print();
    Login_Wait();
}

int width_character3 = 15;//提示词宽度
int height_character3 = 30;//提示词高度

int width_button1 = 150;//按钮宽度
int height_button1 = 40;//按钮高度
int x_button1 = 600 - 75;//第一个按钮左上角的x值
int y_button1 = 500;//第一个按钮左上角的y值
int distance_button1 = 60;//两个按钮之间的高度差
int n_button1 = 2;//按钮个数
int width_character1 = 15;//汉字宽度
int height_character1 = 30;//汉字高度
vector<wstring> text_button1 = { L"找回", L"返回" };//每个按钮上的文本

void draw0() {//打印提示框
    setfillcolor(WHITE);
    fillroundrect(790, 490, 1100, 600, 10, 10);
}

void draw1() {//这个函数用来打印n个未触摸状态的按钮
    settextstyle(height_character1, width_character1, _T("FangSong"));
    setfillcolor(WHITE);//调整按钮原本的背景颜色
    settextcolor(BLACK);//调整文本颜色
    for (int i = 0; i < n_button1; i++) {
        fillroundrect(x_button1, y_button1 + i * distance_button1, x_button1 + width_button1, y_button1 + i * distance_button1 + height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((x_button1 + x_button1 + width_button1) / 2 - textwidth(text_button1[i].c_str()) / 2), (y_button1 + i * distance_button1 + y_button1 + i * distance_button1 + height_button1) / 2 - textheight(text_button1[i].c_str()) / 2.0, text_button1[i].c_str());
    }
}

void check1()//检查按是否被触摸.若触摸则改变按钮样式
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
                setfillcolor(GREEN);//触摸后按钮颜色
                settextcolor(RED);//触摸后按钮上文本颜色
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
                        outtextxy(800, 500, L"您的密码是：");
                        outtextxy(800, 550, bs_stringToWString(Passback_Wait_PasswordShow()).c_str());
                    }
                    else {
                        draw0();
                        outtextxy(800, 500, L"账号或密保答案错误！");

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

int width_button2 = 400;//按钮宽度
int height_button2 = 50;//按钮高度
int x_button2 = 600 - 200;//第一个按钮左上角的x值
int y_button2 = 200;//第一个按钮左上角的y值
int distance_button2 = 60;//两个按钮之间的高度差
int n_button2 = 2;//按钮个数
int width_character2 = 15;//汉字宽度
int height_character2 = 30;//汉字高度
vector<wstring> text_button2 = { L"请输入ID",L"请输入密保" };//每个按钮上的文本
void draw2() {//这个函数用来打印n个未触摸状态的按钮
    settextstyle(height_character2, width_character2, _T("FangSong"));
    setfillcolor(WHITE);//调整按钮原本的背景颜色
    settextcolor(BLACK);//调整文本颜色
    for (int i = 0; i < n_button2; i++) {
        fillroundrect(x_button2, y_button2 + i * distance_button2, x_button2 + width_button2, y_button2 + i * distance_button2 + height_button2, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((x_button2 + x_button2 + width_button2) / 2 - textwidth(text_button2[i].c_str()) / 2), (y_button2 + i * distance_button2 + y_button2 + i * distance_button2 + height_button2) / 2 - textheight(text_button2[i].c_str()) / 2.0, text_button2[i].c_str());
    }
}
void check2()//检查按是否被触摸.若触摸则改变按钮样式
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
                        InputBox(num, 16, L"请输入ID");
                        wstring num2(num);
                        text_button2[i] = num2;
                        Passback_ID = bs_WStringTostring(num2);
                    }
                    else if (i == 1) {
                        InputBox(num, 16, L"请输入密保");
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
负责人:毕宿
功能:初始化与Passback界面相关的数据
类别:无(指前后端做都可以)
参数:void
返回值:void
*/
void Passback_init();
void Passback_init() {
    string Passback_ID = "";
    string Passback_Password = "";
}

/*
负责人:毕宿
功能:打印背景图,打印ID和密保输入框以及返回和找回密码按钮
类别:view
参数:void
返回值:void
*/
void Passback_Print();
void Passback_Print() {
    IMAGE background;
    loadimage(&background, L".\\素材图\\首页等.png", 1200, 760, true);
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    settextstyle(height_character2/1.5, width_character2/1.5, _T("FangSong"));
    outtextxy(350, (y_button2 + 0 * distance_button2 + y_button2 + 0 * distance_button2 + height_button2) / 2 - textheight(text_button2[0].c_str()) / 2.0, L"ID：");
    outtextxy(350, (y_button2 + 1 * distance_button2 + y_button2 + 1 * distance_button2 + height_button2) / 2 - textheight(text_button2[1].c_str()) / 2.0, L"密保：");
    draw1();
    draw2();
}

/*
负责人:毕宿
功能:
	建立while(1)循环并等待用户鼠标输入.{
		若用户点击ID输入框,则弹出ID输入框,接收用户输入的ID并将该ID储存至数据Passback_ID中
		若用户点击密保输入框,则弹出密保输入框,接收用户输入的密码并将该密码储存至数据Passback_Password中
		若用户点击找回,则调用Passback_Wait_Judge()函数判断ID与密保是否合法.若合法,输出提示词并调用Passback_Wait_PasswordShow输出密码;若不合法,则输出提示词;
		若用户点击返回,则调用Home_Show函数;
	}
类别:view
参数:void
返回值:void
*/
void Passback_Wait();
void Passback_Wait() {
    while (1) {
        check1();
        check2();
    }
}

/*
负责人:毕宿
功能:
	清空界面
	Passback_Print()
	Passback_Wait()
类别:view
参数:void
返回值:void
*/
void Passback_Show();
void Passback_Show() {
    cleardevice();
    Passback_init();
    Passback_Print();
    Passback_Wait();
}

/*
负责人:念安
功能:初始化与Enroll界面相关的数据
类别:无(指前后端做都可以)
参数:void
返回值:void
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
负责人:念安
功能:打印背景图,打印昵称,密码和密保输入框以及返回和注册按钮
类别:view
参数:void
返回值:void
*/
void Enroll_Print();
void Enroll_Print()
{
    initgraph(1200, 760, 1);
    IMAGE image;
    loadimage(&image, L".\\素材图\\首页等.png", 1200, 760);
    putimage(0, 0, &image);


    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(500, 230, 500 + 200, 230 + 42, 10, 10);
    wchar_t text1[] = L"请输入账号昵称";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"黑体");
    outtextxy(530, 240, text1);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(500, 280, 500 + 200, 280 + 42, 10, 10);
    wchar_t text2[] = L"请输入账号密码";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"黑体");
    outtextxy(530, 290, text2);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(500, 330, 500 + 200, 330 + 42, 10, 10);
    wchar_t text3[] = L"请输入密保答案";
    wchar_t text[] = L"您的生日是：";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"黑体");
    outtextxy(530, 340, text3);
    outtextxy(390, 340, text);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(530, 380, 530 + 150, 380 + 42, 10, 10);
    wchar_t text4[] = L"注册";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"黑体");
    outtextxy(584, 390, text4);


    setfillcolor(WHITE);
    setlinecolor(BLACK);
    solidroundrect(530, 430, 530 + 150, 430 + 42, 10, 10);
    wchar_t text5[] = L"返回";
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, L"黑体");
    outtextxy(584, 440, text5);
}

bool checkName()
{
    if (Enroll_Name.size() == 0)
    {
        MessageBox(NULL, _T("昵称为空！请输入昵称！"), _T("昵称"), MB_OK);
        return false;
    }
    return true;

}
bool checkPassword1()//有一点问题,不知为啥单独拿出来运行没问题，一整合就错误频出，苦笑
{
    int length = Enroll_Password1.size();
    if (length == 0)
    {
        MessageBox(NULL, _T("密码为空！请输入密码！"), _T("密码"), MB_OK);
        return false;
    }
    else if (length > 16 || length < 5)
    {
        outtextxy(710, 290, L"密码过长或过短！请重新输入！");
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
        MessageBox(NULL, _T("密保为空！请输入密保！"), _T("密保"), MB_OK);
        return false;
    }
    return true;

}
/*
负责人:念安
功能:
	建立while(1)循环并等待用户鼠标输入.{
		若用户点击昵称输入框,则弹出昵称输入框,接收用户输入的昵称并将该昵称储存至数据Enroll_Name中
		若用户点击密码输入框,则弹出密码输入框,接收用户输入的密码并将该密码储存至数据Enroll_Password1中
		若用户点击密保输入框,则弹出密保输入框,接收用户输入的密保并将该密保储存至数据Enroll_Password2中
		若用户点击注册,则判断昵称,密码以及密保是否合法.若合法,输出提示词并调用Enroll_Wait_Save输出密码;若不合法,则输出提示词;
		若用户点击返回,则调用Home_Show函数;
	}
类别:view
参数:void
返回值:void
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
                    settextstyle(20, 0, L"黑体");
                    outtextxy(510, 290, s2);
                    Enroll_Password1 = bs_WStringTostring(wstring(s2));//用户在注册界面输入的昵称
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
                    Enroll_Password2 =bs_WStringTostring(wstring(s3));//用户在注册界面输入的昵称
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
                        MessageBox(NULL, to_wstring(id).c_str(), _T("注册成功！您的ID为"), MB_OK);
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
负责人:念安
功能:
	清空界面
	Passback_Print()
	Passback_Wait()
类别:view
参数:void
返回值:void
*/
void Enroll_Show();
void Enroll_Show()//这个应该就这么多吧，不是我改
{
    cleardevice();
    Enroll_Print();
    Enroll_Wait();
}

/*
负责人:念安
功能:初始化音效为开,难度为简单
参数:void
返回值:void
*/
void Menu_init();//初始化不全,且被屏蔽
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
负责人:念安
功能{
	清空界面
	打印背景图
	打印开始游戏,设置,排行榜,商店,退出账号,退出游戏以及账号信息显示框七个按钮
	在左上角用函数Menu_Get_ID(),Menu_Get_Name(),Menu_Get_Highest()输出账号信息
	等待用户鼠标输入.若用户点击相应按钮,则调用相应的Show函数
}
类别:view
参数:void
返回值:void
*/
void Menu_Show();
void Menu_Show()
{
    cleardevice();
    settextstyle(20, 0, L"微软雅黑");
    IMAGE m2;
    loadimage(&m2, L".\\界面图片\\QQ图片20240801174722.jpg", 1200, 760,true);
    putimage(0, 0, &m2);
    setbkmode(TRANSPARENT);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(500, 450, 500 + 200, 450 + 42, 10, 10);//开始游戏
    solidroundrect(400, 500, 400 + 150, 500 + 42, 10, 10);//退出账号
    solidroundrect(650, 500, 650 + 150, 500 + 42, 10, 10);//退出游戏
    solidroundrect(50, 300, 50 + 150, 300 + 42, 10, 10);//排行榜
    solidroundrect(50, 250, 50 + 150, 250 + 42, 10, 10);//设置
    solidroundrect(50, 200, 50 + 150, 200 + 42, 10, 10);//商店
    wchar_t text1[] = L"开始游戏";
    int x1 = 500 + (200 - textwidth(text1)) / 2;
    int y1 = 450 + (42 - textheight(text1)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x1, y1, text1);
    wchar_t text2[] = L"退出账号";
    int x2 = 400 + (150 - textwidth(text2)) / 2;
    int y2 = 500 + (42 - textheight(text2)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x2, y2, text2);

    wchar_t text3[] = L"退出游戏";
    int x3 = 650 + (150 - textwidth(text3)) / 2;
    int y3 = 500 + (42 - textheight(text3)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x3, y3, text3);

    wchar_t text4[] = L"排行榜";
    int x4 = 50 + (200 - textwidth(text4)) / 2;
    int y4 = 300 + (42 - textheight(text4)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(95, y4, text4);

    wchar_t text5[] = L"设置";
    int x5 = 50 + (150 - textwidth(text5)) / 2;
    int y5 = 250 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x5, y5, text5);

    wchar_t text6[] = L"商店";
    int x6 = 50 + (150 - textwidth(text5)) / 2;
    int y6 = 200 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x6, y6, text6);
    solidroundrect(10, 10, 10 + 250, 10 + 60, 10, 10);
    outtextxy(10, 10, L"ID:");
    outtextxy(10, 30, L"昵称:");
    outtextxy(10, 50, L"最高分数:");
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
                if (msg1.x > 500 && msg1.x < 700 && msg1.y>450 && msg1.y < 492)//开始游戏
                {
                    Game_Show();

                }
                else if (msg1.x > 400 && msg1.x < 650 && msg1.y>500 && msg1.y < 542)//退出账号
                {
                    Home_Show();
                }
                else if (msg1.x > 650 && msg1.x < 800 && msg1.y>500 && msg1.y < 542)//退出游戏
                {
                    exit(0);
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>300 && msg1.y < 342)//排行榜
                {

                    ListSelect_Show();
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>250 && msg1.y < 292)//设置
                {
                    Setting_Show();
                }
                else if (msg1.x > 50 && msg1.x < 200 && msg1.y>200 && msg1.y < 242)//商店
                {
                    Shop_Show();
                }
            }
        }
    }
}

/*
负责人:念安
功能:打印背景图,打印开关音效,难度切换,制作人员信息,游戏玩法和返回按钮
类别:view
参数:void
返回值:void
*/
void Setting_Print();//部分屏蔽
void Setting_Print()
{
    settextstyle(20, 0, L"微软雅黑");
    IMAGE m3;
    loadimage(&m3, L"./素材图/主菜单等.jpg", 1200, 760);
    putimage(0, 0, &m3);
    setbkmode(TRANSPARENT);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidroundrect(10, 10, 10 + 150, 10 + 42, 10, 10);
    solidroundrect(10, 60, 10 + 150, 60 + 42, 10, 10);
    solidroundrect(10, 110, 10 + 150, 110 + 42, 10, 10);
    solidroundrect(10, 160, 10 + 150, 160 + 42, 10, 10);
    solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
    wchar_t text1[] = L"返回";
    int x1 = 10 + (150 - textwidth(text1)) / 2;
    int y1 = 10 + (42 - textheight(text1)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x1, y1, text1);
    wchar_t text2[] = L"制作人员介绍";
    int x2 = 10 + (150 - textwidth(text2)) / 2;
    int y2 = 60 + (42 - textheight(text2)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x2, y2, text2);

    wchar_t text3[] = L"游戏玩法";
    int x3 = 10 + (150 - textwidth(text3)) / 2;
    int y3 = 110 + (42 - textheight(text3)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x3, y3, text3);

    wchar_t text4[] = L"开关音效";
    int x4 = 10 + (150 - textwidth(text4)) / 2;
    int y4 = 160 + (42 - textheight(text4)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x4, y4, text4);

    wchar_t text5[] = L"难度切换";
    int x5 = 10 + (150 - textwidth(text5)) / 2;
    int y5 = 210 + (42 - textheight(text5)) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(x5, y5, text5);
}

/*
负责人:念安
功能:
	建立while(1)循环并等待用户鼠标输入.{
		若用户点击音效开关,则调整全局变量Music并重新打印音效开关按钮(因为音效开关按钮上要显示当前音效状态)
		若用户点击难度切换按钮,则调整全局变量Difficulty并重新打印难度切换按钮(因为难度切换按钮上要显示当前难度状态)
		若用户点击制作人员信息,则调用Author_Show函数;
		若用户点击游戏玩法,则调用Method_Show函数;
		若用户点击返回,则调用Menu_Show函数;
	}
类别:view
参数:void
返回值:void
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
                        settextstyle(20, 0, L"黑体");
                        outtextxy(40, 170, L"音效已关");
                    }
                    else
                    {
                        Music = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RGB(126, 132, 247));
                        solidroundrect(10, 160, 10 + 150, 160 + 42, 10, 10);
                        settextstyle(20, 0, L"黑体");
                        outtextxy(40, 170, L"音效已开");
                    }
                    Menu_init();


                }
                else if (msg2.x > 10 && msg2.x < 160 && msg2.y>210 && msg2.y < 252)//设置
                {
                    if (Difficulty == 1)
                    {
                        Difficulty = 2;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(GREEN);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"黑体");
                        outtextxy(40, 220, L"中等模式");
                    }
                    else if (Difficulty == 2)
                    {
                        Difficulty = 3;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RED);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"黑体");
                        outtextxy(40, 220, L"困难模式");

                    }
                    else if (Difficulty == 3)
                    {
                        Difficulty = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(WHITE);
                        solidroundrect(10, 210, 10 + 150, 210 + 42, 10, 10);
                        settextstyle(20, 0, L"黑体");
                        outtextxy(40, 220, L"简单模式");
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

void hui_7(int x, int y, int w, int h)//绘制简单难度按钮
{


    setfillcolor(RGB(216, 221, 223));//设置颜色
    solidroundrect(x, y, x + w, y + h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    wchar_t d_1[] = L"简单";
    int wSpace = ((w - textwidth(d_1)) / 2);
    int vSpace = ((h - textheight(d_1)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_1);
}
void hui_8(int x, int y, int w, int h)//绘制中等难度按钮
{


    setfillcolor(RGB(216, 221, 223));//设置颜色
    solidroundrect(x, y, x + w, y + h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    wchar_t d_2[] = L"中等";
    int wSpace = ((w - textwidth(d_2)) / 2);
    int vSpace = ((h - textheight(d_2)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_2);

}
void hui_9(int x, int y, int w, int h)//绘制困难难度按钮
{

    setfillcolor(RGB(216, 221, 223));//设置颜色
    solidroundrect(x, y, x + w, y + h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    wchar_t d_3[] = L"困难";
    int wSpace = ((w - textwidth(d_3)) / 2);
    int vSpace = ((h - textheight(d_3)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_3);
}

/*
负责人:听风
功能{
	清空界面
	打印背景图
	打印简单,中等,坤难三个按钮
	等待用户鼠标输入.若用户点击相应按钮,则调用相应的Show函数并传入相应的参数(1代表简单,2代表中等,3代表坤难)
}
类别:view
参数 : void
返回值 : void
*/
void ListSelect_Show();
void hui_10(int x, int y, int w, int h)//绘制返回按钮
{
    //绘制返回按钮
    setfillcolor(RGB(216, 221, 223));//设置颜色
    solidroundrect(x, y, x + w, y + h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    wchar_t d_2[] = L"返回";
    int wSpace = ((w - textwidth(d_2)) / 2);
    int vSpace = ((h - textheight(d_2)) / 2);
    outtextxy(x + wSpace, y + vSpace, d_2);
}
// 
// 
void ListSelect_Show()
{
    cleardevice();//清空界面
    //打印背景图
    IMAGE img;
    loadimage(&img, L"./素材图/主菜单等.jpg", Window_Width, Window_Height); // 替换为你的图片文件名
    // 将图片绘制到窗口上，作为背景
    // 注意：默认从(0,0)坐标开始绘制，即窗口的左上角
    putimage(0, 0, &img);
    int x_7 = 500; int y_7 = 200; int w_7 = 100; int h_7 = 50;//简单难度按钮位置
    int x_8 = 500; int y_8 = 300; int w_8 = 100; int h_8 = 50;//中等难度按钮位置
    int x_9 = 500; int y_9 = 400; int w_9 = 100; int h_9 = 50; //困难难度按钮位置
    int x_10 = 500; int y_10 = 550; int w_10 = 100; int h_10 = 50;//返回按钮位置
    hui_7(x_7, y_7, w_7, h_7);//绘制简单难度按钮
    hui_8(x_8, y_8, w_8, h_8);//绘制中等难度按钮
    hui_9(x_9, y_9, w_9, h_9);//绘制困难难度按钮
    hui_10(x_10, y_10, w_10, h_10);//绘制返回按钮
    ExMessage msg_3;
    msg_3 = getmessage(EX_MOUSE);
    while (1)
    {
        //获取消息
        if (peekmessage(&msg_3, EX_MOUSE))
        {
            if (button(x_7, y_7, w_7, h_7, msg_3))//左键点击简单难度按钮
            {
                List_Show(1);

            }
            else if (button(x_8, y_8, w_8, h_8, msg_3))//左键点击中等难度按钮
            {
                List_Show(2);

            }
            else if (button(x_9, y_9, w_9, h_9, msg_3))//左键点击困难难度按钮
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
负责人:组长
功能:清空画面,打印背景图,充值码输入框,购买商品按钮,组长二维码等
类别:view
参数:void
返回值:void
*/
void Shop_Print();
//功能:清空画面, 打印背景图, 充值码输入框, 购买商品按钮, 组长二维码等
void Shop_Print()
{
    int L = 30;//按键的左边界
    int R = 170;//按键的右边界
    int GR_Width = 200;
    int GR_Height = 0;
    int Window_Width = 752;
    int Window_Height = 1196;
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    IMAGE img_kun2;
    //
    //图片为绝对路径，整合时修改！！！
    //
    loadimage(&img_kun2, L"./素材图/商店页面.jpg");
    putimage(0, 0, &img_kun2);
    settextstyle(30, 0, L"SimHei");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(103, 229, 215));//背景矩形填充颜色
    fillroundrect(L, 25, R, 75, 10, 10);//绘制矩形和输出文字
    outtextxy(GR_Width / 2 - textwidth(L"伤害增加") / 2,
        GR_Height / 2 + 50 - textheight(L"伤害增加") / 2, L"伤害增加");
    fillroundrect(L, 175, R, 225, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"散弹枪") / 2,
        GR_Height / 2 + 200 - textheight(L"散弹枪") / 2, L"散弹枪");
    fillroundrect(L, 325, R, 375, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"无敌道") / 2,
        GR_Height / 2 + 350 - textheight(L"无敌道") / 2, L"无敌道");
    fillroundrect(L, 475, R, 525, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"兑换码") / 2,
        GR_Height / 2 + 500 - textheight(L"兑换码") / 2, L"兑换码");
    fillroundrect(L, 625, R, 675, 10, 10);
    outtextxy(GR_Width / 2 - textwidth(L"BACK") / 2,
        GR_Height / 2 + 650 - textheight(L"BACK") / 2, L"BACK");

}

/*
负责人:组长
功能:
	建立while(1)循环并等待用户鼠标输入.{
		若用户点击充值码输入框,则弹出充值码输入框,接收用户输入的充值码并将该充值码储存至数据Shop_Password中.调用Shop_Wait_Judge函数判断充值是否成功.若成功则输出提示词并Gold+=addGold,若失败则输出提示词
		若用户点击返回,则调用Menu_Show函数;
	}
类别:view
参数:void
返回值:void
*/
void Shop_Wait();
void Shop_Wait()
{
    //
    int Recharge = 0;//整合记得删
    int Gold = 0;//整合记得删
    int addGold = 6;//整合记得删

    //
    int L = 30;//按键的左边界
    int R = 170;//按键的右边界
    MOUSEMSG Mouse;
    while (true)
    {
        if (MouseHit())
        {
            Mouse = GetMouseMsg();
            if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 25 && Mouse.y <= 75 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //购买伤害增加
                if (Gold >= 1) {
                    Gold = Gold - 1;
                    Recharge += 1;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 175 && Mouse.y <= 225 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //购买散弹枪
                if (Gold >= 2) {
                    Gold = Gold - 2;
                    Recharge += 2;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 325 && Mouse.y <= 375 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //购买无敌
                if (Gold >= 3) {
                    Gold = Gold - 3;
                    Recharge += 3;
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 475 && Mouse.y <= 525 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //兑换码
                wchar_t* rechange_code=nullptr;
                InputBox(rechange_code, 10, L"请输入充值码");
                if (wstring(rechange_code).size() != 0) {
                    Shop_Password = bs_WStringTostring(wstring(rechange_code));
                    if (Shop_Wait_Judge())
                    {
                        Gold += addGold;
                        //输出氪金成功
                    }
                    else
                    {
                        //输出氪金失败
                    }
                }
            }
            else if (Mouse.x >= L && Mouse.x <= R &&
                Mouse.y >= 625 && Mouse.y <= 675 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //返回主菜单
                Menu_Show();
            }
        }


    }
}

/*
负责人:组长
功能:
	Shop_init()
	Shop_Print()
	Shop_Wait()
类别:无
参数:void
返回值:void
*/
void Shop_Show();
void Shop_Show() {
    Shop_init();
    Shop_Print();
    Shop_Wait();
}

/*
负责人:组长
功能:打印背景图,制作人员信息与返回按钮
类别:view
参数:void
返回值:void
*/
void Author_Print();
void Author_Print()
{
    MOUSEMSG Mouse;//定义鼠标
    int Window_Width = 752;
    int Window_Height = 1196;
    cleardevice();
    IMAGE img_kun2;
    //
    //图片为绝对路径，整合时修改！！！
    //
    loadimage(&img_kun2, L".\\界面图片\\kun.jpg");
    putimage(0, 0, &img_kun2);
    settextstyle(30, 0, L"微软雅黑");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    setfillcolor(RGB(98, 90, 88));//背景矩形填充颜色
    /*
    打印小组信息！！！
     */
    settextcolor(RGB(119, 103, 255));
    outtextxy(90 - textwidth(L"小组信息：") / 2,
        50 - textheight(L"小组信息：") / 2, L"小组信息：");
    settextcolor(BLACK);
    fillroundrect(1030, 665, 1170, 735, 10, 10);
    outtextxy(1100 - textwidth(L"返回") / 2,
        700 - textheight(L"返回") / 2, L"返回");
    settextstyle(50, 0, L"微软雅黑");
    settextcolor(WHITE);
    outtextxy(300 - textwidth(L"雪穗: 坤门不倒,IKUN永存") / 2,
        100 - textheight(L"雪穗: 坤门不倒,IKUN永存") / 2, L"雪穗: 坤门不倒,IKUN永存");
    outtextxy(265 - textwidth(L"毕宿：蔡蔡c艹练习生") / 2,
        175 - textheight(L"毕宿：蔡蔡c艹练习生") / 2, L"毕宿：蔡蔡c艹练习生");
    outtextxy(240 - textwidth(L"腿毛：蔡蔡大学生") / 2,
        250 - textheight(L"腿毛：蔡蔡大学生") / 2, L"腿毛：蔡蔡大学生");
    outtextxy(350 - textwidth(L"九喜：给教堂屋顶小黑子们献吻") / 2,
        325 - textheight(L"九喜：给教堂屋顶小黑子们献吻") / 2, L"九喜：给教堂屋顶小黑子们献吻");
    outtextxy(270 - textwidth(L"听风：闪光，你抓不住") / 2,
        400 - textheight(L"听风：闪光，你抓不住") / 2, L"听风：闪光，你抓不住");
    outtextxy(315 - textwidth(L"丁真：到达世界最高城-理塘") / 2,
        475 - textheight(L"丁真：到达世界最高城-理塘") / 2, L"丁真：到达世界最高城-理塘");
    outtextxy(230 - textwidth(L"阿呦：just do  it!") / 2,
        550 - textheight(L"阿呦：just do  it!") / 2, L"阿呦：just do  it!");
    outtextxy(310 - textwidth(L"念安：心向暖阳，无畏风霜") / 2,
        625 - textheight(L"念安：心向暖阳，无畏风霜") / 2, L"念安：心向暖阳，无畏风霜");

}

/*
负责人:组长
功能:
	建立while(1)循环,等待用户鼠标输入.若用户点击返回按钮,则调用Setting_Show()函数
类别:view
参数:void
返回值:void
*/
void Author_Wait();
void Author_Wait()
{
    MOUSEMSG Mouse;
    while (true)
    {

        if (MouseHit()) {
            //获取鼠标消息
            Mouse = GetMouseMsg();
            //用户的鼠标在按钮范围内，并且按下左键
            if (Mouse.x >= 1030 && Mouse.x <= 1170 &&
                Mouse.y >= 665 && Mouse.y <= 735 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                Setting_Show();//返回设置
                break;
            }
        }

    }
}

/*
功能:组长
	Author_Print();
	Author_Wait();
*/
void Author_Show();
void Author_Show() {
    Author_Print();
    Author_Wait();
}


/*
* 负责人:组长
功能:
	Method_Print();
	Method_Wait();
*/
void Method_Show();
void Method_Show() {
    //加载相关资源
    int Window_Width = 752;
    int Window_Height = 1196;
    initgraph(Window_Height, Window_Width, EX_SHOWCONSOLE);
    cleardevice();
    MOUSEMSG Mouse;
    IMAGE k1;
    loadimage(&k1, L".\\界面图片\\QQ图片20240801173825.jpg");
    putimage(0, 0, &k1);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, L"SimHei");
    setfillcolor(RGB(255, 255, 255));
    //退出
    settextcolor(RGB(214, 157, 133));
    outtextxy(200 - textwidth(L"这么简单的游戏还用教？") / 2,
       100 - textheight(L"这么简单的游戏还用教？") / 2, L"这么简单的游戏还用教？");
    outtextxy(200 - textwidth(L"看会美女算了") / 2,
        150 - textheight(L"看会美女算了") / 2, L"看会美女算了");
    fillroundrect(1100, 500, 1150, 600, 10, 10);
    outtextxy(1125 - textwidth(L"退") / 2,
        530 - textheight(L"退") / 2,
        L"退");
    outtextxy(1125 - textwidth(L"出") / 2,
        570 - textheight(L"出") / 2,
        L"出");
    FlushBatchDraw();
    while (true) {
        if (MouseHit()) {
            Mouse = GetMouseMsg();
            if (Mouse.x >= 1100 && Mouse.x <= 1150 &&
                Mouse.y >= 500 && Mouse.y <= 600 &&
                Mouse.uMsg == WM_LBUTTONDOWN) {
                //返回设置
                Setting_Show();
                break;

            }


        }
    }
}

int List_width_button1 = 100;//按钮宽度
int List_height_button1 = 40;//按钮高度
int List_x_button1 = 600 - 50;//第一个按钮左上角的x值
int List_y_button1 = 600;//第一个按钮左上角的y值
int List_distance_button1 = 60;//两个按钮之间的高度差
int List_n_button1 = 1;//按钮个数
int List_width_character1 = 15;//汉字宽度
int List_height_character1 = 30;//汉字高度
vector<wstring> List_text_button1 = { L"返回" };//每个按钮上的文本

void List_draw1() {//这个函数用来打印n个未触摸状态的按钮
    settextstyle(List_height_character1, List_width_character1, _T("FangSong"));
    setfillcolor(WHITE);//调整按钮原本的背景颜色
    settextcolor(BLACK);//调整文本颜色
    for (int i = 0; i < List_n_button1; i++) {
        fillroundrect(List_x_button1, List_y_button1 + i * List_distance_button1, List_x_button1 + List_width_button1, List_y_button1 + i * List_distance_button1 + List_height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((List_x_button1 + List_x_button1 + List_width_button1) / 2 - textwidth(List_text_button1[i].c_str()) / 2), (List_y_button1 + i * List_distance_button1 + List_y_button1 + i * List_distance_button1 + List_height_button1) / 2 - textheight(List_text_button1[i].c_str()) / 2.0, List_text_button1[i].c_str());
    }
}

void List_check1()//检查按是否被触摸.若触摸则改变按钮样式
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
                setfillcolor(GREEN);//触摸后按钮颜色
                settextcolor(RED);//触摸后按钮上文本颜色
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
负责人:毕宿
功能:
	打印背景图,排行榜标题,排行榜展示框和返回按钮
	调用List_init函数(要传入难度参数)
	根据全局变量List打印排行榜
	等待用户鼠标输入.若用户点击返回按钮,则调用ListSelect_Show函数;
类别:view
参数:int,难度参数
返回值:void
*/
void List_Show(int);
void List_Show(int _Difficulty) {
    List_init(_Difficulty);
    cleardevice();
    IMAGE background;
    loadimage(&background, L"C:\\Users\\XKWL\\source\\repos\\如来佛组_飞机大战\\界面图片\\微信图片_20240725221749.jpg", 1200, 760, true);
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    wstring Difficulty_s;
    settextstyle(50, 25, L"FangSong");
    if (_Difficulty == 1) {
        Difficulty_s = L"简单模式排行榜";
    }
    else if (_Difficulty == 2) {
        Difficulty_s = L"中等模式排行榜";
    }
    else if (_Difficulty == 3) {
        Difficulty_s = L"坤难模式排行榜";
    }
    outtextxy(600 - textwidth(L"简单模式排行榜") / 2, 30, Difficulty_s.c_str());//标题
    settextstyle(30, 15, L"FangSong");
    outtextxy(150 - textwidth(L"名次") / 2, 100, L"名次");//小标题
    outtextxy(300 - textwidth(L"ID") / 2, 100, L"ID");//小标题
    outtextxy(600 - textwidth(L"昵称") / 2, 100, L"昵称");//小标题
    outtextxy(900 - textwidth(L"最高分") / 2, 100, L"最高分");//小标题
    for (int i = 0; i < List.size(); i++) {
        const wchar_t* rank_s = to_wstring(i + 1).c_str();
        const wchar_t* ID_s = bs_stringToWString(List[i].getid()).c_str();
        const wchar_t* name_s = bs_stringToWString(List[i].getname()).c_str();
        const wchar_t* highest_s = to_wstring(List[i].gethighest()).c_str();
        outtextxy(150 - textwidth(to_wstring(i + 1).c_str()) / 2, (i+1+4) * 25, to_wstring(i + 1).c_str());//小标题
        outtextxy(300 - textwidth(bs_stringToWString(List[i].getid()).c_str()) / 2, (i + 1 + 4) * 25, bs_stringToWString(List[i].getid()).c_str());//小标题
        outtextxy(600 - textwidth(bs_stringToWString(List[i].getname()).c_str()) / 2, (i + 1 + 4) * 25, bs_stringToWString(List[i].getname()).c_str());//小标题
        outtextxy(900 - textwidth(to_wstring(List[i].gethighest()).c_str()) / 2, (i + 1 + 4) * 25, to_wstring(List[i].gethighest()).c_str());//小标题
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
负责人:念安
功能:
	初始化所有与游戏相关的数据
参数;void
返回值:void
*/
void Game_init();
void Game_init()
{
    BaseV = 1;//游戏界面,移速为1的物体的移速(每一帧移动的格数)
    BaseR = 10;
    CClock = 0;//代表游戏时钟,用于辅助刷怪机制
    BaseNumber1 = 2;//怪1的基础刷新数量
    BaseNumber2 = 1;//怪2的基础刷新数量
    BaseNumber3 = 1;//怪3的基础刷新数量
    BaseNumber4 = 0;//怪4的基础刷新数量
    BaseNumber5 = 3;//怪5的基础刷新数量
    isbossalive = 0;//表示boss是否存活.1代表存活,0代表死亡
    MyPlaneDir = 0;//表示我方飞机的移动方向数据
    Enermy_Bullet.clear(); //储存敌方子弹的全局数组
    Enermy_Plane.clear();//储存敌方飞机的全局数组
    My_Bullet.clear();//储存我方子弹的全局数组
    Music = 1;
    MyPlane = Plane(630, 380, 2, 10, 1, 30000,2,1,1,1, 0, 0,0,0);
    isbossalive = 0;
    cur_round = -1;
    state_0 = 1, state_1 = 1;
    renew_flag[8] = { 0 };
    settextstyle(30, 15, L"Fangsong");
    Game_Mark = 0;
    loadimage(&m5, L"./素材图/游戏页面.jpg", 1200, 760);
    loadimage(&EnemyBullet_1, L"./素材图/敌方子弹1.png", Bullet1_w, Bullet1_h);
    loadimage(&EnemyBullet_2, L"./素材图/敌方子弹2.png", Bullet2_w, Bullet2_h);
    loadimage(&EnemyBullet_3, L"./素材图/敌方子弹3.png", Bullet3_w, Bullet3_h);
    loadimage(&EnemyBullet_4, L"./素材图/敌方子弹4.png", Bullet4_w, Bullet4_h);
    loadimage(&EnemyBullet_5, L"./素材图/敌方子弹5.png", Bullet5_w, Bullet5_h);
    loadimage(&EnemyBullet_6, L"./素材图/敌方子弹6.png", Bullet6_w, Bullet6_h);
    loadimage(&MyBullet_1, L"./素材图/我方子弹1.jpg", MyBullet1_w, MyBullet1_h, false);
    loadimage(&MyBullet_2, L"./素材图/我方子弹2.jpg", MyBullet1_w, MyBullet1_h, false);
    loadimage(&EnemyPlane_1, L"./素材图/敌机1.jpg", Plane1_w, Plane1_h);
    loadimage(&EnemyPlane_2, L"./素材图/敌机2.jpg", Plane2_w, Plane2_h);
    loadimage(&EnemyPlane_3, L"./素材图/敌机3.jpg", Plane3_w, Plane3_h);
    loadimage(&EnemyPlane_4, L"./素材图/敌机4.jpg", Plane4_w, Plane4_h);
    loadimage(&EnemyPlane_5, L"./素材图/敌机5.png", Plane5_w, Plane5_h);
    loadimage(&EnemyPlane_6, L"./素材图/Boss.jpg", Plane6_w, Plane6_h);
    loadimage(&m4, L"./素材图/坤坤.jpg", 30, 30, false);
}

/*
负责人:念安
功能:
	Game_init();
	Game_Print();
	Game_Run();
类别:view
参数;void
返回值:void
*/
void Game_Show();
void Game_Show()
{
    Game_init();
    Game_Print();
    Game_Run();
}

/*
负责人:念安
功能:
	打印游戏界面背景图,暂停按钮;
类别:view
参数;void
返回值:void
*/
void Game_Print();
void Game_Print()
{
    IMAGE m4;
    loadimage(&m4, L"./素材图/游戏页面.jpg", 1200, 760);
    putimage(0, 0, &m4);
    setbkcolor(BLUE);
    solidroundrect(1150, 10, 1150 + 42, 10 + 42, 10, 10);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(1168, 25, L"||");
}

/*
负责人:念安
功能:
	while(1){
	Game_Run_Stop()
	Game_Run_RenewSituation()
	Game_Run_RenewEnermy()
	Game_Run_GetDir()
	Game_Run_Move()
	}
参数;void
返回值:void
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
负责人:念安
功能:接收设备输入.若玩家按下空格或者鼠标点击暂停,那么调用Stop_Show转到暂停页面
类别:view
参数:void
返回值:void
*/
void Game_Run_Stop();
void Game_Run_Stop()
{
    ExMessage msg1;
    if (peekmessage(&msg1)) {
        switch (msg1.message) {
        case WM_LBUTTONDOWN:
        {
            // 获取鼠标坐标   
            if (msg1.x > 1150 && msg1.x < 1192 && msg1.y > 10 && msg1.y < 52) { // 开始游戏  
                Stop_Show();
            }
        }
        break; 
        case WM_KEYDOWN:
            if (msg1.wParam == VK_SPACE) { // VK_SPACE 表示空格键  
                Stop_Show();
            }
            break;
        }
    }
}

/*
负责人:念安
功能:
	接收键盘输入,将移动数据存入全局变量MyPlaneDir中.
	1代表左,2代表左上,3代表上.....以此类推八个方向.
类别:view
参数:void
返回值:void
*/
void Game_Run_GetDir();
void Game_Run_GetDir() {
    MyPlaneDir = 16; // 初始状态设为某个值  

    // 检测按键状态  
    if (GetAsyncKeyState('A') & 0x8000) {
        MyPlaneDir = 0; // 向左  
        if (GetAsyncKeyState('W') & 0x8000) {
            MyPlaneDir = 2;  
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            MyPlaneDir = 14;   
        }
    }
    if (GetAsyncKeyState('W') & 0x8000) {
        MyPlaneDir = 4; // 向上  
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        MyPlaneDir = 8; // 向右  
        if (GetAsyncKeyState('W') & 0x8000) {
            MyPlaneDir = 6;  
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            MyPlaneDir = 10;  
        }
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        MyPlaneDir = 12; // 向下  
    }

    MyPlane.setDir(MyPlaneDir);
}
/*
负责人:念安/组长
功能:
    清除上一帧打印的飞机以及子弹,然后根据当前帧飞机和子弹(这些元素都储存在相应的全局数组里)的x,y值(飞机类和子弹类的坐标都有接口函数),打印飞机和子弹的贴图(不同类型的飞机或者子弹要有不同的贴图哦)
类型:view
参数:void
返回值:void
*/
void Game_Run_Print();
void Game_Run_Print() {//毕宿
    BeginBatchDraw();

    putimage(0, 0, &m5);
    setbkcolor(BLUE);
    solidroundrect(1150, 10, 1150 + 42, 10 + 42, 10, 10);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(1168, 25, L"||");
    //以上,打印背景图以及返回按钮


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
    outtextxy(10, 670, L"血量:");
    outtextxy(10, 700, L"分数:");
    outtextxy(85,700,bs_stringToWString(to_string(Game_Mark)).c_str());
    EndBatchDraw();
}



/*
负责人:听风
功能:打印暂停背景图以及返回按钮
类别:view
参数:void
返回值:void
*/
void Stop_Print();
void Stop_Print()
{

    IMAGE img;
    loadimage(&img, L"./xx.jpg", Window_Width, Window_Height); // 替换为你的图片文件名
    // 将图片绘制到窗口上，作为背景
    // 注意：默认从(0,0)坐标开始绘制，即窗口的左上角
    putimage(0, 0, &img);
    //绘制返回按钮
    //按钮位置
    int f_x = 950;
    int f_y = 50;
    int f_w = 150;
    int f_h = 50;
    setfillcolor(RGB(239, 136, 190));//设置颜色
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    wchar_t d_2[] = L"返回";
    int wSpace = ((f_w - textwidth(d_2)) / 2);
    int vSpace = ((f_h - textheight(d_2)) / 2);
    outtextxy(f_x + wSpace, f_y + vSpace, d_2);

    f_x = 950;
    f_y = 120;
    f_w = 150;
    f_h = 50;
    setfillcolor(RGB(239, 136, 190));//设置颜色
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    outtextxy(1000, 135, L"音效已关");

    f_x = 950;
    f_y = 190;
    f_w = 150;
    f_h = 50;
    setfillcolor(RGB(239, 136, 190));//设置颜色
    solidroundrect(f_x, f_y, f_x + f_w, f_y + f_h, 10, 10);//绘制按钮
    //绘制按钮上的文字
    settextcolor(BLACK);//设置字体颜色
    setbkmode(TRANSPARENT);//设置背景透明
    settextstyle(20, 0, L"微软雅黑");
    outtextxy(990, 205, L"返回主菜单");

}



/*
负责人:听风
功能:
    建立while(1)循环并等待用户鼠标输入.{
        若用户点击返回,则清空屏幕,调用Game_Print()打印游戏界面相关组件并跳出循环;
    }
类别:view
参数:void
返回值:void
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
                        settextstyle(20, 0, L"微软雅黑");
                        outtextxy(1000, 135, L"音效已关");
                    }
                    else
                    {
                        Music = 1;
                        setbkmode(TRANSPARENT);
                        setlinecolor(BLACK);
                        setfillcolor(RGB(239, 136, 190));
                        solidroundrect(950, 120, 950 + 150, 120 + 50, 10, 10);
                        settextstyle(20, 0, L"微软雅黑");
                        outtextxy(1000, 135, L"音效已开");
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
负责人:听风
功能:
    Stop_Print()
    Stop_Wait()
类别:view
参数:void
返回值:void
*/
void Stop_Show();
void Stop_Show()
{
    Stop_Print();
    Stop_Wait();
}

int End_width_button1 = 400;//按钮宽度
int End_height_button1 = 50;//按钮高度
int End_x_button1 = 600 - 200;//第一个按钮左上角的x值
int End_y_button1 = 500;//第一个按钮左上角的y值
int End_distance_button1 = 60;//两个按钮之间的高度差
int End_n_button1 = 2;//按钮个数
int End_width_character1 = 15;//汉字宽度
int End_height_character1 = 30;//汉字高度
vector<wstring> End_text_button1 = { L"再来一局",L"返回" };//每个按钮上的文本
void End_draw1() {//这个函数用来打印n个未触摸状态的按钮
    settextstyle(End_height_character1, End_width_character1, _T("FangSong"));
    setfillcolor(WHITE);//调整按钮原本的背景颜色
    settextcolor(BLACK);//调整文本颜色
    for (int i = 0; i < End_n_button1; i++) {
        fillroundrect(End_x_button1, End_y_button1 + i * End_distance_button1, End_x_button1 + End_width_button1, End_y_button1 + i * End_distance_button1 + End_height_button1, 10, 10);
        setbkmode(TRANSPARENT);
        outtextxy((int)((End_x_button1 + End_x_button1 + End_width_button1) / 2 - textwidth(End_text_button1[i].c_str()) / 2), (End_y_button1 + i * End_distance_button1 + End_y_button1 + i * End_distance_button1 + End_height_button1) / 2 - textheight(End_text_button1[i].c_str()) / 2.0, End_text_button1[i].c_str());
    }
}
void End_check1()//检查按是否被触摸.若触摸则改变按钮样式
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
                setfillcolor(GREEN);//触摸后按钮颜色
                settextcolor(RED);//触摸后按钮上文本颜色
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
    loadimage(&End_background, L"./素材图/结束页面.jpg", 1200, 760, TRUE);
    putimage(0, 0, &End_background);
    End_draw1();
    settextstyle(50, 25,L"Fangsong");
    settextcolor(BLACK);
    outtextxy(10, 10, L"您的分数是:");
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

        // 检查条件并更新  
        if (End_id == Menu_Get_ID() && End_diff == Difficulty && End_highest < Game_Mark) {
            Group_highest.back() = Game_Mark; // 更新最高分  
        }
    }

    file_rank.close(); // 关闭文件以便后续的重写  

    // 打开文件，以清除内容并写入更新的数据  
    file_rank.open("rank.txt", std::fstream::out | std::fstream::trunc);
    if (!file_rank.is_open()) {
        return;
    }

    // 写入更新的数据  
    for (size_t i = 0; i < Group_diff.size(); ++i) {
        file_rank << Group_diff[i] << " " << Group_id[i] << " " << Group_highest[i] << std::endl;
    }

    file_rank.close(); // 关闭文件
    End_Wait();
}