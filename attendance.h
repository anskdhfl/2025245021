#pragma once
#define MAX_ATT 1000

//출결 상태를 구분할 기준
#define STATUS_ABSENT  0
#define STATUS_LATE    1
#define STATUS_PRESENT 2



typedef struct {
    char date[11];     // YYYY-MM-DD
    char name[32];     // 학생 이름
    char course[32];   // 과목명
    int status;        // 출석 상태 (0~2)
} Attendance;



void add_attendance();
void list_attendance();
void show_stats();
void search_by_name();
