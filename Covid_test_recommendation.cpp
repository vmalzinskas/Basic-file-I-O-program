#include <iostream>
#include <fstream>
#include <string.h>
#include <string> //This needed for converting string to int
#include <iomanip>
using namespace std;

//Prototypes
void databaseCreater(string databaseName); //creates patient database
void databaseCreater1(string databaseName); //creates symptom database
void databaseCreater2(string databaseName); //creates location database
string databaseAlt1(string databaseName,char add); //alters patient database
void databaseAlt2(string databaseName); //alters symptom database
void databaseAlt3(string databaseName, string location); //alters location database
int idCreator(string databaseName, int databaseLineSize); // Used for generating ID numbers
int printDatabase(string databaseName); // Prints a select database line by line
void positiveDetailsReturn(string databaseName, int lineSize); //Prints positive cases
string idDetailsReturn(string databaseName, int lineSize, string id_number, string patientName);//search functionality returns the patient line from database
void symptomChecker(char userChoice1);// Does the standard display and check for symptoms
void DatabaseSwap(string database,int dataOut, string dataIn, int line, int databaseLineSize);
string printHeadline(string databaseName);
string capitalizer(string input); // for steralizing inputs

int main () 
{
		// Variables.
		int userChoice, databaseLine, userChoice4, databaseline4;
		int * pointUC= &userChoice;
		char userChoice1;
		string test_status, search_line,id_str,pass,pass44;
		string userChoice_of_search, status2, userInput4;
		
		

		databaseCreater("Patient_Database");	//The database is opened/created then closed at the start of the program.
		databaseCreater1("Symptoms_Database");
		databaseCreater2("HR_locations")	;								

		pass="no";
		while (pass=="no"){

			// find out what they want.	
			cout<<endl;
			cout<<"Please choose from the following options and enter it's number."<<endl<<endl
				<<"1. Enter your current details for Covid Test Recommentdaion."<<endl
				<<"2. Submit your COVID test status & update the location database."<<endl
				<<"3. Display the updated locations that are High risk for COVID."<<endl
				<<"4. Update COVID patient details." <<endl
				<<"5. Display all COVID positive patient details in patient database." <<endl
				<<"6. Quit" <<endl<<endl;

			cin>>userChoice;
			if (cin.fail()){
					cout<<"Unknown selection, please try again."<<endl<<endl;
					cin.clear();
					cin.ignore(256,'\n'); //This clears out 256 bytes of crap from cin until the
				}

			cout<<endl;
			// if (userChoice==1||userChoice==2||userChoice==3||userChoice==4||userChoice==5||userChoice==6)
						// pass="yes"; //User made a valid choice					
		
		

					
					switch (userChoice)//switch for the basic choices
					{	
					case 1: // 
						userChoice1='y'; // This structure is left over from testing when I had it asking if a user was new or not
						symptomChecker(userChoice1);
						break;
					case 2:
						cout<<endl;
						cout<<"Please Enter the Patients Id number. (ID: 0000000000000#)"<<endl;
						cin.ignore();
						getline(cin,userChoice_of_search);
						cout<<"Please enter your Test results. (POSITIVE/NEGATIVE)"<<endl;
						getline(cin, test_status);
						test_status = capitalizer(test_status);
						search_line=idDetailsReturn("Patient_Database", 150, userChoice_of_search,"N/A");
						databaseLine = stoi(userChoice_of_search);  //Convert ID serch string to int as the id is also the line in the patient records occupied
						
						// open the patient database and go to the correnct line and alter it

						DatabaseSwap("Patient_Database", 120,  test_status,  databaseLine,  162);//include the new line size
						cout<<printHeadline("Patient_Database")<<endl;
						cout<<idDetailsReturn("Patient_Database", 150, userChoice_of_search, "N/A")<<endl;//search functionality returns the patient line from database


						if (test_status[0]=='P'){
			 						int travel_times;
			 						cout<<endl;
			 						cout<<"How many times have you travelled from your home in the last 2 weeks?"<<endl;
			 						cin>>travel_times;
			 							cin.ignore();
			 							for (int i = 1; i<=travel_times; i++){
				 								string location = "-------";
				 								cout<<"Enter location "<<i<< " description. "<<endl;
				 								getline(cin,location);
				 								if (location.size()>55)
				 								location.erase(55);
				 							  databaseAlt3("HR_locations", location);
			 							}
			 					}

						break;
					case 3: 
						printDatabase("HR_locations");
						// databaseAlt3("HR_locations");
						break;
					case 4:	
						cout<<endl;
						cout<<"Please Enter the Patients name or ID number.(NAME: FIRST SURNAME),(ID: 0000000000000#)"<<endl;
						cin.ignore();
						getline(cin,userChoice_of_search);
						databaseline4 =stoi(userChoice_of_search);
						cout<<endl;
						cout<<printHeadline("Patient_Database")<<endl;
						cout<<idDetailsReturn("Patient_Database", 150, userChoice_of_search,userChoice_of_search)<<endl;
						
						pass44="no";
						while (pass44=="no"){
						cout<<endl<<endl<<"Which patient detail would you like to update? "<<endl<<endl
								<<"1. Name.(NAME: FIRST SURNAME)"<<endl
								<<"2. Date of birth.(dd/mm/yyyy)"<<endl
								<<"3. Address.(LIMIT 35 CHARACTERS)"<<endl
								<<"4. Last overseas travel.(dd/mm/yyyy)"<<endl
								<<"5. Current state of mortality. (ALIVE/DEAD)."<<endl;				

						cin>>userChoice4;
								cout<<endl;

								if (userChoice4==1||userChoice4==2||userChoice4==3||userChoice4==4||userChoice4==5)
									pass44="yes";
								else{
									cin.clear();
									cin.ignore(256,'\n'); //This clears out 256 bytes of crap from cin until the
									cout<<"Unknown selection, please try again."<<endl;
								}
							}

								switch(userChoice4){
									case 1:
										cout<<endl<<"What is your current name? (NAME: FIRST SURNAME)"<<endl;
										cin.ignore();
										getline(cin,userInput4);
										DatabaseSwap("Patient_Database", 15,  userInput4,  databaseline4,  162);//include the new line size

									break;
									case 2:
										cout<<endl<<"What is your current date of birth? (dd/mm/yyyy)"<<endl;
										cin.ignore();
										getline(cin,userInput4);
										DatabaseSwap("Patient_Database", 45,  userInput4,  databaseline4,  162);//include the new line size

									break;
									case 3:
										cout<<endl<<"What is your current address? (LIMIT 35 CHARACTERS)"<<endl;
										cin.ignore();
										getline(cin,userInput4);
										DatabaseSwap("Patient_Database", 60,  userInput4,  databaseline4,  162);//include the new line size

									break;
									case 4:
										cout<<endl<<"When was your last overseas travel? (dd/mm/yyyy)"<<endl;
										cin.ignore();
										getline(cin,userInput4);
										DatabaseSwap("Patient_Database", 95,  userInput4,  databaseline4,  162);//include the new line size

									break;
									case 5:
										cout<<endl<<"What is you current state of mortality. (ALIVE/DEAD)"<<endl;
										cin.ignore();
										getline(cin,userInput4);
										userInput4=capitalizer(userInput4);
										DatabaseSwap("Patient_Database", 135,  userInput4,  databaseline4,  162);//include the new line size

									break;
								}
							

						DatabaseSwap("Patient_Database", 120,  "positive",  1,  162);//include the new line size

						break;
					case 5:
					 	positiveDetailsReturn("Patient_Database", 162);
						break;
					case 6:	
						cout<<"Goodbye"<<endl;
						pass="yes";
						break;
					}
					}			
return 0;
}








