class Student{
char * name;
int rollNo;
public:
void setName(char *);
void setRollNo(int aNo);
};
void Student::setName(char * aName){
if (strlen(aName) > 0)
{
name = new char[strlen(aName)];
strcpy(name,aName);
}
}
void Student::setRollNo(int arollNo){
if(arollNo > 0)
rollNo = arollNo;
}
int main(){
Student aStudent;
aStudent.rollNo = 5;
/* Error: we can not access private member of the class. */
aStudent.name = “Ali”;
/* Error: we can not access private member of the class */
aStudent.setRollNo(1);
aStudent.setName(“Ali”);
/* Correct way to access the data member using public setter functions */
}
