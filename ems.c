#include <stdio.h>
#include <stdlib.h>

struct EmployeeNode{
	int employee_id;
	char name[50];
	float salary;
	struct EmployeeNode* next;
};

//listenin basina yeni employee ekler ve listenin yeni head ini dondurur
struct EmployeeNode* insertEmployee(struct EmployeeNode* head, int id, const char* name, float salary){

	struct EmployeeNode* newEmployee = malloc(sizeof(struct EmployeeNode));
	
	if(head == NULL){
		head = newEmployee;
		newEmployee->next=NULL;	
	}
	else{	
		newEmployee->next=head;
		head = newEmployee;
	}
	
	newEmployee.employee_id=id;
	newEmployee.name=
	newEmployee.salary=salary;
}

//secilen employee yi siler ve listenin head ini dondurur
struct EmployeeNode* deleteEmployee(struct EmployeeNode* head, int){


}

//secilen employeenin magasini istenilen degerle gunceller returns 1 or 0
int searchAndUpdateSalary(struct EmployeeNode* head, int id, float new_salary){


}

//butun employye listesini konsola yazdirir
void displayAllEmployees(struct EmployeeNode* head){


}

//deallacotes everything
void freeList(struct EmployeeNode* head){

}


int main (){
	struct EmployeeNode* head = NULL;

	printf("Please chose one operation:\n1. Add new employee\n2. Delete employee by ID\n3. Update employee salary by ID\n4. Display all employees\n5. Exit\n");
		
	



	return 0;
}