//////////////////////////////////////////////////////////////////////////////////
/*This function will create and close a Patient database based on the name chosen. 
So there will always be a database existing when the program is run*/

 void databaseCreater(string databaseName){
 	//local variables
 	char create,add;
 	
 	//Check if file exists which will happen if the program has been run previously and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(databaseName.c_str()); //opening the database
 	if(databaseCheck.fail()){ // If the database doesnt exist it creates it with headings.
 		ofstream databaseCreate;
 		databaseCreate.open(databaseName.c_str());
 		databaseCreate
 		<<setw(15)<<left<<"ID_number:"
 		<<setw(30)<<left<<"Patient_Name:"
 		<<setw(15)<<left<<"Date_of_Birt:"
 		<<setw(35)<<left<<"Address:"
 		<<setw(25)<<left<<"Last_overseas_travel:"
 		<<setw(15)<<left<<"Covid_test:"
 		<<setw(25)<<left<<"Life status:(Alive/Dead)"<<endl;
 		databaseCreate.close(); //Closes the file until program wants it again.
 	}
 }

/////////////////////////////////////////////////////////////////////////////////
/*This function will create and close a symptom database based on the name chosen. 
So there will always be a database existing when the program is run*/

void databaseCreater1(string databaseName){
 	//local variables
 	char create,add;
 	
 	//Check if file exists which will happen if the program has been run previously and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(databaseName.c_str()); //opening the database
 	if(databaseCheck.fail()){ // If the database doesnt exist it creates it with headings.
 		ofstream databaseCreate;
 		databaseCreate.open(databaseName.c_str());
 		databaseCreate
 		<<setw(10)<<left<<"Risk:"
 		<<setw(50)<<left<<"Description:"<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Aches and Pains."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Sore throat."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Diarrhoea."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Conjunctivitis."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Headache."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Loss of taste or smell."<<endl
 		<<setw(10)<<left<<"Low:"
 		<<setw(50)<<left<<"Rash on skin, or discolouration of fingers or toes."<<endl
 		<<setw(10)<<left<<"Medium:"
 		<<setw(50)<<left<<"Fever."<<endl
 		<<setw(10)<<left<<"Medium:"
 		<<setw(50)<<left<<"Dry Cough.:"<<endl
 		<<setw(10)<<left<<"Medium:"
 		<<setw(50)<<left<<"Tiredness:"<<endl
 		<<setw(10)<<left<<"HIGH:"
 		<<setw(50)<<left<<"Difficulty breathing of shortness of breath."<<endl
 		<<setw(10)<<left<<"HIGH:"
 		<<setw(50)<<left<<"Chest pain or pressure on chest."<<endl
 		<<setw(10)<<left<<"HIGH:"
 		<<setw(50)<<left<<"Loss of speech or movement."<<endl;


 		databaseCreate.close(); //Closes the file until program wants it again.
 	}
 }


 ////////////////////////////////////////////////////////////////////////////////
 /*This function will create and close a location database based on the name chosen. 
So there will always be a database existing when the program is run*/

  void databaseCreater2(string databaseName){
 	//local variables
 	char create,add;
 	
 	//Check if file exists which will happen if the program has been run previously and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(databaseName.c_str()); //opening the database
 	if(databaseCheck.fail()){ // If the database doesnt exist it creates it with headings.
 		ofstream databaseCreate;
 		databaseCreate.open(databaseName.c_str());
 		databaseCreate
 		<<setw(15)<<left<<"Location_ID:"
 		<<setw(55)<<left<<"Description (55 char limit)"<<endl; //Lines in database are 52 Long
 		databaseCreate.close(); //Closes the file until program wants it again.
 	}
 }

 //////////////////////////////////////////////////////////////////////////////////
 /* This function opens the patient Datbase and adds a new set of data 
 to it*/

 string databaseAlt1(string databaseName,char add){
 	
 	//local variables
 	int id_number;
 	char create;//add;
 	string filename = databaseName;
 	string patient_Name,date_of_Birth,address,locations;
 	string date_time,last_overseas_travel,covid_test,status;

 	//Check if file exists and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(filename.c_str()); //opening
 	if(databaseCheck.fail()){
 		databaseCheck.close();
 		cout<<"The database "<<databaseName<<" currently does not exist or is empty."<<endl;
 	}

 	else{
 		cout<<"The database "<<databaseName<<" exist."<<endl;
 			// <<"Would you like to add new patient to "<<databaseName<<" ? y/n"<<endl; //from testing 
 			// cin>>add;
 			if (add=='y'){
 				
 				cout<<"Please enter the following:"<<endl
 					<<"Patient's Name. (NAME: FIRST SURNAME)"<<endl;
 					cin.ignore();										// List catergories in patient database, also truncate the inputs to be the correct lenth
 					getline(cin,patient_Name);
 					if (patient_Name.size()>30)
 						patient_Name.erase(30);

 					cout<<"Patient's Date of birth. (dd/mm/yyyy)"<<endl; 				
 					getline(cin,date_of_Birth);
 					if (date_of_Birth.size()>15)
 						date_of_Birth.erase(15);

 					cout<<"Patient's address.(LIMIT 35 CHARACTERS)"<<endl; 					
 					getline(cin,address); 				
 					if (address.size()>35)
 					address.erase(35);

 					cout<<"Patient's date of last overseas travel. (dd/mm/yyyy)"<<endl;
 					getline(cin, last_overseas_travel);
 					if (last_overseas_travel.size()>25) 					
 					last_overseas_travel.erase(25);

 					cout<<"Patient covid test results. (POSITIVE/NEGATIVE) "<<endl;
 					getline(cin, covid_test);
 					covid_test = capitalizer(covid_test);
 					if (covid_test.size()>15) 			
 					covid_test.erase(15);

 					cout<<"Patient's current state of mortality. (ALIVE/DEAD)."<<endl;
 					getline(cin, status);
 					status = capitalizer(status);
 					if (status.size()>25)
 					status.erase(25);
 					// If positive add to database


 					if (covid_test=="POSITIVE"){
 						int travel_times;
 						cout<<"How many times did the patient travel from their home in the last 2 weeks?"<<endl;
 						cin>>travel_times;
 							cin.ignore();
 							for (int i = 1; i<=travel_times; i++){
	 								string location = "-------";
	 								cout<<"Enter location "<<i<< " description. "<<endl;
	 								getline(cin,location);
	 								if (location.size()>55)
	 								location.erase(55);
	 							  databaseAlt3("HR_locations", location);
 							}
 					}

 				ofstream databaseAdd;   		// Open file and write all data
 				databaseAdd.open(filename.c_str(),ofstream::app);
 				databaseAdd.seekp(0,ios::end);

 				id_number = idCreator("Patient_Database",150); //This needs to be the length of the patient database line

 				cout<<endl
 						<<"The patients ID number will be "
 						<<setw(14)<<setfill('0')<<id_number
 						<<". Please keep it safe."<<endl;

 				databaseAdd
 				<<setw(30)<<left<<patient_Name
 				<<setw(15)<<left<<date_of_Birth
 				<<setw(35)<<left<<address
 				<<setw(25)<<left<<last_overseas_travel
 				<<setw(15)<<left<<covid_test
 				<<setw(25)<<left<<status<<endl;

 				databaseAdd.close();

 			
 	}
 }
return status;
}


 ///////////////////////////////////////////////////////////////////////////////////////////
