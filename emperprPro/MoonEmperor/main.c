#include <stdio.h>
#include <stdlib.h>
#include <string.h> //֧���ַ�������

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.Lib")



#define MAX 6   //����MAX��ʾϵͳҪ��������������
int main()
{
    //ʹ���ַ������ʾ�ַ���
    int i, j, temp;            //ѭ����������ʱ���ͱ���
    int count = 5;          //��ǰδ�����乬����������
    int choice;             //�ʵ۵�ѡ��1-4֮��
    int searchIndex = -1;   //������Ų��ҵ�Ԫ�ص��±�
    char emperorName[50];   //�ʵ۵�����
    char tempName[20];      //���������ʱ�ַ������ַ�����
    char names[MAX][20] = {"����", "����", "��֪����", "��ʩ", "���¸�"};
    //�����ļ�������
    char levelNames[][10] = {"����", "����", "����", "�ʹ���", "�ʺ�"};
    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int levels[MAX] = {0, 1, 2, 3, 4, -9999};
    //loves�����е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ�����ÿ���˵ĺøжȶ�Ϊ100
    int loves[MAX] = {100, 100, 100, 100, 100, -9999};
    PlaySound(TEXT("sounds\\��������.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    printf("\n***********************************************\n");
    printf("���Դ��룺�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n", "����");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("***********************************************\n");


    printf("�����뵱ǰ�ǻ��Ļʵ����ţ�");
    scanf("%s", emperorName);   //¼���ַ���ʱ������Ҫ&����
    printf("�ʵۡ�%s������,�������࣬�����˳���\n", emperorName);
    printf("1���ʵ���ּѡ����\t\t�����ӹ��ܣ�\n");
    printf("2�����Ƴ��ң�\t\t���޸�״̬���ܣ�\n");
    printf("3�������乬��\t\t��ɾ�����ܣ�\n");
    printf("4�������ټ�����ȥС������������¡�\n");
    printf("������ѡ��");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1://�ʵ���ּѡ����\t\t�����ӹ��ܣ�
        PlaySound(TEXT("sounds\\ѡ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        //1.����ǰ��Ҫ�ж�������û�пռ�
        //2.��������Ԫ�أ�names��loves��levels��
        if(count < MAX)//�����ǰ����������С��ϵͳ���ֵ
        {
            //ִ�����Ӳ���
            printf("��������������䣺");
            scanf("%s", tempName);
            for(i = 0; i < count; i++)
            {
                    if(strcmp(tempName, names[i]) ==0)  //������ͬ
                    {
                            printf("�����ˣ���������");
                            break;
                    }
                    else
                    {
                            strcpy(names[count],tempName);
                            //����count��Ԫ�ص�״̬��ʼ��
                            levels[count] = 0;  //�����ʼΪ0
                            loves[count] = 100; //�øжȳ�ʼΪ100
                            count++;                //������Ԫ�غ����Ӽ�����
                            break;
                    }
            }
        }
        else
        {
            printf("���£�Ҫע�����尡�����Ѿ�����Ϊ����\n����ʧ�ܣ�\n");
        }

        break;
    case 2://���Ƴ��ң�\t\t���޸�״̬���ܣ�
        //1.�ҵ�Ҫ�������ӵ��±�
        //2.�޸�������ӵ�״̬ �øж�+10�� ������1���������߼��Ͳ�������
        //3.�޸��������ӵ�״̬ ������Ľ���ʺޣ��������Ӻøж�-10
        //��Ҫ�����bug��δ֧�����������ڵ�������������Բ����
        printf("���£�������Ҫ���췭����������䣺");
        scanf("%s", tempName);
        //�ַ����Ĳ���strcmp����Ҫ����<string.h>
        //strcmp(tempName, "abc")   0-�����ַ�����ȣ�1-ǰһ�����ں�һ����-1-ǰһ��С�ں�һ��
        for(i = 0; i < count; i++)
        {
            if(strcmp(tempName, names[i]) ==0)//�������������պõ��������е�ĳ������
            {
                loves[i] += 10;
                //����Ҫע�⣬���ܳ���5����0-4֮�䣩
                levels[i] =  levels[i] >= 4 ? 4 : levels[i] + 1;
            }
            else
            {
                loves[i] -= 10;
            }
        }
        break;
    case 3:
        printf("3�������乬��\t\t��ɾ�����ܣ�\n");
        //1.����
        //2.����һ������ǰ��һ��Ԫ��
        //3.����--
        //4.�޸��������ӵ�״̬���øж�-20
        printf("���£�������Ҫ�����乬��������");
        scanf("%s", tempName);
        //ѭ������
        for(i = 0; i < count; i++)
        {
            if(strcmp(tempName, names[i]) == 0)//�Ƚ��ַ����Ƿ����
            {
                //��¼��Ҫ���ҵ��±�
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)//���searchIndex��ֵΪ��ֵ-1����ʾû���ҵ�
        {
            printf("�龪һ�������˴����乬���óԳԸúȺȣ�\n");
        }
        else
        {
            for(i = searchIndex; i < count - 1; i++)
            {
                //names[i] = names[i + 1]; ��Ϊ���ַ����飬C�����в�֧�������ֱ�Ӹ�ֵ
                //������Ҫʹ��strcpy����ʵ������ĸ�ֵ�������γ̻���ϸ���⣬����ֻ��Ҫ�˽���ʲô���ܼ���
                strcpy(names[i], names[i + 1]);
                loves[i] = loves[i + 1];
                levels[i] = levels[i + 1];
            }
            count--;
        }
        break;
    case 4://�����ټ�����ȥС�������������
        //1.����
        //2.���Ӻøжȼ���
        //3.����ʹ���������ʫ�裬ʹ��������ֵķ�ʽ�����ֻʵ۵��Ĳ�

        break;
    default:
        printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ�\n");
    }
    //����ӡ��������״̬ǰ���Լ����������ʹ��ð������
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(levels[j] < levels[j + 1])
            {
                //��Ҫ��������������ͺøж�
                temp = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = temp;
                temp = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = temp;
                //ע���ַ����Ľ���
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }


    printf("\n***********************************************\n");
    printf("���Դ��룺�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n", "����");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("***********************************************\n");
    return 0;
}