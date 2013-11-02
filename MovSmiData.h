/*
 * MovSmiData.h
 *
 *  Created on: 2013. 9. 9.
 *      Author: hy711972
 */

#ifndef MOVSMIDATA_H_
#define MOVSMIDATA_H_

#include <string>
#include <vector>

class MovSmiData
{
public:
	MovSmiData();
	virtual ~MovSmiData();

	int getSizeOfVectorMov();
	int getSizeOfVectorSmi();
	void delMovItem(long index);
	void delSmiItem(long index);
	void loadFiles(const char* path);
	void listFiles();
	std::string getExtension(std::string str);
	std::string getFileName(std::string str);
	int renameFiles(std::string oldname, std::string newname);
	void renameSmiFiles();
	void renameMovFiles();

	static bool sortOp(std::string i, std::string j)
	{
		return (i < j);
	}

	static bool sortOpReverse(std::string i, std::string j)
	{
		return (i > j);
	}

	void sortFiles(bool asc = true);
	void clearVector();

	std::vector<std::string> mvMovFiles;
	std::vector<std::string> mvSmiFiles;
};

#endif /* MOVSMIDATA_H_ */
