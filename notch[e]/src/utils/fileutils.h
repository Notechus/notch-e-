#pragma once
#ifndef FILEUTILS_H_INCLUDED
#define FILEUTILS_H_INCLUDED

#include <string>
#include <fstream>
#include <sstream>

namespace notche
{
	struct FileUtils
	{
		static std::string read_file(const std::string& filepath)
		{
			std::stringstream result;
			std::ifstream stream(filepath);
			if (stream.is_open())
			{
				while (stream.peek() != EOF)
				{
					result << (char)stream.get();
				}
				stream.close();
				return result.str();
			}
			else
			{
				return "File not found";
			}
		}
	};
}

#endif