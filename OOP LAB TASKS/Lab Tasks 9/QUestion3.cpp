#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DoctorInterface;
class BillingInterface;

class PatientRecord {
private:
    string name;
    string id;
    string dateOfBirth;

    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<string> billingDetails;

public:
    PatientRecord(string name, string id, string dob)
        : name(name), id(id), dateOfBirth(dob) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData() const {
        return "History: " + join(medicalHistory) +
               ", Treatments: " + join(currentTreatments);
    }

    void updateMedicalHistory(const string& entry) {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string& treatment) {
        currentTreatments.push_back(treatment);
    }

    void addBillingDetails(const string& billingInfo) {
        billingDetails.push_back(billingInfo);
    }

    string getBillingInfo() const {
        return join(billingDetails);
    }

private:
    static string join(const vector<string>& vec) {
        string result;
        for (const auto& item : vec) {
            result += item + "; ";
        }
        return result;
    }

    friend class DoctorInterface;
    friend class BillingInterface;
};

class DoctorInterface {
public:
    static void updateMedicalRecord(PatientRecord& record, const string& entry) {
        record.updateMedicalHistory(entry);
    }

    static void addTreatment(PatientRecord& record, const string& treatment) {
        record.addTreatment(treatment);
    }

    static string viewMedicalData(const PatientRecord& record) {
        return record.getMedicalData();
    }
};

class BillingInterface {
public:
    static void addBill(PatientRecord& record, const string& bill) {
        record.addBillingDetails(bill);
    }

    static string getBillingInfo(const PatientRecord& record) {
        return record.getBillingInfo();
    }
};

class Receptionist {
public:
    static void tryAccess(PatientRecord& record) {
        cout << "[Receptionist] Accessing Public Info: " << record.getPublicData() << endl;
    }
};

int main() {
    PatientRecord patient("John Doe", "12345", "1990-01-01");

    Receptionist::tryAccess(patient);

    DoctorInterface::updateMedicalRecord(patient, "Diabetes");
    DoctorInterface::addTreatment(patient, "Insulin injection");
    cout << "[Doctor] Viewing Medical Data: " << DoctorInterface::viewMedicalData(patient) << endl;

    BillingInterface::addBill(patient, "MRI Scan - $200");
    cout << "[Billing] Billing Info: " << BillingInterface::getBillingInfo(patient) << endl;

    return 0;
}
