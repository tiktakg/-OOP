#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <string>

class core
{
public:
	
	std::string setModel(std::string text)
	{
		std::string textAboutModel;
		std::cout << text;
		std::cin >> textAboutModel;

		return textAboutModel;
	}

	int setCore()
	{
		int countCore;
		std::cout << "Write a count core\n";
		std::cin >> countCore;

		return countCore;
	}
};

class CPU : core
{
public:
	int countCore;

	std::string modelCpu;

	void setCPU()
	{
		modelCpu = setModel("Write a model of Cpu\n");
		countCore = setCore();
	}
};

class GPU : core
{
public:
	int countCore;
	std::string modelGpu;

	void setGPU()
	{
		modelGpu = setModel("Write a model of Gpu\n");
		countCore = setCore();
	}
};

class Pc : GPU, CPU
{
	int countGpuCore;
	int countCpuCore;
	std::string modelPc;

public:

	void makePc()
	{
		setCPU();
		setGPU();

		countGpuCore = GPU::countCore;
		countCpuCore = CPU::countCore;
		modelPc = GPU::modelGpu + " " + CPU::modelCpu;
	}

	void writeConfig()
	{
		system("cls");

		std::cout << "Model of pc = " + modelPc << std::endl;
		std::cout << "Count core cpu = " + std::to_string(countCpuCore) << std::endl;
		std::cout << "Count core gpu = " + std::to_string(countGpuCore) << std::endl;
	}
};

int main()
{
	Pc pc;

	pc.makePc();
	pc.writeConfig();
}