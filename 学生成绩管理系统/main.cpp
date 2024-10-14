#include <iostream>
#include<windows.h>
#include<string>
#include<cstring>
#include <fstream>//文件操作头文件
using namespace std;
//利用homePage函数调出一级菜单界面
void homePage();
//利用mainPage函数调出二级主菜单界面
void mainPage();
//学生结构体
struct Student
{
    string s_Name;//姓名
    int s_Sex;//性别：1男 2女
    string s_StuNum;//学号
    string s_Sch;//学院
    string s_Phone;//电话
    int s_Math;//高数成绩
    int s_Eng;//英语成绩
    int s_Phy;//大物成绩
};
#define MAX 5000//可录入的最大人数
//学生信息结构体
struct studentsInformation
{
    struct Student studentArray[MAX];//学生信息中保存的学生数组
    int s_Num;//学生信息中当前记录的学生个数
};
//记录每位学生姓名和成绩的结构体
struct StudentScore
{
    string name;
    int averagescore;
};
//函数1.录入学生成绩
void addStudent(studentsInformation * stuinf);
//函数2.显示学生成绩
void showStudent(studentsInformation * stuinf);
//辅助函数.判断学生是否在学生信息库中
int isExist(studentsInformation * stuinf, string name);
//函数3-删除学生成绩
void deleteStudent(studentsInformation * stuinf);
//函数4.查找学生成绩
void findStudent(studentsInformation * stuinf);
//函数5.修改学生成绩
void modifyStudent(studentsInformation * stuinf);
//函数6.清空学生信息
void cleanStudent(studentsInformation * stuinfo);
//函数7.1高数平均分
double averageMath(studentsInformation * stuinf);
//函数7.2英语平均分
double averageEnglish(studentsInformation * stuinf);
//函数7.3大物平均分
double averagePhysics(studentsInformation * stuinf);
//函数7.4输出每位同学的平均成绩
void AverageStudentScore(studentsInformation * stuinf);
//函数8冒泡排序输出学霸成绩排名
void bubbleSort1(StudentScore *nameScore,studentsInformation * stuinf);
//函数9冒泡排序输出学渣成绩排名
void bubbleSort2(StudentScore *nameScore,studentsInformation * stuinf);
//读取学生信息到文件中
void test(studentsInformation * stuinf);
int main()
{
    //循环播放背景音乐
    PlaySound ("広橋真紀子 - いのちの名前",NULL,SND_FILENAME|SND_ASYNC);
    //一级菜单
    homePage();
    //创建学生信息结构体变量
    studentsInformation stuinf;
    //创建记录学生姓名和平均成绩的结构体数组
    struct StudentScore nameScore[MAX];
    //初始化学生信息中当前学生个数为0
    stuinf.s_Num=0;
    while(true)//利用循环让教师输入本系统密码，输入错误提示重新输入
    {
        //注：学生管理系统密码为1314520
        double key;
        cin>>key;
        if(key==1314520)
        {
            while(true)//利用循环让教师不断进入主菜单操作
            {
                //进入主菜单（二级菜单）
                mainPage();
                int choice = 0;//创建教师选择输入的变量
                cin>>choice;
                switch(choice)
                {
                case 1://1.录入学生成绩
                    addStudent(&stuinf);
                    break;
                case 2://2.显示学生成绩
                    showStudent(&stuinf);
                    break;
                case 3://3.删除学生成绩
                    deleteStudent(&stuinf);
                    break;
                case 4://4.查询学生成绩
                    findStudent(&stuinf);
                    break;
                case 5://5.修改学生成绩
                    modifyStudent(&stuinf);
                    break;
                case 6://6.清空学生成绩
                    cleanStudent(&stuinf);
                    break;
                case 7://7.查询平均成绩
                    if (stuinf.s_Num == 0)
                    {
                        cout <<"当前记录为空"<<endl;
                    }
                    else
                    {
                        cout<<"★"<<"所有学生的高数平均分为："<<averageMath(&stuinf)<<"分"<<endl;
                        cout<<"★"<<"所有学生的英语平均分为："<<averageEnglish(&stuinf)<<"分"<<endl;
                        cout<<"★"<<"所有学生的大物平均分为："<<averagePhysics(&stuinf)<<"分"<<endl;
                        cout<<"———————————————"<<endl;
                        cout<<"依录入顺序,每位学生成绩如下："<<endl;
                        AverageStudentScore(&stuinf);
                    }
                    break;
                case 8://8.查询学霸排名
                    cout<<"学霸依平均成绩排名如下："<<endl;
                    bubbleSort1(nameScore,&stuinf);
                    break;
                case 9://9.查询学渣排名
                    cout<<"学渣依平均成绩排名如下："<<endl;
                    bubbleSort2(nameScore,&stuinf);
                    break;
                case 10://10.学生信息存档
                    test(&stuinf);
                    cout<<"文件读取成功"<<endl;
                    break;
                case 0://0.退出管理系统
                    cout<<"欢迎下次使用！"<<endl;
                    return 0;
                    break;
                }

            }
            break;
        }
        else
        {
            cout<<"密码错误，请重新输入(我是不会告诉你密码是1314520的!)"<<endl;
        }

    }


    return 0;

}
//封装调用一次菜单的函数
void homePage()
{
    cout<<endl;
    cout<<endl;
    cout<<"             \t"<<"圣·马家沟男子职业技术学院"<<endl;
    cout<<"             \t"<<"    学生成绩管理系统     "<<endl;
    cout<<endl;
    cout<<"             \t"<<"       版本号：+∞        "<<endl;
    cout<<endl;
    cout<<"                      *请输入密码*"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"             \t"<<"        2020年6月         "<<endl;
    cout<<"             \t"<<"      www.hit.edu.cn      "<<endl;
    cout<<endl;
    cout<<endl;
}
//封装调用二级菜单的函数
void mainPage()
{
    cout<<endl;
    cout<<endl;
    cout<<"        ****************欢迎进入本系统****************"<<endl;
    cout<<"             **********************************     "<<endl;
    cout<<"        \t"<<"                         "<<endl;
    cout<<"        \t"<<"     ★学生成绩管理系统★    "<<endl;
    cout<<endl;
    cout<<"                 *      1.录入学生成绩       * "<<endl;
    cout<<"                 *      2.显示学生成绩       * "<<endl;
    cout<<"                 *      3.删除学生成绩       * "<<endl;
    cout<<"                 *      4.查询学生成绩       * "<<endl;
    cout<<"                 *      5.修改学生成绩       * "<<endl;
    cout<<"                 *      6.清空学生成绩       * "<<endl;
    cout<<"                 *      7.查询平均成绩       * "<<endl;
    cout<<"                 *      8.查询学霸排名       * "<<endl;
    cout<<"                 *      9.查询学渣排名       * "<<endl;
    cout<<"                 *     10.学生成绩存档       * "<<endl;
    cout<<"                 *      0.退出管理系统       * "<<endl;
    cout<<"        \t"<<"                         "<<endl;
    cout<<"             **********************************     "<<endl;
    cout<<"        ********************************************"<<endl;
}
//1.录入学生成绩
void addStudent(studentsInformation * stuinf)
{
    //判断学生信息是否已经满，如果满了就不再添加
    if (stuinf->s_Num==MAX)
    {
        cout<<"本系统学生人数已满，无法添加！"<<endl;
        return;
    }
    else
    {
        //添加每位学生的成绩

        //姓名
        string name;
        cout<<"请输入学生姓名：";
        cin>>name;
        stuinf->studentArray[stuinf->s_Num].s_Name = name;
        //性别
        cout<<"请输入学生性别(1男,2女): ";
        int sex=0;
        while(true)
        {
            //如果输入1或2退出循环；如果输入有误重新输入
            cin>>sex;
            if (sex==1||sex==2)
            {
                stuinf->studentArray[stuinf->s_Num].s_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        //学号
        cout<<"请输入学生的学号: ";
        string student_nmuber;
        cin>>student_nmuber;
        stuinf->studentArray[stuinf->s_Num].s_StuNum = student_nmuber;
        //学院
        cout<<"请输入学生所在学院: ";
        string school;
        cin>>school;
        stuinf->studentArray[stuinf->s_Num].s_Sch = school;
        //电话
        cout<<"请输入学生联系电话：";
        string phone;
        cin >> phone;

        stuinf->studentArray[stuinf->s_Num].s_Phone = phone;

        //高数成绩
        cout<<"请输入该学生高数成绩: ";
        float math;
        cin>>math;
        stuinf->studentArray[stuinf->s_Num].s_Math = math;
        //英语成绩
        cout<<"请输入该学生英语成绩: ";
        float english;
        cin>>english;
        stuinf->studentArray[stuinf->s_Num].s_Eng = english;
        //大物成绩
        cout<<"请输入该学生大物成绩: ";
        float physics;
        cin>>physics;
        stuinf->studentArray[stuinf->s_Num].s_Phy = physics;
        //更新学生人数
        stuinf->s_Num++;
        cout<<"成绩录入成功"<<endl;
        system("pause");
        system("cls");
    }
}
//2.显示所有学生信息
void showStudent(studentsInformation * stuinf)
{
    //判断系统中学生人数是否为0，如果为0，记录为空；如果不为0，显示记录的学生信息
    if (stuinf->s_Num == 0)
    {
        cout <<"当前记录为空"<<endl;
    }
    else
    {
        for (int i = 0; i<stuinf->s_Num; i++)
        {
            cout<<"姓名： "<<stuinf->studentArray[i].s_Name<<"  ";
            cout<<"性别： "<<(stuinf->studentArray[i].s_Sex == 1?"男":"女")<<"  ";//if-else结构简单写法，如果是1输出为男；如果不是输出为女
            cout<<"学号： "<<stuinf->studentArray[i].s_StuNum<<"  ";
            cout<<"学院： "<<stuinf->studentArray[i].s_Sch<<"  ";
            cout<<"电话： "<<stuinf->studentArray[i].s_Phone<<"\t";
            cout<<"高数： "<<stuinf->studentArray[i].s_Math<<"分"<<"  ";
            cout<<"英语： "<<stuinf->studentArray[i].s_Eng<<"分"<<"  ";
            cout<<"大物： "<<stuinf->studentArray[i].s_Phy<<"分"<<"  ";
            cout<<"总分： "<<stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy<<"分"<<"  ";
            cout<<"平均分： "<<(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0<<"分"<<endl;
        }
    }
    system ("pause");//按任意键继续
    system ("cls");//清屏
}
//辅助函数：检测学生是否存在于系统中，如果存在，返回学生所在数组中的具体位置；不存在返回-1
int isExist(studentsInformation * stuinf, string name)//参数1：学生信息库    参数2：判断这个学生是否在学生信息库中
{
    for(int i =0; i<stuinf->s_Num; i++)
    {
        if (stuinf->studentArray[i].s_Name == name)//找到教师输入的姓名
        {
            return i;//找到后返回学生所在数组中编号
        }
    }
    return -1;//遍历结束还未找到该学生，返回-1
}
//3.删除某个学生信息
void deleteStudent(studentsInformation * stuinf)
{
    cout<<"请输入您要删除其信息的学生的姓名"<<endl;
    string name;
    cin>>name;
    //result==-1未查到      result!=-1查到
    int result = isExist(stuinf, name);
    if(result !=-1)
    {
        //查找到该学生，进行删除操作，只需要将要所删除的学生后的学生依次向前移动赋值覆盖，并让学生信息库中记录的学生人数-1即可。
        for(int i =result; i<stuinf->s_Num; i++)
        {
            //数据前移
            stuinf->studentArray[i]=stuinf->studentArray[i+1];
        }
        stuinf->s_Num--;//更新学生信息库中人员数
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
//4.查找学生成绩
void findStudent(studentsInformation * stuinf)
{
    cout<<"请输入您要查找的学生姓名"<<endl;
    string name;
    cin>> name;
    //判断该学生是否存在学生信息库中
    int result= isExist(stuinf,name);

    if(result!=-1)//找到学生
    {
        cout<<"姓名："<<stuinf->studentArray[result].s_Name<<"\t";
        cout<<"性别："<<stuinf->studentArray[result].s_Sex<<"\t";
        cout<<"学号："<<stuinf->studentArray[result].s_StuNum<<"\t";
        cout<<"学院："<<stuinf->studentArray[result].s_Sch<<"\t";
        cout<<"电话："<<stuinf->studentArray[result].s_Phone<<"\t";
        cout<<"高数："<<stuinf->studentArray[result].s_Math<<"分"<<"\t";
        cout<<"英语："<<stuinf->studentArray[result].s_Eng<<"分"<<"\t";
        cout<<"大物："<<stuinf->studentArray[result].s_Phy<<"分"<<endl;
    }
    else //未找到该学生
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}
//5.修改学生信息
void modifyStudent(studentsInformation * stuinf)
{
    cout<<"请输入您要修改的学生姓名：";
    string name;
    cin>>name;

    int result = isExist(stuinf,name);
    if(result!=-1)//找到学生
    {
        //修改姓名
        string name;
        cout<<"请重新输入姓名：";
        cin>>name;
        stuinf->studentArray[result].s_Name = name;
        //修改性别
        cout<<"请重新输入性别："<<endl;
        cout<<"1-----------男："<<endl;
        cout<<"2-----------女："<<endl;
        int sex=0;
        while (true)
        {
            cin>>sex;
            if(sex == 1|| sex == 2)
            {
                stuinf->studentArray[result].s_Sex = sex;
                break;//输入正确 退出循环输入
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        //修改学号
        cout<<"请重新输入学号：";
        string student_number;
        cin>>student_number;
        stuinf->studentArray[result].s_Sch = student_number;
        //修改学院
        cout<<"请重新输入学院：";
        string school;
        cin>>school;
        stuinf->studentArray[result].s_Sch = school;
        //修改电话
        cout<<"请重新输入联系电话：";
        string phone;
        cin >> phone;
        stuinf->studentArray[result].s_Phone = phone;
        //修改高数成绩
        cout<<"请重新输入高数成绩：";
        double math;
        cin>>math;
        stuinf->studentArray[result].s_Math=math;
        //修改英语成绩
        cout<<"请重新输入英语成绩：";
        double english;
        cin>>english;
        stuinf->studentArray[result].s_Eng=english;
        //修改大物成绩
        cout<<"请重新输入大物成绩：";
        double physics;
        cin>>physics;
        stuinf->studentArray[result].s_Phy=physics;
        cout<<"修改成功！"<<endl;
    }
    else//未找到该学生
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
//6.清空学生信息
void cleanStudent(studentsInformation * stuinf)//只需要进行逻辑上的清空，就是把学生信息库中的学生个数置为0，从而使访问者无法访问到学生信息，形式上就是清空
{
    cout<<"您是否要清空所有学生信息？"<<endl;
    cout<<"1---------------------是"<<endl;
    cout<<"2---------------------否"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {
        stuinf->s_Num = 0;
        cout<<"学生信息已清空"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        system("pause");
        system("cls");
    }
}
//7.1高数成绩平均分
double averageMath(studentsInformation * stuinf)
{
    int sum_math  = 0;
    double average_math = 0;
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        sum_math+=stuinf->studentArray[i].s_Math;
    }
    average_math=sum_math/stuinf->s_Num;
    return average_math;

}
//7.2英语平均分
double averageEnglish(studentsInformation * stuinf)
{
    int sum_english = 0;
    double average_english = 0;
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        sum_english+=stuinf->studentArray[i].s_Eng;
    }
    average_english=sum_english/stuinf->s_Num;
    return  average_english;
}
//7.3大物平均分
double averagePhysics(studentsInformation * stuinf)
{
    int sum_physics = 0;
    double average_physics = 0;
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        sum_physics+=stuinf->studentArray[i].s_Phy;

    }
    average_physics=sum_physics/stuinf->s_Num;
    return average_physics;

}
//7.4每位同学的平均成绩
void AverageStudentScore(studentsInformation * stuinf)
{
    //判断系统中学生人数是否为0，如果为0，记录为空；如果不为0，显示记录的学生信息
    if (stuinf->s_Num == 0)
    {
        cout <<"当前记录为空"<<endl;
    }
    else
    {

        struct StudentScore nameScore[stuinf->s_Num];
        for (int i = 0; i<stuinf->s_Num; i++)
        {
            nameScore[i].name=stuinf->studentArray[i].s_Name;
            nameScore[i].averagescore=(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0;
            cout<<"姓名："<<nameScore[i].name<<"\t"
                <<"总分："<<3*nameScore[i].averagescore<<"\t"
                <<"平均分："<<nameScore[i].averagescore<<endl;
        }
    }
    system ("pause");//按任意键继续
    system ("cls");//清屏
}
//8.查询学霸成绩排名
void bubbleSort1(StudentScore *nameScore,studentsInformation * stuinf)
{
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        nameScore[i].name=stuinf->studentArray[i].s_Name;
        nameScore[i].averagescore=(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0;
    }
    for(int i =0; i<stuinf->s_Num; i++)
    {
        for(int j =0; j<stuinf->s_Num-i-1; j++)
        {
            if(nameScore[j].averagescore<nameScore[j+1].averagescore)
            {
                StudentScore temp = nameScore[j];
                nameScore[j]=nameScore[j+1];
                nameScore[j+1]=temp;
            }
        }
    }
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        cout<<"第"<<i+1<<"名*"<<"姓名："<<nameScore[i].name<<"\t"
            <<"平均分："<<nameScore[i].averagescore<<endl;
    }
    system("pause");
    system("cls");
}
//9.查询学渣成绩排名
void bubbleSort2(StudentScore *nameScore,studentsInformation * stuinf)
{
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        nameScore[i].name=stuinf->studentArray[i].s_Name;
        nameScore[i].averagescore=(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0;
    }
    for(int i =0; i<stuinf->s_Num; i++)
    {
        for(int j =0; j<stuinf->s_Num-i-1; j++)
        {
            if(nameScore[j].averagescore>nameScore[j+1].averagescore)
            {
                StudentScore temp = nameScore[j];
                nameScore[j]=nameScore[j+1];
                nameScore[j+1]=temp;
            }
        }
    }
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        cout<<"倒数第"<<i+1<<"名*"<<"姓名："<<nameScore[i].name<<"\t"
            <<"平均分："<<nameScore[i].averagescore<<endl;
    }
    system("pause");
    system("cls");
}
void test(studentsInformation * stuinf)
{
    ofstream ofs;//创建流对象
    ofs.open("哈尔滨工业大学2019级学生期末成绩.txt",ios::out);//指定打开方式
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        ofs<<"姓名： "<<stuinf->studentArray[i].s_Name<<"  ";
        ofs<<"性别： "<<(stuinf->studentArray[i].s_Sex == 1?"男":"女")<<"  ";//if-else结构简单写法，如果是1输出为男；如果不是输出为女
        ofs<<"学号： "<<stuinf->studentArray[i].s_StuNum<<"  ";
        ofs<<"学院： "<<stuinf->studentArray[i].s_Sch<<"  ";
        ofs<<"电话： "<<stuinf->studentArray[i].s_Phone<<"\t";
        ofs<<"高数： "<<stuinf->studentArray[i].s_Math<<"分"<<"  ";
        ofs<<"英语： "<<stuinf->studentArray[i].s_Eng<<"分"<<"  ";
        ofs<<"大物： "<<stuinf->studentArray[i].s_Phy<<"分"<<"  ";
        ofs<<"总分： "<<stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy<<"分"<<"  ";
        ofs<<"平均分： "<<(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0<<"分"<<endl;
    }
    ofs.close();//关闭文件

}
