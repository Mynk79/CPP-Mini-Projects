#include <iostream>
#include <map>
using namespace std;


// Defining struct Students 
struct student{

      int studentRollNo;
      string studentName;
      string studentFatherName;
      string studentDOB;
      string studentBranch;
      int studentYear;
      int passingYear;
      string studentState;
      int PIN;
      string studentCountry;
};

// Function Prototype/Signature for search the student
void updateStudentByDetail(student *ptr);

// Function prototype/signature for searching the desired student
student* searchStudentIfExist(student *ptr, int studentCount,int rollNumber);

// Function Prototype for creating report on student details
void generateReport(student *rptr, int count);


int main(){

          student ptr[100];
          char deleteChoice;
          student *searchptr;
          int getPosition;
          int choice = 0, count = 0, updateStudentRoll = 0;

          cout << endl << "Welcome to Student Management System";
          while (choice != 5){

                  cout << endl << endl << "1. Add new student to the list. " << endl;
                  cout << "2. Update the record." << endl;
                  cout << "3. Delete the record." << endl;
                  cout << "4. Generate the report." << endl;
                  cout << "5. Exit the system." << endl;
                  cout << "Enter you choice: ";
                  cin >> choice;

                  switch (choice){

                        case 1: 

                              if (count <= 99){

                                    cout << endl << "Enter student Roll Number: ";
                                    cin >> (ptr + count)->studentRollNo;
                                    cin.ignore();
                                    cout << "Enter Student Name: ";
                                    getline(cin,(ptr + count)->studentName);
                                    cout << "Enter Father's Name: ";
                                    getline(cin,(ptr + count)->studentFatherName);
                                    cout << "Enter Student DOB: ";
                                    getline(cin,(ptr + count)->studentDOB);
                                    cout << "Enter student branch: ";
                                    getline(cin,(ptr + count)->studentBranch);
                                    cout << "Enter student joining year: ";
                                    cin >> (ptr + count)->studentYear;
                                    cout << "Enter student passing year: ";
                                    cin >> (ptr + count)->passingYear;
                                    cin.ignore();
                                    cout << "Enter student state: ";
                                    getline(cin,(ptr + count)->studentState);
                                    cout << "Enter student PINCODE: ";
                                    cin >> (ptr + count)->PIN;
                                    cin.ignore();
                                    cout << "Enter student country: ";
                                    getline(cin,(ptr + count)->studentCountry);
                                    count++;
                                    cout << "Thanks! "<< count << " student(s) has been added to the system" << endl;
                                    break;
                              }
                              else{
                                    cout << "Maximum records capacity has reached" << endl;
                                    break;
                              }

                        case 2:

                              if ((count > 0) && (count <= 99)){
                                    cout << endl << "Search for student\n";
                                    cout << "Enter student roll number: ";
                                    cin >> updateStudentRoll;
                                    searchptr = searchStudentIfExist(ptr,count,updateStudentRoll);
                                    if (searchptr != nullptr){
                                          cout << "Ok got it!, what do you want to update for this student ?" << endl;
                                          updateStudentByDetail(searchptr);
                                          break;
                                    }
                                    else {
                                          cout << "No Match found with this roll number";
                                          break;
                                    }
                              }
                              else {
                                    cout << "Currently there are no students records in the database";
                                    break;
                              }

                        case 3:

                              if (count!= 0){
                                    cout << endl << "Delete student record\n";
                                    cout << "Enter student roll number: ";
                                    cin >> updateStudentRoll;
                                    searchptr = searchStudentIfExist(ptr,count,updateStudentRoll);
                                    cout << searchptr->studentName << endl << endl;
                                    if (searchptr != nullptr){

                                          cout << "Do you want to delete the student record with following details" << endl;
                                          cout << "Name: " << searchptr->studentName << endl;
                                          cout << "Father's Name: " << searchptr->studentFatherName << endl;
                                          cout << "Date of Birth: " << searchptr->studentDOB << endl;
                                          cout << "Enter your choice (y/n): ";
                                          cin >> deleteChoice;

                                          if (deleteChoice == 'y'){
                                                cout << "Student record has been deleted";
                                                // delete searchptr;
                                                getPosition = searchptr - ptr;
                                                for (int i = getPosition; i < count; i++){
                                                      *(ptr + i) = *(ptr + i + 1);
                                                }
                                                count--;
                                                searchptr = nullptr;
                                                break;
                                          }
                                          else{
                                                break;
                                          }
                                    }
                                    else{
                                          cout << "No student found with the provided roll number";
                                          break;
                                    }
                              }
                              else{
                                    cout << "Currently there are no students records in the database";
                                    break;
                              }

                        case 4:

                              if (count!= 0){
                                    cout << endl << "Here is the report shown below: " << endl;
                                    generateReport(ptr, count);
                                    break;
                              }
                              else{
                                    cout << "Currently there are no students records in the database";
                                    break;
                              }
                        
                        case 5:

                              cout << "Thanks for using the student management system" << endl << endl;
                              break;
            }
          }


  return 0;
}


