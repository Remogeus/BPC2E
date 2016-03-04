#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

/** class Date - Day, Month, Year **/
class Date
{
public:
    int   SetDate(char* new_date);       //in form DD.MM.YYYY
    int   SetDate(int new_d, int new_m, int new_y); //in form DD,MM,YYYY
    char* GetDate() const;
    int   GetDayVal() const {return Day + 31*Month + 366*Year;}
protected:
    int   Day;
    int   Month;
    int   Year;
};

/** methods for class Date **/

int Date::SetDate(char *new_date)
{
    int d, m, y;
    char *ep;
    d = strtol (new_date,&ep,10);
    if(*ep++ != '.')
    {
        cout << endl << "Wrong format of date!!!" << endl;
        return 1;
    }
    m = strtol (ep,&ep,10);
    if(*ep++ != '.')
    {
        cout << endl << "Wrong format of date!!!" << endl;
        return 1;
    }
    y = strtol (ep,&ep,10);
    if(*ep != NULL)
    {
        cout << endl << "Wrong format of date!!!" << endl;
        return 1;
    }
    if((d < 1) || (d > 31) || (m < 1) || (m > 12) || (y < 1921) || (y > 2020))
    {
        cout << endl << "Wrong value of date!!!" << endl;
        return 2;
    }
    if(((d == 31) && ((m == 2) || (m == 4) || (m == 6) || (m == 9) || (m == 11))) || ((d == 30) && (m == 2)))
    {
        cout << endl << "Wrong value of date!!!" << endl;
        return 2;
    }
    Day = d;
    Month = m;
    Year = y;
    return 0;
}

int Date::SetDate(int new_d, int new_m, int new_y)
{
    if((new_d < 1) || (new_d > 31) || (new_m < 1) || (new_m > 12) || (new_y < 1921) || (new_y > 2020))
    {
        cout << endl << "Wrong value of date!!!" << endl;
        return 2;
    }
    if(((new_d == 31) && ((new_m == 2) || (new_m == 4) || (new_m == 6) || (new_m == 9) || (new_m == 11))) || ((new_d == 30) && (new_m == 2)))
    {
        cout << endl << "Wrong value of date!!!" << endl;
        return 2;
    }
    Day = new_d;
    Month = new_m;
    Year = new_y;
    return 0;
}

char* Date::GetDate() const
{
    char out_date[11];
    sprintf(out_date,"%d.%d.%d", Day, Month, Year);
    return out_date;
}

/** class PersID - child of Date + Tail, Sex **/

class PersID:public Date
{
public:
    int   SetPID(char* new_pid);
    char* GetPID() const;
    char  GetSex() const {return Sex;}
private:
    int Tail;        // PID tail
    char Sex;        // Sex 'f' - woman, 'm' - man
};

/** methods for class PersID **/
int PersID::SetPID(char *new_pid)
{
    int t, y, m, d, test, i;
    long long ymd, ct;
    char *ep, dstr[11], s;
    ymd = strtol (new_pid,&ep,10);
    if(*ep++ != '/')
    {
        cout << endl << "Wrong format of PID!!!" << endl;
        return 3;
    }
    t = strtol (ep,&ep,10);
    if(*ep != NULL)
    {
        cout << endl << "Wrong format of PID!!!" << endl;
        return 3;
    }
    if((t < 0) || (t>9999))
    {
        cout << endl << "Wrong range of PID tail!!!" << endl;
        return 4;
    }
    if((ymd < 101) || (ymd > 996231))
    {
        cout << endl << "Wrong birth date in PID!!!" << endl;
        return 4;
    }
    ct =  ymd * 10000 + t;
    ct = ct % 11;
    if(((ymd * 10000 + t) % 11) != 0)
    {
        cout << endl << "Invalid value of PID tail!!!" << endl;
        return 4;
    }
    y = ymd / 10000;
    ymd -= y* 10000;
    if(y < 21)
        y += 2000;
    else
        y += 1900;
    m = ymd / 100;
    d = ymd - m * 100;
    if(m >= 50)
    {
        s = 'f';
        m -= 50;
    }
    else
        s = 'm';

    test = SetDate(d, m, y);
    if (test)
        return test;
    Sex = s;
    Tail = t;
    return 0;
}

char* PersID::GetPID() const
{
    char out_pid[12], str_auxd[4], str_auxt[4];
    int pid_ymd, n_ord;

    pid_ymd = (Year % 100) * 10000 + Month * 100 + Day;
    if (Sex == 'f')
        pid_ymd += 5000;

    if (pid_ymd < 1000)
        strcpy(str_auxd, "000");
    else if
       (pid_ymd < 10000)
        strcpy(str_auxd, "00");
    else if
       (pid_ymd < 100000)
        strcpy(str_auxd, "0");
    else
        strcpy(str_auxd, "");

    if (Tail < 10)
        strcpy(str_auxt, "000");
    else if
       (Tail < 100)
        strcpy(str_auxt, "00");
    else if
       (Tail < 1000)
        strcpy(str_auxt, "0");
    else
        strcpy(str_auxt, "");

    sprintf(out_pid,"%s%d/%s%d", str_auxd, pid_ymd, str_auxt, Tail);
    return out_pid;
}

/** class Person - FName, SName, Addr, PID **/

class Person
{
public:
    int   SetPerson(char* new_fname, char* new_sname, char* new_addr, char* new_pid);
    char* GetPerson() const;
    int   GetBirthDateVal();
protected:
    char   FName[10];
    char   SName[10];
    char   Addr[30];
    PersID PID;
};