// This function add informations set to the symptoms database

 void databaseAlt2(string databaseName){

 	//local variables
 	char create,add;
 	string pass;
 	string filename = databaseName;
 	
 	//Check if file exists and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(filename.c_str()); //opening
 	if(databaseCheck.fail()){
 		databaseCheck.close();
 		cout<<"The database "<<databaseName<<" currently does not exist or is empty."<<endl;
 			
 	}
 	else{
 		 	cout<<"The database "<<databaseName<<" exist."<<endl;
 			cout<<"Would you like to add new symptom to "<<databaseName<<" ? y/n"<<endl;
 			cin>>add;

 			pass="no";
 			while (pass=="no"){	
 				add=toupper(add); 		
	 			if (add=='Y'||add=='N')
	 				pass="yes";	 			 
	 			else {
	 				cout<<"Sorry unknown selection, please try again."<<endl;
	 			 	cin>>add;
	 			}
	 				
 			}

 			if (add=='Y'){
 				string risk,description;
 				cout<<"Please enter the following:"<<endl
 					<<"Risk ?"<<endl;
 					cin.ignore();
 					getline(cin,risk); 					
 					cout<<"Description?"<<endl; 				
 					getline(cin,description);
 				ofstream databaseAdd;
 				databaseAdd.open(filename.c_str(),ofstream::app);
 				databaseAdd.seekp(0,ios::end);
 				databaseAdd<<risk<<"\t"<<description<<endl;
 				databaseAdd.close();

 			}
 	}
 }
 ///////////////////////////////////////////////////////////////////////
 // This function opens and adds locations to the location database

  void databaseAlt3(string databaseName, string location){

 	//local variables
 	char create,add;
 	string filename = databaseName;
 	string description=location;
 	
 	//Check if file exists and create if needed.
 	ifstream databaseCheck;
 	databaseCheck.open(filename.c_str()); //opening
 	if(databaseCheck.fail()){
 		databaseCheck.close();
 		cout<<"The database "<<databaseName<<" currently does not exist or is empty."<<endl;
 			
 	}
 	else{
 		///// The bit below is left over from manual testing

 		// cout<<"The database "<<databaseName<<" exist."<<endl
 		// 	<<"Would you like to add new loation to "<<databaseName<<" ? y/n"<<endl;
 		// 	cin>>add;
 		// 	if (add=='y'){

 				idCreator(filename,52);

 				// string location_ID,description;
 				// cout<<"Please enter the an area Decription?"<<endl;
 				// 	cin.ignore();
 				// 	getline(cin,description);
 									
 				ofstream databaseAdd;
 				databaseAdd.open(filename.c_str(),ofstream::app);
 				databaseAdd.seekp(0,ios::end);
 				databaseAdd<<setw(35)<<left<<description<<endl;
 				databaseAdd.close();

 			}
 }
 



 //////////////////////////////////////////////////////////////
