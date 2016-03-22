#include "fseeker.h"
#include <fstream>

#pragma warning(disable:4996)

fseeker::fseeker() {
	pFile = fopen("ProfileData.txt", "w");
	readFile = NULL;
}

std::vector<std::string> fseeker::split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);       // turn the string into a stream.
	std::string tok;

	while(getline(ss, tok, delimiter))
	{
		internal.push_back(tok);
	}

	return internal;
}

std::string fseeker::getName(int index)
{
	std::string result;
	char name[20];
	readFile = fopen("ProfileData.txt","r");
	int profileIndex = index * 53;
	fseek(readFile, profileIndex, SEEK_SET);
	fgets(name, 21, readFile);
	result = std::string(name);
	result = stripWord(result);
	fclose(readFile);
	return result;
}

std::string fseeker::getAge(int index)
{
	std::string result;
	char age[3];
	readFile = fopen("ProfileData.txt", "r");
	int profileIndex = index * 53 + 20;
	fseek(readFile, profileIndex, SEEK_SET);
	fgets(age, 4, readFile);
	result = std::string(age);
	result = stripWord(result);
	fclose(readFile);
	return result;
}

std::string fseeker::getOccupation(int index)
{
	std::string result;
	char occupation[30];
	readFile = fopen("ProfileData.txt", "r");
	int profileIndex = index * 53 + 23;
	fseek(readFile, profileIndex, SEEK_SET);
	fgets(occupation, 31, readFile);
	result = std::string(occupation);
	result = stripWord(result);
	fclose(readFile);
	return result;
}

void fseeker::insert(std::string name, std::string age, std::string occupation, int index) {
	int profileIndex = index * 53;
	fseek(pFile, profileIndex, SEEK_SET);
	char* name1 = new char[name.length() + 1];
	memcpy(name1, name.c_str(), name.length() + 1);
	fputs(name1, pFile);
	fseek(pFile, 20 - strlen(name1), SEEK_CUR);
	char* age1 = new char[age.length() + 1];
	memcpy(age1, age.c_str(), age.length() + 1);
	fputs(age1, pFile);
	fseek(pFile, 3 - strlen(age1), SEEK_CUR);
	char* occupation1 = new char[occupation.length() + 1];
	memcpy(occupation1, occupation.c_str(), occupation.length() + 1);
	fputs(occupation1, pFile);
	fflush(pFile);
}

bool fseeker::isWordChar(char c) {
	return
		(c >= 65 && c <= 90) ||   // upper case
		(c >= 97 && c <= 122) ||  // lower case
		(c >= 48 && c <= 57);    // digits
}

std::string fseeker::stripWord(std::string word) {

	while (!(isWordChar(word[word.length() - 1])) && word.length() > 0) {
		word.erase(word.end() - 1);
	}

	return word;
}

