#include "Animal.h"

Animal::Animal()
{
	this->m_color = _strdup("GRAY");  // במבחן בלי קו תחתון
	this->m_childCount = 0;
	this->m_avgLifetime = 0.f;  // float
}

Animal::Animal(const char* color, int childs, float avgLifetime)
{
	this->m_color = _strdup(color);  // במבחן בלי קו תחתון
	this->m_childCount = childs;
	this->m_avgLifetime = avgLifetime;
}


Animal::Animal(ifstream& in_file)  // קריאה מקובץ בינארי
{
	char c;
	m_color = readTextFromFile(in_file); // נשמור משתנה מסוג צאר
	in_file.read((char*)&m_childCount, sizeof(m_childCount));  // עשינו קאסטינג לצאר , כי המשתנה הוא אינט
	in_file.read(&c, 1);
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));// עשינו קאסטינג לצאר , כי המשתנה הוא פלוט
	in_file.read(&c, 1);
}

Animal::Animal(const Animal& other) // copy constractor
{
	this->m_color = _strdup(other.m_color);
	m_childCount = other.m_childCount;
	this->m_avgLifetime = other.m_avgLifetime;
}

Animal::~Animal()
{
	if (m_color)
	{
		delete m_color;
	}
	m_color = nullptr;
}

const char* Animal::GetColor() const // נחזיר צאר
{
	return m_color;
}

int Animal::GetChildCount() const  // נחזיר אינט
{
	return m_childCount;
}

float Animal::GetLifetime() const  // נחזיר פלוט
{
	return m_avgLifetime;
}

void Animal::Load(ifstream& in_file)  // קריאה/טעינה   מקובץ טקסט
{
	m_color = readTextFromFile(in_file);
	in_file >> m_childCount;
	in_file >> m_avgLifetime;
}

void Animal::Save(ofstream& out_file) const  // כתיבה/שמירה מקובץ טקסט
{
	SaveType(out_file);
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;
}

void Animal::SaveType(ofstream& out_file) const
{
	out_file << GetTypeName() << endl;
}

void Animal::SaveBin(ofstream& out_file) const  // שמירה /כתיבה  בינארי קובץ
{
	SaveTypeBin(out_file);
	out_file.write(m_color, strlen(m_color));   // הצקאה לצאר כוכבית כבר
	out_file.write("\n", 1);
	out_file.write((char*)&m_childCount, sizeof(m_childCount));  // המרה מאינט לצאר כי לקובץ
	out_file.write("\n", 1);
	out_file.write((char*)&m_avgLifetime, sizeof(m_avgLifetime));
	out_file.write("\n", 1);

}

void Animal::SaveTypeBin(ofstream& out_file) const // שמירה וכתיבה של הסוג בקובץ בינארי
{
	char type[256] = { 0 };
	strcpy(type, GetTypeName());//   העברת שם הסוג לצד שמאל
	out_file.write((const char*)type, strlen(type));
	out_file.write("\n", 1);
}



char* readTextFromFile(ifstream& in_file)  // פונ עזר למשתנה מסוג צאר
{
	char str[256] = { 0 };
	while (0 == strlen(str))
		in_file.getline(str, 256, '\n');

	return _strdup(str);
}


char* fixTypeName(char* name)  // פונ עזר
{
	if ('0' <= name[0] && name[0]<='9')
	{
		return (char*)(name + 1);
	}
	return (char*)(name + 1);
}

char* Animal::GetTypeName() const // פונ עזר
{
	return fixTypeName((char*)typeid(*this).name());
}