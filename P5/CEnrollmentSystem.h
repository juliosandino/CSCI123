//
// Created by Julio Sandino on 11/22/16.
//

#ifndef P5_CENROLLMENTSYSTEM_H
#define P5_CENROLLMENTSYSTEM_H

#include "CStudentInfo.h"
#include "CCourse.h"
#include "CDepartment.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CEnrollmentSystem {

public:
    string courseFilePath;
    string studentFilePath;
    string departmentFilePath;

    //constructors
    CEnrollmentSystem();
    CEnrollmentSystem(string courses, string students, string departments);
    ~CEnrollmentSystem();

    //functions
    void EnrollSystem();
    int menu ();
    void listAllDepartments();
    void addDepartment();
    bool doesDepartmentExist(string ID);
    void listAllCourses ();
    void addCourse();
    bool doesCourseExist(string CRN);
    void cancelCourse();
    void dropClass();
    void listCoursesOfSpecificDepartment ();
    void listCoursesWithLessSpecificUnit ();
    void listCoursesWithEqualSpecificUnit ();
    void listCoursesWithMoreSpecificUnit ();
    void listCoursesWithSpecificTitle ();
    void listCourseInfoWithSpecificCrn ();
    void listAllStudentsInCourse ();
    void listAllStudentInfoWithSpecificTerm ();
    void listAllStudentInfoWithSpecificLastName ();
    void listStudentInfoWithSpecificId ();
    void Enroll ();
    bool isCoursesArrayOpen(CStudentInfo student);
    void Quit();
    void readStudentInfo();
    void writeStudentInfo();
    void readCourseInfo();
    void writeCourseInfo();
    void readDepartmentInfo();
    int getEnrolledUnits(string studentId);
    CStudentInfo studentByID(string ID);
    string searchId(string first, string last);
    void writeDepartmentInfo();
};


#endif //P5_CENROLLMENTSYSTEM_H
