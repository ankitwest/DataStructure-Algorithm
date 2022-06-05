

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
