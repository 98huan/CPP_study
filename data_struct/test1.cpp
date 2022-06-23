#include<iostream>
#include<vector>
using namespace std;
 
void deal(vector<char> task, int num1, int num2)
{
	//任务所在芯片计数
	int count_A = 0;
	int count_B = 0;
	//位置
	int id_A = 0;   //A资源ID位置
	int id_B = 0;   //B资源ID位置
    // 总芯片计数
    int count = 0;

	for (char c : task)
	{
		if (c == 'A'){
            if (id_A % 4 == 0)
            {
                id_A = 0;
                count_A = ++count;
            }
            id_A++;
        }
        else
        {
            count_B = ++count;
            id_B = 1;
        }
	}

	if (count > num1)
		cout << "0" << endl << "0" << endl;
	else
	{
		if (task[num2 - 1] == 'A')
            cout << count_A << endl << id_A << endl;
        else
            cout << count_B << endl << id_B << endl;
	}
	
}

int main()
{
    int num1;//芯片数量
    int num2;//任务数量
    char tasktype;//任务种类

	while (cin >> num1 >> num2)
	{
		vector<char> task;
		for (int i = 0; i < num2; i++)
		{
			cin >> tasktype;
			task.push_back(tasktype);
		}
		deal(task, num1, num2);
	}
	return 0;
}