/** methods for class Person **/

int Person::SetPerson(char* new_fname, char* new_sname, char* new_addr, char* new_pid)
{
    strcpy(FName, new_fname);
    strcpy(SName, new_sname);
    strcpy(Addr, new_addr);
    PID.SetPID(new_pid);
}

char* Person::GetPerson() const
{
    char out_person[70];
    char aux[12];
    strcpy(aux, PID.GetPID());
    sprintf(out_person,"%10s %10s %30s pid: %12s", FName, SName, Addr, aux);
    return out_person;
}

int Person::GetBirthDateVal()
{
    int aux;
    aux = PID.GetDayVal();
    return aux;
}


/** class Student - child of Person + Spec, SYear, Qual, QValid**/

class Student:public Person
{
public:
     int SetStudent(char* new_spec, int new_syear, int new_qual, char* new_qvalid);
     char* GetStudent() const;
     int GetQual() {return Qual;};

 private:
    char  Spec[6]; //specialization, e.g. BEST
    int   SYear;   //study year
    int   Qual;    //degree (paragraph) of el. qualification
    Date  QValid;   //date of validity of el. qualification
};

/** methods for class Student **/

int Student::SetStudent(char* new_spec, int new_syear, int new_qual, char* new_qvalid)
{
    strcpy(Spec, new_spec);
    SYear = new_syear;
    Qual = new_qual;
    QValid.SetDate(new_qvalid);
}


char* Student::GetStudent()const
{
    char out_student[70];
    char aux[10];
    strcpy(aux, QValid.GetDate());
    sprintf(out_student,"%10s, year: %3d, el.qual.: par %3d valid till %10s", Spec, SYear, Qual, aux);
    return out_student;
}





/** MAIN function **/

int main()
{
    char txt1[100];
    char txt2[100];

    Student S[10];      //array of 10 objects of student
    int num_st, i, j;

    S[0].SetPerson("Jaroslav", "Novak", "V lesiku 128, 51205 Blounky", "960105/1361");
    S[0].SetStudent("BEST", 1, 4, "13.6.2015");
    S[1].SetPerson("Petr", "Kohout", "Gorbacovova 1, 10000 Praha", "951212/5557");
    S[1].SetStudent("BEST", 2, 5, "20.6.2015");
    S[2].SetPerson("Jana", "Mlsna", "Kojeticka 2, 35611 Dolni Ves", "965525/0231");
    S[2].SetStudent("BBMI", 2, 4, "15.6.2015");
    S[3].SetPerson("Hynek", "Potkal", "Horni 12, 59102 Kunice", "971102/8514");
    S[3].SetStudent("BAUT", 1, 4, "30.5.2015");
    S[4].SetPerson("Martina", "Uzasna", "Nad lesem 996, 69255 Milonice", "966028/4447");
    S[4].SetStudent("BEST", 3, 6, "7.6.2014");
    S[5].SetPerson("Petr", "Psotka", "Pod lesem 12, 69255 Milonice", "951112/4535");
    S[5].SetStudent("BEST", 1, 4, "10.2.2015");
    S[6].SetPerson("Emil", "Kolejnik", "Ujezd 302, 75188 Mrkvojedy", "970102/1990");
    S[6].SetStudent("BEST", 2, 5, "10.6.2015");
    S[7].SetPerson("Josef", "Straka", "Ptaci 96, 66633 Ptacinec", "961010/2260");
    S[7].SetStudent("BEST", 1, 4, "11.6.2015");
    S[8].SetPerson("Ernest", "Kroupa", "Posledni 1, 45236 Oustlice", "970109/5228");
    S[8].SetStudent("BEST", 1, 4, "11.6.2015");
    S[9].SetPerson("Karel", "Halenka", "Poupova 102, 71000 Olomouc", "971119/4889");
    S[9].SetStudent("BEST", 1, 4, "11.6.2015");
    num_st = 10;

    //print all students
    cout << endl << "List of students:" << endl;
    for(i = 0; i < num_st; i++)
    {
        strcpy(txt1, S[i].GetPerson());
        strcpy(txt2, S[i].GetStudent());
        cout << i+1 << ". " << "\t" << txt1 << "  " << txt2 << endl;
    }
    Student tmp;
    cout << endl << "Sorted list of students: " << endl;
    for(j = 0; j < num_st - 1; j++)
    {
        for(int k = 0; k < num_st - 1; k++)
        {
            if((S[k+1].GetBirthDateVal()) < (S[k].GetBirthDateVal()))
            {
                tmp = S[k+1];
                S[k+1] = S[k];
                S[k] = tmp;
            }
        }
    }
    for(i = 0; i < num_st; i++)
    {
        strcpy(txt1, S[i].GetPerson());
        strcpy(txt2, S[i].GetStudent());
        cout << i+1 << ". " << "\t" << txt1 << "  " << txt2 << endl;
    }

    int num;
    cout << "Insert par. of el. qualification: ";
    cin >> num;
    cout << endl << "List of students with el. qual. par. " << num << ":" << endl;
    for(i = 0; i < num_st; i++)
    {
        if(S[i].GetQual() == num)
        {
            strcpy(txt1, S[i].GetPerson());
            strcpy(txt2, S[i].GetStudent());
            cout << i+1 << ". " << "\t" << txt1 << "  " << txt2 << endl;
        }
    }

    return 0;
}
