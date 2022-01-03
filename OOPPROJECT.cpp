#include<iostream>
#include<fstream>
#include<string.h>
#include"Header.h"
#include <windows.h>   
using namespace std;
int main() {
home:
	system("CLS");
	admin admin;
	Attendance attend;
	coordinator coo;
	students obj;
	timetable t;
	student_portal st;
	teacher_portal tp;
	email_system Email;
	student_result result;
	College_transport transport;
	Accountant account;
	College_Expenditure expenditure;
	teachers teach;
	revenue rev;
	salary salary;
	student_fee fee;
	library library;
	admission_office add;
	//pointers and inheritance
	students* p_student = &obj;
	 p_student = new students;
	std::string user;
	int pass;
	std::string user_trans;
	int pass_trans;
	std::string user_account;
	int pass_account;
	bool response = 0;
	std::ifstream filemenu("mainmenu.dat");
	std::string str;
	while (std::getline(filemenu, str)) {
		std::cout << str << "\n";
	}
	int a;
	cout << "Enter Your Choice = ";
	cin >> a;
	switch (a) {

	case 1:

		std::cout << "Enter Your Username: \n";
		cin >> user;
		std::cout << "Enter Your Password: \n";
		cin >> pass;
		st.set_user(user);
		st.set_pass(pass);
		response = st.login();
		if (response == 1) {
		again:
			system("Color 1B");
			system("CLS");
			int x;
			char rev;
			std::ifstream filemenu("studentmenu.dat");
			std::string str;
			while (std::getline(filemenu, str)) {
				std::cout << str << "\n";
			}
			std::cout << "Your Choice\n";
			cin >> x;
			if (x == 1) {
				st.view_student();
			}
			else if (x == 2) {
				attend.view_personal_StudentAttendence();
			}
			else if (x == 3) {
				t.view_student_timetable();
			}
			else if (x == 5) {
				result.search_result_student();
			}
			else if (x == 6) {
				st.show_course();
			}

			else if (x == 7) {
				Email.student_mail();
			}
			else if (x == 8) {
				Email.view_Smail_response();
			}
			else if (x == 9) {
			st.update_student_password();
			}
			else if (x == 10) {
				obj.update_students();
			}
			else if (x == 11) {
				goto home;
			}
			std::cout << "Press n To Home, Press y For Student Main Menu\n";
			cin >> rev;
			if (rev == 'y' || rev == 'Y') {
				goto again;
			}

			if (rev == 'n' || rev == 'N') {
				system("Color 1A");
				goto home;
			}

	    }


		break;
	case 2:
		std::cout << "Enter Your Username: \n";
		cin >> user;
		std::cout << "Enter Your Password: \n";
		cin >> pass;
		tp.set_teacher_pass(pass);
		tp.set_teacher_user(user);
		response = tp.teacher_login();
		if (response == 1) {
			system("color F9");
			tagain:
			system("CLS");
			std::ifstream filemenu("teachermenu.dat");
			std::string str;
			while (std::getline(filemenu, str)) {
				std::cout << str << "\n";
			}
			int tchoice;
			std::cout << "Enter Your Choice: ";
			cin >> tchoice;
			if (tchoice == 1) {
				teach.view_teacher_information();
			}
			if (tchoice == 2) {
				attend.view_personal_StaffAttendence();
			}
			if (tchoice == 3) {
				t.view_teacher_timetable();
			}
			if (tchoice == 4) {
				std::cout << "1. Add Student Attendence\n";
				std::cout << "2. Show Student Attendence \n";
				std::cout << "3. Search Student Attendence\n";
				std::cout << "4. Update Student Attendence\n";
				std::cout << "5. Remove Student Attendence\n";
				int w;
				cin >> w;
				if (w == 1) {
					attend.add_StudentAttendence();
				}
				else if (w == 2) {
					attend.view_StudentAttendence();
				}
				else if (w == 3) {
					attend.search_StudentAttendence();
				}
				else if (w == 4) {
					attend.update_StudentAttendence();
				}
				else if (w == 5) {
					attend.remove_StudentAttendence();
				}
			}

			else if (tchoice == 5) {
				std::cout << "1. Add Student Result\n";
				std::cout << "2. View Student Result\n";;
				std::cout << "3. Update Student Result\n";
				int rc;
				cin >> rc;
				if (rc == 1) {
					result.add_result_student();
				}

				if (rc == 2) {
					std::string v;
					std::cout << "Enter Student ID: ";
					std::cin >> v;
					result.search_result_student(v);
				}

				if (rc == 3) {
					result.update_result_student();

				}


				
			}
			else if (tchoice == 6) {
				result.calculate_grade();
			}
			else if (tchoice == 7) {
				Email.view_student_teachermail();
			}
			else if (tchoice == 8) {
				Email.student_mail_response();
			}
			else if (tchoice == 11) {
				goto home;
			}
			char r;
			std::cout << "Press n To Home, Press y For Teacher Main Menu\n";
			cin >> r;
			if (r == 'y' || r == 'Y') {
				goto tagain;
			}

			if (r == 'n' || r == 'N') {
				system("Color 1A");
				goto home;
			}
		}
		break;
	case 3:
		bool admin_response;
		std::cout << "Enter Your Username: ";
		cin >> user_account;
		std::cout << "Enter Your Password: ";
		cin >> pass_account;
		admin.set_admin_user(user_account);
		admin.set_admin_pass(pass_account);
		admin_response = admin.admin_login();

		if (admin_response == 1) {
			
		accountant:
			system("CLS");
			std::ifstream filemenu("adminmenu.dat");
			std::string str;
			while (std::getline(filemenu, str)) {
				std::cout << str << "\n";
			}
			int a;
			std::cout << "Enter Your Choice\n";
			cin >> a;
			if (a == 1) {
				
				std::cout << "1. New Student \n";
				std::cout << "2. Show Student \n";
				std::cout << "3. Search Student \n";
				std::cout << "4. Update Student \n";
				std::cout << "5. Remove Student \n";
				std::cout << "Enter Your Choice \n";
				int p;
				std::cout << "Enter Your Choice\n";
				cin >> p;
				if (p == 1) {
					obj.new_students();
				}
				else if (p == 2) {
					obj.show_students();
				}
				else if (p == 3) {
					obj.search_students();
				}
				else if (p == 4) {
					obj.update_students();

				}
				else if (p == 5) {
					obj.remove_students();
				}
				else {
					std::cout << "Invalid Selection\n";
				}
			}
			else if (a == 2) {
				
				std::cout << "1. New Teacher \n";
				std::cout << "2. Show Teacher \n";
				std::cout << "3. Search Teacher \n";
				std::cout << "4. Update Teacher \n";
				std::cout << "5. Remove Teacher \n";
				std::cout << "Enter Your Choice: ";
				int p;
				std::cout << "Enter Your Choice\n";
				cin >> p;
				if (p == 1) {
					teach.add_teacher();
				}
				else if (p == 2) {
					teach.view_teacher();
				}
				else if (p == 3) {
					teach.search_teacher();
				}
				else if (p == 4) {
					teach.update_teacher();

				}
				else if (p == 5) {
					teach.remove_teacher();
				}
				else {
					std::cout << "Invalid Selection\n";
				}

			}


			else if (a == 3) {
				rev.view_total_revenue();
			}
			else if (a == 4) {
				expenditure.view_total_expenditure();
			}
			else if (a == 5) {
				rev.calculate_total_fee();
			}
			else if (a == 6) {
				Email.view_student_adminmail();
			}
			else if (a == 7) {
				Email.student_mail_response();
			}
			char q;
			std::cout << "Press n To Home, Press y For Admin Main Menu\n";
			cin >> q;
			if (q == 'y' || q == 'Y') {
				goto accountant;
			}

			if (q == 'n' || q == 'N') {
				goto home;
			}
		}
		break;
	case 4:
		bool coordinator_response;
		std::cout << "Enter Your Username: \n";
		cin >> user_trans;
		std::cout << "Enter Your Password: \n";
		cin >> pass_trans;
		coo.set_coordinator_user(user_trans);
		coo.set_coordinator_pass(pass_trans);
		coordinator_response = coo.coordinator_login();

		if (coordinator_response == 1) {
		coord:
			system("CLS");
			std::ifstream filemenu("coordinatormenu.dat");
			std::string str;
			while (std::getline(filemenu, str)) {
				std::cout << str << "\n";
			}
			int cr;
			cin >> cr;
			if (cr == 6) {
				t.add_teacher_timetable();
			}
			else if (cr == 7) {
				t.view_teacher_timetablecoo();
			}
			else if (cr == 1) {
				t.student_timetable();
			}
			else if (cr == 2) {
				std::string Roll;
				std::cout << "Enter Student ID: ";
				cin >> Roll;
				t.view_student_timetable(Roll);
			}
			else if (cr == 3) {
				t.update_student_timetable();
			}
			else if (cr == 4) {
				t.remove_student_timetable();
				
			}
			else if (cr == 8) {
				st.student_course();

			}
			else if (cr == 9) {
				std::string ssection;
				std::cout << "Enter Section: ";
				cin >> ssection;
				st.show_course(ssection);

			}


		}
		char w;
		std::cout << "Press n To Home, Press y For Coordinator Main Menu\n";
		cin >> w;
		if (w == 'y' || w == 'Y') {
			goto coord;
		}

		if (w == 'n' || w == 'N') {
			goto home;
		}
		break;

	case 5:
		bool accountant_response;
		std::cout << "Enter Your Username: \n";
		cin >> user_account;
		std::cout << "Enter Your Password: \n";
		cin >> pass_account;
		account.set_accountant_user(user_account);
		account.set_accountant_pass(pass_account);
		accountant_response = account.accountant_login();

		if (accountant_response == 1) {
		account_label:
			system("CLS");
			std::ifstream filea("accountantmenu.dat");
			std::string s;
			while (std::getline(filea, s)) {
				std::cout << s << "\n";
			}
			int u;
			std::cout << "Enter Your Choice: ";
			cin >> u;
			if (u == 1) {
				int f;
				std::cout << "1. Add Student Fee\n";
				std::cout << "2. View Student Fee\n";
				std::cout << "3. Search Student Fee\n";
				std::cout << "4. Update Student Fee\n";
				std::cout << "5. Remove Student Fee\n";
				std::cout << "Your Choice: ";
				std::cin >> f;
				if (f == 1) {
					fee.add_student_fee();
				}
				else if (f == 2) {
					fee.view_student_fee();
				}
				else if (f == 3) {
					fee.search_student_fee();
				}
				else if (f == 4) {
					fee.update_student_fee();
				}
				else if (f == 5) {
					fee.remove_student_fee();
				}
				else if (f == 6) {
					rev.calculate_total_fee();
				}
				else {
					std::cout << "Invalid Selection\n";
				}

			}
			else if (u == 2) {
				std::cout << "1. Add Staff Salary\n";
				std::cout << "2. View Staff Salary\n";
				std::cout << "3. Search Staff Salary\n";
				std::cout << "4. Update Staff Salary\n";
				std::cout << "5. Remove Staff Salary\n";
				int s;
				std::cout << "Your Choice: ";
				cin >> s;
				if (s == 1) {
					salary.add_salary();
				}
				else if (s == 2) {
					salary.view_salary();
				}
				else if (s == 3) {
					salary.search_salary();
				}
				else if (s == 4) {
					salary.update_salary();
				}
				else if (s == 5) {
					salary.remove_salary();
				}
				else {
					std::cout << "Invalid Selection\n";
				}
			}




			else if (u == 3) {
				int ws;
				std::cout << "1. Add Worker Salary\n";
				std::cout << "2. View Worker Salary\n";
				std::cout << "3. Search Worker Salary\n";
				std::cout << "4. Update Worker Salary\n";
				std::cout << "5. Remove Worker Salary\n";
				std::cout << "Your Choice: ";
				std::cin >> ws;
				if (ws == 1) {
					salary.worker_add_salary();
				}
				else if (ws == 2) {
					salary.worker_add_salary();
				}
				else if (ws == 3) {
					salary.worker_add_salary();
				}
				else if (ws == 4) {
					salary.worker_add_salary();
				}
				else if (ws == 5) {
					salary.worker_add_salary();
				}
				else {
					std::cout << "Invalid Selection\n";
				}
			}


			else if (u == 4) {
				std::cout << "1. Add Monthly Expenditure\n";
				std::cout << "2. View Monthly Expenditure\n";
				std::cout << "3. Update Monthly Expenditure\n";
				int k;
				cin >> k;
				if (k == 1) {
					double f,g,h;
					std::cout << "Enter Monthly Electricity Bill\n";
					std::cin >> f;
					std::cout << "Enter Monthly Furniture Expenses\n";
					std::cin >> g;
					std::cout << "Enter Other College Expenditure\n";
					std::cin >> h;
					expenditure.college_expense(f,g,h);
				}
				else if (k == 2) {
					expenditure.view_total_expenditure();
				}
				else if (k == 3) {
					expenditure.update_expendture();
				}
				else {
					std::cout << "Invalid Selection\n";
				}

			}
			else if (u == 5) {
			std::cout << "The Total Monthly Expenditure is: " <<  ++expenditure;
			}
			else if (u == 6) {
				std::cout << "1. Calculate Total Monthly Revenue\n";
				std::cout << "2. View Total Monthly Revenue\n";
				std::cout << "Your Choice: ";
				int v;
				cin >> v;
				if (v == 1) {
					rev.calculate_revenue();
				}
				if (v == 2) {
					rev.view_total_revenue();
				}

			}

			else if (u == 7) {
				++salary;
			}
			else if (u == 8) {
				goto home;
			}
			char n;
			std::cout << "Press n To Home, Press y For Accountant Main Menu\n";
			cin >> n;
			if (n == 'y' || n == 'Y') {
				goto account_label;
			}

			if (n == 'n' || n == 'N') {
				goto home;
			}
		}
		break;


	case 6:
		bool trans_response;
		std::cout << "Log in as Transport Admin\n";
		std::cout << "Enter Your Username: \n";
		cin >> user_trans;
		std::cout << "Enter Your Password: \n";
		cin >> pass_trans;
		transport.set_trans_user(user_trans);
		transport.set_trans_pass(pass_trans);
		trans_response = transport.transport_login();
 
		if (trans_response == 1) {
		trans_label:
		go:
			system("CLS");
			int f;
			std::ifstream filemenu("busmenu.dat");
			std::string str;
			while (std::getline(filemenu, str)) {
				std::cout << str << "\n";
			}
			std::cout << "Enter Your Choice: ";
			cin >> f;
			if (f == 1) {

				transport.buses_root();
			}
			else if (f == 2) {
				transport.show_busroot();
			}
			else if (f == 3) {
				transport.search_busroot();
			}
			else if (f == 4) {
				transport.update_busroot();
			}
			else if (f == 5) {
				transport.remove_busroot();
			}

			if (f == 6) {

				transport.add_bus_expenditure();
			}
			else if (f == 7) {
				transport.view_bus_expenditure();
			}
			else if (f == 8) {
				transport.search_bus_expenditure();
			}
			else if (f == 9) {
				transport.update_bus_expenditure();
			}
			else if (f == 10) {
				transport.remove_bus_expenditure();
			}
			else if (f == 11) {
				transport.calculate_busexpenses();
			}
			else if (f == 12) {
				goto home;
			}
		}
		char i;
		std::cout << "Press n To Home, Press y For Transport Main Menu\n";
		cin >> i;
		if (i == 'y' || i == 'Y') {
			goto trans_label;
		}

		if (i == 'n' || i == 'N') {
			goto home;
		}

		break;
	
	case 7:
	lib_label:
		std::cout << "\t\t\t\tLibrary Managment Sytem\n";
		std::cout << "\t\t\t\t1. Log in As Librarian\n";
		std::cout << "\t\t\t\t2. Visit As Student\n";
		int lib;
		std::cin >> lib;

		if (lib == 1) {
			bool library_response;
			std::cout << "Enter Your Username: \n";
			cin >> user_account;
			std::cout << "Enter Your Password: \n";
			cin >> pass_account;
			library.set_library_user(user_account);
			library.set_library_pass(pass_account);
			library_response = library.library_login();

			if (library_response == 1) {
				int l = 1;
				while (l != 0) {
					std::cout << "\t\t\t\t\t1. Add Book\n";
					std::cout << "\t\t\t\t\t2. View Book\n";
					std::cout << "\t\t\t\t\t3. Search Book\n";
					std::cout << "\t\t\t\t\t4. Update Book\n";
					std::cout << "\t\t\t\t\t5. Remove Book\n";
					cin >> l;
					if (l == 1) {
						library.add_book();
					}
					else if (l == 2) {
						library.view_book();
					}
					else if (l == 3) {
						library.search_book();
					}
					else if (l == 4) {
						library.update_book();
					}
					else if (l == 5) {
						library.remove_book();
					}
					else if(l == 0){

					}
					else {
						std::cout << "Invalid Selection\n";
					}



				}
			}
		}

		else if (lib == 2) {
			int o = 1;
			while (o != 0) {
				std::cout << "\t\t\t\t\t\t1. View All Books\n";
				std::cout << "\t\t\t\t\t\t2. Issue Book\n";
				std::cout << "\t\t\t\t\t\t3. Search Book\n";
				std::cout << "\t\t\t\t\t\t4. Return Book\n";
				std::cout << "\t\t\t\t\t\t0. Exit\n";

				cin >> o;
				if (o == 1) {
					library.view_book();
				}
				else if (o == 2) {
					library.add_issue_book();
				}
				else if (o == 3) {
					library.search_book();
				}
				else if (o == 4) {
					library.update_issue_book();
				}

			}
			
		}
		char m;
		std::cout << "Press n To Home, Press y For Library Main Menu\n";
		cin >> m;
		if (m == 'y' || m == 'Y') {
			goto lib_label;
		}

		if (m == 'n' || m == 'N') {
			goto home;
		}
		break;
	case 8:
		admission:
		int b;
		std::cout << "1. New Student \n";
		std::cout << "2. Show Student \n";
		std::cout << "3. Search Student \n";
		std::cout << "4. Update Student \n";
		std::cout << "5. Remove Student \n";
		std::cout << "6. Total Admissions \n";
		std::cout << "7. Total Teachers in College \n";
		std::cout << "Enter Your Choice \n";

		std::cout << "__________________________________\n";
		cin >> b;
		if (b == 1) {
			p_student->new_students();
		}
		else if (b == 2) {
			p_student->show_students();
		}
		else if (b == 3) {
			p_student->search_students();
		}
		else if (b == 4) {
			p_student->update_students();
		}
		else if (b == 5) {
			p_student->remove_students();
		}
		else if (b == 6) {
			std::cout<<"Total Number of admission in this month: "<<add.view_total_admissions()<<std::endl;
		}
		else if (b == 7) {
			add.all_teachers();
		}
		char z;
		std::cout << "Press n To Home, Press y For Admission Office Main Menu\n";
		cin >> z;
		if (z == 'y' || z == 'Y') {
			goto admission;
		}

		if (z == 'n' || z == 'N') {
			goto home;
		}
		break;
	case 9:
		std::cout << "You can send Email Or Reply for Email By Signing In \n";
		break;
	case 10:
		system("CLS");
		std::ifstream filemenu("goodbye.dat");
		std::string str;
		while (std::getline(filemenu, str)) {
			std::cout << str << "\n";
		}
		exit(EXIT_SUCCESS);

	}
	

	char ex;
	std::ifstream file("exit.dat");
	std::string stru;
	while (std::getline(file, stru)) {
		std::cout << stru << "\n";
	}
	cin >> ex;
	if (ex == 'y') {
		std::ifstream filemenu("goodbye.dat");
		std::string str;
		while (std::getline(filemenu, str)) {
			std::cout << str << "\n";
		}
	}
	else if(ex == 'n'){
		goto home;
	}

}