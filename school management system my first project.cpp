#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

class students {
public :
	int id ;
	string name ,standard;
	string roll_num ,phone_num;
	string mother_name, father_name;
	string mother_phone_num, father_phone_num , gmail;
	string address;
	string gender;

};

class teachers {
public :
	int teacher_id = 0, age;
	string name, subject; 
	string phone_num ,gmail;
	double salary;
	string address, joined_date;

};
class branch {
public:

	int branch_id = 0;
	

	string branch_name ;
	
	int total_students = 0, next_student_id = 1;

	string address, pincode, principal ,phone_n;
	vector<students> student;
	vector<teachers> teacher;
	
	bool isphone_num(string s) {
		string phone_nu = s;
		int chance = 3;
		while (chance) {

			if (phone_nu.length() != 10) {
				cout << " enter valid mobile num \n";
				chance--;
				cin >> phone_nu;
				continue;
			};
			if (phone_nu[0] != '9' && phone_nu[0] != '8' &&
				phone_nu[0] != '7' && phone_nu[0] != '6') {
				cout << " enter valid mobile num \n";
				chance--;
				cin >> phone_nu;
				continue;
			}
			for (int i = 0; i < phone_nu.size(); i++) {
				if (phone_nu[i] < '0' || phone_nu[i] > '9') {
					cout << " enter valid mobile num \n";
					cin >> phone_nu;
					continue;
				}
			}
			return true;

		}
	}

	bool isvalid_mail(string s) {
			if (s.size() < 6 || s.size() > 50) {
				cout << "make sure ur gmail in bw 6 to 50 char \n";
				return false;
			}

			if (!isalnum(s[0])) {
				cout << " first char should be alphabet or num \n";
				return false;
			}
			if (!(s[s.size() - 1] == 'm' &&
				s[s.size() - 2] == 'o' &&
				s[s.size() - 3] == 'c' &&
				s[s.size() - 4] == '.' ||
				s[s.size() - 1] == 'n' &&
				s[s.size() - 2] == 'i' &&
				s[s.size() - 3] == '.')) {
				cout << "the last chars  should be .com  or .in \n";
				return false;
			}
			int a_count = 0;
			int at_idx = 0;
			for (int k = 0; k < s.size(); k++) {

				if (!isalnum(s[k]) && s[k] != '_' && s[k] != '@' && s[k] != '.') {
					cout << " enter the valid email address \n";
					return false;
				}

				if (s[k] == '@') {
					at_idx = k;
					a_count++;
				}

			}


			if (a_count != 1) {
				cout << " only  consist of one @ \n";
				return false;
			}
			if (s[at_idx + 1] == '.') {
				cout << " can't place . after @ \n";
				return false;
			}
			bool founddot = false;

			for (int i = at_idx + 1; i < s.size() - 1; i++) {

				if (s[i] == '.' && s[i + 1] == '.') {
					founddot = false;
					break;
				}
			}
			if (!founddot) {
				cout << " invalid email  address :two  consecutive'. '.' aftetr @ \n";
				return false;
			}
			return true;

		}
private:

	void savestudent(ofstream& file, const students& d)
			{
				file << d.id << " "
					<< d.name << " "
					<< d.standard << " "
					<< d.mother_name << " "
					<< d.gender << " "
					<< d.father_name << " "
					<< d.phone_num << " "
					<< d.mother_phone_num <<  " "
					<< d.father_phone_num << " "
					<< d.address << " "

					<< d.gmail << '\n';

				
				return;
			}
	bool readstudent(ifstream& file,  students& d) {


					file >>  d.id 
					>> d.name 
					>> d.standard 
					>> d.mother_name 
					>> d.gender 
					>> d.father_name 
					>> d.phone_num 
					>> d.mother_phone_num
					>> d.father_phone_num 
					>> d.address 
					>> d.gmail ;

			if (file.fail())return false;


			 return true;
	}
			 
	void  saveall_students() 
	{
			ofstream file("students.txt");

				for (const students& s : student) {

					savestudent(file, s);
				}

				file.close();
	}
		
    void saveteacher(ofstream & file, const teachers & t)
    {
	 file << t.teacher_id << " "
	 << t.age << " "
	 << t.name << " "
	 << t.subject << " "
	 << t.phone_num << " "
	 << t.gmail << " "
	 << t.salary << " "
	 << t.address << " "
	 << t.joined_date << endl;


     
 return;
}

