#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i < 5; i++)
	{
		cout << "i=" << i << endl;
		if (i==2)
		{
			break;//整个for函数直接结束
		}
	}



}