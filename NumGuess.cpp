//文件名：数字游戏.cpp
//精典的猜数字游戏

#include <cstdlib>
#include <ctime>
#include <iostream> 
using namespace std;

int num1, num2, num3, random[3], i = 0, j, temp, counter1, counter2, playTime = 0, winTime = 0;
bool flag;
char choice;


int main()
{	cout << "需要玩游戏吗（Y/N）？";
	cin >> choice;
	while (choice == 'Y'){										//询问玩家是否要玩，知道玩家输入N为止
		playTime += 1;											//游戏次数 
		
		srand(time(NULL));                          			//生成一个三个数的数组，三个数不相同 
		random[0] = rand()%10;
		while (i<3) {											 
			flag = true;
			temp = rand()%10;
			for (j=0; j<i; ++j){
				if (random[j] == temp){
					flag = false; break;
				}
			}
			if (flag){random[i] = temp,++i;
			}
		}
	
		//for (i=0;i<3;++i){           							//测试时使用    			
		//	cout << random[i];
		//}
	
		for (i=0; i<7; ++i){									//判断数字和位置是否正确 
			cout << "请输入你猜测的数字:" << '\n';
			cin >> num1 >> num2 >> num3;
			counter1 = 0;										//数字正确且位置正确的个数 
			counter2 = 0;										//数字正确但位置不正确的个数 
			if (random[0] == num1){
				counter1+=1;}
			if (random[0] == num2||random[0] == num3){
				counter2+=1;}
		
			if (random[1] == num2){
				counter1+=1;}
			if (random[1] == num1||random[1] == num3){
				counter2+=1;}
		
			if (random[2] == num3){
				counter1+=1;}
			if (random[2] == num1||random[2] == num2){
				counter2+=1;}
		
			if (counter1 == 3){										//当A为3时已经猜对，跳出循环 
				winTime += 1;										//胜利次数 
				cout << "恭喜，你猜对了" << endl;break;
			}else{
				cout << counter1 << 'A'	<< counter2 << 'B' << endl; 
			}
		
			if (i == 6){											//仍没有猜对的情况 
				cout << "很遗憾，你没有在规定次数内猜对。答案是 ";
				for (i=0;i<3;++i){
		  		cout << random[i];
				}
				cout << endl;break;
			}
		}
		cout << "需要玩游戏吗（Y/N）？";
		cin >> choice;		
	}
	cout << "你一共玩了" << playTime << "局，赢了" << winTime << "局，输了" << (playTime - winTime) << "局" << endl;		
	return 0;			
} 
