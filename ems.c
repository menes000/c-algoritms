#include <stdio.h>
#include <stdlib.h>

struct EmployeeNode{
	int employee_id;
	char name[50];
	float salary;
	struct EmployeeNode* next;
};

//listenin basina yeni employee ekler ve listenin yeni head ini dondurur
struct EmployeeNode* insertEmployee(){
	


}

//secilen employee yi siler ve listenin head ini dondurur
struct EmployeeNode* deleteEmployee(){


}

//secilen employeenin magasini istenilen degerle gunceller returns 1 or 0
int searchAndUpdateSalary(){


}

//butun employye listesini konsola yazdirir
void displayAllEmployees(){


}

//deallacotes everything
void freeList(){

}


int main (){
	struct EmployeeNode* head = malloc(sizeof(struct EmployeeNode));
	
	printf("Please chose one operation:\n1. Add new employee\n2. Delete employee\n3. Update employee salary\n4. Display all employees\n5. Exit\n");
		
	



	return 0;
}
