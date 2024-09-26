/*
E/18/301
Raviprabha H. B. G.
21/01/2022
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to store each patient data
struct patient{
char NIC[15]; //987401311v
char name[50]; // H.B.G. Raviprabha
char age[5]; //23
char gender[10]; //female
char admission_date[12]; // 12/12/2021
char vaccinated[20]; // 2 nd dose
char bloodGroup[5]; //B+
};

//add a patient
void addPatient(int index, struct patient array[]){
int vacStatus; //to store vaccine status
//create pointer per patient
//struct patient *ptr_patient;
//allocate dynamic memory per patient
//ptr_patient = (struct patient*) malloc (sizeof(struct patient));
//ask and store relevant data for a patient
printf("\nEnter NIC no%8c: ",32 );
scanf("%s",array[index].NIC);
printf("Enter Name%10c: ",32);
//since string name contains spaces also
//fgets( ptr_patient -> name, 50 , stdin);
gets(array[index].name);
printf("Enter Age%11c: ",32);
scanf("%s",array[index].age);
printf("Enter gender%8c: ",32);
scanf("%s",array[index].gender);
printf("Enter Admission date: ");
scanf("%s",array[index].admission_date);
//get the vaccination information
printf("Vaccination status\n1. 1 st dose\n2. 2 nd dose\n3. 3 rd dose\n4. None\nEnter[0-4]%10c: ",32);
scanf("%d", &vacStatus);
//add the relevent vaccination status to the array of structs
if (vacStatus == 1) strcpy(array[index].vaccinated, "1 st dose");
if (vacStatus == 2) strcpy(array[index].vaccinated, "2 nd dose");
if (vacStatus == 3) strcpy(array[index].vaccinated, "3 rd dose");
if (vacStatus == 4) strcpy(array[index].vaccinated, "None");
else if ((vacStatus != 1)&&(vacStatus != 2)&&(vacStatus != 3)&&(vacStatus != 4))strcpy(array[index].vaccinated, "Not mentioned");

printf("Enter blood group%3c: ",32);
scanf("%s", array[index].bloodGroup);
}


//delete a patient
void dltPatient(struct patient array[],int *size){
char NICinput[15];
//ask from user and store the NIC number of patient want to delete
printf("\nEnter NIC no: ");
scanf("%s",NICinput);
int comparison;
//check each added patients and find the NIC of the patient that want to delete
for (int i=0; i<*size; ++i){
    //compare the user given NIC number with existing NIC numbers
    comparison = strcmp(array[i].NIC, NICinput);
    //if relevant NIC found
    if (comparison == 0){
        //replacing the patient need to delete by shifting every elements after that by one and reduce array size by one
        for (int c = i ; c < (*size - 1); c++){
        array[c] = array[c+1];
        //break;
        }
        //display weather desired option succeeded or not
        printf("Patient record deleted\n");
        (*size)--;
        break;
    }
}
//if entered a wrong NIC number display error message
if (comparison!=0){
    printf("NIC number not found\n");
}
}


//show a patient
void showPatient(struct patient array[], int size){
char NICinput[15];
//ask and store the NIC number of patient want to display
printf("\nEnter NIC no%6c: ",32);
scanf("%s",NICinput);
int comparison;
//check each added patients and find the NIC of the patient that want to display
for (int i=0; i<size; ++i){
    //compare the user given NIC number with existing NIC numbers
    comparison = strcmp(array[i].NIC, NICinput);
    //if relevant NIC found
    if (comparison == 0){
        //display all the information entered for that patient
        printf("Name%14c: %s\n", 32, array[i].name);
        printf("Age%15c: %s\n", 32, array[i].age);
        printf("Gender%12c: %s\n", 32, array[i].gender);
        printf("Admission date%4c: %s\n", 32, array[i].admission_date);
        printf("Vaccination status: %s\n", array[i].vaccinated);
        printf("Blood group%7c: %s\n", 32, array[i].bloodGroup);
        break;
    }
}
//if entered a wrong NIC number display error message
if (comparison!=0) printf("NIC number not found\n");
}


//show all patient records
void showAll(int size, struct patient array[]){
//go through all the elements of array of patients and display data
for (int i=0; i<size; ++i){
    printf("\nNIC no%12c: %s\nName%14c: %s\nAge%15c: %s\nGender%12c: %s\nAdmission date%4c: %s\nVaccination staus : %s\nBlood group%7c: %s\n\n", 32,array[i].NIC,32, array[i].name,32, array[i].age,32, array[i].gender,32,array[i].admission_date, array[i].vaccinated, 32, array[i].bloodGroup);
}
}



int main(){

printf("COVID-19 PATIENT MANAGEMENT SYSTEM\n\n");

//database can store 1000 patient details only
struct patient *patientList = malloc (1000 * sizeof(struct patient));

//store the option
int option;
//ask first option from user
printf("0. Quit\n1. Add a Patient Record\n2. Print a Patient Record\n3. Print all Patient Records\n4. Delete a Patient Record\nEnter Option [0-4]\n\n");
//store the option
scanf("%d",&option);
//store the number of patients
int k=0;
//int ptrk = &k;
//iterates until user need quit
while (option!=0){
//check weather user give correct inputs
if (option == 1 || option == 2 || option == 3 || option == 4 ){

//if need to add new patient
if (option == 1){
    //defined function
    addPatient(k, patientList);
    //number of patients increase by one when add a new patient
    k++;
}
//if need to show a patient
if((option == 2) && (k!=0)){
    //defined function
    showPatient(patientList,k);
}
//if need to show all patients
if ((option == 3) && (k!=0)){
    //defined function
    showAll(k,patientList);
}
//if need to delete a patient
if ((option == 4) && (k!=0)){
    //defined function
    dltPatient(patientList,&k);
    //number of patients decrease by one when delete a patient
    //k--;
}
}

//if user gives wrong input (other than 1 2 3 4 5) display error message
else {
    printf("Invalid input");
}
//prompt asking from users the option they need until they enter '5' to quit
printf("\n0. Quit\n1. Add a Patient Record\n2. Print a Patient Record\n3. Print all Patient Records\n4. Delete a Patient Record\nEnter Option [0-4]\n\n");
//store the user option
scanf("%d",&option);

}
//if user input is '5' exit from the programme
exit(0);
//free the dynamic memory
free(patientList);


return 0;
}

