#include "stdafx.h"
#include "ControlCar.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;

CControlCar::CControlCar(CCar & car, istream & input, ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ 
			{ "Info", bind(&CControlCar::Info, this, _1) },
			{ "EngineOn", bind(&CControlCar::EngineOn, this, _1) },
			{ "EngineOff", bind(&CControlCar::EngineOff, this, _1) },
			{ "SetGear", bind(&CControlCar::SetGear, this, _1) },
			{ "SetSpeed", bind(&CControlCar::SetSpeed, this, _1) }
		})
{
}

bool CControlCar::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CControlCar::Info(std::istream & /*args*/)
{
	string info;
	if (m_car.IsTurnedOn())
	{
		info += "��������� ���������� �������\n";
	}
	else
	{
		info += "��������� ���������� ��������\n";
	}

	info += "���������� ";

	if (m_car.GetDirection() == Direction::BACK)
	{
		info += "��������� �����\n";
	}
	else if (m_car.GetDirection() == Direction::STANDING_STILL)
	{
		info += "����� �� �����\n";
	}
	else if (m_car.GetDirection() == Direction::FORWARD)
	{
		info += "��������� �����\n";
	}

	if (m_car.GetSpeed() != 0)
	{
		info += "�� ��������� " + to_string(m_car.GetSpeed()) + "��/�\n";
	}

	info += "�� " + to_string(m_car.GetGear()) + " ��������\n";
	
	m_output << info;
	return true;
}

bool CControlCar::EngineOn(std::istream & args)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "��������� �������\n";
	}
	else
	{
		m_output << "�� ������� �������� ���������\n";
	}
	return true;
}

bool CControlCar::EngineOff(std::istream & args)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "��������� ��������\n";
	}
	else
	{
		m_output << "�� ������� ��������� ���������\n";
	}
	return true;
}

bool CControlCar::SetGear(std::istream & args)
{
	string info;

	int gear;
	args >> gear;

	if (!m_car.SetGear(gear))
	{
		info = "�� ������� �������� ��������\n";
	}
	else
	{
		info = "�������� " + to_string(gear) + " ��������\n";
	}

	m_output << info;
	return true;
}

bool CControlCar::SetSpeed(std::istream & args)
{
	string info;

	int speed;
	args >> speed;

	if (!m_car.SetSpeed(speed))
	{
		info = "�� ������� ���������� ��������\n";
	}
	else
	{
		info = "�������� ��������, ������ ��� " + to_string(speed) + " ��/�\n";
	}

	m_output << info;
	return true;
}