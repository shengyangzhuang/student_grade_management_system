#include <iostream>
#include<windows.h>
#include<string>
#include<cstring>
#include <fstream>//�ļ�����ͷ�ļ�
using namespace std;
//����homePage��������һ���˵�����
void homePage();
//����mainPage���������������˵�����
void mainPage();
//ѧ���ṹ��
struct Student
{
    string s_Name;//����
    int s_Sex;//�Ա�1�� 2Ů
    string s_StuNum;//ѧ��
    string s_Sch;//ѧԺ
    string s_Phone;//�绰
    int s_Math;//�����ɼ�
    int s_Eng;//Ӣ��ɼ�
    int s_Phy;//����ɼ�
};
#define MAX 5000//��¼����������
//ѧ����Ϣ�ṹ��
struct studentsInformation
{
    struct Student studentArray[MAX];//ѧ����Ϣ�б����ѧ������
    int s_Num;//ѧ����Ϣ�е�ǰ��¼��ѧ������
};
//��¼ÿλѧ�������ͳɼ��Ľṹ��
struct StudentScore
{
    string name;
    int averagescore;
};
//����1.¼��ѧ���ɼ�
void addStudent(studentsInformation * stuinf);
//����2.��ʾѧ���ɼ�
void showStudent(studentsInformation * stuinf);
//��������.�ж�ѧ���Ƿ���ѧ����Ϣ����
int isExist(studentsInformation * stuinf, string name);
//����3-ɾ��ѧ���ɼ�
void deleteStudent(studentsInformation * stuinf);
//����4.����ѧ���ɼ�
void findStudent(studentsInformation * stuinf);
//����5.�޸�ѧ���ɼ�
void modifyStudent(studentsInformation * stuinf);
//����6.���ѧ����Ϣ
void cleanStudent(studentsInformation * stuinfo);
//����7.1����ƽ����
double averageMath(studentsInformation * stuinf);
//����7.2Ӣ��ƽ����
double averageEnglish(studentsInformation * stuinf);
//����7.3����ƽ����
double averagePhysics(studentsInformation * stuinf);
//����7.4���ÿλͬѧ��ƽ���ɼ�
void AverageStudentScore(studentsInformation * stuinf);
//����8ð���������ѧ�Գɼ�����
void bubbleSort1(StudentScore *nameScore,studentsInformation * stuinf);
//����9ð���������ѧ���ɼ�����
void bubbleSort2(StudentScore *nameScore,studentsInformation * stuinf);
//��ȡѧ����Ϣ���ļ���
void test(studentsInformation * stuinf);
int main()
{
    //ѭ�����ű�������
    PlaySound ("�ژ���o�� - ���Τ�����ǰ",NULL,SND_FILENAME|SND_ASYNC);
    //һ���˵�
    homePage();
    //����ѧ����Ϣ�ṹ�����
    studentsInformation stuinf;
    //������¼ѧ��������ƽ���ɼ��Ľṹ������
    struct StudentScore nameScore[MAX];
    //��ʼ��ѧ����Ϣ�е�ǰѧ������Ϊ0
    stuinf.s_Num=0;
    while(true)//����ѭ���ý�ʦ���뱾ϵͳ���룬���������ʾ��������
    {
        //ע��ѧ������ϵͳ����Ϊ1314520
        double key;
        cin>>key;
        if(key==1314520)
        {
            while(true)//����ѭ���ý�ʦ���Ͻ������˵�����
            {
                //�������˵��������˵���
                mainPage();
                int choice = 0;//������ʦѡ������ı���
                cin>>choice;
                switch(choice)
                {
                case 1://1.¼��ѧ���ɼ�
                    addStudent(&stuinf);
                    break;
                case 2://2.��ʾѧ���ɼ�
                    showStudent(&stuinf);
                    break;
                case 3://3.ɾ��ѧ���ɼ�
                    deleteStudent(&stuinf);
                    break;
                case 4://4.��ѯѧ���ɼ�
                    findStudent(&stuinf);
                    break;
                case 5://5.�޸�ѧ���ɼ�
                    modifyStudent(&stuinf);
                    break;
                case 6://6.���ѧ���ɼ�
                    cleanStudent(&stuinf);
                    break;
                case 7://7.��ѯƽ���ɼ�
                    if (stuinf.s_Num == 0)
                    {
                        cout <<"��ǰ��¼Ϊ��"<<endl;
                    }
                    else
                    {
                        cout<<"��"<<"����ѧ���ĸ���ƽ����Ϊ��"<<averageMath(&stuinf)<<"��"<<endl;
                        cout<<"��"<<"����ѧ����Ӣ��ƽ����Ϊ��"<<averageEnglish(&stuinf)<<"��"<<endl;
                        cout<<"��"<<"����ѧ���Ĵ���ƽ����Ϊ��"<<averagePhysics(&stuinf)<<"��"<<endl;
                        cout<<"������������������������������"<<endl;
                        cout<<"��¼��˳��,ÿλѧ���ɼ����£�"<<endl;
                        AverageStudentScore(&stuinf);
                    }
                    break;
                case 8://8.��ѯѧ������
                    cout<<"ѧ����ƽ���ɼ��������£�"<<endl;
                    bubbleSort1(nameScore,&stuinf);
                    break;
                case 9://9.��ѯѧ������
                    cout<<"ѧ����ƽ���ɼ��������£�"<<endl;
                    bubbleSort2(nameScore,&stuinf);
                    break;
                case 10://10.ѧ����Ϣ�浵
                    test(&stuinf);
                    cout<<"�ļ���ȡ�ɹ�"<<endl;
                    break;
                case 0://0.�˳�����ϵͳ
                    cout<<"��ӭ�´�ʹ�ã�"<<endl;
                    return 0;
                    break;
                }

            }
            break;
        }
        else
        {
            cout<<"�����������������(���ǲ��������������1314520��!)"<<endl;
        }

    }


    return 0;

}
//��װ����һ�β˵��ĺ���
void homePage()
{
    cout<<endl;
    cout<<endl;
    cout<<"             \t"<<"ʥ����ҹ�����ְҵ����ѧԺ"<<endl;
    cout<<"             \t"<<"    ѧ���ɼ�����ϵͳ     "<<endl;
    cout<<endl;
    cout<<"             \t"<<"       �汾�ţ�+��        "<<endl;
    cout<<endl;
    cout<<"                      *����������*"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"             \t"<<"        2020��6��         "<<endl;
    cout<<"             \t"<<"      www.hit.edu.cn      "<<endl;
    cout<<endl;
    cout<<endl;
}
//��װ���ö����˵��ĺ���
void mainPage()
{
    cout<<endl;
    cout<<endl;
    cout<<"        ****************��ӭ���뱾ϵͳ****************"<<endl;
    cout<<"             **********************************     "<<endl;
    cout<<"        \t"<<"                         "<<endl;
    cout<<"        \t"<<"     ��ѧ���ɼ�����ϵͳ��    "<<endl;
    cout<<endl;
    cout<<"                 *      1.¼��ѧ���ɼ�       * "<<endl;
    cout<<"                 *      2.��ʾѧ���ɼ�       * "<<endl;
    cout<<"                 *      3.ɾ��ѧ���ɼ�       * "<<endl;
    cout<<"                 *      4.��ѯѧ���ɼ�       * "<<endl;
    cout<<"                 *      5.�޸�ѧ���ɼ�       * "<<endl;
    cout<<"                 *      6.���ѧ���ɼ�       * "<<endl;
    cout<<"                 *      7.��ѯƽ���ɼ�       * "<<endl;
    cout<<"                 *      8.��ѯѧ������       * "<<endl;
    cout<<"                 *      9.��ѯѧ������       * "<<endl;
    cout<<"                 *     10.ѧ���ɼ��浵       * "<<endl;
    cout<<"                 *      0.�˳�����ϵͳ       * "<<endl;
    cout<<"        \t"<<"                         "<<endl;
    cout<<"             **********************************     "<<endl;
    cout<<"        ********************************************"<<endl;
}
//1.¼��ѧ���ɼ�
void addStudent(studentsInformation * stuinf)
{
    //�ж�ѧ����Ϣ�Ƿ��Ѿ�����������˾Ͳ������
    if (stuinf->s_Num==MAX)
    {
        cout<<"��ϵͳѧ�������������޷���ӣ�"<<endl;
        return;
    }
    else
    {
        //���ÿλѧ���ĳɼ�

        //����
        string name;
        cout<<"������ѧ��������";
        cin>>name;
        stuinf->studentArray[stuinf->s_Num].s_Name = name;
        //�Ա�
        cout<<"������ѧ���Ա�(1��,2Ů): ";
        int sex=0;
        while(true)
        {
            //�������1��2�˳�ѭ�����������������������
            cin>>sex;
            if (sex==1||sex==2)
            {
                stuinf->studentArray[stuinf->s_Num].s_Sex = sex;
                break;
            }
            cout<<"������������������"<<endl;
        }
        //ѧ��
        cout<<"������ѧ����ѧ��: ";
        string student_nmuber;
        cin>>student_nmuber;
        stuinf->studentArray[stuinf->s_Num].s_StuNum = student_nmuber;
        //ѧԺ
        cout<<"������ѧ������ѧԺ: ";
        string school;
        cin>>school;
        stuinf->studentArray[stuinf->s_Num].s_Sch = school;
        //�绰
        cout<<"������ѧ����ϵ�绰��";
        string phone;
        cin >> phone;

        stuinf->studentArray[stuinf->s_Num].s_Phone = phone;

        //�����ɼ�
        cout<<"�������ѧ�������ɼ�: ";
        float math;
        cin>>math;
        stuinf->studentArray[stuinf->s_Num].s_Math = math;
        //Ӣ��ɼ�
        cout<<"�������ѧ��Ӣ��ɼ�: ";
        float english;
        cin>>english;
        stuinf->studentArray[stuinf->s_Num].s_Eng = english;
        //����ɼ�
        cout<<"�������ѧ������ɼ�: ";
        float physics;
        cin>>physics;
        stuinf->studentArray[stuinf->s_Num].s_Phy = physics;
        //����ѧ������
        stuinf->s_Num++;
        cout<<"�ɼ�¼��ɹ�"<<endl;
        system("pause");
        system("cls");
    }
}
//2.��ʾ����ѧ����Ϣ
void showStudent(studentsInformation * stuinf)
{
    //�ж�ϵͳ��ѧ�������Ƿ�Ϊ0�����Ϊ0����¼Ϊ�գ������Ϊ0����ʾ��¼��ѧ����Ϣ
    if (stuinf->s_Num == 0)
    {
        cout <<"��ǰ��¼Ϊ��"<<endl;
    }
    else
    {
        for (int i = 0; i<stuinf->s_Num; i++)
        {
            cout<<"������ "<<stuinf->studentArray[i].s_Name<<"  ";
            cout<<"�Ա� "<<(stuinf->studentArray[i].s_Sex == 1?"��":"Ů")<<"  ";//if-else�ṹ��д���������1���Ϊ�У�����������ΪŮ
            cout<<"ѧ�ţ� "<<stuinf->studentArray[i].s_StuNum<<"  ";
            cout<<"ѧԺ�� "<<stuinf->studentArray[i].s_Sch<<"  ";
            cout<<"�绰�� "<<stuinf->studentArray[i].s_Phone<<"\t";
            cout<<"������ "<<stuinf->studentArray[i].s_Math<<"��"<<"  ";
            cout<<"Ӣ� "<<stuinf->studentArray[i].s_Eng<<"��"<<"  ";
            cout<<"��� "<<stuinf->studentArray[i].s_Phy<<"��"<<"  ";
            cout<<"�ܷ֣� "<<stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy<<"��"<<"  ";
            cout<<"ƽ���֣� "<<(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0<<"��"<<endl;
        }
    }
    system ("pause");//�����������
    system ("cls");//����
}
//�������������ѧ���Ƿ������ϵͳ�У�������ڣ�����ѧ�����������еľ���λ�ã������ڷ���-1
int isExist(studentsInformation * stuinf, string name)//����1��ѧ����Ϣ��    ����2���ж����ѧ���Ƿ���ѧ����Ϣ����
{
    for(int i =0; i<stuinf->s_Num; i++)
    {
        if (stuinf->studentArray[i].s_Name == name)//�ҵ���ʦ���������
        {
            return i;//�ҵ��󷵻�ѧ�����������б��
        }
    }
    return -1;//����������δ�ҵ���ѧ��������-1
}
//3.ɾ��ĳ��ѧ����Ϣ
void deleteStudent(studentsInformation * stuinf)
{
    cout<<"��������Ҫɾ������Ϣ��ѧ��������"<<endl;
    string name;
    cin>>name;
    //result==-1δ�鵽      result!=-1�鵽
    int result = isExist(stuinf, name);
    if(result !=-1)
    {
        //���ҵ���ѧ��������ɾ��������ֻ��Ҫ��Ҫ��ɾ����ѧ�����ѧ��������ǰ�ƶ���ֵ���ǣ�����ѧ����Ϣ���м�¼��ѧ������-1���ɡ�
        for(int i =result; i<stuinf->s_Num; i++)
        {
            //����ǰ��
            stuinf->studentArray[i]=stuinf->studentArray[i+1];
        }
        stuinf->s_Num--;//����ѧ����Ϣ������Ա��
        cout<<"ɾ���ɹ�"<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
//4.����ѧ���ɼ�
void findStudent(studentsInformation * stuinf)
{
    cout<<"��������Ҫ���ҵ�ѧ������"<<endl;
    string name;
    cin>> name;
    //�жϸ�ѧ���Ƿ����ѧ����Ϣ����
    int result= isExist(stuinf,name);

    if(result!=-1)//�ҵ�ѧ��
    {
        cout<<"������"<<stuinf->studentArray[result].s_Name<<"\t";
        cout<<"�Ա�"<<stuinf->studentArray[result].s_Sex<<"\t";
        cout<<"ѧ�ţ�"<<stuinf->studentArray[result].s_StuNum<<"\t";
        cout<<"ѧԺ��"<<stuinf->studentArray[result].s_Sch<<"\t";
        cout<<"�绰��"<<stuinf->studentArray[result].s_Phone<<"\t";
        cout<<"������"<<stuinf->studentArray[result].s_Math<<"��"<<"\t";
        cout<<"Ӣ�"<<stuinf->studentArray[result].s_Eng<<"��"<<"\t";
        cout<<"���"<<stuinf->studentArray[result].s_Phy<<"��"<<endl;
    }
    else //δ�ҵ���ѧ��
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");//�����������
    system("cls");//����
}
//5.�޸�ѧ����Ϣ
void modifyStudent(studentsInformation * stuinf)
{
    cout<<"��������Ҫ�޸ĵ�ѧ��������";
    string name;
    cin>>name;

    int result = isExist(stuinf,name);
    if(result!=-1)//�ҵ�ѧ��
    {
        //�޸�����
        string name;
        cout<<"����������������";
        cin>>name;
        stuinf->studentArray[result].s_Name = name;
        //�޸��Ա�
        cout<<"�����������Ա�"<<endl;
        cout<<"1-----------�У�"<<endl;
        cout<<"2-----------Ů��"<<endl;
        int sex=0;
        while (true)
        {
            cin>>sex;
            if(sex == 1|| sex == 2)
            {
                stuinf->studentArray[result].s_Sex = sex;
                break;//������ȷ �˳�ѭ������
            }
            cout<<"������������������"<<endl;
        }
        //�޸�ѧ��
        cout<<"����������ѧ�ţ�";
        string student_number;
        cin>>student_number;
        stuinf->studentArray[result].s_Sch = student_number;
        //�޸�ѧԺ
        cout<<"����������ѧԺ��";
        string school;
        cin>>school;
        stuinf->studentArray[result].s_Sch = school;
        //�޸ĵ绰
        cout<<"������������ϵ�绰��";
        string phone;
        cin >> phone;
        stuinf->studentArray[result].s_Phone = phone;
        //�޸ĸ����ɼ�
        cout<<"��������������ɼ���";
        double math;
        cin>>math;
        stuinf->studentArray[result].s_Math=math;
        //�޸�Ӣ��ɼ�
        cout<<"����������Ӣ��ɼ���";
        double english;
        cin>>english;
        stuinf->studentArray[result].s_Eng=english;
        //�޸Ĵ���ɼ�
        cout<<"�������������ɼ���";
        double physics;
        cin>>physics;
        stuinf->studentArray[result].s_Phy=physics;
        cout<<"�޸ĳɹ���"<<endl;
    }
    else//δ�ҵ���ѧ��
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
//6.���ѧ����Ϣ
void cleanStudent(studentsInformation * stuinf)//ֻ��Ҫ�����߼��ϵ���գ����ǰ�ѧ����Ϣ���е�ѧ��������Ϊ0���Ӷ�ʹ�������޷����ʵ�ѧ����Ϣ����ʽ�Ͼ������
{
    cout<<"���Ƿ�Ҫ�������ѧ����Ϣ��"<<endl;
    cout<<"1---------------------��"<<endl;
    cout<<"2---------------------��"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {
        stuinf->s_Num = 0;
        cout<<"ѧ����Ϣ�����"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        system("pause");
        system("cls");
    }
}
//7.1�����ɼ�ƽ����
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
//7.2Ӣ��ƽ����
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
//7.3����ƽ����
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
//7.4ÿλͬѧ��ƽ���ɼ�
void AverageStudentScore(studentsInformation * stuinf)
{
    //�ж�ϵͳ��ѧ�������Ƿ�Ϊ0�����Ϊ0����¼Ϊ�գ������Ϊ0����ʾ��¼��ѧ����Ϣ
    if (stuinf->s_Num == 0)
    {
        cout <<"��ǰ��¼Ϊ��"<<endl;
    }
    else
    {

        struct StudentScore nameScore[stuinf->s_Num];
        for (int i = 0; i<stuinf->s_Num; i++)
        {
            nameScore[i].name=stuinf->studentArray[i].s_Name;
            nameScore[i].averagescore=(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0;
            cout<<"������"<<nameScore[i].name<<"\t"
                <<"�ܷ֣�"<<3*nameScore[i].averagescore<<"\t"
                <<"ƽ���֣�"<<nameScore[i].averagescore<<endl;
        }
    }
    system ("pause");//�����������
    system ("cls");//����
}
//8.��ѯѧ�Գɼ�����
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
        cout<<"��"<<i+1<<"��*"<<"������"<<nameScore[i].name<<"\t"
            <<"ƽ���֣�"<<nameScore[i].averagescore<<endl;
    }
    system("pause");
    system("cls");
}
//9.��ѯѧ���ɼ�����
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
        cout<<"������"<<i+1<<"��*"<<"������"<<nameScore[i].name<<"\t"
            <<"ƽ���֣�"<<nameScore[i].averagescore<<endl;
    }
    system("pause");
    system("cls");
}
void test(studentsInformation * stuinf)
{
    ofstream ofs;//����������
    ofs.open("��������ҵ��ѧ2019��ѧ����ĩ�ɼ�.txt",ios::out);//ָ���򿪷�ʽ
    for (int i = 0; i<stuinf->s_Num; i++)
    {
        ofs<<"������ "<<stuinf->studentArray[i].s_Name<<"  ";
        ofs<<"�Ա� "<<(stuinf->studentArray[i].s_Sex == 1?"��":"Ů")<<"  ";//if-else�ṹ��д���������1���Ϊ�У�����������ΪŮ
        ofs<<"ѧ�ţ� "<<stuinf->studentArray[i].s_StuNum<<"  ";
        ofs<<"ѧԺ�� "<<stuinf->studentArray[i].s_Sch<<"  ";
        ofs<<"�绰�� "<<stuinf->studentArray[i].s_Phone<<"\t";
        ofs<<"������ "<<stuinf->studentArray[i].s_Math<<"��"<<"  ";
        ofs<<"Ӣ� "<<stuinf->studentArray[i].s_Eng<<"��"<<"  ";
        ofs<<"��� "<<stuinf->studentArray[i].s_Phy<<"��"<<"  ";
        ofs<<"�ܷ֣� "<<stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy<<"��"<<"  ";
        ofs<<"ƽ���֣� "<<(stuinf->studentArray[i].s_Math+stuinf->studentArray[i].s_Eng+stuinf->studentArray[i].s_Phy)/3.0<<"��"<<endl;
    }
    ofs.close();//�ر��ļ�

}
