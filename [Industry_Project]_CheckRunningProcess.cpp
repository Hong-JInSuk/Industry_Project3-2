#include<Windows.h>
#include<iostream>
#include<stdio.h>
//CreateToolhelp32Snapshot(), Process32First(), Process32Next() ����ϱ����� ���̺귯��
#include<TlHelp32.h>

using namespace std;

int main(void) {

    HANDLE hProcess = NULL;

    // ���μ����� ������ ������ ����ü.
    PROCESSENTRY32 pe32 = { 0 };

    // ��� ���μ����� �޾ƿ´�.
    hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    // ����ü�� ũ�⸦ ������.
    pe32.dwSize = sizeof(PROCESSENTRY32);

    cout << "System Process Name" << "          " << "PID" << endl;

    // ����ü���� ������ �޾ƿ���
    if (Process32First(hProcess, &pe32)) {

        // ���� ���μ����� ������ �޾ƿ´�.
        while (Process32Next(hProcess, &pe32)) {

            // szExeFile : ���μ����� �̸�, th32ProcessID : PID
            cout << pe32.szExeFile << "     " << pe32.th32ProcessID << endl;

        }
    }
    else {
        printf("CHECK --------------");
    }

    return 0;

}