	bool readteacher(ifstream& file,  teachers& t) {


		file>> t.teacher_id 
			>> t.age 
			>> t.name 
			>> t.subject 
			>> t.phone_num 
			>> t.gmail
			>> t.salary 
			>> t.address 
			>> t.joined_date ;

		if (file.fail())return false;


		return true;

	}

	void saveall_teachers() {

		ofstream file("teachers.txt");

		for (teachers& s : teacher) {

			saveteacher(file, s);
		}

		return;
		
	}
public:
	void load_students() {

		student.clear();
		ifstream file("students.txt");
		students s;

		while (readstudent(file, s)) {

			student.push_back(s);
		}

		file.close();
	}

	void load_teacher() {

		teacher.clear();
		ifstream  file("teachers.txt");

		teachers t;

		while (readteacher(file, t)) {

			teacher.push_back(t);
		}
		file.close();
	}

	void add_student() {
		int n;

		ofstream file("students.txt", ios::app);
		cout << "enter no of students \n";
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			students d;

			d.id = next_student_id++;
			total_students++;
			cout << "new student id is  \n " << d.id << endl;




			cout << "enter name if student \n";
			getline(cin, d.name);
			cout << " enter standard \n";
			getline(cin, d.standard);
			cout << " enter students mother name \n";
			getline(cin, d.mother_name);
			cout << "enter gender \n";
			getline(cin, d.gender);
			cout << " enter students father name \n";
			getline(cin, d.father_name);
			cout << " enter student phone num \n";
			getline(cin, d.phone_num);
			while(!isphone_num(d.phone_num)) {
				cout << "enter a valid phone num \n";
			}
			cout << " enter students mother phone num \n";
			getline(cin, d.mother_phone_num);

			while (!isphone_num(d.mother_phone_num)) {
				cout << "enter a valid phone num \n";
			}

			cout << " enter  students father phone num \n";
			getline(cin, d.father_phone_num);

			while (!isphone_num(d.father_phone_num)) {
				cout << "enter a valid phone num \n";

				getline(cin, d.father_phone_num);
			}

			cout << "enter students address \n";
			getline(cin, d.address);
			cout << "enter gmail address \n";
			getline(cin, d.gmail);

			while(!isvalid_mail(d.gmail)) {

				cout << "enter the valid one \n";		
	    		getline(cin, d.gmail);
						
			}
			student.push_back(d);
			savestudent(file, d);
		}
	}

	void add_teacher()
	{

		ofstream file("teachers.txt", ios::app);
		int teachercount = 0, totalteachers = 0;
		int n;

		cout << "Enter number of teachers: ";
		cin >> n;
		cin.ignore();

		for (int i = 0; i < n; i++)
		{
			teachers t;

			teachercount++;
			t.teacher_id = teachercount;

			cout << "\nTeacher ID: " << t.teacher_id << endl;

			cout << "\nEnter teacher name: ";
			getline(cin, t.name);

			cout << "\nEnter age: ";
			cin >> t.age;
			cin.ignore();

			cout << "\nEnter subject: ";
			getline(cin, (t.subject));

			cout << "\nEnter phone number: ";
			getline(cin, t.phone_num);

			if (!isphone_num(t.phone_num)) {
				cout << " enter a valid phone num \n";
			}

			cout << "\n Enter gmail address ";
			getline(cin, t.gmail);

			if (!isvalid_mail(t.gmail)) {
				cout << " enter a valid gmaial address \n";
			}

			cout << "\nEnter salary: ";
			cin >> t.salary;
			cin.ignore();

			cout << "\nEnter address: ";
			getline(cin, t.address);

			cout << "\nEnter joining date: ";
			getline(cin, t.joined_date);

			teacher.push_back(t);

			saveteacher(file, t);
		}
		
	}

	void remove_student() {

				int n;
				vector<int >id;
				cout << "enter no of students id want to remove \n";
				cin >> n;
				for (int i = 1; i <= n; i++) {
					int idq;

					cout << "enter the id of " << i << "st student to remove : \n ";
					cin >> idq;
					id.push_back(idq);


				}
				int not_f = 0;
				for (int i = 0; i < id.size(); i++) {
					not_f = id[i];
					bool found = false;
					for (int j = 0; j < student.size(); j++) {

						if (student[j].id == id[i]) {
							student.erase(student.begin() + j);
							found = true;
							break;
						}

					}
					if (!found)cout << "student id" << not_f << "not found \n";
				}

				saveall_students();



	}

	void remove_teacher() {
				int n;
				vector<int>id;
				cout << "enter how many teachers to remove : \n";
				cin >> n;
				for (int i = 1; i <= n; i++) {
					int inx;
					cout << "enter the teacher iid to remove :\n";
					cin >> inx;
					id.push_back(inx);
				}

				for (int i = 0; i < id.size(); i++) {

					bool found = false;

					for (int j = 0; j < teacher.size(); j++) {

						if (teacher[j].teacher_id == id[i]) {
							teacher.erase(teacher.begin() + j);
							found = true;
							break;
						}
					}
					if (!found)cout << " teacher id not found \n "
						<< id[i];
				}

				saveall_teachers();
			}

	void student_details() {
				int choice;
				cout << "enter student id \n";
				cin >> choice;
				bool found = false;

				for (const students& k : student) {

					if (k.id == choice) {
						found = true;
						cout << "Name: " << k.name << endl;
						cout << "Standard: " << k.standard << endl;
						cout << "Roll No: " << k.roll_num << endl;
						cout << "Mother Name: " << k.mother_name << endl;
						cout << "Father Name: " << k.father_name << endl;
						cout << "Mother Phone: " << k.mother_phone_num << endl;
						cout << "Father Phone: " << k.father_phone_num << endl;
						cout << "Email: " << k.gmail << endl;
						cout << "Address: " << k.address << endl;
						cout << "Gender: " << k.gender << endl;
						break;
					}
				}
				if (!found) {
					cout << " student not found \n";
				}
			}

	void teacher_details() {

				int choice;
				cout << "entere teacher id \n";
				cin >> choice;
				bool found = false;

				for (const teachers& k : teacher) {

					if (k.teacher_id == choice) {
						found = true;
						cout << "Teacher ID      : " << k.teacher_id << endl;
						cout << "Name            : " << k.name << endl;
						cout << "Age             : " << k.age << endl;
						cout << "Subject         : " << k.subject << endl;
						cout << "Phone Number    : " << k.phone_num << endl;
						cout << "Salary          : " << k.salary << endl;
						cout << "Address         : " << k.address << endl;
						cout << "Join Date       : " << k.joined_date << endl;
						break;
					}
				}
				if (!found)cout << " teacher id not found \n";

			}

	void all_students() {

				if (student.empty()) {
					cout << " no students available \n";
					return;
				}
				int count = 1;
				for (const students& k : student) {
					cout << "student " << count << endl;
					cout << "Name: " << k.name << endl;
					cout << "Standard: " << k.standard << endl;
					cout << "Roll No: " << k.roll_num << endl;
					cout << "Mother Name: " << k.mother_name << endl;
					cout << "Father Name: " << k.father_name << endl;
					cout << "Mother Phone: " << k.mother_phone_num << endl;
					cout << "Father Phone: " << k.father_phone_num << endl;
					cout << "Email: " << k.gmail << endl;
					cout << "Address: " << k.address << endl;
					cout << "Gender: " << k.gender << endl;
					cout << "___________________________________________________\n";
					count++;
				}

			}

	void show_all_teachers() {
				if (teacher.empty()) {
					cout << " no teachers available \n";
					return;
				}
				int count = 1;
				for (const teachers& k : teacher) {
					cout << "teacher " << count << endl;
					cout << "Teacher ID      : " << k.teacher_id << endl;
					cout << "Name            : " << k.name << endl;
					cout << "Age             : " << k.age << endl;
					cout << "Subject         : " << k.subject << endl;
					cout << "Phone Number    : " << k.phone_num << endl;
					cout << "Salary          : " << k.salary << endl;
					cout << "Address         : " << k.address << endl;
					cout << "Join Date       : " << k.joined_date << endl;
					cout << "___________________________________________________\n";
					count++;
				}
			}

	void update_choice(students & student) {
				vector<int>update;

				int k;
				cout << "\nEnter how many fields you want to update: ";

				cout << "\n========== UPDATE STUDENT DETAILS ==========\n";
				cout << "1. Student Name\n";
				cout << "2. Standard\n";
				cout << "3. Mother's Name\n";
				cout << "4. Father's Name\n";
				cout << "5. Mother's Phone Number\n";
				cout << "6. Father's Phone Number\n";
				cout << "7. Gmail\n";
				cout << "8. Gender\n";
				cout << "9. Student Phone Number\n";
				cout << "10. Roll Number\n";
				cout << "11. Address\n";
				cin >> k;
				for (int i = 0; i < k; i++) {
					int chance = 3;
					while (chance) {
						int choice;

						cout << " enter the choices u want to update ; \n";
						cin >> choice;
						if (choice < 1 || choice >11) {
							cout << " wrong option choosed \n choose  b/w 0 to 11 \n ";
							chance--;
							continue;
						}

						if (find(update.begin(), update.end(), choice) != update.end()) {
							cout << "entered the already selected "
								<< "enter new section \n";
							chance--;
							if (chance == 0) {
								cout << " you have exausted all 3 chances \n";
							}
							continue;
						}
						update.push_back(choice);
						break;

					}
				}
				for (int j = 0; j < update.size(); j++) {

					switch (update[j]) {
					case 1:
						cout << " enter student name \n";
						cin >> student.name;
						break;
					case 2:
						cout << "enter standard \n";
						cin >> student.standard;
						break;
					case 3:
						cout << " enter mothers name \n";
						cin >> student.mother_name;
						break;
					case 4:
						cout << " enter fathers name \n";
						cin >> student.father_name;
						break;
					case 5:
						cout << "enter mother phone num :\n";
						cin >> student.mother_phone_num;
						break;
					case 6:
						cout << " enter fathers phone num \n";
						cin >> student.father_phone_num;
						break;
					case 7:
						cout << " enter gmail \n";
						cin >> student.gmail;
						break;
					case 8:
						cout << " enter gender \n";
						cin >> student.gender;
						break;
					case  9:
						cout << " enter student phone_num\n";
						cin >> student.phone_num;
						break;
					case 10:
						cout << " enter roll num \n";
						cin >> student.roll_num;
						break;
					case 11:
						cout << " enter address\n";
						cin >> student.address;
						break;

					}

				}

			
				
				
			}

	void update_student_details() {
				int choice;
				cout << "enter student id  \n";
				cin >> choice;

				bool found = false;
				for (int i = 0; i < student.size(); i++) {

					if (student[i].id == choice) {
						found = true;
						update_choice(student[i]);
						break;
					}
				}
				if (!found)
					cout << "the id " << choice << " you entered is not found \n";
				saveall_students();
			}
	void update_details(teachers & t) {

				vector<int>update;

				int J;
				cout << "enter the no of fields u want update \n";
				cin >> J;
				cout << "\n========== UPDATE TEACHER DETAILS ==========\n";
				cout << "Choose the fields you want to update:\n\n";

				cout << "1. Teacher Name\n";
				cout << "2. Age\n";
				cout << "3. Subject\n";
				cout << "4. Phone Number\n";
				cout << "5. Salary\n";
				cout << "6. Address\n";
				cout << "7. Joined Date\n";

				for (int i = 0; i < J; i++) {
					int chance = 3;

					while (chance) {
						int choice;
						cout << "enter the field u want to update \n";
						cin >> choice;
						if (choice < 1 || choice >7) {
							cout << "enter the wrong field \n enter the correct one \n";
							chance--;
							continue;
						}
						if (find(update.begin(), update.end(), choice) != update.end()) {
							cout << "entered the existed element \n pls check and re enter the correct one \n";
							chance--;
							if (chance == 0) {
								cout << " you have exausted all 3 chances \n";
							}
							continue;
						}
						update.push_back(choice);
						break;
					}
				}

				for (int i = 0; i < update.size(); i++) {

					switch (update[i]) {

					case 1:

						cout << "1. Teacher Name\n";
						cin >> t.name;
						break;
					case 2:
						cout << "2. Age\n";
						cin >> t.age;
						break;
					case 3:
						cout << "3. Subject\n";
						cin >> t.subject;
						break;
					case 4:
						cout << "4. Phone Number\n";
						cin >> t.phone_num;
						break;
					case 5:
						cout << "5. Salary\n";
						cin >> t.salary;
						break;
						cout << "6. Address\n";
						cin >> t.address;
						break;
						cout << "7. Joined Date\n";
						cin >> t.joined_date;
						break;

					}
				}
			}

	void update_teacher_details() {
		int choice;
		cout << "enter teacher id \n";
		cin >> choice;
		bool found = false;

		for (int i = 0; i < teacher.size(); i++) {

			if (choice == teacher[i].teacher_id) {
				found = true;
				update_details(teacher[i]);

				break;

			}
		}
		if (!found)
			cout << "entered id " << choice << " not found \n";

		saveall_teachers();
	};
	

	
};

