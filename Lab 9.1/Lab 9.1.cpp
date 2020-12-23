// A
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Spec {  KN,INF,ME,FI,TN };
string SpecStr[] = { "Комп.наука", "Інформатика", "Математика та Економіка", "Фізика та Інформатика", "Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Spec spec;
		int physics;
		int math;
		int inform;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
double LineSearch1(Student* p, const int N);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	int cnt = LineSearch(p, N);
	cout << "Кількість студентів,які навчаються на відмінно та добре:" << endl;
		cout << cnt << endl;
		int proc = LineSearch1(p, N);
		cout << "Процент студентів, у яких середній бал менший 4:" << endl;
		cout << proc << '%' << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " Спеціальність: (0 - Комп.науки, 1 -Інформатика , 2 - Математика та економіка, 3 - Фізика та Інформатика,4 - Трудове навчання): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " Оцінка по фізиці: ";cin >> p[i].physics;
		cout << " Оцінка по математиці: ";cin >> p[i].math;
		cout << " Оцінка по інформатиці: ";cin >> p[i].inform;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика|"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(3) << right << i + 1 << " ";
		cout << "|  " << setw(6) << left << p[i].prizv<< "| " << setw(4) << right << p[i].kurs << "  "
			<< "| " << setw(6) << left << SpecStr[p[i].spec] << setw(4);
		cout<< "   |" << setw(4) << right<< p[i].physics  << setw(4) << right << "| ";
		cout<< setw(4) << right<< p[i].math << setw(4) << right << "    | " ;
		cout << setw(4)<< right<< p[i].inform << setw(1) << right << " |" <<endl;
		cout << "========================================================================="
			<< endl;
		cout << endl;
	}
}
	double LineSearch(Student * p, const int N){
		int n = 0;
		for (int i = 0; i < N; i++)
		{
			if ((p[i].physics>3) && (p[i].math>3) && (p[i].inform>3))
			{
				n++;
			}
		}
		return n;
	}
	double LineSearch1(Student* p, const int N) {
		int n = 0,k=0;
		for (int i = 0; i < N; i++)
		{
			n++;
			if (((p[i].physics + p[i].math+p[i].inform)/ 3)<4 )
			{
				k++;
			}
		}
		return 100*k/n;
	}