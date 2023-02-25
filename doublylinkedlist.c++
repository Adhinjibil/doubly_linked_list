#include <iostream> //header files
using namespace std;
struct Node 
{ 
public:
string name,reg;
int math,dsa,ade,coa,oodp,avg;
char grade;
Node* next;
Node* prev;
} *head=NULL; 
void grading(Node* temp) //function for allotting grade
{ 
int sum=0; 
sum=temp->math + temp->dsa + temp->ade + temp->coa + temp->oodp; 
temp->avg=sum/5; 
if(temp->avg>=90) 
temp->grade='O'; 
else if(temp->avg>=80 && temp->avg<90) 
temp->grade='A'; 
else if(temp->avg>=70 && temp->avg<80) 
temp->grade='B'; 
else if(temp->avg>=60 && temp->avg<70) 
temp->grade='C'; 
else if(temp->avg>=50 && temp->avg<60) 
temp->grade='D'; 
else
temp->grade='F'; 
} 
void push() //function for pushing data 
{ 
Node* new_node = new Node();
cout<<"\n Enter the following details of student"; 
cout<<"\n\tName : "; 
cin>>new_node->name; 
cout<<"\n\tRegistration number : "; 
cin>>new_node->reg; 
cout<<"\n\tMarks obtained in Math [100] : "; 
cin>>new_node->math; 
cout<<"\n\tMarks obtained in DSA [100] : "; 
cin>>new_node->dsa; 
cout<<"\n\tMarks obtained in ADE [100] : "; 
cin>>new_node->ade; 
cout<<"\n\tMarks obtained in COA [100] : ";
cin>>new_node->coa; 
cout<<"\n\tMarks obtained in OODP [100] : "; 
cin>>new_node->oodp; 
new_node->next=NULL; 
if(head==NULL) 
 { 
head=new_node;
new_node->prev=NULL; 
 } 
else
 { 
Node* temp = head;
while(temp->next!=NULL) 
 { 
temp=temp->next; 
 } 
temp->next=new_node;
new_node->prev=temp;
 } 
grading(new_node);
} 
void print(Node *temp) //function for 
printing data
{ 
cout<<"\n Name of the student: "<<temp->name; 
cout<<"\n Registration number: "<<temp->reg; 
cout<<"\n Marks obtained "; 
cout<<"\n\tMath = "<<temp->math; 
cout<<"\n\tDSA = "<<temp->dsa; 
cout<<"\n\tADE = "<<temp->ade; 
cout<<"\n\tCOA = "<<temp->coa; 
cout<<"\n\tOODP = "<<temp->oodp; 
cout<<"\n\tAverage = "<<temp->avg; 
cout<<"\n\tGrade = "<<temp->grade; 
} 
void printList() //function for 
printing list in each direction
{ 
Node* temp = head;
cout<<"\n Forward travesing\n"; 
cout<<" ............. "; 
while(temp->next!=NULL) // Start with the front node and visit all the nodes until
//the node becomes NULL.
 { 
print(temp);
temp=temp->next; 
 } 
print(temp);
cout<<"\n\n Backward travesing\n"; 
cout<<" .............. "; 
while(temp->prev!=NULL) //Start with the end node and visit all the nodes 
//until the node becomes NULL.
 { 
print(temp);
temp=temp->prev; 
 } 
print(temp);
} 
int main() //main function
{ 
int n;
cout<<"\n Enter the number of entries to be made: "; 
cin>>n;
for(int i=0;i<n;i++)
 { 
push();
cout<<"\n"; 
 } 
printList();
return 0;
}
