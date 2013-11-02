/*
 * MovSmiData.cpp
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <dirent.h>
#include <algorithm>

#include "MovSmiData.h"

MovSmiData::MovSmiData()
{
	// TODO Auto-generated constructor stub

}

MovSmiData::~MovSmiData()
{
	// TODO Auto-generated destructor stub
	mvMovFiles.clear();
	mvSmiFiles.clear();
}

void MovSmiData::loadFiles(const char* path)
{
	DIR* dirFile = opendir(path);
	if (dirFile)
	{
		struct dirent* hFile;
		while ((hFile = readdir(dirFile)) != NULL)
		{
			if (!strcmp(hFile->d_name, "."))
				continue;
			if (!strcmp(hFile->d_name, ".."))
				continue;

			if (hFile->d_name[0] == '.')
				continue;

			if (strstr(hFile->d_name, ".mp4") || strstr(hFile->d_name, ".avi") || strstr(hFile->d_name, ".mkv"))
			{
				std::string str(hFile->d_name);
				mvMovFiles.push_back(str);
			}
			else if (strstr(hFile->d_name, ".smi")
					|| strstr(hFile->d_name, ".smil")
					|| strstr(hFile->d_name, ".srt"))
			{
				std::string str2(hFile->d_name);
				mvSmiFiles.push_back(str2);
			}
		}
	}
	closedir(dirFile);

	//std::cout << "We found " << mvMovFiles.size() << " files.\n" << std::endl;
}

void MovSmiData::listFiles()
{
	int size1, size2;
	size1 = mvMovFiles.size();
	size2 = mvSmiFiles.size();
	if (size1 != size2)
	{
		std::cout << "error : Count does not match " << "size1 : " << size1
				<< " size2 : " << size2 << std::endl;
	}
	else
	{
		for (int i = 0; i < size1; i++)
			std::cout << mvMovFiles[i] << '\n' << mvSmiFiles[i] << std::endl;
	}
}

std::string MovSmiData::getExtension(std::string str)
{
	unsigned found = str.find_last_of(".");
	return str.substr(found);
}

std::string MovSmiData::getFileName(std::string str)
{
	unsigned found = str.find_last_of(".");
	return str.substr(0, found);
}

int MovSmiData::renameFiles(std::string oldname, std::string newname)
{
	int result = rename(oldname.c_str(), newname.c_str());

	//std::cout << oldname << " " << newname;

	if (result != 0)
		perror("Error renaming file");

	return 0;
}

void MovSmiData::renameSmiFiles()
{
	int size = mvMovFiles.size();

	for (int i = 0; i < size; i++)
		renameFiles(mvSmiFiles[i],
				getFileName(mvMovFiles[i]) + getExtension(mvSmiFiles[i]));

	//std::cout << "\nRename Operation has been done." << std::endl;
}

void MovSmiData::renameMovFiles()
{
	int size = mvSmiFiles.size();

	for(int i=0; i< size; i++)
		renameFiles(mvMovFiles[i], getFileName(mvSmiFiles[i]) + getExtension(mvMovFiles[i]));

	//std::cout << "\nRename Operation has been done." << std::endl;
}


int MovSmiData::getSizeOfVectorMov()
{
	return mvMovFiles.size();
}

int MovSmiData::getSizeOfVectorSmi()
{
	return mvSmiFiles.size();
}

void MovSmiData::sortFiles(bool asc)
{
	if (asc == true)
	{
		std::sort(mvMovFiles.begin(), mvMovFiles.end(), MovSmiData::sortOp);
		std::sort(mvSmiFiles.begin(), mvSmiFiles.end(), MovSmiData::sortOp);
	}
	else
	{
		std::sort(mvMovFiles.begin(), mvMovFiles.end(),
				MovSmiData::sortOpReverse);
		std::sort(mvSmiFiles.begin(), mvSmiFiles.end(),
				MovSmiData::sortOpReverse);
	}

}

void MovSmiData::clearVector()
{
	mvMovFiles.clear();
	mvSmiFiles.clear();
}

void MovSmiData::delMovItem(long index)
{
	mvMovFiles.erase(mvMovFiles.begin()+index);
}

void MovSmiData::delSmiItem(long index)
{
	mvSmiFiles.erase(mvSmiFiles.begin()+index);
}

