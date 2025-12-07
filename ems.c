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
	
	//liste bos ise calisir
	if(head == NULL){
		head = newEmployee;
		newEmployee->next=NULL;	
	}
	//listede eleman var ise calisir
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
	//liste bos mu kontrolu
	if(head==NULL){
		printf("liste bos\n");
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

//butun employee listesini konsola yazdirir
void displayAllEmployees(struct EmployeeNode* head){
	if(head==NULL){
		printf("Liste Bos!\n");
		return;
	}
	
	struct EmployeeNode* temp = head;
	printf("----------Calisan Listesi---------\n");
	printf("%-10s%-25s%-10s\n","ID","ISIM","MAAS");
	while(temp!=NULL){
		printf("%-10d%-25s%-10.2f\n",temp->employee_id,temp->name,temp->salary);
		temp = temp->next;
	}	

}

//deallacotes everything
void freeList(struct EmployeeNode* head){

	struct EmployeeNode* temp = head;
	struct EmployeeNode* next = NULL;
	while(temp!=NULL){
		next = temp->next;
		free(temp);
		temp = next;
	}
}


int main (){
	struct EmployeeNode* head = NULL;

	//kullanicidan veri almak icin degiskenler
	int id;
	char name[50];
	float salary;
	int choice;

	while(1){
	printf("Please chose one operation:\n1. Add new employee\n2. Delete employee by ID\n3. Update employee salary by ID\n4. Display all employees\n5. Exit\n");
	scanf("%d", &choice);

	switch(choice){
		case 1: //personel ekleme
			printf("ID giriniz: ");
			scanf("%d", &id);
			printf("ISIM giriniz: ");
			scanf("%s", name);
			printf("MAAS giriniz: ");
			scanf("%f", &salary);
	
			//head i direk fonksiyonun returnune esitliyoruz
			head = insertEmployee(head, id, name, salary);
			printf("personel eklendi\n");
			break;
	
		case 2:  //personel silme
			printf("Silinecek ID yi giriniz: ");
			scanf("%d", &id);

			head = deleteEmployee(head,id);
			break;	

		case 3:  //salary update
			printf("Maasi guncellencek ID yi giriniz: ");
			scanf("%d", &id);
			printf("YENI maasi giriniz: ");
			scanf("%f", salary);
			
			searchAndUpdateSalary(head, id, salary);

		case 4: 
			displayAllEmployees(head);
			break;
		
		case 5: 
			freeList(head);
	       		return 0;

		default: 
			printf("Gecersiz karakter Lutfen tekrar giriniz...");	
	}	
	}

	return 0;
}
