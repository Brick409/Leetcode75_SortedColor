// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  //包括min和max函数

using namespace std;
/* 
75题目：给定一个有n个元素的数组，数组中元素的取值只有0，1，2三种可能，
		为这个数组排序，使排序后相同字母挨着，并有序。
	例如：
		Input: [2,0,2,1,1,0]
		Output: [0,0,1,1,2,2]
 */
/* 方法一：计数排序：分别统计0，1，2的元素个数 */
class Solution75_1
{
public:
	//时间复杂度O（n）
	//空间复杂度：O（k），k为元素的取值范围
	void sortColors(vector<int>&nums)
	{
		int count[3] = { 0 };//存放0，1，2三个元素的频率
		for (int i = 0; i < nums.size(); i++)
		{
			assert(nums[i] >= 0 && nums[i] < 2);
			count[nums[i]]++;
		}

		int index = 0;
		for (int i=0;i<count[0];i++)
		{
			nums[index++] = 0;
		}
		for (int i = 0;i < count[1];i++)
		{
			nums[index++] = 1;
		}
		for (int i = 0;i < count[2];i++)
		{
			nums[index++] = 2;
		}
	}
private:

};

/* 方法二：三路快速排序法 */
class Solution75_2
{
public:
	//时间复杂度O（n）
	//空间复杂度：O（1）
	//只遍历了一遍
	void sortColors(vector<int>&nums)
	{
		int zero = -1;        //nums[0...zero]==0
		int two = nums.size(); //nums[two...n-1]==2

		for (int i=0; i < two;)
		{
			if (nums[i]==1)
			{
				i++;
			}
			else if (nums[i]==2)
			{
				two--;
				swap(nums[i], nums[two]);
			}
			else //nums[i]==0
			{
				assert(nums[i] == 0);
				zero++;
				swap(nums[zero], nums[i]);
				i++;
			}
		}
	}
private:

};

int main()
{
	int nums1[] = { 2,0,2,1,1,0 };

	vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));

	Solution75_2().sortColors(vec1);

	for (int i=0;i<vec1.size();i++)
	{
		cout << vec1[i] << " ";
	}

	cout << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
