#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	newEmployee->employee_id=id;
	strcpy(newEmployee->name, name);
	newEmployee->salary=salary;

	return head;
}

//secilen id yesaghip ilk employee yi siler ve listenin head ini dondurur
struct EmployeeNode* deleteEmployee(struct EmployeeNode* head, int id){
	
	struct EmployeeNode* temp = head;	

	if(head==NULL){
		printf("liste bos");
		return head;
	}

	//ilk nodede ise aranan id burasi calisir
	if(head->employee_id==id){
		head = head->next;
		free(temp);
		printf("%d id`li ilk kullanici kaldirildi\n",id);
		return head;
	}

	temp = head->next;
	struct EmployeeNode* prev = head;

	while(temp!=NULL){
		if(temp->employee_id==id){
			prev->next = temp->next;
			free(temp);
			printf("%d id`li ilk kullanici kaldirildi\n",id);
			return head;	
		}
		else{
		temp = temp->next;
		prev = prev->next;
		}
	}
	printf("%d idli calisan bulunamadi\n", id);
	return head;




}	

//secilen employeenin magasini istenilen degerle gunceller returns 1 or 0
int searchAndUpdateSalary(struct EmployeeNode* head, int id, float new_salary){
	struct EmployeeNode* temp = head;

	while(temp!=NULL){
		if(temp->employee_id==id){
			temp->salary = new_salary;
			printf("ilk %d idli calisanin maasi basariyla degistirildi\n",id);
			return 1;	
		}
		else{
			temp = temp->next;
		}
	}	
	printf("%d idli calisan bulunamadi\n", id);
	return 0;

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
