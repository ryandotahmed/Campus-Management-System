#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include <iomanip> 
#include<math.h>

using namespace std;
//Globle Variables
std::string student_section ;
std::string student_rollnumber;
std::string Teacher_ID;
std::string Teacher_section;
std::string expenses;

class admin
{
private:
	string name_admin;
	string admin_cnic;
	string admin_phone;
	string admin_adress;
	string admin_username;
	int admin_pass;
public:
	void set_admin_user(string a)
	{
		admin_username = a;
	}
	void set_admin_pass(int b)
	{
		admin_pass = b;
	}
	string get_admin_user()
	{
		return admin_username;
	}
	int get_admin_pass()
	{
		return admin_pass;
	}
	bool admin_login()
	{
		if (get_admin_user() == "admin" && get_admin_pass() == 1122)
		{
			std::cout << "Login Successful\n";
			return 1;
		}
		else
		{
			std::cout << "Login Details Are Not Correct\n";
			return 0;
		}
	}
};

class students
{

protected:
	std::string student_fname;
	std::string student_lname;
	std::string student_phone;
	std::string student_cnic;
	std::string student_email;
	std::string student_address;
	std::string check_cnic;
	std::string student_semes;
	std::string id_student;
	double student_fee;
	int password;
public:
	students()
	{
		 student_fname = "";
		 student_lname = "";
		 student_phone = "";
		 student_cnic = "";
		 student_email = "";
		 student_address = "";
		 check_cnic = "";
		 student_semes = "";
		 id_student = "";
		 student_fee = 0;
		 password = 1111;
	}
	void new_students()
	{
		students stu;
		bool flag = 0;
		std::fstream file, result_file, file_fee, f;
		std::string check_exis_cnic;
		//variable for student result
		double moke_marks = 0;
		double pre_board_marks = 0;
		double class_marks = 0;

		file.open("student.dat", std::ios::in);
		result_file.open("StudentResult.dat", std::ios::app);
		file_fee.open("StudentFee.dat", std::ios::app);
		f.open("StudentPassword.dat", std::ios::app);

		if (file.fail() && result_file.fail() && file_fee.fail()) {
			std::cout << "File Connection Error\n";
		}

		std::cout << "Enter Student First Name: ";
		std::cin >> student_fname;
		std::cout << "Enter Student Last Name: ";
		std::cin >> student_lname;
		std::cout << "Enter Student Section: ";
		std::cin >> student_semes;
		std::cout << "Enter ID (Roll_Number): ";
		std::cin >> id_student;
		std::cout << "Enter Student Ph# : ";
		std::cin >> student_phone;
		std::cout << "Enter Student CNIC: ";
		std::cin >> student_cnic;
		std::cout << "Enter Student Email: ";
		std::cin >> student_email;
		std::cout << "Enter Student Address: ";
		std::cin >> student_address;
		std::cout << "Enter Student Fee: ";
		std::cin >> student_fee;
		while (!file.eof())
		{
			file >> stu.student_fname >> stu.student_lname >> stu.student_phone >> stu.student_cnic >> stu.student_email >> stu.student_address >> stu.student_semes >> stu.id_student;
			if (student_cnic == stu.student_cnic) {
				flag = 1;
				std::cout << "Student Already Exist\n";
			}
		}
		file.close();
		file.open("student.dat", std::ios::app);
		f << "\n" << id_student << "\t" << password;
		if (flag == 0) {
			file << "\n" << student_fname << "\t" << student_lname << "\t" << student_phone << "\t" << student_cnic << "\t" << student_email << "\t" << student_address << "\t" << student_semes << "\t" << id_student;
			result_file << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << pre_board_marks << "\t" << class_marks;
			f << "\n" << id_student << "\t" << password;
			file_fee << "\n" << id_student << "\t" << student_fee;
			cout << "Student Register Successfully\n";
		}
		file.close();
		file_fee.close();
		f.close();
		result_file.close();
	}

	void show_students()
	{
		std::fstream a;
		//load
		a.open("student.dat", std::ios::in);
		while (!a.eof())
		{
			a >> student_fname >> student_lname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes >> id_student;
			//file_obj.read((char*)&obj, sizeof(obj));

			std::cout << "Student Name   | ";
			std::cout << student_fname << " " << student_lname << std::endl;
			std::cout << "Student RollNo | ";
			std::cout << id_student << std::endl;
			std::cout << "Student Section| ";
			std::cout << student_semes << std::endl;
			std::cout << "Student Ph#    | ";
			std::cout << student_phone << std::endl;
			std::cout << "Student CNIC   | ";
			std::cout << student_cnic << std::endl;
			std::cout << "Student Email  | ";
			std::cout << student_email << std::endl;
			std::cout << "Student Address| ";
			std::cout << student_address << std::endl;

			cout << "_______________________________________________\n";
		}
	}
	void search_students()
	{
		std::fstream file, temp;
		file.open("student.dat", std::ios::in);
		temp.open("temp.dat", std::ios::out);
		bool flag = 0;
		std::cout << "Enter Student CNIC to updae\n";
		cin >> check_cnic;
		while (!file.eof())
		{
			file >> student_fname >> student_lname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes;
			if (check_cnic == student_cnic)
			{
				flag = 1;
				std::cout << "Student Name   | ";
				std::cout << student_fname << " " << student_lname << std::endl;
				std::cout << "Student RollNo | ";
				std::cout << id_student << std::endl;
				std::cout << "Student Section| ";
				std::cout << student_semes << std::endl;
				std::cout << "Student Ph#    | ";
				std::cout << student_phone << std::endl;
				std::cout << "Student CNIC   | ";
				std::cout << student_cnic << std::endl;
				std::cout << "Student Email  | ";
				std::cout << student_email << std::endl;
				std::cout << "Student Address| ";
				std::cout << student_address << std::endl;

				cout << "_______________________________________________\n";
			}

		}
		if (flag == 0)
		{
			cout << "Sorry! Student Not Found\n";
		}
		file.close();
		temp.close();
	}

	void update_students() {
		std::fstream file, temp;
		file.open("student.dat", std::ios::in);
		temp.open("temp.dat", std::ios::out);
		bool flag = 0;
		std::cout << "Enter Student CNIC to update\n";
		cin >> check_cnic;
		while (!file.eof())
		{
			file >> student_fname >> student_lname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes;
			if (check_cnic == student_cnic)
			{
				//update
				std::string section;
				std::string name;
				std::cout << "Enter Student's Semester:";
				std::cin >> section;
				std::cout << "Enter Student's Name:";
				std::cin >> name;
				temp << "\n" << name << "\t" << student_phone << "\t" << student_cnic << "\t" << student_email << "\t" << student_address << "\t" << section;
				flag = 1;
			}
			else
			{
				//same content copy
				temp << "\n" << student_fname << "\t" << student_lname << "\t" << student_phone << "\t" << student_cnic << "\t" << student_email << "\t" << student_address << "\t" << student_semes;
			}
		}
		file.close();
		temp.close();

		remove("student.dat");
		rename("temp.dat", "student.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
		else {
			std::cout << "Sorry! Cnic Not Found\n";
		}
	}

	void remove_students() {
		std::fstream file, temp;
		file.open("student.dat", std::ios::in);
		temp.open("temp.dat", std::ios::out);
		cout << "Enter Student CNIC To Remove\n";
		cin >> check_cnic;
		bool flag = 0;
		while (!file.eof())
		{
			file >> student_fname >> student_fname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes;
			if (check_cnic == student_cnic)
			{
				flag = 1;
			}
			else
			{
				//same content copy
				temp << "\n" << student_fname << "\t" << student_fname << "\t" << student_phone << "\t" << student_cnic << "\t" << student_email << "\t" << student_address << "\t" << student_semes;;
			}
		}
		file.close();

		temp.close();

		remove("student.dat");
		rename("temp.dat", "student.dat");
		if (flag == 1)
		{
			std::cout << "Successfully deleted\n";

		}
		else {
			std::cout << "Sorry! Cnic Not Found\n";
		}
	}

};


class student_portal : private students
{
private:
	std::string username;
	int pass;
	std::string file_username;
	int file_password;

public:
	students student;
	void set_user(std::string p) {
		username = p;
	}
	std::string get_user() {
		return username;
	}
	void set_pass(int pas) {
		pass = pas;
	}
	int get_pass() {
		return pass;
	}

	bool login()
	{

		std::fstream file_pass, file_student;
		bool flag = 0;
		file_pass.open("StudentPassword.dat", std::ios::in);
		file_student.open("student.dat", std::ios::in);

		if (file_pass.fail() && file_student.fail()) {
			cout << "Couldn't open the file!" << endl;
			return 0;
		}

		while (!file_student.eof()) {
			file_student >> student_fname >> student_lname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes >> id_student;
			if (get_user() == id_student) {
				student_section = student_semes;
				student_rollnumber = id_student;
			}
		}

		while (!file_pass.eof())
		{
			file_pass >> file_username >> file_password;

			if (get_user() == file_username && get_pass() == file_password)
			{
				// Login Successful

				flag = 1;
				std::cout << "Login Successful\n";

			}


		}
		// to check student section

		if (flag == 0)
		{
			std::cout << "Login details are not correct\n";
			return 0;
		}
		else {
			return 1;
		}

	}


	void update_student_password() {

		std::fstream file_pass;
		std::fstream file_update;
		bool flag = 0;
		std::string check_exis;
		std::string update_username;;
		int update_passw;
		int old_passw;
		file_pass.open("StudentPassword.dat", std::ios::in);
		file_update.open("Update_StudentPassword.dat", std::ios::out);

		if (file_pass.fail() && file_update.fail()) {

			cout << "Couldn't open the file!" << endl;

		}

		std::cout << "Enter Your Username\n";
		std::cin >> update_username;
		std::cout << "Enter Your Old Password\n";
		std::cin >> old_passw;

		while (!file_pass.eof()) {
			file_pass >> username >> pass;
			if (update_username == username && old_passw == pass) {

				std::cout << "Enter Your New Password\n";
				std::cin >> update_passw;
				flag = 1;
				file_update << "\n" << update_username << "\t" << update_passw;
				std::cout << "Password Successfully Changed\n";


			}

			else {
				file_update << "\n" << username << "\t" << pass;
			}

		}

		if (flag == 0) {
			std::cout << "Username Not Found\n";
		}

		file_pass.close();
		file_update.close();
		remove("StudentPassword.dat");
		rename("Update_StudentPassword.dat", "StudentPassword.dat");
	}


	void student_course() {
		std::string* p;
		int a;
		bool flag = 0;
		std::fstream file;

		std::cout << "Enter Section:";
		std::cin >> student_semes;
		std::cout << "How many subject you like to enroll in " << student_semes;
		if (student_semes == "3rd") {
			file.open("BEE12-B_course.dat", std::ios::app);
			std::cout << "You Can Only Enter 5 Subjects To " << student_semes;
			std::cin >> a;
			p = new std::string[a];
			file << "\n";
			file << student_semes << "\t";
			for (int i = 0; i < a; i++) {
				std::cout << "Enter Subject:";
			std:cin >> p[i];
				file << p[i] << "\t";
			}


			file.close();
		}
		if (student_semes == "1st") {
			file.open("BEE13-B_course.dat", std::ios::app);
			std::cout << "You Can Only Enter 4 Subjects To " << student_semes;
			std::cin >> a;
			p = new std::string[a];
			file << "\n";
			file << student_semes << "\t";
			for (int i = 0; i < a; i++) {
				std::cout << "Enter Subject:";
				std::cin >> p[i];
				file << p[i] << "\t";
			}


			file.close();
		}
		if (student_semes == "5th") {
			file.open("BEE11-B_course.dat", std::ios::app);
			std::cout << "You Can Only Enter 6 Subjects To " << student_semes;
			std::cin >> a;
			p = new std::string[a];
			file << "\n";
			file << student_semes << "\t";
			for (int i = 0; i < a; i++) {
				std::cout << "Enter Subject:";
				std::cin >> p[i];
				file << p[i] << "\t";
			}


			file.close();
		}
	}


