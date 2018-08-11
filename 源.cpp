#include <iostream>
using namespace std;
struct mdata
{
	int time;
	int level;
	int trgtNum;
	int *targets;
};
//void prt(mdata* data,int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "(" << data[i].time << "," << data[i].level << ")" << " ";
//	}
//	cout << endl;
//}
//void prtt(mdata* data, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "(" << data[i].time << "," << data[i].level << ","<<data[i].trgtNum<<")" << " ";
//	}
//	cout << endl;
//}
int main()
{
	int mNum; int tNum;
	cin >> mNum >> tNum;

	int mSum = 0; int tSum = 0;
	bool *done = new bool[tNum];
	for (int i = 0; i < tNum; i++)
	{
		done[i] = false;
	}
	mdata * machines = new mdata[mNum];
	for (int i = 0; i < mNum; i++)
	{
		cin >> machines[i].time;
		cin >> machines[i].level;
	}
	mdata *tasks = new mdata[tNum];
	for (int i = 0; i < tNum; i++)
	{
		cin >> tasks[i].time;
		cin >> tasks[i].level;
	}

	//按照钱的数目进行排序(降序)
	for (int i = 0; i < tNum - 1; i++)
	{
		for (int j = 0; j < tNum - i - 1; j++)
		{
			if ((500 * tasks[j].time + 2 * tasks[j].level) < (500 * tasks[j + 1].time + 2 * tasks[j + 1].level))
			{
				mdata tem = tasks[j];
				tasks[j] = tasks[j + 1];
				tasks[j + 1] = tem;
			}
		}
	}
	//prt(tasks, tNum);


	//确认每一台机器的能力大小，以trgtNum确定
	for (int i = 0; i < mNum; i++)
	{
		machines[i].trgtNum = 0;
		machines[i].targets = new int[mNum];
		for (int j = 0; j < tNum; j++)
		{
			if (tasks[j].level <= machines[i].level&&tasks[j].time <= machines[i].time)
			{
				machines[i].targets[machines[i].trgtNum] = j;
				machines[i].trgtNum++;
			}
		}
	}
	//prtt(machines, mNum);

	//按机器能力进行排序
	for (int k = 0; k < mNum; k++)
	{
		for (int i = k; i < mNum - 1; i++)
			for (int j = k; j < mNum - i - 1; j++)
			{
				if (machines[j].trgtNum >= machines[j + 1].trgtNum)
				{
					mdata tem = machines[j];
					machines[j] = machines[j + 1];
					machines[j + 1] = tem;
				}
			}
		//prtt(machines, mNum);
		for (int j = 0; j < tNum; j++)
		{
			if (tasks[j].level <= machines[k].level&&tasks[j].time <= machines[k].time && !done[j])
			{
				mSum += 500 * tasks[j].time + 2 * tasks[j].level;
				tSum++;
				done[j] = true;
				for (int i = k + 1; i < mNum; i++)
				{
					for (int k = 0; k < machines[i].trgtNum; k++)
					{
						if (machines[i].targets[k] == j)
						{
							for (int m = k; m < machines[i].trgtNum; m++)
							{
								machines[i].targets[k] = machines[i].targets[k + 1];
							}
							machines[i].trgtNum--;
							break;
						}
					}
				}
				break;
			}
		}
	}
	cout << tSum << " " << mSum << endl;

	delete[]done;
	delete[]machines;
	delete[]tasks;

	return 0;
}


