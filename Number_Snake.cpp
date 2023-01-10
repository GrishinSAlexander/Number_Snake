#include <iostream>
#include <array>

#define HEIGHT 5
#define LENGTH 5

void fillSnake(std::array <std::array<int, LENGTH>, HEIGHT>& arr)
{
	int height = HEIGHT;
	int length = LENGTH;
	int left = 0;
	int up = 0;

	int colPoint = 0;
	int rowPoint = 0;

	int num = 1;

	while (height >= up && length >= left)
	{
	++up;

	for (rowPoint; rowPoint < length; ++rowPoint)
		arr[colPoint][rowPoint] = num++;
	--rowPoint;

	--length;

	for (++colPoint; colPoint < height; ++colPoint)
		arr[colPoint][rowPoint] = num++;
	--colPoint;

	--height;

	for (--rowPoint; rowPoint > left; --rowPoint)
		arr[colPoint][rowPoint] = num++;

	++left;

	for (colPoint; colPoint > up; --colPoint)
		arr[colPoint][rowPoint] = num++;

	}
}

int main()
{
	std::array <std::array<int, LENGTH>, HEIGHT> array;

	fillSnake(array);

	for (auto& col : array)
	{
		for (auto& element : col)
		{
			std::cout << element << "\t";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}