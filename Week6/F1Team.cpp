#include "F1Team.h"
#include <fstream>
#include <iostream>
void F1Team::readBinaryFile()
{
	std::ifstream in_file;
	in_file.open("team.bin", std::ios::in | std::ios::binary);
	if (!in_file.is_open())
	{
		std::cerr << "File was not found";
		return;
	}

	in_file.read((char*)this, sizeof(*this));
	in_file.close();
}

void F1Team::writeBinaryFile()
{
	std::ofstream out_file;
	out_file.open("team.bin", std::ios::out | std::ios::binary);
	if (!out_file.is_open())
	{
		std::cerr << "File was not found";
		return;
	}

	out_file.write((char*)this, sizeof(*this));
	out_file.close();
}