/* This function will read an ID from a file and create a variable based on it
so that future submisions to the Database can be added with following 
ordered ID numbers.*/

int idCreator(string databaseName, int databaseLineSize){

//Variables

	int last_ID_number,line_number,new_ID_number; //line number is ID number, first line is line 0 
	
	ifstream databaseRead;

	databaseRead.open(databaseName.c_str()); //open database for reading
	databaseRead.seekg(-databaseLineSize, ios::end);//open at the start of the last filled line of the file
	line_number = (databaseRead.tellg())/databaseLineSize; //Tells me positon, first line is line 0
	databaseRead>>last_ID_number; // Finds if location, symptom, patient id type and number of last entry
	new_ID_number=last_ID_number+1;
	databaseRead.close();

	// cout<<"line number "<<line_number<<endl;      // This section is for debugging
	// cout<<"last ID num "<<last_ID_number<<endl;
	// cout<<"new ID num "<<new_ID_number<<endl;

	
	
	ofstream databaseWrite; //Write new ID type and number to file.
	databaseWrite.open(databaseName.c_str(),ofstream::app);
	databaseWrite.seekp(0,ios::end);
	databaseWrite<<setw(14)<<setfill('0')<<new_ID_number<<" ";
	databaseWrite.close();


return new_ID_number;
}