// Function Definition for searching student by some information
void updateStudentByDetail(student *ptr){

  int numberDetail;
  string stringDetail;
  int updateChoice;

  while(updateChoice != 10){

    cout << endl << endl << "1. Student Name" << endl;
    cout << "2. Father Name" << endl;
    cout << "3. Date of Birth" << endl;
    cout << "4. Student Branch Name" << endl;
    cout << "5. Joining Year" << endl;
    cout << "6. Passing year" << endl;
    cout << "7. Student State" << endl;
    cout << "8. Student PINCODE" << endl;
    cout << "9. Student Country" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter you choice (like 1,2,..): ";
    cin >> updateChoice;
    cin.ignore();

    switch(updateChoice){

      case 1:
            cout << "Enter Student Name: ";
            getline(cin,stringDetail);
            ptr->studentName = stringDetail;
            break;

      case 2:
            cout << "Enter Father's Name: ";
            getline(cin,stringDetail);
            ptr->studentFatherName = stringDetail;
            break;

      case 3:
            cout << "Enter Student DOB: ";  
            getline(cin,stringDetail);
            ptr->studentDOB = stringDetail;
            break;

      case 4:
            cout << "Enter student branch: ";
            getline(cin,stringDetail);
            ptr->studentBranch = stringDetail;
            break;

      case 5:
            cout << "Enter joining year: ";
            cin >> numberDetail;
            ptr->studentYear = numberDetail;
            break;

      case 6:
            cout << "Enter passing year: ";
            cin >> numberDetail;
            ptr->passingYear = numberDetail;
            break;

      case 7:
            cout << "Enter student state: ";
            getline(cin,stringDetail);
            ptr->studentState = stringDetail;
            break;

      case 8:
            cout << "Enter PINCODE: ";
            cin >> numberDetail;
            ptr->PIN = numberDetail;
            break;

      case 9:
            cout << "Enter student country: ";
            getline(cin,stringDetail);
            ptr->studentCountry = stringDetail;
            break;

      case 10:
            cout << "You have been exited from updation window";
            break;
      }
    }
}


// Function for searching student by roll number (if exists in memory)
student* searchStudentIfExist(student *ptr, int studentCount, int rollNumber){

  for (int i = 0; i < studentCount; i++){
    if ((ptr + i)->studentRollNo == rollNumber){
      return (ptr+i);
    }
  }
  return nullptr;
}


// Function for generating report for the records
void generateReport(student *rptr, int count){

  map<string, int> commonNames;
  map<string, int> commonStates;
  map<string, int> commonCountry;

  // Loop to find the common names of the student 
  for (int i = 0; i < count; i++){
      for (int j = i + 1; j < count; j++){
            if ((rptr + i)->studentName == (rptr + j)->studentName){

                  try{
                       commonNames[(rptr + i)->studentName] = commonNames.at((rptr + i)->studentName);
                  }
                  catch(out_of_range& e){
                        commonNames.insert({(rptr + i)->studentName, 2});
                  }   
                  break;
            }
      }
  }

  // Loop to find the student living in common state 
  for (int i = 0; i < count; i++){
      for (int j = i + 1; j < count; j++){
            if ((rptr + i)->studentState == (rptr + j)->studentState){

                  try{
                       commonStates[(rptr + i)->studentState] = commonStates.at((rptr + i)->studentState);
                  }
                  catch(out_of_range& e){
                        commonStates.insert({(rptr + i)->studentState, 2});
                  }
                  break;
            }
      }
  }

  // Loop to find the student living in common country 
  for (int i = 0; i < count; i++){
      for (int j = i + 1; j < count; j++){
            if ((rptr + i)->studentCountry == (rptr + j)->studentCountry){
                  try{
                       commonCountry[(rptr + i)->studentCountry] = commonCountry.at((rptr + i)->studentCountry) + 1;
                  }
                  catch(out_of_range& e){
                        commonCountry.insert({(rptr + i)->studentCountry, 2});
                  }
                  break;
            }
      }
  }

  if (commonNames.size()){
      cout << endl << "Students with Common Names" << endl;
      for (auto i : commonNames){
            cout << "There are " << i.second << " students with " << i.first << " name. " << endl;
      }
  }

  if (commonStates.size()){
      cout << endl << "Students with Common States" << endl;
      for (auto i : commonStates){
            cout << "There are " << i.second << " students living in " << i.first << " state. " << endl;
      }
  }

  if (commonCountry.size()){
      cout << endl << "Students with Common Countries" << endl;
      for (auto i : commonCountry){
            cout << "There are " << i.second << " students living in " << i.first << " country. " << endl;
      }
  }
}


      