class schools
{
public:
	int total_branches;
	string name;
	string location, pincode, principal,phone_num;
	vector<branch>branches;

private:

	void save_branches(ofstream& file, const branch& b) {


		file << b.branch_id <<
			b.branch_name <<
			b.address <<
			b.pincode <<
			b.principal <<
			b.phone_n << endl;

		file.close();
	}

	bool read_branches(ifstream& file, branch& b) {


			file >> b.branch_id>>
						b.branch_name >>
						b.address >>
						b.pincode >>
						b.principal >>
						b.phone_n ;

			if (file.fail())return false;

			return true;
		
	}

	void saveall_branches() {

		ofstream file("branches.txt");

		
		for (branch& b : branches) {

			save_branches(file, b);
		}
		file.close();
	}

public:
	void load_branches()
	{
		branches.clear();

		ifstream file("branches.txt");
		branch b;

		while (read_branches(file, b)) {
			branches.push_back(b);

		}
		file.close();

	}

	void add_branch() {
		
		ofstream file("branches.txt" ,ios::app);
		int next_branch_id ;
		total_branches++;
		branch b;
		b.branch_id = next_branch_id++;
		cout << b.branch_id << endl;
		cout << "enter name \n";
		cin >> b.branch_name;
		cout << " enter location \n";
		cin >> b.address;
		cout << " enter branch address \n";
		cin >> b.pincode ;
		cout << " enter principal \n";
		cin >> b.principal;
		cout << " enter phone_num \n";
		cin >> b.phone_n;
		branches.push_back(b);

		save_branches(file, b);
	}

