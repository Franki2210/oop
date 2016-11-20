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
		info += "Двигатель автомобиля включён\n";
	}
	else
	{
		info += "Двигатель автомобиля выключен\n";
	}

	info += "Автомобиль ";

	if (m_car.GetDirection() == Direction::BACK)
	{
		info += "двигается назад\n";
	}
	else if (m_car.GetDirection() == Direction::STANDING_STILL)
	{
		info += "стоит на месте\n";
	}
	else if (m_car.GetDirection() == Direction::FORWARD)
	{
		info += "двигается вперёд\n";
	}

	if (m_car.GetSpeed() != 0)
	{
		info += "Со скоростью " + to_string(m_car.GetSpeed()) + "км/ч\n";
	}

	info += "На " + to_string(m_car.GetGear()) + " передаче\n";
	
	m_output << info;
	return true;
}

bool CControlCar::EngineOn(std::istream & args)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Двигатель включён\n";
	}
	else
	{
		m_output << "Не удалось включить двигатель\n";
	}
	return true;
}

bool CControlCar::EngineOff(std::istream & args)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Двигатель выключен\n";
	}
	else
	{
		m_output << "Не удалось выключить двигатель\n";
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
		info = "Не удалось включить передачу\n";
	}
	else
	{
		info = "Включена " + to_string(gear) + " передача\n";
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
		info = "Не удалось установить скорость\n";
	}
	else
	{
		info = "Скорость изменена, теперь она " + to_string(speed) + " км/ч\n";
	}

	m_output << info;
	return true;
}