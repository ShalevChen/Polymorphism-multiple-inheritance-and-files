#include "Zoo.h"
// �� ����
Zoo::Zoo()  // ����� ����� �����
{
	this->m_name = nullptr;  // ����� ������ ��� ���� ���������
	this->m_address = nullptr; // ����� ������ ��� ���� ���������
	this->m_ticketPrice = 0;
	this->m_openHours = nullptr; // ����� ������ ��� ���� ���������
	this->m_closeHours = nullptr; // ����� ������ ��� ���� ���������
	this->m_numOfAnimals = 0;
	this->m_animals = nullptr; // ����� ������ ��� ���� ���������
}

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)  // ����� ����� ����� - �� ��� ������ ������� ����� ���� �� ���������
{
	this->m_name = _strdup(name);
	this->m_address = _strdup(address);
	this->m_ticketPrice = ticket;
	this->m_openHours = _strdup(open);
	this->m_closeHours = _strdup(close);
	this->m_numOfAnimals = 0;
	this->m_animals = nullptr;

}

Zoo::Zoo(ifstream& in_file)
{

}

Zoo::~Zoo()
{
}

const char* Zoo::GetName() const
{
	return nullptr;
}

const char* Zoo::GetAddress() const
{
	return nullptr;
}

float Zoo::GetTicketPrice() const
{
	return 0.0f;
}

const char* Zoo::GetOpenHour() const
{
	return nullptr;
}

const char* Zoo::GetCloseHour() const
{
	return nullptr;
}

int Zoo::GetNumOfAnimals() const
{
	return 0;
}

Animal** Zoo::GetAnimals() const
{
	return nullptr;
}

void Zoo::AddAnimal(Animal* an)
{
}

Zoo& Zoo::operator+(Animal* an)
{
	// TODO: insert return statement here
}

Zoo Zoo::operator+(const Zoo& other) const
{
	return Zoo();
}

void Zoo::Save(ofstream& ofs) const
{
}

void Zoo::Load(ifstream& ifs)
{
}

void Zoo::SaveBin(ofstream& ofs) const
{
}

ofstream& operator<<(ofstream& out, const Zoo& z)
{
	// TODO: insert return statement here
}

ifstream& operator>>(ifstream& in, Zoo& z)
{
	// TODO: insert return statement here
}