	void show_total_branches() {
		int count = 1;
		cout << "total branches are " << total_branches;
		

				for (const branch& b : branches) {

					cout << "branch " << count << endl;
					cout << "branch id is" << b.branch_id << endl;
					cout << " branch name " << b.branch_name << endl;
					cout << "branch address " << b.address << endl;
					cout << "branch pincode " << b.pincode << endl;
					cout << " branch principal " << b.principal << endl;
					cout << " branch phone num " << b.phone_n << endl;
					count++;
				}
	}

	void remove_branch() {
		int k;
		cout << "enter how many branches u want to remove \n";
		cin >> k;
		vector<int>branchid;
		for (int i = 0; i < k; i++) {
			int ids;
			cout << "enter branchs id to remove \n";
			cin >> ids;
			branchid.push_back(ids);
		}
		for (int i = 0; i < branchid.size(); i++) {

			bool found = false;
			for (int j = 0; j < branches.size(); j++) {

				if (branches[j].branch_id == branchid[i]) {
					branches.erase(branches.begin() + j);
					found = true;
					total_branches--;
					break;

				}
			}
			if (!found)cout << "id " <<branchid[i] << " u entered not found \n";

		} 

		saveall_branches();
	}

	void show_branch() {
		int h;
		cout << "enter branch is id \n";
		cin >> h;
		bool found = false;
		for (int i = 0; i < branches.size(); i++) {
			if (branches[i].branch_id == h) {
				found = true;
				cout << "=========== BRANCH DETAILS ===========\n";
				cout << "Branch ID       : " << branches[i].branch_id << endl;
				cout << "Branch Name     : " << branches[i].branch_name << endl;
				cout << "Branch Address  : " << branches[i].address << endl;
				cout << "Branch Pincode  : " << branches[i].pincode << endl;
				cout << "Principal       : " << branches[i].principal << endl;
				cout << "Phone Number    : " << branches[i].phone_n << endl;
				break;
			}
		}
		if (!found)cout << "not found entered id" << h;

	}
	
	
	void add_student() {
		
		int choice = 0;
		cout << "select the branch u want to add student\n ";
		for (int d = 0; d < branches.size(); d++) {

			cout << d + 1 << " ." << branches[d].branch_id <<
			     " --" << branches[d].address << endl;
		 }
		cin >> choice;
		bool found = false;
		for (int i = 0; i < branches.size(); i++) {
			
			if (choice == branches[i].branch_id) {
				found = true;
				cout << "id u selected  is found" << branches[i].branch_id;
				branches[i].add_student();

				break;
			}
		}
		if (!found)cout << " wrong id entered \n";
	}

