#include <iostream>
#include <map>
#include <string>
using namespace std;


class UnitImage
{
private:
	string image;
public:
	void SetImage(string image) {
		this->image = image;
	}
	string GetImage()const {
		return image;
	}
};

class Unit abstract
{
protected:
	int power;
	int speed;
public:
	virtual void Show(UnitImage* ui)abstract;
};

class Infantry: public Unit
{
public:
	Infantry()
	{
		speed = 20;
		power = 10;
	}
	void Show(UnitImage* ui) override
	{
		char buffer[100];
		sprintf_s(buffer, "Infantry on %s map; \n: %d - speed   %d - power", ui->GetImage().c_str(), speed, power);
		cout << buffer << endl;
	}
};

class TransportVehicle: public Unit
{
public:
	TransportVehicle()
	{
		speed = 70;
		power = 0;
	}
	void Show(UnitImage* ui) override
	{
		char buffer[100];
		sprintf_s(buffer, "Transport vehicle on %s map; \n: %d - speed   %d - power", ui->GetImage().c_str(), speed, power);
		cout << buffer << endl;
	}
};

class HeavyGroundCombat : public Unit
{
public:
	HeavyGroundCombat()
	{
		speed = 15;
		power = 150;
	}
	void Show(UnitImage* ui) override
	{
		char buffer[100];
		sprintf_s(buffer, "Heavy ground combat on %s map; \n: %d - speed   %d - power", ui->GetImage().c_str(), speed, power);
		cout << buffer << endl;
	}
};

class LightGroundCombat : public Unit
{
public:
	LightGroundCombat()
	{
		speed = 50;
		power = 30;
	}
	void Show(UnitImage* ui) override
	{
		char buffer[100];
		sprintf_s(buffer, "Light ground combat on %s map; \n: %d - speed   %d - power", ui->GetImage().c_str(), speed, power);
		cout << buffer << endl;
	}
};

class Aircraft: public Unit
{
public:
	Aircraft()
	{
		speed = 300;
		power = 100;
	}
	void Show(UnitImage* ui) override
	{
		char buffer[100];
		sprintf_s(buffer, "Aircraft on % s map; \n: % d - speed % d - power", ui->GetImage().c_str(), speed, power);
		cout << buffer << endl;
	}
};

class UnitFactory
{
private:
	map<char, Unit*> characters;
public:
	Unit* GetUnit(char key)
	{
		Unit* unit = characters[key];
		if (unit == nullptr)
		{
			switch (key)
			{
			case '1':
				unit = new Infantry();
				break;
			case '2':
				unit = new TransportVehicle();
				break;
			case '3':
				unit = new HeavyGroundCombat();
				break;
			case '4':
				unit = new LightGroundCombat();
				break;
			case '5':
				unit = new Aircraft();
				break;
			}
			characters[key] = unit;
		}
		return unit;
	}
};

int main()
{
	//1 2 3 4 5
	string order = "1345123";
	string loc = "desert";
	UnitImage location;
	location.SetImage(loc);
	UnitFactory *unitFactory = new UnitFactory();

	for (int i = 0; i < order.length(); i++)
	{
		Unit*unit = unitFactory->GetUnit(order[i]);
		unit->Show(&location);
	}

	system("pause");

	delete unitFactory;
	system("pause");
}