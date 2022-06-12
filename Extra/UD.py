

from pickle import NONE
 


class Patient:
    def init(self, Code, Name, age, doctorName, billAmount):
        self.Code = Code
        self.Name = Name
        self.age = age
        self.doctorName = doctorName
        self.billAmount = billAmount


class Doctor:
    Doctor = "UD"

    def init(self, PatientList):
        # self.Doctor = Doctor
        self.PatientList = PatientList

    def findPatientWithMaximumAge(self):
        ans = -1
        obj = []
        for i in self.PatientList:
            if int(i[2]) > ans:
                ans = int(i[2])
                obj = i
        if ans == -1:
            return NONE
        return obj

    def sortPatientByBillAmount(self):
        lis = []
        for val in self.PatientList:
            lis.append(float(val[4]))
        if len(lis) == 0:
            return NONE
        return sorted(lis)

# if name == "main":


inp = []
n = int(input())
for i in range(n):
    arr = []
    for i in range(5):
        x = input()
        arr.append(x)
    obj = Patient()
    obj.Code = arr[0]
    obj.age = arr[1]
    obj.Name = arr[2]
    obj.doctorName = arr[3]
    obj.billAmount = arr[4]
    inp.append(arr)
obj1 = Doctor()
obj1.PatientList = inp
val = obj1.findPatientWithMaximumAge()
val2 = obj1.sortPatientByBillAmount()
for val in val:
    print(val)
for i in val2:
    print(i)
    
    
    
    
    
    5
uniyhwqh
ngpuxlm
66
klqtaby
951.0
vexhgdb
yitlxrm
53
fbzbgr
520.0
itnobkg
siiarnm
17
qdqmczm
288.0
xlaheaf
cqosyec
94
pbuweui
633.0
otxlyfu
vcybcng
59
ydbfrnx
356.0







C++
class Patient{
    string code;
    string name;
    int age;
    string doctorName;
    double billAmount;
    Patient(string code,string name,int age,string doctorName,double billAmount){
        this.code = code;
        this.name = name;
        this.age = age;
        this.doctorName = doctorName;
        this.billAmount = billAmount;
    }
};

class Doctor{
    string doctor;
    vector<Patient> PatientList;
    Doctor(Patient PatientList){
        this.PatientList = PatientList;
    }

    int findPatientWithMaximumAge(){
        int n = PatientList.size();
        int maxi = INT_MIN; int pos = -1;
        for(int i=0;i<n;i++){
            if(maxi > PatientList[i].age){
                maxi = PatientList[i].age;
                pos = i;
            }
        }
        return pos;
    }
    vector<double> sortPatientByBillAmount(){
        int n = PatientList.size();
        vector<double> bills;
         for(int i=0;i<n;i++){
            bills.push_back(PatientList[i].billAmount);
        }
        sort(bills.begin(),bills.end());
        return bills;
    }   
};

int main(){
    int n;cin>>n;
    string code;
    string name;
    int age;
    string doctorName;
    double billAmount;

    vector<Patient> patientlist;
    for(int i=0;i<n;i++){
        cin>>code>>name;
        cin>>age;
        cin>>doctorName;
        cin>>billAmount;
        Patient obj = new Patient(code,name,age,doctorName,billAmount);
        patientlist.push_back(obj);
    }

    Doctor object = new Doctor(patientlist);
    int pos = object.findPatientWithMaximumAge();
    if(pos==-1) cout<<"No Data Found"<<endl;
    else {
        cout<<patientlist[pos].code<<endl;
        cout<<patientlist[pos].name<<endl;
        cout<<patientlist[pos].age<<endl;
        cout<<patientlist[pos].doctorName<<endl;
        cout<<patientlist[pos].billAmount<<endl;
    }

    vector<double> bills = object.sortPatientByBillAmount();
    if(bills.size()==0) cout<<"No Data Found"<<endl;
    else {
        for(int i=0;i<n;i++){
            cout<<bills[i]<<endl;
        }
    }
    return 0;
}