/////////////////////////////////////////////////////////////////////////
// This function prints an entire database
// Local variables
	string line; // a string for each line

int printDatabase(string databaseName){
	ifstream databaseRead;
	databaseRead.open(databaseName.c_str());
	if (databaseRead.fail()){
		cout<<"This database is empty or does not exist."<<endl;
		return 1;
	} 
	else{
	while (databaseRead.good()){
		getline(databaseRead, line); // Get each line and print
		cout<<line<<endl;
	}
	databaseRead.close();
	return 0;
	}
}
	//////////////////////////////////////////////////////////////////////

/* This function prints out positive Patient data based on the
where postion 150 on each line of the database contains a p or not.
This is the location for the positve status, will have to make sure 
entry is standardised.*/

void positiveDetailsReturn(string databaseName, int lineSize){
// local variables
	string covid_status,line,junk,junk1;
	int line_number = 1;
	ifstream databaseRead;

	databaseRead.open(databaseName.c_str());
	if (databaseRead.fail())
		cout<<"[]-The Database is empty."<<endl;
	else{
	getline(databaseRead,line);
	cout<<line<<endl;
	databaseRead.seekg(lineSize,ios::beg);

		while (databaseRead.good()){
			getline(databaseRead, line);
			if (line[120]=='p'||line[120]=='P')//checking if positive based on position of 120 on  line
				cout<<line<<endl;
		
		}

	databaseRead.close();
	}
}
/////////////////////////////////////////////////////
/* This function should search by ID and or name and return the correct
line for updating. */

