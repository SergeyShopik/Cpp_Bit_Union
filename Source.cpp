#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

//bit field
struct BYTE
{
	/*type field_name : size;
	type field_name : size;
	type field_name : size;*/
	bool p1 : 1;
	bool p2 : 1;
	bool p3 : 1;
	bool p4 : 1;
	bool p5 : 1;
	bool p6 : 1; 
	bool p7 : 1;
	bool p8 : 1;
};
union MyUnion
{
	float val1;
	BYTE bit[4];
	unsigned char byte[4];
};
union
{
	int val1;
	unsigned int val2;
	BYTE bit[4];
} m1, m2;

struct Iron
{
	char brand[20];
	char model[20];
	char color[10];
	int minTemp;
	int maxTemp;
	int power;
	bool steam;
};

void read(Iron&, std::istream&);
void print(const Iron&, std::ostream&);
int search(Iron*, size_t, const Iron&);
void editModel(Iron&, char*);


int main()
{
	MyUnion m;
	m.val1 = 128;
	for (int i = 3; i >= 0; i--)
	{
		std::cout << m.bit[i].p8 << m.bit[i].p7 << m.bit[i].p6 << m.bit[i].p5 << m.bit[i].p4 << m.bit[i].p3
			<< m.bit[i].p2 << m.bit[i].p1 << " ";
	}
	std::cout << std::endl;


	// 1. Create union consisting of integer, char array and union consisting of double and char array.
	// Print all number's bytes, print chosen integer's byte, print bytes in decimal and hex view.
	//int b;
	//std::cout << "Enter num of byte: ";
	//std::cin >> b;
	//b = 4 - b; //in order to see left to right
	//std::cout << m.bit[b].p8 << m.bit[b].p7 << m.bit[b].p6 << m.bit[b].p5 << m.bit[b].p4 << m.bit[b].p3
	//	<< m.bit[b].p2 << m.bit[b].p1 << std::endl;
	//std::cout << "Decimal: \n";
	//for (int i = 3; i >= 0; i--)
	//{
	//	std::cout << static_cast<int>(m.byte[i]) << " ";
	//}
	//std::cout << std::endl;
	//std::cout << "Hex: \n";
	//for (int i = 3; i >= 0; i--)
	//{
	//	std::cout << std::hex << static_cast<int>(m.byte[i]) << " ";
	//}

	// 2. Create 4-byte integer which can be applied to as signed integer and unsigned integer without explicit cast. Use union.
	/*m1.val1 = 55;
	m2.val2 = -55;
	int a = 55, b = -55;
	std::cout << m1.val1 << " " << m1.val2 << std::endl;
	std::cout << a << " " << static_cast<size_t>(a) << std::endl;
	std::cout << m2.val1 << " " << m2.val2 << std::endl;
	std::cout << b << " " << static_cast<size_t>(b) << std::endl;*/

	// 3. Create union consisting of integer and array of logical variables.
	// Count integer's null bytes, print info about bytes - null or not null.
	/*std::cout << "Enter number: \n";
	std::cin >> m1.val1;
	int count = 0;
	for (int i = 3; i >= 0; i--)
	{
		if (m1.bit[i].p8 == 0 && m1.bit[i].p7 == 0 && m1.bit[i].p6 == 0 && m1.bit[i].p5 == 0 && m1.bit[i].p4 == 0 && m1.bit[i].p3 == 0 && m1.bit[i].p2 == 0 && m1.bit[i].p1 == 0)
		{
			std::cout << 4 - i << " byte is null.\n";
			count++;
		}
	}
	std::cout << "There are " << count << " null bytes." << std::endl;*/

	// 4. Create struct "Iron"(brand, model, color, min temp, max temp, steam - y/n, power).
	// Create dynamic array of structures.
	// edit element, print only with steam, print less than given power, print all of one brand.

	size_t size = 2;
	Iron* arr = new Iron[size];
	Iron iron;
	std::ifstream fin("Text.txt");
	std::ofstream fout("Out4Task.txt");
	if (!fin)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < size; i++)
	{
		read(arr[i], fin);
		print(arr[i], fout);
	}

	int choice, i;
	std::cout << "What do you want to correct?\n";
	std::cout << "1.Brand\n2.Model\n3.Color\n4.Min temp\n5.Max temp\n6.Power\n7.Steam\n";
	std::cin >> choice;
	std::cout << "Enter desired parameter:\n";
	read(iron, std::cin);
	switch (choice)
	{
	case1:
		break;
	case2: 
		char M[20];
		i = search(arr, size, iron);
		std::cout << "Enter model:\n";
		std::cin >> M;
		editModel(arr[i], M);
		print(arr[i], std::cout);
		break;
	case3:
		break;
	case4:
		break;
	case5:
		break;
	case6:
		break;

	default:
		break;
	}

	//bitwise operators
	char str[80];
	while (!fin.eof())
	{
		char ch;
		fin.getline(str, 80);
		int i = 0;
		while (str[i])
		{
			ch = str[i];
			ch = ~ch;
			fout << ch;
			i++;
		}
		fout << std::endl;
	}
	fout.close();
	std::ifstream fin1("output.txt");
	std::ofstream fout1("output1.txt");
	while (!fin1.eof())
	{
		char ch;
		fin1.getline(str, 80);
		int i = 0;
		while (str[i])
		{
			ch = str[i];
			ch = ~ch;
			fout1 << ch;
			i++;
		}
		fout1 << std::endl;
	}

	return 0;
}

void read(Iron& st, std::istream& in)
{
	in >> st.brand >> st.model >> st.color >> st.maxTemp >> st.minTemp >> st.power >> st.steam;
}
void print(const Iron& st, std::ostream& out)
{
	out << "Brand: " << st.brand << "\nModel: " << st.model << "\nColor: " << st.color << "\nMax temperature: " << st.maxTemp <<
		"\nMin temperature: " << st.minTemp << "\nPower: " << st.power << "\nSteam: " << st.steam << "\n\n";
}
int search(Iron*arr, size_t size, const Iron& st)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].brand, st.brand) == 0 && strcmp(arr[i].model, st.model) == 0 && strcmp(arr[i].color, st.color) == 0
			&& arr[i].maxTemp == st.maxTemp && arr[i].minTemp == st.minTemp && arr[i].power == st.power && arr[i].steam == st.steam)
			return i;
	}
	std::cout << "Not found.\n";
	return -1;
}
void editModel(Iron& st, char* Model)
{
	strcpy(st.model, Model);
}

