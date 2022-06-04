#include <bits/stdc++.h>
using namespace std;

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
        // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("23.txt", "r", stdin); freopen("err.txt", "w", stderr);
    #endif  
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
