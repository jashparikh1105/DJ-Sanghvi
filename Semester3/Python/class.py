class Employee:
    def __init__(self,emp_id,name):
        self.emp_id=emp_id
        self.name=name
class Developer(Employee):
    def __init__(self,emp_id,name,p_lang):
        super().__init__(emp_id,name)
        self.p_lang=p_lang
class Tester(Employee):
    def __init__(self,emp_id,name,test_type):
        super().__init__(emp_id,name)
        self.test_type=test_type
class Manager(Employee):
    def __init__(self,emp_id,name):
        super().__init__(emp_id,name)
        self.managed_emp=[]
    def add_dev(self,d):
        self.managed_emp.append(d)
        print("Developer "+d.name+" added\n")
    def add_tester(self,t):
        self.managed_emp.append(t)
        print("Tester "+t.name+" added\n")
    def remove_emp(self,e):
        if e in self.managed_emp:
            self.managed_emp.remove(e)
        print("Employee "+e.name+" removed\n")
    def disp(self):
        print("Employees managed by Manager "+self.name+"\n")
        for e in self.managed_emp:
            print(e.name)
d1=Developer(1,"Priyank","Python")
t1=Tester(2,"Prinkal","BYBIADKX")
m1=Manager(3,"Prathamesh")
m1.add_dev(d1)
m1.add_tester(t1)
m1.remove_emp(d1)
m1.disp()
        