	void add_teacher() {
		int choice;
		bool found = false;
		cout << " enter branch id to which u want to add teacher \n";
		for (int i = 0; i < branches.size(); i++) {

			cout << i + 1 << ". " << branches[i].branch_id <<
				" " << branches[i].address << endl;
		}
		cin >> choice;

		for (int w = 0; w < branches.size(); w++) {

			if (choice == branches[w].branch_id) {
				found = true;
				cout << "entered id is found \n" <<
					"noe add the teacher \n";
				branches[w].add_teacher();

				break;
			}
		}
		if (!found)cout << "entered  branch id is not found\n ";
	}


	void remove_student() {
		cout << "enter branch id to remove student\n";
		int choice;
		bool check = false;
		for (int u = 0; u < branches.size(); u++) {

			cout <<  u+1  << ". " << branches[u].branch_id <<
				" --" << branches[u].address;
		}
		cin >> choice;
		for (int i = 0; i < branches.size(); i++) {

			if (branches[i].branch_id == choice) {
				check = true;
				cout << " id found and can remove student \n";
				branches[i].remove_student();
				break;
			}
		}
		if (!check)cout << " branch is nout found which u entered \n" << choice;

	
	}

	void remove_teacher() {
		int choice;
		bool found = false;
		cout << "select branch id from whereu want  to remove teacher \n";
		

		for (int g = 0; g < branches.size(); g++) {

			cout <<g+1 <<". "<<branches[g].branch_id << " --"
				<< branches[g].address<<endl;
		}
		cin >> choice;
		for (int y = 0; y < branches.size(); y++) {

			if (choice == branches[y].branch_id) {
				found = true;
				cout << " u selected id is" << branches[y].branch_id
					<< "start removing \n";
				branches[y].remove_teacher();
				break;
			}
		}
		if (!found)
			cout << " wrong branch id entered \n" << endl;

	}

