// modularitycpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>

#include "Header1.h"
void testNumberToPair(int pairNumber,
	TelCoColorCoder::MajorColor expectedMajor,
	TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair =
		TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << std::endl;
	assert(colorPair.getMajor() == expectedMajor);
	assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
	TelCoColorCoder::MajorColor major,
	TelCoColorCoder::MinorColor minor,
	int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}

void ToString()
{
	int i, j, count = 0;
	for (i = 0; i < TelCoColorCoder::numberOfMajorColors; i++)
	{
		for (j = 0; j < TelCoColorCoder::numberOfMinorColors; j++)
		{
			std::cout << "pair number" << ++count << endl;
			std::cout << "color names" << TelCoColorCoder::MajorColorNames[i] << TelCoColorCoder::MinorColorNames[i] << endl;

		}
	}
}
int main() {
	testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
	testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

	testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
	testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
	ToString();
	return 0;
}

