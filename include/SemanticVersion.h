/*
* a simple semantic versioning class.
* (c) 2023 github.com/ida64
*/
#pragma once

#include <string>

class SemanticVersion
{
public: // Constructors and Destructor
	SemanticVersion() = default;
	~SemanticVersion() = default;

	SemanticVersion(int major, int minor, int patch)
		: m_Major(major), m_Minor(minor), m_Patch(patch)
	{ }

	explicit SemanticVersion(const std::string& version)
	{
		std::string major, minor, patch;
		int index = 0;
		for (auto& c : version)
		{
			if (c == '.')
			{
				index++;
				continue;
			}

			switch (index)
			{
				case 0:
					major += c;
					break;
				case 1:
					minor += c;
					break;
				case 2:
					patch += c;
					break;
			}
		}

		m_Major = std::stoi(major);
		m_Minor = std::stoi(minor);
		m_Patch = std::stoi(patch);
	}

public: // Operators
	bool operator==(const SemanticVersion& other) const
	{
		return m_Major == other.m_Major && m_Minor == other.m_Minor && m_Patch == other.m_Patch;
	}

	bool operator!=(const SemanticVersion& other) const
	{
		return !(*this == other);
	}

	bool operator<(const SemanticVersion& other) const
	{
		if (m_Major < other.m_Major)
			return true;
		else if (m_Major > other.m_Major)
			return false;
		if (m_Minor < other.m_Minor)
			return true;
		else if (m_Minor > other.m_Minor)
			return false;
		if (m_Patch < other.m_Patch)
			return true;
		else if (m_Patch > other.m_Patch)
			return false;
		return false;
	}

	bool operator>(const SemanticVersion& other) const
	{
		if (m_Major > other.m_Major)
			return true;
		else if (m_Major < other.m_Major)
			return false;
		if (m_Minor > other.m_Minor)
			return true;
		else if (m_Minor < other.m_Minor)
			return false;
		if (m_Patch > other.m_Patch)
			return true;
		else if (m_Patch < other.m_Patch)
			return false;
		return false;
	}

	bool operator<=(const SemanticVersion& other) const
	{
		return *this < other || *this == other;
	}

	bool operator>=(const SemanticVersion& other) const
	{
		return *this > other || *this == other;
	}

private: // Member Variables
	int m_Major;
	int m_Minor;
	int m_Patch;

}; // class SemanticVersion