	void show_course() {
		int x;
		std::fstream a;
		//load

		if (student_section == "BEE12-B") {
			a.open("BEE12-B_course.dat", std::ios::in);
			std::string course[5];
			int loop = 4;
			std::cout << "=========================\n";
			std::cout << setw(10)<< "Course Name "<<setw(10)<<"Section \n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3] >> course[4];
			if (student_section == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout<< course[i] <<setw(20)<< student_semes <<endl;
				}
			}


			std::cout <<setw(10)<< "=======================\n";
			a.close();
		}
		if (student_section == "BEE13-B") {
			a.open("BEE13-B_course.dat", std::ios::in);
			std::string course[4];
			int loop = 3;
			std::cout << "                                " << "=======================\n";
			std::cout << "                                " << "|Course Name | Section |\n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3];
			if (student_section == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout << "                                " << "|  " << course[i] << "       |   " << student_semes << "  |" << endl;
				}


			}
			std::cout << "                                " << "=======================\n";
			a.close();
		}
		if (student_section == "BEE11-B") {
			a.open("BEE11-B_course.dat", std::ios::in);
			std::string course[6];
			int loop = 5;
			std::cout << "                                " << "=======================\n";
			std::cout << "                                " << "|Course Name | Section |\n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3] >> course[4] >> course[5];
			if (student_section == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout << "                                " << "|  " << course[i] << "       |   " << student_semes << "  |" << endl;
				}
			}

			std::cout << "                                " << "=======================\n";
			a.close();
		}

	}


	void show_course(std::string u) {
		int x;
		std::string iid = u;
		std::fstream a;
		//load

		if (iid == "BEE11-B") {
			a.open("BEE11-B_course.dat", std::ios::in);
			std::string course[5];
			int loop = 4;
			std::cout << "                                " << "=======================\n";
			std::cout << "                                " << "|Course Name | Section |\n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3] >> course[4];
			if (iid == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout << "                                " << "|  " << course[i] << "       |   " << student_semes << "  |" << endl;
				}
			}


			std::cout << "                                " << "=======================\n";
			a.close();
		}
		if (iid == "BEE12-B") {
			a.open("BEE12-B_course.dat", std::ios::in);
			std::string course[4];
			int loop = 3;
			std::cout << "                                " << "=======================\n";
			std::cout << "                                " << "|Course Name | Section |\n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3];
			if (iid == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout << "                                " << "|  " << course[i] << "       |   " << student_semes << "  |" << endl;
				}


			}
			std::cout << "                                " << "=======================\n";
			a.close();
		}
		if (iid == "BEE13-B") {
			a.open("BEE13-B_course.dat", std::ios::in);
			std::string course[6];
			int loop = 5;
			std::cout << "                                " << "=======================\n";
			std::cout << "                                " << "|Course Name | Section |\n";

			a >> student_semes >> course[0] >> course[1] >> course[2] >> course[3] >> course[4] >> course[5];
			if (iid == student_semes) {
				for (int i = 0; i <= loop; i++) {
					std::cout << "                                " << "|  " << course[i] << "       |   " << student_semes << "  |" << endl;
				}
			}






			std::cout << "                                " << "=======================\n";
			a.close();
		}

	}



	void view_student() {
		std::ifstream show;
		bool flag = 0;
		show.open("student.dat", std::ios::in);
		while (!show.eof())
		{
			show >> student_fname >> student_lname >> student_phone >> student_cnic >> student_email >> student_address >> student_semes >> id_student;

			if (get_user() == id_student) {
				flag = 1;

				std::cout << "Student Name   | ";
				std::cout << student_fname << " " << student_lname << std::endl;
				std::cout << "Student RollNo | ";
				std::cout << id_student << std::endl;
				std::cout << "Student Section| ";
				std::cout << student_semes << std::endl;
				std::cout << "Student Ph#    | ";
				std::cout << student_phone << std::endl;
				std::cout << "Student CNIC   | ";
				std::cout << student_cnic << std::endl;
				std::cout << "Student Email  | ";
				std::cout << student_email << std::endl;
				std::cout << "Student Address| ";
				std::cout << student_address << std::endl;
				cout << "_______________________________________________\n";
			}
		}
		if (flag == 0) {
			std::cout << "Error! Your Profile Not Found\n";
		}
	}
};


class timetable : public student_portal
{
private:
	std::string L_start;
	std::string teacherl_name;
	std::string  L_end;
	std::string teacher_name;
	std::string teach_ID;
	std::string subject;
	std::string sect;
public:
	friend class teachers;
	void view_teacher_timetable() {
		std::fstream a;
		std::string section;
		bool flag = 0;

		a.open("TimeTableTeacher.dat", std::ios::in);
		std::cout << "__________________________________________________________________________________\n";
		std::cout << "TeacherID";
		std::cout << "             Lecture Start";
		std::cout << "             Lecture End";
		std::cout << "              Section";
		std::cout << endl;
		std::cout << "___________________________________________________________________________________\n";
		while (!a.eof())
		{
			a >> L_start >> L_end >> teacher_name>> sect;		
			if (Teacher_section == sect) {
				flag = 1;
				std::cout << teacher_name;
				std::cout << "                     " << L_start;
				std::cout << "                     " << L_end;
				std::cout << "                     " << sect;
				std::cout << endl;
				std::cout << "___________________________________________________________________________________\n";
			}

		}
		if (flag == 0) {
			std::cout << "Section Not Found\n";
		}
	}

	void view_teacher_timetablecoo() {
		std::fstream a;
		std::string IId;
		bool flag = 0;
		std::cout << "Enter Teacher ID: ";
		std::cin >> IId;
		a.open("TimeTableTeacher.dat", std::ios::in);
		std::cout << "___________________________________________________________\n";
		std::cout << "Teacher";
		std::cout << "     Lecture Start";
		std::cout << "     Lecture End";
		std::cout << "         Section";
		std::cout << endl;
		std::cout << "___________________________________________________________\n";
		while (!a.eof())
		{
			a >> L_start >> L_end >> teacher_name >>teacherl_name>> sect;
			if (IId == sect) {
				flag = 1;
				std::cout << teacher_name;
				std::cout << "           " << L_start;
				std::cout << "              " << L_end;
				std::cout << "              " << sect;
				std::cout << endl;
				std::cout << "___________________________________________________________\n";
			}

		}
		if (flag == 0) {
			std::cout << "Section Not Found\n";
		}
	}

	void view_student_timetable() {
		std::ifstream a;
		std::string section;
		bool flag = 0;

		a.open("TimeTable.dat", std::ios::in);
		std::cout << "___________________________________________________________\n";
		std::cout << "Teacher";
		std::cout << "     Lecture Start";
		std::cout << "     Lecture End";
		std::cout << "         Section";
		std::cout << endl;
		std::cout << "___________________________________________________________\n";
		
		while (!a.eof())
		{
		a >> L_start >> L_end >> teacher_name >>teacherl_name>> sect;
			if (student_section == sect) {
				flag = 1;
				std::cout << teacher_name<<" ";
				std::cout << teacherl_name;
				std::cout << "           " << L_start;
				std::cout << "           " << L_end;
				std::cout << "           " << sect;
				std::cout << endl;
				std::cout << "___________________________________________________________\n";
			}

		}
		if (flag == 0) {
			std::cout << "Section Not Found\n";
		}
	}


	void view_student_timetable(std::string x) {
		std::fstream a;
		std::string section = x;
		bool flag = 0;

		a.open("TimeTable.dat", std::ios::in);
		std::cout << "___________________________________________________________\n";
		std::cout << "Teacher";
		std::cout << "     Lecture Start";
		std::cout << "     Lecture End";
		std::cout << "         Section";
		std::cout << endl;
		std::cout << "___________________________________________________________\n";
		a >> L_start >> L_end >> teacher_name >>teacherl_name>> sect;
		while (!a.eof())
		{
			if (section == sect) {
				flag = 1;
				std::cout << teacher_name;
				std::cout << "           " << L_start;
				std::cout << "              " << L_end;
				std::cout << "              " << sect;
				std::cout << endl;
				std::cout << "___________________________________________________________\n";
				break;
			}

			a >> L_start >> L_end >> teacher_name >>teacherl_name>> sect;
		}
		if (flag == 0) {
			std::cout << "Section Not Found\n";
		}
	}


	void add_teacher_timetable(std::string x) {
		std::string IID = x;
	again:
		std::fstream file;
		file.open("TimeTableTeacher.dat", std::ios::app);
		std::cout << "Enter Lecture Time Start:\n";
		cin >> L_start;
		std::cout << "Enter Lecture Time End:\n";
		cin >> L_end;
		cout << "Enter Section(Inter_Part 1/Inter_Part 2) :\n";
		cin >> sect;

		file << "\n" << L_start << "\t" << L_end << "\t" << x << "\t" << sect;
		cout << "IimeTale Saved Successfully\n";
		std::cout << "Do you want to Input Timetable Again(y/n): ";
		char a;
		cin >> a;
		if (a == 'y') {
			goto again;
		}
		if (a == 'n') {
			return;
		}
		file.close();
	}
	
	void add_teacher_timetable() {
		std::fstream file;
		std::string sec;
		file.open("TimeTableTeacher.dat", std::ios::app);
		std::cout << "Enter Lecture Time Start:\n";
		std::cin >> sec;
		std::cout << "Enter Lecture Time Start:\n";
		cin >> L_start;
		std::cout << "Enter Lecture Time End:\n";
		cin >> L_end;
		cout << "Enter Section(Inter_Part 1/Inter_Part 2) :\n";
		cin >> sect;

		file << "\n" << L_start << "\t" << L_end << "\t" << sec << "\t" << sect;
		cout << "IimeTale Saved Successfully\n";
		std::cout << "Do you want to Input Timetable Again(y/n): ";
		char a;
		cin >> a;
		file.close();
	}

	void student_timetable() {

		std::fstream file;
		file.open("TimeTable.dat", std::ios::app);
		std::cout << "Enter Lecture Time Start:\n";
		cin >> L_start;
		std::cout << "Enter Lecture Time End:\n";
		cin >> L_end;
		cout << "Enter Section(Inter_Part 1/Inter_Part 2) :\n";
		cin >> sect;
		cout << "Enter Teacher Name:\n";
		cin >> teacher_name;

		file << "\n" << L_start << "\t" << L_end << "\t" << teacher_name << "\t" << sect;
		cout << "IimeTable Saved Successfully\n";

		file.close();
	}

