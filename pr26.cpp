
#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <cstring>

using namespace std;

class Device 
{ 
public:
	Device ()
	{
		cout<<"Device constructor"<<endl;
	}
	
	virtual ~Device()
	{
	}
	void TurnOn()
	{
		cout<<"Device turnOn"<<endl;
	}
	void TurnOff()
		{
		cout<<"Device turnOff"<<endl;
	}
	virtual void GetStatus() const = 0 ;

};
class Printer : public virtual Device 
{
public:
	void Print()
	{
       cout<<"print" <<endl;
	}

void GetStatus() const
{
	cout<<"printer" <<endl;
}

};

class  Scanner: public virtual Device
    {
public:
      void Scan()
	  {
       cout<<"scan"<<endl;
	  }
   void GetStatus() const
{
	cout<<"Scanner" <<endl;
}


};
class MFU: public Printer, Scanner
{
	public:
	 MFU():
      Device ()
	 {
	 }
	
	void GetStatus() const
{
	cout<<"MFU" <<endl;
}
};
int _tmain(int argc, _TCHAR* argv[])
{
 Device* pDevice1 = new Printer();
	pDevice1 -> GetStatus();
 Device* pDevice2 = new Scanner();
 pDevice2 -> GetStatus();
 Device* pDevice3 = new MFU();
  pDevice3 -> GetStatus();
 
  
  Scanner scanner;
   scanner.TurnOn();
  scanner.Scan();
 Printer printer;
 printer.TurnOn();
 printer.Print();
   MFU mfu;
  mfu.TurnOn();
   scanner.TurnOff();
   printer.TurnOff();
    mfu.TurnOff();
   return 0;
}

