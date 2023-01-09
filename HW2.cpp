using namespace std;
#include <iostream>
#include<vector>
//13 и 15 задания
class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)//13
	{
		vector<int> nums(m + n, 0);
		int i = 0;
		int j = 0;
		int k = 0;
		if (n == 0)
			return;
		while (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
				nums[k++] = nums1[i++];
			else
				nums[k++] = nums2[j++];
		}
		while (i < m)
			nums[k++] = nums1[i++];
		while (j < n)
			nums[k++] = nums2[j++];
		nums1 = nums;
	}
	int maxProfit(vector<int>& prices)//15
	{
		int lsf = INT_MAX;
		int op = 0;
		int pist = 0;

		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < lsf) {
				lsf = prices[i];
			}
			pist = prices[i] - lsf;
			if (op < pist) {
				op = pist;
			}
		}
		return op;
	}
};
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	//1 задание
	int a = 1;
	int b = 2;
	cout << "Before swap() a=" << a << ", b=" << b << endl;
	swap(&a, &b);
	cout << "After swap() a=" << a << ", b=" << b << endl;

	cout << "_______________________" << endl;
	//2 задание
	int n = 5;//дано число n
	int* arr = new int[n];
	cout << "Source array:" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << "\nUsed pointers:" << endl;
	int* pa = arr;
	cout << &arr[0] << endl;
	cout << pa << endl;

	int* pla = arr + n - 1;
	cout << &arr[n - 1] << endl;
	cout << pla << endl;

	//swap элементов
	int varToSwap = *pla;
	arr[n - 1] = *pa;
	arr[0] = varToSwap;

	cout << "\nResulted array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;

	cout << "_______________________" << endl;
	//3 задание
	double** p = 0;
	double x;
	double* firstP = new double;//создание структуры
	x = 2;
	firstP = &x;
	p = &firstP;
	cout << "\nNumber in square: " << **p << endl;//вывод
	cout << "_______________________" << endl;
	//4 задание 
	double* dArr = new double[12];
	cout << "Arr of 12 elements:";
	for (int i = 0; i < 12; i++)
	{
		dArr[i] = rand() % 10 + 0.5;
		cout << dArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = i + 1; j < 12; j++)
		{
			if (dArr[i] < dArr[j])//14 перестановок для 12 элементов
			{
				double temp = dArr[i];
				dArr[i] = dArr[j];
				dArr[j] = temp;
			}
		}
	}
	cout << "Desc Sorted array:";
	for (int i = 0; i < 12; i++)
	{
		cout << dArr[i] << " ";
	}
	cout << endl;
	delete[] dArr;
	cout << "_______________________" << endl;
	//10 задание
	int firstSize = 6;
	int secondSize = 8;
	double* firstArr = new double[firstSize];
	double* secondArr = new double[secondSize];

	cout << "First array :";
	for (int i = 0; i < firstSize; i++)
	{
		double minus = rand() % 6;
		firstArr[i] = rand() % 10 - minus / 3;
		cout << firstArr[i] << " ";
	}
	cout << endl;
	double firstMax = 0;
	int firstMaxI;
	for (int i = 1; i < firstSize; i++) {
		if (firstArr[i] > firstMax)
			firstMax = firstArr[i];
	}
	for (int i = 1; i < firstSize; i++) {
		if (firstArr[i] == firstMax) {
			firstMaxI = i;
			break;
		}

	}
	cout << "Max of 1st arr is " << firstMax << " with Index " << firstMaxI << endl;

	cout << "Second array :";
	for (int i = 0; i < secondSize; i++)
	{
		double minus = rand() % 6;
		secondArr[i] = rand() % 5 - minus / 4;
		cout << secondArr[i] << " ";
	}
	cout << endl;
	double secondMax = 0;
	int secondMaxI;
	for (int i = 1; i < secondSize; i++) {
		if (secondArr[i] > secondMax)
			secondMax = secondArr[i];
	}
	for (int i = 1; i < secondSize; i++) {
		if (secondArr[i] == secondMax) {
			secondMaxI = i;
			break;
		}

	}
	cout << "Max of 2nd arr is " << secondMax << " with Index " << secondMaxI << endl;
	for (int i = 0; i < firstSize; i++)
	{
		if (i == firstMaxI)
		{
			firstArr[i] = secondMax;
		}
	}
	for (int i = 0; i < secondSize; i++)
	{
		if (i == secondMaxI)
		{
			secondArr[i] = firstMax;
		}
	}
	cout << "First array after Max replacement:";
	for (int i = 0; i < firstSize; i++)
	{
		cout << firstArr[i] << " ";
	}
	cout << endl;
	cout << "Second array after Max replacement:";
	for (int i = 0; i < secondSize; i++)
	{
		cout << secondArr[i] << " ";
	}
	cout << endl;
	delete[] firstArr;
	delete[] secondArr;
}