string idDetailsReturn(string databaseName, int lineSize, string idNumber, string patientName){
// local variables
	string line, patient_name_read,id_number_read;// we want to operate on the patient name but not wreck the original.
	string pateintName_adjusted = patientName;
	int line_number = 1; 
	int dynamic_line_size; //we have to pad out the size of the name input to 30 characters so it compares correctly.
	int name_pad_size =30-patientName.size();
	string pad_string(name_pad_size,' '); //for some reason needs to be declared in the line as a string
										// Creates a string of spaces the length of pad size	
	ifstream databaseRead;

	databaseRead.open(databaseName.c_str());
	if (databaseRead.fail()){
		cout<<"[]-The Database is empty."<<endl;
	}
	else{
	databaseRead.seekg(lineSize,ios::beg);

		while (databaseRead.good()){ // Work down the lines of a file
			getline(databaseRead, line); // Get each line of the file
			dynamic_line_size = line.size(); //This is so I don't have to hard code line size.

			if (dynamic_line_size>30){
				id_number_read = line.substr(0,14); // These substrings go to the index of the first number and grab the second number worth of elements.
				patient_name_read = line.substr(15,30);	
				pateintName_adjusted.append(pad_string); // Now the argument patientName_adjusted is padded to the correct length for comparison
			}
			

			if (id_number_read==idNumber || patient_name_read == pateintName_adjusted ){ //Compares Id number and name with file and prints the line where ther is a match
					// cout<<"here to check "<<line<<endl; //Left over from testing what line is returned
				break; //break out of while loop
			}
			pateintName_adjusted=patientName;
		}

	databaseRead.close();
	}
return line;
}