	void update_student_timetable() {
		std::fstream file, temp;
		std::string section;
		std::string search_start;
		std::string search_end;
		std::string Update_L_start;
		std::string Update_L_end;
		std::string Update_teacher;
		file.open("TimeTable.dat", std::ios::in);
		temp.open("TimeTableTemp.dat", std::ios::out);
		bool flag = 0;
		std::cout << "Enter Section to update TimeTable (i.e. 2G-1)\n";
		cin >> section;
		std::cout << "Enter Lecture Starting Time to update TimeTable (i.e. 2:00)\n";
		cin >> search_start;
		std::cout << "Enter Lecture Ending Time  to update TimeTable (i.e. 2:00)\n";
		cin >> search_end;
		while (!file.eof())
		{
			file >> L_start >> L_end >> teacher_name >> sect;
			if (section == sect && search_start == L_start && search_end == L_end)
			{
				//update
				flag = 1;
				std::string section;
				std::string name;
				std::cout << "Enter Lecture Start Time:";
				std::cin >> Update_L_start;
				std::cout << "Enter Lecture End Time:";
				std::cin >> Update_L_end;
				std::cout << "Enter Teacher :";
				std::cin >> Update_teacher;
				temp << "\n" << Update_L_start << "\t" << Update_L_end << "\t" << Update_teacher << "\t" << sect; flag = 1;
			}
			else
			{
				//same content copy
				temp << "\n" << L_start << "\t" << L_end << "\t" << teacher_name << "\t" << sect;
			}
		}
		file.close();
		temp.close();

		remove("TimeTable.dat");
		rename("TimeTableTemp.dat", "TimeTable.dat");
		if (flag == 1)
		{
			std::cout << "TimeTable Successfully updated\n";
		}
		else {
			std::cout << "Sorry! Section Not Found\n";
		}

	}
	void remove_student_timetable() {
		std::fstream file, temp;
		std::string section;
		std::string search_start;
		std::string search_end;
		file.open("TimeTable.dat", std::ios::in);
		temp.open("TimeTabletemp.dat", std::ios::out);

		std::cout << "Enter Section to Remove (i.e. BEE12-B)\n";
		cin >> section;
		std::cout << "Enter Lecture Starting Time to Remove (i.e. 2:00)\n";
		cin >> search_start;
		std::cout << "Enter Lecture Ending Time  to Remove (i.e. 2:00)\n";
		cin >> search_end;
		bool flag = 0;

		while (!file.eof())
		{
			file >> L_start >> L_end >> teacher_name >> sect;
			if (section == sect && search_start == L_start && search_end == L_end)
			{
				flag = 1;
			}
			else
			{

				temp << "\n" << L_start << "\t" << L_end << "\t" << teacher_name << "\t" << sect;
			}
		}
		file.close();

		temp.close();
		if (flag == 1)
		{
			std::cout << "Successfully deleted\n";

		}
		else {

			std::cout << "Sorry! Cnic Not Found\n";

		}
		remove("TimeTable.dat");
		rename("TimeTableTemp.dat", "TimeTable.dat");

	}

};


class teachers: public timetable
{
public:
	
	std::string fst_name;
	std::string lst_name;
	std::string exp;
	std::string subj;
	std::string phone_no;
	std::string teacher_id;
	double salary_teacher;


	void add_teacher()

	{
		
		std::fstream file_obj, salary_file;
		file_obj.open("teacher.dat", std::ios::app);
		salary_file.open("TeacherSalary.dat", std::ios::app);

		if (file_obj.fail() && salary_file.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter fst_name-->";
		std::cin >> fst_name;
		std::cout << "Enter lst_name-->";
		std::cin >> lst_name;
		std::cout << "Enter Experience-->";
		std::cin >> exp;
		std::cout << "Enter Phone_no-->";
		std::cin >> phone_no;
		std::cout << "Enter Teacher ID-->";
		std::cin >> teacher_id;
		std::cout << "Enter Subject-->";
		std::cin >> subj;
		std::cout << "Enter Teacher Salary-->";
		std::cin >> salary_teacher;

		add_teacher_timetable(teacher_id);

		file_obj << "\n" << fst_name << "\t" << lst_name << "\t" << exp << "\t" << phone_no << "\t" << teacher_id << "\t" << subj;
		salary_file << "\n" << fst_name << "\t" << lst_name << "\t" << teacher_id << "\t" << salary_teacher;
		file_obj.close();
		salary_file.close();
	}

	void view_teacher()
	{
		std::fstream file_obj;
		file_obj.open("teacher.dat", std::ios::in);
		std::cout << "______________________________________________________________________________________\n";
		std::cout << "Fst_name   | " << " Lst_name   | " << "Experience  | " << " Teacher ID " << " | " << "    Phone_no    | " << "   Subject |" << "\n";
		std::cout << "______________________________________________________________________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> fst_name >> lst_name >> exp >> phone_no >> teacher_id >> subj;



			std::cout << fst_name << "     |   " << lst_name << "    |    " << exp << "   | " << teacher_id << "     |  " << phone_no << "     |     " << subj << "|" << "\n";
			std::cout << "______________________________________________________________________________________\n";

		}
		file_obj.close();
	}