	void  display_student_details() {
		int choice;
		bool found = false;
		cout << "enter branch id from which u want	to show student details ";
		
		for (int i = 0; i < branches.size(); i++) {
			cout << branches[i].branch_id << "--"
				<< branches[i].address << endl;
		}
		cin >> choice;;
		for (int i = 0; i < branches.size(); i++) {

			if (choice== branches[i].branch_id) {
				found = true;
				branches[i].student_details();
				break;
			}
		}
		if (!found)cout << " wrong branch id entered\n";
	}

	void dispaly_teacher_details() {
		int choice;
		bool found = false;
		cout << "enter branch id from which u want	to show teacher details ";

		for (int i = 0; i < branches.size(); i++) {
			cout << branches[i].branch_id << "--"
				<< branches[i].address << endl;
		}
		cin >> choice; 
		for (int i = 0; i < branches.size(); i++) {

			if (choice == branches[i].branch_id) {
				found = true;
				branches[i].teacher_details();
				break;
			}
		}
		if (!found)cout << " wrong branch id entered\n";
	}
		
	void update_student_details(){
		int choice;
		bool found = false;
		cout << "enter branch id from which u want	to update student  details ";

		for (int i = 0; i < branches.size(); i++) {
			cout << branches[i].branch_id << "--"
				<< branches[i].address << endl;
		}
		cin >> choice;
		for (int i = 0; i < branches.size(); i++) {

			if (choice == branches[i].branch_id) {
				found = true;
				branches[i].update_student_details();
				break;
			}
		}
		if (!found)cout << " wrong branch id entered\n";
	}

	void update_teacher_details()
	
	
	
	
	{
		int choice;
		bool found = false;
		cout << "enter branch id from which u want	to update teacher  details ";

		for (int i = 0; i < branches.size(); i++) {
			cout << branches[i].branch_id << "--"
				<< branches[i].address << endl;
		}
		cin >> choice;
		for (int i = 0; i < branches.size(); i++) {

			if (choice == branches[i].branch_id) {
				found = true;
				branches[i].update_teacher_details();
				break;
			}
		}
		if (!found)cout << " wrong branch id entered\n";
	}

	
};
int main() {

    branch q;

    // Load existing students
    q.load_students();

    // Add a student
    q.add_student();

    return 0;
}
	

	


	return 0;
}