///////////////////////////////////////////////////////////
/* This file selects a symptom and recomends a treatment*/
void symptomChecker(char userChoice1){
//local variables
string userChoice2,userChoice3,pass,status;

          			status=databaseAlt1("Patient_Database",'y');

                if (status=="ALIVE"){   //This takes the new patient data and adds to it will seperate the location data.
                cout<<endl;
                cout<<"Do you have any of the following symptoms? y/n "<<endl<<endl;
                // printDatabase("Symptoms_Database");
                if (printDatabase("Symptoms_Database") == 1)
                	cout<<"Unable to recomend COVID Test- required data missing."<<endl;
                 	
                 	pass="no";
                	while (pass=="no"){
	                 	cin>>userChoice3;
	                 	userChoice3 = capitalizer(userChoice3); //capitalize the answer

	                 	if (userChoice3=="Y"||userChoice3=="N"){
	                 		pass="yes";
	                 	}
	                 	else {
	                 		cout<<"Unknown selection, please try again."<<endl;
	                 		pass="no";

	                 	}
                 	}
                 	

                if (userChoice3=="N"){
                				cout<<endl;
                        cout<<"It is not recommended that you get a COVID-19 test. If symptoms persist for more than a few days"<<endl
                            <<"contact you medical providor for assessment."<<endl;
                    return;
                  }
                else{
                    cout<<"Please type in the highest degree of Risk your sypmtom has. i.e., Low, Medium, HIGH"<<endl;
                    

                  pass="no";
                	while (pass=="no"){

	                 	cin>>userChoice2;
	                 	userChoice2=capitalizer(userChoice2);

	                 	if (userChoice2=="HIGH"||userChoice2=="MEDIUM"||userChoice2=="LOW"){
	                 		pass="yes";
	                 	}
	                 	else {
	                 		cout<<"Unknown selection, please try again."<<endl;
	                 		pass="no";
	                 	}
                 	}


                    
                    if(userChoice2=="HIGH"){
                    		cout<<endl;
                        cout<<"Seek medical attention immediately, and get a covid test. For Australian medical emergency dial '000'."<<endl;
                    }
                    else if (userChoice2=="MEDIUM"){
                    		cout<<endl;
                        cout<<"It is recommended that you get a COVID-19 test immediately, and isolate until you recieve your results."<<endl
                                <<"If your results return a positive result, isolate for 14 days and retest for COVID-19 on your 10th day."<<endl
                                <<"If you  results are negative you may leave isolation. "<<endl;
                    }
                    else if (userChoice2=="LOW"){
                    		cout<<endl;
                        cout<<"It is not recommended that you get a COVID-19 test. If symptoms persist for more than a few days"<<endl
                                <<"contact you medical providor for assessment."<<endl;
                    }

                }
}
else if (status == "DEAD"){
	cout<<endl;
	cout<<"As the patient is dead there is no need in a COVID-19 test."<<endl;
}
}
////////////////////////////////////////////////////////
/* This program swaps information in a database of user entered information.
It uses an fstream object opposed to either if or ofstream as I need to swap
between the two mid file.*/

void DatabaseSwap(string database, int dataOut, string dataIn, int line, int lineSize){

//local variables
	string data;

	fstream databaseReadWrite;
	databaseReadWrite.open(database.c_str());
	databaseReadWrite.seekg(lineSize*line+dataOut, ios::beg);

	if (dataOut==15)
	databaseReadWrite<<setw(30)<<left<<dataIn;
	// cout<<data;
	if (dataOut==45)
	databaseReadWrite<<setw(15)<<left<<dataIn;
	// cout<<data;
	if (dataOut==60)
	databaseReadWrite<<setw(35)<<left<<dataIn;
	// cout<<data;
	if (dataOut==95)
	databaseReadWrite<<setw(25)<<left<<dataIn;
	// cout<<data;
	if (dataOut==120)
	databaseReadWrite<<setw(15)<<left<<dataIn;
	// cout<<data;
	if (dataOut==135)
	databaseReadWrite<<setw(25)<<left<<dataIn;
	// cout<<data;





	databaseReadWrite.close();

}
///////////////////////////////////////////////////////////
/*This function prints headlines from database*/
string printHeadline(string databaseName){

	string headLine;
	ifstream databaseRead;

	databaseRead.open(databaseName.c_str());
	getline(databaseRead,headLine);


return headLine;
}

///////////////////////////////////////////

// This function converts a string  capital letters

string capitalizer(string input){

    for (int i=0;i<=input.size();i++){
        input[i]= toupper(input[i]);
        // cout<<input[i]; //for testing
    }
return input;
}