	void search_teacher()
	{
		std::fstream file_obj;
		file_obj.open("teacher.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter Teacher ID To Search";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			std::cout << "______________________________________________________________________________________\n";
			std::cout << "Fst_name   | " << " Lst_name   | " << "Experience  | " << " Teacher ID " << " | " << "    Phone_no    | " << "   Subject |" << "\n";
			std::cout << "______________________________________________________________________________________\n";

			file_obj >> fst_name >> lst_name >> exp >> phone_no >> teacher_id >> subj;
			if (teacher_id == search)
			{
				flag = 1;



				std::cout << fst_name << "     |   " << lst_name << "    |    " << exp << "   | " << teacher_id << "     |  " << phone_no << "     |     " << subj << "|" << "\n";
				std::cout << "______________________________________________________________________________________\n";




			}
		}
		file_obj.close();
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}


	}

	void view_teacher_information()
	{
		std::fstream file_obj;
		file_obj.open("teacher.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		bool flag = 0;
		std::cout << "______________________________________________________________________________________\n";
		std::cout << "Fst_name   | " << " Lst_name   | " << "Experience  | " << " Teacher ID " << " | " << "    Phone_no    | " << "   Section |" << "\n";
		std::cout << "______________________________________________________________________________________\n";
		while (!file_obj.eof())
		{
			
			

			file_obj >> fst_name >> lst_name >> exp >> phone_no >> teacher_id >> subj;
			if (teacher_id == Teacher_ID)
			{
				flag = 1;



				std::cout << fst_name << "     |   " << lst_name << "    |    " << exp << "   | " << teacher_id << "     |  " << phone_no << "     |     " << subj << "|" << "\n";
				std::cout << "______________________________________________________________________________________\n";




			}
		}
		file_obj.close();
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}


	}



	void update_teacher()
	{
		std::string search;
		std::fstream file_obj, temp_obj;
		file_obj.open("teacher.dat", std::ios::in);
		temp_obj.open("temp1.dat", std::ios::out);
		std::cout << "Enter Teacher ID to Update\n";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{

			file_obj >> fst_name >> lst_name >> exp >> phone_no >> teacher_id >> subj;



			if (teacher_id == search)
			{

				std::cout << "Enter fst_name-->";
				std::cin >> fst_name;
				std::cout << "Enter lst_name-->";
				std::cin >> lst_name;
				std::cout << "Enter Experience-->";
				std::cin >> exp;
				std::cout << "Enter Phone_no-->";
				std::cin >> phone_no;
				std::cout << "Enter Subject-->";
				std::cin >> subj;


				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << exp << "\t" << phone_no << "\t" << teacher_id << "\t" << subj;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << exp << "\t" << phone_no << "\t" << teacher_id << "\t" << subj;


			}
		}
		file_obj.close();
		temp_obj.close();

		remove("teacher.dat");
		rename("temp1.dat", "teacher.dat");

		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void remove_teacher()
	{


		std::fstream ofile, dfile;
		ofile.open("teacher.dat", std::ios::in);
		dfile.open("temp1.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter Teacher ID Remove: ";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{


			ofile >> fst_name >> lst_name >> exp >> teacher_id >> phone_no >> subj;

			if (teacher_id == search)
			{
				flag = 1;
			}
			else
			{
				dfile << "\n" << fst_name << "\t" << lst_name << "\t" << exp << "\t" << phone_no << "\t" << teacher_id << "\t" << subj;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Record Successfully Deleted\n";
		}
		ofile.close();
		dfile.close();
		remove("teacher.dat");
		rename("temp1.dat", "teacher.dat");
	}
};
class teacher_portal: public teachers
{
private:
	string teacher_name;
	string teacher_phone;
	string teacher_cnic;
	string teacher_email;
	double teacher_salary;
	string teacher_address;
	int teacher_password;
	string teacher_username;
	string lecture_name;
	string time_start;
	string time_end;
public:
	void set_teacher_user(std::string a) {
		teacher_username = a;

	}

	void set_teacher_pass(int b) {
		teacher_password = b;

	}

	std::string get_teacher_user() {
		return teacher_username;

	}
	int get_teacher_pass() {
		return teacher_password;

	}

	bool teacher_login()
	{

		std::fstream file_pass_teacher, file_teacher;
		std::string username_teacher;
		int password_teacher;
		bool flag = 0;
		file_pass_teacher.open("TeacherPassword.dat", std::ios::in);
		file_teacher.open("teacher.dat", std::ios::in);

		if (file_pass_teacher.fail() && file_teacher.fail()) {
			cout << "Couldn't open the file!" << endl;
			return 0;
		}

		while (!file_teacher.eof()) {
			file_teacher >> fst_name >> lst_name >> exp >> phone_no >> teacher_id >> subj;
			if (get_teacher_user() == teacher_id) {
				Teacher_ID = teacher_id;
				Teacher_section = subj;
				cout << student_rollnumber << std::endl;
			}

			while (!file_pass_teacher.eof())
			{
				file_pass_teacher >> username_teacher >> password_teacher;

				if (get_teacher_user() == username_teacher && get_teacher_pass() == password_teacher)
				{
					// Login Successful

					flag = 1;


				}


			}

			if (flag == 0)
			{
				std::cout << "Login details are not correct\n";
				return 0;
			}
			else {
				std::cout << "Login Successful\n";
				return 1;
			}
		}
	}

		void view_teacherportal() {

		}
		void update_teacherprofile() {

		}

		void update_teacher_pass() {

		}
		void show_time_table() {

		}
	};

// Globle Variable to store section of tudent


class admission_office {
private:

	int administrator_password;
	string administrator_username;
public:
	int view_total_admissions() {

		std::string line;
		int count = 0;
		ifstream file("student.dat");
		while (getline(file, line)) {
			count++;
		}
		count = count - 1;
		return count;
			
	}
	void all_teachers() {
		std::string line;
		int count = 0;
		ifstream file("teacher.dat");
		while (getline(file, line)) {
			count++;
		}
		count = count - 1;
		std::cout << "Total Number of teachers  in college is: " << count<<std::endl;

	}
};


class revenue 
{
private:
	double cant_revenue;
	double admissionform_revenue;
	double teacher_revenue;
	double total_revenue;
	double total_expenses;
	double fee;
	std::string ID;
	double total_student_fee;

public:
	revenue() {
		 cant_revenue = 0;
		 admissionform_revenue = 0;
		 teacher_revenue = 0;
		 total_revenue = 0;
		 ID = " ";
		 total_student_fee = 0;
	}
	~revenue() {

	}
	void calculate_total_fee() {
		fstream revenue_file,file,afile;
		int a, b, c;
		file.open("StudentFee.dat", std::ios::in);
		afile.open("TotalStudentFee.dat", std::ios::app);
		if (file.fail() && afile.fail()) {
			std::cout << "File Connection Error\n";
		}

		while (!file.eof()) {
			file >> ID >> fee;
			total_student_fee += fee;
		}
		std::cout << "Enter Today Date\n";
	    std:cin >> a>> b>> c;
		afile << "\n" << a << "\t" << b << "\t" << c << "\t" << total_student_fee;

		std::cout << "Enter ToTal Monthly Fee Of Students Is: " << total_student_fee<<std::endl;

		file.close();
		afile.close();


	}
	void calculate_revenue() {
		fstream revenue_file, file, afile;
		int a, b, c;
		bool flag = 0;
		bool flag1 = 0;
		int search_a, search_b, search_c;

		file.open("TotalStudentFee.dat", std::ios::in);
		afile.open("calculate_expenses.dat", std::ios::in);
		revenue_file.open("TotalRevenue.dat", std::ios::app);


		std::cout << "Enter Date/Month/Year Which You Want To Calculate Revenue\n";
	    std:cin >> search_a >> search_b>> search_c;
		while (!file.eof()) {
			file >> a >> b >> c >> total_student_fee;
			if (search_a == a && search_b == b && search_c == c) {
				flag1 = 1;
				total_student_fee = total_student_fee;
			}
		}

		while (!afile.eof()) {
			afile >> a >> b >> c >> total_expenses;
			if (search_a == a && search_b == b && search_c == c) {
				flag = 1;
				total_expenses = total_expenses;
			}
		}

		if (flag == 1 && flag1 == 1) {
			total_revenue = total_student_fee - total_expenses;
			
			if (total_revenue <= 0) {
				std::cout << "The Have No Revenue This Month, Loss= :  " << total_revenue << std::endl;
			}
			else {
				std::cout << "The Grand Total Revenue Of College is:  " << total_revenue << std::endl;
			}
			revenue_file << "\n" << search_a << "\t" << search_b << "\t" << search_c << "\t" << total_revenue;
		}


	}
	void update_revenue() {

	}
	void view_total_revenue() {
		fstream revenue_file;
		int a, b, c;
		bool flag = 0;
		int search_a, search_b, search_c;
		revenue_file.open("TotalRevenue.dat", std::ios::in);
		std::cout << "Enter Date/Month/Year Which You Want To Calculate Revenue\n";
	std:cin >> search_a>> search_b >> search_c;
		std::cout << "                     ________________________________"<<std::endl;
		while (!revenue_file.eof()) {
			revenue_file >> a >> b >> c >> total_revenue;

			if (search_a == a && search_b == b && search_c == c) {
				std::cout << "                     | Date      | Month |  Revenue |" << std::endl;
				std::cout << "                     | " << a << "/" << b << "/" << c << "  | " << b << "     | " << total_revenue << "      | "<<endl;
			}
		}
		std::cout << "                     ________________________________" << std::endl;
		revenue_file.close();



	}
};

class student_fee {
private:
	std::string name_student;
	std::string student_id;
	std::string fee_submition_month;
	float fee;
public:
	void add_student_fee() {
		fstream file_fee;
		file_fee.open("StudentFee.dat", std::ios::app);
		if (file_fee.fail() ) {
			std::cout << "File Connection Error\n";
		}
		else{
		std::cout << "Enter Student ID: ";
		cin >> student_id;
		std::cout << "Enter Student Fee: ";
		cin >> fee;
		file_fee << "\n" << student_id << "\t" << fee;
		}
		file_fee.close();
	}
	void update_student_fee() {
		std::fstream file, temp;
		std::string search;
		file.open("StudentFee.dat", std::ios::in);
		temp.open("tempfee.dat", std::ios::out);
		if (file.fail() && temp.fail()) {
			std::cout << "File Connection Error\n";
		}
		bool flag = 0;
		std::cout << "Enter Student ID: \n";
		std::cin >> search;
		while (!file.eof())
		{
			file >> student_id >> fee;
			if (search == student_id)
			{
				std::cout << "Enter Student's Updated Fee:";
				std::cin >> fee;
				temp << "\n" << student_id << "\t" << fee ;
				flag = 1;
			}
			else
			{
				//same content copy
				temp << "\n" << student_id << "\t" << fee;
			}
		}
		file.close();
		temp.close();

		remove("StudentFee.dat");
		rename("tempfee.dat", "StudentFee.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
		else {
			std::cout << "Sorry! ID Not Found\n";
		}

	}
	void search_student_fee() {
		std::fstream file;
		std::string search;
		file.open("StudentFee.dat", std::ios::in);
		if (file.fail()) {
			std::cout << "File Connection Error\n";
		}
		bool flag = 0;
		std::cout << "Enter Student ID: \n";
		std::cin >> search;
		while (!file.eof())
		{
			file >> student_id >> fee;
			if (search == student_id)
			{
				std::cout << "Student ID: " << student_id << " | " << "Student Fee: " << fee;
				flag = 1;
			}
		}
		file.close();
		if (flag == 0)
		{
			std::cout << "ID Not Found\n";
		}
	}
	void remove_student_fee() {
		std::fstream file, temp;
		std::string search;
		file.open("StudentFee.dat", std::ios::in);
		temp.open("tempfee.dat", std::ios::out);
		if (file.fail() && temp.fail()) {
			std::cout << "File Connection Error\n";
		}
		bool flag = 0;
		std::cout << "Enter Student ID: \n";
		std::cin >> search;
		while (!file.eof())
		{
			file >> student_id >> fee;
			if (search == student_id)
			{
				flag = 1;
			}
			else
			{
				temp << "\n" << student_id << "\t" << fee;
			}
		}
		file.close();
		temp.close();

		remove("StudentFee.dat");
		rename("tempfee.dat", "StudentFee.dat");
		if (flag == 1)
		{
			std::cout << "Successfully Deleted\n";
		}
		else {
			std::cout << "Sorry! ID Not Found\n";
		}
	}
	void view_student_fee() {
		std::fstream file;
		file.open("StudentFee.dat", std::ios::in);
		if (file.fail()) {
			std::cout << "File Connection Error\n";
		}
		std::cout << "_______________________________________________\n";
		while (!file.eof())
		{
			file >> student_id >> fee;
				std::cout << "Student ID: " << student_id << " | " << "Student Fee: " << fee<<std::endl;
				std::cout << "_______________________________________________\n";
		
		}
		file.close();
		file.close();
	}
};

class student_result: public students
{
private:
	double Tclass_marks;
	double class_marks;
	double Tmoke_marks;
	double moke_marks;
	double pre_boared_marks;
	double total_pre_marks;
	char grade;
public:
	

	void add_result_student() {
		std::fstream file_obj, file_update;
		double new_class_marks;
		double new_moke_marks;
		double newpre_boared_marks; 
		std::string search_id_student;
		file_obj.open("StudentResult.dat", std::ios::in);
		file_update.open("StudentResultUpdate.dat", std::ios::out);
		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}
		std::cout << "1. Final Exam Marks\n";
		std::cout << "2. Mid Exam Marks\n";
		std::cout << "3. Class Test Marks;\n";
		int x;
		std::cout << "Your Choice: ";
		cin >> x;
		student_result obj;


		std::cout << "Enter Student's Roll Number: ";
		std::cin >> search_id_student;

		if (x == 1) {
			while (!file_obj.eof()) {
				file_obj >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				if (id_student == search_id_student) {
					std::cout << "Enter Student's Final Exam Marks: ";
					std::cin >> new_moke_marks;
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << new_moke_marks << "\t" << pre_boared_marks << "\t" << class_marks;
				}
				else {
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << pre_boared_marks << "\t" << class_marks;
				}
			}
		}
		
		if (x == 2) {
			while (!file_obj.eof()) {
				file_obj >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				if (id_student == search_id_student) {

					std::cout << "Enter Student's Mid Exam Marks: ";
					std::cin >> newpre_boared_marks;
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << newpre_boared_marks << "\t" << class_marks;
				}
				else {
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << pre_boared_marks << "\t" << class_marks;
				}
			}
		}
		if (x == 3) {

			while (!file_obj.eof()) {
				file_obj >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				if (id_student == search_id_student) {
					std::cout << "Enter Student's Class Exam Marks: ";
					std::cin >> new_class_marks;
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << pre_boared_marks << "\t" << new_class_marks;
				}
				else {
					file_update << "\n" << student_fname << "\t" << student_lname << "\t" << id_student << "\t" << moke_marks << "\t" << pre_boared_marks << "\t" << class_marks;
				}
			}
		}


		
		file_obj.close();
		file_update.close();
		remove("StudentResult.dat");
		rename("StudentResultUpdate.dat", "StudentResult.dat");
	}
	void search_result_student() {
		fstream file, grade;
		bool flag = 0;
		bool flag1 = 1;
		file.open("StudentResult.dat", std::ios::in);
		grade.open("grade.dat", std::ios::in);
		int y;
		std::cout << "1. Student's Obtained Marks\n";
		std::cout << "2. Student's Percentage\n";
		cin >> y;
		if (y == 1) {
			
			std::cout << "                       " << "==========================================================================\n";
			std::cout << "                      " << " |Name              | " << " Roll Number    | " << "Final Exam |  " << "Mid Board  |" << "Class Marks|" << "\n";

			std::cout << "                       " << "==========================================================================\n";
			while (!file.eof()) {
				
				file >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				if (student_rollnumber == id_student) {
					flag = 1;
					// Codefor maintaining table design
					int len = student_fname.length();
					int len1 = student_lname.length();
					int len_c = len + len1 + 1;
					int choice = 15 - len_c;
					char a;
					if (choice == 1) {
						a = ' ';
					}
					else if (choice == 2) {
						a = '  ';
					}
					else if (choice == 3) {
						a = '   ';
					}
					else if (choice == 4) {
						a = '    ';
					}
					else {
						a = '    ';
					}

					if (len_c < 15) {
						student_lname.push_back(a);
					}

					//////////////////////

					std::cout << "                       " << "|" << student_fname << " " << student_lname << "       | " << id_student << "         |    " << moke_marks << "         |     " << pre_boared_marks << "       |    " << class_marks << "   |" << std::endl;



					std::cout << setw(98) << " __________________________________________________________________________\n";
				}
				
			}
			if (flag == 0) {
				std::cout << "Something Went Wrong\n";
			}
		}

		if (y == 2) {
			double percent = 0;
			char gra;
			std::cout << "                       " << "==============================================\n";
			std::cout << "                       " << "| Roll Number    | " << "Percentage |  " << "Grade       |\n";

			std::cout << "                       " << "==============================================\n";
			while (!grade.eof()) {

				grade >> id_student >> percent >> gra;
				if (student_rollnumber == id_student) {
					std::cout << "                       " << "|" << id_student << "          |    " << percent << "    |   " << gra << "          |" << std::endl;



					std::cout << setw(70) << " ______________________________________________\n";
                }

			
			}
		}


		file.close();
		grade.close();
	}

	void search_result_student(std::string h) {
		std::string roLL_no = h;
		fstream file, grade;
		bool flag = 0;
		bool flag1 = 1;
		file.open("StudentResult.dat", std::ios::in);
		grade.open("grade.dat", std::ios::in);
		int y;
		std::cout << "1. Student's Obtained Marks\n";
		std::cout << "2. Student's Percentage\n";
		cin >> y;
		if (y == 1) {

			std::cout << "                       " << "==========================================================================\n";
			std::cout << "                      " << " |Name            | " << " Roll Number    | " << "Moke Exam |  " << "Pre Board  |" << "Class Marks|" << "\n";

			std::cout << "                       " << "==========================================================================\n";
			while (!file.eof()) {

				file >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				if (roLL_no == id_student) {
					flag = 1;
					// Codefor maintaining table design
					int len = student_fname.length();
					int len1 = student_lname.length();
					int len_c = len + len1 + 1;
					int choice = 15 - len_c;
					char a;
					if (choice == 1) {
						a = ' ';
					}
					else if (choice == 2) {
						a = '  ';
					}
					else if (choice == 3) {
						a = '   ';
					}
					else if (choice == 4) {
						a = '    ';
					}
					else {
						a = '    ';
					}

					if (len_c < 15) {
						student_lname.push_back(a);
					}

					//////////////////////

					std::cout << "                       " << "|" << student_fname << " " << student_lname << " | " << id_student << "    |    " << moke_marks << "     |     " << pre_boared_marks << "      |    " << class_marks << "     |" << std::endl;



					std::cout << setw(98) << " __________________________________________________________________________\n";
				}

			}
			if (flag == 0) {
				std::cout << "Something Went Wrong\n";
			}
		}

		if (y == 2) {
			double percent = 0;
			char gra;
			std::cout << "                       " << "==============================================\n";
			std::cout << "                       " << "| Roll Number    | " << "Percentage |  " << "Grade       |\n";

			std::cout << "                       " << "==============================================\n";
			while (!grade.eof()) {

				grade >> id_student >> percent >> gra;
				if (roLL_no == id_student) {
					std::cout << "                       " << "|" << id_student << "    |    " << percent << "    |   " << gra << "          |" << std::endl;



					std::cout << setw(70) << " ______________________________________________\n";
				}


			}
		}


		file.close();
		grade.close();
	}


	void update_result_student() {

	}
	void delete_result_student() {

	}
	void view_result_student() {
		fstream file,grade;
		file.open("StudentResult.dat", std::ios::in);
		grade.open("grade.dat", std::ios::in);
		int y;
		std::cout << "1. Student's Obtained Marks\n";
		std::cout << "2. Student's Percentage\n";
		cin >> y;
		if (y == 1) {
			std::cout << "                       " << "==========================================================================\n";
			std::cout << "                      " << " |Name            | " << " Roll Number    | " << "Moke Exam |  " << "Pre Board | " << "Class Marks|" << "\n";

			std::cout << "                       " << "==========================================================================\n";
			while (!file.eof()) {

				file >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
				// Code for maintaining table design
				int len = student_fname.length();
				int len1 = student_lname.length();
				int len_c = len + len1 + 1;
				int choice = 15 - len_c;
				char a;
				if (choice == 1) {
					 a = ' ';
				}
				else if (choice == 2) {
					a = '  ';
				}
				else if (choice == 3) {
					a = '   ';
				}
				else if (choice == 4) {
					 a = '    ';
				}
				else {
					a = '    ';
				}

				if (len_c < 15) {
					student_lname.push_back(a);
				}

				//////////////////////

				std::cout << "                       " << "|" << student_fname << " " << student_lname << " | " << id_student << "    |    " << moke_marks << "     |    " << pre_boared_marks << "      |    " << class_marks << "      |" << std::endl;



				std::cout << setw(98) << " __________________________________________________________________________\n";
			}
		}
		if (y == 2) {
			double percent = 0;
			char gra;
			std::cout << "                       " << "==============================================\n";
			std::cout << "                       "  << "| Roll Number    | " << "Percentage |  " << "Grade       |\n";

			std::cout << "                       " << "==============================================\n";
			while (!grade.eof()) {

				grade >> id_student >> percent >> gra ;
				// Codefor maintaining table design
				

				//////////////////////

				std::cout << "                       " << "|" << id_student << "    |    " << percent << "    |   " << gra <<"          |"<< std::endl;



				std::cout << setw(70) << " ______________________________________________\n";
			}
		}

		
		file.close();
		grade.close();
	}
	void calculate_grade() {
		double moke_avr;
		double preboard_avr;
		double class_avr;
		double total_avr;
		fstream grade_file, file_obj;
		grade_file.open("grade.dat", std::ios::app);
		file_obj.open("StudentResult.dat", std::ios::in);
		while (!file_obj.eof())
		{
			file_obj >> student_fname >> student_lname >> id_student >> moke_marks >> pre_boared_marks >> class_marks;
			moke_avr = (moke_marks / 100) * 30;
			preboard_avr = (pre_boared_marks / 100) * 50;
			class_avr = (class_marks / 100) * 20;
			total_avr = moke_avr + preboard_avr + class_avr;
			if (total_avr > 80)
			{
				grade = 'A';
			}

			else if (total_avr < 80 && total_avr >= 70)

			{
				grade = 'B';
			}

			else if (total_avr < 70 && total_avr >= 65)
			{
				grade = 'C';
			}

			else if (total_avr < 65 && total_avr >= 50)
			{
				grade = 'D';
			}
			else
			{
				grade = 'F';
			}
			grade_file << "\n" << id_student << "\t" << total_avr << "\t" << grade;

		}
	}
};
class Attendance
{
private:
	std::string name;
	std::string teacher_ID;
	std::string present_status;
	int staff_enterance_time;
	int staff_exit_time;
	int day, month, year;
public:
	void add_StaffAttendence()

	{
		std::fstream file_obj;
		file_obj.open("TeacherAttendence.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}
		std::cout << "Enter Date/Day/Year: \n";
		cin >> day >> month >> year;
		std::cout << "Enter Your ID: ";
		std::cin >> teacher_ID;
		std::cout << "Present Status (P Or A): ";
		std::cin >> present_status;


		file_obj << "\n" << day << "\t" << month << "\t" << year<<"\t"<< teacher_ID << "\t" << present_status;
		file_obj.close();
	}

	void view_StaffAttendence()
	{
		std::fstream file_obj;
		file_obj.open("TeacherAttendence.dat", std::ios::in);
		std::cout << "                                 ________________________\n";;
		std::cout << "                                 |  Date     | " << " Status  |" << "\n";
		std::cout << "                                 ________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> day >> month >> year >> teacher_ID >> present_status;



			std::cout << "                                 | " << day << "/" << month << "/" << year << "  |      " << present_status << "   |" << "\n";
			std::cout << "                                 ________________________\n";

		}
		file_obj.close();
	}
	void view_personal_StaffAttendence()
	{
		std::fstream file_obj;
		file_obj.open("TeacherAttendence.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		bool flag = 0;
		std::cout << "                                       ________________________\n";;
		std::cout << "                                       |  Date     | " << " Status  |" << "\n";
		std::cout << "                                       ________________________\n";
		while (!file_obj.eof())
		{
			

			file_obj >> day >> month >> year >> teacher_ID >> present_status;
			if (teacher_ID == Teacher_ID)
			{
				flag = 1;

				std::cout << "                                       | " << day << "/" << month << "/" << year << "  |      " << present_status << "   |" << "\n";
				std::cout << "                                       ________________________\n";


			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}

	void search_StaffAttendence()
	{
		std::fstream file_obj;
		file_obj.open("TeacherAttendence.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter Teacher ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			std::cout << "                                 ________________________\n";;
		
			file_obj >> day >> month >> year >> teacher_ID >> present_status;
			if (teacher_ID == search)
			{
				flag = 1;
				std::cout << "                                 |  Date     | " << " Status  |" << "\n";
				std::cout << "                                 ________________________\n";
				std::cout << "                                 | " << day << "/" << month << "/" << year << "  |      " << present_status << "   |" << "\n";
				std::cout << "                                 ________________________\n";


			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}



	void update_StaffAttendence()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("TeacherAttendence.dat", std::ios::in);
		temp_obj.open("tempAttendence.dat", std::ios::out);
		std::string search;
		int a, b, c;
		std::cout << "Enter Staff Member Id To Update Attendence\n";
		cin >> search;
		std::cout << "Enter Staff Member Id To Update Attendence\n";
		cin >> a >> b >> c;
		bool flag = 0;
		while (!file_obj.eof())
		{

			file_obj >> day >> month >> year >> teacher_ID >> present_status;



			if (search == teacher_ID && day == a && month == b && year == c)
			{

				std::cout << "Enter Present Status (P or A): ";
				std::cin >> present_status;


				temp_obj << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("TeacherAttendence.dat");
		rename("tempAttendence.dat", "TeacherAttendence.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
		else {
			std::cout << "Record Nt Found\n";
		}
	}

	void remove_StaffAttendence()
	{

		std::fstream ofile, dfile;
		ofile.open("TeacherAttendence.dat", std::ios::in);
		dfile.open("tempAttendence.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int a, b, c;
		std::string search;
		std::cout << "Enter Teacher ID: ";
		std::cin >> search;
		std::cout << "Enter Staff Member Id To Update Attendence\n";
		cin >> a >> b >> c;
		bool flag = 0;
		while (!ofile.eof())
		{


			ofile >> day >> month >> year >> teacher_ID >> present_status;

			if (search == teacher_ID && day == a && month == b && year == c)
			{
				flag = 1;
			}
			else
			{
				dfile << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Attendence Successfully Deleted\n";
		}
		ofile.close();
		dfile.close();
		remove("TeacherAttendence.dat");
		rename("tempAttendence.dat", "TeacherAttendence.dat");

	}


	void add_StudentAttendence()

	{
		std::fstream file_obj;
		file_obj.open("StudentAttendence.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}
		std::cout << "Enter Date/Day/Year: \n";
		cin >> day >> month >> year;
		std::cout << "Enter Student ID: ";
		std::cin >> teacher_ID;
		std::cout << "Present Status (P Or A): ";
		std::cin >> present_status;


		file_obj << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;
		file_obj.close();
	}

	void view_StudentAttendence()
	{
		std::fstream file_obj;
		file_obj.open("StudentAttendence.dat", std::ios::in);
		std::cout<<setw(25)<<"     Date"<<"      "<<"   Student ID"<<"    "<<"   Status"<<setw(10)<<"\n";
		while (!file_obj.eof())
		{
			file_obj >> day >> month >> year >> teacher_ID >> present_status;
		std::cout<<setw(25)<<day<<"/"<<month<<"/"<< year<<setw(10)<<teacher_ID<<setw(10)<< present_status <<setw(10)<<"\n";

		}
		file_obj.close();
	}
	void view_personal_StudentAttendence()
	{
		std::fstream file_obj;
		file_obj.open("StudentAttendence.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		bool flag = 0;
		std::cout << "                                 ________________________\n";;
		std::cout << "                                 |  Date     |  " << " Status |" << "\n";
		std::cout << "                                 ________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> day >> month >> year >> teacher_ID >> present_status;
			if (student_rollnumber == teacher_ID)
			{
				flag = 1;

				std::cout << "                                 | " << day << "/" << month << "/" << year << "  |     " << present_status << "    |" << "\n";
				std::cout << "                                 ________________________\n";


			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}

	void search_StudentAttendence()
	{
		std::fstream file_obj;
		file_obj.open("StudentAttendence.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter Student ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			std::cout << "                                 ________________________\n";
			std::cout << "                                 |  Date     | " << " Status  |" << "\n";
			std::cout << "                                 ________________________\n";

			file_obj >> day >> month >> year >> teacher_ID >> present_status;
			if (teacher_ID == search)
			{
				flag = 1;

				std::cout << "                                 | " << day << "/" << month << "/" << year << "  |      " << present_status << "   |" << "\n";
				std::cout << "                                 ________________________\n";


			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}



	void update_StudentAttendence()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("StudentAttendence.dat", std::ios::in);
		temp_obj.open("tempAttendence.dat", std::ios::out);
		std::string search;
		int a, b, c;
		std::cout << "Enter STudent Id To Update Attendence\n";
		cin >> search;
		std::cout << "Enter Student Id To Update Attendence\n";
		cin >> a >> b >> c;
		bool flag = 0;
		while (!file_obj.eof())
		{

			file_obj >> day >> month >> year >> teacher_ID >> present_status;



			if (search == teacher_ID && day == a && month == b && year == c)
			{

				std::cout << "Enter Present Status (P or A): ";
				std::cin >> present_status;


				temp_obj << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("StudentAttendence.dat");
		rename("tempAttendence.dat", "StudentAttendence.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
		else {
			std::cout << "Record Not Found\n";
		}
	}

	void remove_StudentAttendence()
	{

		std::fstream ofile, dfile;
		ofile.open("StudentAttendence.dat", std::ios::in);
		dfile.open("tempAttendence.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int a, b, c;
		std::string search;
		std::cout << "Enter Student ID: ";
		std::cin >> search;
		std::cout << "Enter Student Id To Update Attendence\n";
		cin >> a >> b >> c;
		bool flag = 0;
		while (!ofile.eof())
		{


			ofile >> day >> month >> year >> teacher_ID >> present_status;

			if (search == teacher_ID && day == a && month == b && year == c)
			{
				flag = 1;
			}
			else
			{
				dfile << "\n" << day << "\t" << month << "\t" << year << "\t" << teacher_ID << "\t" << present_status;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Attendence Successfully Deleted\n";
		}
		ofile.close();
		dfile.close();
		remove("StudentAttendence.dat");
		rename("tempAttendence.dat", "StudentAttendence.dat");

	}
	void total_staff_absence() {

	}
};

class Accountant 
{
private:
	string accountant_name;
	string accountant_cnic;
	string accountant_phone;
	string accountant_email;
	string accountant_username;
	int accountant_pass;
public:
	void set_accountant_user(std::string a) {
		accountant_username = a;

	}

	void set_accountant_pass(int b) {
		accountant_pass = b;

	}

	std::string get_accountant_user() {
		return accountant_username;

	}
	int get_accountant_pass() {
		return accountant_pass;

	}

	bool accountant_login()
	{

		std::fstream file_pass_accountant;
		std::string username_accountant;
		int password_accountant;
		bool flag = 0;
		file_pass_accountant.open("accountantPassword.dat", std::ios::in);

		if (file_pass_accountant.fail()) {
			cout << "Couldn't open the file!" << endl;
			return 0;
		}



		while (!file_pass_accountant.eof())
		{
			file_pass_accountant >> username_accountant >> password_accountant;

			if (get_accountant_user() == username_accountant && get_accountant_pass() == password_accountant)
			{
				// Login Successful

				flag = 1;


			}


		}

		if (flag == 0)
		{
			std::cout << "Login details are not correct\n";
			return 0;
		}
		else {
			std::cout << "Login Successful\n";
			return 1;
		}
	}

	void change_accountant_password() {

	}

};


class College_Expenditure
{
private:
	double total_expenditure;
	double electricitybill;
	double furnitureexpense;
	double otherexpense;
	double tranport_expenses;
	std::string expense_name;
	int* p;
	double expen;
public:
	College_Expenditure() {
		total_expenditure = 0;
		electricitybill = 0;
		furnitureexpense = 0;
		otherexpense = 0;
		tranport_expenses = 0;
		expense_name = " ";
		expen = 0;
	}
	~College_Expenditure() {

	}
	template <class a, class b, class c>
	void college_expense(a elect, b furn, c other) {
		std::fstream file_obj;
		file_obj.open("TotalExpenditure.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}


		file_obj << "\n" <<"Electricity_Bill"<<"\t"<< elect;
		file_obj << "\n" << "Furniture_Expenses" << "\t" << furn;
		file_obj << "\n" << "Other_Expenses" << "\t" << other;
		file_obj.close();
	}

	void view_total_expenditure()
	{
		std::fstream file_obj;

		file_obj.open("TotalExpenditure.dat", std::ios::in);
		std::cout << "                        ___________________________________________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> expense_name >> expen;

			std::cout << "                        Expense :  " <<expense_name << " | "<<"Monthly Expenditure:  "<< expen << std::endl;

			std::cout << "                        ___________________________________________________________\n";
		}
		file_obj.close();
	}
	void update_expendture() {
		int Bus_id;
		std::fstream file_obj, temp_obj;
		file_obj.open("TotalExpenditure.dat", std::ios::in);
		temp_obj.open("tempe.dat", std::ios::out);
		if (file_obj.fail() && temp_obj.fail()) {
			std::cout << "SomeThing Went Wrong\n";
		}
			std::cout << "Enter Updated Monthly Electricity Bill\n";
			std::cin >> electricitybill;
			std::cout << "Enter Updated Monthly Furniture Expenses\n";
			std::cin >> furnitureexpense;
			std::cout << "Enter Updated Monthly Transport Expenditure\n";
			std::cin >> tranport_expenses;
			std::cout << "Enter Updated Other College Expenditure\n";
			std::cin >> otherexpense;

			temp_obj << "\n" << "Transport_Expenditure" << "\t" << tranport_expenses;
			temp_obj << "\n" << "Electricity_Bill" << "\t" << electricitybill;
			temp_obj << "\n" << "Furniture_Expenses" << "\t" << furnitureexpense;
			temp_obj << "\n" << "Other_Expenses" << "\t" << otherexpense;
			

		file_obj.close();
		temp_obj.close();

		remove("TotalExpenditure.dat");
		rename("tempe.dat", "TotalExpenditure.dat");
		std::cout << "Successfully updated\n";


	}
	double operator ++() {
		int x, y, z;
		std::fstream file_obj,cal;
		file_obj.open("TotalExpenditure.dat", std::ios::in);
		cal.open("calculate_expenses.dat", std::ios::app);
		std::cout << "Enter Tooday Date\n";
		cin >> x >> y >> z;

		while (!file_obj.eof())
		{
			file_obj >> expense_name >> expen;
			total_expenditure += expen;
			
		}
		//std::cout << "The Total Monthly Expenditure is: " << total_expenditure;
		cal << "\n" << x << "\t" << y << "\t" << z << "\t" << total_expenditure;
		file_obj.close();
		cal.close();
		return total_expenditure;
	}
};

class salary
{
	std::string fst_name;
	std::string lst_name;
	std::string id;
	double lsalary_of_teacher;
	double total_salary;
public:
	salary() {
		fst_name = " " ;
		lst_name = " ";
		id = " ";
		lsalary_of_teacher = 0;
		total_salary = 0;
	}
	~salary() {
		std::cout << ".";
	}
	void operator ++() {
		std::fstream file,calculate;
		file.open("TeacherSalary.dat", std::ios::in);
		calculate.open("TotalExpenditure.dat", std::ios::app);
		if (file.fail() && calculate.fail()) {
			std::cout << "Something Went Wrong\n";
		}
		while (!file.eof()) {
			file >> fst_name >> lst_name >> id >> lsalary_of_teacher;
			total_salary += lsalary_of_teacher;
		}
		std::cout << "Total Salary Of Teachers, Workers, Staff is: " << total_salary<<endl;
		calculate <<"\n"<< "Salary" << "\t" << total_salary;

		file.close();
		calculate.close();
	}
	void add_salary()

	{
		std::fstream file_obj;
		file_obj.open("TeacherSalary.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter fst_name-->";
		std::cin >> fst_name;
		std::cout << "Enter lst_name-->";
		std::cin >> lst_name;
		std::cout << "Enter ID-->";
		std::cin >> id;
		std::cout << "Enter salary_of_teacher-->";
		std::cin >> lsalary_of_teacher;


		file_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
		file_obj.close();
	}

	void view_salary()
	{
		std::fstream file_obj;
		file_obj.open("TeacherSalary.dat", std::ios::in);
		std::cout << "______________________________________________________________\n";
		std::cout << "|  Fst_name | " << " lst_name   | " << "ID        |" << "    Salary_of_teacher   |" << "\n";
		std::cout << "|____________________________________________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;

			
			
			std::cout << "|  " << fst_name << "   |   " << lst_name << "    |    " << id << "|          " << lsalary_of_teacher << "|" << "\n";
			std::cout << "_____________________________________________________________\n";

		}
		file_obj.close();
	}


	void search_salary()
	{
		std::fstream file_obj;
		file_obj.open("TeacherSalary.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			

			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;
			if (id == search)
			{
				flag = 1;
				std::cout << "_______________________________________________________________\n";
				std::cout << "|  Fst_name | " << " lst_name   | " << "ID        |" << "    Salary_of_teacher   |" << "\n";
				std::cout << "|_____________________________________________________________\n";
				std::cout << "|  " << fst_name << "   |   " << lst_name << "    |    " << id << "|          " << lsalary_of_teacher <<"|"<< "\n";
				std::cout << "_____________________________________________________________\n";



			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}



	void update_salary()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("TeacherSalary.dat", std::ios::in);
		temp_obj.open("temp2.dat", std::ios::out);
		std::string search;
		std::cout << "Enter Staff Member Id To Update Salary\n";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{

			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;



			if (search == id)
			{

				std::cout << "Enter salary_of_teacher-->";
				std::cin >> lsalary_of_teacher;


				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("TeacherSalary.dat");
		rename("temp2.dat", "TeacherSalary.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void remove_salary()
	{
		std::fstream ofile, dfile;
		ofile.open("TeacherSalary.dat", std::ios::in);
		dfile.open("temp3.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{
			ofile >> fst_name >> lst_name >> id >> lsalary_of_teacher;

			if (id == search)
			{
				flag = 1;
			}
			else
			{
				dfile << std::endl << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Record Successfully Deleted\n";
		}
		ofile.close();
		dfile.close();
		remove("TeacherSalary.dat");
		rename("temp3.dat", "TeacherSalary.dat");
	}

//
	void worker_add_salary()

	{
		std::fstream file_obj;
		file_obj.open("WorkerSalary.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter fst_name-->";
		std::cin >> fst_name;
		std::cout << "Enter lst_name-->";
		std::cin >> lst_name;
		std::cout << "Enter ID-->";
		std::cin >> id;
		std::cout << "Enter Worker Salary-->";
		std::cin >> lsalary_of_teacher;


		file_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
		file_obj.close();
	}

	void worker_view_salary()
	{
		std::fstream file_obj;
		file_obj.open("WorkerSalary.dat", std::ios::in);
		std::cout << "______________________________________________________________\n";
		std::cout << "|  Fst_name | " << " lst_name   | " << "ID        |" << "    Salary_of_teacher   |" << "\n";
		std::cout << "|____________________________________________________________\n";
		while (!file_obj.eof())
		{
			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;



			std::cout << "|  " << fst_name << "   |   " << lst_name << "    |    " << id << "|          " << lsalary_of_teacher << "|" << "\n";
			std::cout << "_____________________________________________________________\n";

		}
		file_obj.close();
	}


	void worker_search_salary()
	{
		std::fstream file_obj;
		file_obj.open("WorkerSalary.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{


			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;
			if (id == search)
			{
				flag = 1;
				std::cout << "_______________________________________________________________\n";
				std::cout << "|  Fst_name | " << " lst_name   | " << "ID        |" << "    Salary_of_teacher   |" << "\n";
				std::cout << "|_____________________________________________________________\n";
				std::cout << "|  " << fst_name << "   |   " << lst_name << "    |    " << id << "|          " << lsalary_of_teacher << "|" << "\n";
				std::cout << "_____________________________________________________________\n";



			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();

	}



	void worker_update_salary()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("WorkerSalary.dat", std::ios::in);
		temp_obj.open("temp2.dat", std::ios::out);
		std::string search;
		std::cout << "Enter Worker Id To Update Salary\n";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{

			file_obj >> fst_name >> lst_name >> id >> lsalary_of_teacher;



			if (search == id)
			{

				std::cout << "Enter Worker Salary-->";
				std::cin >> lsalary_of_teacher;


				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("WorkerSalary.dat");
		rename("temp2.dat", "WorkerSalary.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void worker_remove_salary()
	{
		std::fstream ofile, dfile;
		ofile.open("WorkerSalary.dat", std::ios::in);
		dfile.open("temp3.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter ID: ";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{
			ofile >> fst_name >> lst_name >> id >> lsalary_of_teacher;

			if (id == search)
			{
				flag = 1;
			}
			else
			{
				dfile << std::endl << fst_name << "\t" << lst_name << "\t" << id << "\t" << lsalary_of_teacher;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Record Successfully Deleted\n";
		}
		ofile.close();
		dfile.close();
		remove("WorkerSalary.dat");
		rename("temp3.dat", "WorkerSalary.dat");
	}


};

class library
{
	string books;
	string book_name;
	int total_issue_books;
	std::string student_id;
	std::string student_name;
	int book_num;
	std::string book_author;
	std::string library_username;
	int library_pass;
public:

	void set_library_user(std::string a) {
		library_username = a;

	}

	void set_library_pass(int b) {
		library_pass = b;

	}

	std::string get_library_user() {
		return library_username;

	}
	int get_library_pass() {
		return library_pass;

	}

	bool library_login()
	{
			if (get_library_user() == "librarian" && get_library_pass() == 1122)
			{

				std::cout << "Login Successful\n";
				return 1;


		    }
		else {
			std::cout << "Login Details are not Correct\n";
			return 0;
		}
	}
	void add_book()

	{
		std::fstream file_obj;
		file_obj.open("book.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter book_num-->";
		std::cin >> book_num;
		std::cout << "Enter book_name-->";
		std::cin >> book_name;
		std::cout << "Enter book_author-->";
		std::cin >> book_author;

		file_obj << "\n" << book_num << "\t" << book_name << "\t" << book_author;
		file_obj.close();
	}

	void view_book()
	{
		std::fstream file_obj;
		file_obj.open("book.dat", std::ios::in);

		std::cout << "__________________________________________\n";
		std::cout << "|Book Num  | " << " Book name    | " << "Book Author  " << "\n";
		std::cout << "__________________________________________ \n";
		file_obj >> book_num >> book_name >> book_author;
		while (!file_obj.eof())
		{

			std::cout << "|" << book_num << "       |   " << book_name << "     |    " << book_author << "\n";
			std::cout << "__________________________________________\n";

			file_obj >> book_num >> book_name >> book_author;



		}
		file_obj.close();
	}


	void search_book()
	{
		std::fstream file_obj;
		file_obj.open("book.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter book_num";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{


			file_obj >> book_num >> book_name >> book_author;
			if (book_num == search)
			{
				flag = 1;

				std::cout << "__________________________________________\n";
				std::cout << "|Book_num  | " << " book_name   | " << "book_author  |" << "\n";
				std::cout << "|_______________________________________ |\n";
				std::cout << "|" << book_num << "       |   " << book_name << "     |    " << book_author << "   |" << "\n";
				std::cout << "_________________________________________\n";



			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();
	}



	void update_book()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("book.dat", std::ios::in);
		temp_obj.open("temp.dat", std::ios::out);

		bool flag = 0;
		while (!file_obj.eof())
		{
			file_obj >> book_num >> book_name >> book_author;

			if (book_num == book_num)
			{

				std::cout << "Enter book_num-->";
				std::cin >> book_num;
				std::cout << "Enter  book_name-->";
				std::cin >> book_name;
				std::cout << "Enter  book_author-->";
				std::cin >> book_author;


				temp_obj << "\n" << book_num << "\t" << book_name << "\t" << book_author;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << book_num << "\t" << book_name << "\t" << book_author;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("book.dat");
		rename("temp.dat", "book.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void remove_book()
	{


		std::fstream ofile, dfile;
		ofile.open("book.dat", std::ios::in);
		dfile.open("temp.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter book_num";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{

			ofile >> book_num >> book_name >> book_author;
			if (book_num == search)
			{
				flag = 1;
			}
			else
			{
				dfile << "\n" << book_num << "\t" << book_name << "\t" << book_author;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else{
			std::cout << "Book Deleted" << std::endl;
		}
		
		ofile.close();
		dfile.close();
		remove("book.dat");
		rename("temp.dat", "book.dat");
	}
	void total_library_expenditure() {

	}

	void add_issue_book()

	{
		std::fstream file_obj;
		file_obj.open("IssueBooks.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter student_id-->";
		std::cin >> student_id;
		std::cout << "Enter student_name-->";
		std::cin >> student_name;
		std::cout << "Enter book_name-->";
		std::cin >> book_name;

		file_obj << "\n" << student_id << "\t" << student_name << "\t" << book_name;
		file_obj.close();
	}

	void view_issue_book()
	{
		std::fstream file_obj;
		file_obj.open("book1.dat", std::ios::in);
		std::cout << "___________________________________________\n";
		std::cout << "|student_id | " << " student_name   | " << "book_name |" << "\n";
		std::cout << "|_________________________________________||\n";
		while (!file_obj.eof())
		{
			file_obj >> student_id >> student_name >> book_name;


			std::cout << "|" << student_id << "       |   " << student_name << "         |    " << book_name << " ||" << "\n";
			std::cout << "____________________________________________\n";

		}
		file_obj.close();
	}


	void search_issue_book()
	{
		std::fstream file_obj;
		file_obj.open("IssueBooks.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search;
		std::cout << "Enter book_num";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{


			file_obj >> student_id >> student_name >> book_name;
			if (student_id == search)
			{
				flag = 1;

				std::cout << "___________________________________________\n";
				std::cout << "|student_id | " << " student_name   | " << "book_name | " << "\n";
				std::cout << "|_________________________________________|\n";
				std::cout << "|" << student_id << "       |   " << student_name << "         |    " << book_name << " |" << "\n";
				std::cout << "____________________________________________\n";



			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		file_obj.close();
	}




	void update_issue_book()
	{

		std::fstream file_obj, temp_obj;
		file_obj.open("IssueBooks.dat", std::ios::in);
		temp_obj.open("temp1.dat", std::ios::out);
		std::cout << "Enter Student ID To Update Issue Book\n";
		std::string search;
		getline(cin, search);
		bool flag = 0;
		while (!file_obj.eof())
		{
			file_obj >> student_id >> student_name >> book_name;

			if (search == student_id)
			{

				std::cout << "Enter student_id-->";
				std::cin >> student_id;
				std::cout << "Enter  student_name-->";
				std::cin >> student_name;
				std::cout << "Enter  book_name-->";
				std::cin >> book_name;


				temp_obj << "\n" << student_id << "\t" << student_name << "\t" << book_name;
				flag = 1;
			}
			else
			{
				temp_obj << "\t" << student_id << "\t" << student_name << "\t" << book_name;


			}
		}
		file_obj.close();
		temp_obj.close();

		remove("IssueBooks.dat");
		rename("temp1.dat", "IssueBooks.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}


	void remove_issue_book()
	{


		std::fstream ofile, dfile;
		ofile.open("IssueBooks.dat", std::ios::in);
		dfile.open("temp1.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		std::string search,search1;
		std::cout << "Enter Student ID: ";
		std::cin >> search;
		std::cout << "If Student Return Book in Due Time Then Enter Book Name: ";
		getline(cin, search1);
		bool flag = 0;
		while (!ofile.eof())
		{

			ofile >> student_id >> student_name >> book_name;
			if (student_id == search && search1 == book_name)
			{
				flag = 1;
			}
			else
			{
				dfile << std::endl << student_id << "\n" << student_name << "\n" << book_name;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else{
			std::cout << "Book Return\n";
		}
		ofile.close();
		dfile.close();
		remove("IssueBooks.dat");
		rename("temp1.dat", "IssueBooks.dat");
	}
};


class Cafe
{
	string eatables;
	float price_of_eatables;
	float cafe_expenses;
	float cafe_rev;

public:
	void add_cafe_menu() {

	}
	void search_cafe_menu() {

	}
	void update_cafe_menu() {

	}
	void remove_cafe_menu() {

	}
	void show_cafe_menu() {

	}
	void cafe_expenditure() {

	}
	void cafe_revenue() {

	}


};


class College_transport
{
	int total_buses;
	int bus_no;
	string Starting_root;
	string Ending_root;
	string student_name;
	float instalment_transport;
	float expenditure;
	float transport_rev;
	std::string trans_login;
	int trans_pass;
public:
	void set_trans_user(std::string a) {
		trans_login = a;

	}

	void set_trans_pass(int b) {
		trans_pass = b;

	}

	std::string get_trans_user() {
		return trans_login;

	}
	int get_trans_pass() {
		return trans_pass;

	}

	bool transport_login()
	{

		std::fstream file_pass_transport;
		std::string username_trans;
		int password_trans;
		bool flag = 0;
		file_pass_transport.open("TransportPassword.dat", std::ios::in);

		if (file_pass_transport.fail()) {
			cout << "Couldn't open the file!" << endl;
			return 0;
		}



		while (!file_pass_transport.eof())
		{
			file_pass_transport >> username_trans >> password_trans;

			if (get_trans_user() == username_trans && get_trans_pass() == password_trans)
			{
				// Login Successful

				flag = 1;
				

			}


		}

		if (flag == 0)
		{
			std::cout << "Login details are not correct\n";
			return 0;
		}
		else {
			std::cout << "Login Successful\n";
			return 1;
		}
	}

	void buses_root() {
		std::fstream file_obj;
		file_obj.open("transport.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter Bus_id-->";
		std::cin >> bus_no;
		std::cout << "Enter  Starting_root-->";
		std::cin >> Starting_root;
		std::cout << "Enter ending_root-->";
		std::cin >> Ending_root;



		file_obj << "\n" << bus_no << "\t" << Starting_root << "\t" << Ending_root ;
		file_obj.close();
	}
	void show_busroot() {
		std::fstream file_obj;
		file_obj.open("transport.dat", std::ios::in);

		while (!file_obj.eof())
		{
			file_obj >>  bus_no >> Starting_root >> Ending_root ;

			std::cout << "                              --------------------------------------------------\n";
			std::cout << setw(42) << "|BUS_ID   | " << " Starting_root     | " << "Ending_root     |  "  << "\n";
			std::cout  << "                              __________________________________________________\n";
			std::cout << setw(32) << "| "<<bus_no << "    |    " << Starting_root << "       |    " << Ending_root << "  |      "  << std::endl;



			std::cout << "                              __________________________________________________\n";

		}
		file_obj.close();
	}

	void update_busroot() {
		int Bus_id;
		std::string new_start;
		std::string new_end;
		int search;
		std::fstream file_obj, temp_obj;
		file_obj.open("transport.dat", std::ios::in);
		temp_obj.open("temp.dat", std::ios::out);
		std::cout << "Enter Bus Number To Update\n";
		cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			file_obj >> bus_no >> Starting_root >> Ending_root ;

			if (search == bus_no)
			{

				std::cout << "Enter Bus_id-->";
				std::cin >> Bus_id;
				std::cout << "Enter  Updated Starting Root Of Bus " << Bus_id << endl;
				std::cin >> new_start;
				std::cout << "Enter  Upadated Ending Root Of Bus "<< Bus_id<<endl;
				std::cin >> new_end;


				temp_obj << "\n" << Bus_id << "\t" << new_start << "\t" << new_end ;
				flag = 1;
			}
			else
			{


				temp_obj << "\n" << bus_no << "\t" << Starting_root << "\t" << Ending_root  ;
			}
		}
		file_obj.close();
		temp_obj.close();

		remove("transport.dat");
		rename("temp.dat", "transport.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void search_busroot() {
		std::fstream file_obj;
		file_obj.open("transport.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter bus_id:";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{
			std::string Starting_root;
			std::string Ending_root;
			int Monthly_fair;
			float Monthly_bus_expenditure;
			file_obj >> bus_no >> Starting_root >> Ending_root >> Monthly_fair;
			if (bus_no == search)
			{
				flag = 1;

				std::cout << "                              --------------------------------------------------\n";
				std::cout << setw(42) << "|BUS_ID   | " << " Starting_root     | " << "Ending_root     |  " << "\n";
				std::cout << "                              __________________________________________________\n";
				std::cout << setw(32) << "| " << bus_no << "    |    " << Starting_root << "       |    " << Ending_root << "  |      " << std::endl;



				std::cout << "                              __________________________________________________\n";

			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
	}
	void remove_busroot() {
		std::fstream ofile, dfile;
		ofile.open("transport.dat", std::ios::in);
		dfile.open("temp.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter Bus Number: ";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{

			ofile >> bus_no >> Starting_root >> Ending_root ;
			if (bus_no == search)
			{
				flag = 1;
			}
			else
			{
				dfile << "\n"<< bus_no << "\t" << Starting_root << "\t" << Ending_root;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		else {
			std::cout << "Record Successfully Deleted" << std::endl;
		}
		ofile.close();
		dfile.close();
		remove("transport.dat");
		rename("temp.dat", "transport.dat");
	}




	void add_bus_expenditure()

	{
		std::fstream file_obj;
		file_obj.open("BusExpense.dat", std::ios::app);

		if (file_obj.fail()) {
			std::cout << "Connection not establish\n";
		}

		std::cout << "Enter Bus_no-->";
		std::cin >> bus_no;
		std::cout << "Enter  bus_expenditure-->";
		std::cin >> expenditure;




		file_obj << "\n" << bus_no << "\t" << expenditure;
		file_obj.close();
	}

	void view_bus_expenditure()
	{
		std::fstream file_obj;
		file_obj.open("BusExpense.dat", std::ios::in);

		while (!file_obj.eof())
		{
			file_obj >> bus_no >> expenditure;

			std::cout << "Bus Number:  ";
			std::cout << bus_no <<" | ";
			std::cout << "Bus Expenditure:  ";
			std::cout << expenditure << std::endl;

			std::cout << "__________________________________________\n";
		}
		file_obj.close();
	}


	void search_bus_expenditure()
	{
		std::fstream file_obj;
		file_obj.open("BusExpense.dat", std::ios::in);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter Bus Number to Search\n";
		std::cin >> search;
		bool flag = 0;
		while (!file_obj.eof())
		{


			file_obj >> bus_no >> expenditure;
			if (bus_no == search)
			{
				flag = 1;

				std::cout << "Bus Number:  ";
				std::cout << bus_no << " | ";
				std::cout << "Bus Expenditure:  ";
				std::cout << expenditure << std::endl;


				std::cout << "_____________________________________________________\n";



			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}

	}



	void update_bus_expenditure()
	{

		std::fstream file_obj, temp_obj;
		int search;
		file_obj.open("BusExpense.dat", std::ios::in);
		temp_obj.open("temp.dat", std::ios::out);

		bool flag = 0;
		std::cout<<"Enter Bus Number to Update\n";
		cin >> search;
		while (!file_obj.eof())
		{
			file_obj >> bus_no >> expenditure;

			if (bus_no == search)
			{

				std::cout << "Enter Bus_no-->";
				std::cin >> bus_no;
				std::cout << "Enter  Bus Expenditure-->";
				std::cin >> expenditure;


				temp_obj << "\n" << bus_no << "\t" << expenditure;
				flag = 1;
			}
			else
			{

				temp_obj << "\n" << bus_no << "\t" << expenditure;

			}
		}
		file_obj.close();
		temp_obj.close();

		remove("BusExpense.dat");
		rename("temp.dat", "BusExpense.dat");
		if (flag == 1)
		{
			std::cout << "Successfully updated\n";
		}
	}

	void remove_bus_expenditure()
	{


		std::fstream ofile, dfile;
		ofile.open("BusExpense.dat", std::ios::in);
		dfile.open("temp.dat", std::ios::out);
		if (!ofile.is_open() && !dfile.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		int search;
		std::cout << "Enter Bus Number: ";
		std::cin >> search;
		bool flag = 0;
		while (!ofile.eof())
		{

			ofile >> bus_no >> expenditure;
			if (bus_no == search)
			{
				flag = 1;
			}
			else
			{
				dfile << std::endl << bus_no << "\t" << expenditure;
			}
		}
		if (flag == 0)
		{
			std::cout << "Record not Found" << std::endl;
		}
		ofile.close();
		dfile.close();
		remove("BusExpense.dat");
		rename("temp.dat", "BusExpense.dat");
	}

	void calculate_busexpenses() {
		double total_bus_expense = 0;
		bool flag=0;
		std::fstream file_obj, file_expenditure;
		file_obj.open("BusExpense.dat", std::ios::in);
		file_expenditure.open("TotalExpenditure.dat", std::ios::out);
		if (!file_obj.is_open())
		{
			std::cout << "Connection not established";
			return;
		}
		while (!file_obj.eof())
		{

			flag = 1;
			file_obj >> bus_no >> expenditure;

			total_bus_expense += expenditure;



		
		}
		expenses = "Bus_Expenditure";
		file_expenditure << "\n" << expenses << "\t" << total_bus_expense;

		if (flag == 1)
		{
			std::cout << "Total Monthly Bus Expenditure is "<< total_bus_expense << std::endl;
		}
	}


	void add_student_transport() {

	}
	void search_student_transport() {

	}
	void update_student_transport() {

	}
	void remove_student_transport() {

	}
	void show_student_transport() {

	}
	void transport_expenditure() {

	}
	void transport_revenue() {

	}
};
class email_system {
private:
	std::string mail_stID;
	std::string mail_stName;
	std::string mail_content;
	std::string mail_subject;
	std::string mail_response;
	std::string desina;

public:

	void student_mail() {
		fstream admin_mail, principle_mail, accountant_mail, teacher_mail;

		int check;

		std::cout << "1. Send Email To Admin\n";
		std::cout << "2. Send Email To Principle\n";
		std::cout << "3. Send Email To Accountant\n";
		std::cout << "4. Send Email To Teacher\n";
		int mail_select;
		std::cout << "Your Choice = ";
		std::cin >> mail_select;

		if (mail_select == 1) {
			admin_mail.open("Sadmin_email.dat", std::ios::app);
			cin.ignore();
			std::cout << "Enter Subject Of Your Email\n";
			getline(std::cin, mail_subject);
			std::cout << "Enter Your Name\n";
			getline(std::cin, mail_stName);
			std::cout << "Enter Your Roll Number\n";
			getline(std::cin, mail_stID);
			std::cout << "Enter Your Mail Content\n";
			getline(std::cin, mail_content);
			admin_mail << "\n" << mail_stID << " | " << "\t" << mail_stName << " | " << "\t" << mail_subject << " | " << "\t" << mail_content;
			admin_mail.close();

		}

		else if (mail_select == 2) {
			principle_mail.open("Sprinciple_email.dat", std::ios::app);
			cin.ignore();
			cout << "Enter Subject Of Your Email\n";
			getline(std::cin, mail_subject);
			cout << "Enter Your Name\n";
			getline(std::cin, mail_stName);
			cout << "Enter Your Roll Number\n";
			getline(std::cin, mail_stID);
			cout << "Enter Your Mail Content\n";
			getline(std::cin, mail_content);
			principle_mail << "\n" << mail_stID << " | " << "\t" << mail_stName << " | " << "\t" << mail_subject << " | " << "\t" << mail_content;
			principle_mail.close();

		}
		else if (mail_select == 3) {
			accountant_mail.open("Saccountant_email.dat", std::ios::app);
			cin.ignore();
			cout << "Enter Subject Of Your Email\n";
			getline(std::cin, mail_subject);
			cout << "Enter Your Name\n";
			getline(std::cin, mail_stName);
			cout << "Enter Your Roll Number\n";
			getline(std::cin, mail_stID);
			cout << "Enter Your Mail Content\n";
			getline(std::cin, mail_content);
			admin_mail << "\n" << mail_stID << " | " << "\t" << mail_stName << " | " << "\t" << mail_subject << " | " << "\t" << mail_content;
			accountant_mail.close();

		}
		else if (mail_select == 4) {
			teacher_mail.open("Steacher_email.dat", std::ios::app);
			cin.ignore();
			cout << "Enter Subject Of Your Email\n";
			getline(std::cin, mail_subject);
			cout << "Enter Your Name\n";
			getline(std::cin, mail_stName);
			cout << "Enter Your Roll Number\n";
			getline(std::cin, mail_stID);
			cout << "Enter Your Mail Content\n";
			getline(std::cin, mail_content);
			admin_mail << "\n" << mail_stID << " | " << "\t" << mail_stName << " | " << "\t" << mail_subject << " | " << "\t" << mail_content;
			teacher_mail.close();

		}


	}

	void student_mail_response() {

		fstream admin_mail;
		admin_mail.open("Student_emailResponse.dat", std::ios::app);
		cin.ignore();
		cout << "Enter Your Desination: \n";
		getline(std::cin, desina);
		cout << "Enter Student Roll Number: \n";
		getline(std::cin, mail_stID);
		cout << "Enter Email Subject: \n";
		getline(std::cin, mail_subject);
		cout << "Write Email Reply: (Use Naming Convention(_) instead of Space)\n";
		getline(std::cin, mail_response);
		admin_mail << "\n" << desina << "\t" << mail_stID << "\t" << mail_subject << "\t" << mail_response;
		admin_mail.close();


	}


	void view_Smail_response() {
		std::string mail_response;
		std::string search_roll;
		fstream admin_mail;
		admin_mail.open("Student_emailResponse.dat", std::ios::in);
		while (!admin_mail.eof()) {

			admin_mail >> desina >> mail_stID >> mail_subject >> mail_response;
			
			if (student_rollnumber == mail_stID) {
				std::cout << "________________________________________________\n";
				std::cout << "Email Subject: " << mail_subject << std::endl;
				std::cout << "Reply From " << desina << ":" << endl;
				std::cout << mail_response << endl;
				std::cout << "________________________________________________\n";

			}

		}

		admin_mail.close();


	}

	void view_student_adminmail() {
		fstream admin_mail;
		admin_mail.open("Sadmin_email.dat", std::ios::in);
		cout << "________________________________________________________________________________________________________________________\n";
		std::cout << endl;
		std::ifstream filemenu("Sadmin_email.dat");
		std::string str;
		while (std::getline(filemenu, str)) {
			std::cout << str << "\n";
			cout << "________________________________________________________________________________________________________________________\n";
			std::cout << endl;
		}
		
		admin_mail.close();
	}

	void view_student_teachermail() {
		fstream admin_mail;
		admin_mail.open("Steacher_email.dat", std::ios::in);
		cout << "________________________________________________________________________________________________________________________\n";
		std::cout << endl;
		while (!admin_mail.eof()) {

			admin_mail >> mail_stID >> mail_stName >> mail_subject >> mail_content;
			std::cout << mail_stID << " ";
			std::cout << mail_stName << " ";
			std::cout << mail_subject << " ";
			std::cout << mail_content << " ";

		}
		std::cout << endl;
		cout << "________________________________________________________________________________________________________________________\n";

		admin_mail.close();
	}

};

class coordinator {
private:
	string coordinator_name;
	string coordinator_username;
	int coordinator_pass;
public:
	void set_coordinator_user(std::string a) {
		coordinator_username = a;

	}

	void set_coordinator_pass(int b) {
		coordinator_pass = b;

	}

	std::string get_coordinator_user() {
		return coordinator_username;

	}
	int get_coordinator_pass() {
		return coordinator_pass;

	}

	bool coordinator_login()
	{
		if (get_coordinator_user() == "coordinator" && get_coordinator_pass() == 1122)
		{

			std::cout << "Login Successful\n";
			return 1;


		}
		else {
			std::cout << "Login Details Are Not Correct\n";
			return 0;
		}
	}
};